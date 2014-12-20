/* InfoDIAG.h
##############################################################################
# Copyright (c) 2008 FIHTDC, Inc. or its subsidiaries.
# All rights reserved.
##############################################################################*/

#ifndef _INFO_DIAG_
#define _INFO_DIAG_

//#include "Platform.h"
#include "libModemInterface.h"

#pragma pack(1)
    
#define NO_SUBID        0

#define DIAG_SW_ID       00
#define DIAG_NV_MAX_SIZE 01
#define DIAG_HW_ID       02
#define DIAG_BAT_VOLT    04
#define DIAG_FLASH_CAP   05


/* Version Number Request/Response            */
#define DIAG_VERNO_F    0

/* Mobile Station ESN Request/Response        */
#define DIAG_ESN_F      1

/* Peek byte Request/Response                 */
#define DIAG_PEEKB_F    2
  
/* Peek word Request/Response                 */
#define DIAG_PEEKW_F    3

/* Peek dword Request/Response                */
#define DIAG_PEEKD_F    4  

/* Poke byte Request/Response                 */
#define DIAG_POKEB_F    5  

/* Poke word Request/Response                 */
#define DIAG_POKEW_F    6  

/* Poke dword Request/Response                */
#define DIAG_POKED_F    7  

/* Byte output Request/Response               */
#define DIAG_OUTP_F     8

/* Word output Request/Response               */
#define DIAG_OUTPW_F    9  

/* Byte input Request/Response                */
#define DIAG_INP_F      10 

/* Word input Request/Response                */
#define DIAG_INPW_F     11 

/* DMSS status Request/Response               */
#define DIAG_STATUS_F   12 

/* 13-14 Reserved */

/* Set logging mask Request/Response          */
#define DIAG_LOGMASK_F  15 

/* Log packet Request/Response                */
#define DIAG_LOG_F      16 

/* Peek at NV memory Request/Response         */
#define DIAG_NV_PEEK_F  17 

/* Poke at NV memory Request/Response         */
#define DIAG_NV_POKE_F  18 

/* Invalid Command Response                   */
#define DIAG_BAD_CMD_F  19 

/* Invalid parmaeter Response                 */
#define DIAG_BAD_PARM_F 20 

/* Invalid packet length Response             */
#define DIAG_BAD_LEN_F  21 

/* 22-23 Reserved */

/* Packet not allowed in this mode 
   ( online vs offline )                      */
#define DIAG_BAD_MODE_F     24
                            
/* info for TA power and voice graphs         */
#define DIAG_TAGRAPH_F      25 

/* Markov statistics                          */
#define DIAG_MARKOV_F       26 

/* Reset of Markov statistics                 */
#define DIAG_MARKOV_RESET_F 27 

/* Return diag version for comparison to
   detect incompatabilities                   */
#define DIAG_DIAG_VER_F     28 
                            
/* Return a timestamp                         */
#define DIAG_TS_F           29 

/* Set TA parameters                          */
#define DIAG_TA_PARM_F      30 

/* Request for msg report                     */
#define DIAG_MSG_F          31 

/* Handset Emulation -- keypress              */
#define DIAG_HS_KEY_F       32 

/* Handset Emulation -- lock or unlock        */
#define DIAG_HS_LOCK_F      33 

/* Handset Emulation -- display request       */
#define DIAG_HS_SCREEN_F    34 

/* 35 Reserved */

/* Parameter Download                         */
#define DIAG_PARM_SET_F     36 

/* 37 Reserved */

/* Read NV item                               */
#define DIAG_NV_READ_F  38 
/* Write NV item                              */
#define DIAG_NV_WRITE_F 39 
/* 40 Reserved */

/* Mode change request                        */
#define DIAG_CONTROL_F    41 

/* Error record retreival                     */
#define DIAG_ERR_READ_F   42 

/* Error record clear                         */
#define DIAG_ERR_CLEAR_F  43 

/* Symbol error rate counter reset            */
#define DIAG_SER_RESET_F  44 

/* Symbol error rate counter report           */
#define DIAG_SER_REPORT_F 45 

/* Run a specified test                       */
#define DIAG_TEST_F       46 

/* Retreive the current dip switch setting    */
#define DIAG_GET_DIPSW_F  47 

