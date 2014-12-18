/* libModemInterface.h
##############################################################################
# Copyright (c) 2008 FIHTDC, Inc. or its subsidiaries.
# All rights reserved.
##############################################################################*/

#ifndef _CRC_H_
#define _CRC_H_

#include "comdef.h"
//#include "platform.h"

namespace UtilCRC
{
	U16 crc_16l_calc (const byte * buffer, U16 length);
    U16 crc_16l_calc_seed (word seed, const byte * buffer, U16 length);
	U16 crc_16l_step (const byte * buffer, U16 length, U16 seed);
}

#endif
