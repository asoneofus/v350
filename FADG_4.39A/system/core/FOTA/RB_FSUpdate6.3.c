		/*********************************************************
	  **					C O N F I D E N T I A L             **
	 **						  Copyright 2002-2010                **
	  **                         Red Bend Software              **
	   **********************************************************/
	
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>
#include <fcntl.h>

#include "./headerfiles/MultiFilesApi.h"
#include "./headerfiles/RB_ImageUpdate.h"
#include "./headerfiles/RB_vRM_Errors.h"
#include "./headerfiles/vRM_PublicDefines.h"
#include "./headerfiles/vRM_Languages.h"
#include "./headerfiles/RB_vRM_ImageUpdate.h"

#define FS_U_RAM_SIZE	3*1024*1024
#define FS_ID_MAX_LEN 4
#ifndef MAX_PATH
#define MAX_PATH 1024
#endif

/************************************************************
 *                     common functions
 ************************************************************/
void unicode_to_char(
	const unsigned short *src,
	unsigned char *dest)
{
	int i;

	for(i=0; src[i] != '\0';i++) {
		dest[i] = (char)src[i];
		if (dest[i] == '\\') 
			dest[i] = '/';
	}
	dest[i] = '\0';

	printf("%s : %s\n", __func__, dest);
}

void char_to_unicode(
	const unsigned char *src,
	unsigned short *dest)
{
	int i;
	for (i=0; src[i]; i++){
		dest[i] = src[i];
		dest[i] &= 0xff;
		}
	dest[i] = '\0';
}

long RecursiveFolderCreater(
	const char*	folderpath,
	const		mode_t mode)
{
	int ret = 0;
	char temppath[MAX_PATH] =  {'\0'};
	int pathOffset = strlen(folderpath);// For counting back until the '/' delimiter

	printf(" %s path: %s\n", __func__, folderpath);
	
	if(pathOffset == 0)
		return -1;//if from some reason we got to the end return error!!!.
		
	while(folderpath[pathOffset] != '/')// get to the next '/' place
		pathOffset--;
			
	strncpy(temppath, folderpath, pathOffset);// copy one depth below till and without the char '/'
	printf(" temppath: %s\n", temppath);
	
	ret = mkdir(temppath, mode);
	printf(" mkdir result: %d errno: %d\n", ret, errno);
	if (ret == 0 || ((ret == -1) && (errno == EEXIST)))
	{
		return 0;//meaning the depth creation is success.
	}
	else if((ret == -1) && (errno == ENOENT))
	{
		ret = RecursiveFolderCreater(temppath, mode);
		if (ret == 0)
		{
			ret = mkdir(temppath, mode);
		}
		return ret;
	}
	else
	{
		return -1;
	}
}

/*!
 ************************************************************
 *                     RB_CopyFile
 ************************************************************
 *
 * @brief
 *	This function copies a file to another file with a different name or path.
 *
 *
 *	@param pbUserData	Any user data structure, that may be useful for the user
 *					implementation If not needed set to NULL.
 *					The calling function supply you with the user data,
 *					previously supplied in the RB_FileSystemUpdate.
 *
 *	@param strFromPath	The path where the file exist.
 *
 *	@param strToPath	New destination of the file.
 *
 *	@return			One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */

long RB_CopyFile(
	void*					pbUserData,
	const unsigned short*	strFromPath,
	const unsigned short*	strToPath)
{
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	unsigned int readCount = 0, writeCount = 0;
	const unsigned long BUFFER_SIZE = 10240;
	char buf[BUFFER_SIZE];
	int ret = 0;
	char path1[MAX_PATH]={'\0'};
	char path2[MAX_PATH]={'\0'};

	enumFileType fileType = FT_MISSING;
	unicode_to_char(strFromPath, path1);
	unicode_to_char(strToPath, path2);

	printf ("%s: %s -> %s ", __func__, path1, path2);
	if (!strFromPath || !strToPath)
	{
		printf("NULL file name find. Abort.\n");
		return -1;			//should never happen
	}
	
	ret = RB_GetFileType(pbUserData, (unsigned short *)strFromPath, &fileType);

	if (fileType == FT_SYMBOLIC_LINK)
	{
		char linkedPath[MAX_PATH] = {'\0'};
		ret = readlink (path1, linkedPath, MAX_PATH);
		if (ret < 0)
		{
			printf(" readlink failed with return value: %d\n",ret);
			return -2;
		}
		if (symlink (linkedPath, path2))
			return -3;
		return 0;
	}
	
	fp1 = fopen(path1, "r");
	if (!fp1)
	{
		printf(" Open %s ENOENT %d\n", path1, errno);
		printf("Open %s failed. Abort.\n", path1);
		return E_RB_OPENFILE_ONLYR;
	}

	fp2 = fopen(path2, "w");
	if (!fp2)
	{
		unsigned short shortfolderpath [MAX_PATH];
		char* folder = strrchr(path2,'/'); 
		char* folderPath = (char *) malloc(folder - path2 + 1); 
		
		memset(folderPath,'\0',folder - path2 + 1); 
		strncpy(folderPath,path2,folder - path2);
		char_to_unicode(folderPath,shortfolderpath);
		free(folderPath);
		if ( RB_CreateFolder(NULL,shortfolderpath) != S_RB_SUCCESS )
		{
			fclose(fp1);
			printf("Open %s failed. Abort.\n", path2);
			return E_RB_OPENFILE_WRITE;
		}
		else
		{
			fp2 = fopen(path2, "w");
			if(!fp2)
			{
				fclose(fp1);
				printf("Open %s failed. Abort.\n", path2);
				return E_RB_OPENFILE_WRITE;
			}
		}
	}

	while( (readCount = fread(buf, 1, BUFFER_SIZE, fp1))> 0)
	{
		writeCount = fwrite(buf, 1, readCount, fp2);
		if (writeCount != readCount)
		{
			printf(" read %d, but write %d, abort.\n", readCount, writeCount);
			ret = E_RB_WRITE_ERROR;
 			break;
		}
	}

	fclose(fp1);
	fclose(fp2);

	return ret;
}

