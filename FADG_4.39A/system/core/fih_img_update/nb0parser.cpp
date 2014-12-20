#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdarg.h>

#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/un.h>

#include "comdef.h"
#include "nb0parser.h"
#include "md5.h"

//[Package Info] 
#define   UPDATE_FLAG_NULL      0x00 
#define   UPDATE_FLAG_QCSBL     0x01 
#define   UPDATE_FLAG_OEMSBL    0x02 
#define   UPDATE_FLAG_AMSS      0x04 
#define   UPDATE_FLAG_CEFS      0x08 
#define   UPDATE_FLAG_APPSBOOT  0x10 
#define   UPDATE_FLAG_ANDROID_BOOT  0x100
#define   UPDATE_FLAG_ANDROID_SYSTEM    0x200
#define   UPDATE_FLAG_ANDROID_USER_DATA 0x400
#define   UPDATE_FLAG_ANDROID_RECOVERY  0x800
#define   UPDATE_FLAG_ANDROID_SPLASH    0x1000
#define   UPDATE_FLAG_ANDROID_HIDDEN    0x2000
#define   UPDATE_FLAG_ANDROID_FTM       0x4000

#define LOG_TO_KMSG	1
extern void _LOGK(const char * fmt,...);
extern FILE *fp_pipe;
#if LOG_TO_KMSG
#if 1
#define DBG_MSG(...)    \
    do                  \
    {                   \
        if(fp_pipe)     \
        {               \
            fprintf(fp_pipe, "LOG:" __VA_ARGS__); \
            fflush(fp_pipe);    \
        }   \
        else    \
            _LOGK("LOG:" __VA_ARGS__); \
    }while(0)
#endif
//#define DBG_MSG _LOGK
//#define LOG_INFO(a1, a2)    do { _LOGK(a1 a2);}while(0)
#define LOG_INFO(a1, a2)    do { }while(0)
#define LOG_ERROR(a1, a2, a3)    DBG_MSG(a1 a2 "%d\n", a3);
#define LOG_WARNNING(a1, a2, a3) DBG_MSG(a1 a2 "%d\n", a3);
//#define ProgressReport(a1, a2)  do { _LOGK("Prgs %d %s",a1, a2);}while(0)
//#define ProgressReport(a1, a2)  do { _LOGK("ProgressReport %d %s",a1, a2);}while(0)
#else
#define DBG_MSG(fmt, args...) fprintf(stdout, fmt, ## args)
//#define LOG_INFO(a1, a2)    do { fprintf(stdout, a1 a2 "\n");}while(0)
#define LOG_INFO(a1, a2)    do { }while(0)
#define LOG_ERROR(a1, a2, a3)    fprintf(stdout, a1 a2 "%d\n", a3);
#define LOG_WARNNING(a1, a2, a3) fprintf(stdout, a1 a2 "%d\n", a3);
//#define ProgressReport(a1, a2)  do { fprintf(stdout, "Prgs %d %s\n",a1, a2);}while(0)
//#define ProgressReport(a1, a2)  do { fprintf(stdout, "ProgressReport %d %s\n",a1, a2);}while(0)
#endif

typedef enum
{
    FILENAME_ID_FLASH_HEX = 0,
    FILENAME_ID_FLASH_BIN,
    FILENAME_ID_PARTITION,
    FILENAME_ID_QCSBLHDCFG,
    FILENAME_ID_QCSBL,
    FILENAME_ID_OEMSBLHD,
    FILENAME_ID_OEMSBL,
    FILENAME_ID_AMSSHD,
    FILENAME_ID_AMSS,
//    FILENAME_ID_CEFS,
    FILENAME_ID_APPSBOOTHD,
    FILENAME_ID_APPSBOOT,
    FILENAME_ID_ANDROID_BOOT,
    FILENAME_ID_ANDROID_SYSTEM,
//    FILENAME_ID_ANDROID_USER_DATA,
    FILENAME_ID_ANDROID_RECOVERY,
    FILENAME_ID_ANDROID_SPLASH,
    FILENAME_ID_ANDROID_HIDDEN,
    FILENAME_ID_ANDROID_FTM,
    FILENAME_ID_ANDROID_CDA,
    FILENAME_ID_ANDROID_NV_CUST,
    FILENANE_ID_QCN_FILENAME,
    FILENAME_ID_NV_DEFINITION,
    FILENAME_ID_CUSTOM_NV,
    FILENAME_ID_MAX
} FILE_ID;

