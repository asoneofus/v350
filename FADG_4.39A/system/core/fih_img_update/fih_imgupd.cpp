
/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
#include <sys/reboot.h>
#include <unistd.h>

#include <cutils/config_utils.h>
#include <cutils/cpu_info.h>
#include <cutils/properties.h>
#include <cutils/sockets.h>

#include <linux/netlink.h>

//using namespace std;

//#include   "cmath"
#include "utilcrc.h"
#include "QualcommModemUtil.h"
#include "infoDIAG.h"
#include "libModemInterface.h"
#include "tinyxml.h"
#include "nb0parser.h"
#define NOT_USE_CPP 1
#define SKIP_RESTORE_NV
//using namespace QualcommModemUtil;

enum RECEIVE_TYPE
{
	NONE,
	DMSS_Write32,
	ARMPRG_HELLO,
	ARMPRG_STREAM_WRITE,
	ARMPRG_UNFRAMED_WRITE,
	ARMPRG_FLASH_READ,
	NV_R_W
};
#define MIBIB_PARTITION_NAME  "0:MIBIB"
#define SIM_SECURE_PARTITION_NAME   "0:SIM_SECURE"
#define EFS2_PARTITION_NUMBER       2
#define FLASH_USR_PART_MAGIC1     0xAA7D1B9A
#define FLASH_USR_PART_MAGIC2     0x1F7D48BC
struct mbn_flash_partition_entry {
	char name[16];
	U32 size;	/* user defined size for the paritition */
	U32 reserved_size;	/* user defined reserved size for the partition */
	U8 attrib1;
	U8 attrib2;
	U8 attrib3;
	U8 which_flash;	/* Numeric ID (first = 0, second = 1) */
};
struct mbn_flash_partition_table {
	U32 magic1;
	U32 magic2;
	U32 version;
	U32 numparts;
	struct mbn_flash_partition_entry part_entry[16];
};

struct flash_partition_entry {
	char name[16];
	U32 offset;	/* Offset in blocks from beginning of device */
	U32 length;	/* Length of the partition in blocks */
	U8 attrib1;
	U8 attrib2;
	U8 attrib3;
	U8 which_flash;	/* Numeric ID (first = 0, second = 1) */
};
struct flash_partition_table {
	U32 magic1;
	U32 magic2;
	U32 version;
	U32 numparts;
	struct flash_partition_entry part_entry[16];
};
#define NAND_BLOCK_SIZE_KB 128 // block size is 128 kbyte
// +++ diag ioctl code +++
#define DIAG_IOCTL_COMMAND_REG  0
#define DIAG_IOCTL_GET_DELAYED_RSP_ID 8
#define DIAG_IOCTL_LSM_DEINIT	9
#define DIAG_IOCTL_WRITE_BUFFER 10
#define DIAG_IOCTL_READ_BUFFER  11
#define DIAG_IOCTL_PASS_FIRMWARE_LIST  12
#define DIAG_IOCTL_GET_PART_TABLE_FROM_SMEM  13
// --- diag ioctl code ---

/// DIAG global buffer
#define BUFFER_SIZE_DIAG_SEND (3*1024)
static U8 g_pBUFFER_DIAG_SEND[BUFFER_SIZE_DIAG_SEND];

#define BUFFER_SIZE_DIAG_RECV (3*1024)
static U8 g_pBUFFER_DIAG_RECV[BUFFER_SIZE_DIAG_RECV];

FILE *fp_pipe = NULL;    // For writing progress to parent process 
#define NVITEM_MAX_LEN_IN_XML 1024
#define LOG_TO_KMSG 1
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
#define LOG_ERROR(a1, a2, a3)    DBG_MSG(a1 a2 " %d\n", a3);
#define LOG_WARNNING(a1, a2, a3) DBG_MSG(a1 a2 " %d\n", a3);
#define ProgressReport(a1, a2)  \
    do                  \
    {                   \
        if(fp_pipe)     \
        {               \
            fprintf(fp_pipe, "Prgs %d %s\n", a1, a2); \
            fflush(fp_pipe);    \
        }   \
        else    \
            _LOGK("Prgs %d %s",a1, a2); \
    }while(0)

#else
#define DBG_MSG(fmt, args...) fprintf(stdout, fmt, ## args)
//#define LOG_INFO(a1, a2)    do { fprintf(stdout, a1 a2 "\n");}while(0)
#define LOG_INFO(a1, a2)    do { }while(0)
#define LOG_ERROR(a1, a2, a3)    fprintf(stdout, a1 a2 "%d\n", a3);
#define LOG_WARNNING(a1, a2, a3) fprintf(stdout, a1 a2 "%d\n", a3);
#define ProgressReport(a1, a2)  do { fprintf(stdout, "Prgs %d %s\n",a1, a2);}while(0)
#endif

#define min(a, b) (((a) < (b)) ? (a) : (b))

#define sprintf_s snprintf
#define strcat_s(s1, size, s2) strncat(s1, s2, size)
#define strcpy_s(s1, size, s2) strncpy(s1, s2, size)
#define sscanf_s sscanf
#define strtok_s strtok_r
typedef unsigned int Port;

BOOL id_find_definitation_to_write(TiXmlAttribute *nvid_u,TiXmlElement **FirstNvItem_d, char *u_data, char *pNV_data);
void id_find_definitation_to_read(TiXmlElement **FirstNvItem, char *u_data, char *pNV_data);
extern int ParseNB0(char *filename, DL_FILE_LIST *DLlist, char *tmpPath, char *hw_id, unsigned int);