/*!
 ************************************************************
 *                     RB_DeleteFile
 ************************************************************
 *
 * @brief
 *	This function deletes a specified file and removes it from the File System.
 *
 *
 *	@param pbUserData	Any user data structure, that may be useful for the user
 *						implementation If not needed set to NULL.
 *						The calling function supply you with the user data,
 *						previously supplied in the RB_FileSystemUpdate.
 *
 *	@param strPath		The path of the file.
 *
 *	@return				One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */

long RB_DeleteFile(
	void*					pbUserData,
	const unsigned short*	strPath)
{
	char path[MAX_PATH]={'\0'};
	int ret = 0;
 
	unicode_to_char(strPath, path);
	printf ("%s: %s\n", __func__, path);
	ret = unlink(path);
	printf (" unlink value: %d, errno: %d\n", ret, errno);
	if (ret == 0)
		return S_RB_SUCCESS;
 
	if (ret < 0 && errno == ENOENT)	//if file does not exist then we can say that we deleted it successfully
		return S_RB_SUCCESS;
  	return E_RB_DELETEFILE;
}

/*!
 ************************************************************
 *                     RB_DeleteFolder
 ************************************************************
 *
 * @brief
 *	This function deletes a specified folder and removes it from the File System.
 *
 *
 *	@param pbUserData	Any user data structure, that may be useful for the user
 *						implementation If not needed set to NULL.
 *						The calling function supply you with the user data,
 *						previously supplied in the RB_FileSystemUpdate.
 *
 *	@param strPath		The path of the folder.
 *
 *	@return				One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */

long RB_DeleteFolder(
	void*					pbUserData,
	const unsigned short*	strPath)
{
	int ret = 0;
	char path[MAX_PATH]={'\0'};

	unicode_to_char(strPath, path);

	printf ("%s: %s\n", __func__, path);

	ret = rmdir(path);
 	printf (" rmdir value: %d, errno: %d\n", ret, errno);
	
	if ((ret == 0) || ((ret < 0) && ((errno == ENOENT) || (errno == ENOTEMPTY ))))
		return S_RB_SUCCESS;
	
 	return E_RB_FAILURE;
}

/*!
 ************************************************************
 *                     RB_CreateFolder
 ************************************************************
 *
 * @brief
 *	This function deletes a specified folder and removes it from the File System.
 *
 *
 *	@param pbUserData	Any user data structure, that may be useful for the user
 *						implementation If not needed set to NULL.
 *						The calling function supply you with the user data,
 *						previously supplied in the RB_FileSystemUpdate.
 *
 *	@param strPath		The path of the folder.
 *
 *	@return				One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */

long RB_CreateFolder(
	void*					pbUserData,
	const unsigned short*	strPath)
{
	mode_t mode = 0;
	int ret = 0;
	char path[MAX_PATH] = {'\0'};

	unicode_to_char(strPath, path);
	mode = 
		S_IRUSR /*Read by owner*/ | 
		S_IWUSR /*Write by owner*/ | 
		S_IXUSR /*Execute by owner*/ | 
		S_IRGRP /*Read by group*/ | 
		S_IWGRP /*Write by group*/ | 
		S_IXGRP /*Execute by group*/ | 
		S_IROTH /*Read by others*/ | 
		S_IWOTH /*Write by others*/ | 
		S_IXOTH /*Execute by others*/;
	
	printf ("%s: %s, mode:0x%x\n", __func__, path, mode);
	
	ret = mkdir(path, mode);
	
	if (ret == 0 || ((ret == -1) && (errno == EEXIST)))
	{
		return S_RB_SUCCESS;
	}
	else if((ret == -1) && (errno == ENOENT))//maybe multi directory problem
	{
		ret = RecursiveFolderCreater(path, mode);
		if(ret == 0) 
		{
			ret = mkdir(path, mode);//After creating all the depth Directories we try to create the Original one again.
			if(ret == 0)
				return S_RB_SUCCESS;
			else
				return E_RB_FAILURE;
		}
		else
		{
			return E_RB_FAILURE;
		}
	}
	else
	{
		return E_RB_FAILURE;
	}
}

