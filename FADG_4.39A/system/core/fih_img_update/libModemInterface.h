/* libModemInterface.h
##############################################################################
# Copyright (c) 2008 FIHTDC, Inc. or its subsidiaries.
# All rights reserved.
##############################################################################*/

#include "comdef.h"
#ifndef _LIB_MODEM_INTERFACE_H_
#define _LIB_MODEM_INTERFACE_H_

////////////////////////////////
// interface info
#define LIB_NAME_MODEM_UPDATER        TEXT("QPD.dll")     //< modemUpdater library path

#define DIAGOEM_HWID_DATE_STRLEN      6
#define DIAGOEM_VERNO_DATE_STRLEN     11
#define DIAGOEM_VERNO_TIME_STRLEN      8
#define DIAGOEM_VERNO_MOB_REV_STRLEN  17
#define DIAGOEM_FLASH_NAME_LEN  32

#define DLOAD_RETRY_TIMES 3

#define DIAG_RETRY_TIMES 3




enum MODEM_UPDATER_ERROR
{
	MODEM_UPDATER_ERROR_NONE,// success, no error
	MODEM_UPDATER_WARNING_NOT_Diag_MODE,
	MODEM_UPDATER_ERROR_UNSUPPORTED,// miscellaneous error
	MODEM_UPDATER_ERROR_UNKNOWN,// unknown error
	MODEM_UPDATER_ERROR_OPEN_PORT,
	MODEM_UPDATER_ERROR_OPEN_NV_FILE,
	MODEM_UPDATER_ERROR_NO_MODEM_SERVICE,
	MODEM_UPDATER_ERROR_UPDATE_FW,
	MODEM_UPDATER_ERROR_UPDATE_UA,  //FOTA UA
	MODEM_UPDATER_ERROR_UPDATE_PRL,
	MODEM_UPDATER_ERROR_UPDATE_PRI,
	MODEM_UPDATER_ERROR_OTA_UPDATE_FW,
	MODEM_UPDATER_ERROR_OTA_UPDATE_PRL,
	MODEM_UPDATER_ERROR_OTA_UPDATE_PRI,
	MODEM_UPDATER_ERROR_OTA_UPDATE_MODEM,
	
	MODEM_UPDATER_ERROR_MBN_FILE_NONEXISTENCE,

    MODEM_UPDATER_ERROR_RBUFFER,      //cant get rsp or get error rsp
    MODEM_UPDATER_ERROR_TBUFFER,       //cant send data to transmit buffer
	
	MODEM_UPDATER_ERROR_NPRG_HEX_TO_BIN,   //maybe buffer size to small
	
	MODEM_UPDATER_ERROR_DMSS_GetVersion_RSP,
    MODEM_UPDATER_ERROR_DMSS_GetVersion_TIMEOUT,
    MODEM_UPDATER_ERROR_DMSS_GetVersion_TBUFFER,
    
	MODEM_UPDATER_ERROR_DMSS_Write32_NAK,  //maybe with reason    
	MODEM_UPDATER_ERROR_DMSS_Write32_RSP,
    MODEM_UPDATER_ERROR_DMSS_Write32_TIMEOUT,
    MODEM_UPDATER_ERROR_DMSS_Write32_TBUFFER,    
	MODEM_UPDATER_ERROR_DMSS_WRITE32_PKT_TOBIG,	  //NPRG or FirmwareImage pkt size to big

	MODEM_UPDATER_ERROR_DMSS_GO_NAK,
	MODEM_UPDATER_ERROR_DMSS_GO_RSP,
    MODEM_UPDATER_ERROR_DMSS_GO_TIMEOUT,
    MODEM_UPDATER_ERROR_DMSS_GO_TBUFFER,
    
    MODEM_UPDATER_ERROR_FIRMWARE_OPEN_FAIL,
    MODEM_UPDATER_ERROR_FIRMWARE_READ_FAIL,
    MODEM_UPDATER_ERROR_FIRMWARE_READ_END,
    MODEM_UPDATER_ERROR_ARMPRG_NAK,
    
	MODEM_UPDATER_ERROR_ARMPRG_hello_NAK,
    MODEM_UPDATER_ERROR_ARMPRG_hello_RSP,
   	MODEM_UPDATER_ERROR_ARMPRG_hello_TIMEOUT,
	MODEM_UPDATER_ERROR_ARMPRG_hello_TBUFFER,
	MODEM_UPDATER_ERROR_ARMPRG_hello_OLD_VERSION,
	