/* Write new dip switch setting               */
#define DIAG_SET_DIPSW_F  48 

/* Start/Stop Vocoder PCM loopback            */
#define DIAG_VOC_PCM_LB_F 49 

/* Start/Stop Vocoder PKT loopback            */
#define DIAG_VOC_PKT_LB_F 50 

/* 51-52 Reserved */

/* Originate a call                           */
#define DIAG_ORIG_F 53 
/* End a call                                 */
#define DIAG_END_F  54 
/* 55-57 Reserved */

/* Switch to downloader                       */
#define DIAG_DLOAD_F 58 
/* Test Mode Commands and FTM commands        */
#define DIAG_TMOB_F  59 
/* Test Mode Commands and FTM commands        */
#define DIAG_FTM_CMD_F  59 
/* 60-62 Reserved */

#ifdef FEATURE_HWTC
#error code not present
#endif /* FEATURE_HWTC */

/* Return the current state of the phone      */
#define DIAG_STATE_F        63 

/* Return all current sets of pilots          */
#define DIAG_PILOT_SETS_F   64 

/* Send the Service Prog. Code to allow SP    */
#define DIAG_SPC_F          65 

/* Invalid nv_read/write because SP is locked */
#define DIAG_BAD_SPC_MODE_F 66 

/* get parms obsoletes PARM_GET               */
#define DIAG_PARM_GET2_F    67 

/* Serial mode change Request/Response        */
#define DIAG_SERIAL_CHG_F   68 

/* 69 Reserved */

/* Send password to unlock secure operations  
   the phone to be in a security state that
   is wasn't - like unlocked.                 */
#define DIAG_PASSWORD_F     70 

/* An operation was attempted which required  */
#define DIAG_BAD_SEC_MODE_F 71 

/* Write Preferred Roaming list to the phone. */
#define DIAG_PR_LIST_WR_F   72 

/* Read Preferred Roaming list from the phone.*/
#define DIAG_PR_LIST_RD_F   73 

/* 74 Reserved */

/* Subssytem dispatcher (extended diag cmd)   */
#define DIAG_SUBSYS_CMD_F   75 

/* 76-80 Reserved */

/* Asks the phone what it supports            */
#define DIAG_FEATURE_QUERY_F   81 

/* 82 Reserved */

/* Read SMS message out of NV                 */
#define DIAG_SMS_READ_F        83 

/* Write SMS message into NV                  */
#define DIAG_SMS_WRITE_F       84 

/* info for Frame Error Rate          
   on multiple channels                       */
#define DIAG_SUP_FER_F         85 

/* Supplemental channel walsh codes           */
#define DIAG_SUP_WALSH_CODES_F 86 

/* Sets the maximum # supplemental 
   channels                                   */
#define DIAG_SET_MAX_SUP_CH_F  87 

/* get parms including SUPP and MUX2: 
   obsoletes PARM_GET and PARM_GET_2          */
#define DIAG_PARM_GET_IS95B_F  88 

/* Performs an Embedded File System
   (EFS) operation.                           */
#define DIAG_FS_OP_F           89 

/* AKEY Verification.                         */
#define DIAG_AKEY_VERIFY_F     90 

/* Handset emulation - Bitmap screen          */
#define DIAG_BMP_HS_SCREEN_F   91 

/* Configure communications                   */
#define DIAG_CONFIG_COMM_F        92 

/* Extended logmask for > 32 bits.            */
#define DIAG_EXT_LOGMASK_F        93 

/* 94-95 reserved */

/* Static Event reporting.                    */
#define DIAG_EVENT_REPORT_F       96 

/* Load balancing and more!                   */
#define DIAG_STREAMING_CONFIG_F   97 

/* Parameter retrieval                        */
#define DIAG_PARM_RETRIEVE_F      98 

 /* A state/status snapshot of the DMSS.      */
#define DIAG_STATUS_SNAPSHOT_F    99
 
/* Used for RPC                               */
#define DIAG_RPC_F               100 

/* Get_property requests                      */
#define DIAG_GET_PROPERTY_F      101 

/* Put_property requests                      */
#define DIAG_PUT_PROPERTY_F      102 