/*!
 ************************************************************
 *                     RB_OpenFile
 ************************************************************
 *
 * @brief
 *	Opens a file in the file system.
 *
 *	A glue function that needs to be implemented by the customer.
 *
 *	It should follow the following restrictions:
 *
 * 1. Returning the proper error level \see RbErrors.h
 *
 *
 *	@param pbUserData	Any user data structure, that may be useful for the user
 *						implementation If not needed set to NULL.
 *						The calling function supply you with the user data,
 *						previously supplied in the RB_FileSystemUpdate.
 *
 *	@param strPath		An absolute path to the file location in the FS.
 *
 *	@param wFlag		Controls the access mode read, write or both.
 *						opens a file to write deletes the file content.
 *
 *	@param pwHandle		A handle to the file.
 *
 *	@return				One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */
mode_t get_mode(E_RW_TYPE wFlag)
{
	switch (wFlag)
	{
	case ONLY_R:
		printf(" RDONLY \n");
		return O_RDONLY;
	case ONLY_W:
		printf(" WRONLY \n");
		return O_WRONLY | O_CREAT;
	case BOTH_RW:
		printf(" RDWR \n");
		return O_RDWR | O_CREAT;
	default:
		printf(" Unknown \n");
		return 0;
	}
}

long RB_OpenFile(
	void*					pbUserData,
	const unsigned short*	strPath,
	E_RW_TYPE				wFlag,
	long*					pwHandle)
{
	mode_t mode;
	char path[MAX_PATH] = {'\0'};

	unicode_to_char(strPath, path);
	printf("open file %s\n", path);
	
	printf("%s: Path:%s | Mode:", __func__, path);
	mode = get_mode(wFlag);

	*pwHandle = open(path, mode);
	if (*pwHandle == -1)
	{
		*pwHandle = 0;
		printf(" First open() with error %d\n", errno);
		if (wFlag == ONLY_R)
			return E_RB_OPENFILE_ONLYR;

		//if  we need to open the file for write or read/write then we need to create the folder (in case it does not exist)
		if ((wFlag != ONLY_R) && (errno == ENOENT))
		{
			char dir[MAX_PATH] = {'\0'};
			unsigned short dirShort[MAX_PATH] = {'\0'};
			int i = 0;
			//copy the full file path to directory path variable
			while (path[i] != '\0')
			{
				dir[i] = path[i];
				i++;
			}
			printf(" copy dir[]=%s\n", dir);
			//search for the last '/' char
			while (dir[i--] != '/')
				;
			dir[i+1] = '\0';
			printf(" remove dir[]=%s\n", dir);
			
			char_to_unicode((unsigned char*)dir, dirShort);

			if (RB_CreateFolder(pbUserData, dirShort))
			{
				printf(" Fail create folder, Leave RB_OpenFile\n");
				return E_RB_OPENFILE_WRITE;
			}
	
			*pwHandle = open(path, mode);
			if (*pwHandle == -1 || *pwHandle == 0)
			{
				*pwHandle = 0;
				printf(" After successful creating folder, fail open() with error %d\n", errno);
				return E_RB_OPENFILE_WRITE;
			}
		}
 	}
	printf(" Successful open() *pwHandle:%ld\n", *pwHandle);

	return S_RB_SUCCESS;
}

/*!
 ************************************************************
 *                     RB_ResizeFile
 ************************************************************
 *
 * @brief
 *	set the size of a file in the file system.
 *
 *	@param pbUserData	Any user data structure, that may be useful for the user
 *						implementation If not needed set to NULL.
 *						The calling function supply you with the user data,
 *						previously supplied in the RB_FileSystemUpdate.
 *
 *	@param wHandle		A handle to the file.
 *
 *	@param dwSize		The new size of the file.
 *
 *	@return				One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */

long RB_ResizeFile(
	void*			pbUserData,
	long			wHandle,
	unsigned long	dwSize)
{
	int ret = -1;

	printf("%s: handle %ld, dwSize %d\n", __func__, wHandle, dwSize);

	if (wHandle)
		ret = ftruncate(wHandle, dwSize);

	if (ret)
		ret = E_RB_RESIZEFILE;
	
	printf("%s: ret %d handle %ld %d\n", __func__, ret, wHandle, errno);
	
	return ret;
}

