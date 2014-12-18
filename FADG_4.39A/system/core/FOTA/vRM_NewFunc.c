		/*********************************************************
	  **					C O N F I D E N T I A L             **
	 **						  Copyright ® 2002-2010             **
	  **                         Red Bend Software              **
		**********************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Red Bend implementation of vRM 6.x porting layer function for vCM 5.x File System users
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "./headerfiles/RB_vRM_ImageUpdate.h"

#define MAX_INT 0xefffffff

/* vrm functions */
long RB_GetAvailableFreeSpace(void* pbUserData, unsigned short* partition_name, unsigned long* available_flash_size)
{
	*available_flash_size = MAX_INT;
	return 0;
}

long RB_GetRBDeltaOffset(void* pbUserData, unsigned long delta_ordinal, unsigned long* delta_offset, unsigned long *installer_types, unsigned long installer_types_num, UpdateType update_type)
{
	unsigned long size = 0;
	return RB_GetSignedDeltaOffset(delta_ordinal, delta_offset, &size, installer_types, installer_types_num, update_type);
}