	MODEM_UPDATER_ERROR_ARMPRG_SECURITY_NAK,
    MODEM_UPDATER_ERROR_ARMPRG_SECURITY_RSP,
   	MODEM_UPDATER_ERROR_ARMPRG_SECURITY_TIMEOUT,
	MODEM_UPDATER_ERROR_ARMPRG_SECURITY_TBUFFER,
	    
	MODEM_UPDATER_ERROR_ARMPRG_PARTITION_NAK,
  	MODEM_UPDATER_ERROR_ARMPRG_PARTITION_RSP,
	MODEM_UPDATER_ERROR_ARMPRG_PARTITION_TIMEOUT,
	MODEM_UPDATER_ERROR_ARMPRG_PARTITION_TBUFFER,	
    MODEM_UPDATER_ERROR_ARMPRG_PARTITION_FILE_OPEN_FAIL,
    MODEM_UPDATER_ERROR_ARMPRG_PARTITION_READ,
    MODEM_UPDATER_ERROR_ARMPRG_PARTITION_OVERFLOW,//pload size to big
    MODEM_UPDATER_ERROR_ARMPRG_PARTITION_DIFF,
    MODEM_UPDATER_ERROR_ARMPRG_PARTITION_FORMAT,
    MODEM_UPDATER_ERROR_ARMPRG_PARTITION_ERASE_FAIL,
/*QPD_CR#4 start fix the problem of  CEFS partition will be erased when CEFS partition changed*/
    MODEM_UPDATER_ERROR_ARMPRG_PARTITION_EFS_DIFF,
/*QPD_CR#4 end*/
    
	   	
	MODEM_UPDATER_ERROR_ARMPRG_OPENMUTI_NAK,
	MODEM_UPDATER_ERROR_ARMPRG_OPENMUTI_RSP,
	MODEM_UPDATER_ERROR_ARMPRG_OPENMUTI_TIMEOUT,
	MODEM_UPDATER_ERROR_ARMPRG_OPENMUTI_TBUFFER,
	MODEM_UPDATER_ERROR_ARMPRG_OPENMUTI_READ,
    MODEM_UPDATER_ERROR_ARMPRG_OPENMUTI_UNKNOWN_ERR,
    MODEM_UPDATER_ERROR_ARMPRG_OPENMUTI_PAYLOAD_REQUIRED,
    MODEM_UPDATER_ERROR_ARMPRG_OPENMUTI_PAYLOAD_NOT_ALLOWED,
    MODEM_UPDATER_ERROR_ARMPRG_OPENMUTI_LENGTH_EXCEEDED,
	   			
	MODEM_UPDATER_ERROR_ARMPRG_Write32_NAK,
  	MODEM_UPDATER_ERROR_ARMPRG_Write32_RSP,
	MODEM_UPDATER_ERROR_ARMPRG_Write32_TIMEOUT,
	MODEM_UPDATER_ERROR_ARMPRG_Write32_TBUFFER,
	MODEM_UPDATER_ERROR_ARMPRG_Write32_PKT_TOBIG,
	   		
	MODEM_UPDATER_ERROR_ARMPRG_CLOSE_NAK,
  	MODEM_UPDATER_ERROR_ARMPRG_CLOSE_RSP,
	MODEM_UPDATER_ERROR_ARMPRG_CLOSE_TIMEOUT,
	MODEM_UPDATER_ERROR_ARMPRG_CLOSE_TBUFFER,
	   	
	MODEM_UPDATER_ERROR_ARMPRG_RESET_NAK,
   	MODEM_UPDATER_ERROR_ARMPRG_RESET_RSP,
   	MODEM_UPDATER_ERROR_ARMPRG_RESET_TIMEOUT,
   	MODEM_UPDATER_ERROR_ARMPRG_RESET_TBUFFER,

	MODEM_UPDATER_ERROR_ARMPRG_ERASE_NAK,
   	MODEM_UPDATER_ERROR_ARMPRG_ERASE_RSP,
	MODEM_UPDATER_ERROR_ARMPRG_ERASE_TIMEOUT,
	MODEM_UPDATER_ERROR_ARMPRG_ERASE_TBUFFER,