/*!
 ************************************************************
 *                     RB_CloseFile
 ************************************************************
 *
 * @brief
 *	Close a file in the file system.
 *
 *	A glue function that needs to be implemented by the customer.
 *
 *	It should follow the following restrictions:
 *
 * 1. Returning the proper error level \see RbErrors.h
 *
 *
 *	@param pbUserData	Any user data structure, that may be useful for the user
 *						implementation, if not needed set to NULL.
 *						The calling function supply you with the user data,
 *						previously supplied in the RB_FileSystemUpdate.
 *
 *	@param wHandle		A handle to the file.
 *
 *	@return				One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */

long RB_CloseFile(
	void*	pbUserData,
	long 	wHandle )
{
	int ret = E_RB_CLOSEFILE_ERROR;
	printf("%s: wHandle = %ld\n", __func__, wHandle);
	
	if (wHandle>=0)
		ret = close(wHandle);
	
	if (ret == 0)
		return S_RB_SUCCESS;
	
	return E_RB_CLOSEFILE_ERROR;
}

/*!
 ************************************************************
 *                     RB_WriteFile
 ************************************************************
 *
 * @brief
 *	Writes block of data to an open file in a reliable manner.
 *
 *	A glue function that needs to be implemented by the customer.
 *
 *	It should follow the following restrictions:
 *
 *	1. Returning the proper error level \see RbErrors.h
 *	2. The writing procedure should be a transaction.
 *		In case of returning successfully after writing a block means that
 *		the block has been written to its target location, or at least resides
 *		in a NV memory, and an automatic procedure will restore it to its target
 *		location. e.g. a power fail right after returning from the function invocation.
 *
 *	@param pbUserData		Any user data structure, that may be useful for the user
 *							implementation, if not needed set to NULL.
 *							The calling function supply you with the user data,
 *							previously supplied in the RB_FileSystemUpdate.
 *
 *	@param wHandle			Handle to the file.
 *
 *	@param dwPosition		Position were to write
 *
 *	@param pbBuffer			The block of data that should be written.
 *
 *	@param dwSize			The size in bytes of the block to be written.
 *
 *	@return					One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */

long RB_WriteFile(
	void*			pbUserData,
	long			wHandle,
	unsigned long	dwPosition,
	unsigned char*	pbBuffer,
	unsigned long	dwSize)
{
	int ret = 0, size = 0;

	printf("%s: Handle:%ld , Pos:%ld , Size: %ld", __func__, wHandle,dwPosition,dwSize);
	size = lseek(wHandle, 0, SEEK_END);
	/* from the guide: if dwPosition is beyond size of file the gap between end-of-file and the position should be filled with 0xff */
	if (size < dwPosition)
	{
		int heap_size = dwPosition - size;
		unsigned char* p_heap = malloc(heap_size);
		memset(p_heap, 0xFF, heap_size);
		ret = write(wHandle, p_heap, heap_size);
		free(p_heap);
		if (ret < 0)
			return E_RB_WRITE_ERROR;
	}
	ret = lseek(wHandle, dwPosition, SEEK_SET);
	if (ret < 0)
	{
		printf(" lseek failed with return value: %d\n",ret);
		return E_RB_WRITE_ERROR;
	}

	ret = write(wHandle, pbBuffer, dwSize);
	if (ret < 0)
	{
		printf(" Failed with return value: %d\n",ret);
		return E_RB_WRITE_ERROR;
	}
	printf(" Bytes Write: %d\n",ret);

	ret = fsync(wHandle);
	if (ret < 0)
	{
		printf(" fsync Failed with return value: %d\n",ret);
		return E_RB_WRITE_ERROR;
	}
	printf(" fsync after write: %d\n",ret);

	return S_RB_SUCCESS;
}

/*!
 ************************************************************
 *                     RB_ReadFile
 ************************************************************
 *
 * @brief
 *	Reads data from an open file.
 *
 *	A glue function that needs to be implemented by the customer.
 *
 *	It should follow the following restrictions:
 *
 *	1. Returning the proper error level \see RbErrors.h
 *
 *	@param pbUserData	Any user data structure, that may be useful for the user
 *						implementation, if not needed set to NULL.
 *						The calling function supply you with the user data,
 *						previously supplied in the RB_FileSystemUpdate.
 *
 *	@param wHandle		Handle to the file.
 *
 *	@param dwPosition	The offset in the read file that should be
 *						the starting point for the copy.
 *
 *	@param pbBuffer		The gives buffer that the data from the open file should be.
 *						copy into.
 *
 *	@param dwSize		The size in bytes that should be copied from the open file,
 *						starting from the given position offset.
 *
 *	@return				One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */

