/* Copyright (c) 2008-2011, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of Code Aurora Forum, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef DIAGCHAR_SHARED
#define DIAGCHAR_SHARED

#define MSG_MASKS_TYPE			1
#define LOG_MASKS_TYPE			2
#define EVENT_MASKS_TYPE		4
#define PKT_TYPE			8
#define DEINIT_TYPE			16
#define MEMORY_DEVICE_LOG_TYPE		32
#define USB_MODE			1
#define MEMORY_DEVICE_MODE		2
#define NO_LOGGING_MODE			3
#define MAX_SYNC_OBJ_NAME_SIZE		32

/* different values that go in for diag_data_type */
#define DATA_TYPE_EVENT         	0
#define DATA_TYPE_F3            	1
#define DATA_TYPE_LOG           	2
#define DATA_TYPE_RESPONSE      	3

/* Different IOCTL values */
#define DIAG_IOCTL_COMMAND_REG  	0
#define DIAG_IOCTL_SWITCH_LOGGING	7
#define DIAG_IOCTL_GET_DELAYED_RSP_ID 	8
#define DIAG_IOCTL_LSM_DEINIT		9
// +++ EricCHWang, SD card download
#define DIAG_IOCTL_WRITE_BUFFER 10
#define DIAG_IOCTL_READ_BUFFER  11
#define DIAG_IOCTL_PASS_FIRMWARE_LIST  12
#define DIAG_IOCTL_GET_PART_TABLE_FROM_SMEM  13
// --- EricCHWang, SD card download

/* Machine ID and corresponding PC Tools IDs */
#define APQ8060_MACHINE_ID	86
#define AO8960_MACHINE_ID	87
#define APQ8060_TOOLS_ID	4062
#define AO8960_TOOLS_ID		4064

#define MSG_MASK_0			(0x00000001)
#define MSG_MASK_1			(0x00000002)
#define MSG_MASK_2			(0x00000004)
#define MSG_MASK_3			(0x00000008)
#define MSG_MASK_4			(0x00000010)
#define MSG_MASK_5			(0x00000020)
#define MSG_MASK_6			(0x00000040)
#define MSG_MASK_7			(0x00000080)
#define MSG_MASK_8			(0x00000100)
#define MSG_MASK_9			(0x00000200)
#define MSG_MASK_10			(0x00000400)
#define MSG_MASK_11			(0x00000800)
#define MSG_MASK_12			(0x00001000)
#define MSG_MASK_13			(0x00002000)
#define MSG_MASK_14			(0x00004000)
#define MSG_MASK_15			(0x00008000)
#define MSG_MASK_16			(0x00010000)
#define MSG_MASK_17			(0x00020000)
#define MSG_MASK_18			(0x00040000)
#define MSG_MASK_19			(0x00080000)
#define MSG_MASK_20			(0x00100000)
#define MSG_MASK_21			(0x00200000)
#define MSG_MASK_22			(0x00400000)
#define MSG_MASK_23			(0x00800000)
#define MSG_MASK_24			(0x01000000)
#define MSG_MASK_25			(0x02000000)
#define MSG_MASK_26			(0x04000000)
#define MSG_MASK_27			(0x08000000)
#define MSG_MASK_28			(0x10000000)
#define MSG_MASK_29			(0x20000000)
#define MSG_MASK_30			(0x40000000)
#define MSG_MASK_31			(0x80000000)

/*  These masks are to be used for support of all legacy messages in the sw.
The user does not need to remember the names as they will be embedded in
the appropriate macros. */
#define MSG_LEGACY_LOW			MSG_MASK_0
#define MSG_LEGACY_MED			MSG_MASK_1
#define MSG_LEGACY_HIGH			MSG_MASK_2
#define MSG_LEGACY_ERROR		MSG_MASK_3
#define MSG_LEGACY_FATAL		MSG_MASK_4

/* Legacy Message Priorities */
#define MSG_LVL_FATAL			(MSG_LEGACY_FATAL)
#define MSG_LVL_ERROR			(MSG_LEGACY_ERROR | MSG_LVL_FATAL)
#define MSG_LVL_HIGH			(MSG_LEGACY_HIGH | MSG_LVL_ERROR)
#define MSG_LVL_MED			(MSG_LEGACY_MED | MSG_LVL_HIGH)
#define MSG_LVL_LOW			(MSG_LEGACY_LOW | MSG_LVL_MED)

#define MSG_LVL_NONE			0

/* This needs to be modified manually now, when we add
 a new RANGE of SSIDs to the msg_mask_tbl */
#define MSG_MASK_TBL_CNT		19
#define EVENT_LAST_ID			0x083F