    MODEM_UPDATER_ERROR_ARMPRG_CRC_FAIL,
    MODEM_UPDATER_ERROR_ARMPRG_PKT_LOSE,
    MODEM_UPDATER_ERROR_ARMPRG_PKT_LOSE_TO_MUCH,
	
	MODEM_UPDATER_ERROR_Diag_Get_VERSION,
	MODEM_UPDATER_ERROR_Diag_Get_NV_Size,
	MODEM_UPDATER_ERROR_Diag_HW_ID,
	MODEM_UPDATER_ERROR_Diag_SW_ID,
	MODEM_UPDATER_ERROR_Diag_BAT_VOLT,	
	MODEM_UPDATER_ERROR_Diag_FLASH_CAP,
	MODEM_UPDATER_ERROR_Diag_NV_BACKUP,
	MODEM_UPDATER_ERROR_Diag_NV_RESTORE,
	MODEM_UPDATER_ERROR_Diag_NV_UPDATE,
	MODEM_UPDATER_ERROR_Diag_NV_WRITE,
	MODEM_UPDATER_ERROR_Diag_NV_READ,
	MODEM_UPDATER_ERROR_Diag_NV_READ_WARNING,	
	MODEM_UPDATER_ERROR_Diag_NV_UNDEFINE,
	MODEM_UPDATER_ERROR_Diag_SPC,
	MODEM_UPDATER_ERROR_SwitchToDLOAD,
	MODEM_UPDATER_ERROR_DIAG_Reset,
	MODEM_UPDATER_ERROR_CHANGE_MODE_TIMEOUT,	
	MODEM_UPDATER_ERROR_CHANGE_MODE_TBUFFER,
	MODEM_UPDATER_ERROR_MODE_UNKNOWN,
	
	MODEM_UPDATER_ERROR_EFS,
	MODEM_UPDATER_ERROR_EFS_PC_CREATE_FILE,
	MODEM_UPDATER_ERROR_EFS_PC_READ_FILE,
	MODEM_UPDATER_ERROR_EFS_PC_WRITE_FILE,
	MODEM_UPDATER_ERROR_EFS_PACKET_DATA_SIZE,
	MODEM_UPDATER_ERROR_EFS_PACKET_OFFSET,
	MODEM_UPDATER_ERROR_EFS_OPEN_FAIL,
	MODEM_UPDATER_ERROR_EFS_ERR_PERMIT,
	MODEM_UPDATER_ERROR_EFS_NO_FILE,
	MODEM_UPDATER_ERROR_EFS_FILE_EXIST,
	MODEM_UPDATER_ERROR_EFS_BAD_FILE_DESCRIPTOR, 
	MODEM_UPDATER_ERROR_EFS_PERMISSION_DENIED,
	MODEM_UPDATER_ERROR_EFS_BUSY,
    MODEM_UPDATER_ERROR_EFS_INVALID_ARGUMENT,
    MODEM_UPDATER_ERROR_EFS_NO_SPACE,
    MODEM_UPDATER_ERROR_EFS_NAMED_TOO_LONG,
    MODEM_UPDATER_ERROR_EFS_NOT_DIRECTORY,

    MODEM_UPDATER_ERROR_DYNALLOCATE_MEM,
    MODEM_UPDATER_ERROR_LoadDebugViewDll,
	MODEM_UPDATER_ERROR_UnLoadDebugViewDll,

    MODEM_UPDATER_ERROR_LoadSHMEMDll

};

#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )

typedef enum PORT_TYPE
{
	PORT_UART,
	PORT_USB
} PORT_TYPE;
#if 0   //paul
typedef struct LIB_INFO
{
	PTCHAR pName;
	PTCHAR pVersion;
} LIB_INFO;
#endif //paul
struct SoftwareID
{
	char comp_date	 [ DIAGOEM_VERNO_DATE_STRLEN ];  /* Compile date Jun 11 1991   */
	char comp_time	 [ DIAGOEM_VERNO_TIME_STRLEN ];  /* Compile time hh:mm:ss	   */
	char rel_date	 [ DIAGOEM_VERNO_DATE_STRLEN ];  /* Release date			   */
	char rel_time	 [ DIAGOEM_VERNO_TIME_STRLEN ];  /* Release time			   */
	char mob_rev	 [ DIAGOEM_VERNO_MOB_REV_STRLEN ];	/* PRJ-n-nnnn-nnnn-n */
};
    #if 0   //paul