long RB_ReadFile(
	void*			pbUserData,
	long			wHandle,
	unsigned long	dwPosition,
	unsigned char*	pbBuffer,
	unsigned long	dwSize)
{
	int ret = 0;

	printf(" %s: Handle:%ld , Pos:%ld , Size: %ld", __func__, wHandle,dwPosition,dwSize);
	
	ret = lseek (wHandle, dwPosition, SEEK_SET);
	if (ret < 0)
	{
		printf(" lseek failed with return value: %d\n",ret);
		return E_RB_READ_ERROR;
	}
	ret = read(wHandle, pbBuffer, dwSize);
	if (ret < 0)
	{
		printf(" read failed with return value: %d\n",ret);
		return E_RB_READ_ERROR;
	}
	
	printf(" Bytes Read: %d\n",ret);
	if (ret != dwSize && ((ret + dwPosition) != RB_GetFileSize(pbUserData, wHandle)))
		return E_RB_READ_ERROR;
	
	return S_RB_SUCCESS;
}

long RB_GetFileSize(
	void*	pbUserData,
	long	wHandle)
{
	int ret = 0;

	printf("%s: %ld ", __func__, wHandle);

	ret = lseek(wHandle, 0, SEEK_END);

	if (ret == -1)
	{
		printf(" lseek errno: %d\n", errno);
		return E_RB_READFILE_SIZE;
	}
	printf("Returning Size = 0x%lx\n",ret);
	
	return ret;
}

long RB_Unlink(
	void*			pbUserData,
	unsigned short*	pLinkName)
{
	int ret = 0;
	char path[MAX_PATH]={'\0'};
	enumFileType fileType;

	printf("%s \n", __func__);

	unicode_to_char(pLinkName, path);
	
	ret = RB_GetFileType(pbUserData, pLinkName, &fileType);
	/*If the specified file does not exist or is not a symbolic link file, this function should return an error.*/
	if (ret != S_RB_SUCCESS || fileType == FT_MISSING || fileType == FT_REGULAR_FILE)
	{
		printf("cannot unlink file type %d\n", fileType);
		return E_RB_CAN_UNLINK_ONLY_SYMBOLIC_LINK;
	}

	ret = unlink(path);
	if(ret < 0)
	{
		printf(" unlink failed with return value: %d\n",ret);
		return E_RB_FAILURE;
	}
	printf(" unlink with return value: %d\n",ret);

	return S_RB_SUCCESS;
}

long RB_Link(
	void*			pbUserData,
	unsigned short*	pLinkName,
	unsigned short*	pReferenceFileName)
{
	int ret = 0;
	char sympath[MAX_PATH]={'\0'};
	char refpath[MAX_PATH]={'\0'};
	enumFileType fileType;
	
	printf("%s \n", __func__);
	
	unicode_to_char(pLinkName, sympath);
	unicode_to_char(pReferenceFileName, refpath);

	if(!RB_VerifyLinkReference(pbUserData, pLinkName, pReferenceFileName))
		return S_RB_SUCCESS;

	ret = RB_GetFileType(pbUserData, pLinkName, &fileType);
	/*If a file with the name pLinkName already exists – 
		either as a symbolic link file or as regular file, this function should return an error. The existence of the file with the name pReferenceFileName should not be checked*/
	if (ret != S_RB_SUCCESS || (fileType != FT_MISSING && fileType != FT_SYMBOLIC_LINK))
	{
		printf(" get file type failed with file type: %d value %d\n", fileType, ret);
		return E_RB_FAILED_CREATING_SYMBOLIC_LINK;
	}

	ret = symlink(refpath, sympath);
	if (ret != 0)
	{
		printf(" symlink failed with return value: %d, errno: %d\n", ret, errno);
		if (errno == EEXIST && RB_VerifyLinkReference(pbUserData, pLinkName, pReferenceFileName))
		{
			return S_RB_SUCCESS;
		}
		return E_RB_FAILED_CREATING_SYMBOLIC_LINK;
	}
	printf(" symlink with return value: %d\n",ret);

	return S_RB_SUCCESS;
}

long RB_VerifyLinkReference(
	void*		pbUserData,
	unsigned short*	pLinkName,
	unsigned short*	pReferenceFileName)
{
	int ret = 0;
	char path[MAX_PATH]={'\0'};
	char linkedpath[MAX_PATH]={'\0'};
	char refPath[MAX_PATH] = { '\0' };

	printf("%s \n", __func__);

	unicode_to_char(pLinkName, path);
	unicode_to_char(pReferenceFileName, refPath);
	
	ret = readlink(path, linkedpath, MAX_PATH);
	if (ret < 0)
	{
		printf(" readlink failed with return value: %d\n",ret);
		return E_RB_FAILURE;
	}
	
	if ((memcmp(&linkedpath, &refPath, ret))!=0)
	{
		printf(" not same linked path - linkedpath[%s] pReferenceFileName[%s]\n", linkedpath, refPath);
		return E_RB_FAILURE;
	}
	printf(" same linked path\n");

	return S_RB_SUCCESS;
}

