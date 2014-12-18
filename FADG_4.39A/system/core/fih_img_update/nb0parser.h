#ifndef __NB0_PARSER_H_
#define __NB0_PARSER_H_

#define DL_FILENAME_LEN 32
#define FIRMWARE_LIST_MAGIC 0x464C4D00  //'F' 'L' 'M' 0x00
typedef struct dl_list
{
  uint32 MAGIC_NUM;
  uint32 iFLAG;// update flag, flag in mlf
  uint32 dl_flag;              /*bit 0 (1)be set-> dont' switch to backup even EFS parti diff*/
                                     /*bit 1 (2)be set-> combined image mode*/
                                     /*bit 2 (4)be set-> need backup and restore NV*/
                                     /*bit 3 (8)be set-> multi port download*/
                                    /*bit 4 (16)be set-> combined image multi port download*/
  char pCOMBINED_IMAGE[DL_FILENAME_LEN];
  int  aARMPRG_BIN[2];         /*[0]->image start address in combined file offset, [1]->image size */
  int  aPARTITION[2];
  int  aQCSBLHDCFG[2];
  int  aQCSBL[2];
  int  aOEMSBLHD[2];
  int  aOEMSBL[2];
  int  aAMSSHD[2];
  int  aAMSS[2];
  int  aAPPSBOOTHD[2];
  int  aAPPSBOOT[2];
  int  aAPPSHD[2];
  int  aAPPS[2];
  int  aCEFS[2];
  int  aWINCEHD[2];
  int  aWINCE[2];
  int  aANDROID_BOOT[2];
  int  aANDROID_SYSTEM[2];
  int  aANDROID_SPLASH[2];
  int  aANDROID_RECOVERY[2];
  int  aANDROID_HIDDEN[2];
  int  aANDROID_USR_DATA[2];
  int  aANDROID_FTM[2];
  int  aOSBLHD[2];
  int  aOSBL[2];
  int  aDBL[2];
  int  aFSBL[2];
  int  aDSP1[2];
  int  aDSP2[2];
  int  aANDROID_CDA[2];
  int  aCUSTOMER_NV[2];
  uint32 checksum;
}FirmwareList;

typedef struct _NB0ItemHead
{
	dword dwOffset; //start offset from the end of the header
	dword dwLength;//the size of the file
	byte	bytReserved[8];//value 0xFF
	byte	bytFilename[48]; //file name
} NB0ItemHead;

typedef struct _DOWNLOAD_FILE_LIST
{
	FirmwareList Flist;
	char NVDefFile[256];
	char NVCustomFile[256]; //file name
	char StaticNVFile[256];   //Static NV file name, ex: F0X_MP1_NV.xml
} DL_FILE_LIST;

typedef struct _MD5_Record
{
	dword dwOffset; //start offset from the end of the header
	dword dwLength;//the size of the file
	byte	bytMd5chksum[16];//Pre-calculated md5 check sum
} MD5_Record;

#define FILENAME_STATIC_NV  "static_nv.xml"
#define FILENAME_CUSTOM_NV  "cust_nv.xml"
#define FILENAME_BACKUP_NV  "backup_nv.xml"
#define FILENAME_DEFINITION_NV  "nvdefinition.xml"
#define FILENAME_PARTITION_TABLE    "partition.mbn"
#define FILENAME_TEMP_MLF   "temp.mlf"
#define FILENAME_ERASE_USER_DATA   "erase_userdata_"
#endif