/* Get_guid requests                          */
#define DIAG_GET_GUID_F          103 

/* Invocation of user callbacks               */
#define DIAG_USER_CMD_F          104 

/* Get permanent properties                   */
#define DIAG_GET_PERM_PROPERTY_F 105 

/* Put permanent properties                   */
#define DIAG_PUT_PERM_PROPERTY_F 106 

/* Permanent user callbacks                   */
#define DIAG_PERM_USER_CMD_F     107 

/* GPS Session Control                        */
#define DIAG_GPS_SESS_CTRL_F     108 

/* GPS search grid                            */
#define DIAG_GPS_GRID_F          109 

/* GPS Statistics                             */
#define DIAG_GPS_STATISTICS_F    110 

/* Packet routing for multiple instances of diag */
#define DIAG_ROUTE_F             111 

/* IS2000 status                              */
#define DIAG_IS2000_STATUS_F     112

/* RLP statistics reset                       */
#define DIAG_RLP_STAT_RESET_F    113

/* (S)TDSO statistics reset                   */
#define DIAG_TDSO_STAT_RESET_F   114

/* Logging configuration packet               */
#define DIAG_LOG_CONFIG_F        115

/* Static Trace Event reporting */
#define DIAG_TRACE_EVENT_REPORT_F 116

/* SBI Read */
#define DIAG_SBI_READ_F           117

/* SBI Write */
#define DIAG_SBI_WRITE_F          118

/* SSD Verify */
#define DIAG_SSD_VERIFY_F         119

/* Log on Request */
#define DIAG_LOG_ON_DEMAND_F      120

/* Request for extended msg report */
#define DIAG_EXT_MSG_F            121 

/* ONCRPC diag packet */
#define DIAG_ONCRPC_F             122

/* Diagnostics protocol loopback. */
#define DIAG_PROTOCOL_LOOPBACK_F  123

/* Extended build ID text */
#define DIAG_EXT_BUILD_ID_F       124

/* Request for extended msg report */
#define DIAG_EXT_MSG_CONFIG_F     125

/* Extended messages in terse format */
#define DIAG_EXT_MSG_TERSE_F      126

/* Translate terse format message identifier */
#define DIAG_EXT_MSG_TERSE_XLATE_F 127

/* Subssytem dispatcher Version 2 (delayed response capable) */
#define DIAG_SUBSYS_CMD_VER_2_F    128

/* Get the event mask */
#define DIAG_EVENT_MASK_GET_F      129

/* Set the event mask */
#define DIAG_EVENT_MASK_SET_F      130

/* RESERVED CODES: 131-139 */
#ifdef PALM_HW_VALIDATION
/* Palm general purpose test command */
#define DIAG_GP_READ_CMD_F         135
#define DIAG_GP_WRITE_CMD_F        136
#endif

/* Command Code for Changing Port Settings. */
#define DIAG_CHANGE_PORT_SETTINGS  140

/* Number of packets defined. */
#define DIAG_MAX_F                 140