long RB_GetFileType(
	void*			pbUserData,
	unsigned short*	pLinkName,
	enumFileType*	fileType)
{
	int ret = 0;
	char path[MAX_PATH]={'\0'};
	struct stat sbuf;

	printf("%s \n", __func__);

	unicode_to_char(pLinkName, path);

	ret = lstat(path, &sbuf);
	if (ret < 0)
	{
		printf(" stat failed with return value: %d errno: %d\n", ret, errno);
		*fileType = FT_MISSING;
		return S_RB_SUCCESS;
	}

	if (S_ISLNK(sbuf.st_mode))
	{
		printf(" stat->st_mode = symbolic link file\n");
		*fileType = FT_SYMBOLIC_LINK;
		return S_RB_SUCCESS;
	}

	if (S_ISREG(sbuf.st_mode))
	{
		printf(" stat->st_mode = regular file\n");
		*fileType = FT_REGULAR_FILE;
		return S_RB_SUCCESS;		
	}
	
	if (S_ISDIR(sbuf.st_mode))
	{
		printf(" stat->st_mode = regular file\n");
		*fileType = FT_FOLDER;
		return S_RB_SUCCESS;		
	}

	return E_RB_FAILURE;
}

char a2ch(int value)
{
	char set_value = 0;
	
	switch(value)
	{
		case '1':
			set_value = 0x01;
			break;
		case '2':
			set_value = 0x02;
			break;
		case '3':
			set_value = 0x03;
			break;
		case '4':
			set_value = 0x04;
			break;
		case '5':
			set_value = 0x05;
			break;
		case '6':
			set_value = 0x06;
			break;
		case '7':
			set_value = 0x07;
			break;
		case '8':
			set_value = 0x08;
			break;
		case '9':
			set_value = 0x09;
			break;
		case '0':
			set_value = 0x00;
			break;
		default:
			printf("Wrong attribute value: %d\n",value);

	}
	printf("a2ch : %c\n", set_value);

	return set_value;
}

void chtoa(
	int value,
	char* str)
{
	char *pStr = str;

	printf("%s : %d\n", __func__, value);
	
	switch(value)
	{
		case 1:
			*pStr = '1';
			break;
		case 2:
			*pStr = '2';
			break;
		case 3:
			*pStr = '3';
			break;
		case 4:
			*pStr = '4';
			break;
		case 5:
			*pStr = '5';
			break;
		case 6:
			*pStr = '6';
			break;
		case 7:
			*pStr = '7';
			break;
		case 8:
			*pStr = '8';
			break;
		case 9:
			*pStr = '9';
			break;
		case 0:
			*pStr = '0';
			break;
		default:
			printf("Wrong attribute value: %d\n",value);
	}
}

long RB_SetFileAttributes(void *pbUserData,
				const unsigned short *ui16pFilePath,
				const unsigned long ui32AttribSize,
				const unsigned char *ui8pAttribs)
{
	const int ATTRSIZE = 25;
	char tmpAttribs[ATTRSIZE];
	char *tp;
	char *endstr;
	char * rb_sig;
	
	uid_t setUserID		= 0;
	gid_t setGroupID	= 0;
	mode_t setFileMode	= 0;
	char setFilePath[MAX_PATH]={'\0'};
	struct stat sbuf;
	int ret = 0;
	// debug start
	int count = 0;
	// debug end
	
	printf("%s \n", __func__);
	
	if(NULL == ui16pFilePath)
	{
		printf("ui16pFilePath NULL [error]\n");
		return E_RB_BAD_PARAMS;
	}
	else if(NULL == ui8pAttribs)
	{
		printf("ui8pAttribs NULL [error]\n");
		return E_RB_BAD_PARAMS;
	}

	unicode_to_char(ui16pFilePath, setFilePath);
		
	ret = lstat(setFilePath, &sbuf);
	if(ret < 0)
	{	
			printf(" stat failed with return value: %d\n",ret);
			return E_RB_FAILURE;
	}
	else
	{
		if(S_ISLNK(sbuf.st_mode))
		{
			printf(" stat->st_mode = symbolic link file\n");
			return S_RB_SUCCESS;
		}
		if(S_ISREG(sbuf.st_mode))
		{
			printf(" stat->st_mode = regular file\n");
		}
		if (S_ISDIR(sbuf.st_mode))
		{
			printf(" stat->st_mode = directory\n");
		}
	}
	
	if(0 == ui32AttribSize)
	{
		printf("ui32AttribSize 0\n");
		return S_RB_SUCCESS;
	}
	
	printf("ui16pFilePath = %s\n", setFilePath);
	printf("ui32AttribSize = %u\n", ui32AttribSize);
	printf("ui8pAttribs = %s\n", ui8pAttribs);
	// debug start
	for(count=0;count<ATTRSIZE;count++)
	{
		printf("ui8pAttribs[%d] = %c\n", count, ui8pAttribs[count]);
	}
	// debug end

	memset((void*)tmpAttribs, 0x0, ATTRSIZE);
	memcpy(tmpAttribs, ui8pAttribs, (size_t)ui32AttribSize);
	
	//Check that the structure is Valid
	if(NULL == strstr(tmpAttribs,"_redbend_"))
		return E_RB_FAILURE;


	tp = strtok((unsigned char *)tmpAttribs, ":");

	//Remove the _redbend_ SAFIX
	rb_sig = strrchr(tp,'_');
	rb_sig++;

	
	// Get FileMode
	setFileMode = strtol(rb_sig, &endstr, 8);
	tp = strtok(NULL, ":");

	// Get UserID
	if (tp != NULL)
	{
		setUserID = (uid_t)strtol(tp, &endstr, 16);
		tp = strtok(NULL, ":");
	}

	// Get GroupID
	if (tp != NULL)
	{
		setGroupID = (gid_t)strtol(tp, &endstr, 16);
	}

	// Set FileMode
	printf("setFilePath = %s\n",setFilePath);
	printf("setFileMode = %d\n", setFileMode);
	printf("setFileMode = %o\n", setFileMode);
	printf("setUserID = %d\n", setUserID);
	printf("setGroupID = %d\n", setGroupID);
	
	// Set UserID,GroupID
	if( chown(setFilePath, setUserID, setGroupID) )
	{
		printf("%s chown error\n", __func__);
		// debug start
		printf("%s setUserID = %d\n", __func__, setUserID);
		printf("%s setGroupID = %d\n", __func__, setGroupID);
		printf("%s chown errno = %d\n", __func__, errno);
		// debug end
		return E_RB_FAILURE;
	}

	if( chmod(setFilePath, setFileMode) )
	{
		printf("%s chmod error\n", __func__);
		return E_RB_FAILURE;
	}

	printf("%s SUCCESS\n", __func__);
	return S_RB_SUCCESS;
}