void _LOGK(const char *fmt, ...)
{
    char buf[1024];
    int fd;
    fd = open( "/dev/kmsg", O_WRONLY );
    
    if(fd >=0)
    {
        int len;
        va_list ap;
        va_start(ap, fmt);

        vsnprintf(buf, sizeof(buf), fmt, ap);
        len = strlen(buf);
        write(fd, buf, len);        
        close(fd);    
    }
}
#if 0
void LOGP(const char *fmt, args...)
{
    if(fp_pipe)
    {
        fprintf(fp_pipe, fmt, ## args);
        fflush(fp_pipe);
    }
    else
        _LOGK(fmt, ## args);
}
#endif
void hex_dump(U8* pBuf, int size)
{

    for (int i=0; i<size; i++)
    {
        if (i%16 == 0)
            DBG_MSG("\n");
        DBG_MSG("%02X ", *pBuf++);

    }
}
// +++ utilcrc +++
#define HDLC_FLAG	0x7E
#define HDLC_ESCAPE 0x7D
U32 dwordByteSwap(U32 val)
{
	return ( ((val & 0xff000000) >> 24) |
			 ((val & 0x00ff0000) >> 8 ) |
			 ((val & 0x0000ff00) << 8 ) |
			 ((val & 0x000000ff) << 24) );
}

U16 wordByteSwap(U16 val)
{
	return ( ((val & 0xff00) >> 8 ) |
			 ((val & 0x00ff) << 8 ) );
}


//****************************************************************************/
// Function: EncodeEscape
// Purpose: the function is encoding escape character in the data pack
// Commentes: 
//****************************************************************************/
BOOL EncodeEscape(/*[out]*/U8* pNewPack, /*[out]*/U16 &iNewPackLen,const U8* pPack, U16 iPackLen)
{
	U8* pTemp = pNewPack;
	for (U16 i = 0; i < iPackLen; i++)
	{
		if ( pPack[i] == HDLC_FLAG )
		{
			*pTemp = 0x7D;
			*(++pTemp) = 0x5E;// 0x7E | 0x20
		}
		else if ( pPack[i] == HDLC_ESCAPE )
		{
			*pTemp = 0x7D;
			*(++pTemp) = 0x5D;// 0x7D | 0x20
		}
		else
		{
			*pTemp = pPack[i];
		}
		
		pTemp++;
	}

	iNewPackLen = pTemp - pNewPack;
	return TRUE;
}

//****************************************************************************/
// Function: DecodeEscape
// Purpose: the function is Decoding escape character in the data pack
// Commentes: 
//****************************************************************************/
BOOL DecodeEscape(/*[in,out]*/U8* pPack, /*[in,out]*/U16 &iPackSize)
{
	LOG_INFO("<<<","QualcommModemUtil::DecodeEscape");
	/////////////////////////
	// get packet
	U8* pRead = pPack;
	U8* pWrite = pPack;
	U8* pEnd = pPack + iPackSize;
	while ( pRead < pEnd )
	{
		if (*pRead == 0x7D)
		{
			if ( *(pRead+1) == 0x5E )
			{
				*pWrite = 0x7E;
				pRead++;
			}
			else if ( *(pRead+1) == 0x5D )
			{
				*pWrite = 0x7D;
				pRead++;
			}
			else
			{
				*pWrite = *pRead;
			}
		}
		else
		{
			*pWrite = *pRead;
		}

		pRead++;
		pWrite++;
	}

	iPackSize = pWrite - pPack;
	LOG_INFO(">>>","QualcommModemUtil::DecodeEscape");
	return TRUE;
}
// --- utilcrc ---

struct diagpkt_ioctl_param
{
		U8* pPacket;
		U16 Len;
};

BOOL DiagWrite(U8* pPacket, U16 len)
{
    int fd = -1;
    BOOL rc = FALSE;
    diagpkt_ioctl_param pkt;
    int size = 0;
    pkt.pPacket = pPacket;
    pkt.Len = len;
    
    fd = open("/dev/diag", O_RDWR);
    if (fd < 0)
    {
        DBG_MSG("Fail to open /dev/diag\n");
        goto lbError;
    }
    #if 0
    size = write(fd, (void*)&pkt, sizeof(pkt));
    if (size <= 0)
    {
        DBG_MSG("diag write failed!\n");
        goto lbError;
    }
    #else
    
    if(ioctl(fd, DIAG_IOCTL_WRITE_BUFFER, (void*)&pkt)){
        DBG_MSG("ioctl failed!\n");
        goto lbError;
    }
    #endif
    rc = TRUE;

lbError:
    close(fd);
    return rc;
}

BOOL DiagRead(U8* pPacket, U16* len, RECEIVE_TYPE type)
{
    int fd = -1;
    int size = 0;
    BOOL rc = FALSE;
    diagpkt_ioctl_param pkt;

    pkt.pPacket = pPacket;
    pkt.Len = 0;
    
    fd = open("/dev/diag", O_RDWR);
    if (fd < 0)
    {
        DBG_MSG("Fail to open /dev/diag\n");
        goto lbError;
    }
    #if 0
    size = read(fd, (void*)&pkt, BUFFER_SIZE_DIAG_RECV);
    if (size <= 0)
    {
        DBG_MSG("diag read failed!\n");
        goto lbError;
    }
    *len = size - 1;
    #else
    if(ioctl(fd, DIAG_IOCTL_READ_BUFFER, (void*)&pkt)){
        DBG_MSG("ioctl failed!\n");
        goto lbError;
    }
    
    *len = pkt.Len - 1;
    #endif
    rc = TRUE;

lbError:
    close(fd);
    return rc;
}

BOOL DiagGetPartTableFromSMEM(struct flash_partition_table *pPartition_table)
{
    int fd = -1;
    int size = 0;
    BOOL rc = FALSE;
    diagpkt_ioctl_param pkt;
    
    fd = open("/dev/diag", O_RDWR);
    if (fd < 0)
    {
        DBG_MSG("Fail to open /dev/diag\n");
        goto lbError;
    }
    if(ioctl(fd, DIAG_IOCTL_GET_PART_TABLE_FROM_SMEM, (void*)pPartition_table)){
        DBG_MSG("ioctl failed!\n");
        goto lbError;
    }
    
    rc = TRUE;

lbError:
    close(fd);
    return rc;
}

BOOL DiagPassFirmwareList(FirmwareList *fl)
{
    int fd = -1;
    BOOL rc = FALSE;
    int retry = 3;

lbRetry:
    fd = open("/dev/diag", O_RDWR);
    if (fd < 0)
    {
        DBG_MSG("Fail to open /dev/diag\n");
        goto lbError;
    }
    if(ioctl(fd, DIAG_IOCTL_PASS_FIRMWARE_LIST, (void*)fl)){
        DBG_MSG("ioctl failed!\n");
        goto lbError;
    }

    rc = TRUE;

lbError:
    close(fd);
    if (retry-- > 0 && rc == FALSE)
        goto lbRetry;

    return rc;
}
/*!=============================================================================

FUNCTION  DIAGTalk

DESCRIPTION
  This function use to Tx HDLC packet.
  
DEPENDENCIES
  QualcommModemUtilDIAG namespace
  
RETURN VALUE
  TRUE : packet be transmit out success.
  FALSE: packet can't be transmit.

SIDE EFFECTS
  None

=============================================================================*/
#if NOT_USE_CPP
static BOOL DIAGTalk(Port* pPort,U8* pData,U16 iDataSize)
#else
static BOOL QualcommModemUtilDIAG::DIAGTalk(Port* pPort,U8* pData,U16 iDataSize)
#endif
{
	LOG_INFO("<<<","QualcommModemUtilDIAG::DIAGTalk");

	BOOL bResult = FALSE;

	/// set buffer
	U8* pPACKET = g_pBUFFER_DIAG_SEND;
//hex_dump(pPACKET, iDataSize);
	/// get CRC
	U16 wCRC = UtilCRC::crc_16l_calc(pData, (U16)iDataSize);	// -3 because we subtract out the CRC and the end char
//  We don't have to do the HDLC encode when sending diag command to modem.
//  Just need to do the decode when receiving diag command
	#if 0
	/// encode escape in CRC
	U32 dwCRCBuffer;
	U16 iCRCLen;
    DBG_MSG("EncodeEscape CRC\n");
    hex_dump((U8*)&wCRC, sizeof(wCRC));
	EncodeEscape((U8*)&dwCRCBuffer,iCRCLen,(U8*)&wCRC,sizeof(U16));
    hex_dump((U8*)&dwCRCBuffer, sizeof(dwCRCBuffer));
    DBG_MSG("EncodeEscape data\n");
	/// encode escape in data payload
	U16 iDataLen;
    hex_dump(pData, iDataSize);
	EncodeEscape(pPACKET,iDataLen,pData,iDataSize);
    hex_dump(pPACKET,iDataLen);

	/// combine Data and CRC
	memcpy(pPACKET+iDataLen,(void*)&dwCRCBuffer,iCRCLen);


	/// calculate total length
	U16 iLen = iCRCLen + iDataLen + 1;


	/// add HDLC flags to packet
	///*pPACKET = HDLC_FLAG;
	*(pPACKET+iLen-1) = HDLC_FLAG;

//hex_dump(pPACKET, iLen);
	/// send packet
	//bResult = pPort->WriteBuffer(pPACKET, iLen);
	DBG_MSG("pPACKET\n");
	hex_dump(pPACKET,iLen);
	bResult = DiagWrite(pPACKET, iLen);
    #else
    memset(pPACKET, 0, sizeof(pPACKET));
    memcpy(pPACKET, pData, iDataSize);
    memcpy((pPACKET + iDataSize), (void*)&wCRC, sizeof(U16));
    U16 iLen = sizeof(U16) + iDataSize + 1;

    *(pPACKET+iLen-1) = HDLC_FLAG;
	//DBG_MSG("pPACKET\n");
	//hex_dump(pPACKET,iLen);
	bResult = DiagWrite(pPACKET, iLen);
    
    #endif

	if ( bResult == FALSE )
	{
		//bResult = pPort->WriteBuffer(pPACKET, iLen);	
		bResult = DiagWrite(pPACKET, iLen);
	}
	
	LOG_INFO(">>>","QualcommModemUtilDIAG::DIAGTalk");

	return bResult;
}

/*!=============================================================================

FUNCTION  DIAGListen

DESCRIPTION
  This function use to Rx HDLC packet.
  
DEPENDENCIES
  QualcommModemUtilDIAG namespace
  
RETURN VALUE
  TRUE : get some data from port
  FALSE: no any data be listened
SIDE EFFECTS
  None

=============================================================================*/
#if NOT_USE_CPP
BOOL DIAGListen(Port* pPort,U8* pBuffer,U16 &iCount, RECEIVE_TYPE type )
#else
BOOL QualcommModemUtilDIAG::DIAGListen(Port* pPort,U8* pBuffer,U16 &iCount, RECEIVE_TYPE type )
#endif
{
	LOG_INFO("<<<","QualcommModemUtilDIAG::DIAGListen");

	BOOL bResult = FALSE;

	/// allocate DIAG packet
	U8* pPACKET = g_pBUFFER_DIAG_RECV;
	U16 dwSize = BUFFER_SIZE_DIAG_RECV;
    U16 CRC_tmp;
    
	memset(pPACKET,0,dwSize);
	//bResult = pPort->ReadBuffer(pPACKET,dwSize,type);
	bResult = DiagRead(pPACKET, &dwSize, type);
    //DBG_MSG("dwSize=%d\n", dwSize);
//hex_dump(pPACKET, dwSize);
	/// after get packet
	if ( bResult )
	{	
	    ///decoding HDLC escapse code
		DecodeEscape(pPACKET,dwSize);
//hex_dump(pPACKET, dwSize);
        ///extract the payload to calculate CRC value 
	    U16 wCRC = UtilCRC::crc_16l_calc(pPACKET, (U16)(dwSize-2));
//DBG_MSG("wCRC=%X\n",wCRC);
        ///extract the packet' CRC field
        memcpy(&CRC_tmp, &pPACKET[dwSize-2], 2); 
//DBG_MSG("CRC_tmp=%X\n",CRC_tmp);
     
        if(CRC_tmp==wCRC)
           {
             dwSize-=2;
       		 iCount = min(iCount,dwSize);
       		 memcpy(pBuffer,pPACKET,iCount);            
           }
        else
		   {   
		   DBG_MSG("CRC error\n");
             bResult=FALSE;
		   }
	}
	
	LOG_INFO(">>>","QualcommModemUtilDIAG::DIAGListen");

	return bResult;
}

/*!=============================================================================

FUNCTION  DoDIAG

DESCRIPTION
  This function use to Tx & Rx HDLC packet.
  
DEPENDENCIES
  DIAG MODE
  QualcommModemUtilDIAG namespace
  
RETURN VALUE
  MODEM_UPDATER_ERROR_NONE    : no error
  MODEM_UPDATER_ERROR_TBUFFER : can't transmit out
  MODEM_UPDATER_ERROR_RBUFFER : can't receive any response

SIDE EFFECTS
  None

=============================================================================*/
#if NOT_USE_CPP
MODEM_UPDATER_ERROR DoDIAG(Port* pPort, CONTAINER& oPacket, RECEIVE_TYPE type)
#else
MODEM_UPDATER_ERROR QualcommModemUtilDIAG::DoDIAG(Port* pPort, CONTAINER& oPacket, RECEIVE_TYPE type)
#endif
{
	LOG_INFO("<<<","QualcommModemUtilDIAG::DoDIAG");
	MODEM_UPDATER_ERROR bResult = MODEM_UPDATER_ERROR_NONE;


    /*! Tx packet*/
	if (!DIAGTalk(pPort, oPacket.pRequest, oPacket.iRequestLen))
	{	
		LOG_ERROR("ERR","WriteBuffer FAILED!",-1);        
		bResult = MODEM_UPDATER_ERROR_TBUFFER;
		goto End;
	}

    /*! Rx packet*/    
	if ( oPacket.iResponseLen > 0 && oPacket.pResponse != 0 )
	{  

		U16 iTempSize = oPacket.iResponseLen;


		if (!DIAGListen(pPort, oPacket.pResponse, iTempSize, type))
		{    
			LOG_ERROR("ERR","ReadBuffer FAILED!",-1);            
            bResult = MODEM_UPDATER_ERROR_RBUFFER;
			goto End;
		}
        
        oPacket.iResponseLen = min(oPacket.iResponseLen,iTempSize);

	}

End:

	LOG_INFO(">>>","QualcommModemUtilDIAG::DoDIAG");
	return bResult;
}

/*!=============================================================================

FUNCTION  DIAG_NVRead

DESCRIPTION
  This function use to read NV item
  
DEPENDENCIES
  DIAG MODE
  QualcommModemUtilDIAG namespace
  
RETURN VALUE
  MODEM_UPDATER_ERROR_NONE                 : no error
  MODEM_UPDATER_ERROR_Diag_NV_READ_WARNING : certain NV item has bad parameter response, we should bypass it.
  MODEM_UPDATER_ERROR_Diag_NV_READ         : 1.can't transmit out
                                             2.no response
                                             3.error response

SIDE EFFECTS
  None

=============================================================================*/
#if NOT_USE_CPP
MODEM_UPDATER_ERROR DIAG_NVRead(Port* pPort,DIAG_PACKET_NV &oNV)
#else
MODEM_UPDATER_ERROR QualcommModemUtilDIAG::DIAG_NVRead(Port* pPort,DIAG_PACKET_NV &oNV)
#endif
{
	LOG_INFO("<<<","QualcommModemUtilDIAG::DIAG_NVRead");
    MODEM_UPDATER_ERROR bResult = MODEM_UPDATER_ERROR_NONE;

	char sBuf[64];

    int Retry = DIAG_RETRY_TIMES;
    U16 NV_ITEM = 0;
    
	/*Form the packet, call the read function*/
	oNV.CMD_CODE = DIAG_NV_READ_F;
		
	CONTAINER oCONTAINER;
	oCONTAINER.pRequest = (U8*)&oNV;
	oCONTAINER.iRequestLen = sizeof(oNV);
	oCONTAINER.pResponse = (U8*)&oNV;
	oCONTAINER.iResponseLen = sizeof(oNV);

    NV_ITEM = oNV.NV_ITEM;
//DBG_MSG("oNV content @0x%X:\n", &oNV);
//hex_dump((U8*)&oNV, sizeof(oNV));
//DBG_MSG("oContainer.pRequest: 0x%X 0x%X 0x%X 0x%X\n", 
//    oCONTAINER.pRequest, oCONTAINER.iRequestLen,
//    oCONTAINER.pResponse, oCONTAINER.iResponseLen);

    while(--Retry>=0)
     {
        bResult = DoDIAG(pPort,oCONTAINER, NV_R_W);
        memset(sBuf, 0, sizeof(sBuf));
    	/*check the response*/
    	if ( bResult == MODEM_UPDATER_ERROR_NONE)
    	{   
    	    /*some NV items will return Bad parameter response, we don't need handle this issue*/
    		if ( oNV.CMD_CODE != DIAG_NV_READ_F || oNV.NV_ITEM != NV_ITEM)
    		{
    		    sprintf_s(sBuf, sizeof(sBuf), "NV#%d bad parameter", NV_ITEM);
                ProgressReport(((NV_ITEM * 100) / 10000), sBuf);
    			bResult = MODEM_UPDATER_ERROR_Diag_NV_READ_WARNING;
    		}
    		else
    		{
    			if (oNV.STATUS==0)
    			{
    		        //sprintf_s(sBuf,sizeof(sBuf), "READ NV #%d", oNV.NV_ITEM);
    				ProgressReport(((oNV.NV_ITEM * 100) / 10000), sBuf);
    	        }
    			else if (oNV.STATUS==5)
    			{
    				//sprintf_s(sBuf, sizeof(sBuf), "#%d DIAG_NV_READ not exist", oNV.NV_ITEM);
                    //ProgressReport(((oNV.NV_ITEM * 100) / 10000), sBuf);
    				bResult = MODEM_UPDATER_ERROR_Diag_NV_READ_WARNING;
    			}
                else if (oNV.STATUS==6)
    			{
    				sprintf_s(sBuf, sizeof(sBuf), "#%d Diag command error", oNV.NV_ITEM);
                    ProgressReport(((oNV.NV_ITEM * 100) / 10000), sBuf);
    				bResult = MODEM_UPDATER_ERROR_Diag_NV_READ_WARNING;
    			}
    			else
    			{
    			    /*this NV item with some problem, just recoder error message, bypass it*/
           		    sprintf_s(sBuf,sizeof(sBuf), "READ NV #%d - message code:%d", oNV.NV_ITEM, oNV.STATUS);
    				ProgressReport(((oNV.NV_ITEM * 100) / 10000), sBuf);
    			  	bResult = MODEM_UPDATER_ERROR_Diag_NV_READ;
                }
    		}
            
            Retry=0;
    	}
    	else
        {   
            ProgressReport(0, "DIAG_NV_READ Fail, Try Again.");
            bResult = MODEM_UPDATER_ERROR_Diag_NV_READ;
        }
     }
	
	LOG_INFO(">>>","QualcommModemUtilDIAG::DIAG_NVRead");

	return bResult;
}

/*!=============================================================================

FUNCTION  DIAG_NVWrite

DESCRIPTION
  This function use to write NV item
  
DEPENDENCIES
  DIAG MODE
  QualcommModemUtilDIAG namespace
  
RETURN VALUE
  MODEM_UPDATER_ERROR_NONE          : no error
  MODEM_UPDATER_ERROR_Diag_NV_WRITE : 1.can't transmit out
                                      2.no response
                                      3.error response
                                      4.NV can't be write or write fail

SIDE EFFECTS
  None

=============================================================================*/
#if NOT_USE_CPP
MODEM_UPDATER_ERROR DIAG_NVWrite(Port* pPort,DIAG_PACKET_NV &oRequest)
#else
MODEM_UPDATER_ERROR QualcommModemUtilDIAG::DIAG_NVWrite(Port* pPort,DIAG_PACKET_NV &oRequest)
#endif
{
	LOG_INFO("<<<","QualcommModemUtilDIAG::DIAG_NVWrite");
	MODEM_UPDATER_ERROR bResult = MODEM_UPDATER_ERROR_NONE;

    /*use to store error message*/
	char sBuffer[100];
    
    int Retry = DIAG_RETRY_TIMES;
	DIAG_PACKET_NV oResponse;
    U16 NV_ITEM = 0;

	/*Form the packet, call the write function*/
	oRequest.CMD_CODE = DIAG_NV_WRITE_F;
		
	CONTAINER oCONTAINER;
	oCONTAINER.pRequest = (U8*)&oRequest;
	oCONTAINER.iRequestLen = sizeof(oRequest);
	oCONTAINER.pResponse = (U8*)&oResponse;
	oCONTAINER.iResponseLen = sizeof(oResponse);

    NV_ITEM = oRequest.NV_ITEM;

    while(--Retry>=0)
     {
    	bResult = DoDIAG(pPort,oCONTAINER, NV_R_W);
        
    	/*check the response*/
    	if ( bResult == MODEM_UPDATER_ERROR_NONE && oResponse.CMD_CODE == DIAG_NV_WRITE_F && oResponse.NV_ITEM == NV_ITEM)
    	{
			if (oResponse.STATUS==0)
			{
		        sprintf_s(sBuffer, sizeof(sBuffer), "WRITE NV #%d", oResponse.NV_ITEM);
				ProgressReport((oResponse.NV_ITEM * 100/10000), sBuffer);
			}
			else if ((oResponse.STATUS>=1&&oResponse.STATUS<=4)||oResponse.STATUS==9||oResponse.STATUS==10)
			{
     		    sprintf_s(sBuffer, sizeof(sBuffer), "WRITE NV #%d - message code:%d", oResponse.NV_ITEM, oResponse.STATUS);
				ProgressReport((oResponse.NV_ITEM * 100/10000), sBuffer);
			  	bResult = MODEM_UPDATER_ERROR_Diag_NV_WRITE;
			}
			else if (oResponse.STATUS==7)
			{
 			    sprintf_s(sBuffer, sizeof(sBuffer), "WRITE NV #%d - read only", oResponse.NV_ITEM, oResponse.STATUS);
				ProgressReport((oResponse.NV_ITEM * 100/10000), sBuffer);
			}

            Retry=0;
    	}	
    	else
        {   
            ProgressReport(0, "DIAG_NV_WRITE Fail, Try Again.");
            bResult = MODEM_UPDATER_ERROR_Diag_NV_WRITE;
        }
     }
        
    
	LOG_INFO(">>>","QualcommModemUtilDIAG::DIAG_NVWrite");
	return bResult;
}

#if NOT_USE_CPP
MODEM_UPDATER_ERROR DIAG_Get_Hw_ID(Port* pPort,char* hw_id)
#else
MODEM_UPDATER_ERROR QualcommModemUtilDIAG::DIAG_Get_Hw_ID(Port* pPort,char* hw_id)
#endif
{
	LOG_INFO("<<<","QualcommModemUtilDIAG::DIAG_Get_Hw_ID");
	MODEM_UPDATER_ERROR bResult = MODEM_UPDATER_ERROR_NONE;

    int Retry = DIAG_RETRY_TIMES;
    
	DIAG_PACKET_HW_ID oNV;
	DIAG_PACKET_RSP_HW_ID oNVR;

	oNV.CMD_CODE=DIAG_SUBSYS_CMD_F;
	oNV.SUB_ID=NO_SUBID;
	oNV.SUB_CMD_CODE = DIAG_HW_ID;
		
	CONTAINER oCONTAINER;
	oCONTAINER.pRequest = (U8*)&oNV;
	oCONTAINER.iRequestLen = sizeof(oNV);
	oCONTAINER.pResponse = (U8*)&oNVR;
	oCONTAINER.iResponseLen = sizeof(oNVR);

    while(--Retry>=0)
     {
        bResult = DoDIAG(pPort,oCONTAINER, NV_R_W);

    	if ( bResult== MODEM_UPDATER_ERROR_NONE)
    	{
    		if ( oNVR.SUB_CMD_CODE != DIAG_HW_ID )
    		{
                ProgressReport(0,"DIAG_HW_ID Not support");
    			bResult = MODEM_UPDATER_ERROR_Diag_HW_ID;
    		}
    		else
    		{   
    		    //memcpy(hw_id,&oNVR.HW_ID,DIAGOEM_HWID_DATE_STRLEN);
    		    strcpy_s(hw_id, DIAGOEM_HWID_DATE_STRLEN, oNVR.HW_ID);
                Retry=0;
    		}
    	}
    	else
        {   
            ProgressReport(0, "DIAG_HW_ID Fail, Try Again.");
            bResult = MODEM_UPDATER_ERROR_Diag_HW_ID;
        }

     }

			
	LOG_INFO(">>>","QualcommModemUtilDIAG::DIAG_Get_Hw_ID");
	return bResult;
}


BOOL id_find_definitation_to_write(TiXmlAttribute *nvid_u,TiXmlElement **FirstNvItem_d, char *u_data, char *pNV_data)
{
  int i=0;
  BOOL bResult=FALSE;
  TiXmlAttribute *NvItem_id;
  TiXmlAttribute *member_type;
  TiXmlAttribute *size;
  char *pch;
  char *position ;


  do
  {     
    NvItem_id = (*FirstNvItem_d)->FirstAttribute();

    if(nvid_u->IntValue()==NvItem_id->IntValue())
      break;
    else
      *FirstNvItem_d = (*FirstNvItem_d)->NextSiblingElement();

  }while(*FirstNvItem_d!=NULL);
 

  if(*FirstNvItem_d==NULL)
    {
     return bResult;
    }
  else
  { 
    TiXmlElement *sub_FirstNvItem = (*FirstNvItem_d)->FirstChildElement();

    int8   ch8=0;   
    int16  ch16=0;
    int32  ch32=0;
    int64  ch64=0;

    uint8  uch8=0;
    uint16 uch16=0;
    uint32 uch32=0;
    uint64 uch64=0;
    
    
    pch = strtok_s(u_data,",", &position);

      do
      {
        member_type = sub_FirstNvItem->FirstAttribute();
        size = member_type->Next();

        if(!strcmp(member_type->Value(), "int8"))
           { 
            sscanf_s(pch,"%d",&ch8);
            memcpy(pNV_data+i,&ch8,1);
            i+=1;
            for(int k=1;k<size->IntValue();k++)
               {
                 pch = strtok_s(NULL,",",&position);
                 sscanf_s(pch,"%d",&ch8);
                 memcpy(pNV_data+i,&ch8,1);
                 i+=1;
               }
             
           }
        else if(!strcmp(member_type->Value(), "uint8"))
           {      
            sscanf_s(pch,"%u",&uch8);
            memcpy(pNV_data+i,&uch8,1);
            i+=1;
            for(int k=1;k<size->IntValue();k++)
               {
                 pch = strtok_s(NULL,",",&position);
                 sscanf_s(pch,"%u",&uch8);
                 memcpy(pNV_data+i,&uch8,1);
                 i+=1;
               }

           }
        else if(!strcmp(member_type->Value(), "int16"))
           {
            sscanf_s(pch,"%d",&ch16);
            memcpy(pNV_data+i,&ch16,2);
            i+=2;
            for(int k=1;k<size->IntValue();k++)
               {
                 pch = strtok_s(NULL,",",&position);
                 sscanf_s(pch,"%d",&ch16);
                 memcpy(pNV_data+i,&ch16,2);
                 i+=2;
               }

           }
        else if(!strcmp(member_type->Value(), "uint16"))
           {
            sscanf_s(pch,"%u",&uch16);
            memcpy(pNV_data+i,&uch16,2);
            i+=2;
            for(int k=1;k<size->IntValue();k++)
               {
                 pch = strtok_s(NULL,",",&position);
                 sscanf_s(pch,"%u",&uch16);
                 memcpy(pNV_data+i,&uch16,2);
                 i+=2;
               }
           
           }
        else if(!strcmp(member_type->Value(), "int32"))
           {
            sscanf_s(pch,"%d",&ch32);
            memcpy(pNV_data+i,&ch32,4);
            i+=4;
            for(int k=1;k<size->IntValue();k++)
               {
                 pch = strtok_s(NULL,",",&position);
                 sscanf_s(pch,"%d",&ch32);
                 memcpy(pNV_data+i,&ch32,4);
                 i+=4;
               }
           
           }
        else if(!strcmp(member_type->Value(), "uint32"))
           {
            sscanf_s(pch,"%u",&uch32);
            memcpy(pNV_data+i,&uch32,4);
            i+=4;
            for(int k=1;k<size->IntValue();k++)
               {
                 pch = strtok_s(NULL,",",&position);
                 sscanf_s(pch,"%u",&uch32);
                 memcpy(pNV_data+i,&uch32,4);
                 i+=4;
               }
           
           }
        else if(!strcmp(member_type->Value(), "int64"))
           {
            sscanf_s(pch,"%I64d",&ch64);
            memcpy(pNV_data+i,&ch64,8);
            i+=8;
            for(int k=1;k<size->IntValue();k++)
               {
                 pch = strtok_s(NULL,",",&position);
                 sscanf_s(pch,"%I64d",&ch64);
                 memcpy(pNV_data+i,&ch64,8);
                 i+=8;
               }
           
           }
        else if(!strcmp(member_type->Value(), "uint64"))
           {
            sscanf_s(pch,"%I64u",&uch64);
            memcpy(pNV_data+i,&uch64,8);
            i+=8;
            for(int k=1;k<size->IntValue();k++)
               {
                 pch = strtok_s(NULL,",",&position);
                 sscanf_s(pch,"%I64u",&uch64);
                 memcpy(pNV_data+i,&uch64,8);
                 i+=8;
               }
           
           }
        
         pch = strtok_s(NULL,",",&position);

         if(pch==NULL)
            break;
         
         sub_FirstNvItem = sub_FirstNvItem->NextSiblingElement();
       }while(sub_FirstNvItem!=NULL);
    
    }/*FirstNvItem==NULL*/
 
    bResult=TRUE;
    return bResult;
}

void id_find_definitation_to_read(TiXmlElement **FirstNvItem, char *u_data, char *pNV_data)
{
  int i=0,n=0;
  int array_size=0;

  TiXmlAttribute *member_type;
  TiXmlAttribute *size;

  

  TiXmlElement *sub_FirstNvItem = (*FirstNvItem)->FirstChildElement();

  int8   ch8=0;   
  int16  ch16=0;
  int32  ch32=0;
  int64  ch64=0;

  uint8  uch8=0;
  uint16 uch16=0;
  uint32 uch32=0;
  uint64 uch64=0;

  char data_tmp[24];

  do
  { 
    memset(data_tmp,0,sizeof(data_tmp));
    member_type = sub_FirstNvItem->FirstAttribute();
    size = member_type->Next();
    
    if(!strcmp(member_type->Value(), "int8"))
       { 
        memcpy(data_tmp,pNV_data+i,2);
        i+=2;
        ch8=strtol(data_tmp,0,16);
        sprintf_s(data_tmp,sizeof(data_tmp), "%d", ch8);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
        for(int k=1;k<size->IntValue();k++)
           {
            memset(data_tmp,0,sizeof(data_tmp));
            memcpy(data_tmp,pNV_data+i,2);
            i+=2;
            ch8=strtol(data_tmp,0,16);
            sprintf_s(data_tmp,sizeof(data_tmp), "%d", ch8);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
           }            
       }
    else if(!strcmp(member_type->Value(), "uint8"))
       {      
        memcpy(data_tmp,pNV_data+i,2);
        i+=2;
        uch8=strtoul(data_tmp,0,16);
        sprintf_s(data_tmp,sizeof(data_tmp), "%u", uch8);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
        for(int k=1;k<size->IntValue();k++)
           {
            memset(data_tmp,0,sizeof(data_tmp));
            memcpy(data_tmp,pNV_data+i,2);
            i+=2;
            uch8=strtoul(data_tmp,0,16);
            sprintf_s(data_tmp,sizeof(data_tmp), "%u", uch8);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
           }
       }
    else if(!strcmp(member_type->Value(), "int16"))
       {
        memcpy(&data_tmp[2],pNV_data+i,2);
        i+=2;
        memcpy(data_tmp,pNV_data+i,2);
        i+=2;
        
        ch16=strtol(data_tmp,0,16);
        sprintf_s(data_tmp,sizeof(data_tmp), "%d", ch16);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");

        for(int k=1;k<size->IntValue();k++)
           {
            memset(data_tmp,0,sizeof(data_tmp));
            memcpy(&data_tmp[2],pNV_data+i,2);
            i+=2;
            memcpy(data_tmp,pNV_data+i,2);
            i+=2;
            
            ch16=strtol(data_tmp,0,16);
            sprintf_s(data_tmp,sizeof(data_tmp), "%d", ch16);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
           }
       }
    else if(!strcmp(member_type->Value(), "uint16"))
       {
        memcpy(&data_tmp[2],pNV_data+i,2);
        i+=2;
        memcpy(data_tmp,pNV_data+i,2);
        i+=2;
        
        uch16=strtoul(data_tmp,0,16);
        sprintf_s(data_tmp,sizeof(data_tmp), "%u", uch16);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
        for(int k=1;k<size->IntValue();k++)
           {
            memset(data_tmp,0,sizeof(data_tmp));
            memcpy(&data_tmp[2],pNV_data+i,2);
            i+=2;
            memcpy(data_tmp,pNV_data+i,2);
            i+=2;
            
            uch16=strtoul(data_tmp,0,16);
            sprintf_s(data_tmp,sizeof(data_tmp), "%u", uch16);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
           }
       }
    else if(!strcmp(member_type->Value(), "int32"))
       {
        for(n=0;n<=6;n+=2)
            {
              memcpy(&data_tmp[6-n],pNV_data+i,2);
              i+=2;
            }

        uch32=strtoul(data_tmp,0,16);
        sprintf_s(data_tmp,sizeof(data_tmp), "%d", uch32);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
        for(int k=1;k<size->IntValue();k++)
           {
            memset(data_tmp,0,sizeof(data_tmp));
            for(n=0;n<=6;n+=2)
                {
                  memcpy(&data_tmp[6-n],pNV_data+i,2);
                  i+=2;
                }
            
            uch32=strtoul(data_tmp,0,16);
            sprintf_s(data_tmp,sizeof(data_tmp), "%d", uch32);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
           }
       }
    else if(!strcmp(member_type->Value(), "uint32"))
       {
        for(n=0;n<=6;n+=2)
            {
              memcpy(&data_tmp[6-n],pNV_data+i,2);
              i+=2;
            }
        uch32=strtoul(data_tmp,0,16);
        sprintf_s(data_tmp,sizeof(data_tmp), "%u", uch32);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
        for(int k=1;k<size->IntValue();k++)
           {
            memset(data_tmp,0,sizeof(data_tmp));
            for(n=0;n<=6;n+=2)
                {
                  memcpy(&data_tmp[6-n],pNV_data+i,2);
                  i+=2;
                }
            
            uch32=strtoul(data_tmp,0,16);
            sprintf_s(data_tmp,sizeof(data_tmp), "%u", uch32);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");
           }
       }
    else if(!strcmp(member_type->Value(), "int64"))
       {
        char _64tmp[8];
        for(n=0;n<=14;n+=2)
            {
              memcpy(&data_tmp[14-n],pNV_data+i,2);
              i+=2;
            }

        memcpy(_64tmp,data_tmp,8);
        ch64=strtoul(_64tmp,0,16)*4294967296ULL;
        memcpy(_64tmp,data_tmp+8,8);
        ch64=ch64+strtoul(_64tmp,0,16);

        sprintf_s(data_tmp,sizeof(data_tmp), "%lld", ch64);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");

        for(int k=1;k<size->IntValue();k++)
           {
            for(n=0;n<=14;n+=2)
                {
                 memset(data_tmp,0,sizeof(data_tmp));
                  memcpy(&data_tmp[14-n],pNV_data+i,2);
                  i+=2;
                }
            
            memcpy(_64tmp,data_tmp,8);
            ch64=strtoul(_64tmp,0,16)*4294967296ULL;
            memcpy(_64tmp,data_tmp+8,8);
            ch64=ch64+strtoul(_64tmp,0,16);
            
            sprintf_s(data_tmp,sizeof(data_tmp), "%lld", ch64);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");

           }
       }
    else if(!strcmp(member_type->Value(), "uint64"))
       {
        char _64tmp[8];
        for(n=0;n<=14;n+=2)
            {
              memcpy(&data_tmp[14-n],pNV_data+i,2);
              i+=2;
            }

        memcpy(_64tmp,data_tmp,8);
        ch64=strtoul(_64tmp,0,16)*4294967296ULL;//16^8  
        memcpy(_64tmp,data_tmp+8,8);

        ch64=ch64+strtoul(_64tmp,0,16);

        sprintf_s(data_tmp,sizeof(data_tmp), "%llu", ch64);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
        strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");

        for(int k=1;k<size->IntValue();k++)
           {
            memset(data_tmp,0,sizeof(data_tmp));
            for(n=0;n<=14;n+=2)
                {
                  memcpy(&data_tmp[14-n],pNV_data+i,2);
                  i+=2;
                }
            
            memcpy(_64tmp,data_tmp,8);
            ch64=strtoul(_64tmp,0,16)*4294967296ULL;//16^8           
            memcpy(_64tmp,data_tmp+8,8);
            ch64=ch64+strtoul(_64tmp,0,16);
            
            sprintf_s(data_tmp,sizeof(data_tmp), "%llu", ch64);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,data_tmp);
            strcat_s(u_data,NVITEM_MAX_LEN_IN_XML,",");

           }
       }
    
     sub_FirstNvItem = sub_FirstNvItem->NextSiblingElement();

     
   }while(sub_FirstNvItem!=NULL);
    

    
    u_data[(strlen(u_data)-1)]='\0';
}

#if NOT_USE_CPP
MODEM_UPDATER_ERROR DIAG_ServiceProgrammingCode(Port* pPort)
#else
MODEM_UPDATER_ERROR QualcommModemUtilDIAG::DIAG_ServiceProgrammingCode(Port* pPort)
#endif
{
	LOG_INFO("<<<","QualcommModemUtilDIAG::DIAG_ServiceProgrammingCode");
    MODEM_UPDATER_ERROR bResult = MODEM_UPDATER_ERROR_NONE;

    int Retry = DIAG_RETRY_TIMES * 2;
	DIAG_PACKET_REQ_SERVICE_PROGRAMMING_CODE oRequest;
	DIAG_PACKET_RES_SERVICE_PROGRAMMING_CODE oResponse;

	// Form the packet, call the write function
	oRequest.CMD_CODE = DIAG_SPC_F;
	for(int i=0;i<6;i++)
	{
	oRequest.SECURITY_CODE[i]='0';// 30 for download mode by valery
	}

	CONTAINER oCONTAINER;
	oCONTAINER.pRequest = (U8*)&oRequest;
	oCONTAINER.iRequestLen = sizeof(oRequest);
	oCONTAINER.pResponse = (U8*)&oResponse;
	oCONTAINER.iResponseLen = sizeof(oResponse);

    while(--Retry>=0)
     {
    	bResult = DoDIAG(pPort,oCONTAINER,NV_R_W);

    	if ( bResult == MODEM_UPDATER_ERROR_NONE)
    	{
    		if ( oResponse.CMD_CODE != DIAG_SPC_F )
    		{   
    			LOG_ERROR("DIAG_ServiceProgrammingCode","CMD_CODE",oResponse.CMD_CODE)

                ProgressReport(0, "SPC response Fail, Try Again.");
                bResult = MODEM_UPDATER_ERROR_Diag_SPC;

    		}
    		else if ( oResponse.SPC_RESULT != SPC_RESULT_SUCCESS )
    		{	
    			LOG_WARNNING("DIAG_ServiceProgrammingCode","SPC_RESULT",oResponse.SPC_RESULT)
                    
                ProgressReport(0, "SPC unlock failed, Try Again.");
                bResult = MODEM_UPDATER_ERROR_Diag_SPC;
    		}
    		
    		else if ( oResponse.SPC_RESULT == SPC_RESULT_SUCCESS )
    		{	
    			LOG_WARNNING("DIAG_ServiceProgrammingCode","SPC_RESULT",oResponse.SPC_RESULT)
                Retry=0;
    		}
    	}
    	else
        {   
            ProgressReport(0, "SPC Fail, Try Again.");
            bResult = MODEM_UPDATER_ERROR_Diag_SPC;
        }
     }

	LOG_INFO(">>>","QualcommModemUtilDIAG::DIAG_ServiceProgrammingCode");
	return bResult;
}

#if NOT_USE_CPP
MODEM_UPDATER_ERROR DIAG_Set_DIPSwitch(Port* pPort)
#else
MODEM_UPDATER_ERROR QualcommModemUtilDIAG::DIAG_Set_DIPSwitch(Port* pPort)
#endif
{
	LOG_INFO("<<<","QualcommModemUtilDIAG::DIAG_Set_DIPSwitch");
    DBG_MSG("<<<QualcommModemUtilDIAG::DIAG_Set_DIPSwitch\n");
    MODEM_UPDATER_ERROR bResult = MODEM_UPDATER_ERROR_NONE;

    int Retry = DIAG_RETRY_TIMES;
	DIAG_PACKET_REQ_DIP_SWITCH oRequest;
	DIAG_PACKET_RES_DIP_SWITCH oResponse;

	// Form the packet, call the write function
	oRequest.CMD_CODE = DIAG_SET_DIPSW_F;
	oRequest.SWITCH_CODE=1;

	CONTAINER oCONTAINER;
	oCONTAINER.pRequest = (U8*)&oRequest;
	oCONTAINER.iRequestLen = sizeof(oRequest);
	oCONTAINER.pResponse = (U8*)&oResponse;
	oCONTAINER.iResponseLen = sizeof(oResponse);

    while(--Retry>=0)
     {
    	bResult = DoDIAG(pPort,oCONTAINER, NV_R_W);

    	if ( bResult == MODEM_UPDATER_ERROR_NONE)
    	{
    		if ( oResponse.CMD_CODE != DIAG_SET_DIPSW_F )
    		{   
    			LOG_ERROR("DIAG_Set_DIPSwitch","CMD_CODE",oResponse.CMD_CODE)

                ProgressReport(0, "SPC response Fail, Try Again.");
                bResult = MODEM_UPDATER_ERROR_Diag_SPC;

    		}
    		else if ( oResponse.SWITCH_CODE != oRequest.SWITCH_CODE )
    		{	
    			LOG_WARNNING("DIAG_Set_DIPSwitch","Switch_RESULT",oResponse.SWITCH_CODE)
                    
                ProgressReport(0, "Set_DIPSwitch failed, Try Again.");
                bResult = MODEM_UPDATER_ERROR_Diag_SPC;
    		}
    		
    		else
    		{	
                Retry=0;
    		}
    	}
    	else
        {   
            ProgressReport(0, "Set_DIPSwitch, Try Again.");
            bResult = MODEM_UPDATER_ERROR_Diag_SPC;
        }
     }
DBG_MSG(">>>QualcommModemUtilDIAG::DIAG_Set_DIPSwitch\n");
	LOG_INFO(">>>","QualcommModemUtilDIAG::DIAG_Set_DIPSwitch");
	return bResult;
}

#if NOT_USE_CPP
MODEM_UPDATER_ERROR DIAG_NV_Update(Port* pPort, char *ufilname_u, char *ufilname_d)
#else
MODEM_UPDATER_ERROR QualcommModemUtilDIAG::DIAG_NV_Update(Port* pPort, char *ufilname_u, char *ufilname_d)
#endif
{

 MODEM_UPDATER_ERROR bResult = MODEM_UPDATER_ERROR_NONE;
 MODEM_UPDATER_ERROR rResult = MODEM_UPDATER_ERROR_NONE;
 char uNV_DATA[128];
 char uNV_data_tmp[1024*58];
 int Retry=DIAG_RETRY_TIMES;

 DIAG_PACKET_NV oNVo;

 /*bfilname_b  "u"-> update function, "_u"->update XML*/
 TiXmlDocument *update = new TiXmlDocument(ufilname_u);
 
 /*bfilname_b  "u"-> update function, "_d"->backup XML*/
 TiXmlDocument *Definition = new TiXmlDocument(ufilname_d);

 ProgressReport(0,ufilname_u);
 ProgressReport(0,ufilname_d);

 if(!Definition->LoadFile())
 {
     ProgressReport(0,"LoadFile Definition.XML FAILED");
     return bResult=MODEM_UPDATER_ERROR_OPEN_NV_FILE;
 }
 else
     ProgressReport(0,"LoadFile Definition.XML Success");

 if(!update->LoadFile())
 {
     ProgressReport(0,"LoadFile NV.XML FAILED");
     return bResult=MODEM_UPDATER_ERROR_OPEN_NV_FILE;
 }
 else
     ProgressReport(0,"LoadFile NV.XML Success");

 /*Get <NvDefinition>*/
 TiXmlElement *NvDefinition_u = update->RootElement();
 TiXmlElement *NvDefinition_d = Definition->RootElement();


 /*<NvItem id="0" name="NV_ESN_I" permission="readwrite">  is FirstChildElement of NvDefinition*/
 TiXmlElement *FirstNvItem_u = NvDefinition_u->FirstChildElement();
 TiXmlElement *FirstNvItem_d = NvDefinition_d->FirstChildElement();

 if(FirstNvItem_u==NULL)
 {
   ProgressReport(0,"%Update empty XML");
   return bResult;
 }
 #if NOT_USE_CPP
 bResult = DIAG_ServiceProgrammingCode(pPort);
 #else
 bResult=QualcommModemUtilDIAG::DIAG_ServiceProgrammingCode(pPort);
 #endif
 if(bResult!=MODEM_UPDATER_ERROR_NONE)
   return bResult;


 do
    {
     memset(uNV_DATA,0,sizeof(uNV_DATA));
     memset(uNV_data_tmp,0,sizeof(uNV_data_tmp));
     
     /*NvItem id="0" is the FirstAttribute of FirstChildElement*/
     TiXmlAttribute *NvItem_id_u = FirstNvItem_u->FirstAttribute();


     strcpy_s(uNV_data_tmp, sizeof(uNV_data_tmp), FirstNvItem_u->GetText());

     if(!id_find_definitation_to_write(NvItem_id_u,
                                       &FirstNvItem_d, uNV_data_tmp, uNV_DATA))
         return bResult=MODEM_UPDATER_ERROR_Diag_NV_UNDEFINE;

     
     oNVo.NV_ITEM=NvItem_id_u->IntValue();
     
     memcpy(&oNVo.ITEM_DATA[0],&uNV_DATA, sizeof(uNV_DATA));
     
     //Grace, request for 16port download      
     /*use to store error message*/
     char sBuffer[100];
     if(oNVo.NV_ITEM%100==0)
     {
         sprintf_s(sBuffer, sizeof(sBuffer), "WRITE NV #%d ", oNVo.NV_ITEM);
         ProgressReport((oNVo.NV_ITEM * 100/10000), sBuffer);
     }      

     bResult = DIAG_NVWrite(pPort, oNVo);
     if(bResult != MODEM_UPDATER_ERROR_NONE)
        {
         Retry--;
         rResult = bResult;
         FirstNvItem_u=FirstNvItem_u->NextSiblingElement();
         if(Retry>0)
            continue;
         else
            return bResult=MODEM_UPDATER_ERROR_Diag_NV_UPDATE;
        }

     FirstNvItem_u=FirstNvItem_u->NextSiblingElement();

    }while(FirstNvItem_u!=NULL);

    if(!bResult && rResult != MODEM_UPDATER_ERROR_NONE)
        return rResult;

	return bResult;
}


#if NOT_USE_CPP
MODEM_UPDATER_ERROR DIAG_NV_Restore(Port* pPort, char *ufilname_b, char *ufilname_d)
#else
MODEM_UPDATER_ERROR QualcommModemUtilDIAG::DIAG_NV_Restore(Port* pPort, char *ufilname_b, char *ufilname_d)
#endif
{
  MODEM_UPDATER_ERROR bResult = MODEM_UPDATER_ERROR_NONE;  
  MODEM_UPDATER_ERROR rResult = MODEM_UPDATER_ERROR_NONE;
  char uNV_DATA[128];
  char uNV_data_tmp[1024*58];
  int Retry=DIAG_RETRY_TIMES;
    
  DIAG_PACKET_NV oNVo;
    
  /*bfilname_b  "u"-> update function, "_u"->update XML*/
  TiXmlDocument *update = new TiXmlDocument(ufilname_b);
    
  /*bfilname_b  "u"-> update function, "_d"->backup XML*/
  TiXmlDocument *Definition = new TiXmlDocument(ufilname_d);

  if(!Definition->LoadFile())
  {
      ProgressReport(0,"LoadFile Definition.XML FAILED");
      return bResult=MODEM_UPDATER_ERROR_OPEN_NV_FILE;
  }
  else
      ProgressReport(0,"LoadFile Definition.XML Success");
  
  if(!update->LoadFile())
  {
      ProgressReport(0,"LoadFile NV.XML FAILED");
      return bResult=MODEM_UPDATER_ERROR_OPEN_NV_FILE;
  }
  else
      ProgressReport(0,"LoadFile NV.XML Success");     
    
  /*Get <NvDefinition>*/
  TiXmlElement *NvDefinition_u = update->RootElement();
  TiXmlElement *NvDefinition_d = Definition->RootElement();
    
  
  /*<NvItem id="0" name="NV_ESN_I" permission="readwrite">  is FirstChildElement of NvDefinition*/
  TiXmlElement *FirstNvItem_u = NvDefinition_u->FirstChildElement();
  TiXmlElement *FirstNvItem_d = NvDefinition_d->FirstChildElement();

  if(FirstNvItem_u==NULL)
  {
    ProgressReport(0,"Restore empty XML");
    return bResult;
  }
  #if NOT_USE_CPP
  bResult = DIAG_ServiceProgrammingCode(pPort);
  #else
  bResult=QualcommModemUtilDIAG::DIAG_ServiceProgrammingCode(pPort);
  #endif
  if(bResult!=MODEM_UPDATER_ERROR_NONE)
    return bResult;
    
    
  do
     {
      memset(uNV_DATA,0,sizeof(uNV_DATA));
      memset(uNV_data_tmp,0,sizeof(uNV_data_tmp));
        
      /*NvItem id="0" is the FirstAttribute of FirstChildElement*/
      TiXmlAttribute *NvItem_id_u = FirstNvItem_u->FirstAttribute();
    
    
      strcpy_s(uNV_data_tmp, sizeof(uNV_data_tmp), FirstNvItem_u->GetText());
    
      if(!id_find_definitation_to_write(NvItem_id_u,
                                        &FirstNvItem_d, uNV_data_tmp, uNV_DATA))
          return bResult=MODEM_UPDATER_ERROR_Diag_NV_UNDEFINE;
    
        
      oNVo.NV_ITEM=NvItem_id_u->IntValue();
        //DBG_MSG("Restore NV#%d\n", oNVo.NV_ITEM);
        //NV #855 is SPC protected. 
        if (oNVo.NV_ITEM == 855 || oNVo.NV_ITEM == 4719)
        {
            //DBG_MSG("Skip 855\n");
            FirstNvItem_u=FirstNvItem_u->NextSiblingElement();
            continue;
        }
      memcpy(&oNVo.ITEM_DATA[0],&uNV_DATA, sizeof(uNV_DATA));

      //Grace, request for 16port download      
      /*use to store error message*/
      char sBuffer[100];
      if(oNVo.NV_ITEM%100==0)
      {
          sprintf_s(sBuffer, sizeof(sBuffer), "WRITE NV #%d ", oNVo.NV_ITEM);
          ProgressReport((oNVo.NV_ITEM * 100/10000), sBuffer);
      }       

      bResult = DIAG_NVWrite(pPort, oNVo);
      if(bResult != MODEM_UPDATER_ERROR_NONE)
         {
          Retry--;
          rResult = bResult;
          FirstNvItem_u=FirstNvItem_u->NextSiblingElement();
          if(Retry>0)
             continue;
          else
             return bResult=MODEM_UPDATER_ERROR_Diag_NV_RESTORE;
         }
    
      FirstNvItem_u=FirstNvItem_u->NextSiblingElement();
    
     }while(FirstNvItem_u!=NULL);

   if(!bResult && rResult != MODEM_UPDATER_ERROR_NONE)
       return rResult;

   return bResult;

}

#if NOT_USE_CPP
MODEM_UPDATER_ERROR DIAG_NV_Backup(Port* pPort,U16* QNV,U16* UNV, char *bfilname_b, char *bfilname_d)
#else
MODEM_UPDATER_ERROR QualcommModemUtilDIAG::DIAG_NV_Backup(Port* pPort,U16* QNV,U16* UNV, char *bfilname_b, char *bfilname_d)
#endif
{		

   MODEM_UPDATER_ERROR bResult = MODEM_UPDATER_ERROR_NONE;

   /*use to store NV data to XML*/
   char bNV_DATA[260]="";
   DIAG_PACKET_NV oNVo;
   
   TiXmlAttribute *NvItem_ID_d;
   TiXmlAttribute *Index_d;
   TiXmlAttribute *NvItem_Name_d;
   TiXmlElement *NvItem_b;
   TiXmlElement *FirstNvItem_d;

   /*bfilname_b  "b"-> backup function, "_d"->backup XML*/
   TiXmlDocument *backup = new TiXmlDocument(bfilname_b);    

   /*bfilname_d  "b"-> backup function, "_d"->Definitation XML*/
   TiXmlDocument *Definition = new TiXmlDocument(bfilname_d);

   if(!Definition->LoadFile())
   {
       return bResult=MODEM_UPDATER_ERROR_OPEN_NV_FILE;
   }

   /*Set Declaration for Backup XML*/ 
   TiXmlDeclaration *decl = new TiXmlDeclaration( "1.0", "UTF-8", "" );
   backup->LinkEndChild(decl);

   TiXmlElement *RootElement = new TiXmlElement("NvSource");
   backup->LinkEndChild(RootElement);
    
   /*Get <NvDefinition>*/
   TiXmlElement *NvDefinition_d = Definition->RootElement();
   
   /*Get Definittion's NVitem Data*/
   FirstNvItem_d = NvDefinition_d->FirstChildElement();

    
   /*<NvItem id="0" name="NV_ESN_I" permission="readwrite">  is FirstChildElement of NvDefinition*/    
   #if NOT_USE_CPP
   //paul bResult = DIAG_ServiceProgrammingCode(pPort);
   #else
   bResult=QualcommModemUtilDIAG::DIAG_ServiceProgrammingCode(pPort);
   #endif
   if(bResult!=MODEM_UPDATER_ERROR_NONE)
     return bResult;

   #if NOT_USE_CPP
   bResult = DIAG_Set_DIPSwitch(pPort);
   #else
   bResult=QualcommModemUtilDIAG::DIAG_Set_DIPSwitch(pPort);
   #endif
   if(bResult!=MODEM_UPDATER_ERROR_NONE)
     return bResult;

#if 1
   do
    {
       
     static char ITEM_DATA_tmp[2];
     //static char *pbNV_data_tmp;
     int array_size=0;
     memset(&oNVo,0,sizeof(oNVo));

     NvItem_ID_d = FirstNvItem_d->FirstAttribute();
//_LOGK("test NV item %d\n", NvItem_ID_d->IntValue());
//    DBG_MSG("NvItem_ID_d=%d\n", NvItem_ID_d->IntValue());
     if(NvItem_ID_d->IntValue()==313)
     {        
         FirstNvItem_d = FirstNvItem_d->NextSiblingElement();
         continue;
     }
     #if 0
     if(NvItem_ID_d->IntValue() != 1149){
        FirstNvItem_d = FirstNvItem_d->NextSiblingElement();
        continue;
     }
     #endif
     Index_d= FirstNvItem_d->LastAttribute();     
     array_size = Index_d->IntValue();

     if(array_size>0)
         array_size -=1;

     
     for(int index=0;index<=array_size;index++)
     {         
         memset(bNV_DATA,0,sizeof(bNV_DATA));
         oNVo.NV_ITEM=NvItem_ID_d->IntValue();

         bResult = DIAG_NVRead(pPort, oNVo);

         if(bResult == MODEM_UPDATER_ERROR_NONE)
         {
                 /*Convert ITEM_DATA from ff to 'F''F' */
                 for(int k=0; k<128; k++)
                    {
                     sprintf(ITEM_DATA_tmp, "%02x", oNVo.ITEM_DATA[k]);                     
                     strncat(bNV_DATA, ITEM_DATA_tmp, 2);
                    }

                 NvItem_b = new TiXmlElement("NvItem");
                 RootElement->LinkEndChild(NvItem_b);
                 
                   
                 char bNV_data_tmp[NVITEM_MAX_LEN_IN_XML]="";
                 //pbNV_data_tmp=&bNV_data_tmp[0];
                 
                 id_find_definitation_to_read(&FirstNvItem_d, bNV_data_tmp, bNV_DATA); 
                 
/*<NvItem id="0" name="NV_ESN_I" mapping="direct" encoding="dec" array_size="15">0</NvItem>*/                              

                 NvItem_Name_d=NvItem_ID_d->Next();
                 NvItem_b->SetAttribute("id", NvItem_ID_d->IntValue());
                 NvItem_b->SetAttribute("name", NvItem_Name_d->Value());
                 NvItem_b->SetAttribute("mapping", "direct");
                 NvItem_b->SetAttribute("encoding","dec");
                 NvItem_b->SetAttribute("index",index);
                 NvItem_b->LinkEndChild(new TiXmlText(bNV_data_tmp));
                 
                 if(index<array_size)
                 {
                      memset(&oNVo,0,sizeof(oNVo));
                      oNVo.ITEM_DATA[0]=(U8)(index+1);
                 }
                 else
                        break;

         }
         else if(bResult==MODEM_UPDATER_ERROR_Diag_NV_READ_WARNING)
            break;
         else
            return bResult;
     }
     
         FirstNvItem_d = FirstNvItem_d->NextSiblingElement();
     
    }while(FirstNvItem_d!=NULL);
#endif
    DBG_MSG("\nStart to saving %s\n", bfilname_b);
   backup->SaveFile(bfilname_b);
    DBG_MSG("\n%s saved\n", bfilname_b);

#if 0 //paul, comment it temporarily
   /*set the #4719_NV_FTM_MODE_BOOT_COUNT_I NV item, if don't erase flash,
     we also can incoming DIAG mode */
   memset(&oNVo,0,sizeof(oNVo));
   oNVo.NV_ITEM=4719;
   oNVo.ITEM_DATA[0]=1;
   bResult=DIAG_NVWrite(pPort, oNVo);
#endif
    //delete backup;
//DBG_MSG("after \n");
    //delete Definition;
//DBG_MSG("after delete Def\n");    
return bResult;

}
MODEM_UPDATER_ERROR SetNV4719(int value)
{
    DIAG_PACKET_NV oNVo;
    memset(&oNVo,0,sizeof(oNVo));
    oNVo.NV_ITEM=4719;
    oNVo.ITEM_DATA[0] = value;
    return DIAG_NVWrite(0, oNVo);
}
#define PARTITION_CHANGED   1
#define PARTITION_NO_CHANGE 0
int ComparePartitionTable(char * tmpPath)
{
    struct flash_partition_table smem_partition_table;
    struct flash_partition_table mbn_partition_table;
    struct mbn_flash_partition_table tmp_table;
    FILE *fp_part = NULL;
    int i = 0;
    int part_size = 0;
    int retry = 3;
    memset(&smem_partition_table, 0, sizeof(struct flash_partition_table));

    while(retry-- > 0)
    {
        if (DiagGetPartTableFromSMEM(&smem_partition_table))
            break;
    }
    // If we can't get partition table from smem, take it as partition changed situation.
    if (retry <= 0)
        return PARTITION_CHANGED;

    char filename[256];
    sprintf(filename, "%s/" FILENAME_PARTITION_TABLE, tmpPath);
    if (!(fp_part = fopen(filename, "r"))) 
    {
        DBG_MSG("Unable to open '%s'\n", filename);
        return -errno;
    }

    part_size = fread(&tmp_table, 1, sizeof(struct flash_partition_table), fp_part);
    fclose(fp_part);

    if (tmp_table.magic1 != FLASH_USR_PART_MAGIC1 || tmp_table.magic2 != FLASH_USR_PART_MAGIC2)
    {
        DBG_MSG("Wrong magic number in '%s'\n", FILENAME_PARTITION_TABLE);
        return -1;
    }
    if (smem_partition_table.numparts != tmp_table.numparts)
        return PARTITION_CHANGED;

    memcpy(&mbn_partition_table, &tmp_table, sizeof(struct flash_partition_table));
    for (i=0; i<tmp_table.numparts; i++)
    {
        if (strncmp(tmp_table.part_entry[i].name, MIBIB_PARTITION_NAME, sizeof(tmp_table.part_entry[i].name)) == 0)
        {
            // unit is block, the offset is zero
            mbn_partition_table.part_entry[i].offset = 0;
            mbn_partition_table.part_entry[i].length = tmp_table.part_entry[i].size + tmp_table.part_entry[i].reserved_size;
        }
        else if (strncmp(tmp_table.part_entry[i].name, SIM_SECURE_PARTITION_NAME, sizeof(tmp_table.part_entry[i].name)) == 0)
        {
            // unit is block. The secure_sim partition is always right after the MIBIB.
            mbn_partition_table.part_entry[i].offset = mbn_partition_table.part_entry[i-1].length;
            mbn_partition_table.part_entry[i].length = tmp_table.part_entry[i].size + tmp_table.part_entry[i].reserved_size;
        }
        else if (i == (tmp_table.numparts - 1))
        {   // The length of the last partition is usually set to GROW (0xFFFFFFFF)
            mbn_partition_table.part_entry[i].offset = mbn_partition_table.part_entry[i-1].offset + mbn_partition_table.part_entry[i-1].length;
            mbn_partition_table.part_entry[i].length = tmp_table.part_entry[i].size;
        }
        else
        {
            // unit is kbyte
            mbn_partition_table.part_entry[i].offset = mbn_partition_table.part_entry[i-1].offset + mbn_partition_table.part_entry[i-1].length;
            // (size + 127)/128 + (reserved + 127)/128
            mbn_partition_table.part_entry[i].length = 
                (tmp_table.part_entry[i].size + NAND_BLOCK_SIZE_KB -1)/NAND_BLOCK_SIZE_KB + (tmp_table.part_entry[i].reserved_size + NAND_BLOCK_SIZE_KB -1)/NAND_BLOCK_SIZE_KB;
        }
    }

    // Compare the partition table
    // for (i=0; i<smem_partition_table.numparts; i++)
    // Just compare the partitions before EFS2. Only need to back up NV when EFS2 partition is changed!
    for (i=0; i <= EFS2_PARTITION_NUMBER; i++)
    {
        if (mbn_partition_table.part_entry[i].offset != smem_partition_table.part_entry[i].offset)
            break;
        if (mbn_partition_table.part_entry[i].length != smem_partition_table.part_entry[i].length)
            break;
        if (strncmp(mbn_partition_table.part_entry[i].name, smem_partition_table.part_entry[i].name, sizeof(mbn_partition_table.part_entry[i].name)))
            break;
    }
    if (i <= EFS2_PARTITION_NUMBER)
    {
        DBG_MSG("Partition changed! Dump partition table\n");
        DBG_MSG("From mbn:\n");
        for (i=0; i<mbn_partition_table.numparts; i++)
        {
            DBG_MSG("name %s ofs=%x len=%x attr=%02x%02x%02x%02x\n", 
                mbn_partition_table.part_entry[i].name,
                mbn_partition_table.part_entry[i].offset,
                mbn_partition_table.part_entry[i].length,
                mbn_partition_table.part_entry[i].attrib1,
                mbn_partition_table.part_entry[i].attrib2,
                mbn_partition_table.part_entry[i].attrib3,
                mbn_partition_table.part_entry[i].which_flash);
        }
        DBG_MSG("From smem:\n");
        for (i=0; i<smem_partition_table.numparts; i++)
        {
            DBG_MSG("name %s ofs=%x len=%x attr=%02x%02x%02x%02x\n", 
                smem_partition_table.part_entry[i].name,
                smem_partition_table.part_entry[i].offset,
                smem_partition_table.part_entry[i].length,
                smem_partition_table.part_entry[i].attrib1,
                smem_partition_table.part_entry[i].attrib2,
                smem_partition_table.part_entry[i].attrib3,
                smem_partition_table.part_entry[i].which_flash);
        }
        return PARTITION_CHANGED;
    }
    return PARTITION_NO_CHANGE;
}
#define CHECK_KVL_PROJ_ID       (1 << 11)
#define CHECK_KVL_MODEL_CODE    (1 << 10)
#define CHECK_KVL_ANDROID_VER   (1 << 9)
#define CHECK_KVL_USERDATA_VER  (1 << 8)
#define CHECK_MD5_CHKSUM    (1 << 7)
#define CHECK_CHANNEL_ID    (1 << 6)
#define CHECK_MODEL_ID      (1 << 5)
#define CHECK_GMS_STATE     (1 << 4)
#define CHECK_REGION_ID     (1 << 3)
#define CHECK_CUSTOMER_ID   (1 << 2)
#define CHECK_HW_VERSION    (1 << 1)
#define CHECK_RESERVED      (1 << 0)
#define CHECK_FLAG_MAGIC    0xAA550000
#define FORCE_UPDATE_FILENAME   "/sdcard/2038ForceUPDATE"
unsigned int CheckForceUpdateFile()
{
    FILE *fp = NULL;
    unsigned int check_flag = 0xFFFF;
    if ((fp = fopen(FORCE_UPDATE_FILENAME, "r")))
    {
        fscanf(fp, "%x", &check_flag);
        DBG_MSG("check_flag from file: 0x%X\n", check_flag);
        if ((check_flag & 0xFFFF0000) != CHECK_FLAG_MAGIC)
        {
            check_flag = 0xFFFF;
            DBG_MSG("check_flag is invalid! Check all\n");
        }
        else
        {
            check_flag &= 0x0000FFFF;
        }
    }
    if (fp)
        fclose(fp);
    DBG_MSG("check_flag=0x%X\n", check_flag);
    return check_flag;
}

#define FIH_VERSION_NV_ID   8030
#define FIH_VERSION_NV_SIZE 128
#define KLV_FORMAT_OFFSET   25  // The KLV format info starting at 26th byte

enum KLV_KEY{
    PROJECT_ID = 1,
    MODEL_CODE,
    ANDROID_VERSION,
    USERDATA_VERSION,
    MAX_KLV_KEY_NR,
};

/*
KLV Format is defined by tool team
KEY --> 1 byte --> ASCII character.
LENGTH --> 2 bytes --> Hexadecimal chracters.
VALUE --> N bytes --> ASCII characters with length defined by LENGTH field.
*/
typedef struct 
{
    BYTE key;
    WORD length;
    char pStr[32];
}KLV_FORMAT;

typedef struct 
{
    BYTE format_ver;
    char software_ver[5];
    char channel_id[5];
    char model_id[5];
    char region_id[4];
    BYTE gms;
    char customer_id[5];
    BYTE hardware_ver;
    char reserved[4];
    KLV_FORMAT klv[MAX_KLV_KEY_NR - 1];
}FIH_PID_INFO_VER_0;

void ParseFihPidInfo(unsigned char *pSrc, FIH_PID_INFO_VER_0 * ppid_info)
{
    int i = 0, j = 0;
    char len[3];
    ppid_info->format_ver = pSrc[0] - '0';
    memcpy(ppid_info->software_ver, &pSrc[1], 4);
    ppid_info->software_ver[4] = 0; //Add null ended character
    memcpy(ppid_info->channel_id, &pSrc[5], 4);
    ppid_info->channel_id[4] = 0; //Add null ended character
    memcpy(ppid_info->model_id, &pSrc[9], 4);
    ppid_info->model_id[4] = 0; //Add null ended character
    memcpy(ppid_info->region_id, &pSrc[13], 3);
    ppid_info->region_id[3] = 0; //Add null ended character
    ppid_info->gms = pSrc[16] - '0';
    memcpy(ppid_info->customer_id, &pSrc[17], 4);
    ppid_info->customer_id[4] = 0; //Add null ended character
    ppid_info->hardware_ver = pSrc[21] - '0';
    memcpy(ppid_info->reserved, &pSrc[22], 3);
    ppid_info->reserved[3] = 0; //Add null ended character

    memset(&ppid_info->klv[0], 0, sizeof(KLV_FORMAT)*(MAX_KLV_KEY_NR - 1));
    i = KLV_FORMAT_OFFSET;
    if (pSrc[i] == 0)
        return; //No KLV information

    for (j=0 ; j<(MAX_KLV_KEY_NR - 1); j++)
    {
        ppid_info->klv[j].key = pSrc[i] - '0';
        i++;
        memset(len, 0, sizeof(len));
        memcpy(len, &pSrc[i], sizeof(WORD));
        sscanf_s(len, "%X", &ppid_info->klv[j].length);
        i += sizeof(WORD);
        strncpy(ppid_info->klv[j].pStr, (char*)&pSrc[i], ppid_info->klv[j].length);
        i += ppid_info->klv[j].length;
        //DBG_MSG("klv key=%d, len=%d, str=%s\n", ppid_info->klv[j].key, ppid_info->klv[j].length, ppid_info->klv[j].pStr);
    }
}

static FIH_PID_INFO_VER_0 pid_orig, pid_new;
int need_erase_userdata()
{
    if (pid_orig.klv[0].key && pid_new.klv[0].key)
    {
#if 0
        if (strcmp(pid_orig.klv[MODEL_CODE-1].pStr, pid_new.klv[MODEL_CODE-1].pStr)
            || strcmp(pid_orig.klv[ANDROID_VERSION-1].pStr, pid_new.klv[ANDROID_VERSION-1].pStr)
            || strcmp(pid_orig.klv[USERDATA_VERSION-1].pStr, pid_new.klv[USERDATA_VERSION-1].pStr))
#else
	if (strcmp(pid_orig.klv[MODEL_CODE-1].pStr, pid_new.klv[MODEL_CODE-1].pStr))
#endif
        {
            return 1;
        }
        
    }
    else if (strncmp(pid_orig.customer_id, pid_new.customer_id, sizeof(pid_orig.customer_id)))
    {
        return 1;
    }
    return 0;
}

int CheckFIHVersion(char* nv_file, unsigned int check_flag)
{
    DIAG_PACKET_NV oNVo;
    int result = MODEM_UPDATER_ERROR_NONE;
    TiXmlDocument *cust_nv = new TiXmlDocument(nv_file);
    TiXmlElement *ElDef;// = cust_nv->RootElement();
    TiXmlElement *ElNvItem_idx;// = ElDef->FirstChildElement();
    TiXmlAttribute *NvItem_ID;    
    char fih_version[FIH_VERSION_NV_SIZE*3];
    unsigned char byte_data[FIH_VERSION_NV_SIZE];
    BOOL    version_nv_is_found = FALSE;
    int key;
//    FIH_PID_INFO_VER_0 pid_orig, pid_new;

    memset(&oNVo,0,sizeof(oNVo));
    oNVo.NV_ITEM = FIH_VERSION_NV_ID;
    result = DIAG_NVRead(0, oNVo);
    if(result == MODEM_UPDATER_ERROR_NONE)
    {
        //for(int k=0; k<128; k++)
        //{
            //sprintf(&fih_version[k*3], "%02d,", oNVo.ITEM_DATA[k]);
        //    DBG_MSG("%02d ", oNVo.ITEM_DATA[k]);
        //}
        //DBG_MSG("\n");
        ParseFihPidInfo(oNVo.ITEM_DATA, &pid_orig);
        //DBG_MSG("ver=%d, softVer=%s, chID=%s", pid_orig.format_ver, pid_orig.software_ver, pid_orig.channel_id);
    }
    else
    {
        DBG_MSG("Read NV 8030 failed, rc=%d\n", result);
        result = -1;
        goto lbExit;
    }

    if(!cust_nv->LoadFile())
    {
        DBG_MSG("Fail to load %s\n", nv_file);
        result = -2;
        goto lbExit;
    }
    ElDef = cust_nv->RootElement();
    ElNvItem_idx = ElDef->FirstChildElement();
    if (ElNvItem_idx == NULL)
    {
        DBG_MSG("%s may be empty\n", nv_file);
        result = -3;
        goto lbExit;
    }

    do
    {
        NvItem_ID = ElNvItem_idx->FirstAttribute();
        //DBG_MSG("NV item ID:%d\n", NvItem_ID_d->IntValue());
        //DBG_MSG("FirstNvItem_d %s\n", FirstNvItem_d->GetText());
        if (NvItem_ID->IntValue() == FIH_VERSION_NV_ID)
        {
            char *pch;
            char *position;
            unsigned int u32tmp;

            version_nv_is_found = TRUE;
            memset(fih_version, 0, sizeof(fih_version));
            snprintf(fih_version, sizeof(fih_version), "%s", ElNvItem_idx->GetText());
            memset(byte_data, 0, sizeof(byte_data));
            pch = strtok_s(fih_version, ",", &position);
            sscanf_s(pch, "%u", &u32tmp);
            byte_data[0] = (unsigned char)u32tmp;
            for (int k=1;k<FIH_VERSION_NV_SIZE; k++)
            {
                pch = strtok_s(NULL, ",", &position);
                sscanf_s(pch, "%u", &u32tmp);
                byte_data[k] = (unsigned char)u32tmp;
            }
        }
        ElNvItem_idx = ElNvItem_idx->NextSiblingElement();
    }while(ElNvItem_idx != NULL);

    if (version_nv_is_found == FALSE)
    {
        DBG_MSG("Can't find NV_FIH_VERSION_I in %s\n", nv_file);
        result = -4;
        goto lbExit;
    }

    ParseFihPidInfo(byte_data, &pid_new);
    
    //Compare two pid
    //if fail, result = -5;
    if (check_flag&CHECK_CHANNEL_ID)
    {
        if (strncmp(pid_orig.channel_id, pid_new.channel_id, sizeof(pid_orig.channel_id)))
        {
            result = -5;
            DBG_MSG("Channel ID doesn't match! orig:%s new:%s\n", pid_orig.channel_id, pid_new.channel_id);
            goto lbExit;
        }
    }
    if (check_flag&CHECK_MODEL_ID)
    {
        if (strncmp(pid_orig.model_id, pid_new.model_id, sizeof(pid_orig.model_id)))
        {
            result = -5;
            DBG_MSG("Model ID doesn't match! orig:%s new:%s\n", pid_orig.model_id, pid_new.model_id);
            goto lbExit;
        }
    }
    if (check_flag&CHECK_GMS_STATE)
    {
        if (pid_orig.gms != pid_new.gms)
        {
            result = -5;
            DBG_MSG("GMS state doesn't match! orig:%d new:%d\n", pid_orig.gms, pid_new.gms);
            goto lbExit;
        }
    }
    if (check_flag&CHECK_REGION_ID)
    {
        if (strncmp(pid_orig.region_id, pid_new.region_id, sizeof(pid_orig.region_id)))
        {
            result = -5;
            DBG_MSG("Region ID doesn't match! orig:%s new:%s\n", pid_orig.region_id, pid_new.region_id);
            goto lbExit;
        }
    }
    if (check_flag&CHECK_CUSTOMER_ID)
    {
        if (strncmp(pid_orig.customer_id, pid_new.customer_id, sizeof(pid_orig.customer_id)))
        {
            result = -5;
            DBG_MSG("Customer ID doesn't match! orig:%s new:%s\n", pid_orig.customer_id, pid_new.customer_id);
            goto lbExit;
        }
    }
    if (check_flag&CHECK_HW_VERSION)
    {
        if (pid_orig.hardware_ver != pid_new.hardware_ver)
        {
            result = -5;
            DBG_MSG("Hardware version doesn't match! orig:%d new:%d\n", pid_orig.hardware_ver, pid_new.hardware_ver);
            goto lbExit;
        }
    }
    if (check_flag&CHECK_RESERVED)
    {
        if (strncmp(pid_orig.reserved, pid_new.reserved, sizeof(pid_orig.reserved)))
        {
            result = -5;
            DBG_MSG("Reserved bytes doesn't match! orig:%s new:%s\n", pid_orig.reserved, pid_new.reserved);
            goto lbExit;
        }
    }

    key = PROJECT_ID - 1;
    
    if (pid_orig.klv[key].key && pid_new.klv[key].key)
    {
        if (check_flag&CHECK_KVL_PROJ_ID)
        {
            if (strcmp(pid_orig.klv[key].pStr, pid_new.klv[key].pStr))
            {
                result = -5;
                DBG_MSG("KVL project id doesn't match! orig:%s new:%s\n", pid_orig.klv[key].pStr, pid_new.klv[key].pStr);
                goto lbExit;
            }
        }
        key = MODEL_CODE - 1;
        if (check_flag&CHECK_KVL_MODEL_CODE)
        {
            if (strcmp(pid_orig.klv[key].pStr, pid_new.klv[key].pStr))
            {
                result = -5;
                DBG_MSG("KVL model code doesn't match! orig:%s new:%s\n", pid_orig.klv[key].pStr, pid_new.klv[key].pStr);
                goto lbExit;
            }
        }
        key = ANDROID_VERSION - 1;
        if (check_flag&CHECK_KVL_ANDROID_VER)
        {
            if (strcmp(pid_orig.klv[key].pStr, pid_new.klv[key].pStr))
            {
            	DBG_MSG("KVL android ver. doesn't match! orig:%s new:%s\n", pid_orig.klv[key].pStr, pid_new.klv[key].pStr);
#if 0//[] EricCHWang remove the ANDROID_VER check procedure  
                result = -5;
                goto lbExit;
#endif
            }
        }
        key = USERDATA_VERSION - 1;
        if (check_flag&CHECK_KVL_USERDATA_VER)
        {
            if (strcmp(pid_orig.klv[key].pStr, pid_new.klv[key].pStr))
            {
            	DBG_MSG("KVL userdata ver. doesn't match! orig:%s new:%s\n", pid_orig.klv[key].pStr, pid_new.klv[key].pStr);
#if 0//[FM6F.B-1273] EricCHWang remove the userdata check procedure             	
                result = -5;      
                goto lbExit;
#endif
            }
        }

    }
    result = 0;
lbExit:

    return result;
}

uint32 count_XOR_checksum(uint32 *pBuf, uint32 size)
{
    int i;
    uint32 chksum = 0;
    for(i = 0; i<size ; i+=4)
        chksum ^= *pBuf++;

    return chksum;
}
#define OPTION_DOWNLOAD "-download" //  Download firmware
#define OPTION_RESTORE  "-restore"  //  Restore NV
#define FILENAME_PARTITION_CHANGED  "part_changed"  //To indicate that we need to restore the backup NV

enum IMG_UPDATE_ERROR_CODE
{
    ERROR_OPEN_PIPE_FD = 201,
    ERROR_GET_HW_ID,
    ERROR_PARSE_NB0,
    ERROR_BACKUP_NV,
    ERROR_PASS_FILE_LIST_TO_MODEM,
    ERROR_SET_NV4719,
    ERROR_PARTITION_TABLE_IS_WRONG,
    ERROR_RESTORE_NV,
    ERROR_FIH_VERSION_NV_NOT_MATCH
};

int main(int argc, char **argv)
{
    FILE *fp_nv_def = NULL;
    FILE *fp_tmp = NULL;
    char nv_def_filename[256];// = "/data/NvDefinition.xml";
    char nv_bak_filename[256];// = "/data/backup.xml";
    char tmp_filename[256];
    char tmp_filename2[256];
    DL_FILE_LIST hlist;
    char *tmpPath = "/sdcard";
    int rc = 0;
    int pipe_fd = -1;   //From parent

    char hw_id[DIAGOEM_HWID_DATE_STRLEN];
    int partition_changed = 0;
    unsigned int check_flag;

    if (strcmp(OPTION_DOWNLOAD, argv[1]) == 0)
    {
        if (argc >= 4)
        {
            pipe_fd = atoi(argv[3]);    //From parent
            DBG_MSG("fih_imgupd pipe fd: %s atoi=%d\n", argv[3], pipe_fd);
        }
        DBG_MSG("nb0 file: %s\n", argv[2]);
        fp_pipe = fdopen(pipe_fd, "w");
        if (fp_pipe == NULL)
        {
            DBG_MSG("fih_imgupd Fail to open pipe_fd\n");
            rc = -ERROR_OPEN_PIPE_FD;
            goto lbExit;
        }

        if (DIAG_Get_Hw_ID(0, hw_id) != MODEM_UPDATER_ERROR_NONE)
        {
            DBG_MSG("DIAG get HW ID failed\n");
            rc = -ERROR_GET_HW_ID;
            goto lbExit;
        }
        DBG_MSG("DIAG get HW ID = %s\n", hw_id);

        check_flag = CheckForceUpdateFile();

        // parse nb0 and get firmware list
        // extract some files from nb0: nvdefinition.xml, temp.mlf, cust_nv.xml, static_nv.xml and partition.mbn
        memset(&hlist, 0, sizeof(hlist));
        hlist.Flist.MAGIC_NUM = FIRMWARE_LIST_MAGIC;
        if (ParseNB0(argv[2], (DL_FILE_LIST*)&hlist, tmpPath, hw_id, (check_flag&CHECK_MD5_CHKSUM)))
        {
            DBG_MSG("ParseNB0 failed\n");
            rc = -ERROR_PARSE_NB0;
            goto lbExit;
        }
        hlist.Flist.checksum = count_XOR_checksum((uint32*)&hlist.Flist, sizeof(FirmwareList));

        memset(tmp_filename, 0, sizeof(tmp_filename));
        sprintf(tmp_filename, "%s/" FILENAME_CUSTOM_NV, tmpPath);
        if (CheckFIHVersion(tmp_filename, check_flag))
        {
            DBG_MSG("PID check failed\n");
            rc = -ERROR_FIH_VERSION_NV_NOT_MATCH;
            goto lbExit;
        }
        // By tool team's request. To erase userdata if model is different.
        if (need_erase_userdata())
        {
            DBG_MSG("Need to erase userdata\n");
            sprintf(tmp_filename, "%s/" FILENAME_ERASE_USER_DATA, tmpPath);
            if (!(fp_tmp = fopen(tmp_filename, "w")))
            {
                DBG_MSG("Unable to create '%s'\n", tmp_filename);
            }
            else
            {
                fclose(fp_tmp);
                fp_tmp = NULL;
            }
        }
        partition_changed = ComparePartitionTable(tmpPath);
        // Remove the partition.mbn after comparing the partition table
        sprintf(tmp_filename, "%s/" FILENAME_PARTITION_TABLE, tmpPath);
        if ((unlink(tmp_filename) && errno != ENOENT)) {
            DBG_MSG("Can't unlink %s\n", tmp_filename);
        }

        if (partition_changed == PARTITION_CHANGED)
        {
            // backup NV
            memset(nv_def_filename, 0, sizeof(nv_def_filename));
            sprintf(nv_def_filename, "%s/" FILENAME_DEFINITION_NV, tmpPath);
            //sprintf(nv_def_filename, "%s/%s", tmpPath, hlist.NVDefFile);

            if (!(fp_nv_def = fopen(nv_def_filename, "r"))) 
            {
                DBG_MSG("Unable to open '%s'\n", nv_def_filename);
                rc = -errno;
                goto lbExit;
            }
            fclose(fp_nv_def);
            memset(nv_bak_filename, 0, sizeof(nv_bak_filename));
            sprintf(nv_bak_filename, "%s/" FILENAME_BACKUP_NV, tmpPath);

            DBG_MSG("Start NV backup\n");
            rc = DIAG_NV_Backup(0, 0, 0, nv_bak_filename, nv_def_filename);

            if ( rc != MODEM_UPDATER_ERROR_NONE && rc != MODEM_UPDATER_ERROR_Diag_NV_READ_WARNING )
            {
                DBG_MSG("NV backup failed\n");
                rc = -ERROR_BACKUP_NV;
                goto lbExit;
            }
        }
        else if (partition_changed < 0)
        {
            DBG_MSG("Partition table file is wrong!\n");
            rc = -ERROR_PARTITION_TABLE_IS_WRONG;
            goto lbExit;
        }

        if (!DiagPassFirmwareList((FirmwareList*) &hlist.Flist))
        {
            DBG_MSG("DiagPassFirmwareList failed\n");
            rc = -ERROR_PASS_FILE_LIST_TO_MODEM;
            goto lbExit;
        }

        if (partition_changed == PARTITION_CHANGED)
        {
            sprintf(nv_bak_filename,"%s/"FILENAME_PARTITION_CHANGED, tmpPath);
            if (!(fp_tmp = fopen(nv_bak_filename, "w")))
            {
                DBG_MSG("Unable to open '%s'\n", nv_bak_filename);
                rc = -errno;
                goto lbExit;
            }
            fclose(fp_tmp);
        }

        // set the #4719_NV_FTM_MODE_BOOT_COUNT_I NV item to enter recovery mode
#ifndef SKIP_RESTORE_NV
        if (SetNV4719(1) != MODEM_UPDATER_ERROR_NONE)
        {
            DBG_MSG("Write NV 4719 failed\n");
            rc = -ERROR_SET_NV4719;
            goto lbExit;
        }
#endif
	}
	else if (strcmp(OPTION_RESTORE, argv[1]) == 0)
    {
        if (argc >= 4)
        {
            pipe_fd = atoi(argv[3]);    //From parent process
            DBG_MSG("fih_imgupd pipe fd: %s atoi=%d\n", argv[3], pipe_fd);
        }

        fp_pipe = fdopen(pipe_fd, "w");
        if (fp_pipe == NULL)
        {
            DBG_MSG("fih_imgupd Fail to open pipe_fd\n");
            rc = -ERROR_OPEN_PIPE_FD;
            goto lbExit;
        }

        // Remove the /sdcard/2038ForceUPDATE after images are downloaded.
        if ((unlink(FORCE_UPDATE_FILENAME) && errno != ENOENT)) {
            DBG_MSG("Can't unlink %s\n", FORCE_UPDATE_FILENAME);
        }

        memset(nv_def_filename, 0, sizeof(nv_def_filename));
        sprintf(nv_def_filename, "%s/" FILENAME_DEFINITION_NV, tmpPath);
       
        memset(tmp_filename, 0, sizeof(tmp_filename));
        sprintf(tmp_filename, "%s/" FILENAME_PARTITION_CHANGED, tmpPath);
        // if partition table is different, we need to restore backup.xml
        if ((fp_tmp = fopen(tmp_filename, "r"))) // The file part_changed exists means the partition is changed
        {
            DBG_MSG("Start restore" " backed-up NV\n");

            memset(nv_bak_filename, 0, sizeof(nv_bak_filename));
            sprintf(nv_bak_filename, "%s/" FILENAME_BACKUP_NV, tmpPath);
            if (DIAG_NV_Restore(0, nv_bak_filename, nv_def_filename) != MODEM_UPDATER_ERROR_NONE)
            {
                rc = -ERROR_RESTORE_NV;
                goto lbExit;
            }
        }
        else
        {
           	DBG_MSG("Start restore" " static NV\n");
            sprintf(nv_bak_filename, "%s/" FILENAME_STATIC_NV, tmpPath);
            if (DIAG_NV_Restore(0, nv_bak_filename, nv_def_filename) != MODEM_UPDATER_ERROR_NONE)
            {
                rc = -ERROR_RESTORE_NV;
                goto lbExit;
            }
        }
        DBG_MSG("Start restore" " custom NV\n");

        memset(tmp_filename2, 0, sizeof(tmp_filename));
        sprintf(tmp_filename2, "%s/" FILENAME_CUSTOM_NV, tmpPath);
        if (DIAG_NV_Restore(0, tmp_filename2, nv_def_filename) != MODEM_UPDATER_ERROR_NONE)
        {
            rc = -ERROR_RESTORE_NV;
            goto lbExit;
        }
        DBG_MSG("restore end\n");

        // Remove all temp files
        if (unlink(tmp_filename) && errno != ENOENT) // The file "part_changed"
        {
            DBG_MSG("Can't unlink %s\n", tmp_filename);
        }
        if (unlink(nv_bak_filename) && errno != ENOENT)  // The file "static_nv.xml" or "backup_nv.xml"
        {
            DBG_MSG("Can't unlink %s\n", nv_bak_filename);
        }
        if (unlink(tmp_filename2) && errno != ENOENT) // The file "cust_nv.xml"
        {
            DBG_MSG("Can't unlink %s\n", tmp_filename2);
        }
        if (unlink(nv_def_filename) && errno != ENOENT) // The file "nvdefinition.xml"
        {
            DBG_MSG("Can't unlink %s\n", nv_def_filename);
        }
    }

    rc = 0;

lbExit:

    if (fp_pipe)
    {
        if (rc == 0)
        {
            fprintf(fp_pipe, "imgupd success\n");
        }
        else if (rc < 0)
        {
            fprintf(fp_pipe, "imgupd failed %d\n", rc);
        }
        fclose(fp_pipe);
        fp_pipe = NULL;
    }
    return rc;
}