#define MSG_SSID_0			0
#define MSG_SSID_0_LAST			68
#define MSG_SSID_1			500
#define MSG_SSID_1_LAST			506
#define MSG_SSID_2			1000
#define MSG_SSID_2_LAST			1007
#define MSG_SSID_3			2000
#define MSG_SSID_3_LAST			2008
#define MSG_SSID_4			3000
#define MSG_SSID_4_LAST			3012
#define MSG_SSID_5			4000
#define MSG_SSID_5_LAST			4010
#define MSG_SSID_6			4500
#define MSG_SSID_6_LAST			4526
#define MSG_SSID_7			4600
#define MSG_SSID_7_LAST			4611
#define MSG_SSID_8			5000
#define MSG_SSID_8_LAST			5024
#define MSG_SSID_9			5500
#define MSG_SSID_9_LAST			5514
#define MSG_SSID_10			6000
#define MSG_SSID_10_LAST		6050
#define MSG_SSID_11			6500
#define MSG_SSID_11_LAST		6521
#define MSG_SSID_12			7000
#define MSG_SSID_12_LAST		7003
#define MSG_SSID_13			7100
#define MSG_SSID_13_LAST		7111
#define MSG_SSID_14			7200
#define MSG_SSID_14_LAST		7201
#define MSG_SSID_15			8000
#define MSG_SSID_15_LAST		8000
#define MSG_SSID_16			8500
#define MSG_SSID_16_LAST		8523
#define MSG_SSID_17			9000
#define MSG_SSID_17_LAST		9008
#define MSG_SSID_18			9500
#define MSG_SSID_18_LAST		9509

struct bindpkt_params {
	uint16_t cmd_code;
	uint16_t subsys_id;
	uint16_t cmd_code_lo;
	uint16_t cmd_code_hi;
	uint16_t proc_id;
	uint32_t event_id;
	uint32_t log_code;
	uint32_t client_id;
};

struct bindpkt_params_per_process {
	/* Name of the synchronization object associated with this process */
	char sync_obj_name[MAX_SYNC_OBJ_NAME_SIZE];
	uint32_t count;	/* Number of entries in this bind */
	struct bindpkt_params *params; /* first bind params */
};

struct diagpkt_delay_params {
	void *rsp_ptr;
	int size;
	int *num_bytes_ptr;
};

static const uint32_t msg_bld_masks_0[] = {
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_ERROR,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_ERROR,
	MSG_LVL_LOW,
	MSG_LVL_ERROR,
	MSG_LVL_ERROR,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_ERROR,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED|MSG_MASK_7 | \
		MSG_MASK_8|MSG_MASK_9|MSG_MASK_10|MSG_MASK_11|MSG_MASK_12 | \
		MSG_MASK_13|MSG_MASK_14|MSG_MASK_15|MSG_MASK_16 | \
		MSG_MASK_17|MSG_MASK_18|MSG_MASK_19|MSG_MASK_20|MSG_MASK_21,
	MSG_LVL_MED|MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8|MSG_MASK_9|MSG_MASK_10| \
		MSG_MASK_11|MSG_MASK_12|MSG_MASK_13|MSG_MASK_14| \
		MSG_MASK_15|MSG_MASK_16|MSG_MASK_17,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED|MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_MED,
	MSG_LVL_MED|MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8|MSG_MASK_9|MSG_MASK_10| \
		MSG_MASK_11|MSG_MASK_12|MSG_MASK_13|MSG_MASK_14|MSG_MASK_15| \
		MSG_MASK_16|MSG_MASK_17|MSG_MASK_18|MSG_MASK_19|MSG_MASK_20| \
		MSG_MASK_21|MSG_MASK_22|MSG_MASK_23|MSG_MASK_24|MSG_MASK_25,
	MSG_LVL_MED|MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8|MSG_MASK_9|MSG_MASK_10,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW | MSG_MASK_5 | \
		MSG_MASK_6 | MSG_MASK_7 | MSG_MASK_8,
	MSG_LVL_LOW | MSG_MASK_5 | \
		MSG_MASK_6,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_MED | MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8|MSG_MASK_9|MSG_MASK_10| \
		MSG_MASK_11|MSG_MASK_12|MSG_MASK_13|MSG_MASK_14|MSG_MASK_15 | \
		MSG_MASK_16|MSG_MASK_17|MSG_MASK_18|MSG_MASK_19|MSG_MASK_20,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
};

static const uint32_t msg_bld_masks_1[] = {
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
};

static const uint32_t msg_bld_masks_2[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED,
	MSG_LVL_MED
};

static const uint32_t msg_bld_masks_3[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED
};

static const uint32_t msg_bld_masks_4[] = {
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH
};

static const uint32_t msg_bld_masks_5[] = {
	MSG_LVL_HIGH,
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED
};

static const uint32_t msg_bld_masks_6[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW
};

static const uint32_t msg_bld_masks_7[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
};

static const uint32_t msg_bld_masks_8[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
};

static const uint32_t msg_bld_masks_9[] = {
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
};