typedef enum {
  DIAG_SUBSYS_OEM                = 0,       /* Reserved for OEM use */
  DIAG_SUBSYS_ZREX               = 1,       /* ZREX */
  DIAG_SUBSYS_SD                 = 2,       /* System Determination */
  DIAG_SUBSYS_BT                 = 3,       /* Bluetooth */
  DIAG_SUBSYS_WCDMA              = 4,       /* WCDMA */
  DIAG_SUBSYS_HDR                = 5,       /* 1xEvDO */
  DIAG_SUBSYS_DIABLO             = 6,       /* DIABLO */
  DIAG_SUBSYS_TREX               = 7,       /* TREX - Off-target testing environments */
  DIAG_SUBSYS_GSM                = 8,       /* GSM */
  DIAG_SUBSYS_UMTS               = 9,       /* UMTS */
  DIAG_SUBSYS_HWTC               = 10,      /* HWTC */
  DIAG_SUBSYS_FTM                = 11,      /* Factory Test Mode */
  DIAG_SUBSYS_REX                = 12,      /* Rex */
  DIAG_SUBSYS_OS                 = DIAG_SUBSYS_REX,
  DIAG_SUBSYS_GPS                = 13,      /* Global Positioning System */
  DIAG_SUBSYS_WMS                = 14,      /* Wireless Messaging Service (WMS, SMS) */
  DIAG_SUBSYS_CM                 = 15,      /* Call Manager */
  DIAG_SUBSYS_HS                 = 16,      /* Handset */
  DIAG_SUBSYS_AUDIO_SETTINGS     = 17,      /* Audio Settings */
  DIAG_SUBSYS_DIAG_SERV          = 18,      /* DIAG Services */
  DIAG_SUBSYS_FS                 = 19,      /* File System - EFS2 */
  DIAG_SUBSYS_PORT_MAP_SETTINGS  = 20,      /* Port Map Settings */
  DIAG_SUBSYS_MEDIAPLAYER        = 21,      /* QCT Mediaplayer */
  DIAG_SUBSYS_QCAMERA            = 22,      /* QCT QCamera */
  DIAG_SUBSYS_MOBIMON            = 23,      /* QCT MobiMon */
  DIAG_SUBSYS_GUNIMON            = 24,      /* QCT GuniMon */
  DIAG_SUBSYS_LSM                = 25,      /* Location Services Manager */
  DIAG_SUBSYS_QCAMCORDER         = 26,      /* QCT QCamcorder */
  DIAG_SUBSYS_MUX1X              = 27,      /* Multiplexer */
  DIAG_SUBSYS_DATA1X             = 28,      /* Data */
  DIAG_SUBSYS_SRCH1X             = 29,      /* Searcher */
  DIAG_SUBSYS_CALLP1X            = 30,      /* Call Processor */
  DIAG_SUBSYS_APPS               = 31,      /* Applications */
  DIAG_SUBSYS_SETTINGS           = 32,      /* Settings */
  DIAG_SUBSYS_GSDI               = 33,      /* Generic SIM Driver Interface */
  DIAG_SUBSYS_TMC                = 34,      /* Task Main Controller */
  DIAG_SUBSYS_USB                = 35,
  DIAG_SUBSYS_PM                 = 36,
  DIAG_SUBSYS_DEBUG              = 37,
  DIAG_SUBSYS_QTV                = 38,
  DIAG_SUBSYS_CLKRGM             = 39,      /* Clock Regime */
  DIAG_SUBSYS_DEVICES            = 40,
  DIAG_SUBSYS_WLAN               = 41,      /* 802.11 Technology */
  DIAG_SUBSYS_PS_DATA_LOGGING    = 42,      /* Data Path Logging */
  DIAG_SUBSYS_PS                 = DIAG_SUBSYS_PS_DATA_LOGGING,
  DIAG_SUBSYS_MFLO               = 43,
  DIAG_SUBSYS_DTV                = 44,      /* Digital TV */
  DIAG_SUBSYS_RRC                = 45,      /* WCDMA Radio Resource Control state */
  DIAG_SUBSYS_PROF               = 46,      /* Miscellaneous Profiling Related */
  DIAG_SUBSYS_TCXOMGR            = 47,
  DIAG_SUBSYS_NV                 = 48,
  DIAG_SUBSYS_AUTOCONFIG         = 49,
  DIAG_SUBSYS_PARAMS             = 50,      /* Parameters required for debugging subsystems */
  DIAG_SUBSYS_MDDI               = 51,      /* Mobile Display Digital Interface */
  DIAG_SUBSYS_DS_ATCOP           = 52,
  DIAG_SUBSYS_L4LINUX            = 53,      /* L4/Linux */
  DIAG_SUBSYS_MVS                = 54,      /* Multimode Voice Services */
  DIAG_SUBSYS_CNV                = 55,      /* Compact NV */
  DIAG_SUBSYS_APIONE_PROGRAM     = 56,      /* apiOne */
  DIAG_SUBSYS_HIT                = 57,      /* Hardware Integration Test */
  DIAG_SUBSYS_DRM                = 58,      /* Digital Rights Management */
  DIAG_SUBSYS_DM                 = 59,      /* Device Management */
  DIAG_SUBSYS_FC                 = 60,      /* Flow Controller */

  DIAG_SUBSYS_LAST,

  /* Subsystem IDs reserved for OEM use */
#ifndef PALM
  DIAG_SUBSYS_RESERVED_OEM_0     = 250,
  DIAG_SUBSYS_RESERVED_OEM_1     = 251,
  DIAG_SUBSYS_RESERVED_OEM_2     = 252,
  DIAG_SUBSYS_RESERVED_OEM_3     = 253,
  DIAG_SUBSYS_RESERVED_OEM_4     = 254,
  DIAG_SUBSYS_RESERVED_OEM_5     = 255,
#else
  DIAG_SUBSYS_PALM_FOTA          = 250,
  DIAG_SUBSYS_RESERVED_OEM_1     = 251,
  DIAG_SUBSYS_RESERVED_OEM_2     = 252,
  DIAG_SUBSYS_RESERVED_OEM_3     = 253,
  DIAG_SUBSYS_RESERVED_OEM_4     = 254,
  DIAG_SUBSYS_RESERVED_OEM_5     = 255,
#endif /* PALM */
} diagpkt_subsys_cmd_enum_type;