enum CarrierID
{
	PALM_CARRIER_ROW,      // ((nv_carrier_id_type)0)
	PALM_CARRIER_VZW,      // ((nv_carrier_id_type)1)
	PALM_CARRIER_SPRINT,   // ((nv_carrier_id_type)2)
	NO_CARRIER_ID = -1  
};
/////////////////////////////////

typedef unsigned char U8;
typedef unsigned short U16;

struct FirmwareList
{
U16 *iFLAG;// update flag
U8 *dl_flag;                 /*bit 0 (1)be set-> dont' switch to backup even EFS parti diff*/
                             /*bit 1 (2)be set-> combined image mode*/
                             /*bit 2 (4)be set-> need backup and restore NV*/
                             /*bit 3 (8)be set-> multi port download*/
//TCHAR* pFwDir;
TCHAR pFwDir[MAX_PATH];
TCHAR* pCOMBINED_IMAGE;                          
TCHAR* pARMPRG_HEX;
TCHAR* pARMPRG_BIN;
TCHAR* pPARTITION;
TCHAR* pQCSBLHDCFG;
TCHAR* pQCSBL;
TCHAR* pOEMSBLHD;
TCHAR* pOEMSBL;
TCHAR* pAMSSHD;
TCHAR* pAMSS;
TCHAR* pAPPSBOOTHD;
TCHAR* pAPPSBOOT;
TCHAR* pAPPSHD;
TCHAR* pAPPS;
TCHAR* pCEFS;
TCHAR* pWINCE;
TCHAR* pFOTA_UA;
TCHAR* pANDROID_BOOT;
TCHAR* pANDROID_SYSTEM;
TCHAR* pANDROID_SPLASH;
TCHAR* pANDROID_RECOVERY;
TCHAR* pANDROID_HIDDEN;
TCHAR* pANDROID_USR_DATA;
TCHAR* pANDROID_FTM;




int* aARMPRG_HEX[2];     /*[0]->image start address in combined file
                           [1]->image size                           */
int* aPARTITION[2];
int* aQCSBLHDCFG[2];
int* aQCSBL[2];
int* aOEMSBLHD[2];
int* aOEMSBL[2];
int* aAMSSHD[2];
int* aAMSS[2];
int* aAPPSBOOTHD[2];
int* aAPPSBOOT[2];
int* aAPPSHD[2];
int* aAPPS[2];
int* aCEFS[2];
int* aWINCE[2];
int* aFOTA_UA[2];
int* aANDROID_BOOT[2];
int* aANDROID_SYSTEM[2];
int* aANDROID_SPLASH[2];
int* aANDROID_RECOVERY[2];
int* aANDROID_HIDDEN[2];
int* aANDROID_USR_DATA[2];
int* aANDROID_FTM[2];

};

struct EFS_FILE_DESCRIPTOR
{
TCHAR EFS_FILE_PATH_PHONE[MAX_PATH]; 
TCHAR EFS_FILE_PATH_PC[MAX_PATH]; 
};
struct device_info
{
  char   flash_name[DIAGOEM_FLASH_NAME_LEN];
  uint32  capacity;
};


#include "libModemInterfaceFota.h"
#include "libModemInterfaceHost.h"
#include "libModemInterfaceTools.h"

#include "Port.h"