static const uint32_t msg_bld_masks_10[] =  {
	MSG_LVL_MED,
	MSG_LVL_ERROR,
	MSG_LVL_LOW,
	MSG_LVL_LOW|MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8|MSG_MASK_9|MSG_MASK_10| \
		MSG_MASK_11|MSG_MASK_12|MSG_MASK_13|MSG_MASK_14|MSG_MASK_15| \
		MSG_MASK_16|MSG_MASK_17|MSG_MASK_18|MSG_MASK_19|MSG_MASK_20| \
		MSG_MASK_21|MSG_MASK_22,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_0 | MSG_MASK_1 | MSG_MASK_2 | \
		MSG_MASK_3 | MSG_MASK_4 | MSG_MASK_5 | MSG_MASK_6,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
};

static const uint32_t msg_bld_masks_11[] = {
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
};

static const uint32_t msg_bld_masks_12[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
};

static const uint32_t msg_bld_masks_13[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
};

static const uint32_t msg_bld_masks_14[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
};

static const uint32_t msg_bld_masks_15[] = {
	MSG_LVL_MED
};

static const uint32_t msg_bld_masks_16[] = {
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
};

static const uint32_t msg_bld_masks_17[] =  {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED | MSG_MASK_6 | \
		MSG_MASK_7 | MSG_MASK_8 | MSG_MASK_9,
	MSG_LVL_MED | MSG_MASK_5 | \
		MSG_MASK_6 | MSG_MASK_7 | MSG_MASK_8 | MSG_MASK_9 | \
		MSG_MASK_10 | MSG_MASK_11 | MSG_MASK_12 | MSG_MASK_13 | \
		MSG_MASK_14 | MSG_MASK_15 | MSG_MASK_16 | MSG_MASK_17,
	MSG_LVL_MED,
	MSG_LVL_MED | MSG_MASK_5 | \
		MSG_MASK_6 | MSG_MASK_7 | MSG_MASK_8 | MSG_MASK_9 | \
		MSG_MASK_10 | MSG_MASK_11 | MSG_MASK_12 | MSG_MASK_13 | \
		MSG_MASK_14 | MSG_MASK_15 | MSG_MASK_16 | MSG_MASK_17 | \
		MSG_MASK_18 | MSG_MASK_19 | MSG_MASK_20 | MSG_MASK_21 | \
		MSG_MASK_22,
	MSG_LVL_MED,
	MSG_LVL_MED,
};

static const uint32_t msg_bld_masks_18[] = {
	MSG_LVL_LOW,
	MSG_LVL_LOW | MSG_MASK_8 | MSG_MASK_9 | MSG_MASK_10 | \
		MSG_MASK_11|MSG_MASK_12|MSG_MASK_13|MSG_MASK_14|MSG_MASK_15 | \
		MSG_MASK_16|MSG_MASK_17|MSG_MASK_18|MSG_MASK_19|MSG_MASK_20,
	MSG_LVL_LOW | MSG_MASK_5 | MSG_MASK_6,
	MSG_LVL_LOW | MSG_MASK_5,
	MSG_LVL_LOW | MSG_MASK_5 | MSG_MASK_6,
	MSG_LVL_LOW,
	MSG_LVL_LOW | MSG_MASK_5 | \
		MSG_MASK_6 | MSG_MASK_7 | MSG_MASK_8 | MSG_MASK_9,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW
};
// +++ EricCHWang, SD card download
struct diagpkt_ioctl_param
{
		uint8_t * pPacket;
		uint16_t Len;
};

#define DL_FILENAME_LEN 32
typedef struct dl_list
{
  uint32_t MAGIC_NUM;
  uint32_t iFLAG;// update flag, flag in mlf
  uint32_t  dl_flag;              /*bit 0 (1)be set-> dont' switch to backup even EFS parti diff*/
                                     /*bit 1 (2)be set-> combined image mode*/
                                     /*bit 2 (4)be set-> need backup and restore NV*/
                                     /*bit 3 (8)be set-> multi port download*/
                                    /*bit 4 (16)be set-> combined image multi port download*/
  char pCOMBINED_IMAGE[DL_FILENAME_LEN];
  int  aARMPRG_BIN[2];         /*[0]->image start address in combined file NPRG_BIN offset size [1]->image size */
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
  uint32_t checksum;
}FirmwareList;
// --- EricCHWang, SD card download
/* LOG CODES */

#define LOG_0	0x0
#define LOG_1	0x1520
#define LOG_2	0x0
#define LOG_3	0x0
#define LOG_4	0x4910
#define LOG_5	0x5420
#define LOG_6	0x0
#define LOG_7	0x74FF
#define LOG_8	0x0
#define LOG_9	0x0
#define LOG_10	0xA38A
#define LOG_11	0xB201
#define LOG_12	0x0
#define LOG_13	0x0
#define LOG_14	0x0
#define LOG_15	0x0

#define LOG_GET_ITEM_NUM(xx_code) (xx_code & 0x0FFF)

#endif