#ifdef PALM
typedef enum {
  DIAG_SUBSYS_PALM_FOTA_INIT         = 0,
  DIAG_SUBSYS_PALM_FOTA_INIT_RSP     = 1,
  DIAG_SUBSYS_PALM_FOTA_TX_DATA      = 2,
  DIAG_SUBSYS_PALM_FOTA_TX_DATA_RSP  = 3,
  DIAG_SUBSYS_PALM_FOTA_CHECKSUM     = 4,
  DIAG_SUBSYS_PALM_FOTA_CHECKSUM_RSP = 5,
  DIAG_SUBSYS_PALM_FOTA_SET_FLAG     = 6,
  DIAG_SUBSYS_PALM_FOTA_SET_FLAG_RSP = 7,
} diag_subsys_palm_fota_type;
#endif /* PALM */
///////////////////////////////








///////////////////////////
// DIAG VERSION
typedef struct DIAG_ONE_BYTE
{
	U8 CMD_CODE;
} DIAG_PACKET_REQ_VERSION, DIAG_PACKET_REQ_ESN,
DIAG_PACKET_REQ_STATUS,DIAG_PACKET_REQ_EXTENDED_BUILD_ID,
DIAG_PACKET_REQ_DOWNLOAD,DIAG_PACKET_RES_DOWNLOAD;

struct DIAG_PACKET_RES_VERSION
{
	U8 CMD_CODE;//0x00	
	U8 COMP_DATE[11];
	U8 COMP_TIME[8];
	U8 REL_DATE[11];
	U8 REL_TIME[8];
	U8 VER_DIR[8];
	U8 SCM;
	U8 MOB_CAI_REV;
	U8 MOB_MODEL;
	U8 MOB_FIRM_REV[2];
	U8 SLOT_CYCLE_INDEX;
	U8 MSM_VER[2];
};

typedef struct DIAG_PACKET_RES_ESN
{
	U8 CMD_CODE;
	U32 ESN;
} DIAG_PACKET_RES_CHANGE_MODEPONSE;

struct DIAG_PACKET_RES_STATUS
{
	U8 CMD_CODE;
	U8 RESERVED[3];
	U8 ESN[4];
	U8 RF_MODE[2];
	U8 MIN1_ANALOG[4];// (Analog)
	U8 MIN1_CDMA[4];// (CDMA)
	U8 MIN2_ANALOG[2];// (Analog)
	U8 MIN2_CDMA[2];// (CDMA) 2
	U8 RESERVED1;// 1
	U8 CDMA_RX_STATE[2];
	U8 CDMA_GOOD_FRAMES[1];
	U8 ANALOG_CORRECTED_FRAMES[2];
	U8 ANALOG_BAD_FRAMES[2];
	U8 ANALOG_WORD_SYNCS[2];
	U8 ENTRY_REASON[2];
	U8 CURRENT_CHAN[2];
	U8 CDMA_CODE_CHAN[1];
	U8 PILOT_BASE[2];
	U8 SID[2];
	U8 NID[2];
	U8 LOCAID[2];
	U8 RSSI[2];
	U8 POWER[1];
};