long RB_CompareFileAttributes(
	void*			pbUserData,
	unsigned short*	pFilePath,
	unsigned char*	pAdditionalAttribs,
	unsigned long	iAddiInfoSize)
{
	return S_RB_SUCCESS;
}

long RB_ResetTimerA(void)
{
	printf("%s \n", __func__);
	return S_RB_SUCCESS;
}

/*!
 ************************************************************
 *                     RB_FSGetDelta
 ************************************************************
 *
 * @brief
 *	Reads data from the delta.
 *
 *	A glue function that needs to be implemented by the customer.
 *
 *	It should follow the following restrictions:
 *
 *	1. Returning the proper error level \see RbErrors.h
 *
 *	@param pbBuffer					The gives buffer that the data from the open file should be.
 *									copy into.
 *
 *	@param dwStartAddressOffset		The offset in the read file that should be
 *									the starting point for the copy.
 *
 *	@param dwSize					The size in bytes that should be copied from the open file,
 *									starting from the given position offset.
 *
 *	@return							One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */

#define DELTA_FILE "/data/dm/delta"

long RB_GetDelta(
	void*			pbUserData,				    /* User data passed to all porting routines */
	unsigned char*	pbBuffer,			/* pointer to user buffer */
    unsigned long	dwStartAddressOffset, /* offset from start of delta file */
    unsigned long	dwSize)
{
	int readCount = 0, ret = 0;
	FILE* fp;

	printf("%s: offset 0x%lx(%ld), size 0x%lx(%ld)\n", __func__,
		dwStartAddressOffset, dwStartAddressOffset, dwSize, dwSize);

	fp = fopen(DELTA_FILE, "r");
	if (!fp)
	{
		printf("%s: open delta file %s failed.\n", __func__, DELTA_FILE);
		return E_RB_OPENFILE_ONLYR;
	}
	ret = fseek(fp, dwStartAddressOffset, 0);
	if (ret == -1)
	{
		fclose(fp);
		return E_RB_READ_ERROR;
	}
	readCount = fread(pbBuffer, 1, dwSize, fp);
	if (readCount != dwSize)
	{
		printf("%s: error in read size\n", __func__);
		fclose(fp);
		ret = E_RB_READ_ERROR;
	}
	fclose(fp);
	return S_RB_SUCCESS;
}

void RB_Progress(
		void*			pbUserData,					/* User data passed to all porting routines */
		unsigned long	uPercent)
	
{
	printf("%s: update %ld percent\n", __func__, uPercent);
	//To do: display the progress bar
}

/*!
 ************************************************************
 *                     RB_FSTrace
 ************************************************************
 *
 * @brief
 *	Generic log
 *
 *	A glue function that needs to be implemented by the customer.
 *	Gives the Update procedure the ability to send out status indications and debug
 *	information.
 *
 *	@param pbUserData	Any user data structure, that may be useful for the user
 *						implementation, if not needed set to NULL.
 *						The calling function supply you with the user data,
 *						previously supplied in the RB_FileSystemUpdate.
 *
 *	@param aFormat		a NULL terminated string that support a subset of the known
 *						standard c library printf.
 *						Supports:
 *							%x - hex number
 *							%0x - hex number with leading zeros
 *							%fx - hex number with leading spaces
 *							%u - unsigned decimal
 *							%s - null terminated string
 *
 *	@param ...			List of the format corresponding variable
 *
 *	@return				One of the return codes as defined in RbErrors.h
 *
 ************************************************************
 */

