/*
##############################################################################
# Copyright (c) 2008 FIHTDC, Inc. or its subsidiaries.
# All rights reserved.
##############################################################################*/

#pragma once

//#include "UtilCRC.h"
//#include "utility.h"
//#include "port.h"

#pragma pack(1)

#if 1   //paul
	enum MODEM_MODE
	{
		MODE_UNKNOWN,
		MODE_DIAG,
		MODE_DLOAD,
		MODE_ARMPRG
	};
	
	typedef struct _CONTAINER
	{
		U8* pRequest;
		U16 iRequestLen;
		U8* pResponse;
		U16 iResponseLen;
	    U32* pRequestRef;
	    U32* pResponseRef;
	    U8  iTimeoutSec;
	}CONTAINER; 
#else   //paul
namespace QualcommModemUtil
{
	
	enum SESSION_MODE
	{
		ONE_WAY,
		TWO_WAY,
		T_WAY,
		R_WAY
	};

	BOOL EncodeEscape(/*[out]*/U8* pNewPack, /*[out]*/U16 &iNewPackLen,/*[in]*/const U8* pPack,/*[in]*/ U16 iPackLen);
	BOOL DecodeEscape(/*[in,out]*/U8* pPack, /*[in,out]*/U16 &iPackSize);

	U16 wordByteSwap(U16 val);
	U32 dwordByteSwap(U32 val);
	
	enum MODEM_MODE
	{
		MODE_UNKNOWN,
		MODE_DIAG,
		MODE_DLOAD,
		MODE_ARMPRG
	};
	
	struct CONTAINER
	{
		U8* pRequest;
		U16 iRequestLen;
		U8* pResponse;
		U16 iResponseLen;
	    U32* pRequestRef;
	    U32* pResponseRef;
	    U8  iTimeoutSec;
	}; 

	MODEM_MODE GetModemMode(Port* pPort);
};
#endif //paul