///////////////////////////
// DIAG CHANGE MODE
typedef struct DIAG_PACKET_CHANGE_MODE
{
	U8 CMD_CODE;// (41 / 0x29) 1

	U16 MODE;
				/*
				 0 ?Offline Analog mode
				 1 ?Offline Digital mode
				 2 ?Reset
				 3 ?Offline Factory Test mode
				 4 ?Online mode; in this mode, the mobile can acquire the
				system and make calls; it is the default mode
				*/
} DIAG_PACKET_REQ_CHANGE_MODE, DIAG_PACKET_RES_CHANGE_MODE;

///////////////////////////
// DIAG SERIVCE PRGRAMMING CODE
struct DIAG_PACKET_REQ_SERVICE_PROGRAMMING_CODE
{
	U8 CMD_CODE;// (41 / 0x29) 1
	U8 SECURITY_CODE[6];
};
typedef struct DIAG_PACKET_DIP_SWITCH
{
	U8 CMD_CODE;// (48 / 0x29) 1
	U16 SWITCH_CODE;
}DIAG_PACKET_REQ_DIP_SWITCH,DIAG_PACKET_RES_DIP_SWITCH;

//////////////////////////
// DIAG SERIVCE PRGRAMMING CODE RESULT
enum SERVICE_PROGRAMMING_SPC_RESULT
{
	SPC_RESULT_FAILED,//0 ?Code was incorrect and SP is still locked
	SPC_RESULT_SUCCESS//1 ?Code was correct and Service Programming (SP) is unlocked
};

struct DIAG_PACKET_RES_SERVICE_PROGRAMMING_CODE
{
	U8 CMD_CODE;// (41 / 0x29) 1
	U8 SPC_RESULT;
};

///////////////////////////
// DIAG EXTENDED BUILD ID
#define EXTENDED_BUILD_ID_INFO_SIZE 256
struct DIAG_PACKET_RES_EXTENDED_BUILD_ID
{
	U8 CMD_CODE;// (124 / 0x7C) 1
	U8 RESERVED[3];
 
	U32 MSM_HW_VERSION;
	U32 MOB_MODEL;
 
	U8 Info[EXTENDED_BUILD_ID_INFO_SIZE];
};
 
typedef struct
{
	U8 CMD_CODE;// (75 / 0x4B) 1 Message ID
				//The DM sets CMD_CODE to 75 for this message.
	U8 SUBSYS_ID;// 1 Subsystem identifier
				//	This is an enumeration of all defined subsystems.
	U16 SUBSYS_CMD_CODE;/* 2 Command code for the given subsystem
				This defines the subsystem packet in the same manner that
				the CMD_CODE field defines this packet as a �Dispatch?
				packet.
				REQUEST Variable Request packet data for this command
				This is defined separately for each command.
				*/
} diagpkt_subsys_header_type; 

 
#define PRL_READ_DATA_SIZE 120
struct DIAG_PACKET_REQ_PRL_READ
{
	U8 CMD_CODE;// (73 / 0x49) 1
	U8 SEQ_NUM;// 1
	U8 NAM;// 1
	/*
	CMD_CODE ?Message ID
	The DM sets CMD_CODE to 73 for this message.
	SEQ_NUM ?Sequence number
	 0 ?First request for the PRL
	 Subsequent requests ?SEQ_NUM equal to the previous
	SEQ_NUM + 1
	NAM ?PRL associated with this NAM is the one requested
	*/
};

struct DIAG_PACKET_RES_PRL_READ
{
	U8 CMD_CODE;// (73 / 0x49) 1
	U8 PR_LIST_STATUS;// 1
	U16 NV_STATUS;// 2
	U8 SEQ_NUM;// 1
	U8 MORE;// 1
	U16 NUM_BITS;// 2
	U8 DATA[PRL_READ_DATA_SIZE];
	/*
	CMD_CODE ?Message ID
	The phone sets CMD_CODE to 73 for this message.
	PR_LIST_STATUS ?Status of Preferred Roaming List Read
	 0 ?No errors
	 1 ?NV read failure
	NV_STATUS ?If PR_LIST_STATUS is 1 (status from NV was not normal
	DONE status), then this field contains the status returned by
	the NV task; otherwise this field is undefined
	 0 ?Request completed OK
	 1 ?Internal use
	 2 ?Unrecognizable command
	 3 ?NV memory is full (should not get this status for a read
	request)
	 4 ?Command failed
	 5 ?Variable was not active
	 6 ?Bad parameter in command block
	 7 ?Item was read-only (should not get this status for a
	read request)
	 8 ?Item not defined for this target
	 9 ?Free memory exhausted (should not get this status for
	a read request)
	 10 ?Internal use
	SEQ_NUM ?Sequence number of this block of data
	 0 ?First block
	 All subsequent blocks ?Previous SEQ_NUM + 1
	MORE ?Block status
	 1 ?More data blocks after this one
	 0 ?Last data block
	NUM_BITS ?Number of valid bits in the data block (1 to 960)
	DATA ?Block of PRL data
	All bytes will always be sent across the link, but only
	NUM_BITS bits are valid data.
	*/
};