long RB_FSTrace(
	void*					pUser,
	const unsigned short*	aFormat,
	...)
{
	va_list list;

	va_start(list, aFormat);
	vprintf(aFormat, list);
	va_end(list);
	printf("\n");
	return S_RB_SUCCESS;
}

/* Prints a string like the C printf() function */
unsigned long RB_Trace(
	void*			pUser,
	const char*		aFormat,
	...)
{
	va_list list;

	va_start(list, aFormat);
	vprintf(aFormat, list);
	va_end(list);
	return S_RB_SUCCESS;
}

int RB_FSUpdateMain(void)
{
	unsigned char *string_fs = "/",ch;
	unsigned char *string_del = "/data/dm/delta";
	unsigned short fs_path[MAX_PATH]={'\0'};
	unsigned short del[MAX_PATH]={'\0'};
	int i;
	unsigned char* pRamMem =(unsigned char*)calloc(FS_U_RAM_SIZE,1);
	int ret = 0;
	unsigned long rest = -1;
	vRM_DeviceData pDeviceDatum;
	CustomerPartitionData pCustomerPartData;
	unsigned long SupplementaryInfoSize = 4;
	unsigned char SupplementaryInfoArray[SupplementaryInfoSize];
	unsigned char* pSupplementaryInfo = (unsigned char*)SupplementaryInfoArray;
	
	unsigned long ComponentInstallerType[1]={0};
	unsigned short PartitionName[MAX_PATH] = {'\0'};
	unsigned char *string_parname = "YAFFS";
	unsigned short MountPoint[MAX_PATH] = {'\0'};
	
	for(i=0; i<strlen(string_fs); i++)
	{
		ch = string_fs[i];
		fs_path[i]= ch;
	}
	
	for(i=0; i<strlen(string_del); i++)
	{
		ch = string_del[i];
		del[i]= ch;
	}

	for(i=0; i<strlen(string_parname); i++)
	{
		ch = string_parname[i];
		PartitionName[i]= ch;
	}

	for(i=0; i<strlen(string_fs); i++)
	{
		ch = string_fs[i];
		MountPoint[i]= ch;
	}
	
	pCustomerPartData.partition_name				= PartitionName;
	pCustomerPartData.base_partition_name			= pCustomerPartData.partition_name;
	pCustomerPartData.page_size = pCustomerPartData.sector_size = 0x20000;
	pCustomerPartData.rom_start_address				= 0;
	pCustomerPartData.rom_end_address				= 0x80000000;
	pCustomerPartData.dir_tree_offset				= 0;
	pCustomerPartData.mount_point					= MountPoint;
	pCustomerPartData.ui16StrSourcePath				= 0;
	pCustomerPartData.ui16StrTargetPath 			= 0;
	pCustomerPartData.ui16StrSourceFileAttr			 = 0;
	pCustomerPartData.ui16StrTargetFileAttr			 = 0;
	pCustomerPartData.partition_type				= PT_FS;
	pCustomerPartData.file_system_type				= FS_JOURNALING_RW;
	pCustomerPartData.rom_type 						= ROM_TYPE_READ_WRITE;
	pCustomerPartData.compression_type 				= NO_COMPRESSION;
	pCustomerPartData.updated 						= rest;
	pDeviceDatum.ui32Operation 						= 0;
	pDeviceDatum.ui32DeviceCaseSensitive			= 1;
	pDeviceDatum.pRam 								= pRamMem;
	pDeviceDatum.ui32RamSize						= FS_U_RAM_SIZE;
	pDeviceDatum.ui32NumberOfBuffers				= 0;
	pDeviceDatum.pBufferBlocks						= 0;
	pDeviceDatum.ui32NumberOfPartitions 			= 1;
	pDeviceDatum.pFirstPartitionData				= &pCustomerPartData;
	pDeviceDatum.ui32NumberOfLangs					= 0;
	pDeviceDatum.pLanguages							= 0;
	pDeviceDatum.pTempPath							= fs_path;
	pDeviceDatum.pSupplementaryInfo					= (unsigned char**)&pSupplementaryInfo;
	pDeviceDatum.pSupplementaryInfoSize				= &SupplementaryInfoSize;
	pDeviceDatum.pComponentInstallerTypes			= ComponentInstallerType;
	pDeviceDatum.ui32ComponentInstallerTypesNum		= 1;
	pDeviceDatum.enmUpdateType						= UT_NO_SELF_UPDATE;
	pDeviceDatum.ui32Flags							= 0;
	pDeviceDatum.pDeltaPath							= del;
	pDeviceDatum.pbUserData							= NULL;
	
	ret = RB_vRM_Update(&pDeviceDatum);
	
	printf("return value from RB_vRM_Update %d\n", ret);
	printf("pCustomerPartData.updated = rest = %d\n", rest);

	return ret;
}