//File name definition for Android platform
const _TCHAR* pszFileNameDefineAd[]=
{
"FILENAME_FLASH_HEX",   // 0
"FILENAME_FLASH_BIN",
"FILENAME_PARTITION",   // 2
"FILENAME_QCSBLHDCFG",
"FILENAME_QCSBL",       // 4
"FILENAME_OEMSBLHD",
"FILENAME_OEMSBL",      // 6
"FILENAME_AMSSHD",
"FILENAME_AMSS",        // 8
//"FILENAME_CEFS",
"FILENAME_APPSBOOTHD",  // 10
"FILENAME_APPSBOOT",
"FILENAME_ANDROID_BOOT",    // 12
"FILENAME_ANDROID_SYSTEM",
//"FILENAME_ANDROID_USR_DATA",   // 14
"FILENAME_ANDROID_RECOVERY",
"FILENAME_ANDROID_SPLASH",    // 16
"FILENAME_ANDROID_HIDDEN",
"FILENAME_ANDROID_FTM",       // 18
"FILENAME_ANDROID_CDA",       
"FILENAME_NV_CUST",   
"QCN FILENAME",
"NV DEFINITION",    // 20
"CUSTOM_NV",
//"FILE NUMBER",
//"FILE NAME",
};

#define MAX_DOWNLOAD_FILE_NUM   32
#define MAX_FILENAME_LENGTH     256
_TCHAR pszFirmwareFileName[MAX_DOWNLOAD_FILE_NUM][MAX_FILENAME_LENGTH];