#define PRL_WRITE_DATA_SIZE 120
struct DIAG_PACKET_REQ_PRL_WRITE
{
	U8 CMD_CODE;// (72 / 0x48) 1 Message ID
	U8 SEQ_NUM;/* 1 Sequence number of this block of data
				 0 ?First block
				 All subsequent blocks ?Previous SEQ_NUM + 1
				 */
	U8 MORE;/* 1 Block status
			 1 ?More data blocks to come
			 0 ?Last data block
			*/
	U8 NAM;// 1 NAM with which this PRL is associated
	U16 NUM_BITS;/*
				 2 Number of valid bits in the data block (1 to 960)
				This will always be exactly 960 except for the last block,
				which may have fewer valid bits.
				*/
	U8 DATA[PRL_WRITE_DATA_SIZE];
				/* 120 Block of PRL data
				All bytes will always be sent across the link, but only
				NUM_BITS bits are valid data.
				*/
};

struct DIAG_PACKET_RES_PRL_WRITE
{
	U8 CMD_CODE;/* (72 / 0x48) 1 Message ID
				The phone sets CMD_CODE to 72 for this message.
				*/
	U8 PR_LIST_STATUS;/* Status of Preferred Roaming List Write
					 0 ?Received block successfully (not the last block)
					 1 ?Received last block successfully and wrote completed
					PRL to NV
					 2 ?Received block with SEQ_NUM out of order
					 3 ?Overflowed maximum PRL size
					*/
	U16 NV_STATUS; /*
				  If PR_LIST_STATUS is 1 (wrote PRL to NV), then this field
					contains the status returned by the NV task; otherwise, this
					field is undefined
					 0 ?Request completed OK
					 1 ?Internal use
					 2 ?Unrecognizable command
					 3 ?NV memory is full
					 4 ?Command failed
					 5 ?Variable was not active (should not get this status for
					a write command)
					 6 ?Bad parameter in command block
					 7 ?Item was read-only
					 8 ?Item not defined for this target
					 9 ?Free memory exhausted
					 10 ?Internal use
					*/
};

////////////////////////////////
// Get NV Max_size
typedef struct DIAG_PACKET_BASIC
{
    U8  CMD_CODE;
	
    U8  SUB_ID;

	U16 SUB_CMD_CODE;
} DIAG_PACKET_SW_ID,DIAG_PACKET_HW_ID,DIAG_PACKET_NV_MaxSize,
DIAG_PACKET_BAT_VOLT,DIAG_PACKET_REQ_FLASH_TYPE;

struct DIAG_PACKET_RSP_HW_ID
{
    U8  CMD_CODE;
		
    U8  SUB_ID;

	U16 SUB_CMD_CODE;/* 0200*/

	char HW_ID[DIAGOEM_HWID_DATE_STRLEN]; 
};

struct DIAG_PACKET_RSP_BAT_VOLT
{
    U8  CMD_CODE;
		
    U8  SUB_ID;

	U16 SUB_CMD_CODE;

	U16 BAT_VOLT; 
};


struct DIAG_PACKET_RSP_SW_ID
{
    U8  CMD_CODE;
		
    U8  SUB_ID;

	U16 SUB_CMD_CODE;/* 0000*/

    char comp_date	 [ DIAGOEM_VERNO_DATE_STRLEN ];  /* Compile date Jun 11 1991   */
	
    char comp_time	 [ DIAGOEM_VERNO_TIME_STRLEN ];  /* Compile time hh:mm:ss	   */
	