extern "C"
{
    DllExport MODEM_UPDATER_ERROR MuUpdateFirmware(char *iPortType, FirmwareList pFirmware);    
	DllExport MODEM_UPDATER_ERROR SwitchToDLOADMode(Port* pPort_f);
    DllExport MODEM_UPDATER_ERROR DIAG_ResetPhone(Port* pPort_f);
    DllExport MODEM_UPDATER_ERROR Write_NV(Port* pPort_f, int aNV_ID, U8 *aNV_DATA);
    DllExport MODEM_UPDATER_ERROR Read_NV(Port* pPort_f, int aNV_ID, U8 *aNV_DATA);
    DllExport MODEM_UPDATER_ERROR MuBackupPhoneData(Port* pPort_f, char *filname_b,char *filname_d);
    DllExport MODEM_UPDATER_ERROR MuRestorePhoneData(Port* pPort_f,U8 *iFlag, char *filname_b,char *filname_u, char *filname_d);
	DllExport MODEM_UPDATER_ERROR Erase_Flash(char* iPortType,FirmwareList oFWList);
    DllExport MODEM_UPDATER_ERROR Get_Sw_ID(Port* pPort_f,SoftwareID *sw_id);
	DllExport MODEM_UPDATER_ERROR Get_Hw_ID(Port* pPort_f,char* hw_id);
    DllExport MODEM_UPDATER_ERROR Get_BAT_VOLT(Port* pPort_f,U16* bat_volt);
    DllExport MODEM_UPDATER_ERROR Get_FLASH_TYPE(Port* pPort_f, device_info* flash);
	DllExport MODEM_UPDATER_ERROR Get_DIAG_Info(Port* pPort_f);
	DllExport MODEM_UPDATER_ERROR Read_Page(Port* pPort_d,FirmwareList oFWList, char *data, int page);
	DllExport MODEM_UPDATER_ERROR DLOAD_mode_check(Port* pPort_d);
	DllExport MODEM_UPDATER_ERROR MuRead_EFS_FILE(Port* pPort_f, FirmwareList *f_list, EFS_FILE_DESCRIPTOR *efs_file);
    DllExport MODEM_UPDATER_ERROR MuWrite_EFS_FILE(Port* pPort_f, FirmwareList *f_list, EFS_FILE_DESCRIPTOR *efs_file);
    DllExport MODEM_UPDATER_ERROR MuDel_EFS_FILE(Port* pPort_f, FirmwareList *f_list, EFS_FILE_DESCRIPTOR *efs_file);

	
	DllExport MODEM_UPDATER_ERROR UnloadDebugView();\
	DllExport MODEM_UPDATER_ERROR MuGetLibInfo(LIB_INFO &oInfo);\
	DllExport MODEM_UPDATER_ERROR InitDebugView(char *sLogPath, char *sMsName, char *sDebugViewDllPath, char *port_num);
	

	//////////////////////////
	// Interface for FOTA; see libModemInterfaceFota.h
	//
	LibModemInterfaceFota;

	///////////////////////////
	// Interface for SD updater; see libModemInterfaceHost.h
	//
	LibModemInterfaceHost;

	///////////////////////////
	// Interface for Fota tester
	//
	LibModemInterfaceFotaEx;
	
	LibModemInterfaceTools;

};

//////////////////////////////////
// GetInfo
#define PROC_LibGetInfo         TEXT("MuGetLibInfo")         
typedef MODEM_UPDATER_ERROR (*pPROC_LibGetInfo)(LIB_INFO &oInfo);

#define PROC_LibFirmwareUpdate	TEXT("MuUpdateFirmware")
typedef MODEM_UPDATER_ERROR (*pPROC_LibFirmwareUpdate)(/*in*/PTCHAR pFirmware,char *iPortType,/*combination of UPDATE_FLAG*/U8 *iFlag);

#define PROC_InitDebugView		TEXT("InitDebugView")
typedef void (*pPROC_InitDebugView)(/*in*/char *sLogPath, char *sMsName, char *sDebugViewDllPath, char *port_num);

#define PROC_LibBackupPhoneData		TEXT("MuBackupPhoneData")
typedef MODEM_UPDATER_ERROR (*pPROC_BackupPhoneData)(/*in*/char *port_num, char *filname);

#define PROC_LibRestorePhoneData		TEXT("MuRestorePhoneData")
typedef MODEM_UPDATER_ERROR (*pPROC_RestorePhoneData)(/*in*/char *port_num, U8 iFlag, char *filname);

#define PROC_LibSwitchToDLOADMode		TEXT("SwitchToDLOADMode")
typedef MODEM_UPDATER_ERROR (*pPROC_LibSwitchToDLOADMode)(char *port_num);

#define PROC_LibDIAGResetPhone		TEXT("DIAG_ResetPhone")
typedef MODEM_UPDATER_ERROR (*pPROC_LibDIAGResetPhone)(char *port_num);


#define PROC_LibWriteNV		TEXT("Write_NV")
typedef MODEM_UPDATER_ERROR (*pPROC_LibWriteNV)(char *port_num, int aNV_ID, U8 *aNV_DATA);
    #endif //paul
#endif