DWORD GetFlagData(char * tmpfilename)
{
    _TCHAR StrBuf[256];
   // _TCHAR StrFlagHexNum[3];
    DWORD dwFlagData = 0;
    //DWORD i, j, k;
    //j = 0;
    FILE * fpTmp;
    
    if (!(fpTmp = fopen(tmpfilename, "r"))) 
    {
        //_LOGK("Unable to open '%s'\n", nv_def_filename);
        DBG_MSG("Unable to open '%s'\n", tmpfilename);
        return -errno;
    }
    fseek(fpTmp, 0, SEEK_SET);
    while(fgets(StrBuf, sizeof(StrBuf), fpTmp))
    {
        if (strstr(StrBuf, "FLAG ="))
        {
            //DBG_MSG("dwFlagData= %d\n", dwFlagData);
            sscanf(StrBuf, "%*s %*s %x", &dwFlagData);
            //DBG_MSG("dwFlagData= %X\n", dwFlagData);
        }
        if (dwFlagData != 0)
            break;
    }
    fclose(fpTmp);
    return dwFlagData;
}
BOOL GetStringData(char * tmpfilename, char * token, char * r_buf)
{
    _TCHAR StrBuf[256];
    BOOL rc = FALSE;
   // _TCHAR StrFlagHexNum[3];
    //DWORD dwFlagData = 0;
    //DWORD i, j, k;
    //j = 0;
    FILE * fpTmp;
    
    if (!(fpTmp = fopen(tmpfilename, "r"))) 
    {
        //_LOGK("Unable to open '%s'\n", nv_def_filename);
        DBG_MSG("Unable to open '%s'\n", tmpfilename);
        return -errno;
    }
    fseek(fpTmp, 0, SEEK_SET);
    while(fgets(StrBuf, sizeof(StrBuf), fpTmp))
    {
        if (strstr(StrBuf, token))
        {
            //DBG_MSG("dwFlagData= %d\n", dwFlagData);
            sscanf(StrBuf, "%*s %*s %s", r_buf);
            DBG_MSG("r_buf=%s\n", r_buf);
            rc = TRUE;
            break;
        }
    }
    fclose(fpTmp);
    return rc;
}
#if 1
BOOL GetFileNameDefinition(_TCHAR *StrBuf, FILE_ID id)
{
    _TCHAR *first, *last;
    if (*pszFirmwareFileName[id] == 0
        && strstr(StrBuf, pszFileNameDefineAd[id]))
    {
        first = strchr(StrBuf, '\"');
        last = strrchr(StrBuf, '\"');
        //printf("first = 0x%x last=0x%x\r\n", first, last);
        if (first != 0 && last !=0 && first != last)
        {
            strncpy(pszFirmwareFileName[id], (first+1), (last-first-1));
            DBG_MSG("%s = %s\r\n", pszFileNameDefineAd[id], pszFirmwareFileName[id]);
            return TRUE;
        }
        else
            return FALSE;
    }
    return FALSE;
}
// Convert string to lower case
int str2lcase(char* s1, char* s2)
{
    int i = 0;
    int len = strlen(s1);

    for(; i<=len; i++)
    {
        if (*s1 >= 'A' && *s1 <= 'Z')
        {
            *s2 = *s1 + 0x20;
        }
        else
        {
            *s2 = *s1;
        }
        s1++;
        s2++;
    }
    return i;
}
int GetFileName(char * inFilename)
{
    _TCHAR StrBuf[256];
    DWORD i;
    FILE *fpMlf;
    
    memset(pszFirmwareFileName, 0, sizeof(pszFirmwareFileName));
    DBG_MSG("sizeof pszFirmwareFileName = %d\n", sizeof(pszFirmwareFileName));

    fpMlf = fopen(inFilename,"r+");
    if(fpMlf == NULL){
	    DBG_MSG("Fail to open %s\r\n", inFilename);
	    return -1;
    }
    fseek(fpMlf, 0, SEEK_SET);
    i = FILENAME_ID_FLASH_HEX;
    while(fgets(StrBuf, sizeof(StrBuf), fpMlf))
    {
        //printf("i = %d\r\n", i);
        if (GetFileNameDefinition(StrBuf, (FILE_ID)i))
        {
            if(++i >= FILENAME_ID_MAX)
                break;
            else
                continue;
        }        
    }
    DBG_MSG("i = %d max =%d\r\n", i, FILENAME_ID_MAX);
    return 0;
}
#endif
int CheckMd5(NB0ItemHead *pHeader, dword dwFileNumber, dword dwTotalHeaderSize, FILE *fpNB0)
{
    #define MD5_HASH_SIZE   16  // 16 bytes
    MD5_Record *pMd5Record = NULL;
    int Md5RecNo = 0; //MD5 record number
    BOOL MD5_check_ok = TRUE;
    char tmpBuf[48];

    // To be compatible with previous nb0 format.
    //If *.md5 doesn't exist in the nb0, skip the md5 check and continue.
    str2lcase((char*)pHeader[dwFileNumber-1].bytFilename, tmpBuf);
    if (strstr(tmpBuf, ".md5") == NULL)
    {
        DBG_MSG( "No MD5 file\n");
        return MD5_check_ok;
    }
    pMd5Record = (MD5_Record*) malloc(pHeader[dwFileNumber-1].dwLength);
    if (pMd5Record == NULL)
        DBG_MSG( "pMd5Recor malloc failed\n");

    Md5RecNo = pHeader[dwFileNumber-1].dwLength / sizeof(MD5_Record);
    DBG_MSG( "Md5RecNo=%d headersize=0x%x md5 ofs=0x%X\n", Md5RecNo, dwTotalHeaderSize, pHeader[dwFileNumber-1].dwOffset);
    fseek(fpNB0, (dwTotalHeaderSize + pHeader[dwFileNumber-1].dwOffset), SEEK_SET);
    fread(pMd5Record, 1, pHeader[dwFileNumber-1].dwLength, fpNB0);

    //Calculate the md5 check sum according to the start offset and size in the md5 records
    struct MD5Context md5c;
    byte * pTmpBuf = NULL;
    unsigned char ss[MD5_HASH_SIZE];

    for (int i=0; i< Md5RecNo; i++)
    {
        pTmpBuf = (byte*)malloc(pMd5Record[i].dwLength);
        if (pTmpBuf == NULL)
            DBG_MSG( "pTmpBuf malloc failed\n");
        fseek(fpNB0, pMd5Record[i].dwOffset, SEEK_SET);
        fread(pTmpBuf, 1, pMd5Record[i].dwLength, fpNB0);

        MD5Init( &md5c );
        MD5Update( &md5c, pTmpBuf, pMd5Record[i].dwLength);
        MD5Final( ss, &md5c );

        //Compare check sum
        for(int j=0; j<MD5_HASH_SIZE; j++ )
        {
            if (ss[j] != pMd5Record[i].bytMd5chksum[j])
            {
                DBG_MSG( "MD5 check error!\n");
            #if 1
                DBG_MSG( "Md5Record[%d]: 0x%08X 0x%08X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\n", 
                    i, pMd5Record[i].dwOffset, pMd5Record[i].dwLength, 
                    pMd5Record[i].bytMd5chksum[0], pMd5Record[i].bytMd5chksum[1],
                    pMd5Record[i].bytMd5chksum[2], pMd5Record[i].bytMd5chksum[3],
                    pMd5Record[i].bytMd5chksum[4], pMd5Record[i].bytMd5chksum[5],
                    pMd5Record[i].bytMd5chksum[6], pMd5Record[i].bytMd5chksum[7],
                    pMd5Record[i].bytMd5chksum[8], pMd5Record[i].bytMd5chksum[9],
                    pMd5Record[i].bytMd5chksum[10], pMd5Record[i].bytMd5chksum[11],
                    pMd5Record[i].bytMd5chksum[12], pMd5Record[i].bytMd5chksum[13],
                    pMd5Record[i].bytMd5chksum[14], pMd5Record[i].bytMd5chksum[15]
                    );
                DBG_MSG( "Calculated md5: 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\n", 
                    ss[0], ss[1], ss[2], ss[3], ss[4], ss[5], ss[6], ss[7], ss[8], ss[9], ss[10], ss[11], ss[12], ss[13], ss[14], ss[15]
                    );
                MD5_check_ok = FALSE;
                break;
            #endif

            }
        }
        free(pTmpBuf);
        pTmpBuf = NULL;
    }
    free(pMd5Record);
    pMd5Record = NULL;

    return MD5_check_ok;
}