    char rel_date	 [ DIAGOEM_VERNO_DATE_STRLEN ];  /* Release date			   */
	
    char rel_time	 [ DIAGOEM_VERNO_TIME_STRLEN ];  /* Release time			   */
	
    char mob_rev	 [ DIAGOEM_VERNO_MOB_REV_STRLEN ];	/* PRJ-n-nnnn-nnnn-n */
};

struct DIAG_PACKET_RES_FLASH_TYPE
{
    U8  CMD_CODE;
		
    U8  SUB_ID;

	U16 SUB_CMD_CODE;/* 0000*/

    char flash_name[DIAGOEM_FLASH_NAME_LEN];
    
    U32 block_count;
};

struct DIAG_PACKET_RSP_NV_MaxSize
{
    U8  CMD_CODE;
		
    U8  SUB_ID;

	U16 SUB_CMD_CODE;/* 0100*/

	U16 max_UNV; 

	U16 max_QNV;
};

struct DIAG_PACKET_NVRSP
{

U16 NV_ITEM;/* 2 Item ID
			The DM sets this field to select the item to be written. The
			values shall be as shown in Chapter 6.
			*/
U8 ITEM_DATA[128];
};
////////////////////////////////
// NV read/write
typedef struct DIAG_PACKET_NV
{
	U8 CMD_CODE;/* (39 / 0x27)  write 
				   (38 / 0x26)  read
				The DM sets CMD_CODE to 39 for this message.
				*/
	U16 NV_ITEM;/* 2 Item ID
				The DM sets this field to select the item to be written. The
				values shall be as shown in Chapter 6.
				*/
	U8 ITEM_DATA[128];
				/*Nonvolatile memory data item
				The DM may specify parameters in this area (to select one
				of an array of elements, for example). The DMSS places
				the data to be written in this field. The format shall be as
				shown in Chapter 6.
				*/
	U16 STATUS; /* 2 Status of the NV Write operation
				The DMSS sets this field to indicate the status of the write
				operation:
				 0 ?Request completed OK
				 1 ?Internal DMSS use
				 2 ?Unrecognizable command
				 3 ?NV memory is full
				 4 ?Command failed
				 5 ?Variable was not active (never written) (should not
				get this status in a write response)
				 6 ?Bad parameter in command block (may indicate this
				item does not exist for this phone or for the specified
				index for this phone)
				 7 ?Item was read-only
				 8 ?Item not defined for this target
				 9 ?Free memory exhausted
				 10 ?Internal use
				*/
//} DIAG_PACKET_REQ_NV_WRITE, DIAG_PACKET_RES_NV_WRITE, DIAG_PACKET_NV;
} DIAG_PACKET_REQ_NV_WRITE, DIAG_PACKET_NV;


enum BIO_SW
{
	BIO_SW1_M = 0x0080,//0000000010000000b;// IF loopback
	BIO_SW2_M = 0x0040,//0000000001000000b;// Reload Reverse Link long code each 80-ms frame
	BIO_SW3_M = 0x0020,//0000000000100000b;// Forward Link scrambling disable
	BIO_SW4_M = 0x0010,//0000000000010000b;// Forward Link puncturing disable
	BIO_SW5_M = 0x0008,//0000000000001000b;// Reverse Link power control disable
	BIO_SW6_M = 0x0004,//0000000000000100b;// Turn Tx power on during acquisition and sync channel
	BIO_SW7_M = 0x0002,//0000000000000010b;// Sounder mode
	BIO_SW8_M = 0x0001,//0000000000000001b;// Force Reverse Link voice to full rate
	BIO_SW9_M = 0x0100,//0000000100000000b;// Turn off sleep mode operation
	BIO_SW10_M = 0x0200//0000001000000000b;// Suppress VOX and audio filters
};

typedef struct DIAG_PACKET_DIP
{
	U8 CMD_CODE;/* Message ID
				*/
	U16 SWITCHES;/* value for software DIP switches
				*/
} DIAG_PACKET_REQ_DIP_RETRIEVAL,DIAG_PACKET_RES_DIP_RETRIEVAL,
DIAG_PACKET_REQ_DIP_SET,DIAG_PACKET_RES_DIP_SET;

#endif