#define UPDATE_FLAG_IS_NULL	-2
#define FIRMWARE_FILE_NAME_ERROR	-3
#define PROJECT_NAME_NULL	-4
#define MD5_CHECK_ERROR     -5
int ParseNB0(char *filename, DL_FILE_LIST *DLlist, char *tmpPath, char *hw_id, unsigned int check_md5)
{
    FILE *fpNB0;
    dword dwFileNumber = 0;
    NB0ItemHead *pHeader = NULL;
    FILE *fpTmp;
    char tmpfilename[256];
    BYTE buf[4096];
    dword dwTotalHeaderSize = 0;
    dword dwFlag = 0;   //the flag for downloading files 
    char * pch = NULL;
    char tmpBuf[256];

    if (!(fpNB0 = fopen(filename, "r"))) 
    {
        DBG_MSG("Unable to open '%s'\n", filename);
        return -errno;
    }
    if (fread(&dwFileNumber, 1, sizeof(dwFileNumber), fpNB0) != sizeof(dwFileNumber))
    {
        DBG_MSG("Failed to read '%s'\n", filename);
        return -errno;
    }
    dwTotalHeaderSize = 4 + (dwFileNumber * sizeof(NB0ItemHead));   // 4 byte(file numbers) + total headers of all files
    pHeader = (NB0ItemHead *)malloc(dwFileNumber * sizeof(NB0ItemHead));
    //for (int i=0; i< dwFileNumber; i++)
    {
        fread(pHeader, sizeof(NB0ItemHead), dwFileNumber, fpNB0);
    }
    #if 0
    for (int i=0; i< dwFileNumber; i++)
    {
        DBG_MSG("File %d ofs %x len %x '%s'\n", i, pHeader[i].dwOffset, pHeader[i].dwLength, pHeader[i].bytFilename);
    }
    #endif

    //Do md5 check 
    if (check_md5)
    {
        if (!CheckMd5(pHeader, dwFileNumber, dwTotalHeaderSize, fpNB0))
            return MD5_CHECK_ERROR;
    }
    //Read mlf file to get file name and flag
    memset(tmpfilename, 0, sizeof(tmpfilename));
    sprintf(tmpfilename, "%s/" FILENAME_TEMP_MLF, tmpPath);

    if (!(fpTmp = fopen(tmpfilename, "w"))) 
    {
        DBG_MSG("Unable to open '%s'\n", tmpfilename);
        return -errno;
    }
    fseek(fpNB0, dwTotalHeaderSize, SEEK_SET);
    fread(buf, 1, pHeader[0].dwLength, fpNB0);
    fwrite(buf, 1, pHeader[0].dwLength, fpTmp);
    fclose(fpTmp);

// ++++++++++++++++ Parse mlf ++++++++++++++++++++++++
    dwFlag = GetFlagData(tmpfilename);
    if (dwFlag == UPDATE_FLAG_NULL)
    {
        DBG_MSG("Update flag = 0, no file can be updated\n");
        return UPDATE_FLAG_IS_NULL;
    }

    char proj_name[8];
	if (!GetStringData(tmpfilename, "PROJECT", proj_name))
    {
        return PROJECT_NAME_NULL;
    }
    sprintf(DLlist->StaticNVFile, "%s_%s_NV.xml", proj_name, hw_id);
    //DBG_MSG("staticNV=%s\n", DLlist->StaticNVFile);

    if (GetFileName(tmpfilename) < 0)
        return FIRMWARE_FILE_NAME_ERROR;
    //Remove the temp.mlf
    sprintf(tmpfilename, "%s/" FILENAME_TEMP_MLF, tmpPath);
    if ((unlink(tmpfilename) && errno != ENOENT)) {
        DBG_MSG("Can't unlink %s\n", tmpfilename);
    }
// -------------------- Parse mlf -----------------------
    str2lcase(&pszFirmwareFileName[FILENAME_ID_NV_DEFINITION][0], (char *) tmpBuf);
    strcpy(DLlist->NVDefFile, tmpBuf);
    str2lcase(&pszFirmwareFileName[FILENAME_ID_CUSTOM_NV][0], (char *) tmpBuf);
    strcpy(DLlist->NVCustomFile, tmpBuf);
    str2lcase(DLlist->StaticNVFile, (char *) tmpBuf);
    strcpy(DLlist->StaticNVFile, tmpBuf);

    //Pass the file name and offset to the FirmwareList structure
    DLlist->Flist.iFLAG = dwFlag;
    if (strlen(filename) >= DL_FILENAME_LEN)
    {
        DBG_MSG("NB0 File name is over %d bytes\n", DL_FILENAME_LEN);
        return -1;
    }
    pch = strrchr(filename, '/') + 1;   //Remove the '/' character
    strcpy(DLlist->Flist.pCOMBINED_IMAGE, pch);

    #if 1
    for (int i=0; i< dwFileNumber; i++)
    {
        str2lcase((char*)pHeader[i].bytFilename, (char *) tmpBuf);
        //DBG_MSG("'%s'\n", tmpBuf);
        #if 0
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_FLASH_HEX][0]) == 0)
        {   //filename match
            DLlist->Flist.aARMPRG_BIN[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aARMPRG_BIN[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        #endif
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_FLASH_BIN][0]) == 0)
        {   //filename match
            DLlist->Flist.aARMPRG_BIN[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aARMPRG_BIN[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_PARTITION][0]) == 0)
        {   //filename match
            DLlist->Flist.aPARTITION[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aPARTITION[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
            sprintf(tmpfilename, "%s/" FILENAME_PARTITION_TABLE, tmpPath);
            if (!(fpTmp = fopen(tmpfilename, "w"))) 
            {
                //_LOGK("Unable to open '%s'\n", nv_def_filename);
                DBG_MSG("Unable to open '%s'\n", tmpfilename);
                return -errno;
            }
            fseek(fpNB0, (pHeader[i].dwOffset + dwTotalHeaderSize), SEEK_SET);
            int j = pHeader[i].dwLength;
            //DBG_MSG("len=%d\n", j);
            while(j > 0)
            {
                if (j < sizeof(buf))
                {
                    j -= (pHeader[i].dwLength % sizeof(buf));
                    fread(buf, 1, (pHeader[i].dwLength % sizeof(buf)), fpNB0);
                    fwrite(buf, 1, (pHeader[i].dwLength % sizeof(buf)), fpTmp);
                }
                else
                {
                    fread(buf, 1, sizeof(buf), fpNB0);
                    fwrite(buf, 1, sizeof(buf), fpTmp);
                    j -= sizeof(buf);
                }
            }
            fclose(fpTmp);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_QCSBLHDCFG][0]) == 0)
        {   //filename match
            DLlist->Flist.aQCSBLHDCFG[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aQCSBLHDCFG[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_QCSBL][0]) == 0)
        {   //filename match
            DLlist->Flist.aQCSBL[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aQCSBL[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_OEMSBLHD][0]) == 0)
        {   //filename match
            DLlist->Flist.aOEMSBLHD[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aOEMSBLHD[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_OEMSBL][0]) == 0)
        {   //filename match
            DLlist->Flist.aOEMSBL[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aOEMSBL[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_AMSSHD][0]) == 0)
        {   //filename match
            DLlist->Flist.aAMSSHD[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aAMSSHD[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_AMSS][0]) == 0)
        {   //filename match
            DLlist->Flist.aAMSS[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aAMSS[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_APPSBOOTHD][0]) == 0)
        {   //filename match
            DLlist->Flist.aAPPSBOOTHD[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aAPPSBOOTHD[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_APPSBOOT][0]) == 0)
        {   //filename match
            DLlist->Flist.aAPPSBOOT[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aAPPSBOOT[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_ANDROID_BOOT][0]) == 0)
        {   //filename match
            DLlist->Flist.aANDROID_BOOT[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aANDROID_BOOT[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_ANDROID_SYSTEM][0]) == 0)
        {   //filename match
            DLlist->Flist.aANDROID_SYSTEM[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aANDROID_SYSTEM[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        //else
        //if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_ANDROID_USER_DATA][0]) == 0)
        //{   //filename match
        //    DLlist->Flist.aANDROID_USR_DATA[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
        //    DLlist->Flist.aANDROID_USR_DATA[1] = pHeader[i].dwLength;   // Size
        //    DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        //}
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_ANDROID_RECOVERY][0]) == 0)
        {   //filename match
            DLlist->Flist.aANDROID_RECOVERY[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aANDROID_RECOVERY[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_ANDROID_SPLASH][0]) == 0)
        {   //filename match
            DLlist->Flist.aANDROID_SPLASH[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aANDROID_SPLASH[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_ANDROID_HIDDEN][0]) == 0)
        {   //filename match
            DLlist->Flist.aANDROID_HIDDEN[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aANDROID_HIDDEN[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_ANDROID_FTM][0]) == 0)
        {   //filename match
            DLlist->Flist.aANDROID_FTM[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aANDROID_FTM[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_ANDROID_CDA][0]) == 0)
        {   //filename match
            DLlist->Flist.aANDROID_CDA[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aANDROID_CDA[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp((char*)pHeader[i].bytFilename, &pszFirmwareFileName[FILENAME_ID_ANDROID_NV_CUST][0]) == 0)
        {   //filename match
            DLlist->Flist.aCUSTOMER_NV[0] = dwTotalHeaderSize + pHeader[i].dwOffset;   // Offset address in NB0 file
            DLlist->Flist.aCUSTOMER_NV[1] = pHeader[i].dwLength;   // Size
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
        }
        else
        if (strcmp(tmpBuf, DLlist->NVDefFile) == 0)
        {   //filename match
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
            sprintf(tmpfilename, "%s/" FILENAME_DEFINITION_NV, tmpPath);
            if (!(fpTmp = fopen(tmpfilename, "w"))) 
            {
                DBG_MSG("Unable to open '%s'\n", tmpfilename);
                return -errno;
            }
            fseek(fpNB0, (pHeader[i].dwOffset + dwTotalHeaderSize), SEEK_SET);
            int j = pHeader[i].dwLength;
            //DBG_MSG("len=%d\n", j);
            while(j > 0)
            {
                if (j < sizeof(buf))
                {
                    j -= (pHeader[i].dwLength % sizeof(buf));
                    fread(buf, 1, (pHeader[i].dwLength % sizeof(buf)), fpNB0);
                    fwrite(buf, 1, (pHeader[i].dwLength % sizeof(buf)), fpTmp);
                }
                else
                {
                    fread(buf, 1, sizeof(buf), fpNB0);
                    fwrite(buf, 1, sizeof(buf), fpTmp);
                    j -= sizeof(buf);
                }
                //DBG_MSG("len=%d\n", j);
            }
            fclose(fpTmp);
        }
        else
        if (strcmp(tmpBuf, DLlist->NVCustomFile) == 0)
        {   //filename match
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
            //sprintf(tmpfilename, "%s/%s", tmpPath, DLlist->NVCustomFile);
            sprintf(tmpfilename, "%s/" FILENAME_CUSTOM_NV, tmpPath);
            if (!(fpTmp = fopen(tmpfilename, "w"))) 
            {
                //_LOGK("Unable to open '%s'\n", nv_def_filename);
                DBG_MSG("Unable to open '%s'\n", tmpfilename);
                return -errno;
            }
            fseek(fpNB0, (pHeader[i].dwOffset + dwTotalHeaderSize), SEEK_SET);
            int j = pHeader[i].dwLength;
            //DBG_MSG("len=%d\n", j);
            while(j > 0)
            {
                if (j < sizeof(buf))
                {
                    j -= (pHeader[i].dwLength % sizeof(buf));
                    fread(buf, 1, (pHeader[i].dwLength % sizeof(buf)), fpNB0);
                    fwrite(buf, 1, (pHeader[i].dwLength % sizeof(buf)), fpTmp);
                }
                else
                {
                    fread(buf, 1, sizeof(buf), fpNB0);
                    fwrite(buf, 1, sizeof(buf), fpTmp);
                    j -= sizeof(buf);
                }
                //DBG_MSG("len=%d\n", j);
            }
            fclose(fpTmp);        
        }
        else
        if (strcmp(tmpBuf, DLlist->StaticNVFile) == 0)
        {   //filename match
            DBG_MSG("File %d ofs %x len %x '%s'\n", i, (pHeader[i].dwOffset + dwTotalHeaderSize), pHeader[i].dwLength, pHeader[i].bytFilename);
            //sprintf(tmpfilename, "%s/%s", tmpPath, DLlist->StaticNVFile);
            sprintf(tmpfilename, "%s/" FILENAME_STATIC_NV, tmpPath);
            if (!(fpTmp = fopen(tmpfilename, "w"))) 
            {
                //_LOGK("Unable to open '%s'\n", nv_def_filename);
                DBG_MSG("Unable to open '%s'\n", tmpfilename);
                return -errno;
            }
            fseek(fpNB0, (pHeader[i].dwOffset + dwTotalHeaderSize), SEEK_SET);
            int j = pHeader[i].dwLength;
            //DBG_MSG("len=%d\n", j);
            while(j > 0)
            {
                if (j < sizeof(buf))
                {
                    j -= (pHeader[i].dwLength % sizeof(buf));
                    fread(buf, 1, (pHeader[i].dwLength % sizeof(buf)), fpNB0);
                    fwrite(buf, 1, (pHeader[i].dwLength % sizeof(buf)), fpTmp);
                }
                else
                {
                    fread(buf, 1, sizeof(buf), fpNB0);
                    fwrite(buf, 1, sizeof(buf), fpTmp);
                    j -= sizeof(buf);
                }
                //DBG_MSG("len=%d\n", j);
            }
            fclose(fpTmp);        
        }
        DBG_MSG("File %d '%s' strlen %d\n", i, (char*)pHeader[i].bytFilename, strlen((char*)pHeader[i].bytFilename));
    }
    #endif

    return 0;
}

