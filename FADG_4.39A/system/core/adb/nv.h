#ifndef NV_H_trimmed
#define NV_H_trimmed
/*=============================================================================
  @file  nv.h

  ---------------------------------------------------------------------------
  Copyright (c) 2010 QUALCOMM Incorporated. 
  All Rights Reserved. QUALCOMM Proprietary and Confidential.
  ---------------------------------------------------------------------------

  $Id: //depot/asic/msm7x27/android_froyo/7.0/MODEM_APIS/libs/remote_apis/nv/inc/nv.h#22 $

  Notes: 
     ==== Auto-Generated File, do not edit manually ====
     Generated from build type: TFNCKNLGH 
     #defines containing FNCKNLGH replaced with ________
=============================================================================*/
#ifndef NV_H
#define NV_H
/*==========================================================================

         N V    T A S K    P U B L I C    H E A D E R    F I L E

DESCRIPTION

  This header file contains all the definitions necessary for any task
  to interface with the Non Volatile Memory task, in order to access
  the NV items in EFS to read, write, and start.

Copyright (c) 2005-2009 by QUALCOMM, Incorporated.
All Rights Reserved.
Qualcomm Confidential and Proprietary

===========================================================================*/

#ifndef TARGET_H
#define TARGET_H
/*===========================================================================

      T A R G E T   C O N F I G U R A T I O N   H E A D E R   F I L E

DESCRIPTION
  All the declarations and definitions necessary for general configuration
  of the DMSS software for a given target environment.

Copyright (c) 1998,1999,2000,2001,2002  by QUALCOMM, Inc.  All Rights Reserved.
===========================================================================*/


/* All featurization starts from customer.h which includes the appropriate
**    cust*.h and targ*.h
*/
#ifdef CUST_H
#ifndef CUSTOMER_H
#define CUSTOMER_H
/*===========================================================================

                   C U S T O M E R    H E A D E R    F I L E

DESCRIPTION
  This header file provides customer specific information for the current
  build.  It expects the compile time switch /DCUST_H=CUSTxxxx.H.  CUST_H
  indicates which customer file is to be used during the current build.
  Note that cust_all.h contains a list of ALL the option currently available.
  The individual CUSTxxxx.H files define which options a particular customer
  has requested.


Copyright (c) 1996, 1997       by QUALCOMM Incorporated.  All Rights Reserved.
Copyright (c) 1998, 1999, 2000 by QUALCOMM Incorporated.  All Rights Reserved.
Copyright (c) 2001, 2002       by QUALCOMM Incorporated.  All Rights Reserved.
===========================================================================*/


/* Make sure that CUST_H is defined and then include whatever file it
** specifies.
*/
#ifdef CUST_H
#ifndef CUSTT_________H
#define CUSTT_________H
/* ========================================================================
FILE: CUSTT________

Copyright (c) 2001-2010 by QUALCOMM Incorporated.  All Rights Reserved.        
=========================================================================== */

#ifndef TARGT_________H
#ifndef TARGT_________H
#define TARGT_________H
/* ========================================================================
FILE: TARGT________

Copyright (c) 2001-2010 by QUALCOMM Incorporated.  All Rights Reserved.        
=========================================================================== */


#define FEATURE_KARURA 
#define T_MSM6800 
#define T_MSM7500 
#define T_MSM6500 
#define FEATURE_BUILD_CDMA_CELL_PCS 
#define FEATURE_BUILD_CDMA_CELL_PCS 
#define FEATURE_BUILD_CDMA_CELL_PCS 


#endif /* TARGT_________H */
#endif

#define FEATURE_GSM 
#define FEATURE_WCDMA 
#define FEATURE_GWSMS 
#define FEATURE_CDMA 
#define FEATURE_CDMA1X 
#define FEATURE_DUAL_SIM 
#define FEATURE_DATA_1H08_4_DUAL_PROC 
#define FEATURE_DS 
#define FEATURE_HDR 
#define FEATURE_CDSMS 
#define FEATURE_RUIM 
#define FEATURE_AUTH 
#define FEATURE_HSDPA_ACCESS_STRATUM 
#define FEATURE_WCDMA 
#define FEATURE_GWSMS 
#define FEATURE_CGPS_USES_UMTS 
#define FEATURE_CGPS 
#define FEATURE_ESTK 
#define FEATURE_ERR_EXTENDED_STORE 
#define FEATURE_AUDIO_CONFIGURATION_VALUE_ADD 
#define FEATURE_MULTIPROCESSOR 
#define FEATURE_VOC_4GV 
#define FEATURE_MMGSDI_NO_TCB_PTR_OR_CRIT_SEC 
#define FEATURE_HS_USB 
#define FEATURE_L4 
#ifndef CUSTCDMA2000_H
#define CUSTCDMA2000_H
/*===========================================================================

            " C D M A 2 0 0 0 "   H E A D E R   F I L E

DESCRIPTION
  Configuration for IS-856 support on MSM6800 targets.

  Copyright (c) 2001, 2002, 2003
                2004, 2005, 2006 by QUALCOMM Incorporated. All Rights Reserved.
===========================================================================*/

#define FEATURE_BUILD_CDMA_TRIMODE 

/* FEATURE_CDMA feature should be defined only in C2k 
 * and multimode (UMTS + CDMA) builds. 
 * support for IS-95/IS2000/1X Data Services   */
#define FEATURE_CDMA

#endif /* CUSTCDMA2000_H */
#ifndef CUSTCDMA_H
#define CUSTCDMA_H
/*===========================================================================

DESCRIPTION
  Configuration for CDMA and AMPS Operation

  Copyright (c) 2002,2003  by QUALCOMM Incorporated. All Rights Reserved.
===========================================================================*/


/* -----------------------------------------------------------------------
** Top Level CDMA Call Processing Mode Feature Selection
** ----------------------------------------------------------------------- */
#if (defined (FEATURE_BUILD_CDMA_CELL) && !defined (FEATURE_BUILD_JCDMA))
#elif defined FEATURE_BUILD_CDMA_CELL_AMPS
#elif (defined (FEATURE_BUILD_JCDMA) && !defined (FEATURE_BUILD_CDMA_PCS))
#elif (defined (FEATURE_BUILD_CDMA_PCS) && !defined (FEATURE_BUILD_JCDMA))
#elif (defined (FEATURE_BUILD_CDMA_PCS) && defined (FEATURE_BUILD_JCDMA))
#elif defined FEATURE_BUILD_CDMA_TRIMODE

   /* Supports CDMA at 800  MHz
   **          CDMA at 1900 Mhz
   **          AMPS
   */
   #define FEATURE_CDMA_800
   #define FEATURE_CDMA_1900
   /* Enable Analog Call Processing.
   */
#ifndef T_MSM6500
   #define FEATURE_ACP
#endif
   
#elif defined FEATURE_BUILD_CDMA_CELL_PCS
#else
#endif


/* -----------------------------------------------------------------------
** IS-95B
** ----------------------------------------------------------------------- */
#define FEATURE_IS95B

#ifdef FEATURE_IS95B
  /*---------------------------------------*/
  /* Enable the individual IS-95B features */
  /*---------------------------------------*/

  /* IS95B compliant version of Calling NAme Presentation (CNAP)
  ** This is included only if FEATURE_IS95B is included
  */
  #define FEATURE_IS95B_EXT_DISP

  /* IS95B compliant version of Network Directed System Selection (NDSS)
  ** This is included only if FEATURE_IS95B is included
  */
  #define FEATURE_IS95B_NDSS

  /* IS95B compliant version of the Alert Answer Bypass Feature
  ** This is included only if FEATURE_IS95B is included
  */
  #define FEATURE_IS95B_ALERT_ANS_BYPASS

  /*-----------------------------------------------------------*/
  /* Enable the individual IS-95B Protocol Revision 5 features */
  /* These are optional for Revsion 4                          */
  /*-----------------------------------------------------------*/

  /*-----------------------------------------------------------*/
  /* End of IS-95B Feature Definitions                         */
  /*-----------------------------------------------------------*/

#endif /* FEATURE_IS95B */

/* -----------------------------------------------------------------------
** IS-2000
** ----------------------------------------------------------------------- */
#define FEATURE_IS2000

/* The following 4 features are Authentication features */
#define FEATURE_AUTH

#endif /* CUSTCDMA_H */
#ifndef CUSTMODEMDATA_H
#define CUSTMODEMDATA_H
/*===========================================================================

DESCRIPTION
  Configuration for NVM.

Copyright (c) 2002 - 2010 QUALCOMM Incorporated.
All Rights Reserved.
Qualcomm Confidential and Proprietary.
===========================================================================*/


/*===========================================================================

                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

$Header: //depot/asic/msm7x27/android_froyo/7.0/MODEM_APIS/libs/remote_apis/nv/inc/nv.h#22 $
$DateTime: 2010/10/20 10:24:59 $ $Author: abickett $

when       who     what, where, why
--------   ---     ------------------------------------------------------------
10/07/10   msr     SMI integration for 7x27 BMP 2.0
07/07/10   pg      Moved DS Profile feature set to custdatacommon.h.
06/23/10   ms      Added FEATURE_DATA_REFRESH_VOTING
02/04/10   ss      Enable FEATURE_DATA_MODEM_HEAP if FEATURE_MODEM_HEAP is
                   defined.
05/22/09   nc      Defining __NON_DEMAND_PAGED_FUNCTION__ to NULL
                   for Non-LCU builds.
04/20/09   sa      Enable FEATURE_DSAT_FWD_CMDS for Linux and Winmobile
                   multiprocessor targets.
04/14/08   hs      Created new file for multimode targets
===========================================================================*/
/* -----------------------------------------------------------------------
** Data Services
** ----------------------------------------------------------------------- */
#define FEATURE_DS

#if defined(FEATURE_GSM_GPRS) || defined(FEATURE_WCDMA)
#ifndef CUSTDATAUMTS_H
#define CUSTDATAUMTS_H

/*===========================================================================

DESCRIPTION
  Configuration for NVM.

  Copyright (c) 2002 - 2010  by QUALCOMM Incorporated. All Rights Reserved.
===========================================================================*/


#if (!defined(FEATURE_DATA_ON_APPS) && defined(IMAGE_MODEM_PROC))
  /* Enable UCSD API for VT calls (WindowsCE builds)
  */
  #define FEATURE_DATA_UCSD_SCUDIF_API
#endif

#ifdef FEATURE_DATA_1H08_4_DUAL_PROC
  #define FEATURE_DATA_UCSD_SCUDIF_API
#endif


/*  Enable UCSD API SIO port notificaiton */
#define FEATURE_DATA_UCSD_API_SIOPORT

#define FEATURE_SECONDARY_PDP

#endif /* CUSTDATAUMTS_H */
#endif /* FEATURE_GSM_GPRS || FEATURE_WCDMA*/

#ifdef FEATURE_CDMA
#ifndef CUSTDATAC2K_H
#define CUSTDATAC2K_H

/*===========================================================================

DESCRIPTION
  Configuration for NVM.

  Copyright (c) 2002 - 2010  by QUALCOMM Incorporated. All Rights Reserved.
===========================================================================*/


/*===========================================================================

                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

$Header: //depot/asic/msm7x27/android_froyo/7.0/MODEM_APIS/libs/remote_apis/nv/inc/nv.h#22 $
$DateTime: 2010/10/20 10:24:59 $ $Author: abickett $

when       who     what, where, why
--------   ---     ------------------------------------------------------------
10/07/10   msr     SMI integration for 7x27 BMP 2.0
05/19/10   ssh     FEATURE_DATA_PS_PAP_INTERNAL_AUTH
05/06/10   pg      Added FEATURE_IS707B_ADDENDUM.
03/24/10   pt      Feature wrapping "FEATURE_HDR_AT_TEST_ONLY" under
                   "FEATURE_INTERNAL_USE_BUILDS_ONLY".
03/11/10   sn      Enabled FEATURE_DATA_DISABLE_IS95B_MDR to disable MDR SOs.
03/11/10   pt      Enabled "FEATURE_CDMA_SMS" and "FEATURE_DSAT_CDMA_PBM".
09/09/08   sn      Removed dependency on FEATURE_UIM_3GPD_MULTIPLE_SIP_PROFILES
                   in enabling OMH feature.
08/05/08   hs      Included FEATURE_OMH. Made MIP Feature changes.
07/14/08   psng    Added FEATURE_DS_OMH for multiple profiles functionality.
03/06/08   mga     Enabled FEATURE_DS_LN_UPDATE
09/28/07   as      Switched on FEATURE_DATA_MOBILE_IP_DMU_MODIFIES_AN_AUTH
08/21/07   wsh     Retired EATURE_C2K_INTERNAL_USE_ONLY flag in 1H07 branch
08/09/07   wli     added support for FEATURE_DADA_ON_APPS
08/03/07   pm      updated to use FEATURE_INTERNAL_USE_FFABUILDS_ONLY
05/23/07   dnn     Mainlined FEATURE_HDR_QOS_DQOS_SUPPORTED_ALWAYS
05/23/07   ssr     Adding GSM custdata.h under FEATURE_GSM_GPRS
05/17/07   ssr     Adding GSM / GPRS fearure sets to enable combined 1x/GSM PLF
04/17/07   ac      Turn off certain features when VoIP is off
11/14/06   vrk/gr  turning off RDUD, CAM, DCTM for JCDMA builds
11/15/06   vas     Added FEATURE_C2K_INTERNAL_USE_ONLY related features
05/23/06   vrk     enable FEATURE_DATA_SERIALIZER for 6800 5.0
12/13/05   vrk     enable FEATURE_CALL_THROTTLE (DCTM) and move RSVP Featurization
10/17/05   vrk     disable FEATURE_DS_QNC in JCDMA builds and modified comments
04/05/05   gr      Integrated EPZID functionality onto the main line
02/28/05   ks      Enabled FEATURE_DATA_PS_DATA_LOGGING for Data Protocol
                   Logging.
02/25/05   kvd     Removed FEATURE_DS_MOBILE_IP_MULTIPLE_NAI as the feature is
                   now appicable to SIP calls also and is covered by
                   FEATURE_DS_MULTIPLE_NAI.
02/15/05   kvd     Added FEATURE_DS_MULTIPLE_NAI.
02/03/05   kvd     Added FEATURE_DS_MOBILE_IP_MULTIPLE_NAI.
11/11/02   cah     Added GSM features.
05/01/02   jct     Created
===========================================================================*/



#ifdef FEATURE_DS

   /* Support for IS-95/IS2000/1X Data Services.   */
   #define FEATURE_CDMA

#endif /* FEATURE_DS */

#endif /* CUSTDATAC2K_H */
#endif /*FEATURE_CDMA*/


#endif /* CUSTMODEMDATA_H */
#ifndef CUSTHDR_H
#define CUSTHDR_H
/*===========================================================================

            " M S M 6 8 0 0 -  S U R F "   H E A D E R   F I L E

DESCRIPTION
  Configuration for IS-856 support on MSM6800 targets.

  Copyright (c) 2001-2010 by QUALCOMM Incorporated. All Rights Reserved.
===========================================================================*/


/* HDR Air Interface support.
*/
#define FEATURE_HDR

/* HDR-1X handoff */
#define FEATURE_HDR_HANDOFF 

/* Hybrid operation
*/
#define FEATURE_HDR_HYBRID

/* Data Dedicated Transmission mode 
   to minimize the hyrbid HDR data call interruption 
*/ 
#define FEATURE_DDTM_CNTL

/* HDR Broadcast related features */
#define FEATURE_BCMCS

#ifdef FEATURE_BCMCS
/* BCMCS 1.X features */
#define FEATURE_HDR_BCMCS

#ifndef FEATURE_KARURA
/* BCMCS 2.X features */
#define FEATURE_BCMCS_20
#endif

#endif /* FEATURE_HDR_BCMCS */

#if defined(T_MSM6800) && !defined(T_MSM7500)
/* Feature for Enhanced Multi-flow Packet Application. Turn on only for 6800 */
#define FEATURE_HDR_EMPA
#endif

#endif /* CUSTHDR_H */

#ifndef CUSTUIM_H
  #define CUSTUIM_H
  /*===========================================================================

              " C u s t -  U I M "   H E A D E R   F I L E

  DESCRIPTION
  Configuration for UIM Feature.

  Copyright (c) 2008-2010 by QUALCOMM Incorporated. All Rights Reserved.
  ===========================================================================*/
  /*===========================================================================

                        EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //depot/asic/msm7x27/android_froyo/7.0/MODEM_APIS/libs/remote_apis/nv/inc/nv.h#22 $ $DateTime: 2010/10/20 10:24:59 $ $Author: abickett $

  when       who     what, where, why
  --------   ---     ----------------------------------------------------------
  08/18/10   tkl     Updated for FEATURE_ESTK_UI_NO_ICON_SUPPORT
  07/30/10   yt      Changes for BMP simulation
  07/29/10   ms      Removed featurization of TEST_FRAMEWORK on 
                     FEATURE_UIM_WIM feature
  07/26/10   ssr     Enabled FEATURE_UIM_SUPPORT_3GPD_NV  
  07/20/10   rm      Enable FEATURE_UIM_ALLOW_WRITE_TO_XML feature in test
                     framework
  07/19/10   kk      Moved QMI UIM feature to 7x27 hw cust file
  07/16/10   nmb     Enabled FEATURE_MMGSDI_ABSENT_MANDATORY_FILES_INIT
  07/15/10   nmb     Added FEATURE_MMGSDI_ABSENT_MANDATORY_FILES_INIT
  07/15/10   ssr     Enable FEATURE_UIM_MISCONFIG_RUIM_N5_WORKAROUND  
  07/12/10   adp     Feature Clean up  
  06/28/10   adp     Adding support for MOB related features and enabling 
                     GW/MM/1X  technologies in the off-target.
  05/24/10   nmb     Enabled FEATURE_PERSO_RUIM and FEATURE_PERSO_SIM
  03/12/10   dd      Enable FEATURE_CCAT
  03/02/10   vs      Added relevant 1x features
  02/04/10   vs      Promoted FEATURE_CSIM to build file level
  02/02/10   xz      Enable ESTK sub-features for DS/DS
  01/25/10   vs      Updates for CSIM and session lib support
  01/12/10   kk      Enable support for streaming APDUs at UIM server
  12/08/09   xz      Enabled DS/DS GSTK support
  11/16/09   kk      Enabled FEATURE_MMGSDI_SESSION_LIB
  10/08/09   dd      Enable raw messages in Symbian targets
  09/30/09   ps      Missed to undef FEATURE_UIM2 when adding DUAL_SIM
  09/30/09   ps      Support for feature FEATURE_DUAL_SIM
  06/24/09   kp      Moving FEATURE_UIM_ZI_MEMORY_REDUCTION under
                     FEATURE_MODEM_HEAP
  06/18/09   kp      changes upmerged from 07H1_2
  05/22/09   dd      Enable FEATURE_CAT_REL6 for all targets
  06/09/09   ps      Moved UIM/RUIM features from msm76xx.builds to cust file
  06/05/09   adp     Define UIM MFLO features conditionally based on feature
                     FEATURE_MFLO_OPENCA
  05/27/09   adp     Enable FEATURE_UIM_WIM.
  05/20/09   ssr     Fixed FEATURE_RUIM for multimode support.
  05/12/09   yk      Enabled RUIM specific features
  04/15/09   xz      Add feature dependency check for FEATURE_ESTK
  06/01/09   kp      Defined FEATURE_UIM_ZI_MEMORY_REDUCTION
  03/25/09   nk      Defined FEATURE_UIM_USES_NEW_SLEEP_API
  03/19/09   rm      Platform specific cust file inclusions
  02/17/09   yb      Added FEATURE_GSTK_TEST_AUTOMATION
  02/12/09   nd      Fixed linker error when FEATURE_VIRTUAL_SIM is defined
  02/04/09   nk      Reverted PERSO SFS enablement
  01/26/09   jar     Enabled PERSO SFS when using a Secure Partition
  01/14/09   yk      Removed FEATURE_UIM_PMIC_ON_UIM1 which is a target
                     specific feature
  01/12/09   ssr     MMGSDI RTRE Configuration initialization
  01/09/09   nk      Updated MBMS and Perso Featurization
  01/07/09   sk      Added FEATURE_GSTK_ENH_MULTI_CLIENT_SUPPORT and
                     related support for ESTK and gstk streaming apdu.
  11/25/08   nk      Updated with RUIM support
  11/17/08   as/nk   Initial Revision.
  ===========================================================================*/
  /*---------------------------------------------------------------------------
                              Task Related Defines
  ---------------------------------------------------------------------------*/

  #define FEATURE_MMGSDI

#ifndef BMP_MOB_SIMULATION
  /* USAT support*/
  #define FEATURE_GSTK
#endif //BMP_MOB_SIMULATION
  /* Adds support for the basic toolkit features */

  /*---------------------------------------------------------------------------
                              ALWAYS DEFINED
  ---------------------------------------------------------------------------*/
  #define FEATURE_UIM_UICC

#if defined(FEATURE_UIM_TEST_FRAMEWORK) || defined(BMP_MOB_SIMULATION)
  /* Enable Dual SIM for TEST_FRAMEWORK/BMP_MOB_SIMULATION */
  #define FEATURE_DUAL_SIM
#endif /* FEATURE_UIM_TEST_FRAMEWORK || BMP_MOB_SIMULATION */

  #ifdef FEATURE_DUAL_SIM
    /* Support for UIM2 */
    /* Support for Dual Slots in UIMDRV */
    #define FEATURE_UIM_SUPPORT_DUAL_SLOTS
  #endif /* FEATURE_DUAL_SIM */

  /*-------------------------------------------------------------------------*/
  /*                              UMTS specific                              */
  /*-------------------------------------------------------------------------*/
  #ifdef FEATURE_WCDMA
    #define FEATURE_MMGSDI_UMTS
    /* Enables support for the USIM-specific UIM commands and responses. */
  #endif /* FEATURE_WCDMA */

  #ifdef FEATURE_UIM_UICC
    /* Feature for performing terminal profile before USIM activation */
    /* Features for 1000 PBM */
    #define FEATURE_USIM_1000_PBM
    /* MBMS Support */
  #endif /* FEATURE_UIM_UICC */

  /*---------------------------------------------------------------------------
                         GSM SIM support
  ---------------------------------------------------------------------------*/
  #ifdef FEATURE_GSM
    /* The feature enables support for GSM specific UIM commands and responses.*/
    #define FEATURE_MMGSDI_GSM
  #endif /* FEATURE_GSM */


  #if defined (FEATURE_CDMA)
    #define FEATURE_RUIM
  #endif /* FEATURE_CDMA */
  /*---------------------------------------------------------------------------
                         CDMA RUIM support
  ---------------------------------------------------------------------------*/

  /*---------------------------------------------------------------------------
                         Either GSM or UMTS Support
  ---------------------------------------------------------------------------*/
  #if defined ( FEATURE_MMGSDI_GSM) || defined (FEATURE_MMGSDI_UMTS)
    /* PKCS 15 */
    /* Feature for dual processor build to prevent these members from being accessed */
    #define FEATURE_MMGSDI_NO_TCB_PTR_OR_CRIT_SEC
  #endif

  /*---------------------------------------------------------------------------
                                  MMGSDI
  ---------------------------------------------------------------------------*/
  /* MMGSDI Task support */
  #ifdef FEATURE_MMGSDI
    /* Enable the GSDI - DIAG Interface for Test Autoamtion */
    /* Enable the GSDI/MMGSDI Interface to provide Detailed Error Events */
    #define FEATURE_MMGSDI_CARD_ERROR_INFO
    /* Enable the support Factory Test Mode Software SIM */

    /* PERSONALIZATION Features*/
    /* Support SIM Lock Features */
    #define FEATURE_MMGSDI_PERSONALIZATION
    /* Switch to New SIM Lock Architecture */
    #define FEATURE_MMGSDI_PERSONALIZATION_ENGINE
    /* Feature to use tmc small heap when applicable*/

    #if defined (FEATURE_MMGSDI_PERSONALIZATION_ENGINE)
      #if defined (FEATURE_MMGSDI_GSM) || defined (FEATURE_MMGSDI_UMTS)
        /*SIM Lock for GSM/UMTS only*/
        #define FEATURE_PERSO_SIM
    #endif /* FEATURE_MMGSDI_GSM || FEATURE_MMGSDI_UMTS */
    #endif /* FEATURE_MMGSDI_PERSONALIZATION_ENGINE */


  #endif /* FEATURE_MMGSDI */

  /*---------------------------------------------------------------------------
                     GENERIC SIM DRIVER INTERFACE (GSDI)
  ---------------------------------------------------------------------------*/

  #ifdef FEATURE_GSTK
    /* number of GSTK instances */
     /* Feature to use tmc_small_heap for gstk */
    #define FEATURE_GSTK_USE_SMALL_HEAP
    /* Support for Send SS - Call Fwd Unconditional */
    /* Feature CAT REL6 */
    #define FEATURE_CAT_REL6

  #endif /* FEATURE_GSTK */


  /*---------------------------------------------------------------------------
                             NV access in RUIM
  ---------------------------------------------------------------------------*/
  #if defined(FEATURE_CDMA) && defined(FEATURE_RUIM)
    /* Enable the feature to include guard band channels as valid channels */
    #ifndef FEATURE_NO_CELL_GUARD_BANDS
      #define FEATURE_NO_CELL_GUARD_BANDS
    #endif
    /* Feature for Perso RUIM support */
    #if defined (FEATURE_MMGSDI_PERSONALIZATION)
      #define FEATURE_PERSO_RUIM
    #endif /* FEATURE_MMGSDI_PERSONALIZATION */
    /* CDMA Application Tool kit */
  #endif /* defined(FEATURE_CDMA) && defined(FEATURE_RUIM) */


  /* R-UIM Support*/
  #if defined(FEATURE_RUIM)
    /* R-UIM Support from the UIM server */
    #define FEATURE_UIM_RUIM
    /* R-UIM run time enable support by other modules */
    #define FEATURE_UIM_RUN_TIME_ENABLE
    /* PrefMode is read from NV rather than the RUIM card. */

  #endif /* FEATURE_RUIM */

#endif /* CUSTUIM_H */
#ifndef CUSTWCDMA_H
#define CUSTWCDMA_H
/*=========================================================================== 

                           C U S T    W C D M A 

DESCRIPTION
  Customer file for WCDMA

  Copyright (c) 2002-2008 by QUALCOMM Incorporated. All Rights Reserved.
===========================================================================*/


/* BMC Feature */       
#define FEATURE_UMTS_BMC

#ifdef FEATURE_HSDPA_ACCESS_STRATUM
  #define FEATURE_REL5
  /* Make CQI estimation less pessimistic */
#endif


#endif /* CUSTWCDMA_H */
#ifndef CUSTUSURF_H
#define CUSTUSURF_H
/*=========================================================================== 

                           C U S T U S U R F

DESCRIPTION
  Customer file for the MSM6280 UMTS (GSM + WCDMA) SURF build.

  Copyright (c) 1996-2002 by QUALCOMM Incorporated. All Rights Reserved.
===========================================================================*/


#if defined(FEATURE_WCDMA) && defined(FEATURE_GSM)

// --- WCDMA ---
/* Enable WCDMA code
*/
#define FEATURE_WCDMA

#endif /* FEATURE_WCDMA && FEATURE_GSM */

// ---  GSM  ---
/* Enable GSM code
*/
#define FEATURE_GSM

/* Enable MM GSDI
*/
#define FEATURE_MMGSDI 
#define FEATURE_MMGSDI_GSM 
#define FEATURE_MMGSDI_UMTS


/* USAT support
*/
#define FEATURE_GSTK
#define FEATURE_ALS

/* Support for Multiple PDP contexts */
#define FEATURE_MULTIPLE_PRIMARY_PDP

#define FEATURE_UUS

#define FEATURE_CCBS

//David - added to make FTM audio compile
#define FEATURE_VOC_PCM_INTERFACE

/*#define FEATURE_LSM_PCH_REPORTING*/
#define FEATURE_NAS_REL7


#endif /* CUSTUSURF_H */


/*****************************************************************************/
#ifndef CUSTGSM_H
#define CUSTGSM_H
/*===========================================================================

                           C U S T G S M

DESCRIPTION
  Customer file for GSM.

  Copyright (c) 2002-2010 by QUALCOMM Incorporated. All Rights Reserved.
===========================================================================*/


/*===========================================================================

                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

$Header: //depot/asic/msm7x27/android_froyo/7.0/MODEM_APIS/libs/remote_apis/nv/inc/nv.h#22 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
14/07/10    sjw    Enabled FEATURE_GSM_PCH_SINGLE_BURST_DEC for all Dual SIM targets
22/06/10    sjw    Enabled FEATURE_GSM_GPRS_ENH_SNR_RESEL for all targets using this branch
16/06/10    hvan   Enabled FEATURE_GSM_L2_RANDOM_PADDING for Chetak
16/03/10    cgc    Removed LIST_SEARCH_IN_PAGING_BLOCK for Mustang as it causes PCH decode errors.
02/02/10    rn     Added FEATURE_GSM_RR_CELL_CALLBACK for all targets, move away from custusurf.h target specific featurisation.
01/18/10    ps     Added FEATURE_GSM_GPRS_AGC_UPDATE for all targets
09/25/09    rc     Removed FEATURE_GERAN_STORED_LIST_CELL_SELECTION as the RR_ACQ_DB feature covers the functionality
09/22/09    rc     Added FEATURE_GSM_EGPRS_IR_OPT
08/12/08    rc     Added 3G Rove in feature def within FEATURE_GAN
06/10/08    rc     Added FEATURE_BPLMN_SEARCH_PRIORITY for GOBI-2000 - Fix for CR:152804
02/10/08    ps	   Enable AMR-WB for LCU
18/09/08    rc     Removed FEATURE_USB_WITH_ARM_HALT, Enabled FEATURE_GAN dependent features & FEATURE_LAPDM_REESTABLISHMENT
04/09/08    rc     Enabled FEATURE_GSM_RGS_MULTIPASS
01/09/08    rc     Enable R-SACCH for LCU
04/08/08    rc     Disable AMR-WB and R-SACCH feature in LCU for now.
08/07/08    ws     Changes for raptor2 Target, Disable AMR-WB and define FEATURE_GSM_8K_QDSP6_AUDIO
13/06/08    rc     Added 2H07 GERAN Feature AMR-WB
07/05/08    rc     Added 2H07 GERAN Features R-SACCH & PS HO
07/05/08    rc     Added FEATURE_GPRS_FAST_RACH
30/04/08    ws     Moved ESAIC feature to cutgsmdrv.h
30/04/08    ws     Enable ESAIC for LCU
06/02/08    ws     Added FEATURE_GSM_MDSP_ESAIC
05/02/08    ws     Added FEATURE_GSM_L1_IMPLEMENT_LPM
22/01/08    ws     Added T_QSC6270 specific featurisation
22/10/07    ws     Addede Enable ACQ database feature
14/09/07    rc     Added FEATURE_GPRS_COMP_ENUM_TYPES to re-use SNDCP VU that support IPHC with other layers that does not support IPHC
14/08/07    rc     Replaced FEATURE_GSM_SNDCP_IPHC_ROHC with FEATURE_GSM_SNDCP_IPHC
                   Added FEATURE_GSM_L1_OOS_SEARCH_TIME_ENH
09/07/07    rc     Removed FEATURE_CSN_REFACTORED
31/05/07    ws     Enabled FEATURE_GSM_L1_CONTROL_SET_BAND
16/04/07    npr    Enabled 2H06 features: EDTM, RFACCH, IPA, CSN
19/01/07    rc     Enabled FEATURE_GSM_GPRS_LLC_GEA_NV_SUPPORT
21/11/06    rc     Enabled FEATURE_GSM_L1_HFREQ_ERR_NCELL_SCH_DECODE
10/02/06    ws     Enabled DTM,EDA and PFC
09/06/05    ws     Removed FEATURE_GSM_DTM  since new build Id's use them
08/26/05    ws     Merged from Raven Branch features DISABLE_XFER_SNR_RESELECTION
                   and FEATURE_GPRS_GRR_GMM_PCCCH_PAGING_COORD
08/25/05    ws     Enabled FEATURE_GSM_DTM
06/23/05   src     Enabled FEATURE_GSM_GPRS_PEMR
05/24/05    gw     Enable WCDMA ID searches in transfer mode via
                   FEATURE_GTOW_RESELECTION_XFER_CELL_ID
04/24/05    bk     Temp disabled SNR based reselection in transfer via DISABLE_XFER_SNR_RESELECTION
11/19/04   gfr     Moved DEBUG_HW_SELECT_STAGE2_OUTPUT_CHANNEL_FILTER to
                   custgsmdrv.h
13/05/04   npr     Initial revision.
===========================================================================*/

#ifdef FEATURE_GSM

/***************************************************************************
                                 GSM
****************************************************************************/
#define FEATURE_GSM_EXT_SPEECH_PREF_LIST


/* Enable GPRS as Standard */
#define FEATURE_GSM_GPRS

#if (!defined(T_MSM8650B)) && (!defined(T_MDM8200)) && (!defined(FEATURE_WINNER1)) && (!defined(FEATURE_WYNN1))
/* Don't enable W-AMR on Raptor2 or Symbian for now */
#define FEATURE_GSM_AMR_WB
#endif


/*-------------------------------------------------------------------------*/
#endif /* FEATURE_GSM */
#endif /* CUSTGSM_H */

#ifndef CUSTCGPS_H
#define CUSTCGPS_H
/*===========================================================================

            " C u s t - C G P S "   H E A D E R   F I L E

DESCRIPTION
  Configuration for GPS Feature.

  Copyright (c) 2006 - 2010
                by QUALCOMM Incorporated. All Rights Reserved.

===========================================================================*/


/*---------------------------------------------------------------------------
                            gpsOne Features
---------------------------------------------------------------------------*/

#define FEATURE_CGPS

#ifdef FEATURE_CGPS

  #define FEATURE_GPSONE 

  #ifdef FEATURE_CGPS_USES_UMTS

    #define FEATURE_CM_LCS

  #endif  /* FEATURE_CGPS_USES_UMTS */

#endif /* FEATURE_CGPS */
#endif /* CUSTCGPS_H */
#ifndef CUSTMMODE_H
#define CUSTMMODE_H
/*========================================================================

DESCRIPTION

  Configuration CUST file for all of Multi Mode code

  Copyright (c) 2009  by QUALCOMM Incorporated. All Rights Reserved.
========================================================================*/


  /* Enable FEATURE_MM_SUPERSET for targets that use RPCs and thus
  ** need remote API files.
  ** This flag being on results in uniform remote API files for MMODE
  ** as even 1X-only targets will then pull in NAS files that CM uses in
  ** its API
  */
  #ifdef FEATURE_MULTIPROCESSOR
  #define FEATURE_MM_SUPERSET
  #endif


  /* Features that need to be defined on build to enable HDR meas */
  #ifdef FEATURE_IRAT_PILOT_MEAS
  #define FEATURE_CM_SS_MEAS
  #endif 


#endif /* CUSTMMODE_H */
#ifndef CUSTDRIVERS_H
#define CUSTDRIVERS_H
/*=========================================================================== 

                           C U S T D R I V E R S

DESCRIPTION
  Customer definition file for drivers.

  Copyright (c) 2006 by QUALCOMM Incorporated. All Rights Reserved.

===========================================================================*/


/* Enable F3 trace feature */
#if !defined(BOOT_LOADER) && !defined(BUILD_HOSTDL) && !defined(FEATURE_WINCE)
  #define FEATURE_SAVE_DEBUG_TRACE
  #define FEATURE_ERR_EXTENDED_STORE
#endif


#endif /* CUSTDRIVERS_H */
#ifndef CUSTAVS_H
#define CUSTAVS_H
/*===========================================================================

DESCRIPTION
  Configuration for AVS

  Copyright(c) 2002 - 2009 by QUALCOMM, Incorporated.
  All Rights Reserved. Qualcomm Proprietary and Confidential.
===========================================================================*/


/*===========================================================================

                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

$Header: //depot/asic/msm7x27/android_froyo/7.0/MODEM_APIS/libs/remote_apis/nv/inc/nv.h#22 $ $DateTime: 2010/10/20 10:24:59 $ $Author: abickett $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
11/17/09   sud     Enabled FEATURE_IIR_FILTER and FEATURE_IIR_FILTER_5S if
                   FEATURE_AVS_CRYSTAL_SPEECH is defined.
08/18/09   gs      Added feature FEATURE_DEVICE_WARMUP to remove pop on
                   speaker under standard configuration
07/09/09   lp      Removed feature guarding to QDSP_PACKET_SNIFFER,CR187596 fix.
07/06/09   ks      Fixed 7k compilation errors due to LCU demand paging changes.
04/14/09   sud     Removed feature FEATURE_VOC_4GV_WB from this file. Not a
                   supported feature for this target. This needs to be defined
                   in builds file if required in future.
                   Updated Copyright.
04/03/09   knm     Removing previously defined feature
04/03/09   knm     defined FEATURE_RIM_POP macro for RIM pop fix.
02/20/08    mk     Added feature FEATURE_VOC_4GV_WB  for 4GV-WB Vocoder.
06/12/08    ys     Enabled FEATURE_AVS_DYNAMIC_CALIBRATION
04/01/08   sud     Added support for DTMF Detection.
02/08/08   sud     Added feature FEATURE_VOC_AMR_WB for AMR-WB Vocoder.
                   Added feature FEATURE_IIR_FILTER_5S for 5-stage IIR filter.
                   Updated Copyright.
12/17/07   sud     Re-enabled FEATURE_AVS_CRYSTAL_SPEECH.
12/14/07   sud     Enabled FEATURE_PCM_VOCODER for 7600 and 7200A 5.X
                   Removed FEATURE_AVS_CRYSTAL_SPEECH feature enable.
08/21/07    ac     Added FEATURE_AVS_CRYSTAL_SPEECH
06/20/07    np     Added FEATURE_AUDFMT_EVB for 4GV playback.
05/01/07    aw     Added support for GSM TTY and PCM Package log.
03/23/07    aw     Enable QDSP_PACKET_SNIFFER only for vocoder 1x which have
                   FEATURE_DIAG_PACKET_COUPLING enabled in custdiag.h
01/22/07    aw     Enabled FEATURE_AUDIO_NEW_AUX_CODEC_HW for 7600, 7200A
17/01/07   kan     Enabled  QDSP_PACKET_SNIFFER for 1X vocoder packet log.
01/16/06    ac     Enabled FEATURE_AVS_I2SSBC
                           FEATURE_EXTERNAL_SDAC
                           FEATURE_EXTERNAL_SADC
11/16/06    aw     Enable FEATURE_IIR_FILTER
10/23/06    aw     Added FEATURE_AVS_NEXTGEN_EC
07/19/06    aw     Added FEATURE_VOC_PCM_INTERFACE
04/07/06    aw     Added FEATURE_INTERNAL_SADC
02/04/06   bam     Added FEATURE_AUDFMT_AMR
12/28/05   bam     Added FEATURE_VOICE_RECORD.
12/28/05    aw     Enabled FEATURE_VOICE_PLAYBACK
12/20/05    aw     Added FEATURE_VOC_PACKET_INTERFACE
12/12/04    aw     Added FEATURE_MVS
11/10/04    ro     Added FEATURE_QDSP_RTOS.
02/19/03    st     Added FEATURE_GRAPH_ADPCM.
02/03/03   cah     Added FEATURE_MVS for GSM.
11/11/02   cah     Added GSM features.
09/06/02    st     Enabled FEATURE_TTY.
08/23/02    st     Updated defines for SDAC.
05/01/02   jct     Created
===========================================================================*/
#if defined(FEATURE_AUDIO_CONFIGURATION_VALUE_ADD) || \
    defined(FEATURE_AUDIO_CONFIGURATION_STANDARD)

  /**************************************************************************
  [FEATURE NAME]:      FEATURE_VOICE_PLAYBACK
  [SCOPE]:             AUDDRV, AUDSVC
  [DESCRIPTION]:       Enable Voice playback function for QCP file playback
  [OEM CAN ENABLE/DISABLE]: YES.
  **************************************************************************/
  #define FEATURE_VOICE_PLAYBACK

  /**************************************************************************
  [FEATURE NAME]:      FEATURE_VOICE_RECORD
  [SCOPE]:             AUDDRV, AUDSVC
  [DESCRIPTION]:       Enable Voice recording function for QCP file recording
  [OEM CAN ENABLE/DISABLE]: YES.
  **************************************************************************/
  #define FEATURE_VOICE_RECORD

  #ifndef FEATURE_AUDIO_CONFIGURATION_MINIMAL
    #define FEATURE_AUDIO_CONFIGURATION_MINIMAL
  #endif

#endif /* FEATURE_AUDIO_CONFIGURATION_VALUE_ADD ||
          FEATURE_AUDIO_CONFIGURATION_STANDARD */

#ifdef FEATURE_AUDIO_CONFIGURATION_MINIMAL

  /**************************************************************************
  [FEATURE NAME]:      FEATURE_AUDIO_AGC
  [SCOPE]:             AVS, AUDDRV, AUDSVC
  [DESCRIPTION]:       Enable AUDIO AGC
  [OEM CAN ENABLE/DISABLE]: YES.
  **************************************************************************/
  #define FEATURE_AUDIO_AGC

  /**************************************************************************
  [FEATURE NAME]:      FEATURE_TTY
  [SCOPE]:             AVS
  [DESCRIPTION]:       Enable TTY Support
  [OEM CAN ENABLE/DISABLE]: YES.
  **************************************************************************/
  #define FEATURE_TTY

  /**************************************************************************
  [FEATURE NAME]:      FEATURE_VOC_PCM_INTERFACE
  [SCOPE]:             AVS
  [DESCRIPTION]:       Enable voice PCM interface for capture and playback 8K
                       PCM sample on ARM9
  [OEM CAN ENABLE/DISABLE]: YES.
  **************************************************************************/
  #define FEATURE_VOC_PCM_INTERFACE

  /**************************************************************************
  [FEATURE NAME]:      FEATURE_TTY_UMTS
  [SCOPE]:             VOCDRV, VOCSVC
  [DESCRIPTION]:       Enable new aux codec hardware interface on 7600, 7200A
                       Target.
  [OEM CAN ENABLE/DISABLE]: NO.
  **************************************************************************/
  #define FEATURE_TTY_UMTS

#endif /* FEATURE_AUDIO_CONFIGURATION_MINIMAL */

/*--------------- DO NOT CHANGE CODE BELOW THIS LINE ----------------------*/
/****************************************************************************
*****************************************************************************
*****************************************************************************
*****************************************************************************
*****************************************************************************
*****************************************************************************
****************************************************************************/

/*---------------------------------------------------------------------------
                            Feature Dependencies
---------------------------------------------------------------------------*/

#ifdef FEATURE_TTY_UMTS
  #ifndef FEATURE_TTY
    #define FEATURE_TTY
  #endif
  #ifndef FEATURE_VOC_PCM_INTERFACE
    #define FEATURE_VOC_PCM_INTERFACE
  #endif
#endif /* FEATURE_TTY_UMTS */


#endif /* CUSTAVS_H */
#ifndef CUSTWMS_H
#define CUSTWMS_H
/*===========================================================================

DESCRIPTION
  Configuration for WMS

  Copyright (c) 2002,2003,2004, 2005, 2006 by QUALCOMM Incorporated. 
  All Rights Reserved.
===========================================================================*/


/*---------------------------------------------------------------------------
                         Wireless Messaging Services
---------------------------------------------------------------------------*/
#if defined(FEATURE_CDMA) || defined(FEATURE_LTE)
  #define FEATURE_CDSMS
#endif

#if (defined(FEATURE_WCDMA) || defined(FEATURE_GSM))
  #define FEATURE_GWSMS
#endif

/* Common Features across CDMA and GW Modes */
#if defined(FEATURE_CDSMS) || defined(FEATURE_GWSMS)
  
  /* Enables user data headers to support voice and email address.
  */
  #define FEATURE_SMS_UDH

  /* Features specific to CDMA Mode */
  #ifdef FEATURE_CDSMS

    /* Broadcast SMS support
    */
    #define FEATURE_BROADCAST_SMS

    /* New Implementation of CDMA Broadcast API
    */
    #define FEATURE_CDSMS_BROADCAST

  #endif /* FEATURE_CDSMS */

#endif /*defined(FEATURE_CDSMS) || defined(FEATURE_GWSMS)*/

#endif /* CUSTWMS_H */
#ifndef CUSTHSUSB_H
#define CUSTHSUSB_H

/*===========================================================================

DESCRIPTION
Configuration for HS-USB. Karura M76XXT

Copyright (c) 2009  by QUALCOMM Incorporated. All Rights Reserved.
===========================================================================*/


/* Enables HS-USB for the target 
*/
#define FEATURE_HS_USB

#endif /* CUSTHSUSB_H */
#ifdef FEATURE_MODEM_STATISTICS
   #undef FEATURE_MODEM_STATISTICS
#endif

#endif /* CUSTT_________H */
#else
#endif

/* Now perform certain Sanity Checks on the various options and combinations
** of option.  Note that this list is probably NOT exhaustive, but just
** catches the obvious stuff.
*/


#endif /* CUSTOMER_H */
#endif

#endif /* TARGET_H */
#ifndef COMDEF_H
#define COMDEF_H
/*===========================================================================

                   S T A N D A R D    D E C L A R A T I O N S

DESCRIPTION
  This header file contains general types and macros that are of use
  to all modules.  The values or definitions are dependent on the specified
  target.  T_WINNT specifies Windows NT based targets, otherwise the
  default is for ARM targets.

       T_WINNT  Software is hosted on an NT platforn, triggers macro and
                type definitions, unlike definition above which triggers
                actual OS calls

DEFINED CONSTANTS

       Name      Definition
       -------   --------------------------------------------------------
       ON        Asserted condition
       OFF       Deasserted condition

       NULL      Pointer to nothing

       PACK()    Used to declare a C type packed for either GCC or ARM
                 compilers.

       *** DEPRECATED - WON'T WORK FOR newer versions (3.x) of GCC ***
       PACKED    Used to indicate structures which should use packed
                 alignment
       *** DEPRECATED - WON'T WORK FOR newer versions (3.x) of GCC ***

       INLINE    Used to inline functions for compilers which support this

Copyright (c) 1990-2010 by QUALCOMM, Inc.  All Rights Reserved.
===========================================================================*/

#ifndef COM_DTYPES_H
#define COM_DTYPES_H
/*===========================================================================

                   S T A N D A R D    D E C L A R A T I O N S

DESCRIPTION
  This header file contains general data types that are of use to all modules.  
  The values or definitions are dependent on the specified
  target.  T_WINNT specifies Windows NT based targets, otherwise the
  default is for ARM targets.

  T_WINNT  Software is hosted on an NT platforn, triggers macro and
           type definitions, unlike definition above which triggers
           actual OS calls

Copyright (c) 2009-2010 by QUALCOMM, Inc.  All Rights Reserved.
===========================================================================*/


/* ------------------------------------------------------------------------
** Constants
** ------------------------------------------------------------------------ */

#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif

#define TRUE   1   /* Boolean true value. */
#define FALSE  0   /* Boolean false value. */

#define  ON   1    /* On value. */
#define  OFF  0    /* Off value. */

#ifndef NULL
  #define NULL  0
#endif

/* -----------------------------------------------------------------------
** Standard Types
** ----------------------------------------------------------------------- */

/* The following definitions are the same accross platforms.  This first
** group are the sanctioned types.
*/
#ifndef _ARM_ASM_

#if defined(DALSTDDEF_H) /* guards against a known re-definer */
#define _UINT32_DEFINED
#define _UINT16_DEFINED
#define _UINT8_DEFINED
#define _INT32_DEFINED
#define _INT16_DEFINED
#define _INT8_DEFINED
#define _UINT64_DEFINED
#define _INT64_DEFINED
#define _BYTE_DEFINED
#endif /* #if !defined(DALSTDDEF_H) */

#ifndef _UINT32_DEFINED
typedef  unsigned long int  uint32;      /* Unsigned 32 bit value */
#define _UINT32_DEFINED
#endif

#ifndef _UINT16_DEFINED
typedef  unsigned short     uint16;      /* Unsigned 16 bit value */
#define _UINT16_DEFINED
#endif

#ifndef _UINT8_DEFINED
typedef  unsigned char      uint8;       /* Unsigned 8  bit value */
#define _UINT8_DEFINED
#endif

#ifndef _INT32_DEFINED
typedef  signed long int    int32;       /* Signed 32 bit value */
#define _INT32_DEFINED
#endif

#ifndef _INT16_DEFINED
typedef  signed short       int16;       /* Signed 16 bit value */
#define _INT16_DEFINED
#endif

#ifndef _INT8_DEFINED
typedef  signed char        int8;        /* Signed 8  bit value */
#define _INT8_DEFINED
#endif

/* This group are the deprecated types.  Their use should be
** discontinued and new code should use the types above
*/
#ifndef _BYTE_DEFINED
typedef  unsigned char      byte;         /* Unsigned 8  bit value type. */
#define  _BYTE_DEFINED
#endif

typedef  unsigned short     word;         /* Unsinged 16 bit value type. */
typedef  unsigned long      dword;        /* Unsigned 32 bit value type. */

typedef  unsigned char      uint1;        /* Unsigned 8  bit value type. */
typedef  unsigned short     uint2;        /* Unsigned 16 bit value type. */
typedef  unsigned long      uint4;        /* Unsigned 32 bit value type. */

typedef  signed char        int1;         /* Signed 8  bit value type. */
typedef  signed short       int2;         /* Signed 16 bit value type. */
typedef  long int           int4;         /* Signed 32 bit value type. */

typedef  signed long        sint31;       /* Signed 32 bit value */
typedef  signed short       sint15;       /* Signed 16 bit value */
typedef  signed char        sint7;        /* Signed 8  bit value */

#if (! defined T_WINNT) && (! defined __GNUC__)
  /* Non WinNT Targets */
  #ifndef _INT64_DEFINED
    typedef long long     int64;       /* Signed 64 bit value */
    #define _INT64_DEFINED
  #endif
  #ifndef _UINT64_DEFINED
    typedef  unsigned long long  uint64;      /* Unsigned 64 bit value */
    #define _UINT64_DEFINED
  #endif
#else /* T_WINNT || TARGET_OS_SOLARIS || __GNUC__ */
#endif /* T_WINNT */

#endif /* _ARM_ASM_ */

#endif  /* COM_DTYPES_H */

#ifndef _MSC_VER
#endif

#if defined FEATURE_L4  && !defined FEATURE_L4_KERNEL && !defined BUILD_BOOT_CHAIN && !defined ARCH_QDSP6
  #ifndef _ARM_ASM_
/*===========================================================================
     Copyright (c) 2004-2008 QUALCOMM Incorporated. All Rights Reserved.

     QUALCOMM Confidential and Proprietary
===========================================================================*/

#ifndef __MSM_SYSCALL_H__
#define __MSM_SYSCALL_H__
/*===========================================================================

              M S M    S Y S C A L L    H E A D E R    F I L E

DESCRIPTION
   This file contains the functions in assembly, which are equivelent
   to those inline assembly functions defined in msm_syscall.h

===========================================================================*/

#ifndef KXCACHE_H
#define KXCACHE_H

/*====================================================================
  FILE:         KxCache.h

  SERVICES:     Quartz cache management

  DESCRIPTION:  This API gives access to the cache functionality
                allowing various operations such as flushing and
                invalidating the cache at various granularity levels.


  Copyright (c) 2006 QUALCOMM Incorporated.
  All Rights Reserved. QUALCOMM Proprietary and Confidential.

 =====================================================================
 *$Header: //depot/asic/msm7x27/android_froyo/7.0/MODEM_APIS/libs/remote_apis/nv/inc/nv.h#22 $ */

 
/*
 * stdlib.h declares four types, several general purpose functions,
 * and defines several macros.
 */

#ifndef __stdlib_h
#define __stdlib_h


  #ifndef __STDLIB_DECLS
  #define __STDLIB_DECLS


#undef NULL
#define NULL 0                   /* see <stddef.h> */


   /*
    * Defining __USE_ANSI_EXAMPLE_RAND at compile time switches to
    * the example implementation of rand() and srand() provided in
    * the ANSI C standard. This implementation is very poor, but is
    * provided for completeness.
    */
#ifdef __USE_ANSI_EXAMPLE_RAND
#define rand _ANSI_rand
#else
#endif
   /*
    * RAND_MAX: an integral constant expression, the value of which
    * is the maximum value returned by the rand function.
    */
  #endif /* __STDLIB_DECLS */


#endif
/* end of stdlib.h */

#endif /* #ifdef KXCACHE_H */

#endif  /* __MSM_SYSCALL_H__ */
  #endif
#endif


/* ---------------------------------------------------------------------
** Compiler Keyword Macros
** --------------------------------------------------------------------- */


#if (! defined T_WINNT) && (! defined __GNUC__)
  
    /* Non WinNT Targets */

    #if defined(__ARMCC_VERSION) 
      #define PACKED __packed
      #define PACKED_POST
    #else  /* __GNUC__ */
    #endif /* defined (__GNUC__) */
  

#else /* T_WINNT || TARGET_OS_SOLARIS || __GNUC__ */
#endif /* T_WINNT */

/* ----------------------------------------------------------------------
** Lint does not understand __packed, so we define it away here.  In the
** past we did this:
**   This helps us catch non-packed pointers accessing packed structures,
**   for example, (although lint thinks it is catching non-volatile pointers
**   accessing volatile structures).
**   This does assume that volatile is not being used with __packed anywhere
**   because that would make Lint see volatile volatile (grrr).
** but found it to be more trouble than it was worth as it would emit bogus
** errors
** ---------------------------------------------------------------------- */
#ifdef _lint
  #ifdef __packed
    #undef __packed
  #endif /* __packed */
  #define __packed
#endif

/* ----------------------------------------------------------------------
**                          STANDARD MACROS
** ---------------------------------------------------------------------- */


/*===========================================================================

MACRO MAX
MACRO MIN

DESCRIPTION
  Evaluate the maximum/minimum of 2 specified arguments.

PARAMETERS
  x     parameter to compare to 'y'
  y     parameter to compare to 'x'

DEPENDENCIES
  'x' and 'y' are referenced multiple times, and should remain the same
  value each time they are evaluated.

RETURN VALUE
  MAX   greater of 'x' and 'y'
  MIN   lesser of 'x' and 'y'

SIDE EFFECTS
  None

===========================================================================*/
#ifndef MAX
   #define  MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#endif

#ifndef MIN
   #define  MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )
#endif


/* Provide a new macro that will hopefully be used correctly to conditionally
** turn static on/off
*/
#define STATIC static


/*===========================================================================

                      FUNCTION DECLARATIONS

===========================================================================*/

#endif  /* COMDEF_H */
#ifndef REX_H
#define REX_H
/*==========================================================================

                      R E X    H E A D E R    F I L E

DESCRIPTION
   API for the REX - Real Time Executive


Copyright (c) 1990-2009 by QUALCOMM Incorporated.  All Rights Reserved.
===========================================================================*/

typedef dword   rex_sigs_type;
#ifndef TIMETICK_H
#define TIMETICK_H
/*=============================================================================

                   T I M E   S E R V I C E   S U B S Y S T E M

GENERAL DESCRIPTION
  Implements time-keeping functions using the slow clock.

  Slow Clock Frequency          Granularity     Timer Range
    30.000kHz (lower limit)      33.3 us         39.7 hrs
    32.768kHz (nominal freq)     30.5 us         36.4 hrs
    60.000kHz (upper limit)      16.6 us         19.8 hrs


REGIONAL FUNCTIONS

  timetick_set_modem_app_sclk_offset(delta)
    Sets the modem/app sclk counter difference.  Call only from time*.c


EXTERNALIZED FUNCTIONS

  timetick_get
    Returns the current SLEEP_XTAL_TIMETICK counter's count.

  timetick_get_safe
    Returns the current SLEEP_XTAL_TIMETICK counter's count.
    Must be called from an INTLOCK'd context.

  timetick_get_diff
    Determines the time between two timeticks, in slow clocks, milliseconds,
    seconds, etc.

  timetick_get_elapsed
    Determines the time between a past timetick and now, in slow clocks,
    milliseconds, seconds, etc.

  timetick_get_ms
    Returns a monotonically increasing millisecond count, that is not
    related to system time or time-of-day.  Speed, not accuracy, is
    the focus of this function.

  timetick_cvt_to_sclk
    Converts a time value from seconds, milliseconds, etc to slow clocks

  timetick_cvt_from_sclk
    Converts a time value from slow clocks to seconds, milliseconds, etc

  timetick_sclk_to_prec_us
    Converts sclks to microseconds with precision and full range

INITIALIZATION AND SEQUENCING REQUIREMENTS
    None


Copyright (c) 2003 - 2009 by QUALCOMM Incorporated.  All Rights Reserved.

=============================================================================*/


/*-----------------------------------------------------------------------------
  Time, in slow clock counts, from 0 to 0xFFFFFFFF (~1.5 days)
-----------------------------------------------------------------------------*/

typedef uint32                    timetick_type;

#endif /* TIMETICK_H */

#endif /* END REX_H */
#ifndef QW_H
#define QW_H
/*===========================================================================

                  Q U A D W O R D   S E R V I C E S
                        H E A D E R    F I L E

DESCRIPTION
  This file contains delarations necessary to use the Quadword Services.

Copyright (c) 1991-2005 by QUALCOMM, Incorporated.  All Rights Reserved.
===========================================================================*/


/*
 * string.h declares one type and several functions, and defines one macro
 * useful for manipulating character arrays and other objects treated as
 * character arrays. Various methods are used for determining the lengths of
 * the arrays, but in all cases a char * or void * argument points to the
 * initial (lowest addresses) character of the array. If an array is written
 * beyond the end of an object, the behaviour is undefined.
 */

#ifndef __string_h
#define __string_h


  #ifndef __STRING_DECLS
  #define __STRING_DECLS


#undef NULL
#define NULL 0                   /* see <stddef.h> */

  #endif /* __STRING_DECLS */


#endif

/* end of string.h */

/* <EJECT> */
/*===========================================================================

                        DATA DECLARATIONS

===========================================================================*/

typedef unsigned long qword[ 2 ];

#endif /* QW_H */
#ifndef NV_ITEMS_H
#define NV_ITEMS_H

/*===========================================================================

                               NV_ITEMS.H 

DESCRIPTION
  This file is generated by NVC and contains constants, types, and definitions
  of all items in NV. 

  $Header: //depot/asic/msm7x27/android_froyo/7.0/MODEM_APIS/libs/remote_apis/nv/inc/nv.h#22 $
   Copyright (c) 2006 by QUALCOMM Incorporated.  All Rights Reserved.
===========================================================================*/


/* Maximum of 109 speed dials */
#define  NV_MAX_SPEED_DIALS                                    109

/* With up to 12-letter names */
#define  NV_MAX_LTRS                                            12

/* Maximum 20 call stack numbers */
#define  NV_MAX_STACK_DIALS                                     20

/* Up to 2 NAMs allowed */
#define  NV_MAX_NAMS                                             1

/* PRL size is 8192 */
#define  NV_ROAMING_LIST_MAX_SIZE                            16384

/* Max SID+NID */
#define  NV_MAX_SID_NID                                          1

/* size of all tables based on temperature */
#define  NV_TEMP_TABLE_SIZ                                       8

/* Size of all tables based on Frequency */
#define  NV_FREQ_TABLE_SIZ                                      16

/* size of all tables based on power level */
#define  NV_PWR_TABLE_SIZ                                       16

/* Size of all tables based on battery voltage */
#define  NV_VOLT_TABLE_SIZ                                       8

/* For 2 IP address records */
#define  NV_IP_ADDRESS_TABLE_SIZE                                2

/* For 4 IP addresses per record */
#define  NV_IP_ADDRESSES_PER_ENTRY                               4

/* Max size of the UP cache */
#define  NV_UP_MAX_CACHE_SIZE                                    1

/* PN ID table size */
#define  NV_PN_ID_TABLE_SIZE                                  2048

/* 100 bytes for each of two items */
#define  NV_SI_TEST_DATA_SIZE                                  100

/* Max size of key field */
#define  NV_UP_MAX_KEY_SIZE                                     16

/* CDMA Tx linearizer master offset size */
#define  NV_CDMA_TX_LIN_MASTER_SIZ                              37

/* 6 digit security code */
#define  NV_SEC_CODE_SIZE                                        6

/* size of tables based on temperature in MSM6xxx */
#define  NV_TEMP_TABLE2_SIZ                                     16

/* Maximum 32 digit number */
#define  NV_MAX_DIAL_DIGITS                                     32

/* Max of 64 chars in User ID */
#define  NV_MAX_PAP_USER_ID_LENGTH                              64

/* Max of 14 chars in Password */
#define  NV_MAX_PAP_PASSWORD_LENGTH                             14

/* Max length of the PPP password */
#define  NV_MAX_PPP_PASSWORD_LENGTH                            127

/* Max length of the PPP user id */
#define  NV_MAX_PPP_USER_ID_LENGTH                             127

/* Maximum length of Security Services Device Key */
#define  NV_SEC_DEVICE_KEY_MAX_LEN                              32

/* Maximum 20 logs in error log */
#define  NV_MAX_ERR_LOG                                         20

/* 8 characters file name length */
#define  NV_ERR_FILE_NAME_LEN                                    8

/* number digits in FSC */
#define  NV_FSC_SIZ                                              6

/* With up to 5 letters wdc */
#define  NV_WDC_LTRS                                             5

/* Array size for factory info */
#define  NV_FACTORY_INFO_SIZ                                   100

/* Can peek at up to 32 bytes in one request */
#define  NV_MAX_PEEK_SIZE                                       32

/* Can poke at up to 32 bytes in one request */
#define  NV_MAX_POKE_SIZE                                       32

/* CDMA MIN index */
#define  NV_CDMA_MIN_INDEX                                       1

/* Analog MIN index */
#define  NV_ANALOG_MIN_INDEX                                     0

/* One time alarms for DOT */
#define  NV_MAX_ALARMS                                           6

/* Number entries in table */
#define  NV_DIAL_STATE_TABLE_MAX_SIZE                          125

/* Mode is inactive (neither analog nor CDMA) */
#define  NV_MODE_INACTIVE                                        0

/* Mode is analog */
#define  NV_MODE_ANALOG                                          1

/* Mode is CDMA */
#define  NV_MODE_CDMA                                            2

/* Normal Mute */
#define  NV_MUTE_NORM                                            0

/* Mute */
#define  NV_MUTE_MUTE                                            1

/* Mute Speaker */
#define  NV_MUTE_SPKR                                            2

/* For 2 link info table records */
#define  NV_UP_LINK_INFO_TABLE_SIZE                              2

/* Up to 6 SIDs to lock out */
#define  NV_MAX_SID_LOCK                                         6

/* Up to 6 SIDs to acquire */
#define  NV_MAX_SID_ACQ                                          6

/* Up to 2 MINs per NAM allowed */
#define  NV_MAX_MINS                                             2

/* Table consists of 12 words */
#define  NV_MRU_TABLE_SIZE                                      12

/* Up to 10 SID/NIDs to lock out */
#define  NV_MAX_SID_NID_LOCK                                    10

/* Up to 20 home SID/NID pairs */
#define  NV_MAX_HOME_SID_NID                                    20

/* num digits in dir_number */
#define  NV_DIR_NUMB_SIZ                                        10

/* num digits in dir_number_pcs */
#define  NV_DIR_NUMB_PCS_SIZ                                    15

/* Max of 35 table entries */
#define  NV_USER_ZONE_MAX_ENTRIES                               35

/* Max of 15 characters per entry */
#define  NV_USER_ZONE_ENTRY_LENGTH                              15

/* Table consists of 12 words */
#define  NV_MRU2_TABLE_SIZE                                     12

/* Buffer bytes to account for uneven bit in PRL system table */
#define  NV_RAM_PRL_BUF_BYTES                                    6

/* An always-invalid prl version number */
#define  NV_PRL_VERSION_INVALID                        0xFFFF

#define  NV_SIZE_OF_ROAMING_LIST_IN_UNION_TYPE                   1

#define  NV_SIZE_OF_RAM_ROAMING_LIST                   ( NV_ROAMING_LIST_MAX_SIZE + NV_RAM_PRL_BUF_BYTES )

/* Maximum Micro Broswer data size */
#define  NV_UBROWSER_ELEMENT_SIZE                               64

/* Micro Browser table size */
#define  NV_UBROWSER_TABLE_SIZE                                 32

#define  NV_DIAG_RESTART_CONFIG_LOGMASK_SIZE                    16

/* Max size of perm_store field */
#define  NV_UP_MAX_PERM_STORE_SIZE                              10

/* Max size of alert_name field */
#define  NV_UP_ALERT_NAME_SIZE                                  11

/* Number of alert records */
#define  NV_UP_MAX_ALERT_RECORDS                                 9

/* Maximum 16 digit number */
#define  NV_MAX_PKT_ORIG_DIGITS                                 16

/* Maximum of 6 Mobile IP user profiles are supported */
#define  NV_DS_MIP_MAX_NUM_PROF                                  6

/* Maximum length of User NAI field */
#define  NV_MAX_NAI_LENGTH                                      72

/* Maximum length of MN-HA shared secret */
#define  NV_MAX_MN_HA_SHARED_SECRET_LEN                         16

/* Maximum length of MN-AAA shared secret */
#define  NV_MAX_MN_AAA_SHARED_SECRET_LEN                        16

/* Maximum number of Mobile/Home Agent timebase offset */
#define  NV_NUM_DS_MIP_MN_HA_TIME_DELTA                          6

/* Maximum Length of a domain name */
#define  NV_DOMAIN_NAME_SIZE                                   100

/* Maximum length of APN name */
#define  NV_MAX_APN_STRING_LEN                                 128

/* Maximum length of a DS Packet Dial string */
#define  NV_PKT_DIAL_STRING_SIZE                                 5

/* Number of entries in the packet dial string lookup table */
#define  NV_PKT_DIAL_STRING_LIST_SIZE                            4

/* Maximum number of PPP devices */
#define  NV_PPP_MAX_DEV                                          3

#define  NV_HDRSCP_PRTL_SUBTYPE_SIZ                    0x1A

#define  NV_HDR_CURR_STREAM_CFG_SIZ                              4

#define  NV_UATI_LENGTH                                         16

#define  NV_RPC_AUTH_KEY_MAX_LEN                                20

#define  NV_MAX_AN_AUTH_NAI_LENGTH                              64

#define  NV_MAX_AN_AUTH_PASSWORD_LENGTH                         14

#define  NV_MAX_AN_PPP_PASSWORD_LENGTH                         127

#define  NV_MAX_AN_PPP_USER_ID_LENGTH                          127

#define  NV_MAX_AN_AUTH_PASSWD_LONG_LENGTH                     127

#define  NV_MAX_AN_AUTH_USER_ID_LONG_LENGTH                    127

/* Up to 64 */
#define  NV_FR_TEMP_OFFSET_TABLE_SIZ                            64

/* CDMA Rx linearizer offset size */
#define  NV_CDMA_RX_LIN_SIZ                                     16

/* CDMA expected HDET reading vs AGC PDM size */
#define  NV_CDMA_EXP_HDET_VS_AGC_SIZ                            16

/* CDMA HDET error slope vs HDET reading size */
#define  NV_CDMA_ERR_SLP_VS_HDET_SIZ                             8

/* Adj vs. Frequency size */
#define  NV_ADJ_VS_FREQ_SIZ                                     16

/* Adj vs. Temp size */
#define  NV_ADJ_VS_TEMP_SIZ                                      8

/* HDET ADC table size */
#define  NV_HDET_ADC_TABLE_SIZ                                   6

/* Up to 32 items */
#define  NV_FREQ_ADJ_TABLE_SIZ                                  32

/* Portables RF CDMA Compensation Table Size */
#define  NV_RIPPLE_COMP_TABLE_SIZ                               32

/* Portable RX offset Compensation Table Size */
#define  NV_RX_OFFSET_TABLE_SIZ                                 32

/* Portable RX Power Compensation Table Size */
#define  NV_RX_POWER_TABLE_SIZ                                 128

/* Portable RX Error Compensation Table Size */
#define  NV_RX_ERROR_TABLE_SIZ                                 128

/* Portable TX Slope 1 Compensation Table Size */
#define  NV_TX_SLOPE_1_TABLE_SIZ                               128

/* Portable TX Slope 2 Compensation Table Size */
#define  NV_TX_SLOPE_2_TABLE_SIZ                               128

/* Portable Tx Nonlinear Error Compensation Table Size */
#define  NV_TX_NON_LIN_ERR_TABLE_SIZ                           128

/* HDET table size */
#define  NV_HDET_TABLE_SIZ                                     128

/* PCS Rx linearizer offset size */
#define  NV_PCS_RX_LIN_SIZ                                      16

/* PCS Tx linearizer master offset size */
#define  NV_PCS_TX_LIN_MASTER_SIZ                               37

/* PCS expected HDET reading vs AGC PDM size */
#define  NV_PCS_EXP_HDET_VS_AGC_SIZ                             16

/* Number of PA ranges */
#define  NV_NUM_PA_RANGES                                        4

/* Number of Tx linearizers */
#define  NV_NUM_TX_LINEARIZERS                                   4

/* Maximum Switch to Analog values */
#define  NV_MAX_STA_VALUES                                       2

/* Table size of TX AGC backoff values */
#define  NV_TX_BACKOFF_TABLE_SIZE                               20

/* Three values, min, med, and max, of the PA backoff values */
#define  NV_NUM_PA_BCKOFF_CAL_VOLT                               3

/* WCDMA Rx linearizer offset table size */
#define  NV_WCDMA_RX_LIN_SIZ                                    17

/* WCDMA Tx linearizer master offset table size */
#define  NV_WCDMA_TX_LIN_MASTER_SIZ                             37

/* WCDMA expected HDET reading vs TX AGC table size */
#define  NV_WCDMA_EXP_HDET_VS_AGC_SIZ                           16

/* Number of WCDMA Tx linearizers */
#define  NV_WCDMA_NUM_TX_LINEARIZERS                             2

/* Length of a version number in bytes */
#define  NV_SIZE_OF_VERSION                                      8

/* 9 character QCOM serial number */
#define  NV_QC_SERIAL_NUM_LEN                                    9

/* Table size of VCO_COARSE_TUNE table */
#define  NV_VCO_COARSE_TUNE_TABLE_SIZ                           16

/* Max bytes in SMS data buffer */
#define  NV_SMS_DATA_SIZ                                       388

/* Max bytes in SMS DM data buffer */
#define  NV_SMS_DM_DATA_SIZ                                    100

/* Total size of header fields within nvi_sms_type (i.e. excluding data) */
#define  NV_SMS_HEADER_SIZE                                     14

/* Max services */
#define  NV_SMS_MAX_SERVICES                                    32

/* Max number of languages for SMS displayed */
#define  NV_SMS_MAX_LANGUAGES                                    4

#define  NV_SMS_BC_TABLE_SIZE                          ( NV_SMS_MAX_SERVICES * NV_SMS_MAX_LANGUAGES )

/* Total size of label fields within nv_sms_bc_service_table_type */
#define  NV_SMS_BC_SRV_LABEL_SIZE                               30

/* Max size of GSM/WCDMA SMS template */
#define  NV_SMS_GW_PARAMS_SIZE                                 127

/* Max number of GWM/WCDMA SMS routes */
#define  NV_SMS_MAX_ROUTES                                       6

/* Max bytes in SMS GW data buffer */
#define  NV_SMS_GW_DATA_SIZ                                    176

/* Max number of CDMA SMS template */
#define  NV_SMS_CD_PARMS_MAX_ENTRIES                            20

/* Max size of CDMA SMS template */
#define  NV_SMS_CD_PARMS_SIZE                                  126

/* Max table size for GSM/UMTS Cell Broadcast SMS Service table */
#define  NV_SMS_GW_CB_TABLE_SIZE                               200

/* Max storage address for dial type */
#define  MAX_STORAGE_ADDRESS                                    99

/* Up to 20 characters in a pager */
#define  NV_MAX_PAGE_CHARS                                      20

/* 4 digit lock code */
#define  NV_LOCK_CODE_SIZE                                       4

/* Bytes in passwd */
#define  NV_ISD_STD_PASSWD_SIZ                                   4

/* Ten entries in the table */
#define  NV_DIAL_RESTRICT_LVLS_SIZE                             10

/* Up to 12 characters of text allowed */
#define  NV_ROAM_MSG_MAX_SIZE                                   12

/* 12 bytes per table entry */
#define  NV_DIAL_STATE_TABLE_NEXT_STATES                        12

/* 100 bytes per entry */
#define  NV_CARRIER_INFO_ELEMENT_SIZE                          100

/* Max of 3 entries allowed */
#define  NV_CARRIER_INFO_MAX_ELEMENTS                            3

/* Maximum 20 page messages */
#define  NV_MAX_PAGE_MSGS                                       20

/* Up to 6 entries in the table */
#define  NV_ROAM_MSG_MAX_ENTRIES                                 6

/* Max length of multimedia ringer filename */
#define  NV_FS_FILENAME_MAX_LENGTH                              40

/* Number of bytes in an R-UIM CHV */
#define  NV_RUIM_CHV_SIZE                                        8

/* 6 bytes per addr */
#define  NV_BD_ADDR_SIZE                                         6

/* Number of ECC phone numbers can be used */
#define  NV_MAX_NUM_OF_ECC_NUMBER                               10

/* Number of digits in an ECC phone number */
#define  NV_ECC_NUMBER_SIZE                                      3

/* Size of a Public Land Mobile Network ID */
#define  NV_PLMN_ID_SIZE                                         3

/* Maximum length of the equivalent PLMN list */
#define  NV_EQUIVALENT_PLMN_LIST_MAX_SIZE                        5

/* This defines the NAM for the RUIM card */
#define  NV_RUIM_NAM                                             0

/* Size of RPLMN */
#define  NV_RPLMNACA_SIZE                                        2

/* Size of UE IMEI */
#define  NV_UE_IMEI_SIZE                                         9

/* Max acquisition database entries */
#define  MAX_ACQ_DB_ENTRIES                                     10

/* Max acquisition database entries */
#define  MAX_MCC_DIGITS                                          3

/* Max acquisition database entries */
#define  MAX_MNC_DIGITS                                          3

#define  NV_TX_BURST_RAMP_SIZ                                   30

#define  NV_NUM_GSM_PA_PROFILES                                 15

#define  NV_NUM_DCS_PA_PROFILES                                 16

#define  NV_GSM_CAL_ARFCN_SIZ                                    8

#define  NV_DCS_CAL_ARFCN_SIZ                                   16

#define  NV_MAX_NUMBER_OF_BEST_CELLS                             7

#define  NV_EXP_HDET_VS_AGC_SIZ                                 16

#define  NV_GSM_1900_CAL_ARFCN_SIZ                              16

#define  NV_GSM_850_CAL_ARFCN_SIZ                                8

#define  NV_BREW_BKEY_SIZ                                       16

#define  NV_BREW_SERVER_SIZ                                     64

#define  NV_BREW_SID_SIZ                                        32

#define  NV_UPLOADMEDIA_ALBUM_ADDR_SIZ                          64

#define  NV_UPLOADMEDIA_POSTCARD_ADDR_SIZ                       64

#define  NV_MAX_SW_VERSION_INFO_SIZ                             30

#define  NV_USER_GREETING_SIZ                                   64

#define  NV_SMS_SMSC_ADDRESS_SIZ                                37

#define  NV_POC_SERVER_IP_SIZ                                   16

#define  NV_POC_NAI_SIZ                                         33

#define  NV_POC_BILLING_SERVICE_SIZ                             33

#define  NV_POC_GLM_PASSWORD_SIZ                                32

#define  NV_IM_IP_ADDR_SIZ                                      16

#define  MV_IM_SERVER_NAME_SIZ                                  64

#define  NV_EXT_OP_NAME_SIZ                                     64

#define  NV_LANGUAGE_COUNT                                      20

#define  NV_IRDA_DEVICE_NAME_SIZ                                20

#define  NV_IRDA_PNP_DEVICE_ID_SIZ                              15

#define  NV_IRDA_PNP_MANUFACTURER_SIZ                           31

#define  NV_IRDA_PNP_NAME_SIZ                                   91

#define  NV_IRDA_PNP_DEVICE_CATEGORY_SIZ                         4

#define  NV_MAX_SUPPORTED_BEARERS                                3

#define  NV_MAX_CIR_METHODS                                      6

#define  NV_IM_MAX_USERID_SIZE                                  50

#define  NV_IM_MAX_PASSWORD_SIZ                                 50

#define  NV_MAX_CIR_PORT_SIZ                                     6

#define  IM_MAX_SMSC_ADDR_SIZ                                   21

#define  NV_IM_OPTIONAL_HEADER_SIZ                              33

#define  NV_IM_MAX_SCHEMA_COUNT                                  8

#define  NV_IM_MAX_SCHEMA_NAME_LEN                               4

#define  NV_IM_MAX_START_STR_SIZ                                21

#define  NV_INTELLICEIVER_CAL_LENGTH                            14

#define  NV_RF_SWITCHPOINT_COUNT                                 4

#define  NV_PRESUPL_WAP_GW_ADDR_SIZE                            16

#define  NV_RF_POWER_MODE_SIZ                                    3

#define  NV_OFFSET_CALIBRATION_LENGTH                  ( NV_RF_POWER_MODE_SIZ*NV_FREQ_TABLE_SIZ )

#define  NV_VCO_CAL_LENGTH                             ( NV_RF_POWER_MODE_SIZ*NV_VCO_COARSE_TUNE_TABLE_SIZ)

#define  NV_POC_PASSWORD_SIZ                                    32

#define  NV_BROWSER_JUMP_PORTAL_NAME_SIZ                        32

#define  NV_BROWSER_JUMP_EMBDLNK_SIZ                            32

#define  NV_VOICE_MAIL_LINE_SIZ                                 48

#define  SOS_NUMBER_SIZ                                         32

#define  WAP_MAX_URL_SIZ                                        64

#define  WAP_PUSH_AUTOLOAD_SIZ                                  13

#define  NV_MAX_URL_SIZ                                        128

#define  NV_LC_SERVICENAME_SIZ                                  25

#define  NV_LC_UDPPUSHSERVERNAME_SIZ                           128

#define  NV_TRUSTEDDOMAIN_SIZ                                  128

#define  NV_LC_SUBURL_KEY_LABEL_SIZ                             16

/* Size of all tables based on Frequency */
#define  NV_MAX_ANT_NO_SIZ                                       4

#define  NV_MAX_NO_OF_ANT_V                                      4

#define  NV_SQN_ARR_HALF_SIZE                                   16

#define  NV_3G_KEY_SIZE                                         16

#define  NV_CAMERA_PREFIX_SIZ                                   10

#define  NV_VIDEO_NAME_PREFIX_SIZ                               10

#define  NV_SMS_HEADER_TEMPLATE_FILE_SIZ                        64

#define  NV_SMS_SIGNATURE_TEMPLATE_FILE_SIZ                     64

#define  NV_INTELLICEIVER_DETECTOR_COUNT                         2

#define  NV_CUSTOMIZATION_VERSIONING_SIZ                        33

#define  NV_SEQ_SQN_ARR_SIZE                           16*6

#define  NV_SD_ITEMS_MAX                                        25

#define  NV_MAX_NW_NAME_CHARS                                   32

#define  NV_PA_COMPENSATE_VS_FREQ_TYPE                          16

#define  NV_TX_PDM_LIN_TYPE                                     32

#define  NV_SEC_CSPRNG_INIT_SEED_LEN                            32

#define  NV_HDRSCMDB_MAX_PERSONALITIES                           4

#define  NV_HDRKEP_KEY_SIG_LEN                                  20

#define  NV_SECAPI_HSH_SHA_DIGEST_SIZE                          20

#define  NV_MAX_BUS_PROF_MONITORS                                4

#define  NV_MAX_GPSONE_PASSWORD_LENGTH                         127

#define  NV_SMS_BEARER_PREFS_MAX                                10

#define  NV_DVBH_MAX_FREQ_RANGES_IN_BAND                         5

#define  NV_DVBH_MAX_PLATFORMS                                   5

#define  NV_DVBH_MAX_NW_IDS_IN_PLATFORM                         10

#define  NV_CDMA_TX_PDM_LIN_TYPE                                64

#define  NV_MBP_RF_NUM_CAL_FREQS                                16

#define  NV_DVBH_MAX_FREQ_RANGES_AND_OFFSET_IN_BAND              8

#define  NV_DVBH_MAX_CELL_ID_RANGES                             16

#define  NUM_OF_LOCKS                                            4

#define  MF_PROXY_MAX_LEN                                      128

#define  NV_SID_TO_MCC_TBL_LEN                                  10

#define  NV_UI_IOTA_MAX_URL_SIZE                               128

#define  NV_UI_IOTA_URL_SIZE_64                                 64

#define  NV_MAX_WEB_SVRS                                         4

#define  NV_TX_LIN_MASTER_ENH_SIZE                              64

#define  NV_TX_PDM_LIN_ENH_SIZE                                 64

#define  NV_RR_ACQ_DB_MAX_ENTRIES_PER_CHUNK                     25

#define  NV_CSCA_SCA_STR_MAX_LEN                                22

#define  NV_CSCA_TOSCA_STR_MAX_LEN                               6

#define  NV_CSMP_FO_STR_MAX_LEN                                  4

#define  NV_CSMP_VP_STR__MAX_LEN                                23

#define  NV_CSCB_MIDS_STR_MAX_LEN                               51

#define  NV_CSCB_DCSS_STR_MAX_LEN                               51

#define  GSM_RGI_NV_ITEM_SIZE                                   32

#define  GSM_PMEAS_NV_ITEM_SIZE                                 32

#define  NV_KV_VS_TEMP_MAX_SIZ                                   8

#define  NV_LINEAR_PA_TEMP_COMP_SIZE                            16

#define  GSM_AMAM_TBL_LINEAR_PA_SIZE                            64

#define  GSM_AMPM_TBL_LINEAR_PA_SIZE                            64

#define  NV_MAX_MIPV6_PROFILES                                   5

#define  NV_MAX_MIPV6_NAI_LENGTH                                72

#define  NV_MAX_MIPV6_EAP_AKA_CREDENTIAL_LENGTH                 16

#define  NV_MAX_MIPV6_MN_AAA_SHARED_SECRET_LENGTH               16

#define  NV_MAX_MIPV6_MN_HA_SHARED_SECRET_LENGTH                16

#define  SMD_DATA_PORT_COUNT                                    10

#define  NV_IWLAN_MAX_OPERATOR_ID                              100

#define  NV_IWLAN_MAX_REALM_LENGTH                             127

#define  NV_IWLAN_MAX_DOMAIN_NAME_SIZE                         127

#define  NV_TEMP_THRESH_CNT                                      3

#define  NV_PPP_EAP_MAX_SHARED_SECRET_LENGTH                    16

#define  NV_PPP_EAP_MAX_USER_ID_LEN                             72

#define  NV_WWWAN_MAX_CFG                                       10

#define  NV_ICCID_MAX_SIZE                                      10

#define  NV_EHRPD_MILENAGE_MAX_OP_LENGTH                        16

#define  MAX_MSIN_DIGITS                                        10

#define  NV_IS683A_MAX_HDR_BAND_CHAN                             1

#define  LTE_LNA_RISE_FALL_SIZ                                  16

#define  LTE_RX_CAL_CHAN_SIZE                                   16

#define  RX_TEMP_BIN_SIZ                                         8

#define  TX_ROT_ANGLE_SIZE                                       8

#define  TX_PA_STATE_SIZ                                         8

#define  LTE_USABLE_GAIN_STATES                                  8

#define  LTE_RX_FREQ_COMP_SIZ                                   16

#define  LTE_TX_TEMP_COMP_SIZ                                    8

#define  LTE_TX_CAL_CHAN_SIZ                                    16

#define  LTE_MPR_SIZ                                            16

#define  LTE_TX_LIN_MASTER_SIZ                                  64

#define  LTE_TX_FREQ_COMP_SIZ                                   16

#define  LTE_HDET_VS_AGC_SIZ                                    16

#define  NV_QMI_PORT_LIST_MAX_SIZE                               9

#define  NV_EXTENDED_EQUIVALENT_PLMN_LIST_MAX_SIZE              10

/* Additional NV items added by customers should start with ID:50000 onwards*/
/* to avoid duplicate identification numbers.                               */

typedef enum {

  NV_ESN_I                                       = 0,
  NV_ESN_CHKSUM_I                                = 1,
  NV_VERNO_MAJ_I                                 = 2,
  NV_VERNO_MIN_I                                 = 3,
  NV_SCM_I                                       = 4,
  NV_SLOT_CYCLE_INDEX_I                          = 5,
  NV_MOB_CAI_REV_I                               = 6,
  NV_MOB_FIRM_REV_I                              = 7,
  NV_MOB_MODEL_I                                 = 8,
  NV_CONFIG_CHKSUM_I                             = 9,
  NV_PREF_MODE_I                                 = 10,
  NV_CDMA_PREF_SERV_I                            = 11,
  NV_ANALOG_PREF_SERV_I                          = 12,
  NV_CDMA_SID_LOCK_I                             = 13,
  NV_CDMA_SID_ACQ_I                              = 14,
  NV_ANALOG_SID_LOCK_I                           = 15,
  NV_ANALOG_SID_ACQ_I                            = 16,
  NV_ANALOG_FIRSTCHP_I                           = 17,
  NV_ANALOG_HOME_SID_I                           = 18,
  NV_ANALOG_REG_I                                = 19,
  NV_PCDMACH_I                                   = 20,
  NV_SCDMACH_I                                   = 21,
  NV_PPCNCH_I                                    = 22,
  NV_SPCNCH_I                                    = 23,
  NV_NAM_CHKSUM_I                                = 24,
  NV_A_KEY_I                                     = 25,
  NV_A_KEY_CHKSUM_I                              = 26,
  NV_SSD_A_I                                     = 27,
  NV_SSD_A_CHKSUM_I                              = 28,
  NV_SSD_B_I                                     = 29,
  NV_SSD_B_CHKSUM_I                              = 30,
  NV_COUNT_I                                     = 31,
  NV_MIN1_I                                      = 32,
  NV_MIN2_I                                      = 33,
  NV_MOB_TERM_HOME_I                             = 34,
  NV_MOB_TERM_FOR_SID_I                          = 35,
  NV_MOB_TERM_FOR_NID_I                          = 36,
  NV_ACCOLC_I                                    = 37,
  NV_SID_NID_I                                   = 38,
  NV_MIN_CHKSUM_I                                = 39,
  NV_CURR_NAM_I                                  = 40,
  NV_ORIG_MIN_I                                  = 41,
  NV_AUTO_NAM_I                                  = 42,
  NV_NAME_NAM_I                                  = 43,
  NV_NXTREG_I                                    = 44,
  NV_LSTSID_I                                    = 45,
  NV_LOCAID_I                                    = 46,
  NV_PUREG_I                                     = 47,
  NV_ZONE_LIST_I                                 = 48,
  NV_SID_NID_LIST_I                              = 49,
  NV_DIST_REG_I                                  = 50,
  NV_LAST_CDMACH_I                               = 51,
  NV_CALL_TIMER_I                                = 52,
  NV_AIR_TIMER_I                                 = 53,
  NV_ROAM_TIMER_I                                = 54,
  NV_LIFE_TIMER_I                                = 55,
  NV_RUN_TIMER_I                                 = 56,
  NV_DIAL_I                                      = 57,
  NV_STACK_I                                     = 58,
  NV_STACK_IDX_I                                 = 59,
  NV_PAGE_SET_I                                  = 60,
  NV_PAGE_MSG_I                                  = 61,
  NV_EAR_LVL_I                                   = 62,
  NV_SPEAKER_LVL_I                               = 63,
  NV_RINGER_LVL_I                                = 64,
  NV_BEEP_LVL_I                                  = 65,
  NV_CALL_BEEP_I                                 = 66,
  NV_CONT_KEY_DTMF_I                             = 67,
  NV_CONT_STR_DTMF_I                             = 68,
  NV_SVC_AREA_ALERT_I                            = 69,
  NV_CALL_FADE_ALERT_I                           = 70,
  NV_BANNER_I                                    = 71,
  NV_LCD_I                                       = 72,
  NV_AUTO_POWER_I                                = 73,
  NV_AUTO_ANSWER_I                               = 74,
  NV_AUTO_REDIAL_I                               = 75,
  NV_AUTO_HYPHEN_I                               = 76,
  NV_BACK_LIGHT_I                                = 77,
  NV_AUTO_MUTE_I                                 = 78,
  NV_MAINTRSN_I                                  = 79,
  NV_LCKRSN_P_I                                  = 80,
  NV_LOCK_I                                      = 81,
  NV_LOCK_CODE_I                                 = 82,
  NV_AUTO_LOCK_I                                 = 83,
  NV_CALL_RSTRC_I                                = 84,
  NV_SEC_CODE_I                                  = 85,
  NV_HORN_ALERT_I                                = 86,
  NV_ERR_LOG_I                                   = 87,
  NV_UNIT_ID_I                                   = 88,
  NV_FREQ_ADJ_I                                  = 89,
  NV_VBATT_I                                     = 90,
  NV_FM_TX_PWR_I                                 = 91,
  NV_FR_TEMP_OFFSET_I                            = 92,
  NV_DM_IO_MODE_I                                = 93,
  NV_CDMA_TX_LIMIT_I                             = 94,
  NV_FM_RSSI_I                                   = 95,
  NV_CDMA_RIPPLE_I                               = 96,
  NV_CDMA_RX_OFFSET_I                            = 97,
  NV_CDMA_RX_POWER_I                             = 98,
  NV_CDMA_RX_ERROR_I                             = 99,
  NV_CDMA_TX_SLOPE_1_I                           = 100,
  NV_CDMA_TX_SLOPE_2_I                           = 101,
  NV_CDMA_TX_ERROR_I                             = 102,
  NV_PA_CURRENT_CTL_I                            = 103,
  NV_SONY_ATTEN_1_I                              = 104,
  NV_SONY_ATTEN_2_I                              = 105,
  NV_VOC_GAIN_I                                  = 106,
  NV_SPARE_1_I                                   = 107,
  NV_SPARE_2_I                                   = 108,
  NV_DATA_SRVC_STATE_I                           = 109,
  NV_DATA_IO_MODE_I                              = 110,
  NV_IDLE_DATA_TIMEOUT_I                         = 111,
  NV_MAX_TX_ADJ_I                                = 112,
  NV_INI_MUTE_I                                  = 113,
  NV_FACTORY_INFO_I                              = 114,
  NV_SONY_ATTEN_3_I                              = 115,
  NV_SONY_ATTEN_4_I                              = 116,
  NV_SONY_ATTEN_5_I                              = 117,
  NV_DM_ADDR_I                                   = 118,
  NV_CDMA_PN_MASK_I                              = 119,
  NV_SEND_TIMEOUT_I                              = 120,
  NV_FM_AGC_SET_VS_PWR_I                         = 121,
  NV_FM_AGC_SET_VS_FREQ_I                        = 122,
  NV_FM_AGC_SET_VS_TEMP_I                        = 123,
  NV_FM_EXP_HDET_VS_PWR_I                        = 124,
  NV_FM_ERR_SLP_VS_PWR_I                         = 125,
  NV_FM_FREQ_SENSE_GAIN_I                        = 126,
  NV_CDMA_RX_LIN_OFF_0_I                         = 127,
  NV_CDMA_RX_LIN_SLP_I                           = 128,
  NV_CDMA_RX_COMP_VS_FREQ_I                      = 129,
  NV_CDMA_TX_COMP_VS_FREQ_I                      = 130,
  NV_CDMA_TX_COMP_VS_VOLT_I                      = 131,
  NV_CDMA_TX_LIN_MASTER_OFF_0_I                  = 132,
  NV_CDMA_TX_LIN_MASTER_SLP_I                    = 133,
  NV_CDMA_TX_LIN_VS_TEMP_I                       = 134,
  NV_CDMA_TX_LIN_VS_VOLT_I                       = 135,
  NV_CDMA_TX_LIM_VS_TEMP_I                       = 136,
  NV_CDMA_TX_LIM_VS_VOLT_I                       = 137,
  NV_CDMA_TX_LIM_VS_FREQ_I                       = 138,
  NV_CDMA_EXP_HDET_VS_AGC_I                      = 139,
  NV_CDMA_ERR_SLP_VS_HDET_I                      = 140,
  NV_THERM_I                                     = 141,
  NV_VBATT_PA_I                                  = 142,
  NV_HDET_OFF_I                                  = 143,
  NV_HDET_SPN_I                                  = 144,
  NV_ONETOUCH_DIAL_I                             = 145,
  NV_FM_AGC_ADJ_VS_FREQ_I                        = 146,
  NV_FM_AGC_ADJ_VS_TEMP_I                        = 147,
  NV_RF_CONFIG_I                                 = 148,
  NV_R1_RISE_I                                   = 149,
  NV_R1_FALL_I                                   = 150,
  NV_R2_RISE_I                                   = 151,
  NV_R2_FALL_I                                   = 152,
  NV_R3_RISE_I                                   = 153,
  NV_R3_FALL_I                                   = 154,
  NV_PA_RANGE_STEP_CAL_I                         = 155,
  NV_LNA_RANGE_POL_I                             = 156,
  NV_LNA_RANGE_RISE_I                            = 157,
  NV_LNA_RANGE_FALL_I                            = 158,
  NV_LNA_RANGE_OFFSET_I                          = 159,
  NV_POWER_CYCLES_I                              = 160,
  NV_ALERTS_LVL_I                                = 161,
  NV_ALERTS_LVL_SHADOW_I                         = 162,
  NV_RINGER_LVL_SHADOW_I                         = 163,
  NV_BEEP_LVL_SHADOW_I                           = 164,
  NV_EAR_LVL_SHADOW_I                            = 165,
  NV_TIME_SHOW_I                                 = 166,
  NV_AIR_CNT_I                                   = 168,
  NV_ROAM_CNT_I                                  = 169,
  NV_LIFE_CNT_I                                  = 170,
  NV_SEND_PIN_I                                  = 171,
  NV_SMS_I                                       = 174,
  NV_SMS_DM_I                                    = 175,
  NV_IMSI_MCC_I                                  = 176,
  NV_IMSI_11_12_I                                = 177,
  NV_DIR_NUMBER_I                                = 178,
  NV_VOICE_PRIV_I                                = 179,
  NV_SPARE_B1_I                                  = 180,
  NV_SPARE_B2_I                                  = 181,
  NV_SPARE_W1_I                                  = 182,
  NV_SPARE_W2_I                                  = 183,
  NV_FSC_I                                       = 184,
  NV_ALARMS_I                                    = 185,
  NV_STANDING_ALARM_I                            = 186,
  NV_ISD_STD_PASSWD_I                            = 187,
  NV_ISD_STD_RESTRICT_I                          = 188,
  NV_DIALING_PLAN_I                              = 189,
  NV_FM_LNA_CTL_I                                = 190,
  NV_LIFE_TIMER_G_I                              = 191,
  NV_CALL_TIMER_G_I                              = 192,
  NV_PWR_DWN_CNT_I                               = 193,
  NV_FM_AGC_I                                    = 194,
  NV_FSC2_I                                      = 195,
  NV_FSC2_CHKSUM_I                               = 196,
  NV_WDC_I                                       = 197,
  NV_HW_CONFIG_I                                 = 198,
  NV_CDMA_RX_LIN_VS_TEMP_I                       = 199,
  NV_CDMA_ADJ_FACTOR_I                           = 200,
  NV_CDMA_TX_LIM_BOOSTER_OFF_I                   = 201,
  NV_CDMA_RX_SLP_VS_TEMP_I                       = 202,
  NV_CDMA_TX_SLP_VS_TEMP_I                       = 203,
  NV_PA_RANGE_VS_TEMP_I                          = 204,
  NV_LNA_SWITCH_VS_TEMP_I                        = 205,
  NV_FM_EXP_HDET_VS_TEMP_I                       = 206,
  NV_N1M_I                                       = 207,
  NV_IMSI_I                                      = 208,
  NV_IMSI_ADDR_NUM_I                             = 209,
  NV_ASSIGNING_TMSI_ZONE_LEN_I                   = 210,
  NV_ASSIGNING_TMSI_ZONE_I                       = 211,
  NV_TMSI_CODE_I                                 = 212,
  NV_TMSI_EXP_I                                  = 213,
  NV_HOME_PCS_FREQ_BLOCK_I                       = 214,
  NV_DIR_NUMBER_PCS_I                            = 215,
  NV_ROAMING_LIST_I                              = 216,
  NV_MRU_TABLE_I                                 = 217,
  NV_REDIAL_I                                    = 218,
  NV_OTKSL_I                                     = 219,
  NV_TIMED_PREF_MODE_I                           = 220,
  NV_RINGER_TYPE_I                               = 221,
  NV_ANY_KEY_ANSWER_I                            = 222,
  NV_BACK_LIGHT_HFK_I                            = 223,
  NV_KEY_SOUND_I                                 = 225,
  NV_DIALS_SORTING_METHOD_I                      = 226,
  NV_LANGUAGE_SELECTION_I                        = 227,
  NV_MENU_FORMAT_I                               = 228,
  NV_RINGER_SPKR_LVL_I                           = 229,
  NV_BEEP_SPKR_LVL_I                             = 230,
  NV_MRU2_TABLE_I                                = 231,
  NV_VIBRATOR_I                                  = 232,
  NV_FLIP_ANSWERS_I                              = 233,
  NV_DIAL_RESTRICT_LVLS_I                        = 234,
  NV_DIAL_STATE_TABLE_LEN_I                      = 235,
  NV_DIAL_STATE_TABLE_I                          = 236,
  NV_VOICE_PRIV_ALERT_I                          = 237,
  NV_IP_ADDRESS_I                                = 238,
  NV_CURR_GATEWAY_I                              = 239,
  NV_DATA_QNC_ENABLED_I                          = 240,
  NV_DATA_SO_SET_I                               = 241,
  NV_UP_LINK_INFO_I                              = 242,
  NV_UP_PARMS_I                                  = 243,
  NV_ELAPSED_TIME_I                              = 245,
  NV_PDM2_I                                      = 246,
  NV_RX_AGC_MINMAX_I                             = 247,
  NV_VBATT_AUX_I                                 = 248,
  NV_DTACO_CONTROL_I                             = 249,
  NV_DTACO_INTERDIGIT_TIMEOUT_I                  = 250,
  NV_PDM1_I                                      = 251,
  NV_BELL_MODEM_I                                = 252,
  NV_PDM1_VS_TEMP_I                              = 253,
  NV_PDM2_VS_TEMP_I                              = 254,
  NV_SID_NID_LOCK_I                              = 255,
  NV_PRL_ENABLED_I                               = 256,
  NV_ROAMING_LIST_683_I                          = 257,
  NV_SYSTEM_PREF_I                               = 258,
  NV_HOME_SID_NID_I                              = 259,
  NV_OTAPA_ENABLED_I                             = 260,
  NV_NAM_LOCK_I                                  = 261,
  NV_IMSI_T_S1_I                                 = 262,
  NV_IMSI_T_S2_I                                 = 263,
  NV_IMSI_T_MCC_I                                = 264,
  NV_IMSI_T_11_12_I                              = 265,
  NV_IMSI_T_ADDR_NUM_I                           = 266,
  NV_UP_ALERTS_I                                 = 267,
  NV_UP_IDLE_TIMER_I                             = 268,
  NV_SMS_UTC_I                                   = 269,
  NV_ROAM_RINGER_I                               = 270,
  NV_RENTAL_TIMER_I                              = 271,
  NV_RENTAL_TIMER_INC_I                          = 272,
  NV_RENTAL_CNT_I                                = 273,
  NV_RENTAL_TIMER_ENABLED_I                      = 274,
  NV_FULL_SYSTEM_PREF_I                          = 275,
  NV_BORSCHT_RINGER_FREQ_I                       = 276,
  NV_PAYPHONE_ENABLE_I                           = 277,
  NV_DSP_ANSWER_DET_ENABLE_I                     = 278,
  NV_EVRC_PRI_I                                  = 279,
  NV_AFAX_CLASS_20_I                             = 280,
  NV_V52_CONTROL_I                               = 281,
  NV_CARRIER_INFO_I                              = 282,
  NV_AFAX_I                                      = 283,
  NV_SIO_PWRDWN_I                                = 284,
  NV_PREF_VOICE_SO_I                             = 285,
  NV_VRHFK_ENABLED_I                             = 286,
  NV_VRHFK_VOICE_ANSWER_I                        = 287,
  NV_PDM1_VS_FREQ_I                              = 288,
  NV_PDM2_VS_FREQ_I                              = 289,
  NV_SMS_AUTO_DELETE_I                           = 290,
  NV_SRDA_ENABLED_I                              = 291,
  NV_OUTPUT_UI_KEYS_I                            = 292,
  NV_POL_REV_TIMEOUT_I                           = 293,
  NV_SI_TEST_DATA_1_I                            = 294,
  NV_SI_TEST_DATA_2_I                            = 295,
  NV_SPC_CHANGE_ENABLED_I                        = 296,
  NV_DATA_MDR_MODE_I                             = 297,
  NV_DATA_PKT_ORIG_STR_I                         = 298,
  NV_UP_KEY_I                                    = 299,
  NV_DATA_AUTO_PACKET_DETECTION_I                = 300,
  NV_AUTO_VOLUME_ENABLED_I                       = 301,
  NV_WILDCARD_SID_I                              = 302,
  NV_ROAM_MSG_I                                  = 303,
  NV_OTKSL_FLAG_I                                = 304,
  NV_BROWSER_TYPE_I                              = 305,
  NV_SMS_REMINDER_TONE_I                         = 306,
  NV_UBROWSER_I                                  = 307,
  NV_BTF_ADJUST_I                                = 308,
  NV_FULL_PREF_MODE_I                            = 309,
  NV_UP_BROWSER_WARN_I                           = 310,
  NV_FM_HDET_ADC_RANGE_I                         = 311,
  NV_CDMA_HDET_ADC_RANGE_I                       = 312,
  NV_PN_ID_I                                     = 313,
  NV_USER_ZONE_ENABLED_I                         = 314,
  NV_USER_ZONE_I                                 = 315,
  NV_PAP_DATA_I                                  = 316,
  NV_DATA_DEFAULT_PROFILE_I                      = 317,
  NV_PAP_USER_ID_I                               = 318,
  NV_PAP_PASSWORD_I                              = 319,
  NV_STA_TBYE_I                                  = 320,
  NV_STA_MIN_THR_I                               = 321,
  NV_STA_MIN_RX_I                                = 322,
  NV_STA_MIN_ECIO_I                              = 323,
  NV_STA_PRI_I                                   = 324,
  NV_PCS_RX_LIN_OFF_0_I                          = 325,
  NV_PCS_RX_LIN_SLP_I                            = 326,
  NV_PCS_RX_COMP_VS_FREQ_I                       = 327,
  NV_PCS_TX_COMP_VS_FREQ_I                       = 328,
  NV_PCS_TX_LIN_MASTER_OFF_0_I                   = 329,
  NV_PCS_TX_LIN_MASTER_SLP_I                     = 330,
  NV_PCS_TX_LIN_VS_TEMP_I                        = 331,
  NV_PCS_TX_LIM_VS_TEMP_I                        = 332,
  NV_PCS_TX_LIM_VS_FREQ_I                        = 333,
  NV_PCS_EXP_HDET_VS_AGC_I                       = 334,
  NV_PCS_HDET_OFF_I                              = 335,
  NV_PCS_HDET_SPN_I                              = 336,
  NV_PCS_R1_RISE_I                               = 337,
  NV_PCS_R1_FALL_I                               = 338,
  NV_PCS_R2_RISE_I                               = 339,
  NV_PCS_R2_FALL_I                               = 340,
  NV_PCS_R3_RISE_I                               = 341,
  NV_PCS_R3_FALL_I                               = 342,
  NV_PCS_PA_RANGE_STEP_CAL_I                     = 343,
  NV_PCS_PDM1_VS_FREQ_I                          = 344,
  NV_PCS_PDM2_VS_FREQ_I                          = 345,
  NV_PCS_LNA_RANGE_POL_I                         = 346,
  NV_PCS_LNA_RANGE_RISE_I                        = 347,
  NV_PCS_LNA_RANGE_FALL_I                        = 348,
  NV_PCS_LNA_RANGE_OFFSET_I                      = 349,
  NV_PCS_RX_LIN_VS_TEMP_I                        = 350,
  NV_PCS_ADJ_FACTOR_I                            = 351,
  NV_PCS_PA_RANGE_VS_TEMP_I                      = 352,
  NV_PCS_PDM1_VS_TEMP_I                          = 353,
  NV_PCS_PDM2_VS_TEMP_I                          = 354,
  NV_PCS_RX_SLP_VS_TEMP_I                        = 355,
  NV_PCS_TX_SLP_VS_TEMP_I                        = 356,
  NV_PCS_RX_AGC_MINMAX_I                         = 357,
  NV_PA_OFFSETS_I                                = 358,
  NV_CDMA_TX_LIN_MASTER0_I                       = 367,
  NV_CDMA_TX_LIN_MASTER1_I                       = 368,
  NV_CDMA_TX_LIN_MASTER2_I                       = 369,
  NV_CDMA_TX_LIN_MASTER3_I                       = 370,
  NV_TIME_FMT_SELECTION_I                        = 371,
  NV_SMS_BC_SERVICE_TABLE_SIZE_I                 = 372,
  NV_SMS_BC_SERVICE_TABLE_I                      = 373,
  NV_SMS_BC_CONFIG_I                             = 374,
  NV_SMS_BC_USER_PREF_I                          = 375,
  NV_LNA_RANGE_2_RISE_I                          = 376,
  NV_LNA_RANGE_2_FALL_I                          = 377,
  NV_LNA_RANGE_12_OFFSET_I                       = 378,
  NV_NONBYPASS_TIMER_I                           = 379,
  NV_BYPASS_TIMER_I                              = 380,
  NV_IM_LEVEL1_I                                 = 381,
  NV_IM_LEVEL2_I                                 = 382,
  NV_CDMA_LNA_OFFSET_VS_FREQ_I                   = 383,
  NV_CDMA_LNA_12_OFFSET_VS_FREQ_I                = 384,
  NV_AGC_PHASE_OFFSET_I                          = 385,
  NV_RX_AGC_MIN_11_I                             = 386,
  NV_PCS_LNA_RANGE_2_RISE_I                      = 387,
  NV_PCS_LNA_RANGE_2_FALL_I                      = 388,
  NV_PCS_LNA_RANGE_12_OFFSET_I                   = 389,
  NV_PCS_NONBYPASS_TIMER_I                       = 390,
  NV_PCS_BYPASS_TIMER_I                          = 391,
  NV_PCS_IM_LEVEL1_I                             = 392,
  NV_PCS_IM_LEVEL2_I                             = 393,
  NV_PCS_CDMA_LNA_OFFSET_VS_FREQ_I               = 394,
  NV_PCS_CDMA_LNA_12_OFFSET_VS_FREQ_I            = 395,
  NV_PCS_AGC_PHASE_OFFSET_I                      = 396,
  NV_PCS_RX_AGC_MIN_11_I                         = 397,
  NV_RUIM_CHV_1_I                                = 398,
  NV_RUIM_CHV_2_I                                = 399,
  NV_GPS1_CAPABILITIES_I                         = 400,
  NV_GPS1_PDE_ADDRESS_I                          = 401,
  NV_GPS1_ALLOWED_I                              = 402,
  NV_GPS1_PDE_TRANSPORT_I                        = 403,
  NV_GPS1_MOBILE_CALC_I                          = 404,
  NV_PREF_FOR_RC_I                               = 405,
  NV_DS_DEFAULT_BAUD_I                           = 406,
  NV_DIAG_DEFAULT_BAUD_I                         = 407,
  NV_SIO_DEV_MAP_MENU_ITEM_I                     = 408,
  NV_TTY_I                                       = 409,
  NV_PA_RANGE_OFFSETS_I                          = 410,
  NV_TX_COMP0_I                                  = 411,
  NV_MM_SDAC_LVL_I                               = 412,
  NV_BEEP_SDAC_LVL_I                             = 413,
  NV_SDAC_LVL_I                                  = 414,
  NV_MM_LVL_I                                    = 415,
  NV_MM_LVL_SHADOW_I                             = 416,
  NV_MM_SPEAKER_LVL_I                            = 417,
  NV_MM_PLAY_MODE_I                              = 418,
  NV_MM_REPEAT_MODE_I                            = 419,
  NV_TX_COMP1_I                                  = 420,
  NV_TX_COMP2_I                                  = 421,
  NV_TX_COMP3_I                                  = 422,
  NV_PRIMARY_DNS_I                               = 423,
  NV_SECONDARY_DNS_I                             = 424,
  NV_DIAG_PORT_SELECT_I                          = 425,
  NV_GPS1_PDE_PORT_I                             = 426,
  NV_MM_RINGER_FILE_I                            = 427,
  NV_MM_STORAGE_DEVICE_I                         = 428,
  NV_DATA_SCRM_ENABLED_I                         = 429,
  NV_RUIM_SMS_STATUS_I                           = 430,
  NV_PCS_TX_LIN_MASTER0_I                        = 431,
  NV_PCS_TX_LIN_MASTER1_I                        = 432,
  NV_PCS_TX_LIN_MASTER2_I                        = 433,
  NV_PCS_TX_LIN_MASTER3_I                        = 434,
  NV_PCS_PA_RANGE_OFFSETS_I                      = 435,
  NV_PCS_TX_COMP0_I                              = 436,
  NV_PCS_TX_COMP1_I                              = 437,
  NV_PCS_TX_COMP2_I                              = 438,
  NV_PCS_TX_COMP3_I                              = 439,
  NV_DIAG_RESTART_CONFIG_I                       = 440,
  NV_BAND_PREF_I                                 = 441,
  NV_ROAM_PREF_I                                 = 442,
  NV_GPS1_GPS_RF_DELAY_I                         = 443,
  NV_GPS1_CDMA_RF_DELAY_I                        = 444,
  NV_PCS_ENC_BTF_I                               = 445,
  NV_CDMA_ENC_BTF_I                              = 446,
  NV_BD_ADDR_I                                   = 447,
  NV_SUBPCG_PA_WARMUP_DELAY_I                    = 448,
  NV_GPS1_GPS_RF_LOSS_I                          = 449,
  NV_DATA_TRTL_ENABLED_I                         = 450,
  NV_AMPS_BACKSTOP_ENABLED_I                     = 451,
  NV_GPS1_LOCK_I                                 = 452,
  NV_FTM_MODE_I                                  = 453,
  NV_DS_DEFAULT_BAUDRATE_I                       = 454,
  NV_DIAG_DEFAULT_BAUDRATE_I                     = 455,
  NV_JCDMA_DS_F92_I                              = 456,
  NV_DS_QCMIP_I                                  = 459,
  NV_DS_MIP_RETRIES_I                            = 460,
  NV_DS_MIP_RETRY_INT_I                          = 461,
  NV_DS_MIP_PRE_RE_RRQ_TIME_I                    = 462,
  NV_DS_MIP_NUM_PROF_I                           = 463,
  NV_DS_MIP_ACTIVE_PROF_I                        = 464,
  NV_DS_MIP_GEN_USER_PROF_I                      = 465,
  NV_DS_MIP_SS_USER_PROF_I                       = 466,
  NV_HDR_CON_SUSPEND_I                           = 467,
  NV_HDR_PRE_CC_CYC_ENABLED_I                    = 468,
  NV_HDR_PRE_CC_CYC_I                            = 469,
  NV_HDR_SRCH_PARAMS_I                           = 470,
  NV_HDRSMP_KEEP_ALIVE_START_I                   = 471,
  NV_HDRSMP_KEEP_ALIVE_SENT_I                    = 472,
  NV_HDRSMP_KEEP_ALIVE_REQ_INT_I                 = 473,
  NV_HDRAMP_ADDRESS_DATA_I                       = 474,
  NV_HDRSCP_SESSION_STATUS_I                     = 475,
  NV_HDRSCP_TOKEN_I                              = 476,
  NV_HDRSCP_PROTOCOL_SUBTYPE_I                   = 477,
  NV_HDRAMP_DUAL_EXPIRE_TIME_I                   = 478,
  NV_HDRSTREAM_CURR_STREAM_CFG_I                 = 479,
  NV_HDR_SET_MNGMT_SAME_CHAN_I                   = 480,
  NV_HDR_SET_MNGMT_DIFF_CHAN_I                   = 481,
  NV_HDRLUP_UNSOLICITED_ENABLED_I                = 482,
  NV_HDRAMAC_INITIAL_CONFIG_I                    = 483,
  NV_HDRAMAC_POWER_PARAMS_I                      = 484,
  NV_HDRFMAC_DRC_GATING_I                        = 485,
  NV_HDRFMAC_HANDOFF_DELAYS_I                    = 486,
  NV_HDRRMAC_POWER_PARAMS_I                      = 487,
  NV_HDRRMAC_RATE_PARAMS_I                       = 488,
  NV_HDRSLP_RESET_SEQNO_I                        = 489,
  NV_PWR_BACKOFF_VS_VOLT_MED_I                   = 490,
  NV_PWR_BACKOFF_VS_VOLT_LOW_I                   = 491,
  NV_PA_BACKOFF_VOLTS_I                          = 492,
  NV_VBATT_MIN_MAX_I                             = 493,
  NV_DS_MIP_MN_HA_TIME_DELTA_I                   = 494,
  NV_DS_MIP_QC_DRS_OPT_I                         = 495,
  NV_ANT2_CDMA_RX_LIN_OFF_0_I                    = 496,
  NV_ANT2_CDMA_RX_LIN_SLP_I                      = 497,
  NV_ANT2_CDMA_RX_COMP_VS_FREQ_I                 = 498,
  NV_ANT2_CDMA_RX_LIN_VS_TEMP_I                  = 499,
  NV_ANT2_CDMA_RX_SLP_VS_TEMP_I                  = 500,
  NV_ANT2_LNA_RANGE_OFFSET_I                     = 501,
  NV_ANT2_LNA_RANGE_12_OFFSET_I                  = 502,
  NV_ANT2_CDMA_LNA_OFFSET_VS_FREQ_I              = 503,
  NV_ANT2_CDMA_LNA_12_OFFSET_VS_FREQ_I           = 504,
  NV_ANT2_PCS_RX_LIN_OFF_0_I                     = 505,
  NV_ANT2_PCS_RX_LIN_SLP_I                       = 506,
  NV_ANT2_PCS_RX_COMP_VS_FREQ_I                  = 507,
  NV_ANT2_PCS_RX_LIN_VS_TEMP_I                   = 508,
  NV_ANT2_PCS_RX_SLP_VS_TEMP_I                   = 509,
  NV_ANT2_PCS_LNA_RANGE_OFFSET_I                 = 510,
  NV_ANT2_PCS_LNA_RANGE_12_OFFSET_I              = 511,
  NV_ANT2_PCS_CDMA_LNA_OFFSET_VS_FREQ_I          = 512,
  NV_ANT2_PCS_CDMA_LNA_12_OFFSET_VS_FREQ_I       = 513,
  NV_WCDMA_RX_LIN_I                              = 514,
  NV_WCDMA_RX_COMP_VS_FREQ_I                     = 515,
  NV_WCDMA_RX_LIN_VS_TEMP_I                      = 516,
  NV_WCDMA_RX_SLP_VS_TEMP_I                      = 517,
  NV_WCDMA_LNA_RANGE_POL_I                       = 518,
  NV_WCDMA_LNA_RANGE_RISE_I                      = 519,
  NV_WCDMA_LNA_RANGE_FALL_I                      = 520,
  NV_WCDMA_IM_LEVEL_I                            = 521,
  NV_WCDMA_NONBYPASS_TIMER_I                     = 522,
  NV_WCDMA_BYPASS_TIMER_I                        = 523,
  NV_WCDMA_LNA_RANGE_OFFSET_I                    = 524,
  NV_WCDMA_LNA_OFFSET_VS_FREQ_I                  = 525,
  NV_WCDMA_RX_AGC_MIN_I                          = 526,
  NV_WCDMA_RX_AGC_MAX_I                          = 527,
  NV_WCDMA_AGC_PHASE_OFFSET_I                    = 528,
  NV_WCDMA_TX_LIN_MASTER_0_I                     = 529,
  NV_WCDMA_TX_LIN_MASTER_1_I                     = 530,
  NV_WCDMA_TX_COMP_VS_FREQ_0_I                   = 531,
  NV_WCDMA_TX_COMP_VS_FREQ_1_I                   = 532,
  NV_WCDMA_TX_LIN_VS_TEMP_0_I                    = 533,
  NV_WCDMA_TX_LIN_VS_TEMP_1_I                    = 534,
  NV_WCDMA_TX_SLP_VS_TEMP_0_I                    = 535,
  NV_WCDMA_TX_SLP_VS_TEMP_1_I                    = 536,
  NV_WCDMA_R1_RISE_I                             = 537,
  NV_WCDMA_R1_FALL_I                             = 538,
  NV_WCDMA_TX_LIM_VS_TEMP_I                      = 539,
  NV_WCDMA_TX_LIM_VS_FREQ_I                      = 540,
  NV_WCDMA_ADJ_FACTOR_I                          = 541,
  NV_WCDMA_EXP_HDET_VS_AGC_I                     = 542,
  NV_WCDMA_HDET_OFF_I                            = 543,
  NV_WCDMA_HDET_SPN_I                            = 544,
  NV_WCDMA_ENC_BTF_I                             = 545,
  NV_DS_MIP_2002BIS_MN_HA_AUTH_I                 = 546,
  NV_UE_RAT_CAPABILITY_I                         = 547,
  NV_GSM_UE_OP_CLASS_I                           = 548,
  NV_UMTS_UE_OP_CLASS_I                          = 549,
  NV_UE_IMEI_I                                   = 550,
  NV_MSRAC_SMS_VALUE_I                           = 551,
  NV_MSRAC_SM_VALUE_I                            = 552,
  NV_GSM_A5_ALGORITHMS_SUPPORTED_I               = 553,
  NV_HDRFMAC_DRC_LOCK_I                          = 554,
  NV_GPS1_LO_CAL_I                               = 555,
  NV_GPS1_ANT_OFF_DB_I                           = 556,
  NV_GPS1_PCS_RF_DELAY_I                         = 557,
  NV_SMS_VM_NUMBER_I                             = 558,
  NV_SMS_GW_PARMS_I                              = 559,
  NV_SMS_GW_I                                    = 561,
  NV_HYBRID_PREF_I                               = 562,
  NV_SP_ECC_ENABLED_I                            = 563,
  NV_ECC_LIST_I                                  = 564,
  NV_BT_LPOS_LAT_I                               = 565,
  NV_BT_LPOS_LONG_I                              = 566,
  NV_TEST_CODE_VER_I                             = 567,
  NV_SYS_SW_VER_I                                = 568,
  NV_RF_CAL_VER_I                                = 569,
  NV_RF_CONFIG_VER_I                             = 570,
  NV_RF_CAL_DATE_I                               = 571,
  NV_RF_NV_LOADED_DATE_I                         = 572,
  NV_RF_CAL_DAT_FILE_I                           = 573,
  NV_DOMAIN_NAME_I                               = 574,
  NV_PREF_PLMN_I                                 = 577,
  NV_HDR_AN_AUTH_NAI_I                           = 579,
  NV_HDR_AN_AUTH_PASSWORD_I                      = 580,
  NV_PUZL_ENABLED_I                              = 581,
  NV_HDRKEP_CONFIG_I                             = 583,
  NV_HDRAUTH_CONFIG_I                            = 584,
  NV_IM_LEVEL3_I                                 = 585,
  NV_IM_LEVEL4_I                                 = 586,
  NV_AGC_VALUE_3_MIN_I                           = 587,
  NV_AGC_VALUE_4_MIN_I                           = 588,
  NV_TX_GAIN_ATTEN_LIMIT_I                       = 589,
  NV_CDMA_LNA_3_FALL_I                           = 590,
  NV_CDMA_LNA_3_OFFSET_I                         = 591,
  NV_CDMA_LNA_3_RISE_I                           = 592,
  NV_CDMA_LNA_3_OFFSET_VS_FREQ_I                 = 593,
  NV_PCS_LNA_3_FALL_I                            = 594,
  NV_PCS_LNA_3_OFFSET_I                          = 595,
  NV_PCS_LNA_3_RISE_I                            = 596,
  NV_PCS_LNA_3_OFFSET_VS_FREQ_I                  = 597,
  NV_CDMA_LNA_4_FALL_I                           = 598,
  NV_CDMA_LNA_4_OFFSET_I                         = 599,
  NV_CDMA_LNA_4_RISE_I                           = 600,
  NV_CDMA_LNA_4_OFFSET_VS_FREQ_I                 = 601,
  NV_PCS_LNA_4_FALL_I                            = 602,
  NV_PCS_LNA_4_OFFSET_I                          = 603,
  NV_PCS_LNA_4_RISE_I                            = 604,
  NV_PCS_LNA_4_OFFSET_VS_FREQ_I                  = 605,
  NV_DFM_LNA_FALL_I                              = 606,
  NV_DFM_LNA_OFFSET_I                            = 607,
  NV_DFM_LNA_RISE_I                              = 608,
  NV_DFM_LNA_OFFSET_VS_FREQ_I                    = 609,
  NV_DFM_AGC_ACC_MIN_1_I                         = 610,
  NV_DFM_AGC_IM_GAIN_I                           = 611,
  NV_DFM_AGC_DC_GAIN_I                           = 612,
  NV_DFM_IM_LEVEL1_I                             = 613,
  NV_GPS_FG_TRK_OFFSET_SCALER_I                  = 614,
  NV_DIGITAL_FG_TRK_OFFSET_SCALER_I              = 615,
  NV_FM_FG_TRK_OFFSET_SCALER_I                   = 616,
  NV_DFM_LNA_S0_PHASE_OFFSET_I                   = 617,
  NV_DFM_LNA_S1_PHASE_OFFSET_I                   = 618,
  NV_CDMA_RXF_CG_IOFFSET_I                       = 619,
  NV_PCS_RXF_CG_IOFFSET_I                        = 620,
  NV_FM_RXF_CG_IOFFSET_I                         = 621,
  NV_GPS_RXF_CG_IOFFSET_I                        = 622,
  NV_CDMA_RXF_CG_QOFFSET_I                       = 623,
  NV_PCS_RXF_CG_QOFFSET_I                        = 624,
  NV_FM_RXF_CG_QOFFSET_I                         = 625,
  NV_GPS_RXF_CG_QOFFSET_I                        = 626,
  NV_CDMA_RXF_FG_IOFFSET_I                       = 627,
  NV_PCS_RXF_FG_IOFFSET_I                        = 628,
  NV_FM_RXF_FG_IOFFSET_I                         = 629,
  NV_GPS_RXF_FG_IOFFSET_I                        = 630,
  NV_CDMA_RXF_FG_QOFFSET_I                       = 631,
  NV_PCS_RXF_FG_QOFFSET_I                        = 632,
  NV_FM_RXF_FG_QOFFSET_I                         = 633,
  NV_GPS_RXF_FG_QOFFSET_I                        = 634,
  NV_CDMA_DACC_EST_IOFFSET_I                     = 635,
  NV_PCS_DACC_EST_IOFFSET_I                      = 636,
  NV_FM_DACC_EST_IOFFSET_I                       = 637,
  NV_GPS_DACC_EST_IOFFSET_I                      = 638,
  NV_CDMA_DACC_EST_QOFFSET_I                     = 639,
  NV_PCS_DACC_EST_QOFFSET_I                      = 640,
  NV_FM_DACC_EST_QOFFSET_I                       = 641,
  NV_GPS_DACC_EST_QOFFSET_I                      = 642,
  NV_CDMA_DACC_IACCUM0_I                         = 643,
  NV_PCS_DACC_IACCUM0_I                          = 644,
  NV_FM_DACC_IACCUM0_I                           = 645,
  NV_GPS_DACC_IACCUM0_I                          = 646,
  NV_CDMA_DACC_IACCUM1_I                         = 647,
  NV_PCS_DACC_IACCUM1_I                          = 648,
  NV_FM_DACC_IACCUM1_I                           = 649,
  NV_GPS_DACC_IACCUM1_I                          = 650,
  NV_CDMA_DACC_IACCUM2_I                         = 651,
  NV_PCS_DACC_IACCUM2_I                          = 652,
  NV_FM_DACC_IACCUM2_I                           = 653,
  NV_GPS_DACC_IACCUM2_I                          = 654,
  NV_CDMA_DACC_IACCUM3_I                         = 655,
  NV_PCS_DACC_IACCUM3_I                          = 656,
  NV_FM_DACC_IACCUM3_I                           = 657,
  NV_GPS_DACC_IACCUM3_I                          = 658,
  NV_CDMA_DACC_IACCUM4_I                         = 659,
  NV_PCS_DACC_IACCUM4_I                          = 660,
  NV_FM_DACC_IACCUM4_I                           = 661,
  NV_GPS_DACC_IACCUM4_I                          = 662,
  NV_CDMA_DACC_QACCUM0_I                         = 663,
  NV_PCS_DACC_QACCUM0_I                          = 664,
  NV_FM_DACC_QACCUM0_I                           = 665,
  NV_GPS_DACC_QACCUM0_I                          = 666,
  NV_CDMA_DACC_QACCUM1_I                         = 667,
  NV_PCS_DACC_QACCUM1_I                          = 668,
  NV_FM_DACC_QACCUM1_I                           = 669,
  NV_GPS_DACC_QACCUM1_I                          = 670,
  NV_CDMA_DACC_QACCUM2_I                         = 671,
  NV_PCS_DACC_QACCUM2_I                          = 672,
  NV_FM_DACC_QACCUM2_I                           = 673,
  NV_GPS_DACC_QACCUM2_I                          = 674,
  NV_CDMA_DACC_QACCUM3_I                         = 675,
  NV_PCS_DACC_QACCUM3_I                          = 676,
  NV_FM_DACC_QACCUM3_I                           = 677,
  NV_GPS_DACC_QACCUM3_I                          = 678,
  NV_CDMA_DACC_QACCUM4_I                         = 679,
  NV_PCS_DACC_QACCUM4_I                          = 680,
  NV_FM_DACC_QACCUM4_I                           = 681,
  NV_GPS_DACC_QACCUM4_I                          = 682,
  NV_CDMA_DACC_GAIN_MULT_I                       = 683,
  NV_PCS_DACC_GAIN_MULT_I                        = 684,
  NV_FM_DACC_GAIN_MULT_I                         = 685,
  NV_GPS_DACC_GAIN_MULT_I                        = 686,
  NV_CDMA_IM2_I_VALUE_I                          = 687,
  NV_PCS_IM2_I_VALUE_I                           = 688,
  NV_CDMA_IM2_Q_VALUE_I                          = 689,
  NV_PCS_IM2_Q_VALUE_I                           = 690,
  NV_RTC_TIME_ADJUST_I                           = 691,
  NV_FM_VGA_GAIN_OFFSET_I                        = 692,
  NV_CDMA_VGA_GAIN_OFFSET_I                      = 693,
  NV_PCS_VGA_GAIN_OFFSET_I                       = 694,
  NV_FM_VGA_GAIN_OFFSET_VS_FREQ_I                = 695,
  NV_CDMA_VGA_GAIN_OFFSET_VS_FREQ_I              = 696,
  NV_PCS_VGA_GAIN_OFFSET_VS_FREQ_I               = 697,
  NV_FM_VGA_GAIN_OFFSET_VS_TEMP_I                = 698,
  NV_CDMA_VGA_GAIN_OFFSET_VS_TEMP_I              = 699,
  NV_PCS_VGA_GAIN_OFFSET_VS_TEMP_I               = 700,
  NV_FM_MIS_COMP_A_OFFSET_I                      = 701,
  NV_DIGITAL_MIS_COMP_A_OFFSET_I                 = 702,
  NV_GPS_MIS_COMP_A_OFFSET_I                     = 703,
  NV_FM_MIS_COMP_B_OFFSET_I                      = 704,
  NV_DIGITAL_MIS_COMP_B_OFFSET_I                 = 705,
  NV_GPS_MIS_COMP_B_OFFSET_I                     = 706,
  NV_DS_MIP_RRQ_IF_TFRK_I                        = 707,
  NV_COLLOC_DISALLOWED_TIME_I                    = 708,
  NV_HOLD_HDR_TIME_I                             = 709,
  NV_LO_BIAS_UPDATE_CNT_I                        = 710,
  NV_HDRSCP_AN_AUTH_STATUS_I                     = 712,
  NV_IMSI_INDEX_I                                = 713,
  NV_DS_MIP_ENABLE_PROF_I                        = 714,
  NV_PCS_IM_LEVEL3_I                             = 715,
  NV_PCS_IM_LEVEL4_I                             = 716,
  NV_PCS_AGC_VALUE_3_MIN_I                       = 717,
  NV_PCS_AGC_VALUE_4_MIN_I                       = 718,
  NV_HDRSMPKA_START_TIME_I                       = 719,
  NV_HDRSMPKA_SENT_TIME_I                        = 720,
  NV_SMS_BC_SERVICE_TABLE_OPTIONS_I              = 721,
  NV_ACQ_DB_I                                    = 722,
  NV_ACQ_LIST_1_I                                = 723,
  NV_GSM_CAL_ARFCN_I                             = 724,
  NV_DCS_CAL_ARFCN_I                             = 725,
  NV_GSM_RX_GAIN_RANGE_1_FREQ_COMP_I             = 726,
  NV_GSM_RX_GAIN_RANGE_2_FREQ_COMP_I             = 727,
  NV_GSM_RX_GAIN_RANGE_3_FREQ_COMP_I             = 728,
  NV_GSM_RX_GAIN_RANGE_4_FREQ_COMP_I             = 729,
  NV_DCS_RX_GAIN_RANGE_1_FREQ_COMP_I             = 730,
  NV_DCS_RX_GAIN_RANGE_2_FREQ_COMP_I             = 731,
  NV_DCS_RX_GAIN_RANGE_3_FREQ_COMP_I             = 732,
  NV_DCS_RX_GAIN_RANGE_4_FREQ_COMP_I             = 733,
  NV_GSM_TRK_LO_ADJ_PDM_INIT_VAL_I               = 734,
  NV_GSM_TRK_LO_ADJ_PDM_GAIN_SLOPE_I             = 735,
  NV_GPS_DOPP_SDEV_I                             = 736,
  NV_ACQ_LIST_2_I                                = 737,
  NV_ACQ_LIST_3_I                                = 738,
  NV_ACQ_LIST_4_I                                = 739,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_00_I             = 740,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_01_I             = 741,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_02_I             = 742,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_03_I             = 743,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_04_I             = 744,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_05_I             = 745,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_06_I             = 746,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_07_I             = 747,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_08_I             = 748,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_09_I             = 749,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_10_I             = 750,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_11_I             = 751,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_12_I             = 752,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_13_I             = 753,
  NV_GSM_TX_BURST_RAMP_UP_INDEX_14_I             = 754,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_00_I           = 755,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_01_I           = 756,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_02_I           = 757,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_03_I           = 758,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_04_I           = 759,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_05_I           = 760,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_06_I           = 761,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_07_I           = 762,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_08_I           = 763,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_09_I           = 764,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_10_I           = 765,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_11_I           = 766,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_12_I           = 767,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_13_I           = 768,
  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_14_I           = 769,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_00_I             = 770,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_01_I             = 771,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_02_I             = 772,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_03_I             = 773,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_04_I             = 774,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_05_I             = 775,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_06_I             = 776,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_07_I             = 777,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_08_I             = 778,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_09_I             = 779,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_10_I             = 780,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_11_I             = 781,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_12_I             = 782,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_13_I             = 783,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_14_I             = 784,
  NV_DCS_TX_BURST_RAMP_UP_INDEX_15_I             = 785,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_00_I           = 786,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_01_I           = 787,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_02_I           = 788,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_03_I           = 789,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_04_I           = 790,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_05_I           = 791,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_06_I           = 792,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_07_I           = 793,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_08_I           = 794,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_09_I           = 795,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_10_I           = 796,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_11_I           = 797,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_12_I           = 798,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_13_I           = 799,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_14_I           = 800,
  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_15_I           = 801,
  NV_GSM_PA_GAIN_SLOPE_I                         = 802,
  NV_DCS_PA_GAIN_SLOPE_I                         = 803,
  NV_GSM_TX_FREQ_COMP_I                          = 804,
  NV_DCS_TX_FREQ_COMP_I                          = 805,
  NV_GSM_VBATT_HI_PA_COMP_I                      = 806,
  NV_GSM_VBATT_LO_PA_COMP_I                      = 807,
  NV_DCS_VBATT_HI_PA_COMP_I                      = 808,
  NV_DCS_VBATT_LO_PA_COMP_I                      = 809,
  NV_VBATT_3200_MV_ADC_I                         = 810,
  NV_VBATT_3700_MV_ADC_I                         = 811,
  NV_VBATT_4200_MV_ADC_I                         = 812,
  NV_GSM_PRECHARGE_I                             = 813,
  NV_DCS_PRECHARGE_I                             = 814,
  NV_GSM_PRECHARGE_DUR_I                         = 815,
  NV_DCS_PRECHARGE_DUR_I                         = 816,
  NV_DIGITAL_PLL_LOCK_TIMER_I                    = 817,
  NV_HDR_RX_DIVERSITY_CTRL_I                     = 818,
  NV_GSM_PA_START_TIME_OFFSET_I                  = 819,
  NV_GSM_PA_STOP_TIME_OFFSET_I                   = 820,
  NV_DCS_PA_START_TIME_OFFSET_I                  = 821,
  NV_DCS_PA_STOP_TIME_OFFSET_I                   = 822,
  NV_GPS1_PRIVACY_I                              = 823,
  NV_GPS1_NET_ACCESS_I                           = 824,
  NV_GPS1_CELLBASED_SMS_I                        = 825,
  NV_GPS1_TELESERVICE_ID_I                       = 826,
  NV_HDRRUP_SRCH_PARAMS_I                        = 827,
  NV_DFM_LNA_BYPASS_TIMER_I                      = 828,
  NV_DFM_LNA_NONBYPASS_TIMER_I                   = 829,
  NV_SMS_CFG_ROUTING_I                           = 830,
  NV_GPS1_NET_DBM_SIZE_I                         = 831,
  NV_HDR_DO_NOT_DISTURB_I                        = 832,
  NV_CDMA_TX_GAIN_ATTEN_LIMIT_I                  = 833,
  NV_PCS_TX_GAIN_ATTEN_LIMIT_I                   = 834,
  NV_AMPS_TX_GAIN_ATTEN_LIMIT_I                  = 835,
  NV_GPS_TX_GAIN_ATTEN_LIMIT_I                   = 836,
  NV_CDMA_IM2_TRANSCONDUCTOR_VALUE_I             = 837,
  NV_PCS_IM2_TRANSCONDUCTOR_VALUE_I              = 838,
  NV_LNA_NON_BYPASS_TIMER_0_I                    = 839,
  NV_LNA_NON_BYPASS_TIMER_1_I                    = 840,
  NV_LNA_NON_BYPASS_TIMER_2_I                    = 841,
  NV_LNA_NON_BYPASS_TIMER_3_I                    = 842,
  NV_LNA_BYPASS_TIMER_0_I                        = 843,
  NV_LNA_BYPASS_TIMER_1_I                        = 844,
  NV_LNA_BYPASS_TIMER_2_I                        = 845,
  NV_LNA_BYPASS_TIMER_3_I                        = 846,
  NV_SMS_CD_PARMS_I                              = 847,
  NV_ACQ_ORDER_PREF_I                            = 848,
  NV_NET_SEL_MODE_PREF_I                         = 849,
  NV_SERVICE_DOMAIN_PREF_I                       = 850,
  NV_PPP_AUTHENTICATION_I                        = 851,
  NV_APN_NAME_I                                  = 852,
  NV_EQUIVALENT_PLMN_LIST_I                      = 853,
  NV_DS_MIP_DMU_PKOID_I                          = 854,
  NV_RTRE_CONFIG_I                               = 855,
  NV_WCDMA_VGA_GAIN_OFFSET_I                     = 856,
  NV_WCDMA_VGA_GAIN_OFFSET_VS_FREQ_I             = 857,
  NV_WCDMA_VGA_GAIN_OFFSET_VS_TEMP_I             = 858,
  NV_WCDMA_LNA_RANGE_RISE_2_I                    = 859,
  NV_WCDMA_LNA_RANGE_RISE_3_I                    = 860,
  NV_WCDMA_LNA_RANGE_FALL_2_I                    = 861,
  NV_WCDMA_LNA_RANGE_FALL_3_I                    = 862,
  NV_WCDMA_IM_LEVEL_2_I                          = 863,
  NV_WCDMA_IM_LEVEL_3_I                          = 864,
  NV_WCDMA_LNA_RANGE_OFFSET_2_I                  = 865,
  NV_WCDMA_LNA_RANGE_OFFSET_3_I                  = 866,
  NV_WCDMA_LNA_OFFSET_VS_FREQ_2_I                = 867,
  NV_WCDMA_LNA_OFFSET_VS_FREQ_3_I                = 868,
  NV_WCDMA_IM2_I_VALUE_I                         = 869,
  NV_WCDMA_IM2_Q_VALUE_I                         = 870,
  NV_WCDMA_IM2_TRANSCONDUCTOR_VALUE_I            = 871,
  NV_WCDMA_RX_AGC_MIN_2_I                        = 872,
  NV_WCDMA_RX_AGC_MIN_3_I                        = 873,
  NV_WCDMA_VBATT_I                               = 874,
  NV_WCDMA_THERM_I                               = 875,
  NV_WCDMA_MAX_TX_POWER_I                        = 876,
  NV_FM_PA_MAC_HIGH_I                            = 877,
  NV_CDMA_DYNAMIC_RANGE_I                        = 878,
  NV_CDMA_MIN_RX_RSSI_I                          = 879,
  NV_RRC_INTEGRITY_ENABLED_I                     = 880,
  NV_RRC_CIPHERING_ENABLED_I                     = 881,
  NV_RRC_FAKE_SECURITY_ENABLED_I                 = 882,
  NV_CDMA_POWERUP_REG_PERFORMED_I                = 883,
  NV_TX_WARMUP_I                                 = 884,
  NV_LAST_TX_DATA_COUNT_I                        = 885,
  NV_LAST_RX_DATA_COUNT_I                        = 886,
  NV_TOTAL_TX_DATA_COUNT_I                       = 887,
  NV_TOTAL_RX_DATA_COUNT_I                       = 888,
  NV_DS_MIP_DMU_MN_AUTH_I                        = 889,
  NV_USB_PRODUCT_ID_OFFSET_I                     = 890,
  NV_AVCD_CALL_DURATION_I                        = 891,
  NV_AVCD_TIME_BETWEEN_CALLS_I                   = 892,
  NV_AVCD_NUMBER_OF_CALLS_I                      = 893,
  NV_AVCD_SO_I                                   = 894,
  NV_WCDMA_OUT_OF_SERVICE_THRESH_I               = 895,
  NV_UIM_FIRST_INST_CLASS_I                      = 896,
  NV_HDRRUP_OVERRIDE_ALLOWED_I                   = 897,
  NV_JCDMA_M511_MODE_I                           = 898,
  NV_JCDMA_M512_MODE_I                           = 899,
  NV_JCDMA_M513_MODE_I                           = 900,
  NV_CDMA_P1_RISE_FALL_OFF_I                     = 901,
  NV_PCS_P1_RISE_FALL_OFF_I                      = 902,
  NV_GSM_LOCIGPRS_I                              = 903,
  NV_GSM_KCGPRS_I                                = 904,
  NV_ERR_FATAL_OPTIONS_I                         = 905,
  NV_PPP_PASSWORD_I                              = 906,
  NV_TRK_LO_ADJ_VS_TEMP_I                        = 907,
  NV_ROT_FREQ_VS_TEMP_I                          = 908,
  NV_SMS_GW_BEARER_PREF_I                        = 909,
  NV_PPP_USER_ID_I                               = 910,
  NV_MULTISLOT_CLASS_I                           = 911,
  NV_NON_DRX_TIMER_I                             = 912,
  NV_SPLIT_PAGING_CYCLE_I                        = 913,
  NV_UIM_PREF_PROTOCOL_I                         = 914,
  NV_WCDMACS_SYNC_TEST_APP_ENABLED_I             = 915,
  NV_GSM_GAINRANGE_SWITCHPOINTS_I                = 916,
  NV_DCS_GAINRANGE_SWITCHPOINTS_I                = 917,
  NV_HDR_AN_PPP_USER_ID_I                        = 919,
  NV_HDR_AN_PPP_PASSWORD_I                       = 920,
  NV_JTACS_PCDMACH_I                             = 921,
  NV_JTACS_SCDMACH_I                             = 922,
  NV_GSMUMTS_IMSI_I                              = 923,
  NV_RTSP_PROXY_SERVER_ADDR_I                    = 924,
  NV_SMS_GW_DEFAULT_TEMPLATE_I                   = 925,
  NV_SMS_CD_DEFAULT_TEMPLATE_I                   = 926,
  NV_NON_COMPLIANCE_COMMENT_I                    = 927,
  NV_HYSTERISIS_ACTIVATION_TIMER_I               = 928,
  NV_HYSTERISIS_TIMER_I                          = 929,
  NV_PKT_DIAL_STRINGS_I                          = 930,
  NV_VCO_COARSE_TUNE_TABLE_I                     = 931,
  NV_DATA_INCOMING_CSD_CALL_IS_INTERNAL_I        = 932,
  NV_DF_I                                        = 933,
  NV_GSM_PA_TEMP_COMP_INDEX_14_I                 = 934,
  NV_DCS_PA_TEMP_COMP_INDEX_15_I                 = 935,
  NV_RF_TEST_ITEM_1_I                            = 936,
  NV_RF_TEST_ITEM_2_I                            = 937,
  NV_NEG_SLOT_CYCLE_INDEX_I                      = 938,
  NV_BTFD_OLPC_FLOOR_DB_I                        = 939,
  NV_NON_BTFD_OLPC_FLOOR_DB_I                    = 940,
  NV_SSPR_P_REV_I                                = 941,
  NV_RTSP_PROXY_SERVER_ADDR_ALTERNATE_I          = 942,
  NV_UIM_CDMA_PREF_SLOT_I                        = 943,
  NV_UIM_GSM_PREF_SLOT_I                         = 944,
  NV_MRU3_TABLE_I                                = 945,
  NV_BAND_PREF_16_31_I                           = 946,
  NV_GPRS_ANITE_GCF_I                            = 947,
  NV_C1_CDMA_LNA_OFFSET_I                        = 948,
  NV_C1_CDMA_LNA_OFFSET_VS_FREQ_I                = 949,
  NV_C1_PCS_LNA_OFFSET_I                         = 950,
  NV_C1_PCS_LNA_OFFSET_VS_FREQ_I                 = 951,
  NV_C1_CDMA_LNA_2_OFFSET_I                      = 952,
  NV_C1_CDMA_LNA_2_OFFSET_VS_FREQ_I              = 953,
  NV_C1_PCS_LNA_2_OFFSET_I                       = 954,
  NV_C1_PCS_LNA_2_OFFSET_VS_FREQ_I               = 955,
  NV_C1_CDMA_LNA_3_OFFSET_I                      = 956,
  NV_C1_CDMA_LNA_3_OFFSET_VS_FREQ_I              = 957,
  NV_C1_PCS_LNA_3_OFFSET_I                       = 958,
  NV_C1_PCS_LNA_3_OFFSET_VS_FREQ_I               = 959,
  NV_C1_CDMA_LNA_4_OFFSET_I                      = 960,
  NV_C1_CDMA_LNA_4_OFFSET_VS_FREQ_I              = 961,
  NV_C1_PCS_LNA_4_OFFSET_I                       = 962,
  NV_C1_PCS_LNA_4_OFFSET_VS_FREQ_I               = 963,
  NV_C1_CDMA_P1_RISE_FALL_OFFSET_I               = 964,
  NV_C1_PCS_P1_RISE_FALL_OFFSET_I                = 965,
  NV_C1_RX_AGC_VALUE_1_MINMAX_I                  = 966,
  NV_C1_RX_AGC_VALUE_2_MINMAX_I                  = 967,
  NV_C1_RX_AGC_VALUE_3_MINMAX_I                  = 968,
  NV_C1_RX_AGC_VALUE_4_MINMAX_I                  = 969,
  NV_C0_RX_AGC_VREF_VAL_I                        = 970,
  NV_C1_RX_AGC_VREF_VAL_I                        = 971,
  NV_C0_GRP_DELAY_ADJ_I                          = 972,
  NV_C1_GRP_DELAY_ADJ_I                          = 973,
  NV_C1_CDMA_VGA_GAIN_OFFSET_I                   = 974,
  NV_C1_CDMA_VGA_GAIN_OFFSET_VS_FREQ_I           = 975,
  NV_C1_CDMA_VGA_GAIN_OFFSET_VS_TEMP_I           = 976,
  NV_C1_PCS_VGA_GAIN_OFFSET_I                    = 977,
  NV_C1_PCS_VGA_GAIN_OFFSET_VS_FREQ_I            = 978,
  NV_C1_PCS_VGA_GAIN_OFFSET_VS_TEMP_I            = 979,
  NV_C1_DIGITAL_MIS_COMP_A_OFFSET_I              = 980,
  NV_C1_GPS_MIS_COMP_A_OFFSET_I                  = 981,
  NV_C1_DIGITAL_MIS_COMP_B_OFFSET_I              = 982,
  NV_C1_GPS_MIS_COMP_B_OFFSET_I                  = 983,
  NV_C1_CDMA_DACC_IACCUM0_I                      = 984,
  NV_C1_PCS_DACC_IACCUM0_I                       = 985,
  NV_C1_GPS_DACC_IACCUM0_I                       = 986,
  NV_C1_CDMA_DACC_IACCUM1_I                      = 987,
  NV_C1_PCS_DACC_IACCUM1_I                       = 988,
  NV_C1_GPS_DACC_IACCUM1_I                       = 989,
  NV_C1_CDMA_DACC_IACCUM2_I                      = 990,
  NV_C1_PCS_DACC_IACCUM2_I                       = 991,
  NV_C1_GPS_DACC_IACCUM2_I                       = 992,
  NV_C1_CDMA_DACC_IACCUM3_I                      = 993,
  NV_C1_PCS_DACC_IACCUM3_I                       = 994,
  NV_C1_GPS_DACC_IACCUM3_I                       = 995,
  NV_C1_CDMA_DACC_IACCUM4_I                      = 996,
  NV_C1_PCS_DACC_IACCUM4_I                       = 997,
  NV_C1_GPS_DACC_IACCUM4_I                       = 998,
  NV_C1_CDMA_DACC_QACCUM0_I                      = 999,
  NV_C1_PCS_DACC_QACCUM0_I                       = 1000,
  NV_C1_GPS_DACC_QACCUM0_I                       = 1001,
  NV_C1_CDMA_DACC_QACCUM1_I                      = 1002,
  NV_C1_PCS_DACC_QACCUM1_I                       = 1003,
  NV_C1_GPS_DACC_QACCUM1_I                       = 1004,
  NV_C1_CDMA_DACC_QACCUM2_I                      = 1005,
  NV_C1_PCS_DACC_QACCUM2_I                       = 1006,
  NV_C1_GPS_DACC_QACCUM2_I                       = 1007,
  NV_C1_CDMA_DACC_QACCUM3_I                      = 1008,
  NV_C1_PCS_DACC_QACCUM3_I                       = 1009,
  NV_C1_GPS_DACC_QACCUM3_I                       = 1010,
  NV_C1_CDMA_DACC_QACCUM4_I                      = 1011,
  NV_C1_PCS_DACC_QACCUM4_I                       = 1012,
  NV_C1_GPS_DACC_QACCUM4_I                       = 1013,
  NV_SMS_GW_CB_SERVICE_TABLE_I                   = 1014,
  NV_SMS_GW_CB_SERVICE_TABLE_SIZE_I              = 1015,
  NV_SMS_GW_CB_CONFIG_I                          = 1016,
  NV_SMS_GW_CB_USER_PREF_I                       = 1017,
  NV_CDMA_RX_DIVERSITY_CTRL_I                    = 1018,
  NV_LONG_PDPACT_TOLERANCE_FOR_TE_I              = 1019,
  NV_C1_CDMA_IM2_Q_VALUE_I                       = 1020,
  NV_C1_PCS_IM2_Q_VALUE_I                        = 1021,
  NV_C1_CDMA_IM2_I_VALUE_I                       = 1022,
  NV_C1_PCS_IM2_I_VALUE_I                        = 1023,
  NV_C1_CDMA_IM2_TRANSCONDUCTOR_VALUE_I          = 1024,
  NV_C1_PCS_IM2_TRANSCONDUCTOR_VALUE_I           = 1025,
  NV_C1_VCO_COARSE_TUNE_TABLE_I                  = 1026,
  NV_MDSP_MEM_DUMP_ENABLED_I                     = 1027,
  NV_GSM_850_PA_TEMP_COMP_INDEX_14_I             = 1028,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_15_I            = 1029,
  NV_FORCE_UE_SGSNR_R99_I                        = 1030,
  NV_FORCE_UE_MSCR_R99_I                         = 1031,
  NV_GPS_RF_CONFIG_I                             = 1032,
  NV_C1_CDMA_LNA_1_RISE_I                        = 1033,
  NV_C1_CDMA_LNA_2_RISE_I                        = 1034,
  NV_C1_CDMA_LNA_3_RISE_I                        = 1035,
  NV_C1_CDMA_LNA_4_RISE_I                        = 1036,
  NV_C1_PCS_LNA_1_RISE_I                         = 1037,
  NV_C1_PCS_LNA_2_RISE_I                         = 1038,
  NV_C1_PCS_LNA_3_RISE_I                         = 1039,
  NV_C1_PCS_LNA_4_RISE_I                         = 1040,
  NV_C1_CDMA_LNA_1_FALL_I                        = 1041,
  NV_C1_CDMA_LNA_2_FALL_I                        = 1042,
  NV_C1_CDMA_LNA_3_FALL_I                        = 1043,
  NV_C1_CDMA_LNA_4_FALL_I                        = 1044,
  NV_C1_PCS_LNA_1_FALL_I                         = 1045,
  NV_C1_PCS_LNA_2_FALL_I                         = 1046,
  NV_C1_PCS_LNA_3_FALL_I                         = 1047,
  NV_C1_PCS_LNA_4_FALL_I                         = 1048,
  NV_C1_CDMA_IM_LEVEL1_I                         = 1049,
  NV_C1_CDMA_IM_LEVEL2_I                         = 1050,
  NV_C1_CDMA_IM_LEVEL3_I                         = 1051,
  NV_C1_CDMA_IM_LEVEL4_I                         = 1052,
  NV_C1_PCS_IM_LEVEL1_I                          = 1053,
  NV_C1_PCS_IM_LEVEL2_I                          = 1054,
  NV_C1_PCS_IM_LEVEL3_I                          = 1055,
  NV_C1_PCS_IM_LEVEL4_I                          = 1056,
  NV_GSM_1900_CAL_ARFCN_I                        = 1057,
  NV_GSM_1900_RX_GAIN_RANGE_1_FREQ_COMP_I        = 1058,
  NV_GSM_1900_RX_GAIN_RANGE_2_FREQ_COMP_I        = 1059,
  NV_GSM_1900_RX_GAIN_RANGE_3_FREQ_COMP_I        = 1060,
  NV_GSM_1900_RX_GAIN_RANGE_4_FREQ_COMP_I        = 1061,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_00_I        = 1062,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_01_I        = 1063,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_02_I        = 1064,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_03_I        = 1065,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_04_I        = 1066,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_05_I        = 1067,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_06_I        = 1068,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_07_I        = 1069,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_08_I        = 1070,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_09_I        = 1071,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_10_I        = 1072,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_11_I        = 1073,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_12_I        = 1074,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_13_I        = 1075,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_14_I        = 1076,
  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_15_I        = 1077,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_00_I      = 1078,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_01_I      = 1079,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_02_I      = 1080,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_03_I      = 1081,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_04_I      = 1082,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_05_I      = 1083,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_06_I      = 1084,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_07_I      = 1085,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_08_I      = 1086,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_09_I      = 1087,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_10_I      = 1088,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_11_I      = 1089,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_12_I      = 1090,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_13_I      = 1091,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_14_I      = 1092,
  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_15_I      = 1093,
  NV_GSM_1900_PA_GAIN_SLOPE_I                    = 1094,
  NV_GSM_1900_TX_FREQ_COMP_I                     = 1095,
  NV_GSM_1900_VBATT_HI_PA_COMP_I                 = 1096,
  NV_GSM_1900_VBATT_LO_PA_COMP_I                 = 1097,
  NV_GSM_1900_PA_START_TIME_OFFSET_I             = 1098,
  NV_GSM_1900_PA_STOP_TIME_OFFSET_I              = 1099,
  NV_GSM_1900_GAINRANGE_SWITCHPOINTS_I           = 1100,
  NV_GSM_850_CAL_ARFCN_I                         = 1101,
  NV_GSM_850_RX_GAIN_RANGE_1_FREQ_COMP_I         = 1102,
  NV_GSM_850_RX_GAIN_RANGE_2_FREQ_COMP_I         = 1103,
  NV_GSM_850_RX_GAIN_RANGE_3_FREQ_COMP_I         = 1104,
  NV_GSM_850_RX_GAIN_RANGE_4_FREQ_COMP_I         = 1105,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_00_I         = 1106,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_01_I         = 1107,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_02_I         = 1108,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_03_I         = 1109,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_04_I         = 1110,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_05_I         = 1111,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_06_I         = 1112,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_07_I         = 1113,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_08_I         = 1114,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_09_I         = 1115,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_10_I         = 1116,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_11_I         = 1117,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_12_I         = 1118,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_13_I         = 1119,
  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_14_I         = 1120,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_00_I       = 1121,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_01_I       = 1122,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_02_I       = 1123,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_03_I       = 1124,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_04_I       = 1125,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_05_I       = 1126,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_06_I       = 1127,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_07_I       = 1128,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_08_I       = 1129,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_09_I       = 1130,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_10_I       = 1131,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_11_I       = 1132,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_12_I       = 1133,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_13_I       = 1134,
  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_14_I       = 1135,
  NV_GSM_850_PA_GAIN_SLOPE_I                     = 1136,
  NV_GSM_850_TX_FREQ_COMP_I                      = 1137,
  NV_GSM_850_VBATT_HI_PA_COMP_I                  = 1138,
  NV_GSM_850_VBATT_LO_PA_COMP_I                  = 1139,
  NV_GSM_850_PA_START_TIME_OFFSET_I              = 1140,
  NV_GSM_850_PA_STOP_TIME_OFFSET_I               = 1141,
  NV_GSM_850_GAINRANGE_SWITCHPOINTS_I            = 1142,
  NV_WCDMA_1900_VGA_GAIN_OFFSET_I                = 1143,
  NV_WCDMA_1900_VGA_GAIN_OFFSET_VS_FREQ_I        = 1144,
  NV_WCDMA_1900_VGA_GAIN_OFFSET_VS_TEMP_I        = 1145,
  NV_WCDMA_1900_LNA_RANGE_RISE_2_I               = 1146,
  NV_WCDMA_1900_LNA_RANGE_RISE_3_I               = 1147,
  NV_WCDMA_1900_LNA_RANGE_FALL_2_I               = 1148,
  NV_WCDMA_1900_LNA_RANGE_FALL_3_I               = 1149,
  NV_WCDMA_1900_IM_LEVEL_2_I                     = 1150,
  NV_WCDMA_1900_IM_LEVEL_3_I                     = 1151,
  NV_WCDMA_1900_LNA_RANGE_OFFSET_2_I             = 1152,
  NV_WCDMA_1900_LNA_RANGE_OFFSET_3_I             = 1153,
  NV_WCDMA_1900_LNA_OFFSET_VS_FREQ_2_I           = 1154,
  NV_WCDMA_1900_LNA_OFFSET_VS_FREQ_3_I           = 1155,
  NV_WCDMA_1900_IM2_I_VALUE_I                    = 1156,
  NV_WCDMA_1900_IM2_Q_VALUE_I                    = 1157,
  NV_WCDMA_1900_IM2_TRANSCONDUCTOR_VALUE_I       = 1158,
  NV_WCDMA_1900_RX_AGC_MIN_2_I                   = 1159,
  NV_WCDMA_1900_RX_AGC_MIN_3_I                   = 1160,
  NV_WCDMA_1900_MAX_TX_POWER_I                   = 1161,
  NV_WCDMA_1900_OUT_OF_SERVICE_THRESH_I          = 1162,
  NV_WCDMA_1900_LNA_RANGE_RISE_I                 = 1163,
  NV_WCDMA_1900_LNA_RANGE_FALL_I                 = 1164,
  NV_WCDMA_1900_IM_LEVEL_I                       = 1165,
  NV_WCDMA_1900_NONBYPASS_TIMER_I                = 1166,
  NV_WCDMA_1900_BYPASS_TIMER_I                   = 1167,
  NV_WCDMA_1900_LNA_RANGE_OFFSET_I               = 1168,
  NV_WCDMA_1900_LNA_OFFSET_VS_FREQ_I             = 1169,
  NV_WCDMA_1900_RX_AGC_MIN_I                     = 1170,
  NV_WCDMA_1900_RX_AGC_MAX_I                     = 1171,
  NV_WCDMA_1900_AGC_PHASE_OFFSET_I               = 1172,
  NV_WCDMA_1900_TX_LIN_MASTER_0_I                = 1173,
  NV_WCDMA_1900_TX_LIN_MASTER_1_I                = 1174,
  NV_WCDMA_1900_TX_COMP_VS_FREQ_0_I              = 1175,
  NV_WCDMA_1900_TX_COMP_VS_FREQ_1_I              = 1176,
  NV_WCDMA_1900_TX_LIN_VS_TEMP_0_I               = 1177,
  NV_WCDMA_1900_TX_LIN_VS_TEMP_1_I               = 1178,
  NV_WCDMA_1900_TX_SLP_VS_TEMP_0_I               = 1179,
  NV_WCDMA_1900_TX_SLP_VS_TEMP_1_I               = 1180,
  NV_WCDMA_1900_R1_RISE_I                        = 1181,
  NV_WCDMA_1900_R1_FALL_I                        = 1182,
  NV_WCDMA_1900_TX_LIM_VS_TEMP_I                 = 1183,
  NV_WCDMA_1900_TX_LIM_VS_FREQ_I                 = 1184,
  NV_WCDMA_1900_ADJ_FACTOR_I                     = 1185,
  NV_WCDMA_1900_EXP_HDET_VS_AGC_I                = 1186,
  NV_WCDMA_1900_HDET_OFF_I                       = 1187,
  NV_WCDMA_1900_HDET_SPN_I                       = 1188,
  NV_WCDMA_1900_ENC_BTF_I                        = 1189,
  NV_RPLMNACT_I                                  = 1190,
  NV_PS_DATA_ORIG_PREF_I                         = 1191,
  NV_HDR_AN_AUTH_PASSWD_LONG_I                   = 1192,
  NV_DS_MIP_QC_HANDDOWN_TO_1X_OPT_I              = 1193,
  NV_HDR_AN_AUTH_USER_ID_LONG_I                  = 1194,
  NV_PCS_LNA_BYPASS_TIMER_0_I                    = 1195,
  NV_WCDMA_AGC_PA_ON_RISE_DELAY_I                = 1196,
  NV_WCDMA_AGC_PA_ON_FALL_DELAY_I                = 1197,
  NV_WCDMA_AGC_TX_ON_RISE_DELAY_I                = 1198,
  NV_WCDMA_AGC_TX_ON_FALL_DELAY_I                = 1199,
  NV_WCDMA_AGC_UPDATE_TX_AGC_TIME_I              = 1200,
  NV_WCDMA_1900_AGC_PA_ON_RISE_DELAY_I           = 1201,
  NV_WCDMA_1900_AGC_PA_ON_FALL_DELAY_I           = 1202,
  NV_WCDMA_1900_AGC_TX_ON_RISE_DELAY_I           = 1203,
  NV_WCDMA_1900_AGC_TX_ON_FALL_DELAY_I           = 1204,
  NV_WCDMA_1900_AGC_UPDATE_TX_AGC_TIME_I         = 1205,
  NV_PPP_CONFIG_DATA_I                           = 1206,
  NV_CELL_1X_OLTA_BACKOFF_I                      = 1207,
  NV_CELL_HDR_OLTA_BACKOFF_I                     = 1208,
  NV_PCS_OLTA_BACKOFF_I                          = 1209,
  NV_BC6_TX_LIM_VS_TEMP_I                        = 1210,
  NV_C0_BC6_RX_CAL_CHAN_I                        = 1211,
  NV_BC6_TX_LIN_MASTER0_I                        = 1212,
  NV_BC6_TX_LIN_MASTER1_I                        = 1213,
  NV_BC6_TX_COMP0_I                              = 1214,
  NV_BC6_TX_COMP1_I                              = 1215,
  NV_BC6_TX_LIM_VS_FREQ_I                        = 1216,
  NV_BC6_EXP_HDET_VS_AGC_I                       = 1217,
  NV_BC6_HDET_OFF_I                              = 1218,
  NV_BC6_HDET_SPN_I                              = 1219,
  NV_BC6_PA_R1_RISE_I                            = 1220,
  NV_BC6_PA_R1_FALL_I                            = 1221,
  NV_BC6_LNA_RANGE_POL_I                         = 1222,
  NV_BC6_LNA_1_RISE_I                            = 1223,
  NV_BC6_LNA_1_FALL_I                            = 1224,
  NV_C0_BC6_LNA_RANGE_OFFSET_I                   = 1225,
  NV_C1_BC6_LNA_RANGE_OFFSET_I                   = 1226,
  NV_BC6_LNA_2_RISE_I                            = 1227,
  NV_BC6_LNA_2_FALL_I                            = 1228,
  NV_BC6_LNA_RANGE_12_OFFSET_I                   = 1229,
  NV_C0_BC6_IM_LEVEL1_I                          = 1230,
  NV_C0_BC6_IM_LEVEL2_I                          = 1231,
  NV_C0_BC6_IM_LEVEL3_I                          = 1232,
  NV_C0_BC6_IM_LEVEL4_I                          = 1233,
  NV_C0_BC6_LNA_1_OFFSET_VS_FREQ_I               = 1234,
  NV_C1_BC6_LNA_1_OFFSET_VS_FREQ_I               = 1235,
  NV_BC6_AGC_PHASE_OFFSET_I                      = 1236,
  NV_BC6_ADJ_FACTOR_I                            = 1237,
  NV_BC6_RX_AGC_MINMAX_I                         = 1238,
  NV_BC6_RX_AGC_MIN_11_I                         = 1239,
  NV_BC6_ENC_BTF_I                               = 1240,
  NV_BC6_TX_GAIN_ATTEN_LIMIT_I                   = 1241,
  NV_BC6_LNA_3_FALL_I                            = 1242,
  NV_BC6_LNA_3_RISE_I                            = 1243,
  NV_BC6_LNA_3_OFFSET_I                          = 1244,
  NV_C0_BC6_LNA_3_OFFSET_VS_FREQ_I               = 1245,
  NV_C1_BC6_LNA_3_OFFSET_VS_FREQ_I               = 1246,
  NV_BC6_LNA_4_FALL_I                            = 1247,
  NV_BC6_LNA_4_RISE_I                            = 1248,
  NV_C0_BC6_LNA_4_OFFSET_I                       = 1249,
  NV_C1_BC6_LNA_4_OFFSET_I                       = 1250,
  NV_C0_BC6_IM2_I_VALUE_I                        = 1251,
  NV_C1_BC6_IM2_I_VALUE_I                        = 1252,
  NV_C0_BC6_IM2_Q_VALUE_I                        = 1253,
  NV_C1_BC6_IM2_Q_VALUE_I                        = 1254,
  NV_C0_BC6_VGA_GAIN_OFFSET_I                    = 1255,
  NV_C1_BC6_VGA_GAIN_OFFSET_I                    = 1256,
  NV_C0_BC6_VGA_GAIN_OFFSET_VS_FREQ_I            = 1257,
  NV_C1_BC6_VGA_GAIN_OFFSET_VS_FREQ_I            = 1258,
  NV_C0_BC6_VGA_GAIN_OFFSET_VS_TEMP_I            = 1259,
  NV_C1_BC6_VGA_GAIN_OFFSET_VS_TEMP_I            = 1260,
  NV_BC6_P1_RISE_FALL_OFF_I                      = 1261,
  NV_C0_BC6_LNA_4_OFFSET_VS_FREQ_I               = 1262,
  NV_C1_BC6_LNA_4_OFFSET_VS_FREQ_I               = 1263,
  NV_C0_BC6_P1_RISE_FALL_OFFSET_I                = 1264,
  NV_C1_BC6_P1_RISE_FALL_OFFSET_I                = 1265,
  NV_C0_BC6_DIGITAL_MIS_COMP_A_OFFSET_I          = 1266,
  NV_C1_BC6_DIGITAL_MIS_COMP_A_OFFSET_I          = 1267,
  NV_C0_BC6_DIGITAL_MIS_COMP_B_OFFSET_I          = 1268,
  NV_C1_BC6_DIGITAL_MIS_COMP_B_OFFSET_I          = 1269,
  NV_C0_BC6_IM2_TRANSCONDUCTOR_VALUE_I           = 1270,
  NV_C1_BC6_IM2_TRANSCONDUCTOR_VALUE_I           = 1271,
  NV_BC6_VCO_COARSE_TUNE_TABLE_I                 = 1272,
  NV_GSM_PA_TEMP_COMP_INDEX_00_I                 = 1273,
  NV_GSM_PA_TEMP_COMP_INDEX_01_I                 = 1274,
  NV_GSM_PA_TEMP_COMP_INDEX_02_I                 = 1275,
  NV_GSM_PA_TEMP_COMP_INDEX_03_I                 = 1276,
  NV_GSM_PA_TEMP_COMP_INDEX_04_I                 = 1277,
  NV_GSM_PA_TEMP_COMP_INDEX_05_I                 = 1278,
  NV_GSM_PA_TEMP_COMP_INDEX_06_I                 = 1279,
  NV_GSM_PA_TEMP_COMP_INDEX_07_I                 = 1280,
  NV_GSM_PA_TEMP_COMP_INDEX_08_I                 = 1281,
  NV_GSM_PA_TEMP_COMP_INDEX_09_I                 = 1282,
  NV_GSM_PA_TEMP_COMP_INDEX_10_I                 = 1283,
  NV_GSM_PA_TEMP_COMP_INDEX_11_I                 = 1284,
  NV_GSM_PA_TEMP_COMP_INDEX_12_I                 = 1285,
  NV_GSM_PA_TEMP_COMP_INDEX_13_I                 = 1286,
  NV_DCS_PA_TEMP_COMP_INDEX_00_I                 = 1287,
  NV_DCS_PA_TEMP_COMP_INDEX_01_I                 = 1288,
  NV_DCS_PA_TEMP_COMP_INDEX_02_I                 = 1289,
  NV_DCS_PA_TEMP_COMP_INDEX_03_I                 = 1290,
  NV_DCS_PA_TEMP_COMP_INDEX_04_I                 = 1291,
  NV_DCS_PA_TEMP_COMP_INDEX_05_I                 = 1292,
  NV_DCS_PA_TEMP_COMP_INDEX_06_I                 = 1293,
  NV_DCS_PA_TEMP_COMP_INDEX_07_I                 = 1294,
  NV_DCS_PA_TEMP_COMP_INDEX_08_I                 = 1295,
  NV_DCS_PA_TEMP_COMP_INDEX_09_I                 = 1296,
  NV_DCS_PA_TEMP_COMP_INDEX_10_I                 = 1297,
  NV_DCS_PA_TEMP_COMP_INDEX_11_I                 = 1298,
  NV_DCS_PA_TEMP_COMP_INDEX_12_I                 = 1299,
  NV_DCS_PA_TEMP_COMP_INDEX_13_I                 = 1300,
  NV_DCS_PA_TEMP_COMP_INDEX_14_I                 = 1301,
  NV_GSM_AMR_CALL_CONFIG_I                       = 1302,
  NV_GSM_PA_TEMP_COMP_INT8_INDEX_14_I            = 1303,
  NV_DCS_PA_TEMP_COMP_INT8_INDEX_15_I            = 1304,
  NV_GMM_PTMSI_SIG_TOBE_DELETED_I                = 1305,
  NV_C0_BC6_TX_CAL_CHAN_I                        = 1306,
  NV_CDMA_TX_CAL_CHAN_I                          = 1307,
  NV_CDMA_RX_CAL_CHAN_I                          = 1308,
  NV_PCS_RX_CAL_CHAN_I                           = 1309,
  NV_PCS_TX_CAL_CHAN_I                           = 1310,
  NV_SEC_DEVICE_KEY_I                            = 1311,
  NV_GSM_850_PA_TEMP_COMP_INDEX_00_I             = 1312,
  NV_GSM_850_PA_TEMP_COMP_INDEX_01_I             = 1313,
  NV_GSM_850_PA_TEMP_COMP_INDEX_02_I             = 1314,
  NV_GSM_850_PA_TEMP_COMP_INDEX_03_I             = 1315,
  NV_GSM_850_PA_TEMP_COMP_INDEX_04_I             = 1316,
  NV_GSM_850_PA_TEMP_COMP_INDEX_05_I             = 1317,
  NV_GSM_850_PA_TEMP_COMP_INDEX_06_I             = 1318,
  NV_GSM_850_PA_TEMP_COMP_INDEX_07_I             = 1319,
  NV_GSM_850_PA_TEMP_COMP_INDEX_08_I             = 1320,
  NV_GSM_850_PA_TEMP_COMP_INDEX_09_I             = 1321,
  NV_GSM_850_PA_TEMP_COMP_INDEX_10_I             = 1322,
  NV_GSM_850_PA_TEMP_COMP_INDEX_11_I             = 1323,
  NV_GSM_850_PA_TEMP_COMP_INDEX_12_I             = 1324,
  NV_GSM_850_PA_TEMP_COMP_INDEX_13_I             = 1325,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_00_I            = 1326,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_01_I            = 1327,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_02_I            = 1328,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_03_I            = 1329,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_04_I            = 1330,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_05_I            = 1331,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_06_I            = 1332,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_07_I            = 1333,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_08_I            = 1334,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_09_I            = 1335,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_10_I            = 1336,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_11_I            = 1337,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_12_I            = 1338,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_13_I            = 1339,
  NV_GSM_1900_PA_TEMP_COMP_INDEX_14_I            = 1340,
  NV_TCP_GRACEFUL_DORMANT_CLOSE_I                = 1341,
  NV_INTERFREQ_ENABLED_I                         = 1342,
  NV_EPLMN_ENABLED_I                             = 1343,
  NV_DTMF_I                                      = 1344,
  NV_TRK_LO_ADJ_DEFAULT_I                        = 1345,
  NV_TRK_LO_ADJ_SLOPE_DEFAULT_I                  = 1346,
  NV_WCDMA_PA_GAIN_UP_TIME_I                     = 1347,
  NV_WCDMA_PA_GAIN_DOWN_TIME_I                   = 1348,
  NV_BC6_GPS1_RF_DELAY_I                         = 1349,
  NV_BC6_RF_TUNE_RESERVED_I                      = 1350,
  NV_BC6_TX_LIN_MASTER2_I                        = 1351,
  NV_BC6_TX_LIN_MASTER3_I                        = 1352,
  NV_BC6_TX_COMP2_I                              = 1353,
  NV_BC6_TX_COMP3_I                              = 1354,
  NV_BC6_PA_R2_RISE_I                            = 1355,
  NV_BC6_PA_R2_FALL_I                            = 1356,
  NV_BC6_PA_R3_RISE_I                            = 1357,
  NV_BC6_PA_R3_FALL_I                            = 1358,
  NV_C0_BC6_LNA_2_OFFSET_VS_FREQ_I               = 1359,
  NV_C0_BC6_LNA_1_OFFSET_I                       = 1360,
  NV_C0_BC6_LNA_2_OFFSET_I                       = 1361,
  NV_C0_BC6_LNA_3_OFFSET_I                       = 1362,
  NV_C0_BC6_LNA_1_RISE_I                         = 1363,
  NV_C0_BC6_LNA_1_FALL_I                         = 1364,
  NV_C0_BC6_LNA_2_RISE_I                         = 1365,
  NV_C0_BC6_LNA_2_FALL_I                         = 1366,
  NV_C0_BC6_LNA_3_RISE_I                         = 1367,
  NV_C0_BC6_LNA_3_FALL_I                         = 1368,
  NV_C0_BC6_LNA_4_RISE_I                         = 1369,
  NV_C0_BC6_LNA_4_FALL_I                         = 1370,
  NV_C1_BC6_TX_CAL_CHAN_I                        = 1371,
  NV_C1_BC6_RX_CAL_CHAN_I                        = 1372,
  NV_C1_BC6_LNA_2_OFFSET_VS_FREQ_I               = 1373,
  NV_C1_BC6_LNA_1_OFFSET_I                       = 1374,
  NV_C1_BC6_LNA_2_OFFSET_I                       = 1375,
  NV_C1_BC6_LNA_3_OFFSET_I                       = 1376,
  NV_C1_BC6_LNA_1_RISE_I                         = 1377,
  NV_C1_BC6_LNA_1_FALL_I                         = 1378,
  NV_C1_BC6_LNA_2_RISE_I                         = 1379,
  NV_C1_BC6_LNA_2_FALL_I                         = 1380,
  NV_C1_BC6_LNA_3_RISE_I                         = 1381,
  NV_C1_BC6_LNA_3_FALL_I                         = 1382,
  NV_C1_BC6_LNA_4_RISE_I                         = 1383,
  NV_C1_BC6_LNA_4_FALL_I                         = 1384,
  NV_C1_BC6_IM_LEVEL1_I                          = 1385,
  NV_C1_BC6_IM_LEVEL2_I                          = 1386,
  NV_C1_BC6_IM_LEVEL3_I                          = 1387,
  NV_C1_BC6_IM_LEVEL4_I                          = 1388,
  NV_BC5_GPS1_RF_DELAY_I                         = 1389,
  NV_BC5_RF_TUNE_RESERVED_I                      = 1390,
  NV_BC5_TX_LIM_VS_TEMP_I                        = 1391,
  NV_BC5_TX_LIN_MASTER0_I                        = 1392,
  NV_BC5_TX_LIN_MASTER1_I                        = 1393,
  NV_BC5_TX_LIN_MASTER2_I                        = 1394,
  NV_BC5_TX_LIN_MASTER3_I                        = 1395,
  NV_BC5_TX_COMP0_I                              = 1396,
  NV_BC5_TX_COMP1_I                              = 1397,
  NV_BC5_TX_COMP2_I                              = 1398,
  NV_BC5_TX_COMP3_I                              = 1399,
  NV_BC5_TX_LIM_VS_FREQ_I                        = 1400,
  NV_BC5_PA_R1_RISE_I                            = 1401,
  NV_BC5_PA_R1_FALL_I                            = 1402,
  NV_BC5_PA_R2_RISE_I                            = 1403,
  NV_BC5_PA_R2_FALL_I                            = 1404,
  NV_BC5_PA_R3_RISE_I                            = 1405,
  NV_BC5_PA_R3_FALL_I                            = 1406,
  NV_BC5_HDET_OFF_I                              = 1407,
  NV_BC5_HDET_SPN_I                              = 1408,
  NV_BC5_EXP_HDET_VS_AGC_I                       = 1409,
  NV_BC5_ENC_BTF_I                               = 1410,
  NV_BC5_VCO_COARSE_TUNE_TABLE_I                 = 1411,
  NV_BC5_P1_RISE_FALL_OFF_I                      = 1412,
  NV_C0_BC5_TX_CAL_CHAN_I                        = 1413,
  NV_C0_BC5_RX_CAL_CHAN_I                        = 1414,
  NV_C0_BC5_LNA_1_OFFSET_VS_FREQ_I               = 1415,
  NV_C0_BC5_LNA_2_OFFSET_VS_FREQ_I               = 1416,
  NV_C0_BC5_LNA_3_OFFSET_VS_FREQ_I               = 1417,
  NV_C0_BC5_LNA_4_OFFSET_VS_FREQ_I               = 1418,
  NV_C0_BC5_LNA_1_OFFSET_I                       = 1419,
  NV_C0_BC5_LNA_2_OFFSET_I                       = 1420,
  NV_C0_BC5_LNA_3_OFFSET_I                       = 1421,
  NV_C0_BC5_LNA_4_OFFSET_I                       = 1422,
  NV_C0_BC5_IM2_I_VALUE_I                        = 1423,
  NV_C0_BC5_IM2_Q_VALUE_I                        = 1424,
  NV_C0_BC5_VGA_GAIN_OFFSET_I                    = 1425,
  NV_C0_BC5_VGA_GAIN_OFFSET_VS_FREQ_I            = 1426,
  NV_C0_BC5_IM2_TRANSCONDUCTOR_VALUE_I           = 1427,
  NV_C0_BC5_LNA_1_RISE_I                         = 1428,
  NV_C0_BC5_LNA_1_FALL_I                         = 1429,
  NV_C0_BC5_LNA_2_RISE_I                         = 1430,
  NV_C0_BC5_LNA_2_FALL_I                         = 1431,
  NV_C0_BC5_LNA_3_RISE_I                         = 1432,
  NV_C0_BC5_LNA_3_FALL_I                         = 1433,
  NV_C0_BC5_LNA_4_RISE_I                         = 1434,
  NV_C0_BC5_LNA_4_FALL_I                         = 1435,
  NV_C0_BC5_IM_LEVEL1_I                          = 1436,
  NV_C0_BC5_IM_LEVEL2_I                          = 1437,
  NV_C0_BC5_IM_LEVEL3_I                          = 1438,
  NV_C0_BC5_IM_LEVEL4_I                          = 1439,
  NV_C1_BC5_TX_CAL_CHAN_I                        = 1440,
  NV_C1_BC5_RX_CAL_CHAN_I                        = 1441,
  NV_C1_BC5_LNA_1_OFFSET_VS_FREQ_I               = 1442,
  NV_C1_BC5_LNA_2_OFFSET_VS_FREQ_I               = 1443,
  NV_C1_BC5_LNA_3_OFFSET_VS_FREQ_I               = 1444,
  NV_C1_BC5_LNA_4_OFFSET_VS_FREQ_I               = 1445,
  NV_C1_BC5_LNA_1_OFFSET_I                       = 1446,
  NV_C1_BC5_LNA_2_OFFSET_I                       = 1447,
  NV_C1_BC5_LNA_3_OFFSET_I                       = 1448,
  NV_C1_BC5_LNA_4_OFFSET_I                       = 1449,
  NV_C1_BC5_IM2_I_VALUE_I                        = 1450,
  NV_C1_BC5_IM2_Q_VALUE_I                        = 1451,
  NV_C1_BC5_VGA_GAIN_OFFSET_I                    = 1452,
  NV_C1_BC5_VGA_GAIN_OFFSET_VS_FREQ_I            = 1453,
  NV_C1_BC5_IM2_TRANSCONDUCTOR_VALUE_I           = 1454,
  NV_C1_BC5_LNA_1_RISE_I                         = 1455,
  NV_C1_BC5_LNA_1_FALL_I                         = 1456,
  NV_C1_BC5_LNA_2_RISE_I                         = 1457,
  NV_C1_BC5_LNA_2_FALL_I                         = 1458,
  NV_C1_BC5_LNA_3_RISE_I                         = 1459,
  NV_C1_BC5_LNA_3_FALL_I                         = 1460,
  NV_C1_BC5_LNA_4_RISE_I                         = 1461,
  NV_C1_BC5_LNA_4_FALL_I                         = 1462,
  NV_C1_BC5_IM_LEVEL1_I                          = 1463,
  NV_C1_BC5_IM_LEVEL2_I                          = 1464,
  NV_C1_BC5_IM_LEVEL3_I                          = 1465,
  NV_C1_BC5_IM_LEVEL4_I                          = 1466,
  NV_BC4_GPS1_RF_DELAY_I                         = 1467,
  NV_BC4_RF_TUNE_RESERVED_I                      = 1468,
  NV_BC4_TX_LIM_VS_TEMP_I                        = 1469,
  NV_BC4_TX_LIN_MASTER0_I                        = 1470,
  NV_BC4_TX_LIN_MASTER1_I                        = 1471,
  NV_BC4_TX_LIN_MASTER2_I                        = 1472,
  NV_BC4_TX_LIN_MASTER3_I                        = 1473,
  NV_BC4_TX_COMP0_I                              = 1474,
  NV_BC4_TX_COMP1_I                              = 1475,
  NV_BC4_TX_COMP2_I                              = 1476,
  NV_BC4_TX_COMP3_I                              = 1477,
  NV_BC4_TX_LIM_VS_FREQ_I                        = 1478,
  NV_BC4_PA_R1_RISE_I                            = 1479,
  NV_BC4_PA_R1_FALL_I                            = 1480,
  NV_BC4_PA_R2_RISE_I                            = 1481,
  NV_BC4_PA_R2_FALL_I                            = 1482,
  NV_BC4_PA_R3_RISE_I                            = 1483,
  NV_BC4_PA_R3_FALL_I                            = 1484,
  NV_BC4_HDET_OFF_I                              = 1485,
  NV_BC4_HDET_SPN_I                              = 1486,
  NV_BC4_EXP_HDET_VS_AGC_I                       = 1487,
  NV_BC4_ENC_BTF_I                               = 1488,
  NV_BC4_VCO_COARSE_TUNE_TABLE_I                 = 1489,
  NV_BC4_P1_RISE_FALL_OFF_I                      = 1490,
  NV_C0_BC4_TX_CAL_CHAN_I                        = 1491,
  NV_C0_BC4_RX_CAL_CHAN_I                        = 1492,
  NV_C0_BC4_LNA_1_OFFSET_VS_FREQ_I               = 1493,
  NV_C0_BC4_LNA_2_OFFSET_VS_FREQ_I               = 1494,
  NV_C0_BC4_LNA_3_OFFSET_VS_FREQ_I               = 1495,
  NV_C0_BC4_LNA_4_OFFSET_VS_FREQ_I               = 1496,
  NV_C0_BC4_LNA_1_OFFSET_I                       = 1497,
  NV_C0_BC4_LNA_2_OFFSET_I                       = 1498,
  NV_C0_BC4_LNA_3_OFFSET_I                       = 1499,
  NV_C0_BC4_LNA_4_OFFSET_I                       = 1500,
  NV_C0_BC4_IM2_I_VALUE_I                        = 1501,
  NV_C0_BC4_IM2_Q_VALUE_I                        = 1502,
  NV_C0_BC4_VGA_GAIN_OFFSET_I                    = 1503,
  NV_C0_BC4_VGA_GAIN_OFFSET_VS_FREQ_I            = 1504,
  NV_C0_BC4_IM2_TRANSCONDUCTOR_VALUE_I           = 1505,
  NV_C0_BC4_LNA_1_RISE_I                         = 1506,
  NV_C0_BC4_LNA_1_FALL_I                         = 1507,
  NV_C0_BC4_LNA_2_RISE_I                         = 1508,
  NV_C0_BC4_LNA_2_FALL_I                         = 1509,
  NV_C0_BC4_LNA_3_RISE_I                         = 1510,
  NV_C0_BC4_LNA_3_FALL_I                         = 1511,
  NV_C0_BC4_LNA_4_RISE_I                         = 1512,
  NV_C0_BC4_LNA_4_FALL_I                         = 1513,
  NV_C0_BC4_IM_LEVEL1_I                          = 1514,
  NV_C0_BC4_IM_LEVEL2_I                          = 1515,
  NV_C0_BC4_IM_LEVEL3_I                          = 1516,
  NV_C0_BC4_IM_LEVEL4_I                          = 1517,
  NV_C1_BC4_TX_CAL_CHAN_I                        = 1518,
  NV_C1_BC4_RX_CAL_CHAN_I                        = 1519,
  NV_C1_BC4_LNA_1_OFFSET_VS_FREQ_I               = 1520,
  NV_C1_BC4_LNA_2_OFFSET_VS_FREQ_I               = 1521,
  NV_C1_BC4_LNA_3_OFFSET_VS_FREQ_I               = 1522,
  NV_C1_BC4_LNA_4_OFFSET_VS_FREQ_I               = 1523,
  NV_C1_BC4_LNA_1_OFFSET_I                       = 1524,
  NV_C1_BC4_LNA_2_OFFSET_I                       = 1525,
  NV_C1_BC4_LNA_3_OFFSET_I                       = 1526,
  NV_C1_BC4_LNA_4_OFFSET_I                       = 1527,
  NV_C1_BC4_IM2_I_VALUE_I                        = 1528,
  NV_C1_BC4_IM2_Q_VALUE_I                        = 1529,
  NV_C1_BC4_VGA_GAIN_OFFSET_I                    = 1530,
  NV_C1_BC4_VGA_GAIN_OFFSET_VS_FREQ_I            = 1531,
  NV_C1_BC4_IM2_TRANSCONDUCTOR_VALUE_I           = 1532,
  NV_C1_BC4_LNA_1_RISE_I                         = 1533,
  NV_C1_BC4_LNA_1_FALL_I                         = 1534,
  NV_C1_BC4_LNA_2_RISE_I                         = 1535,
  NV_C1_BC4_LNA_2_FALL_I                         = 1536,
  NV_C1_BC4_LNA_3_RISE_I                         = 1537,
  NV_C1_BC4_LNA_3_FALL_I                         = 1538,
  NV_C1_BC4_LNA_4_RISE_I                         = 1539,
  NV_C1_BC4_LNA_4_FALL_I                         = 1540,
  NV_C1_BC4_IM_LEVEL1_I                          = 1541,
  NV_C1_BC4_IM_LEVEL2_I                          = 1542,
  NV_C1_BC4_IM_LEVEL3_I                          = 1543,
  NV_C1_BC4_IM_LEVEL4_I                          = 1544,
  NV_BC3_GPS1_RF_DELAY_I                         = 1545,
  NV_BC3_RF_TUNE_RESERVED_I                      = 1546,
  NV_BC3_TX_LIM_VS_TEMP_I                        = 1547,
  NV_BC3_TX_LIN_MASTER0_I                        = 1548,
  NV_BC3_TX_LIN_MASTER1_I                        = 1549,
  NV_BC3_TX_LIN_MASTER2_I                        = 1550,
  NV_BC3_TX_LIN_MASTER3_I                        = 1551,
  NV_BC3_TX_COMP0_I                              = 1552,
  NV_BC3_TX_COMP1_I                              = 1553,
  NV_BC3_TX_COMP2_I                              = 1554,
  NV_BC3_TX_COMP3_I                              = 1555,
  NV_BC3_TX_LIM_VS_FREQ_I                        = 1557,
  NV_BC3_PA_R1_RISE_I                            = 1558,
  NV_BC3_PA_R1_FALL_I                            = 1559,
  NV_BC3_PA_R2_RISE_I                            = 1560,
  NV_BC3_PA_R2_FALL_I                            = 1561,
  NV_BC3_PA_R3_RISE_I                            = 1562,
  NV_BC3_PA_R3_FALL_I                            = 1563,
  NV_BC3_HDET_OFF_I                              = 1564,
  NV_BC3_HDET_SPN_I                              = 1565,
  NV_BC3_EXP_HDET_VS_AGC_I                       = 1566,
  NV_BC3_ENC_BTF_I                               = 1567,
  NV_BC3_VCO_COARSE_TUNE_TABLE_I                 = 1568,
  NV_BC3_P1_RISE_FALL_OFF_I                      = 1569,
  NV_C0_BC3_TX_CAL_CHAN_I                        = 1570,
  NV_C0_BC3_RX_CAL_CHAN_I                        = 1571,
  NV_C0_BC3_LNA_1_OFFSET_VS_FREQ_I               = 1572,
  NV_C0_BC3_LNA_2_OFFSET_VS_FREQ_I               = 1573,
  NV_C0_BC3_LNA_3_OFFSET_VS_FREQ_I               = 1574,
  NV_C0_BC3_LNA_4_OFFSET_VS_FREQ_I               = 1575,
  NV_C0_BC3_LNA_1_OFFSET_I                       = 1576,
  NV_C0_BC3_LNA_2_OFFSET_I                       = 1577,
  NV_C0_BC3_LNA_3_OFFSET_I                       = 1578,
  NV_C0_BC3_LNA_4_OFFSET_I                       = 1579,
  NV_C0_BC3_IM2_I_VALUE_I                        = 1580,
  NV_C0_BC3_IM2_Q_VALUE_I                        = 1581,
  NV_C0_BC3_VGA_GAIN_OFFSET_I                    = 1582,
  NV_C0_BC3_VGA_GAIN_OFFSET_VS_FREQ_I            = 1583,
  NV_C0_BC3_IM2_TRANSCONDUCTOR_VALUE_I           = 1584,
  NV_C0_BC3_LNA_1_RISE_I                         = 1585,
  NV_C0_BC3_LNA_1_FALL_I                         = 1586,
  NV_C0_BC3_LNA_2_RISE_I                         = 1587,
  NV_C0_BC3_LNA_2_FALL_I                         = 1588,
  NV_C0_BC3_LNA_3_RISE_I                         = 1589,
  NV_C0_BC3_LNA_3_FALL_I                         = 1590,
  NV_C0_BC3_LNA_4_RISE_I                         = 1591,
  NV_C0_BC3_LNA_4_FALL_I                         = 1592,
  NV_C0_BC3_IM_LEVEL1_I                          = 1593,
  NV_C0_BC3_IM_LEVEL2_I                          = 1594,
  NV_C0_BC3_IM_LEVEL3_I                          = 1595,
  NV_C0_BC3_IM_LEVEL4_I                          = 1596,
  NV_C1_BC3_TX_CAL_CHAN_I                        = 1597,
  NV_C1_BC3_RX_CAL_CHAN_I                        = 1598,
  NV_C1_BC3_LNA_1_OFFSET_VS_FREQ_I               = 1599,
  NV_C1_BC3_LNA_2_OFFSET_VS_FREQ_I               = 1600,
  NV_C1_BC3_LNA_3_OFFSET_VS_FREQ_I               = 1601,
  NV_C1_BC3_LNA_4_OFFSET_VS_FREQ_I               = 1602,
  NV_C1_BC3_LNA_1_OFFSET_I                       = 1603,
  NV_C1_BC3_LNA_2_OFFSET_I                       = 1604,
  NV_C1_BC3_LNA_3_OFFSET_I                       = 1605,
  NV_C1_BC3_LNA_4_OFFSET_I                       = 1606,
  NV_C1_BC3_IM2_I_VALUE_I                        = 1607,
  NV_C1_BC3_IM2_Q_VALUE_I                        = 1608,
  NV_C1_BC3_VGA_GAIN_OFFSET_I                    = 1609,
  NV_C1_BC3_VGA_GAIN_OFFSET_VS_FREQ_I            = 1610,
  NV_C1_BC3_IM2_TRANSCONDUCTOR_VALUE_I           = 1611,
  NV_C1_BC3_LNA_1_RISE_I                         = 1612,
  NV_C1_BC3_LNA_1_FALL_I                         = 1613,
  NV_C1_BC3_LNA_2_RISE_I                         = 1614,
  NV_C1_BC3_LNA_2_FALL_I                         = 1615,
  NV_C1_BC3_LNA_3_RISE_I                         = 1616,
  NV_C1_BC3_LNA_3_FALL_I                         = 1617,
  NV_C1_BC3_LNA_4_RISE_I                         = 1618,
  NV_C1_BC3_LNA_4_FALL_I                         = 1619,
  NV_C1_BC3_IM_LEVEL1_I                          = 1620,
  NV_C1_BC3_IM_LEVEL2_I                          = 1621,
  NV_C1_BC3_IM_LEVEL3_I                          = 1622,
  NV_C1_BC3_IM_LEVEL4_I                          = 1623,
  NV_BC1_GPS1_RF_DELAY_I                         = 1624,
  NV_BC1_RF_TUNE_RESERVED_I                      = 1625,
  NV_BC1_TX_LIM_VS_TEMP_I                        = 1626,
  NV_BC1_TX_LIN_MASTER0_I                        = 1627,
  NV_BC1_TX_LIN_MASTER1_I                        = 1628,
  NV_BC1_TX_LIN_MASTER2_I                        = 1629,
  NV_BC1_TX_LIN_MASTER3_I                        = 1630,
  NV_BC1_TX_COMP0_I                              = 1631,
  NV_BC1_TX_COMP1_I                              = 1632,
  NV_BC1_TX_COMP2_I                              = 1633,
  NV_BC1_TX_COMP3_I                              = 1634,
  NV_BC1_TX_LIM_VS_FREQ_I                        = 1635,
  NV_BC1_PA_R1_RISE_I                            = 1636,
  NV_BC1_PA_R1_FALL_I                            = 1637,
  NV_BC1_PA_R2_RISE_I                            = 1638,
  NV_BC1_PA_R2_FALL_I                            = 1639,
  NV_BC1_PA_R3_RISE_I                            = 1640,
  NV_BC1_PA_R3_FALL_I                            = 1641,
  NV_BC1_HDET_OFF_I                              = 1642,
  NV_BC1_HDET_SPN_I                              = 1643,
  NV_BC1_EXP_HDET_VS_AGC_I                       = 1644,
  NV_BC1_ENC_BTF_I                               = 1645,
  NV_BC1_VCO_COARSE_TUNE_TABLE_I                 = 1646,
  NV_BC1_P1_RISE_FALL_OFF_I                      = 1647,
  NV_C0_BC1_TX_CAL_CHAN_I                        = 1648,
  NV_C0_BC1_RX_CAL_CHAN_I                        = 1649,
  NV_C0_BC1_LNA_1_OFFSET_VS_FREQ_I               = 1650,
  NV_C0_BC1_LNA_2_OFFSET_VS_FREQ_I               = 1651,
  NV_C0_BC1_LNA_3_OFFSET_VS_FREQ_I               = 1652,
  NV_C0_BC1_LNA_4_OFFSET_VS_FREQ_I               = 1653,
  NV_C0_BC1_LNA_1_OFFSET_I                       = 1654,
  NV_C0_BC1_LNA_2_OFFSET_I                       = 1655,
  NV_C0_BC1_LNA_3_OFFSET_I                       = 1666,
  NV_C0_BC1_LNA_4_OFFSET_I                       = 1667,
  NV_C0_BC1_IM2_I_VALUE_I                        = 1668,
  NV_C0_BC1_IM2_Q_VALUE_I                        = 1669,
  NV_C0_BC1_VGA_GAIN_OFFSET_I                    = 1670,
  NV_C0_BC1_VGA_GAIN_OFFSET_VS_FREQ_I            = 1671,
  NV_C0_BC1_IM2_TRANSCONDUCTOR_VALUE_I           = 1672,
  NV_C0_BC1_LNA_1_RISE_I                         = 1673,
  NV_C0_BC1_LNA_1_FALL_I                         = 1674,
  NV_C0_BC1_LNA_2_RISE_I                         = 1675,
  NV_C0_BC1_LNA_2_FALL_I                         = 1676,
  NV_C0_BC1_LNA_3_RISE_I                         = 1677,
  NV_C0_BC1_LNA_3_FALL_I                         = 1678,
  NV_C0_BC1_LNA_4_RISE_I                         = 1679,
  NV_C0_BC1_LNA_4_FALL_I                         = 1680,
  NV_C0_BC1_IM_LEVEL1_I                          = 1681,
  NV_C0_BC1_IM_LEVEL2_I                          = 1682,
  NV_C0_BC1_IM_LEVEL3_I                          = 1683,
  NV_C0_BC1_IM_LEVEL4_I                          = 1684,
  NV_C1_BC1_TX_CAL_CHAN_I                        = 1685,
  NV_C1_BC1_RX_CAL_CHAN_I                        = 1686,
  NV_C1_BC1_LNA_1_OFFSET_VS_FREQ_I               = 1687,
  NV_C1_BC1_LNA_2_OFFSET_VS_FREQ_I               = 1689,
  NV_C1_BC1_LNA_3_OFFSET_VS_FREQ_I               = 1690,
  NV_C1_BC1_LNA_4_OFFSET_VS_FREQ_I               = 1691,
  NV_C1_BC1_LNA_1_OFFSET_I                       = 1692,
  NV_C1_BC1_LNA_2_OFFSET_I                       = 1693,
  NV_C1_BC1_LNA_3_OFFSET_I                       = 1694,
  NV_C1_BC1_LNA_4_OFFSET_I                       = 1695,
  NV_C1_BC1_IM2_I_VALUE_I                        = 1696,
  NV_C1_BC1_IM2_Q_VALUE_I                        = 1697,
  NV_C1_BC1_VGA_GAIN_OFFSET_I                    = 1698,
  NV_C1_BC1_VGA_GAIN_OFFSET_VS_FREQ_I            = 1699,
  NV_C1_BC1_IM2_TRANSCONDUCTOR_VALUE_I           = 1700,
  NV_C1_BC1_LNA_1_RISE_I                         = 1701,
  NV_C1_BC1_LNA_1_FALL_I                         = 1702,
  NV_C1_BC1_LNA_2_RISE_I                         = 1703,
  NV_C1_BC1_LNA_2_FALL_I                         = 1704,
  NV_C1_BC1_LNA_3_RISE_I                         = 1705,
  NV_C1_BC1_LNA_3_FALL_I                         = 1706,
  NV_C1_BC1_LNA_4_RISE_I                         = 1707,
  NV_C1_BC1_LNA_4_FALL_I                         = 1708,
  NV_C1_BC1_IM_LEVEL1_I                          = 1709,
  NV_C1_BC1_IM_LEVEL2_I                          = 1710,
  NV_C1_BC1_IM_LEVEL3_I                          = 1711,
  NV_C1_BC1_IM_LEVEL4_I                          = 1712,
  NV_BC0_GPS1_RF_DELAY_I                         = 1713,
  NV_BC0_RF_TUNE_RESERVED_I                      = 1714,
  NV_BC0_TX_LIM_VS_TEMP_I                        = 1715,
  NV_BC0_TX_LIN_MASTER0_I                        = 1716,
  NV_BC0_TX_LIN_MASTER1_I                        = 1717,
  NV_BC0_TX_LIN_MASTER2_I                        = 1718,
  NV_BC0_TX_LIN_MASTER3_I                        = 1719,
  NV_BC0_TX_COMP0_I                              = 1720,
  NV_BC0_TX_COMP1_I                              = 1721,
  NV_BC0_TX_COMP2_I                              = 1722,
  NV_BC0_TX_COMP3_I                              = 1723,
  NV_BC0_TX_LIM_VS_FREQ_I                        = 1724,
  NV_BC0_PA_R1_RISE_I                            = 1725,
  NV_BC0_PA_R1_FALL_I                            = 1726,
  NV_BC0_PA_R2_RISE_I                            = 1727,
  NV_BC0_PA_R2_FALL_I                            = 1728,
  NV_BC0_PA_R3_RISE_I                            = 1729,
  NV_BC0_PA_R3_FALL_I                            = 1730,
  NV_BC0_HDET_OFF_I                              = 1731,
  NV_BC0_HDET_SPN_I                              = 1732,
  NV_BC0_EXP_HDET_VS_AGC_I                       = 1733,
  NV_BC0_ENC_BTF_I                               = 1734,
  NV_BC0_VCO_COARSE_TUNE_TABLE_I                 = 1735,
  NV_BC0_P1_RISE_FALL_OFF_I                      = 1736,
  NV_C0_BC0_TX_CAL_CHAN_I                        = 1737,
  NV_C0_BC0_RX_CAL_CHAN_I                        = 1738,
  NV_C0_BC0_LNA_1_OFFSET_VS_FREQ_I               = 1739,
  NV_C0_BC0_LNA_2_OFFSET_VS_FREQ_I               = 1740,
  NV_C0_BC0_LNA_3_OFFSET_VS_FREQ_I               = 1741,
  NV_C0_BC0_LNA_4_OFFSET_VS_FREQ_I               = 1742,
  NV_C0_BC0_LNA_1_OFFSET_I                       = 1743,
  NV_C0_BC0_LNA_2_OFFSET_I                       = 1744,
  NV_C0_BC0_LNA_3_OFFSET_I                       = 1745,
  NV_C0_BC0_LNA_4_OFFSET_I                       = 1746,
  NV_C0_BC0_IM2_I_VALUE_I                        = 1747,
  NV_C0_BC0_IM2_Q_VALUE_I                        = 1748,
  NV_C0_BC0_VGA_GAIN_OFFSET_I                    = 1749,
  NV_C0_BC0_VGA_GAIN_OFFSET_VS_FREQ_I            = 1750,
  NV_C0_BC0_IM2_TRANSCONDUCTOR_VALUE_I           = 1751,
  NV_C0_BC0_LNA_1_RISE_I                         = 1752,
  NV_C0_BC0_LNA_1_FALL_I                         = 1753,
  NV_C0_BC0_LNA_2_RISE_I                         = 1754,
  NV_C0_BC0_LNA_2_FALL_I                         = 1755,
  NV_C0_BC0_LNA_3_RISE_I                         = 1756,
  NV_C0_BC0_LNA_3_FALL_I                         = 1757,
  NV_C0_BC0_LNA_4_RISE_I                         = 1758,
  NV_C0_BC0_LNA_4_FALL_I                         = 1759,
  NV_C0_BC0_IM_LEVEL1_I                          = 1760,
  NV_C0_BC0_IM_LEVEL2_I                          = 1761,
  NV_C0_BC0_IM_LEVEL3_I                          = 1762,
  NV_C0_BC0_IM_LEVEL4_I                          = 1763,
  NV_C1_BC0_TX_CAL_CHAN_I                        = 1764,
  NV_C1_BC0_RX_CAL_CHAN_I                        = 1765,
  NV_C1_BC0_LNA_1_OFFSET_VS_FREQ_I               = 1766,
  NV_C1_BC0_LNA_2_OFFSET_VS_FREQ_I               = 1767,
  NV_C1_BC0_LNA_3_OFFSET_VS_FREQ_I               = 1768,
  NV_C1_BC0_LNA_4_OFFSET_VS_FREQ_I               = 1769,
  NV_C1_BC0_LNA_1_OFFSET_I                       = 1770,
  NV_C1_BC0_LNA_2_OFFSET_I                       = 1771,
  NV_C1_BC0_LNA_3_OFFSET_I                       = 1772,
  NV_C1_BC0_LNA_4_OFFSET_I                       = 1773,
  NV_C1_BC0_IM2_I_VALUE_I                        = 1774,
  NV_C1_BC0_IM2_Q_VALUE_I                        = 1775,
  NV_C1_BC0_VGA_GAIN_OFFSET_I                    = 1776,
  NV_C1_BC0_VGA_GAIN_OFFSET_VS_FREQ_I            = 1777,
  NV_C1_BC0_IM2_TRANSCONDUCTOR_VALUE_I           = 1778,
  NV_C1_BC0_LNA_1_RISE_I                         = 1779,
  NV_C1_BC0_LNA_1_FALL_I                         = 1780,
  NV_C1_BC0_LNA_2_RISE_I                         = 1781,
  NV_C1_BC0_LNA_2_FALL_I                         = 1782,
  NV_C1_BC0_LNA_3_RISE_I                         = 1783,
  NV_C1_BC0_LNA_3_FALL_I                         = 1784,
  NV_C1_BC0_LNA_4_RISE_I                         = 1785,
  NV_C1_BC0_LNA_4_FALL_I                         = 1786,
  NV_C1_BC0_IM_LEVEL1_I                          = 1787,
  NV_C1_BC0_IM_LEVEL2_I                          = 1788,
  NV_C1_BC0_IM_LEVEL3_I                          = 1789,
  NV_C1_BC0_IM_LEVEL4_I                          = 1790,
  NV_RFR_BB_FILTER_I                             = 1791,
  NV_RFR_IQ_LINE_RESISTOR_I                      = 1792,
  NV_WCDMA_RFR_VCO_COARSE_TUNING_I               = 1793,
  NV_RFR_VCO_COARSE_TUNING_1900_I                = 1794,
  NV_WCDMA_TX_ROT_ANGLE_PA_STATE_00_I            = 1795,
  NV_WCDMA_TX_ROT_ANGLE_PA_STATE_01_I            = 1796,
  NV_WCDMA_TX_ROT_ANGLE_PA_STATE_10_I            = 1797,
  NV_WCDMA_TX_ROT_ANGLE_PA_STATE_11_I            = 1798,
  NV_AMR_I                                       = 1799,
  NV_WCDMA_SPIKE_MITIGATION_ENABLED_I            = 1800,
  NV_PA_COMPENSATE_UP_I                          = 1801,
  NV_PA_COMPENSATE_DOWN_I                        = 1802,
  NV_SN_PPP_STATUS_I                             = 1803,
  NV_DS_UCSD_RLPV2_DEFAULT_I                     = 1804,
  NV_SELECT_TECH_FOR_CARD_I                      = 1805,
  NV_PPP_NCP_REMOTE_INITIATE_I                   = 1806,
  NV_DS_UCSD_RLP_VERSION_GSM_I                   = 1807,
  NV_DS_UCSD_RLP_VERSION_WCDMA_I                 = 1808,
  NV_DS_ATCOP_RLP_VERSION_DEFAULT_I              = 1809,
  NV_DS_UCSD_RECOVERY_MODE_SREJ_I                = 1810,
  NV_TCP_KEEPALIVE_IDLE_TIME_I                   = 1811,
  NV_RF_TUNE_RESERVED_I                          = 1812,
  NV_DATA_FORCE_CDMA_PKT_STR_I                   = 1813,
  NV_WCDMA_800_VGA_GAIN_OFFSET_I                 = 1814,
  NV_WCDMA_800_VGA_GAIN_OFFSET_VS_FREQ_I         = 1815,
  NV_WCDMA_800_VGA_GAIN_OFFSET_VS_TEMP_I         = 1816,
  NV_WCDMA_800_LNA_RANGE_RISE_2_I                = 1817,
  NV_WCDMA_800_LNA_RANGE_RISE_3_I                = 1818,
  NV_WCDMA_800_LNA_RANGE_FALL_2_I                = 1819,
  NV_WCDMA_800_LNA_RANGE_FALL_3_I                = 1820,
  NV_WCDMA_800_IM_LEVEL_2_I                      = 1821,
  NV_WCDMA_800_IM_LEVEL_3_I                      = 1822,
  NV_WCDMA_800_LNA_RANGE_OFFSET_2_I              = 1823,
  NV_WCDMA_800_LNA_RANGE_OFFSET_3_I              = 1824,
  NV_WCDMA_800_LNA_OFFSET_VS_FREQ_2_I            = 1825,
  NV_WCDMA_800_LNA_OFFSET_VS_FREQ_3_I            = 1826,
  NV_WCDMA_800_IM2_I_VALUE_I                     = 1827,
  NV_WCDMA_800_IM2_Q_VALUE_I                     = 1828,
  NV_WCDMA_800_IM2_TRANSCONDUCTOR_VALUE_I        = 1829,
  NV_WCDMA_800_RX_AGC_MIN_2_I                    = 1830,
  NV_WCDMA_800_RX_AGC_MIN_3_I                    = 1831,
  NV_WCDMA_800_MAX_TX_POWER_I                    = 1832,
  NV_WCDMA_800_OUT_OF_SERVICE_THRESH_I           = 1833,
  NV_WCDMA_800_LNA_RANGE_RISE_I                  = 1834,
  NV_WCDMA_800_LNA_RANGE_FALL_I                  = 1835,
  NV_WCDMA_800_IM_LEVEL_I                        = 1836,
  NV_WCDMA_800_NONBYPASS_TIMER_I                 = 1837,
  NV_WCDMA_800_BYPASS_TIMER_I                    = 1838,
  NV_WCDMA_800_LNA_RANGE_OFFSET_I                = 1839,
  NV_WCDMA_800_LNA_OFFSET_VS_FREQ_I              = 1840,
  NV_WCDMA_800_RX_AGC_MIN_I                      = 1841,
  NV_WCDMA_800_RX_AGC_MAX_I                      = 1842,
  NV_WCDMA_800_AGC_PHASE_OFFSET_I                = 1843,
  NV_WCDMA_800_TX_LIN_MASTER_0_I                 = 1844,
  NV_WCDMA_800_TX_LIN_MASTER_1_I                 = 1845,
  NV_WCDMA_800_TX_COMP_VS_FREQ_0_I               = 1846,
  NV_WCDMA_800_TX_COMP_VS_FREQ_1_I               = 1847,
  NV_WCDMA_800_TX_LIN_VS_TEMP_0_I                = 1848,
  NV_WCDMA_800_TX_LIN_VS_TEMP_1_I                = 1849,
  NV_WCDMA_800_TX_SLP_VS_TEMP_0_I                = 1850,
  NV_WCDMA_800_TX_SLP_VS_TEMP_1_I                = 1860,
  NV_WCDMA_800_R1_RISE_I                         = 1861,
  NV_WCDMA_800_R1_FALL_I                         = 1862,
  NV_WCDMA_800_TX_LIM_VS_TEMP_I                  = 1863,
  NV_WCDMA_800_TX_LIM_VS_FREQ_I                  = 1864,
  NV_WCDMA_800_ADJ_FACTOR_I                      = 1865,
  NV_WCDMA_800_EXP_HDET_VS_AGC_I                 = 1866,
  NV_WCDMA_800_HDET_OFF_I                        = 1867,
  NV_WCDMA_800_HDET_SPN_I                        = 1868,
  NV_WCDMA_800_ENC_BTF_I                         = 1869,
  NV_WCDMA_800_AGC_PA_ON_RISE_DELAY_I            = 1870,
  NV_WCDMA_800_AGC_PA_ON_FALL_DELAY_I            = 1871,
  NV_WCDMA_800_AGC_TX_ON_RISE_DELAY_I            = 1872,
  NV_WCDMA_800_AGC_TX_ON_FALL_DELAY_I            = 1873,
  NV_WCDMA_800_AGC_UPDATE_TX_AGC_TIME_I          = 1874,
  NV_PA_R_MAP_I                                  = 1875,
  NV_PS_IPV6_IID_I                               = 1876,
  NV_RF_BC_CONFIG_I                              = 1877,
  NV_RF_HW_CONFIG_I                              = 1878,
  NV_BC0_HDR_IM_FALL_I                           = 1879,
  NV_BC0_HDR_IM_RISE_I                           = 1880,
  NV_VCO_TEMP_I                                  = 1881,
  NV_VCO_DEFAULT_I                               = 1882,
  NV_VCO_SLOPE_I                                 = 1883,
  NV_VCO_SLOPE_RANGE_I                           = 1884,
  NV_RGS_TIME_I                                  = 1885,
  NV_RGS_TYPE_I                                  = 1886,
  NV_RGS_TEMP_I                                  = 1887,
  NV_RGS_ROT_I                                   = 1888,
  NV_RGS_VCO_I                                   = 1889,
  NV_BC0_HDR_IM_LEVEL_I                          = 1890,
  NV_GSM_TX_BURST_OFFSET_ADJ_I                   = 1891,
  NV_DIAG_DEBUG_CONTROL_I                        = 1892,
  NV_QVP_APP_DEFAULT_CAPABILITY_TYPE_I           = 1893,
  NV_RR_STORED_LAST_BEST_ARFCNS_BAND_I           = 1894,
  NV_DIAG_DEBUG_DETAIL_I                         = 1895,
  NV_IPV6_ENABLED_I                              = 1896,
  NV_IPV6_SM_CONFIG_I                            = 1897,
  NV_C1_BC0_VCO_COARSE_TUNE_TABLE_I              = 1898,
  NV_C1_BC1_VCO_COARSE_TUNE_TABLE_I              = 1899,
  NV_C1_BC3_VCO_COARSE_TUNE_TABLE_I              = 1900,
  NV_C1_BC4_VCO_COARSE_TUNE_TABLE_I              = 1901,
  NV_C1_BC5_VCO_COARSE_TUNE_TABLE_I              = 1902,
  NV_C1_BC6_VCO_COARSE_TUNE_TABLE_I              = 1903,
  NV_C1_RFR_BB_FILTER_I                          = 1904,
  NV_IPV6_PRIMARY_DNS_I                          = 1905,
  NV_IPV6_SECONDARY_DNS_I                        = 1906,
  NV_AUTH_REQUIRE_PASSWORD_ENCRYPTION_I          = 1907,
  NV_WCDMA_PRACH_R1_RISE_OFFSET_I                = 1908,
  NV_WCDMA_1900_PRACH_R1_RISE_OFFSET_I           = 1909,
  NV_WCDMA_PRACH_R1_FALL_OFFSET_I                = 1910,
  NV_WCDMA_1900_PRACH_R1_FALL_OFFSET_I           = 1911,
  NV_WCDMA_800_PRACH_R1_FALL_OFFSET_I            = 1912,
  NV_AAGPS_MAX_OSC_UNC_I                         = 1913,
  NV_AAGPS_MAX_OSC_UNC_RATE_I                    = 1914,
  NV_AAGPS_PROCESSING_LOSSES_I                   = 1915,
  NV_AAGPS_MAX_PLATFORM_VELOCITY_I               = 1916,
  NV_AAGPS_MAX_PLATFORM_ACCL_I                   = 1917,
  NV_AAGPS_DEFAULT_QOS_TIME_I                    = 1918,
  NV_AAGPS_RAPID_FIX_REPORT_MAX_LATENCY_I        = 1919,
  NV_AAGPS_POSITIONING_MODES_SUPPORTED_I         = 1920,
  NV_AAGPS_DEFAULT_REF_TIME_UNC_I                = 1921,
  NV_AAGPS_DEFAULT_REF_POSITION_UNC_I            = 1922,
  NV_AAGPS_APP_TRACKING_GPSIDLE_THSLD_I          = 1923,
  NV_AAGPS_GPS_LOCK_CONTROL_I                    = 1924,
  NV_AAGPS_DEFAULT_URL_I                         = 1925,
  NV_AAGPS_DEFAULT_IP_ADDRESS_I                  = 1926,
  NV_AAGPS_TRANSPORT_TYPE_I                      = 1927,
  NV_AAGPS_KEEP_WARM_MODE_I                      = 1928,
  NV_AAGPS_2G_MO_LRSUPPORT_I                     = 1929,
  NV_AAGPS_EMERGENCY_SERVICES_SPPRT_I            = 1930,
  NV_WCDMA_800_PRACH_R1_RISE_OFFSET_I            = 1931,
  NV_PDSN_AS_PROXY_IPV6_DNS_SERVER_I             = 1932,
  NV_HDRAMP_HARDWARE_ID_I                        = 1933,
  NV_AAGPS_PROTOCOL_SELECT_I                     = 1934,
  NV_AAGPS_APP_TRKG_PERIODIC_REQ_DLY_MARGIN_I    = 1935,
  NV_AAGPS_DEFAULT_QOS_UNC_I                     = 1936,
  NV_AAGPS_APP_TRACKING_GPSON_THSLD_I            = 1937,
  NV_AAGPS_MT_LRSUPPORT_I                        = 1940,
  NV_IPV6_FAILOVER_CONFIG_I                      = 1941,
  NV_UIM_USE_CAVE_FOR_AN_AUTH_I                  = 1942,
  NV_MEID_I                                      = 1943,
  NV_GPS1_CALL_RELATED_I                         = 1944,
  NV_RF_ANTSEL_GSM_DEFAULT_I                     = 1945,
  NV_RF_ANTSEL_GSM_850_TX_I                      = 1946,
  NV_RF_ANTSEL_GSM_850_RX_I                      = 1947,
  NV_RF_ANTSEL_GSM_900_TX_I                      = 1948,
  NV_RF_ANTSEL_GSM_900_RX_I                      = 1949,
  NV_RF_ANTSEL_GSM_1800_TX_I                     = 1950,
  NV_RF_ANTSEL_GSM_1800_RX_I                     = 1951,
  NV_RF_ANTSEL_GSM_1900_TX_I                     = 1952,
  NV_RF_ANTSEL_GSM_1900_RX_I                     = 1953,
  NV_RF_ANTSEL_UMTS_800_I                        = 1954,
  NV_RF_ANTSEL_UMTS_1900_I                       = 1955,
  NV_RF_ANTSEL_UMTS_2100_I                       = 1956,
  NV_TCP_SACK_TIMESTAMP_ENABLED_I                = 1957,
  NV_PRL_PREF_I                                  = 1958,
  NV_AAGPS_DEFAULT_IP_PORT_I                     = 1959,
  NV_AAGPS_3G_MO_LRSUPPORT_I                     = 1960,
  NV_AAGPS_DEVELOPMENT_TEST_CONTROL_I            = 1961,
  NV_DIAG_DEBUG_MAX_FILES_I                      = 1962,
  NV_WCDMA_800_PA_COMPENSATE_UP_I                = 1963,
  NV_WCDMA_800_PA_COMPENSATE_DOWN_I              = 1964,
  NV_WCDMA_1900_PA_COMPENSATE_UP_I               = 1965,
  NV_WCDMA_1900_PA_COMPENSATE_DOWN_I             = 1966,
  NV_WCDMA_800_PA_GAIN_UP_TIME_I                 = 1967,
  NV_WCDMA_800_PA_GAIN_DOWN_TIME_I               = 1968,
  NV_WCDMA_1900_PA_GAIN_UP_TIME_I                = 1969,
  NV_WCDMA_1900_PA_GAIN_DOWN_TIME_I              = 1970,
  NV_WCDMA_TX_CAL_CHAN_I                         = 1971,
  NV_WCDMA_RX_CAL_CHAN_I                         = 1972,
  NV_WCDMA_1900_TX_CAL_CHAN_I                    = 1973,
  NV_WCDMA_1900_RX_CAL_CHAN_I                    = 1974,
  NV_WCDMA_800_TX_CAL_CHAN_I                     = 1975,
  NV_WCDMA_800_RX_CAL_CHAN_I                     = 1976,
  NV_BREW_CARRIER_ID_I                           = 1977,
  NV_BREW_PLATFORM_ID_I                          = 1978,
  NV_BREW_BKEY_I                                 = 1979,
  NV_BREW_SERVER_I                               = 1980,
  NV_BREW_DOWNLOAD_FLAGS_I                       = 1981,
  NV_BREW_AUTH_POLICY_I                          = 1982,
  NV_BREW_PRIVACY_POLICY_I                       = 1983,
  NV_BREW_SUBSCRIBER_ID_I                        = 1984,
  NV_WCDMA_RX_DELAY_I                            = 1985,
  NV_WCDMA_800_RX_DELAY_I                        = 1986,
  NV_WCDMA_1900_RX_DELAY_I                       = 1987,
  NV_AAGPS_DEVELOPMENT_TEST_CONTROL2_I           = 1988,
  NV_AAGPS_DEVELOPMENT_TEST_CONTROL3_I           = 1989,
  NV_AAGPS_DEVELOPMENT_TEST_CONTROL4_I           = 1990,
  NV_AAGPS_DEVELOPMENT_TEST_CONTROL5_I           = 1991,
  NV_MEID_CD_I                                   = 1992,
  NV_GPS1_VX_LCS_AGENT_I                         = 1993,
  NV_GPS1_VX_APP_TRUSTED_SETTINGS_I              = 1994,
  NV_GPS1_VX_NI_TELESERVICE_ID_I                 = 1995,
  NV_GPS1_VX_LCS_AGENT_PREV6_ONLY_I              = 1996,
  NV_GPS1_VX_MO_MAX_DURATION_I                   = 1997,
  NV_GPS1_OOS_OPERATION_PREF_I                   = 1998,
  NV_GPS1_VX_GPS_DURING_VOICE_CALL_I             = 1999,
  NV_WLAN_TECH_PREF_I                            = 2000,
  NV_DS_UCSD_RLP_ADM_IDLE_I                      = 2001,
  NV_PPP_CCP_REJECT_I                            = 2002,
  NV_WLAN_SCAN_PREF_I                            = 2003,
  NV_HDRBCMCS_OVHD_PERIOD_I                      = 2004,
  NV_HDRBCMCS_PAGE_REG_PERIOD_I                  = 2005,
  NV_HDRBCMCS_DYN_REG_PERIOD_I                   = 2006,
  NV_HDRBCMCS_MONITOR_PERIOD_I                   = 2007,
  NV_HDRBCMCS_NUM_PERIODS_I                      = 2008,
  NV_WCDMA_TX_LIN_MASTER_2_I                     = 2009,
  NV_WCDMA_TX_LIN_MASTER_3_I                     = 2010,
  NV_WCDMA_TX_COMP_VS_FREQ_2_I                   = 2011,
  NV_WCDMA_TX_COMP_VS_FREQ_3_I                   = 2012,
  NV_WCDMA_TX_LIN_VS_TEMP_2_I                    = 2013,
  NV_WCDMA_TX_LIN_VS_TEMP_3_I                    = 2014,
  NV_WCDMA_TX_SLP_VS_TEMP_2_I                    = 2015,
  NV_WCDMA_TX_SLP_VS_TEMP_3_I                    = 2016,
  NV_WCDMA_R2_RISE_I                             = 2017,
  NV_WCDMA_R2_FALL_I                             = 2018,
  NV_WCDMA_R3_RISE_I                             = 2019,
  NV_WCDMA_R3_FALL_I                             = 2020,
  NV_PA_COMPENSATE_UP_R2_I                       = 2021,
  NV_PA_COMPENSATE_DOWN_R2_I                     = 2022,
  NV_PA_COMPENSATE_UP_R3_I                       = 2023,
  NV_PA_COMPENSATE_DOWN_R3_I                     = 2024,
  NV_WCDMA_PRACH_R2_RISE_OFFSET_I                = 2025,
  NV_WCDMA_PRACH_R2_FALL_OFFSET_I                = 2026,
  NV_WCDMA_PRACH_R3_RISE_OFFSET_I                = 2027,
  NV_WCDMA_PRACH_R3_FALL_OFFSET_I                = 2028,
  NV_WCDMA_PA_RANGE_MAP_I                        = 2029,
  NV_WCDMA_1900_TX_LIN_MASTER_2_I                = 2030,
  NV_WCDMA_1900_TX_LIN_MASTER_3_I                = 2031,
  NV_WCDMA_1900_TX_COMP_VS_FREQ_2_I              = 2032,
  NV_WCDMA_1900_TX_COMP_VS_FREQ_3_I              = 2033,
  NV_WCDMA_1900_TX_LIN_VS_TEMP_2_I               = 2034,
  NV_WCDMA_1900_TX_LIN_VS_TEMP_3_I               = 2035,
  NV_WCDMA_1900_TX_SLP_VS_TEMP_2_I               = 2036,
  NV_WCDMA_1900_TX_SLP_VS_TEMP_3_I               = 2037,
  NV_WCDMA_1900_R2_RISE_I                        = 2038,
  NV_WCDMA_1900_R2_FALL_I                        = 2039,
  NV_WCDMA_1900_R3_RISE_I                        = 2040,
  NV_WCDMA_1900_R3_FALL_I                        = 2041,
  NV_WCDMA_1900_PA_COMPENSATE_UP_R2_I            = 2042,
  NV_WCDMA_1900_PA_COMPENSATE_DOWN_R2_I          = 2043,
  NV_WCDMA_1900_PA_COMPENSATE_UP_R3_I            = 2044,
  NV_WCDMA_1900_PA_COMPENSATE_DOWN_R3_I          = 2045,
  NV_WCDMA_1900_TX_ROT_ANGLE_PA_STATE_00_I       = 2046,
  NV_WCDMA_1900_TX_ROT_ANGLE_PA_STATE_01_I       = 2047,
  NV_WCDMA_1900_TX_ROT_ANGLE_PA_STATE_10_I       = 2048,
  NV_WCDMA_1900_TX_ROT_ANGLE_PA_STATE_11_I       = 2049,
  NV_WCDMA_1900_PRACH_R2_RISE_OFFSET_I           = 2050,
  NV_WCDMA_1900_PRACH_R2_FALL_OFFSET_I           = 2051,
  NV_WCDMA_1900_PRACH_R3_RISE_OFFSET_I           = 2052,
  NV_WCDMA_1900_PRACH_R3_FALL_OFFSET_I           = 2053,
  NV_WCDMA_1900_PA_RANGE_MAP_I                   = 2054,
  NV_WCDMA_800_TX_LIN_MASTER_2_I                 = 2055,
  NV_WCDMA_800_TX_LIN_MASTER_3_I                 = 2056,
  NV_WCDMA_800_TX_COMP_VS_FREQ_2_I               = 2057,
  NV_WCDMA_800_TX_COMP_VS_FREQ_3_I               = 2058,
  NV_WCDMA_800_TX_LIN_VS_TEMP_2_I                = 2059,
  NV_WCDMA_800_TX_LIN_VS_TEMP_3_I                = 2060,
  NV_WCDMA_800_TX_SLP_VS_TEMP_2_I                = 2061,
  NV_WCDMA_800_TX_SLP_VS_TEMP_3_I                = 2062,
  NV_WCDMA_800_R2_RISE_I                         = 2063,
  NV_WCDMA_800_R2_FALL_I                         = 2064,
  NV_WCDMA_800_R3_RISE_I                         = 2065,
  NV_WCDMA_800_R3_FALL_I                         = 2066,
  NV_WCDMA_800_PA_COMPENSATE_UP_R2_I             = 2067,
  NV_WCDMA_800_PA_COMPENSATE_DOWN_R2_I           = 2068,
  NV_WCDMA_800_PA_COMPENSATE_UP_R3_I             = 2069,
  NV_WCDMA_800_PA_COMPENSATE_DOWN_R3_I           = 2070,
  NV_WCDMA_800_TX_ROT_ANGLE_PA_STATE_00_I        = 2071,
  NV_WCDMA_800_TX_ROT_ANGLE_PA_STATE_01_I        = 2072,
  NV_WCDMA_800_TX_ROT_ANGLE_PA_STATE_10_I        = 2073,
  NV_WCDMA_800_TX_ROT_ANGLE_PA_STATE_11_I        = 2074,
  NV_WCDMA_800_PRACH_R2_RISE_OFFSET_I            = 2075,
  NV_WCDMA_800_PRACH_R2_FALL_OFFSET_I            = 2076,
  NV_WCDMA_800_PRACH_R3_RISE_OFFSET_I            = 2077,
  NV_WCDMA_800_PRACH_R3_FALL_OFFSET_I            = 2078,
  NV_WCDMA_800_PA_RANGE_MAP_I                    = 2079,
  NV_BC0_VCO_COARSE_TUNE_2_I                     = 2080,
  NV_BC1_VCO_COARSE_TUNE_2_I                     = 2081,
  NV_BC3_VCO_COARSE_TUNE_2_I                     = 2082,
  NV_BC4_VCO_COARSE_TUNE_2_I                     = 2083,
  NV_BC5_VCO_COARSE_TUNE_2_I                     = 2084,
  NV_BC6_VCO_COARSE_TUNE_2_I                     = 2085,
  NV_GSM_PRUI_00_I                               = 2086,
  NV_GSM_PRUI_01_I                               = 2087,
  NV_GSM_PRUI_02_I                               = 2088,
  NV_GSM_PRUI_03_I                               = 2089,
  NV_GSM_PRUI_04_I                               = 2090,
  NV_GSM_PRUI_05_I                               = 2091,
  NV_GSM_PRUI_06_I                               = 2092,
  NV_GSM_PRUI_07_I                               = 2093,
  NV_GSM_PRUI_08_I                               = 2094,
  NV_GSM_PRUI_09_I                               = 2095,
  NV_GSM_PRUI_10_I                               = 2096,
  NV_GSM_PRDI_00_I                               = 2097,
  NV_GSM_PRDI_01_I                               = 2098,
  NV_GSM_PRDI_02_I                               = 2099,
  NV_GSM_PRDI_03_I                               = 2100,
  NV_GSM_PRDI_04_I                               = 2101,
  NV_GSM_PRDI_05_I                               = 2102,
  NV_GSM_PRDI_06_I                               = 2103,
  NV_GSM_PRDI_07_I                               = 2104,
  NV_GSM_PRDI_08_I                               = 2105,
  NV_GSM_PRDI_09_I                               = 2106,
  NV_GSM_PRDI_10_I                               = 2107,
  NV_GSM_PRDI_11_I                               = 2108,
  NV_DCS_PRUI_00_I                               = 2109,
  NV_DCS_PRUI_01_I                               = 2110,
  NV_DCS_PRUI_02_I                               = 2111,
  NV_DCS_PRUI_03_I                               = 2112,
  NV_DCS_PRUI_04_I                               = 2113,
  NV_DCS_PRUI_05_I                               = 2114,
  NV_DCS_PRUI_06_I                               = 2115,
  NV_DCS_PRUI_07_I                               = 2116,
  NV_DCS_PRUI_08_I                               = 2117,
  NV_DCS_PRUI_09_I                               = 2118,
  NV_DCS_PRUI_10_I                               = 2119,
  NV_DCS_PRUI_11_I                               = 2120,
  NV_DCS_PRUI_12_I                               = 2121,
  NV_DCS_PRDI_00_I                               = 2122,
  NV_DCS_PRDI_01_I                               = 2123,
  NV_DCS_PRDI_02_I                               = 2124,
  NV_DCS_PRDI_03_I                               = 2125,
  NV_DCS_PRDI_04_I                               = 2126,
  NV_DCS_PRDI_05_I                               = 2127,
  NV_DCS_PRDI_06_I                               = 2128,
  NV_DCS_PRDI_07_I                               = 2129,
  NV_DCS_PRDI_08_I                               = 2130,
  NV_DCS_PRDI_09_I                               = 2131,
  NV_DCS_PRDI_10_I                               = 2132,
  NV_DCS_PRDI_11_I                               = 2133,
  NV_DCS_PRDI_12_I                               = 2134,
  NV_GSM_1900_PRUI_00_I                          = 2135,
  NV_GSM_1900_PRUI_01_I                          = 2136,
  NV_GSM_1900_PRUI_02_I                          = 2137,
  NV_GSM_1900_PRUI_03_I                          = 2138,
  NV_GSM_1900_PRUI_04_I                          = 2139,
  NV_GSM_1900_PRUI_05_I                          = 2140,
  NV_GSM_1900_PRUI_06_I                          = 2141,
  NV_GSM_1900_PRUI_07_I                          = 2142,
  NV_GSM_1900_PRUI_08_I                          = 2143,
  NV_GSM_1900_PRUI_09_I                          = 2144,
  NV_GSM_1900_PRUI_10_I                          = 2145,
  NV_GSM_1900_PRUI_11_I                          = 2146,
  NV_GSM_1900_PRUI_12_I                          = 2147,
  NV_GSM_1900_PRDI_02_I                          = 2148,
  NV_GSM_1900_PRDI_03_I                          = 2149,
  NV_GSM_1900_PRDI_04_I                          = 2150,
  NV_GSM_1900_PRDI_05_I                          = 2151,
  NV_GSM_1900_PRDI_06_I                          = 2152,
  NV_GSM_1900_PRDI_07_I                          = 2153,
  NV_GSM_1900_PRDI_09_I                          = 2154,
  NV_GSM_1900_PRDI_10_I                          = 2155,
  NV_GSM_1900_PRDI_12_I                          = 2156,
  NV_GSM_VL_TL_BRUI_14_I                         = 2157,
  NV_GSM_VL_TL_BRUI_13_I                         = 2158,
  NV_GSM_VL_TL_BRUI_12_I                         = 2159,
  NV_GSM_VL_TL_BRDI_14_I                         = 2160,
  NV_GSM_VL_TL_BRDI_13_I                         = 2161,
  NV_GSM_VL_TL_BRDI_12_I                         = 2162,
  NV_DCS_VL_TL_BRUI_15_I                         = 2163,
  NV_DCS_VL_TL_BRUI_14_I                         = 2164,
  NV_DCS_VL_TL_BRUI_13_I                         = 2165,
  NV_DCS_VL_TL_BRDI_15_I                         = 2166,
  NV_DCS_VL_TL_BRDI_14_I                         = 2167,
  NV_DCS_VL_TL_BRDI_13_I                         = 2168,
  NV_GSM_1900_VL_TL_BRUI_15_I                    = 2169,
  NV_GSM_1900_VL_TL_BRUI_14_I                    = 2170,
  NV_GSM_1900_VL_TL_BRUI_13_I                    = 2171,
  NV_GSM_1900_VL_TL_BRDI_15_I                    = 2172,
  NV_GSM_1900_VL_TL_BRDI_14_I                    = 2173,
  NV_GSM_1900_VL_TL_BRDI_13_I                    = 2174,
  NV_GSM_VM_TL_BRUI_14_I                         = 2175,
  NV_GSM_VM_TL_BRUI_13_I                         = 2176,
  NV_GSM_VM_TL_BRUI_12_I                         = 2177,
  NV_GSM_VM_TL_BRDI_14_I                         = 2178,
  NV_GSM_VM_TL_BRDI_13_I                         = 2179,
  NV_GSM_VM_TL_BRDI_12_I                         = 2180,
  NV_DCS_VM_TL_BRUI_15_I                         = 2181,
  NV_DCS_VM_TL_BRUI_14_I                         = 2182,
  NV_DCS_VM_TL_BRUI_13_I                         = 2183,
  NV_DCS_VM_TL_BRDI_15_I                         = 2184,
  NV_DCS_VM_TL_BRDI_14_I                         = 2185,
  NV_DCS_VM_TL_BRDI_13_I                         = 2186,
  NV_GSM_1900_VM_TL_BRUI_15_I                    = 2187,
  NV_GSM_1900_VM_TL_BRUI_14_I                    = 2188,
  NV_GSM_1900_VM_TL_BRUI_13_I                    = 2189,
  NV_GSM_1900_VM_TL_BRDI_15_I                    = 2190,
  NV_GSM_1900_VM_TL_BRDI_14_I                    = 2191,
  NV_GSM_1900_VM_TL_BRDI_13_I                    = 2192,
  NV_GSM_VH_TL_BRUI_14_I                         = 2193,
  NV_GSM_VH_TL_BRUI_13_I                         = 2194,
  NV_GSM_VH_TL_BRUI_12_I                         = 2195,
  NV_GSM_VH_TL_BRDI_14_I                         = 2196,
  NV_GSM_VH_TL_BRDI_13_I                         = 2197,
  NV_GSM_VH_TL_BRDI_12_I                         = 2198,
  NV_DCS_VH_TL_BRUI_15_I                         = 2199,
  NV_DCS_VH_TL_BRUI_14_I                         = 2200,
  NV_DCS_VH_TL_BRUI_13_I                         = 2201,
  NV_DCS_VH_TL_BRDI_15_I                         = 2202,
  NV_DCS_VH_TL_BRDI_14_I                         = 2203,
  NV_DCS_VH_TL_BRDI_13_I                         = 2204,
  NV_GSM_1900_VH_TL_BRUI_15_I                    = 2205,
  NV_GSM_1900_VH_TL_BRUI_14_I                    = 2206,
  NV_GSM_1900_VH_TL_BRUI_13_I                    = 2207,
  NV_GSM_1900_VH_TL_BRDI_15_I                    = 2208,
  NV_GSM_1900_VH_TL_BRDI_14_I                    = 2209,
  NV_GSM_1900_VH_TL_BRDI_13_I                    = 2210,
  NV_GSM_VL_TM_BRUI_14_I                         = 2211,
  NV_GSM_VL_TM_BRUI_13_I                         = 2212,
  NV_GSM_VL_TM_BRUI_12_I                         = 2213,
  NV_GSM_VL_TM_BRDI_14_I                         = 2214,
  NV_GSM_VL_TM_BRDI_13_I                         = 2215,
  NV_GSM_VL_TM_BRDI_12_I                         = 2216,
  NV_DCS_VL_TM_BRUI_15_I                         = 2217,
  NV_DCS_VL_TM_BRUI_14_I                         = 2218,
  NV_DCS_VL_TM_BRUI_13_I                         = 2219,
  NV_DCS_VL_TM_BRDI_15_I                         = 2220,
  NV_DCS_VL_TM_BRDI_14_I                         = 2221,
  NV_DCS_VL_TM_BRDI_13_I                         = 2222,
  NV_GSM_1900_VL_TM_BRUI_15_I                    = 2223,
  NV_GSM_1900_VL_TM_BRUI_14_I                    = 2224,
  NV_GSM_1900_VL_TM_BRUI_13_I                    = 2225,
  NV_GSM_1900_VL_TM_BRDI_15_I                    = 2226,
  NV_GSM_1900_VL_TM_BRDI_14_I                    = 2227,
  NV_GSM_1900_VL_TM_BRDI_13_I                    = 2228,
  NV_GSM_VM_TM_BRUI_14_I                         = 2229,
  NV_GSM_VM_TM_BRUI_13_I                         = 2230,
  NV_GSM_VM_TM_BRUI_12_I                         = 2231,
  NV_GSM_VM_TM_BRDI_14_I                         = 2232,
  NV_GSM_VM_TM_BRDI_13_I                         = 2233,
  NV_GSM_VM_TM_BRDI_12_I                         = 2234,
  NV_DCS_VM_TM_BRUI_15_I                         = 2235,
  NV_DCS_VM_TM_BRUI_14_I                         = 2236,
  NV_DCS_VM_TM_BRUI_13_I                         = 2237,
  NV_DCS_VM_TM_BRDI_15_I                         = 2238,
  NV_DCS_VM_TM_BRDI_14_I                         = 2239,
  NV_DCS_VM_TM_BRDI_13_I                         = 2240,
  NV_GSM_1900_VM_TM_BRUI_15_I                    = 2241,
  NV_GSM_1900_VM_TM_BRUI_14_I                    = 2242,
  NV_GSM_1900_VM_TM_BRUI_13_I                    = 2243,
  NV_GSM_1900_VM_TM_BRDI_15_I                    = 2244,
  NV_GSM_1900_VM_TM_BRDI_14_I                    = 2245,
  NV_GSM_1900_VM_TM_BRDI_13_I                    = 2246,
  NV_GSM_VH_TM_BRUI_14_I                         = 2247,
  NV_GSM_VH_TM_BRUI_13_I                         = 2248,
  NV_GSM_VH_TM_BRUI_12_I                         = 2249,
  NV_GSM_VH_TM_BRDI_14_I                         = 2250,
  NV_GSM_VH_TM_BRDI_13_I                         = 2251,
  NV_GSM_VH_TM_BRDI_12_I                         = 2252,
  NV_DCS_VH_TM_BRUI_15_I                         = 2253,
  NV_DCS_VH_TM_BRUI_14_I                         = 2254,
  NV_DCS_VH_TM_BRUI_13_I                         = 2255,
  NV_DCS_VH_TM_BRDI_15_I                         = 2256,
  NV_DCS_VH_TM_BRDI_14_I                         = 2257,
  NV_DCS_VH_TM_BRDI_13_I                         = 2258,
  NV_GSM_1900_VH_TM_BRUI_15_I                    = 2259,
  NV_GSM_1900_VH_TM_BRUI_14_I                    = 2260,
  NV_GSM_1900_VH_TM_BRUI_13_I                    = 2261,
  NV_GSM_1900_VH_TM_BRDI_15_I                    = 2262,
  NV_GSM_1900_VH_TM_BRDI_14_I                    = 2263,
  NV_GSM_1900_VH_TM_BRDI_13_I                    = 2264,
  NV_GSM_VL_TH_BRUI_14_I                         = 2265,
  NV_GSM_VL_TH_BRUI_13_I                         = 2266,
  NV_GSM_VL_TH_BRUI_12_I                         = 2267,
  NV_GSM_VL_TH_BRDI_14_I                         = 2268,
  NV_GSM_VL_TH_BRDI_13_I                         = 2269,
  NV_GSM_VL_TH_BRDI_12_I                         = 2270,
  NV_DCS_VL_TH_BRUI_15_I                         = 2271,
  NV_DCS_VL_TH_BRUI_14_I                         = 2272,
  NV_DCS_VL_TH_BRUI_13_I                         = 2273,
  NV_DCS_VL_TH_BRDI_15_I                         = 2274,
  NV_DCS_VL_TH_BRDI_14_I                         = 2275,
  NV_DCS_VL_TH_BRDI_13_I                         = 2276,
  NV_GSM_1900_VL_TH_BRUI_15_I                    = 2277,
  NV_GSM_1900_VL_TH_BRUI_14_I                    = 2278,
  NV_GSM_1900_VL_TH_BRUI_13_I                    = 2279,
  NV_GSM_1900_VL_TH_BRDI_15_I                    = 2280,
  NV_GSM_1900_VL_TH_BRDI_14_I                    = 2281,
  NV_GSM_1900_VL_TH_BRDI_13_I                    = 2282,
  NV_GSM_VM_TH_BRUI_14_I                         = 2283,
  NV_GSM_VM_TH_BRUI_13_I                         = 2284,
  NV_GSM_VM_TH_BRUI_12_I                         = 2285,
  NV_GSM_VM_TH_BRDI_14_I                         = 2286,
  NV_GSM_VM_TH_BRDI_13_I                         = 2287,
  NV_GSM_VM_TH_BRDI_12_I                         = 2288,
  NV_DCS_VM_TH_BRUI_15_I                         = 2289,
  NV_DCS_VM_TH_BRUI_14_I                         = 2290,
  NV_DCS_VM_TH_BRUI_13_I                         = 2291,
  NV_DCS_VM_TH_BRDI_15_I                         = 2292,
  NV_DCS_VM_TH_BRDI_14_I                         = 2293,
  NV_DCS_VM_TH_BRDI_13_I                         = 2294,
  NV_GSM_1900_VM_TH_BRUI_15_I                    = 2295,
  NV_GSM_1900_VM_TH_BRUI_14_I                    = 2296,
  NV_GSM_1900_VM_TH_BRUI_13_I                    = 2297,
  NV_GSM_1900_VM_TH_BRDI_15_I                    = 2298,
  NV_GSM_1900_VM_TH_BRDI_14_I                    = 2299,
  NV_GSM_1900_VM_TH_BRDI_13_I                    = 2300,
  NV_GSM_VH_TH_BRUI_14_I                         = 2301,
  NV_GSM_VH_TH_BRUI_13_I                         = 2302,
  NV_GSM_VH_TH_BRUI_12_I                         = 2303,
  NV_GSM_VH_TH_BRDI_14_I                         = 2304,
  NV_GSM_VH_TH_BRDI_13_I                         = 2305,
  NV_GSM_VH_TH_BRDI_12_I                         = 2306,
  NV_DCS_VH_TH_BRUI_15_I                         = 2307,
  NV_DCS_VH_TH_BRUI_14_I                         = 2308,
  NV_DCS_VH_TH_BRUI_13_I                         = 2309,
  NV_DCS_VH_TH_BRDI_15_I                         = 2310,
  NV_DCS_VH_TH_BRDI_14_I                         = 2311,
  NV_DCS_VH_TH_BRDI_13_I                         = 2312,
  NV_GSM_1900_VH_TH_BRUI_15_I                    = 2313,
  NV_GSM_1900_VH_TH_BRUI_14_I                    = 2314,
  NV_GSM_1900_VH_TH_BRUI_13_I                    = 2315,
  NV_GSM_1900_VH_TH_BRDI_15_I                    = 2316,
  NV_GSM_1900_VH_TH_BRDI_14_I                    = 2317,
  NV_GSM_1900_VH_TH_BRDI_13_I                    = 2318,
  NV_GSM_C0_TX_FREQ_COMP_I                       = 2319,
  NV_DCS_C0_TX_FREQ_COMP_I                       = 2320,
  NV_GSM_1900_C0_TX_FREQ_COMP_I                  = 2321,
  NV_GSM_C1_TX_FREQ_COMP_I                       = 2322,
  NV_DCS_C1_TX_FREQ_COMP_I                       = 2323,
  NV_GSM1900_C1_TX_FREQ_COMP_I                   = 2324,
  NV_GSM_ENABLE_TX_FREQ_COMP_VS_PCL_I            = 2325,
  NV_DCS_ENABLE_TX_FREQ_COMP_VS_PCL_I            = 2326,
  NV_GSM_1900_ENABLE_TX_FREQ_COMP_VS_PCL_I       = 2327,
  NV_THERM_COMP_THRESHOLDS_I                     = 2328,
  NV_VBATT_COMP_THRESHOLDS_I                     = 2329,
  NV_WCDMA_C0_TX_COMP_VS_FREQ_0_I                = 2330,
  NV_WCDMA_C0_TX_COMP_VS_FREQ_1_I                = 2331,
  NV_WCDMA_C1_TX_COMP_VS_FREQ_0_I                = 2332,
  NV_WCDMA_C1_TX_COMP_VS_FREQ_1_I                = 2333,
  NV_WCDMA_TX_LIM_VS_VOLT_OFFSET_I               = 2334,
  NV_GSM_VL_TL_PRUI_14_I                         = 2335,
  NV_GSM_VL_TL_PRUI_13_I                         = 2336,
  NV_GSM_VL_TL_PRUI_12_I                         = 2337,
  NV_GSM_VL_TL_PRDI_14_I                         = 2338,
  NV_GSM_VL_TL_PRDI_13_I                         = 2339,
  NV_GSM_VL_TL_PRDI_12_I                         = 2340,
  NV_DCS_VL_TL_PRUI_15_I                         = 2341,
  NV_DCS_VL_TL_PRUI_14_I                         = 2342,
  NV_DCS_VL_TL_PRUI_13_I                         = 2343,
  NV_DCS_VL_TL_PRDI_15_I                         = 2344,
  NV_DCS_VL_TL_PRDI_14_I                         = 2345,
  NV_DCS_VL_TL_PRDI_13_I                         = 2346,
  NV_GSM_1900_VL_TL_PRUI_15_I                    = 2347,
  NV_GSM_1900_VL_TL_PRUI_14_I                    = 2348,
  NV_GSM_1900_VL_TL_PRUI_13_I                    = 2349,
  NV_GSM_1900_VL_TL_PRDI_15_I                    = 2350,
  NV_GSM_1900_VL_TL_PRDI_14_I                    = 2351,
  NV_GSM_1900_VL_TL_PRDI_13_I                    = 2352,
  NV_GSM_VM_TL_PRUI_14_I                         = 2353,
  NV_GSM_VM_TL_PRUI_13_I                         = 2354,
  NV_GSM_VM_TL_PRUI_12_I                         = 2355,
  NV_GSM_VM_TL_PRDI_14_I                         = 2356,
  NV_GSM_VM_TL_PRDI_13_I                         = 2357,
  NV_GSM_VM_TL_PRDI_12_I                         = 2358,
  NV_DCS_VM_TL_PRUI_15_I                         = 2359,
  NV_DCS_VM_TL_PRUI_14_I                         = 2360,
  NV_DCS_VM_TL_PRUI_13_I                         = 2361,
  NV_DCS_VM_TL_PRDI_15_I                         = 2362,
  NV_DCS_VM_TL_PRDI_14_I                         = 2363,
  NV_DCS_VM_TL_PRDI_13_I                         = 2364,
  NV_GSM_1900_VM_TL_PRUI_15_I                    = 2365,
  NV_GSM_1900_VM_TL_PRUI_14_I                    = 2366,
  NV_GSM_1900_VM_TL_PRUI_13_I                    = 2367,
  NV_GSM_1900_VM_TL_PRDI_15_I                    = 2368,
  NV_GSM_1900_VM_TL_PRDI_14_I                    = 2369,
  NV_GSM_1900_VM_TL_PRDI_13_I                    = 2370,
  NV_GSM_VH_TL_PRUI_14_I                         = 2371,
  NV_GSM_VH_TL_PRUI_13_I                         = 2372,
  NV_GSM_VH_TL_PRUI_12_I                         = 2373,
  NV_GSM_VH_TL_PRDI_14_I                         = 2374,
  NV_GSM_VH_TL_PRDI_13_I                         = 2375,
  NV_GSM_VH_TL_PRDI_12_I                         = 2376,
  NV_DCS_VH_TL_PRUI_15_I                         = 2377,
  NV_DCS_VH_TL_PRUI_14_I                         = 2378,
  NV_DCS_VH_TL_PRUI_13_I                         = 2379,
  NV_DCS_VH_TL_PRDI_15_I                         = 2380,
  NV_DCS_VH_TL_PRDI_14_I                         = 2381,
  NV_DCS_VH_TL_PRDI_13_I                         = 2382,
  NV_GSM_1900_VH_TL_PRUI_15_I                    = 2383,
  NV_GSM_1900_VH_TL_PRUI_14_I                    = 2384,
  NV_GSM_1900_VH_TL_PRUI_13_I                    = 2385,
  NV_GSM_1900_VH_TL_PRDI_15_I                    = 2386,
  NV_GSM_1900_VH_TL_PRDI_14_I                    = 2387,
  NV_GSM_1900_VH_TL_PRDI_13_I                    = 2388,
  NV_GSM_VL_TM_PRUI_14_I                         = 2389,
  NV_GSM_VL_TM_PRUI_13_I                         = 2390,
  NV_GSM_VL_TM_PRUI_12_I                         = 2391,
  NV_GSM_VL_TM_PRDI_14_I                         = 2392,
  NV_GSM_VL_TM_PRDI_13_I                         = 2393,
  NV_GSM_VL_TM_PRDI_12_I                         = 2394,
  NV_DCS_VL_TM_PRUI_15_I                         = 2395,
  NV_DCS_VL_TM_PRUI_14_I                         = 2396,
  NV_DCS_VL_TM_PRUI_13_I                         = 2397,
  NV_DCS_VL_TM_PRDI_15_I                         = 2398,
  NV_DCS_VL_TM_PRDI_14_I                         = 2399,
  NV_DCS_VL_TM_PRDI_13_I                         = 2400,
  NV_GSM_1900_VL_TM_PRUI_15_I                    = 2401,
  NV_GSM_1900_VL_TM_PRUI_14_I                    = 2402,
  NV_GSM_1900_VL_TM_PRUI_13_I                    = 2403,
  NV_GSM_1900_VL_TM_PRDI_15_I                    = 2404,
  NV_GSM_1900_VL_TM_PRDI_14_I                    = 2405,
  NV_GSM_1900_VL_TM_PRDI_13_I                    = 2406,
  NV_GSM_VM_TM_PRUI_14_I                         = 2407,
  NV_GSM_VM_TM_PRUI_13_I                         = 2408,
  NV_GSM_VM_TM_PRUI_12_I                         = 2409,
  NV_GSM_VM_TM_PRDI_14_I                         = 2410,
  NV_GSM_VM_TM_PRDI_13_I                         = 2411,
  NV_GSM_VM_TM_PRDI_12_I                         = 2412,
  NV_DCS_VM_TM_PRUI_15_I                         = 2413,
  NV_DCS_VM_TM_PRUI_14_I                         = 2414,
  NV_DCS_VM_TM_PRUI_13_I                         = 2415,
  NV_DCS_VM_TM_PRDI_15_I                         = 2416,
  NV_DCS_VM_TM_PRDI_14_I                         = 2417,
  NV_DCS_VM_TM_PRDI_13_I                         = 2418,
  NV_GSM_1900_VM_TM_PRUI_15_I                    = 2419,
  NV_GSM_1900_VM_TM_PRUI_14_I                    = 2420,
  NV_GSM_1900_VM_TM_PRUI_13_I                    = 2421,
  NV_GSM_1900_VM_TM_PRDI_15_I                    = 2422,
  NV_GSM_1900_VM_TM_PRDI_14_I                    = 2423,
  NV_GSM_1900_VM_TM_PRDI_13_I                    = 2424,
  NV_GSM_VH_TM_PRUI_14_I                         = 2425,
  NV_GSM_VH_TM_PRUI_13_I                         = 2426,
  NV_GSM_VH_TM_PRUI_12_I                         = 2427,
  NV_GSM_VH_TM_PRDI_14_I                         = 2428,
  NV_GSM_VH_TM_PRDI_13_I                         = 2429,
  NV_GSM_VH_TM_PRDI_12_I                         = 2430,
  NV_DCS_VH_TM_PRUI_15_I                         = 2431,
  NV_DCS_VH_TM_PRUI_14_I                         = 2432,
  NV_DCS_VH_TM_PRUI_13_I                         = 2433,
  NV_DCS_VH_TM_PRDI_15_I                         = 2434,
  NV_DCS_VH_TM_PRDI_14_I                         = 2435,
  NV_DCS_VH_TM_PRDI_13_I                         = 2436,
  NV_GSM_1900_VH_TM_PRUI_15_I                    = 2437,
  NV_GSM_1900_VH_TM_PRUI_14_I                    = 2438,
  NV_GSM_1900_VH_TM_PRUI_13_I                    = 2439,
  NV_GSM_1900_VH_TM_PRDI_15_I                    = 2440,
  NV_GSM_1900_VH_TM_PRDI_14_I                    = 2441,
  NV_GSM_1900_VH_TM_PRDI_13_I                    = 2442,
  NV_GSM_VL_TH_PRUI_14_I                         = 2443,
  NV_GSM_VL_TH_PRUI_13_I                         = 2444,
  NV_GSM_VL_TH_PRUI_12_I                         = 2445,
  NV_GSM_VL_TH_PRDI_14_I                         = 2446,
  NV_GSM_VL_TH_PRDI_13_I                         = 2447,
  NV_GSM_VL_TH_PRDI_12_I                         = 2448,
  NV_DCS_VL_TH_PRUI_15_I                         = 2449,
  NV_DCS_VL_TH_PRUI_14_I                         = 2450,
  NV_DCS_VL_TH_PRUI_13_I                         = 2451,
  NV_DCS_VL_TH_PRDI_15_I                         = 2452,
  NV_DCS_VL_TH_PRDI_14_I                         = 2453,
  NV_DCS_VL_TH_PRDI_13_I                         = 2454,
  NV_GSM_1900_VL_TH_PRUI_15_I                    = 2455,
  NV_GSM_1900_VL_TH_PRUI_14_I                    = 2456,
  NV_GSM_1900_VL_TH_PRUI_13_I                    = 2457,
  NV_GSM_1900_VL_TH_PRDI_15_I                    = 2458,
  NV_GSM_1900_VL_TH_PRDI_14_I                    = 2459,
  NV_GSM_1900_VL_TH_PRDI_13_I                    = 2460,
  NV_GSM_VM_TH_PRUI_14_I                         = 2461,
  NV_GSM_VM_TH_PRUI_13_I                         = 2462,
  NV_GSM_VM_TH_PRUI_12_I                         = 2463,
  NV_GSM_VM_TH_PRDI_14_I                         = 2464,
  NV_GSM_VM_TH_PRDI_13_I                         = 2465,
  NV_GSM_VM_TH_PRDI_12_I                         = 2466,
  NV_DCS_VM_TH_PRUI_15_I                         = 2467,
  NV_DCS_VM_TH_PRUI_14_I                         = 2468,
  NV_DCS_VM_TH_PRUI_13_I                         = 2469,
  NV_DCS_VM_TH_PRDI_15_I                         = 2470,
  NV_DCS_VM_TH_PRDI_14_I                         = 2471,
  NV_DCS_VM_TH_PRDI_13_I                         = 2472,
  NV_GSM_1900_VM_TH_PRUI_15_I                    = 2473,
  NV_GSM_1900_VM_TH_PRUI_14_I                    = 2474,
  NV_GSM_1900_VM_TH_PRUI_13_I                    = 2475,
  NV_GSM_1900_VM_TH_PRDI_15_I                    = 2476,
  NV_GSM_1900_VM_TH_PRDI_14_I                    = 2477,
  NV_GSM_1900_VM_TH_PRDI_13_I                    = 2478,
  NV_GSM_VH_TH_PRUI_14_I                         = 2479,
  NV_GSM_VH_TH_PRUI_13_I                         = 2480,
  NV_GSM_VH_TH_PRUI_12_I                         = 2481,
  NV_GSM_VH_TH_PRDI_14_I                         = 2482,
  NV_GSM_VH_TH_PRDI_13_I                         = 2483,
  NV_GSM_VH_TH_PRDI_12_I                         = 2484,
  NV_DCS_VH_TH_PRUI_15_I                         = 2485,
  NV_DCS_VH_TH_PRUI_14_I                         = 2486,
  NV_DCS_VH_TH_PRUI_13_I                         = 2487,
  NV_DCS_VH_TH_PRDI_15_I                         = 2488,
  NV_DCS_VH_TH_PRDI_14_I                         = 2489,
  NV_DCS_VH_TH_PRDI_13_I                         = 2490,
  NV_GSM_1900_VH_TH_PRUI_15_I                    = 2491,
  NV_GSM_1900_VH_TH_PRUI_14_I                    = 2492,
  NV_GSM_1900_VH_TH_PRUI_13_I                    = 2493,
  NV_GSM_1900_VH_TH_PRDI_15_I                    = 2494,
  NV_GSM_1900_VH_TH_PRDI_14_I                    = 2495,
  NV_GSM_1900_VH_TH_PRDI_13_I                    = 2496,
  NV_FACTORY_DATA_1_I                            = 2497,
  NV_FACTORY_DATA_2_I                            = 2498,
  NV_FACTORY_DATA_3_I                            = 2499,
  NV_FACTORY_DATA_4_I                            = 2500,
  NV_GSM_PRUI_11_I                               = 2501,
  NV_GSM_1900_PRDI_00_I                          = 2502,
  NV_GSM_1900_PRDI_01_I                          = 2503,
  NV_GSM_1900_PRDI_11_I                          = 2504,
  NV_GSM_1900_PRDI_08_I                          = 2505,
  NV_APPX5_PREF_I                                = 2506,
  NV_WLAN_NET_SEL_MODE_PREF_I                    = 2507,
  NV_EDGE_FEATURE_SUPPORT_I                      = 2508,
  NV_EDGE_MULTISLOT_CLASS_I                      = 2509,
  NV_EDGE_8PSK_POWER_CLASS_I                     = 2510,
  NV_EDGE_8PSK_POWER_CAPABILITY_I                = 2511,
  NV_GERAN_FEATURE_PACK_1_I                      = 2512,
  NV_GSM_AMAM_MAX_PWR_I                          = 2513,
  NV_GSM_AMAM_MIN_PWR_I                          = 2514,
  NV_DCS_AMAM_MAX_PWR_I                          = 2515,
  NV_DCS_AMAM_MIN_PWR_I                          = 2516,
  NV_GSM_850_AMAM_MAX_PWR_I                      = 2517,
  NV_GSM_850_AMAM_MIN_PWR_I                      = 2518,
  NV_GSM_1900_AMAM_MAX_PWR_I                     = 2519,
  NV_GSM_1900_AMAM_MIN_PWR_I                     = 2520,
  NV_GSM_AMAM_MASTER_TBL_SEG1_F1_I               = 2521,
  NV_GSM_AMAM_MASTER_TBL_SEG2_F1_I               = 2522,
  NV_GSM_AMAM_MASTER_TBL_SEG3_F1_I               = 2523,
  NV_GSM_AMAM_MASTER_TBL_SEG4_F1_I               = 2524,
  NV_GSM_AMAM_MASTER_TBL_SEG5_F1_I               = 2525,
  NV_GSM_AMAM_MASTER_TBL_SEG6_F1_I               = 2526,
  NV_GSM_AMAM_MASTER_TBL_SEG7_F1_I               = 2527,
  NV_GSM_AMAM_MASTER_TBL_SEG8_F1_I               = 2528,
  NV_DCS_AMAM_MASTER_TBL_SEG1_F1_I               = 2529,
  NV_DCS_AMAM_MASTER_TBL_SEG2_F1_I               = 2530,
  NV_DCS_AMAM_MASTER_TBL_SEG3_F1_I               = 2531,
  NV_DCS_AMAM_MASTER_TBL_SEG4_F1_I               = 2532,
  NV_DCS_AMAM_MASTER_TBL_SEG5_F1_I               = 2533,
  NV_DCS_AMAM_MASTER_TBL_SEG6_F1_I               = 2534,
  NV_DCS_AMAM_MASTER_TBL_SEG7_F1_I               = 2535,
  NV_DCS_AMAM_MASTER_TBL_SEG8_F1_I               = 2536,
  NV_GSM_850_AMAM_MASTER_TBL_SEG1_F1_I           = 2537,
  NV_GSM_850_AMAM_MASTER_TBL_SEG2_F1_I           = 2538,
  NV_GSM_850_AMAM_MASTER_TBL_SEG3_F1_I           = 2539,
  NV_GSM_850_AMAM_MASTER_TBL_SEG4_F1_I           = 2540,
  NV_GSM_850_AMAM_MASTER_TBL_SEG5_F1_I           = 2541,
  NV_GSM_850_AMAM_MASTER_TBL_SEG6_F1_I           = 2542,
  NV_GSM_850_AMAM_MASTER_TBL_SEG7_F1_I           = 2543,
  NV_GSM_850_AMAM_MASTER_TBL_SEG8_F1_I           = 2544,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG1_F1_I          = 2545,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG2_F1_I          = 2546,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG3_F1_I          = 2547,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG4_F1_I          = 2548,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG5_F1_I          = 2549,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG6_F1_I          = 2550,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG7_F1_I          = 2551,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG8_F1_I          = 2552,
  NV_GSM_AMAM_MASTER_TBL_SEG1_F2_I               = 2553,
  NV_GSM_AMAM_MASTER_TBL_SEG2_F2_I               = 2554,
  NV_GSM_AMAM_MASTER_TBL_SEG3_F2_I               = 2555,
  NV_GSM_AMAM_MASTER_TBL_SEG4_F2_I               = 2556,
  NV_GSM_AMAM_MASTER_TBL_SEG5_F2_I               = 2557,
  NV_GSM_AMAM_MASTER_TBL_SEG6_F2_I               = 2558,
  NV_GSM_AMAM_MASTER_TBL_SEG7_F2_I               = 2559,
  NV_GSM_AMAM_MASTER_TBL_SEG8_F2_I               = 2560,
  NV_DCS_AMAM_MASTER_TBL_SEG1_F2_I               = 2561,
  NV_DCS_AMAM_MASTER_TBL_SEG2_F2_I               = 2562,
  NV_DCS_AMAM_MASTER_TBL_SEG3_F2_I               = 2563,
  NV_DCS_AMAM_MASTER_TBL_SEG4_F2_I               = 2564,
  NV_DCS_AMAM_MASTER_TBL_SEG5_F2_I               = 2565,
  NV_DCS_AMAM_MASTER_TBL_SEG6_F2_I               = 2566,
  NV_DCS_AMAM_MASTER_TBL_SEG7_F2_I               = 2567,
  NV_DCS_AMAM_MASTER_TBL_SEG8_F2_I               = 2568,
  NV_GSM_850_AMAM_MASTER_TBL_SEG1_F2_I           = 2569,
  NV_GSM_850_AMAM_MASTER_TBL_SEG2_F2_I           = 2570,
  NV_GSM_850_AMAM_MASTER_TBL_SEG3_F2_I           = 2571,
  NV_GSM_850_AMAM_MASTER_TBL_SEG4_F2_I           = 2572,
  NV_GSM_850_AMAM_MASTER_TBL_SEG5_F2_I           = 2573,
  NV_GSM_850_AMAM_MASTER_TBL_SEG6_F2_I           = 2574,
  NV_GSM_850_AMAM_MASTER_TBL_SEG7_F2_I           = 2575,
  NV_GSM_850_AMAM_MASTER_TBL_SEG8_F2_I           = 2576,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG1_F2_I          = 2577,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG2_F2_I          = 2578,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG3_F2_I          = 2579,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG4_F2_I          = 2580,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG5_F2_I          = 2581,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG6_F2_I          = 2582,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG7_F2_I          = 2583,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG8_F2_I          = 2584,
  NV_GSM_AMPM_MASTER_TBL_SEG1_F1_I               = 2585,
  NV_GSM_AMPM_MASTER_TBL_SEG2_F1_I               = 2586,
  NV_GSM_AMPM_MASTER_TBL_SEG3_F1_I               = 2587,
  NV_GSM_AMPM_MASTER_TBL_SEG4_F1_I               = 2588,
  NV_GSM_AMPM_MASTER_TBL_SEG5_F1_I               = 2589,
  NV_GSM_AMPM_MASTER_TBL_SEG6_F1_I               = 2590,
  NV_GSM_AMPM_MASTER_TBL_SEG7_F1_I               = 2591,
  NV_GSM_AMPM_MASTER_TBL_SEG8_F1_I               = 2592,
  NV_DCS_AMPM_MASTER_TBL_SEG1_F1_I               = 2593,
  NV_DCS_AMPM_MASTER_TBL_SEG2_F1_I               = 2594,
  NV_DCS_AMPM_MASTER_TBL_SEG3_F1_I               = 2595,
  NV_DCS_AMPM_MASTER_TBL_SEG4_F1_I               = 2596,
  NV_DCS_AMPM_MASTER_TBL_SEG5_F1_I               = 2597,
  NV_DCS_AMPM_MASTER_TBL_SEG6_F1_I               = 2598,
  NV_DCS_AMPM_MASTER_TBL_SEG7_F1_I               = 2599,
  NV_DCS_AMPM_MASTER_TBL_SEG8_F1_I               = 2600,
  NV_GSM_850_AMPM_MASTER_TBL_SEG1_F1_I           = 2601,
  NV_GSM_850_AMPM_MASTER_TBL_SEG2_F1_I           = 2602,
  NV_GSM_850_AMPM_MASTER_TBL_SEG3_F1_I           = 2603,
  NV_GSM_850_AMPM_MASTER_TBL_SEG4_F1_I           = 2604,
  NV_GSM_850_AMPM_MASTER_TBL_SEG5_F1_I           = 2605,
  NV_GSM_850_AMPM_MASTER_TBL_SEG6_F1_I           = 2606,
  NV_GSM_850_AMPM_MASTER_TBL_SEG7_F1_I           = 2607,
  NV_GSM_850_AMPM_MASTER_TBL_SEG8_F1_I           = 2608,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG1_F1_I          = 2609,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG2_F1_I          = 2610,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG3_F1_I          = 2611,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG4_F1_I          = 2612,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG5_F1_I          = 2613,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG6_F1_I          = 2614,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG7_F1_I          = 2615,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG8_F1_I          = 2616,
  NV_GSM_AMPM_MASTER_TBL_SEG1_F2_I               = 2617,
  NV_GSM_AMPM_MASTER_TBL_SEG2_F2_I               = 2618,
  NV_GSM_AMPM_MASTER_TBL_SEG3_F2_I               = 2619,
  NV_GSM_AMPM_MASTER_TBL_SEG4_F2_I               = 2620,
  NV_GSM_AMPM_MASTER_TBL_SEG5_F2_I               = 2621,
  NV_GSM_AMPM_MASTER_TBL_SEG6_F2_I               = 2622,
  NV_GSM_AMPM_MASTER_TBL_SEG7_F2_I               = 2623,
  NV_GSM_AMPM_MASTER_TBL_SEG8_F2_I               = 2624,
  NV_DCS_AMPM_MASTER_TBL_SEG1_F2_I               = 2625,
  NV_DCS_AMPM_MASTER_TBL_SEG2_F2_I               = 2626,
  NV_DCS_AMPM_MASTER_TBL_SEG3_F2_I               = 2627,
  NV_DCS_AMPM_MASTER_TBL_SEG4_F2_I               = 2628,
  NV_DCS_AMPM_MASTER_TBL_SEG5_F2_I               = 2629,
  NV_DCS_AMPM_MASTER_TBL_SEG6_F2_I               = 2630,
  NV_DCS_AMPM_MASTER_TBL_SEG7_F2_I               = 2631,
  NV_DCS_AMPM_MASTER_TBL_SEG8_F2_I               = 2632,
  NV_GSM_850_AMPM_MASTER_TBL_SEG1_F2_I           = 2633,
  NV_GSM_850_AMPM_MASTER_TBL_SEG2_F2_I           = 2634,
  NV_GSM_850_AMPM_MASTER_TBL_SEG3_F2_I           = 2635,
  NV_GSM_850_AMPM_MASTER_TBL_SEG4_F2_I           = 2636,
  NV_GSM_850_AMPM_MASTER_TBL_SEG5_F2_I           = 2637,
  NV_GSM_850_AMPM_MASTER_TBL_SEG6_F2_I           = 2638,
  NV_GSM_850_AMPM_MASTER_TBL_SEG7_F2_I           = 2639,
  NV_GSM_850_AMPM_MASTER_TBL_SEG8_F2_I           = 2640,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG1_F2_I          = 2641,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG2_F2_I          = 2642,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG3_F2_I          = 2643,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG4_F2_I          = 2644,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG5_F2_I          = 2645,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG6_F2_I          = 2646,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG7_F2_I          = 2647,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG8_F2_I          = 2648,
  NV_GSM_CALPATH_RSB_A_G1_I                      = 2649,
  NV_GSM_CALPATH_RSB_B_G1_I                      = 2650,
  NV_GSM_850_CALPATH_RSB_A_G1_I                  = 2651,
  NV_GSM_850_CALPATH_RSB_B_G1_I                  = 2652,
  NV_DCS_CALPATH_RSB_A_G1_I                      = 2653,
  NV_DCS_CALPATH_RSB_B_G1_I                      = 2654,
  NV_GSM_1900_CALPATH_RSB_A_G1_I                 = 2655,
  NV_GSM_1900_CALPATH_RSB_B_G1_I                 = 2656,
  NV_GSM_CALPATH_RSB_A_G2_I                      = 2657,
  NV_GSM_CALPATH_RSB_B_G2_I                      = 2658,
  NV_GSM_850_CALPATH_RSB_A_G2_I                  = 2659,
  NV_GSM_850_CALPATH_RSB_B_G2_I                  = 2660,
  NV_DCS_CALPATH_RSB_A_G2_I                      = 2661,
  NV_DCS_CALPATH_RSB_B_G2_I                      = 2662,
  NV_GSM_1900_CALPATH_RSB_A_G2_I                 = 2663,
  NV_GSM_1900_CALPATH_RSB_B_G2_I                 = 2664,
  NV_GSM_AMAM_GAIN_LOW_TEMP_I                    = 2665,
  NV_GSM_AMAM_DC_LOW_TEMP_I                      = 2666,
  NV_GSM_AMAM_GAIN_HIGH_TEMP_I                   = 2667,
  NV_GSM_AMAM_DC_HIGH_TEMP_I                     = 2668,
  NV_GSM_AMAM_GAIN_NOM_TEMP_I                    = 2669,
  NV_GSM_AMAM_DC_NOM_TEMP_I                      = 2670,
  NV_GSM_850_AMAM_GAIN_LOW_TEMP_I                = 2671,
  NV_GSM_850_AMAM_DC_LOW_TEMP_I                  = 2672,
  NV_GSM_850_AMAM_GAIN_HIGH_TEMP_I               = 2673,
  NV_GSM_850_AMAM_DC_HIGH_TEMP_I                 = 2674,
  NV_GSM_850_AMAM_GAIN_NOM_TEMP_I                = 2675,
  NV_GSM_850_AMAM_DC_NOM_TEMP_I                  = 2676,
  NV_DCS_AMAM_GAIN_LOW_TEMP_I                    = 2677,
  NV_DCS_AMAM_DC_LOW_TEMP_I                      = 2678,
  NV_DCS_AMAM_GAIN_HIGH_TEMP_I                   = 2679,
  NV_DCS_AMAM_DC_HIGH_TEMP_I                     = 2680,
  NV_DCS_AMAM_GAIN_NOM_TEMP_I                    = 2681,
  NV_DCS_AMAM_DC_NOM_TEMP_I                      = 2682,
  NV_GSM_1900_AMAM_GAIN_LOW_TEMP_I               = 2683,
  NV_GSM_1900_AMAM_DC_LOW_TEMP_I                 = 2684,
  NV_GSM_1900_AMAM_GAIN_HIGH_TEMP_I              = 2685,
  NV_GSM_1900_AMAM_DC_HIGH_TEMP_I                = 2686,
  NV_GSM_1900_AMAM_GAIN_NOM_TEMP_I               = 2687,
  NV_GSM_1900_AMAM_DC_NOM_TEMP_I                 = 2688,
  NV_GSM_AMAM_ARFCN_I                            = 2689,
  NV_DCS_AMAM_ARFCN_I                            = 2690,
  NV_GSM_850_AMAM_ARFCN_I                        = 2691,
  NV_GSM_1900_AMAM_ARFCN_I                       = 2692,
  NV_ABNORMAL_EXIT_COUNT_I                       = 2693,
  NV_SYS_STRUCT_FCT_FILE_NAME_I                  = 2694,
  NV_SYS_STRUCT_FCT_FILE_XSUM_I                  = 2695,
  NV_SYS_CUSTOM_INI_FILE_NAME_I                  = 2696,
  NV_SYS_CUSTOM_INI_FILE_XSUM_I                  = 2697,
  NV_SYS_STD_MAP_FILE_VER_I                      = 2698,
  NV_SYS_STD_MAP_FILE_XSUM_I                     = 2699,
  NV_SYS_SPC_DELTA_FILE_VER_I                    = 2700,
  NV_SYS_SPC_DELTA_FILE_XSUM_I                   = 2701,
  NV_LCD_ID_I                                    = 2702,
  NV_WCDMA_PA_RANGE_FOR_DVS_I                    = 2703,
  NV_WCDMA_PA_COMPENSATE_UP_WITH_DVS_I           = 2704,
  NV_WCDMA_PA_COMPENSATE_DN_WITH_DVS_I           = 2705,
  NV_WCDMA_1900_PA_RANGE_FOR_DVS_I               = 2706,
  NV_WCDMA_1900_PA_COMPENSATE_UP_WITH_DVS_I      = 2707,
  NV_WCDMA_1900_PA_COMPENSATE_DN_WITH_DVS_I      = 2708,
  NV_WCDMA_800_PA_RANGE_FOR_DVS_I                = 2709,
  NV_WCDMA_800_PA_COMPENSATE_UP_WITH_DVS_I       = 2710,
  NV_WCDMA_800_PA_COMPENSATE_DN_WITH_DVS_I       = 2711,
  NV_WCDMA_MAX_PWR_BACKOFF_VOLTAGES_I            = 2712,
  NV_WCDMA_MAX_PWR_BACKOFF_VOLT1_I               = 2713,
  NV_WCDMA_MAX_PWR_BACKOFF_VOLT2_I               = 2714,
  NV_WCDMA_MAX_PWR_BACKOFF_VOLT3_I               = 2715,
  NV_WCDMA_1900_MAX_PWR_BACKOFF_VOLTAGES_I       = 2716,
  NV_WCDMA_1900_MAX_PWR_BACKOFF_VOLT1_I          = 2717,
  NV_WCDMA_1900_MAX_PWR_BACKOFF_VOLT2_I          = 2718,
  NV_WCDMA_1900_MAX_PWR_BACKOFF_VOLT3_I          = 2719,
  NV_WCDMA_800_MAX_PWR_BACKOFF_VOLTAGES_I        = 2720,
  NV_WCDMA_800_MAX_PWR_BACKOFF_VOLT1_I           = 2721,
  NV_WCDMA_800_MAX_PWR_BACKOFF_VOLT2_I           = 2722,
  NV_WCDMA_800_MAX_PWR_BACKOFF_VOLT3_I           = 2723,
  NV_WCDMA_HS_R1_RISE_I                          = 2724,
  NV_WCDMA_HS_R1_FALL_I                          = 2725,
  NV_WCDMA_HS_R2_RISE_I                          = 2726,
  NV_WCDMA_HS_R2_FALL_I                          = 2727,
  NV_WCDMA_HS_R3_RISE_I                          = 2728,
  NV_WCDMA_HS_R3_FALL_I                          = 2729,
  NV_WCDMA_1900_HS_R1_RISE_I                     = 2730,
  NV_WCDMA_1900_HS_R1_FALL_I                     = 2731,
  NV_WCDMA_1900_HS_R2_RISE_I                     = 2732,
  NV_WCDMA_1900_HS_R2_FALL_I                     = 2733,
  NV_WCDMA_1900_HS_R3_RISE_I                     = 2734,
  NV_WCDMA_1900_HS_R3_FALL_I                     = 2735,
  NV_WCDMA_800_HS_R1_RISE_I                      = 2736,
  NV_WCDMA_800_HS_R1_FALL_I                      = 2737,
  NV_WCDMA_800_HS_R2_RISE_I                      = 2738,
  NV_WCDMA_800_HS_R2_FALL_I                      = 2739,
  NV_WCDMA_800_HS_R3_RISE_I                      = 2740,
  NV_WCDMA_800_HS_R3_FALL_I                      = 2741,
  NV_GSM_AUTOCAL_PWR_DAC_F1_I                    = 2742,
  NV_GSM_AMAM_DYNAMIC_RANGE_I                    = 2743,
  NV_DCS_AUTOCAL_PWR_DAC_F1_I                    = 2744,
  NV_DCS_AMAM_DYNAMIC_RANGE_I                    = 2745,
  NV_GSM_850_AUTOCAL_PWR_DAC_F1_I                = 2746,
  NV_GSM_850_AMAM_DYNAMIC_RANGE_I                = 2747,
  NV_GSM_1900_AUTOCAL_PWR_DAC_F1_I               = 2748,
  NV_GSM_1900_AMAM_DYNAMIC_RANGE_I               = 2749,
  NV_GSM_CALPATH_RSB_I                           = 2750,
  NV_DCS_CALPATH_RSB_I                           = 2751,
  NV_GSM_850_CALPATH_RSB_I                       = 2752,
  NV_GSM_1900_CALPATH_RSB_I                      = 2753,
  NV_GSM_AMAM_SYS_GAIN_DC_CORR_I                 = 2754,
  NV_GSM_850_AMAM_SYS_GAIN_DC_CORR_I             = 2755,
  NV_DCS_AMAM_SYS_GAIN_DC_CORR_I                 = 2756,
  NV_GSM_1900_AMAM_SYS_GAIN_DC_CORR_I            = 2757,
  NV_GSM_AMAM_ARFCN_F1_I                         = 2758,
  NV_DCS_AMAM_ARFCN_F1_I                         = 2759,
  NV_GSM_850_AMAM_ARFCN_F1_I                     = 2760,
  NV_GSM_1900_AMAM_ARFCN_F1_I                    = 2761,
  NV_GSM_AMAM_ARFCN_F2_I                         = 2762,
  NV_DCS_AMAM_ARFCN_F2_I                         = 2763,
  NV_GSM_850_AMAM_ARFCN_F2_I                     = 2764,
  NV_GSM_1900_AMAM_ARFCN_F2_I                    = 2765,
  NV_GSM_AUTOCAL_PWR_DAC_F2_I                    = 2766,
  NV_DCS_AUTOCAL_PWR_DAC_F2_I                    = 2767,
  NV_GSM_850_AUTOCAL_PWR_DAC_F2_I                = 2768,
  NV_GSM_1900_AUTOCAL_PWR_DAC_F2_I               = 2769,
  NV_GSM_POLAR_PATH_DELAY_I                      = 2770,
  NV_DCS_POLAR_PATH_DELAY_I                      = 2771,
  NV_GSM_850_POLAR_PATH_DELAY_I                  = 2772,
  NV_GSM_1900_POLAR_PATH_DELAY_I                 = 2773,
  NV_GSM_OPLL_BW_VAL_I                           = 2774,
  NV_DCS_OPLL_BW_VAL_I                           = 2775,
  NV_GSM_850_OPLL_BW_VAL_I                       = 2776,
  NV_GSM_1900_OPLL_BW_VAL_I                      = 2777,
  NV_GSM_BASEBAND_BW_VAL_I                       = 2778,
  NV_DCS_BASEBAND_BW_VAL_I                       = 2779,
  NV_GSM_850_BASEBAND_BW_VAL_I                   = 2780,
  NV_GSM_1900_BASEBAND_BW_VAL_I                  = 2781,
  NV_USB_CURRENT_DEVICE_I                        = 2782,
  NV_GPS1_MIN_NUM_SVS_I                          = 2783,
  NV_AAGPS_DEFAULT_ALLOW_RRC_I                   = 2784,
  NV_AAGPS_DEFAULT_MTLR_GUARD_TIMER_I            = 2785,
  NV_AAGPS_DEFAULT_SMLC_COMM_TIMEOUT_I           = 2786,
  NV_AAGPS_DEFAULT_PRESUPL_UE_TIMER1_VALUE_I     = 2787,
  NV_AAGPS_DEFAULT_PRESUPL_UE_TIMER2_VALUE_I     = 2788,
  NV_AAGPS_DEFAULT_PRESUPL_UE_TIMER3_VALUE_I     = 2789,
  NV_ACTIVE_EPZID_TYPE_I                         = 2790,
  NV_C0_BC0_RX_CAL_CHAN_LRU_I                    = 2791,
  NV_C1_BC0_RX_CAL_CHAN_LRU_I                    = 2792,
  NV_C0_BC1_RX_CAL_CHAN_LRU_I                    = 2793,
  NV_C1_BC1_RX_CAL_CHAN_LRU_I                    = 2794,
  NV_C0_BC3_RX_CAL_CHAN_LRU_I                    = 2795,
  NV_C1_BC3_RX_CAL_CHAN_LRU_I                    = 2796,
  NV_C0_BC4_RX_CAL_CHAN_LRU_I                    = 2797,
  NV_C1_BC4_RX_CAL_CHAN_LRU_I                    = 2798,
  NV_C0_BC5_RX_CAL_CHAN_LRU_I                    = 2799,
  NV_C1_BC5_RX_CAL_CHAN_LRU_I                    = 2800,
  NV_C0_BC6_RX_CAL_CHAN_LRU_I                    = 2801,
  NV_C1_BC6_RX_CAL_CHAN_LRU_I                    = 2802,
  NV_CCM_VERSION_INFO_I                          = 2803,
  NV_TURNOFF_COUNTER_I                           = 2804,
  NV_POWERDOWN_STATUS_I                          = 2805,
  NV_PHONE_POWER_ON_STATUS_I                     = 2806,
  NV_FIRST_POWER_ON_TIME_I                       = 2807,
  NV_SW_VERSION_INFO_I                           = 2808,
  NV_SET_DATE_FORMAT_I                           = 2809,
  NV_SET_TIME_FORMAT_I                           = 2810,
  NV_SET_SHOW_TIME_I                             = 2811,
  NV_SET_AUTO_TIME_I                             = 2812,
  NV_SET_BUDDHIST_YEAR_I                         = 2813,
  NV_BC0_HDR_P1_RISE_FALL_OFF_I                  = 2814,
  NV_BC1_HDR_P1_RISE_FALL_OFF_I                  = 2815,
  NV_BC3_HDR_P1_RISE_FALL_OFF_I                  = 2816,
  NV_BC4_HDR_P1_RISE_FALL_OFF_I                  = 2817,
  NV_BC5_HDR_P1_RISE_FALL_OFF_I                  = 2818,
  NV_BC6_HDR_P1_RISE_FALL_OFF_I                  = 2819,
  NV_DS_INCOMING_DATA_RLP_TIMEOUT_I              = 2820,
  NV_DS_DEFAULT_INACTIVITY_RESTORE_TIMEOUT_I     = 2821,
  NV_CHG_USB_NVDISABLE_VAL_I                     = 2822,
  NV_CONSORTIUM_CONFIG_I                         = 2823,
  NV_DEVICE_SERIAL_NO_I                          = 2824,
  NV_DS_MIP_RM_NAI_I                             = 2825,
  NV_SMS_BMC_READING_PREF_I                      = 2826,
  NV_VOC_HS_MIC_GAIN_ADJUST_I                    = 2827,
  NV_AUTO_POWER_OFF_I                            = 2828,
  NV_FAST_SEARCH_I                               = 2829,
  NV_UPLOADMEDIA_ALBUM_MENU_ENABLED_I            = 2830,
  NV_UPLOADMEDIA_ALBUM_ADDR_I                    = 2831,
  NV_UPLOADMEDIA_POSTCARD_MENU_ENABLED_I         = 2832,
  NV_UPLOADMEDIA_POSTCARD_SEPARATOR_I            = 2833,
  NV_UPLOADMEDIA_POSTCARD_ADDR_I                 = 2834,
  NV_UPLOADMEDIA_POSTCARD_MAX_CHARACTERS_I       = 2835,
  NV_UPLOADMEDIA_POSTCARD_MAX_RECIPIENTS_I       = 2836,
  NV_UPLOADMEDIA_POSTCARD_AUTO_SAVE_I            = 2837,
  NV_EMAIL_ACTIVE_PROFILE_I                      = 2838,
  NV_BT_ACTIVE_I                                 = 2839,
  NV_BT_VISIBLE_I                                = 2840,
  NV_BT_SAP_ENABLE_I                             = 2841,
  NV_WCLOCK_AUTO_NITZ_ZONE_DST_I                 = 2842,
  NV_TIMEZONE_I                                  = 2843,
  NV_HDRSCP_BCMCS_ENABLE_I                       = 2844,
  NV_WCDMA_1800_VGA_GAIN_OFFSET_I                = 2845,
  NV_WCDMA_1800_VGA_GAIN_OFFSET_VS_FREQ_I        = 2846,
  NV_WCDMA_1800_VGA_GAIN_OFFSET_VS_TEMP_I        = 2847,
  NV_WCDMA_1800_LNA_RANGE_RISE_2_I               = 2848,
  NV_WCDMA_1800_LNA_RANGE_RISE_3_I               = 2849,
  NV_WCDMA_1800_LNA_RANGE_FALL_2_I               = 2850,
  NV_WCDMA_1800_LNA_RANGE_FALL_3_I               = 2851,
  NV_WCDMA_1800_IM_LEVEL_2_I                     = 2852,
  NV_WCDMA_1800_IM_LEVEL_3_I                     = 2853,
  NV_WCDMA_1800_LNA_RANGE_OFFSET_2_I             = 2854,
  NV_WCDMA_1800_LNA_RANGE_OFFSET_3_I             = 2855,
  NV_WCDMA_1800_LNA_OFFSET_VS_FREQ_2_I           = 2856,
  NV_WCDMA_1800_LNA_OFFSET_VS_FREQ_3_I           = 2857,
  NV_WCDMA_1800_IM2_I_VALUE_I                    = 2858,
  NV_WCDMA_1800_IM2_Q_VALUE_I                    = 2859,
  NV_WCDMA_1800_IM2_TRANSCONDUCTOR_VALUE_I       = 2860,
  NV_WCDMA_1800_RX_AGC_MIN_2_I                   = 2861,
  NV_WCDMA_1800_RX_AGC_MIN_3_I                   = 2862,
  NV_WCDMA_1800_LNA_RANGE_RISE_I                 = 2863,
  NV_WCDMA_1800_LNA_RANGE_FALL_I                 = 2864,
  NV_WCDMA_1800_IM_LEVEL_I                       = 2865,
  NV_WCDMA_1800_NONBYPASS_TIMER_I                = 2866,
  NV_WCDMA_1800_BYPASS_TIMER_I                   = 2867,
  NV_WCDMA_1800_LNA_RANGE_OFFSET_I               = 2868,
  NV_WCDMA_1800_LNA_OFFSET_VS_FREQ_I             = 2869,
  NV_WCDMA_1800_RX_AGC_MIN_I                     = 2870,
  NV_WCDMA_1800_RX_AGC_MAX_I                     = 2871,
  NV_WCDMA_1800_AGC_PHASE_OFFSET_I               = 2872,
  NV_WCDMA_1800_TX_LIN_MASTER_0_I                = 2873,
  NV_WCDMA_1800_TX_LIN_MASTER_1_I                = 2874,
  NV_WCDMA_1800_TX_LIN_MASTER_2_I                = 2875,
  NV_WCDMA_1800_TX_LIN_MASTER_3_I                = 2876,
  NV_WCDMA_1800_TX_COMP_VS_FREQ_0_I              = 2877,
  NV_WCDMA_1800_TX_COMP_VS_FREQ_1_I              = 2878,
  NV_WCDMA_1800_TX_COMP_VS_FREQ_2_I              = 2879,
  NV_WCDMA_1800_TX_COMP_VS_FREQ_3_I              = 2880,
  NV_WCDMA_1800_TX_LIN_VS_TEMP_0_I               = 2881,
  NV_WCDMA_1800_TX_LIN_VS_TEMP_1_I               = 2882,
  NV_WCDMA_1800_TX_LIN_VS_TEMP_2_I               = 2883,
  NV_WCDMA_1800_TX_LIN_VS_TEMP_3_I               = 2884,
  NV_WCDMA_1800_TX_SLP_VS_TEMP_0_I               = 2885,
  NV_WCDMA_1800_TX_SLP_VS_TEMP_1_I               = 2886,
  NV_WCDMA_1800_TX_SLP_VS_TEMP_2_I               = 2887,
  NV_WCDMA_1800_TX_SLP_VS_TEMP_3_I               = 2888,
  NV_WCDMA_1800_R1_RISE_I                        = 2889,
  NV_WCDMA_1800_R1_FALL_I                        = 2890,
  NV_WCDMA_1800_TX_LIM_VS_TEMP_I                 = 2891,
  NV_WCDMA_1800_TX_LIM_VS_FREQ_I                 = 2892,
  NV_WCDMA_1800_ADJ_FACTOR_I                     = 2893,
  NV_WCDMA_1800_EXP_HDET_VS_AGC_I                = 2894,
  NV_WCDMA_1800_HDET_OFF_I                       = 2895,
  NV_WCDMA_1800_HDET_SPN_I                       = 2896,
  NV_WCDMA_1800_MAX_TX_POWER_I                   = 2897,
  NV_WCDMA_1800_OUT_OF_SERVICE_THRESH_I          = 2898,
  NV_WCDMA_1800_ENC_BTF_I                        = 2899,
  NV_WCDMA_1800_RX_DELAY_I                       = 2900,
  NV_WCDMA_1800_AGC_PA_ON_RISE_DELAY_I           = 2901,
  NV_WCDMA_1800_AGC_PA_ON_FALL_DELAY_I           = 2902,
  NV_WCDMA_1800_AGC_TX_ON_RISE_DELAY_I           = 2903,
  NV_WCDMA_1800_AGC_TX_ON_FALL_DELAY_I           = 2904,
  NV_WCDMA_1800_AGC_UPDATE_TX_AGC_TIME_I         = 2905,
  NV_WCDMA_1800_PA_GAIN_UP_TIME_I                = 2906,
  NV_WCDMA_1800_PA_GAIN_DOWN_TIME_I              = 2907,
  NV_WCDMA_1800_TX_ROT_ANGLE_PA_STATE_00_I       = 2908,
  NV_WCDMA_1800_TX_ROT_ANGLE_PA_STATE_01_I       = 2909,
  NV_WCDMA_1800_TX_ROT_ANGLE_PA_STATE_10_I       = 2910,
  NV_WCDMA_1800_TX_ROT_ANGLE_PA_STATE_11_I       = 2911,
  NV_RFR_VCO_COARSE_TUNING_1800_I                = 2912,
  NV_WCDMA_1800_PA_COMPENSATE_UP_I               = 2913,
  NV_WCDMA_1800_PA_COMPENSATE_DOWN_I             = 2914,
  NV_WCDMA_1800_PRACH_R1_RISE_OFFSET_I           = 2915,
  NV_WCDMA_1800_PRACH_R1_FALL_OFFSET_I           = 2916,
  NV_WCDMA_1800_TX_CAL_CHAN_I                    = 2917,
  NV_WCDMA_1800_RX_CAL_CHAN_I                    = 2918,
  NV_WCDMA_1800_R2_RISE_I                        = 2919,
  NV_WCDMA_1800_R2_FALL_I                        = 2920,
  NV_WCDMA_1800_R3_RISE_I                        = 2921,
  NV_WCDMA_1800_R3_FALL_I                        = 2922,
  NV_WCDMA_1800_PA_COMPENSATE_UP_R2_I            = 2923,
  NV_WCDMA_1800_PA_COMPENSATE_DOWN_R2_I          = 2924,
  NV_WCDMA_1800_PA_COMPENSATE_UP_R3_I            = 2925,
  NV_WCDMA_1800_PA_COMPENSATE_DOWN_R3_I          = 2926,
  NV_WCDMA_1800_PRACH_R2_RISE_OFFSET_I           = 2927,
  NV_WCDMA_1800_PRACH_R2_FALL_OFFSET_I           = 2928,
  NV_WCDMA_1800_PRACH_R3_RISE_OFFSET_I           = 2929,
  NV_WCDMA_1800_PRACH_R3_FALL_OFFSET_I           = 2930,
  NV_WCDMA_1800_PA_RANGE_MAP_I                   = 2931,
  NV_WCDMA_1800_PA_RANGE_FOR_DVS_I               = 2932,
  NV_WCDMA_1800_PA_COMPENSATE_UP_WITH_DVS_I      = 2933,
  NV_WCDMA_1800_PA_COMPENSATE_DN_WITH_DVS_I      = 2934,
  NV_WCDMA_1800_MAX_PWR_BACKOFF_VOLTAGES_I       = 2935,
  NV_WCDMA_1800_MAX_PWR_BACKOFF_VOLT1_I          = 2936,
  NV_WCDMA_1800_MAX_PWR_BACKOFF_VOLT2_I          = 2937,
  NV_WCDMA_1800_MAX_PWR_BACKOFF_VOLT3_I          = 2938,
  NV_WCDMA_1800_HS_R1_RISE_I                     = 2939,
  NV_WCDMA_1800_HS_R1_FALL_I                     = 2940,
  NV_WCDMA_1800_HS_R2_RISE_I                     = 2941,
  NV_WCDMA_1800_HS_R2_FALL_I                     = 2942,
  NV_WCDMA_1800_HS_R3_RISE_I                     = 2943,
  NV_WCDMA_1800_HS_R3_FALL_I                     = 2944,
  NV_WCDMA_1800_DCH_AGC_UPDATE_TX_AGC_TIME_I     = 2945,
  NV_WCDMA_1800_AGC_TX_ADJ_PDM_DELAY_I           = 2946,
  NV_WCDMA_1900_DCH_AGC_UPDATE_TX_AGC_TIME_I     = 2947,
  NV_WCDMA_1900_AGC_TX_ADJ_PDM_DELAY_I           = 2948,
  NV_WCDMA_800_DCH_AGC_UPDATE_TX_AGC_TIME_I      = 2949,
  NV_WCDMA_800_AGC_TX_ADJ_PDM_DELAY_I            = 2950,
  NV_WCDMA_DCH_AGC_UPDATE_TX_AGC_TIME_I          = 2951,
  NV_WCDMA_AGC_TX_ADJ_PDM_DELAY_I                = 2952,
  NV_DS_SIP_RM_NAI_I                             = 2953,
  NV_BAND_PREF_32_63_I                           = 2954,
  NV_MMS_MAX_MSG_SIZE1_I                         = 2955,
  NV_MMS_MAX_MSG_SIZE2_I                         = 2956,
  NV_MMS_MAX_MSG_SIZE3_I                         = 2957,
  NV_MMS_MAX_SIZE_USER_SELECTABLE_I              = 2958,
  NV_MMS_ACTIVE_MAX_MSG_SIZE_I                   = 2959,
  NV_MMS_ACTIVE_PROFILE_I                        = 2960,
  NV_MMS_HIDE_NUMBER_I                           = 2961,
  NV_MMS_REQ_DELIVERY_RPT_I                      = 2962,
  NV_MMS_REQ_READ_RPT_I                          = 2963,
  NV_MMS_PRIORITY_I                              = 2964,
  NV_MMS_VALIDITY_PERIOD_I                       = 2965,
  NV_MMS_SLIDE_DURATION_I                        = 2966,
  NV_MMS_RETRIEVAL_HOME_I                        = 2967,
  NV_MMS_RETRIEVAL_ROAM_I                        = 2968,
  NV_MMS_DELIVERY_TIME_I                         = 2969,
  NV_MMS_ALLOW_ANON_MSG_I                        = 2970,
  NV_MMS_CREATION_MODE_I                         = 2971,
  NV_MMS_AUTOSIG_I                               = 2972,
  NV_MMS_AUTO_SAVE_I                             = 2973,
  NV_MMS_ALLOW_READ_RPT_I                        = 2974,
  NV_MMS_ALLOW_DELIVERY_RPT_I                    = 2975,
  NV_MMS_MAX_RECIPIENTS_I                        = 2976,
  NV_MMS_MAX_STORED_MMS_I                        = 2977,
  NV_MMS_SIGNATURE_ACTIVE_TEMPLATE_I             = 2978,
  NV_BT_FILELOCATION_ONDEVICE_I                  = 2979,
  NV_WCDMA_UTRAN_TX_LIM_VS_TEMP_OFFSET_I         = 2980,
  NV_WCDMA_1800_UTRAN_TX_LIM_VS_TEMP_OFFSET_I    = 2981,
  NV_WCDMA_800_UTRAN_TX_LIM_VS_TEMP_OFFSET_I     = 2982,
  NV_WCDMA_1900_UTRAN_TX_LIM_VS_TEMP_OFFSET_I    = 2983,
  NV_SENDVIA_CFG_I                               = 2984,
  NV_PU_PROMPT_ENABLED_I                         = 2985,
  NV_USER_GREETING_I                             = 2986,
  NV_SCREENSAVER_STYLE_I                         = 2987,
  NV_SCREENSAVER_TIMEOUT_I                       = 2988,
  NV_MESSAGING_FONT_I                            = 2989,
  NV_SYNCML_DM_ACTIVEPROFILE_I                   = 2990,
  NV_SYNCML_DS_ACTIVEPROFILE_I                   = 2991,
  NV_SYNCML_SYNCDIRECTION_I                      = 2992,
  NV_SYNCML_DATATOSYNC_I                         = 2993,
  NV_SYNCML_APPSTOSYNC_I                         = 2994,
  NV_MS_SMS_ACTIVE_PROFILE_I                     = 2995,
  NV_MS_SMS_TEXT_SIZE_I                          = 2996,
  NV_MS_SMS_AUTOHEADER_I                         = 2997,
  NV_MS_SMS_AUTOSIGNATURE_I                      = 2998,
  NV_MS_SMS_HEADER_ACTIVE_TEMPLATE_I             = 2999,
  NV_MS_SMS_SIGNATURE_ACTIVE_TEMPLATE_I          = 3000,
  NV_MS_SMS_AUTOSAVE_I                           = 3001,
  NV_MS_SMS_AUTODELETE_I                         = 3002,
  NV_MS_SMS_ALLOW_EMOTICONS_I                    = 3003,
  NV_MS_SMS_MAX_SEGMENTS_I                       = 3004,
  NV_MS_SMS_MAX_RECIPIENTS_I                     = 3005,
  NV_MS_SMS_MAX_NUMBER_OF_SMS_I                  = 3006,
  NV_MS_SMS_MAX_TEMPLATES_I                      = 3007,
  NV_MS_SMS_OPCO_TYPES_SUPPORTED_I               = 3008,
  NV_MS_SMS_SMSC_ADDRESS1_I                      = 3009,
  NV_MS_SMS_SMSC_ADDRESS2_I                      = 3010,
  NV_MS_SMS_SMSC_ADDRESS3_I                      = 3011,
  NV_MS_SMS_SMSC_ADDRESS4_I                      = 3012,
  NV_MS_SMS_SMSC_ADDRESS5_I                      = 3013,
  NV_WCDMA_MAX_TX_POWER_DCH_PC4_I                = 3014,
  NV_POC_SHOW_PT_MENU_I                          = 3015,
  NV_POC_SERVER_IP1_I                            = 3016,
  NV_POC_SERVER_IP2_I                            = 3017,
  NV_POC_SERVER_PORT_I                           = 3018,
  NV_POC_NAI_I                                   = 3019,
  NV_POC_BILLING_SERVICE_I                       = 3020,
  NV_POC_GLM_PASSWORD_I                          = 3021,
  NV_POC_RTP_PORT_I                              = 3022,
  NV_POC_SIP_PORT_I                              = 3023,
  NV_POC_IS_SIG_COMP_I                           = 3024,
  NV_POC_MAX_AUTH_RETRIES_I                      = 3025,
  NV_POC_CONNECTION_PROFILE_I                    = 3026,
  NV_RF_ANTSEL_UMTS_1800_I                       = 3027,
  NV_IM_SHOW_MENU_I                              = 3028,
  NV_IM_CONNECTION_PROFILE_I                     = 3029,
  NV_IM_PRIMARY_IP_ADDR_I                        = 3030,
  NV_IM_PRIMARY_PORT_I                           = 3031,
  NV_IM_ENCODING_METHOD_I                        = 3032,
  NV_IM_SERVER_NAME_I                            = 3033,
  NV_IM_WV_VERSION_I                             = 3034,
  NV_BC0_PA_DVS_VOLTAGE_I                        = 3035,
  NV_BC1_PA_DVS_VOLTAGE_I                        = 3036,
  NV_BC3_PA_DVS_VOLTAGE_I                        = 3037,
  NV_BC4_PA_DVS_VOLTAGE_I                        = 3038,
  NV_BC5_PA_DVS_VOLTAGE_I                        = 3039,
  NV_BC6_PA_DVS_VOLTAGE_I                        = 3040,
  NV_EXT_OP_LIST_ENTRY_VALID_I                   = 3041,
  NV_EXT_OP_LIST_ENTRY_NAME_I                    = 3042,
  NV_EXT_OP_LIST_ENTRY_PLMN_I                    = 3043,
  NV_BM_BAT_STATS_I                              = 3044,
  NV_DISPLAY_LANGUAGE_OPTIONS_I                  = 3045,
  NV_DISPLAY_LANGUAGE_I                          = 3046,
  NV_INPUT_LANGUAGE_MODE_I                       = 3047,
  NV_INPUT_LANGUAGE_OPTIONS_I                    = 3048,
  NV_INPUT_LANGUAGE_I                            = 3049,
  NV_SYS_CONVERT_SCRIPT_VER_I                    = 3050,
  NV_SYS_PROD_SPEC_CONVERT_SCRIPT_VER_I          = 3051,
  NV_SYS_MANUAL_CONVERT_SCRIPT_VER_I             = 3052,
  NV_IRDA_ACTIVE_I                               = 3053,
  NV_IRDA_FILE_LOCATION_I                        = 3054,
  NV_GSM_RAMP_UP_STEPS_I                         = 3055,
  NV_GSM_RAMP_UP_RAISE_COSINE_POWER_I            = 3056,
  NV_GSM_RAMP_DOWN_STEPS_I                       = 3057,
  NV_GSM_RAMP_DOWN_RAISE_COSINE_POWER_I          = 3058,
  NV_GSM_POWER_LEVELS_I                          = 3059,
  NV_DCS_POWER_LEVELS_I                          = 3060,
  NV_GSM_850_POWER_LEVELS_I                      = 3061,
  NV_GSM_1900_POWER_LEVELS_I                     = 3062,
  NV_GSM_PA_EN_START_I                           = 3063,
  NV_GSM_ANT_TIMING_REL_TO_PA_EN_START_I         = 3064,
  NV_DCS_PA_EN_START_I                           = 3065,
  NV_DCS_ANT_TIMING_REL_TO_PA_EN_START_I         = 3066,
  NV_GSM_850_PA_EN_START_I                       = 3067,
  NV_GSM_1900_PA_EN_START_I                      = 3068,
  NV_GSM_1900_ANT_TIMING_REL_TO_PA_EN_START_I    = 3069,
  NV_GSM_PA_EN_STOP_I                            = 3070,
  NV_GSM_ANT_TIMING_REL_TO_PA_EN_STOP_I          = 3071,
  NV_DCS_PA_EN_STOP_I                            = 3072,
  NV_DCS_ANT_TIMING_REL_TO_PA_EN_STOP_I          = 3073,
  NV_GSM_850_PA_EN_STOP_I                        = 3074,
  NV_GSM_850_ANT_TIMING_REL_TO_PA_EN_STOP_I      = 3075,
  NV_GSM_1900_PA_EN_STOP_I                       = 3076,
  NV_GSM_1900_ANT_TIMING_REL_TO_PA_EN_STOP_I     = 3077,
  NV_GSM_AMAM_MASTER_TBL_SEG1_F3_I               = 3078,
  NV_GSM_AMAM_MASTER_TBL_SEG2_F3_I               = 3079,
  NV_GSM_AMAM_MASTER_TBL_SEG3_F3_I               = 3080,
  NV_GSM_AMAM_MASTER_TBL_SEG4_F3_I               = 3081,
  NV_GSM_AMAM_MASTER_TBL_SEG5_F3_I               = 3082,
  NV_GSM_AMAM_MASTER_TBL_SEG6_F3_I               = 3083,
  NV_GSM_AMAM_MASTER_TBL_SEG7_F3_I               = 3084,
  NV_GSM_AMAM_MASTER_TBL_SEG8_F3_I               = 3085,
  NV_DCS_AMAM_MASTER_TBL_SEG1_F3_I               = 3086,
  NV_DCS_AMAM_MASTER_TBL_SEG2_F3_I               = 3087,
  NV_DCS_AMAM_MASTER_TBL_SEG3_F3_I               = 3088,
  NV_DCS_AMAM_MASTER_TBL_SEG4_F3_I               = 3089,
  NV_DCS_AMAM_MASTER_TBL_SEG5_F3_I               = 3090,
  NV_DCS_AMAM_MASTER_TBL_SEG6_F3_I               = 3091,
  NV_DCS_AMAM_MASTER_TBL_SEG7_F3_I               = 3092,
  NV_DCS_AMAM_MASTER_TBL_SEG8_F3_I               = 3093,
  NV_GSM_850_AMAM_MASTER_TBL_SEG1_F3_I           = 3094,
  NV_GSM_850_AMAM_MASTER_TBL_SEG2_F3_I           = 3095,
  NV_GSM_850_AMAM_MASTER_TBL_SEG3_F3_I           = 3096,
  NV_GSM_850_AMAM_MASTER_TBL_SEG4_F3_I           = 3097,
  NV_GSM_850_AMAM_MASTER_TBL_SEG5_F3_I           = 3098,
  NV_GSM_850_AMAM_MASTER_TBL_SEG6_F3_I           = 3099,
  NV_GSM_850_AMAM_MASTER_TBL_SEG7_F3_I           = 3100,
  NV_GSM_850_AMAM_MASTER_TBL_SEG8_F3_I           = 3101,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG1_F3_I          = 3102,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG2_F3_I          = 3103,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG3_F3_I          = 3104,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG4_F3_I          = 3105,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG5_F3_I          = 3106,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG6_F3_I          = 3107,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG7_F3_I          = 3108,
  NV_GSM_1900_AMAM_MASTER_TBL_SEG8_F3_I          = 3109,
  NV_GSM_AMPM_MASTER_TBL_SEG1_F3_I               = 3110,
  NV_GSM_AMPM_MASTER_TBL_SEG2_F3_I               = 3111,
  NV_GSM_AMPM_MASTER_TBL_SEG3_F3_I               = 3112,
  NV_GSM_AMPM_MASTER_TBL_SEG4_F3_I               = 3113,
  NV_GSM_AMPM_MASTER_TBL_SEG5_F3_I               = 3114,
  NV_GSM_AMPM_MASTER_TBL_SEG6_F3_I               = 3115,
  NV_GSM_AMPM_MASTER_TBL_SEG7_F3_I               = 3116,
  NV_GSM_AMPM_MASTER_TBL_SEG8_F3_I               = 3117,
  NV_DCS_AMPM_MASTER_TBL_SEG1_F3_I               = 3118,
  NV_DCS_AMPM_MASTER_TBL_SEG2_F3_I               = 3119,
  NV_DCS_AMPM_MASTER_TBL_SEG3_F3_I               = 3120,
  NV_DCS_AMPM_MASTER_TBL_SEG4_F3_I               = 3121,
  NV_DCS_AMPM_MASTER_TBL_SEG5_F3_I               = 3122,
  NV_DCS_AMPM_MASTER_TBL_SEG6_F3_I               = 3123,
  NV_DCS_AMPM_MASTER_TBL_SEG7_F3_I               = 3124,
  NV_DCS_AMPM_MASTER_TBL_SEG8_F3_I               = 3125,
  NV_GSM_850_AMPM_MASTER_TBL_SEG1_F3_I           = 3126,
  NV_GSM_850_AMPM_MASTER_TBL_SEG2_F3_I           = 3127,
  NV_GSM_850_AMPM_MASTER_TBL_SEG3_F3_I           = 3128,
  NV_GSM_850_AMPM_MASTER_TBL_SEG4_F3_I           = 3129,
  NV_GSM_850_AMPM_MASTER_TBL_SEG5_F3_I           = 3130,
  NV_GSM_850_AMPM_MASTER_TBL_SEG6_F3_I           = 3131,
  NV_GSM_850_AMPM_MASTER_TBL_SEG7_F3_I           = 3132,
  NV_GSM_850_AMPM_MASTER_TBL_SEG8_F3_I           = 3133,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG1_F3_I          = 3134,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG2_F3_I          = 3135,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG3_F3_I          = 3136,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG4_F3_I          = 3137,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG5_F3_I          = 3138,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG6_F3_I          = 3139,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG7_F3_I          = 3140,
  NV_GSM_1900_AMPM_MASTER_TBL_SEG8_F3_I          = 3141,
  NV_GSM_AMAM_ARFCN_F3_I                         = 3142,
  NV_DCS_AMAM_ARFCN_F3_I                         = 3143,
  NV_GSM_850_AMAM_ARFCN_F3_I                     = 3144,
  NV_GSM_1900_AMAM_ARFCN_F3_I                    = 3145,
  NV_GSM_AUTOCAL_PWR_DAC_F3_I                    = 3146,
  NV_DCS_AUTOCAL_PWR_DAC_F3_I                    = 3147,
  NV_GSM_850_AUTOCAL_PWR_DAC_F3_I                = 3148,
  NV_GSM_1900_AUTOCAL_PWR_DAC_F3_I               = 3149,
  NV_GSM_850_ANT_TIMING_REL_TO_PA_EN_START_I     = 3150,
  NV_GSM_RTR6250_RSB_I                           = 3151,
  NV_DCS_RTR6250_RSB_I                           = 3152,
  NV_GSM_850_RTR6250_RSB_I                       = 3153,
  NV_GSM_1900_RTR6250_RSB_I                      = 3154,
  NV_DISPLAY_LANGUAGE_AUTO_I                     = 3155,
  NV_INPUT_LANGUAGE_AUTO_I                       = 3156,
  NV_BROWSER_DISPLAY_SPLASH_I                    = 3157,
  NV_BROWSER_HTTP_REFERER_I                      = 3158,
  NV_BROWSER_ACTIVE_PROFILE_I                    = 3159,
  NV_BROWSER_DISABLE_IMAGE_I                     = 3160,
  NV_BROWSER_DISABLE_SOUND_I                     = 3161,
  NV_BROWSER_DISABLE_OBJECT_I                    = 3162,
  NV_BROWSER_MAILTO_PHONENUM_I                   = 3163,
  NV_BROWSER_MAILTO_EMAIL_I                      = 3164,
  NV_BROWSER_COOKIE_ENABLE_I                     = 3165,
  NV_BROWSER_SECURE_PROMPT_I                     = 3166,
  NV_BROWSER_IDCACHE_I                           = 3167,
  NV_BROWSER_TITLE_REGION_I                      = 3168,
  NV_BROWSER_SHOWSESSIONINFO_I                   = 3169,
  NV_CURRENTLY_ACTIVE_PROFILE_I                  = 3170,
  NV_ALLOW_MP3_RINGERS_I                         = 3171,
  NV_ALLOW_AACPLUS_RINGERS_I                     = 3172,
  NV_ALLOW_NON_DRM_RINGERS_I                     = 3173,
  NV_CBS_ENABLED_I                               = 3174,
  NV_CBS_MAX_TOPIC_INDEX_I                       = 3175,
  NV_CBS_MIN_TOPIC_INDEX_I                       = 3176,
  NV_CBS_ALLOW_RECEIVE_I                         = 3177,
  NV_CBS_DISPLAY_CELL_INFO_I                     = 3178,
  NV_CBS_NUM_SELECTED_TOPICS_I                   = 3179,
  NV_IRDA_DEVICE_NAME_I                          = 3180,
  NV_IRDA_PNP_DEVICE_ID_I                        = 3181,
  NV_IRDA_PNP_MANUFACTURER_I                     = 3182,
  NV_IRDA_PNP_NAME_I                             = 3183,
  NV_IRDA_PNP_DEVICE_CATEGORY_I                  = 3184,
  NV_IRDA_PNP_COMPATIBILITY_COUNT_I              = 3185,
  NV_IRDA_PNP_STATUS_I                           = 3186,
  NV_IRDA_PNP_VERSION_I                          = 3187,
  NV_DISPLAY_LANGUAGE_GROUP_NUM_I                = 3188,
  NV_POC_AUTO_ANSWER_I                           = 3189,
  NV_POC_INCOMING_CALL_TIMEOUT_I                 = 3190,
  NV_POC_AUTO_LOGIN_I                            = 3191,
  NV_POC_WILDCARDS_I                             = 3192,
  NV_POC_HISTORY_LENGTH_I                        = 3193,
  NV_POC_SECONDARY_PDP_CONTEXT_I                 = 3194,
  NV_POC_EARLY_SESSION_I                         = 3195,
  NV_POC_QOS_MODE_I                              = 3196,
  NV_POC_MAX_CONCURRENT_USER_LIMIT1_I            = 3197,
  NV_POC_MAX_CONCURRENT_USER_LIMIT2_I            = 3198,
  NV_POC_MAX_CONCURRENT_USER_LIMIT3_I            = 3199,
  NV_POC_BUFFERED_PACKETS_I                      = 3200,
  NV_POC_SPEAKER_PHONE_I                         = 3201,
  NV_IM_NOTIFICATION_I                           = 3202,
  NV_IM_AUTO_LOGIN_I                             = 3203,
  NV_IM_SUPPORTED_BEARERS_I                      = 3204,
  NV_IM_SUPPORTED_CIR_METHODS_I                  = 3205,
  NV_IM_MAX_SEARCH_RESULTS_I                     = 3206,
  NV_IM_SHORT_LOGIN_SEQUENCE_I                   = 3207,
  NV_IM_NO_CONTACTS_EXIST_I                      = 3208,
  NV_IM_SEND_FILE_DISABLED_I                     = 3209,
  NV_IM_VERSION_DISCOVERY_I                      = 3210,
  NV_IM_LOGIN_TYPE_I                             = 3211,
  NV_IM_INITIAL_DELIVERY_METHOD_I                = 3212,
  NV_IM_ANY_CONTENT_I                            = 3213,
  NV_IM_ACCEPTED_CHAR_SETS_I                     = 3214,
  NV_IM_ACCEPTED_CONTENT_TYPES_I                 = 3215,
  NV_IM_ACCEPTED_TRANSFER_ENCODINGS_I            = 3216,
  NV_IM_ACCEPTED_CONTENT_LENGTH_I                = 3217,
  NV_IM_PARSER_SIZE_I                            = 3218,
  NV_IM_MAX_SAVED_CONVERSATIONS_I                = 3219,
  NV_IM_MAX_CONCURRENT_CONVERSATIONS_I           = 3220,
  NV_IM_SUPPORTED_BEARER_COUNT_I                 = 3221,
  NV_IM_SERVER_PORT_I                            = 3222,
  NV_IM_HIDE_SERVER_I                            = 3223,
  NV_IM_ALLOW_CHANGE_SERVER_I                    = 3224,
  NV_IM_INTERNET_PROFILE_I                       = 3225,
  NV_IM_KNOCK_SERVICE_TIMEOUT_I                  = 3226,
  NV_IM_PASSWORD_I                               = 3227,
  NV_IM_CIR_PORT_I                               = 3228,
  NV_IM_SCHEMA_COUNT_I                           = 3229,
  NV_IM_CIR_METHODS_COUNT_I                      = 3230,
  NV_IM_MULTIPLE_TRANSACTIONS_I                  = 3231,
  NV_IM_SMSC_ADDRESS_I                           = 3232,
  NV_IM_OPTIONAL_HEADER_I                        = 3233,
  NV_IM_DIGEST_SCHEMAS_I                         = 3234,
  NV_POC_LIMIT_SELECTION_I                       = 3235,
  NV_IM_USERID_I                                 = 3236,
  NV_BC0_VCO_TUNE_2_I                            = 3237,
  NV_BC1_VCO_TUNE_2_I                            = 3238,
  NV_BC3_VCO_TUNE_2_I                            = 3239,
  NV_BC4_VCO_TUNE_2_I                            = 3240,
  NV_BC5_VCO_TUNE_2_I                            = 3241,
  NV_BC6_VCO_TUNE_2_I                            = 3242,
  NV_MM_ENABLE_REAL_I                            = 3243,
  NV_DIAG_DEBUG_CALL_TRACE_I                     = 3244,
  NV_ENABLE_FASTTRACK_I                          = 3245,
  NV_IM_EDIT_MESSENGER_ID_PSWD_I                 = 3246,
  NV_IM_SAFETY_TIP_I                             = 3247,
  NV_IM_START_STRING_I                           = 3248,
  NV_IM_MAX_RECEIVED_FILE_LIMIT_I                = 3249,
  NV_WAP_AUTO_CONNECT_I                          = 3250,
  NV_WAP_LOCKOUT_TIME_I                          = 3251,
  NV_DIAG_SPC_UNLOCK_TTL_I                       = 3252,
  NV_C0_BC0_IM2_LPM_1_I                          = 3253,
  NV_C0_BC1_IM2_LPM_1_I                          = 3254,
  NV_C0_BC3_IM2_LPM_1_I                          = 3255,
  NV_C0_BC4_IM2_LPM_1_I                          = 3256,
  NV_C0_BC5_IM2_LPM_1_I                          = 3257,
  NV_C0_BC6_IM2_LPM_1_I                          = 3258,
  NV_C0_BC0_IM2_LPM_2_I                          = 3259,
  NV_C0_BC1_IM2_LPM_2_I                          = 3260,
  NV_C0_BC3_IM2_LPM_2_I                          = 3261,
  NV_C0_BC4_IM2_LPM_2_I                          = 3262,
  NV_C0_BC5_IM2_LPM_2_I                          = 3263,
  NV_C0_BC6_IM2_LPM_2_I                          = 3264,
  NV_C0_BC0_INTELLICEIVER_CAL_I                  = 3265,
  NV_C0_BC1_INTELLICEIVER_CAL_I                  = 3266,
  NV_C0_BC3_INTELLICEIVER_CAL_I                  = 3267,
  NV_C0_BC4_INTELLICEIVER_CAL_I                  = 3268,
  NV_C0_BC5_INTELLICEIVER_CAL_I                  = 3269,
  NV_C0_BC6_INTELLICEIVER_CAL_I                  = 3270,
  NV_C0_BC0_LNA_SWITCHPOINTS_LPM_1_I             = 3271,
  NV_C0_BC1_LNA_SWITCHPOINTS_LPM_1_I             = 3272,
  NV_C0_BC3_LNA_SWITCHPOINTS_LPM_1_I             = 3273,
  NV_C0_BC4_LNA_SWITCHPOINTS_LPM_1_I             = 3274,
  NV_C0_BC5_LNA_SWITCHPOINTS_LPM_1_I             = 3275,
  NV_C0_BC6_LNA_SWITCHPOINTS_LPM_1_I             = 3276,
  NV_C0_BC0_LNA_SWITCHPOINTS_LPM_2_I             = 3277,
  NV_C0_BC1_LNA_SWITCHPOINTS_LPM_2_I             = 3278,
  NV_C0_BC3_LNA_SWITCHPOINTS_LPM_2_I             = 3279,
  NV_C0_BC4_LNA_SWITCHPOINTS_LPM_2_I             = 3280,
  NV_C0_BC5_LNA_SWITCHPOINTS_LPM_2_I             = 3281,
  NV_C0_BC6_LNA_SWITCHPOINTS_LPM_2_I             = 3282,
  NV_RFR_VCO_COARSE_TUNING_800_I                 = 3283,
  NV_POC_NETINITDEREG_I                          = 3284,
  NV_POC_APP_TIMEOUT_I                           = 3285,
  NV_POC_REGISTRATION_TIMEOUT_I                  = 3286,
  NV_POC_GLM_TIMEOUT_I                           = 3287,
  NV_JAVA_CONNECTION_PROFILE_ID_I                = 3288,
  NV_JAVA_INTERNET_PROFILE_ID_I                  = 3289,
  NV_ENABLE_EXT_GPS_ANTENNA_PWR_SUPPLY_I         = 3290,
  NV_PRESUPL_WAP_GATEWAY_ADDRESS_I               = 3291,
  NV_PRESUPL_WAP_GATEWAY_PORT_I                  = 3292,
  NV_GPS1_POSITION_REPORT_I                      = 3293,
  NV_SET_VOICE_CALL_TONE_I                       = 3294,
  NV_CONN_PROFILE_UNPW_RO_OVERRIDE_I             = 3295,
  NV_INTERNET_PROFILE_UNPW_RO_OVERRIDE_I         = 3296,
  NV_AAGPS_RTI_VALIDITY_DUR_I                    = 3297,
  NV_IPV6_UMTS_FAILOVER_CONFIG_I                 = 3298,
  NV_POC_FORBID_CHANGE_USERID_I                  = 3299,
  NV_POC_WTUSER_PASSWORD_I                       = 3300,
  NV_CBS_MAX_MSG_PER_TOPIC_I                     = 3301,
  NV_BROWSER_FWDURL_TO_I                         = 3302,
  NV_BROWSER_WAP_SIM_COMBINELOCK_I               = 3303,
  NV_BROWSER_STARTPAGE_READONLY_I                = 3304,
  NV_CMGR_DISPLAY_RO_FOR_MISSING_DCF_I           = 3305,
  NV_CMGR_PROMPT_FOR_RO_DELETE_I                 = 3306,
  NV_CMGR_AUTO_REDIRECT_TO_LICENSE_SERVER_I      = 3307,
  NV_SET_DRM_CONTENT_PROMPT_I                    = 3308,
  NV_CMGR_WD_REMAINING_HOURS_1_THRESHOLD_I       = 3309,
  NV_CMGR_WD_REMAINING_HOURS_2_THRESHOLD_I       = 3310,
  NV_CMGR_WD_RUN_EVERY_HOURS_I                   = 3311,
  NV_SET_DRM_EXPIRE_WARNING_I                    = 3312,
  NV_CMGR_MAX_PREVIEW_DATA_SIZE_I                = 3313,
  NV_BROWSER_DISABLE_IMAGE_RO_I                  = 3314,
  NV_BROWSER_DISABLE_SOUND_RO_I                  = 3315,
  NV_BROWSER_TIMEOUT_I                           = 3316,
  NV_BROWSER_TIMEOUT_RO_I                        = 3317,
  NV_BROWSER_SECURE_PROMPT_RO_I                  = 3318,
  NV_BROWSER_FONTSIZE_I                          = 3319,
  NV_BROWSER_TEXTWRAP_I                          = 3320,
  NV_BROWSER_SCROLLSTEP_I                        = 3321,
  NV_BROWSER_EXIT_PROMPT_I                       = 3322,
  NV_PU_FORCE_ON_I                               = 3323,
  NV_BROWSER_JUMP_PORTAL_NAME_I                  = 3324,
  NV_BROWSER_JUMP_EMBDLNK1_NAME_I                = 3325,
  NV_BROWSER_JUMP_EMBDLNK2_NAME_I                = 3326,
  NV_BROWSER_JUMP_EMBDLNK3_NAME_I                = 3327,
  NV_BROWSER_JUMP_EMBDLNK4_NAME_I                = 3328,
  NV_BROWSER_JUMP_EMBDLNK5_NAME_I                = 3329,
  NV_BROWSER_JUMP_EMBDLNK6_NAME_I                = 3330,
  NV_BROWSER_JUMP_EMBDLNK7_NAME_I                = 3331,
  NV_BROWSER_JUMP_EMBDLNK8_NAME_I                = 3332,
  NV_VOICE_MAIL_LINE1_I                          = 3333,
  NV_VOICE_MAIL_USE_SIM_NUMBER_I                 = 3334,
  NV_VOICE_MAIL_NOTIFY_I                         = 3335,
  NV_VOICE_MAIL_LINE2_I                          = 3336,
  NV_CAMERA_APP_SAVE_LOCATION_I                  = 3337,
  NV_VT_SHOW_MY_IMAGE_I                          = 3338,
  NV_VT_AUTO_REDIAL_I                            = 3339,
  NV_SET_RINGER_VOLUME_I                         = 3340,
  NV_WCDMA_C0_TX_LIM_VS_FREQ_I                   = 3341,
  NV_SOS_KEY_ENABLED_I                           = 3342,
  NV_SOS_NUMBER_I                                = 3343,
  NV_WAP_TRUSTED_DOMAIN_I                        = 3344,
  NV_WAP_PUSH_AUTOLOAD_I                         = 3345,
  NV_IM_SERVER_ADDRESS_I                         = 3346,
  NV_POC_TIMEOUT_SCALE_I                         = 3347,
  NV_MR_DEFAULTS_STORED_I                        = 3348,
  NV_SET_PLAY_STARTUP_SOUND_I                    = 3349,
  NV_SET_PLAY_SHUTDOWN_SOUND_I                   = 3350,
  NV_SET_PLAY_STARTUP_ANIMATION_I                = 3351,
  NV_SET_PLAY_SHUTDOWN_ANIMATION_I               = 3352,
  NV_GSM_POLAR_RAMP_PROFILE_I                    = 3353,
  NV_GPS1_MSB_BACK_OFF_FACTOR_I                  = 3354,
  NV_GPS1_MSB_BACK_OFF_MIN_I                     = 3355,
  NV_GPS1_MSB_BACK_OFF_MAX_I                     = 3356,
  NV_GPS1_MSB_BACK_OFF_RESET_I                   = 3357,
  NV_GPS1_MSB_THROTTLE_ENABLE_I                  = 3358,
  NV_MANUAL_PLMN_SEL_I                           = 3359,
  NV_MANUAL_PLMN_SELECTION_I                     = 3360,
  NV_CONSORTIUM_CONFIG_NUMB_I                    = 3361,
  NV_HDR_EQUALIZER_CTRL_I                        = 3362,
  NV_WLAN_ENABLE_PS_MODE_I                       = 3363,
  NV_MF_700_LNA_RISE_2_I                         = 3364,
  NV_MF_700_LNA_RISE_3_I                         = 3365,
  NV_MF_700_LNA_RISE_4_I                         = 3366,
  NV_MF_700_LNA_FALL_2_I                         = 3367,
  NV_MF_700_LNA_FALL_3_I                         = 3368,
  NV_MF_700_LNA_FALL_4_I                         = 3369,
  NV_MF_700_AGC_VS_FREQ_I                        = 3370,
  NV_MF_700_RX_CAL_CHAN_I                        = 3371,
  NV_MF_HW_CONFIG_I                              = 3372,
  NV_MF_BAND_CONFIG_I                            = 3373,
  NV_MF_AFC_LOOP_PARAMS_I                        = 3374,
  NV_LAST_REGISTERED_SCI_I                       = 3375,
  NV_MMS_MAX_CHARS_SLIDE_I                       = 3376,
  NV_MMS_MAX_NUMBER_OF_SLIDES_I                  = 3377,
  NV_MMS_MAX_SUBJECT_SIZE_I                      = 3378,
  NV_QVP_APP_DEFAULT_AUDIO_CAPABILITY_TYPE_I     = 3379,
  NV_QVP_APP_DEFAULT_VIDEO_CAPABILITY_TYPE_I     = 3380,
  NV_HDRMRLP_NUM_BYTES_TO_LOG_I                  = 3381,
  NV_SECTIME_TIME_OFFSETS_I                      = 3382,
  NV_DS_UCSD_NT_CONNECT_STATE_I                  = 3383,
  NV_PB_RECORDASOUND_I                           = 3384,
  NV_PB_AUTO_POWER_OFF_I                         = 3385,
  NV_BC0_HDR_G0_IM_FALL_I                        = 3386,
  NV_BC0_HDR_G0_IM_RISE_I                        = 3387,
  NV_BC0_HDR_G0_IM_LEVEL_I                       = 3388,
  NV_SET_LINGER_TIME_I                           = 3389,
  NV_PB_SIM_DEFAULTNUMBERPRIORITY_FIRST_I        = 3390,
  NV_PB_SIM_DEFAULTNUMBERPRIORITY_SECOND_I       = 3391,
  NV_PB_SIM_DEFAULTNUMBERPRIORITY_THIRD_I        = 3392,
  NV_PB_DEFAULT_SORTING_I                        = 3393,
  NV_SND_SEND_RESTRICTED_I                       = 3394,
  NV_POC_ROAMIING_ALERT_ENABLED_I                = 3395,
  NV_GSM_850_PRECHARGE_I                         = 3396,
  NV_GSM_850_PRECHARGE_DUR_I                     = 3397,
  NV_GSM_1900_PRECHARGE_I                        = 3398,
  NV_GSM_1900_PRECHARGE_DUR_I                    = 3399,
  NV_MS_SMS_USE_SMSC_FROM_SIM_I                  = 3400,
  NV_BROWSER_JUMP_MENU_SETTING_ENABLED_I         = 3401,
  NV_BROWSER_DRM_WAIT_TIME_I                     = 3402,
  NV_LC_ENABLED_I                                = 3403,
  NV_LC_SERVICENAME_I                            = 3404,
  NV_LC_CONNECTIONPROFILE_I                      = 3405,
  NV_LC_INTERNETPROFILE_I                        = 3406,
  NV_LC_UDPPUSHSERVERNAME_I                      = 3407,
  NV_LC_UDPPUSHSERVERPORT_I                      = 3408,
  NV_LC_UDPPUSHRETRYTIMES_I                      = 3409,
  NV_LC_UDPPUSHRETRYSECONDS_I                    = 3410,
  NV_LC_MSGASSEMBLYTIMEOUT_I                     = 3411,
  NV_LC_TICKERTIMEOUT_I                          = 3412,
  NV_LC_TICKERSPEED_I                            = 3413,
  NV_LC_TICKERSTARTDELAY_I                       = 3414,
  NV_LC_MAXTICKERITEMS_I                         = 3415,
  NV_LC_BACKLIGHTTIMEOUT_I                       = 3416,
  NV_LC_TRUSTEDDOMAIN_I                          = 3417,
  NV_LC_SUBURL_KEY_LABEL_I                       = 3418,
  NV_HOMEZONE_ENABLED_I                          = 3419,
  NV_BC0_ANT_QUALITY_I                           = 3420,
  NV_BC1_ANT_QUALITY_I                           = 3421,
  NV_BC3_ANT_QUALITY_I                           = 3422,
  NV_BC4_ANT_QUALITY_I                           = 3423,
  NV_BC5_ANT_QUALITY_I                           = 3424,
  NV_BC6_ANT_QUALITY_I                           = 3425,
  NV_MEDIA_PLAYER_MIN_UDP_PORT_I                 = 3426,
  NV_MEDIA_PLAYER_MAX_UDP_PORT_I                 = 3427,
  NV_MEDIA_PLAYER_CONN_PROF_I                    = 3428,
  NV_MEDIA_PLAYER_QOS_ENABLE_I                   = 3429,
  NV_GPS1_NUM_SEARCHER_TASKS_I                   = 3430,
  NV_GSM_PA_TRANSITION_TABLE_I                   = 3431,
  NV_K_KEY_I                                     = 3432,
  NV_CIPHER_KEY_I                                = 3433,
  NV_INT_KEY_I                                   = 3434,
  NV_LAST_3G_KEY_ID_I                            = 3435,
  NV_SSEQ_I                                      = 3436,
  NV_CK_THRESHOLD_I                              = 3437,
  NV_SEQ_ARR_1_I                                 = 3438,
  NV_SEQ_ARR_2_I                                 = 3439,
  NV_WCDMA_MIN_TX_POWER_I                        = 3440,
  NV_CCBS_SEL_I                                  = 3441,
  NV_HOME_SCREEN_ENABLED_I                       = 3442,
  NV_HOME_SCREEN_LAYOUT_I                        = 3443,
  NV_IS_THM_INITIALIZED_I                        = 3444,
  NV_HEAPTRACKER_ENABLED_I                       = 3445,
  NV_TRM_CONFIG_I                                = 3446,
  NV_IRDA_INACTIVITY_TIMER_I                     = 3447,
  NV_MMS_MAX_TEMPLATES_I                         = 3448,
  NV_MMS_TEXT_SIZE_I                             = 3449,
  NV_VIDEO_APP_SAVE_LOCATION_I                   = 3450,
  NV_CAMERA_DEFAULT_NAME_PREFIX_I                = 3451,
  NV_VIDEO_DEFAULT_NAME_PREFIX_I                 = 3452,
  NV_CAMERA_AUDIO_RECORD_I                       = 3453,
  NV_CAMERA_PICT_RESOLUTION_FRONT_I              = 3454,
  NV_CAMERA_PICT_RESOLUTION_BACK_I               = 3455,
  NV_CAMERA_VIDEO_RESOLUTION_FRONT_I             = 3456,
  NV_CAMERA_VIDEO_RESOLUTION_BACK_I              = 3457,
  NV_HDRSCP_SUBTYPE_CUSTOM_CONFIG_I              = 3458,
  NV_SET_LINGER_TIME_MENU_ENABLE_I               = 3459,
  NV_JAVA_SHOW_LOGO_ON_START_I                   = 3460,
  NV_ENS_ENABLED_I                               = 3461,
  NV_DIAG_SPC_TIMEOUT_I                          = 3462,
  NV_MS_SMS_HEADER_TEMPLATE_FILE_I               = 3463,
  NV_MS_SMS_SIGNATURE_TEMPLATE_FILE_I            = 3464,
  NV_HDRIDLE_ENHANCED_CONFIG_I                   = 3465,
  NV_HDRIDLE_SLOT_CYCLE_TIMEOUTS_I               = 3466,
  NV_BACK_LIGHT_INTENSITY_I                      = 3467,
  NV_DISPLAY_DURATION_I                          = 3468,
  NV_C0_BC0_INTELLICEIVER_DET_THRESH_I           = 3469,
  NV_C0_BC1_INTELLICEIVER_DET_THRESH_I           = 3470,
  NV_C0_BC3_INTELLICEIVER_DET_THRESH_I           = 3471,
  NV_C0_BC4_INTELLICEIVER_DET_THRESH_I           = 3472,
  NV_C0_BC5_INTELLICEIVER_DET_THRESH_I           = 3473,
  NV_C0_BC6_INTELLICEIVER_DET_THRESH_I           = 3474,
  NV_SET_VOICE_VOLUME_I                          = 3475,
  NV_SET_MEDIA_VOLUME_I                          = 3476,
  NV_HDRRMAC_CONFIG_I                            = 3477,
  NV_GPS1_CROSS_CORR_THRESHOLD_DBHZ_I            = 3478,
  NV_GPS1_CME_T_TRACK_THRESHOLD_I                = 3479,
  NV_GPS1_VX_LCSAGENT_V2_HANDOFF_ENABLE_I        = 3480,
  NV_GPS1_VX_LCSAGENT_MO_BACKOFF_DURATION_I      = 3481,
  NV_ODM_BACKLIGHT_INTENSITY_I                   = 3482,
  NV_ODM_POWER_SAVE_TIMEOUT_I                    = 3483,
  NV_ODM_BACKLIGHT_TIMEOUT_I                     = 3484,
  NV_TIMEZONE_CITY_I                             = 3485,
  NV_SIGMAREJECT_I                               = 3486,
  NV_VELNOISEINONESECDRIVE_I                     = 3487,
  NV_VELNOISEINONESECPED_I                       = 3488,
  NV_VELNOISEINONESECSTATIC_I                    = 3489,
  NV_EXTRACLOCKBIASERROR_I                       = 3490,
  NV_CONFIGMASK_I                                = 3491,
  NV_MAXPROPAGATIONWONEWMEAS_I                   = 3492,
  NV_CONFIGCONTROLFLAG_I                         = 3493,
  NV_AAGPS_DEVELOPMENT_TEST_CONTROL6_I           = 3494,
  NV_SET_ALARM_CLOCK_TONE_SETTING_I              = 3495,
  NV_SYS_DEFAULT_EFS_FILE_NAME_I                 = 3496,
  NV_SYS_EFS_FILE_NAME_I                         = 3497,
  NV_SYS_DEFAULT_NV_INI_FILE_NAME_I              = 3498,
  NV_SYS_NV_INI_FILE_NAME_I                      = 3499,
  NV_SYS_SCRIPT_FILE_NAME_I                      = 3500,
  NV_GSM_GAINRANGE5_SWITCHPOINTS_I               = 3501,
  NV_GSM_RX_GAIN_RANGE_5_FREQ_COMP_I             = 3502,
  NV_DCS_RX_GAIN_RANGE_5_FREQ_COMP_I             = 3503,
  NV_GSM_850_RX_GAIN_RANGE_5_FREQ_COMP_I         = 3504,
  NV_GSM_1900_RX_GAIN_RANGE_5_FREQ_COMP_I        = 3505,
  NV_DCS_GAINRANGE5_SWITCHPOINTS_I               = 3506,
  NV_GSM_850_GAINRANGE5_SWITCHPOINTS_I           = 3507,
  NV_GSM_1900_GAINRANGE5_SWITCHPOINTS_I          = 3508,
  NV_DCS_POLAR_RAMP_PROFILE_I                    = 3509,
  NV_GSM_1900_POLAR_RAMP_PROFILE_I               = 3510,
  NV_GSM_850_POLAR_RAMP_PROFILE_I                = 3511,
  NV_WCDMA_TX_LIM_VS_TEMP_VOICE_CALL_ACTIVE_I    = 3512,
  NV_HDRBCMCS_DISABLE_ONE_TIME_REG_I             = 3513,
  NV_HDRBCMCS_DISABLE_SUBNET_REG_I               = 3514,
  NV_CDMA_RX_CHAIN_SEL_THRESH_I                  = 3515,
  NV_SET_AUTO_KEYLOCK_I                          = 3516,
  NV_SET_ANY_KEY_ANSWER_I                        = 3517,
  NV_VP_FRAME_RATE_I                             = 3518,
  NV_DYN_CLOCK_VOLTAGE_I                         = 3519,
  NV_GPS1_SEEDPOS_OPTION_I                       = 3520,
  NV_MS_SEND_ATTEMPTS_I                          = 3521,
  NV_MS_PERIOD_BETW_SEND_ATTEMPTS_I              = 3522,
  NV_MS_SEND_IN_BACKGROUND_I                     = 3523,
  NV_WCDMA_DL_FREQ_I                             = 3524,
  NV_WCDMA_DL_FREQ_ENABLED_I                     = 3525,
  NV_MS_SMS_SMSC_ADDRESS6_I                      = 3526,
  NV_MS_SMS_SMSC_ADDRESS7_I                      = 3527,
  NV_MS_SMS_SMSC_ADDRESS8_I                      = 3528,
  NV_MS_SMS_SMSC_ADDRESS9_I                      = 3529,
  NV_MS_SMS_SMSC_ADDRESS10_I                     = 3530,
  NV_AUTO_TIME_ENABLE_I                          = 3531,
  NV_SMS_MO_RETRY_PERIOD_I                       = 3532,
  NV_SMS_MO_RETRY_INTERVAL_I                     = 3533,
  NV_RMNET_AUTOCONNECT_I                         = 3534,
  NV_ENABLE_BT_DIAG_I                            = 3535,
  NV_BC14_TX_LIN_MASTER0_I                       = 3536,
  NV_BC14_TX_LIN_MASTER1_I                       = 3537,
  NV_BC14_TX_LIN_MASTER2_I                       = 3538,
  NV_BC14_TX_LIN_MASTER3_I                       = 3539,
  NV_BC14_GPS1_RF_DELAY_I                        = 3540,
  NV_BC14_TX_LIM_VS_TEMP_I                       = 3541,
  NV_BC14_TX_COMP0_I                             = 3542,
  NV_BC14_TX_COMP1_I                             = 3543,
  NV_BC14_TX_COMP2_I                             = 3544,
  NV_BC14_TX_COMP3_I                             = 3545,
  NV_BC14_TX_LIM_VS_FREQ_I                       = 3546,
  NV_BC14_PA_R1_RISE_I                           = 3547,
  NV_BC14_PA_R1_FALL_I                           = 3548,
  NV_BC14_PA_R2_RISE_I                           = 3549,
  NV_BC14_PA_R2_FALL_I                           = 3550,
  NV_BC14_PA_R3_RISE_I                           = 3551,
  NV_BC14_PA_R3_FALL_I                           = 3552,
  NV_BC14_HDET_OFF_I                             = 3553,
  NV_BC14_HDET_SPN_I                             = 3554,
  NV_BC14_EXP_HDET_VS_AGC_I                      = 3555,
  NV_BC14_ENC_BTF_I                              = 3556,
  NV_BC14_VCO_COARSE_TUNE_TABLE_I                = 3557,
  NV_BC14_VCO_TUNE_2_I                           = 3558,
  NV_BC14_P1_RISE_FALL_OFF_I                     = 3559,
  NV_BC14_HDR_P1_RISE_FALL_OFF_I                 = 3560,
  NV_C0_BC14_TX_CAL_CHAN_I                       = 3561,
  NV_C0_BC14_RX_CAL_CHAN_I                       = 3562,
  NV_C0_BC14_RX_CAL_CHAN_LRU_I                   = 3563,
  NV_C0_BC14_LNA_1_OFFSET_I                      = 3564,
  NV_C0_BC14_LNA_2_OFFSET_I                      = 3565,
  NV_C0_BC14_LNA_3_OFFSET_I                      = 3566,
  NV_C0_BC14_LNA_4_OFFSET_I                      = 3567,
  NV_C0_BC14_LNA_1_OFFSET_VS_FREQ_I              = 3568,
  NV_C0_BC14_LNA_2_OFFSET_VS_FREQ_I              = 3569,
  NV_C0_BC14_LNA_3_OFFSET_VS_FREQ_I              = 3570,
  NV_C0_BC14_LNA_4_OFFSET_VS_FREQ_I              = 3571,
  NV_C0_BC14_IM2_I_VALUE_I                       = 3572,
  NV_C0_BC14_IM2_Q_VALUE_I                       = 3573,
  NV_C0_BC14_VGA_GAIN_OFFSET_I                   = 3574,
  NV_C0_BC14_VGA_GAIN_OFFSET_VS_FREQ_I           = 3575,
  NV_C0_BC14_IM2_TRANSCONDUCTOR_VALUE_I          = 3576,
  NV_C0_BC14_LNA_1_RISE_I                        = 3577,
  NV_C0_BC14_LNA_1_FALL_I                        = 3578,
  NV_C0_BC14_LNA_2_RISE_I                        = 3579,
  NV_C0_BC14_LNA_2_FALL_I                        = 3580,
  NV_C0_BC14_LNA_3_RISE_I                        = 3581,
  NV_C0_BC14_LNA_3_FALL_I                        = 3582,
  NV_C0_BC14_LNA_4_RISE_I                        = 3583,
  NV_C0_BC14_LNA_4_FALL_I                        = 3584,
  NV_C0_BC14_IM_LEVEL1_I                         = 3585,
  NV_C0_BC14_IM_LEVEL2_I                         = 3586,
  NV_C0_BC14_IM_LEVEL3_I                         = 3587,
  NV_C0_BC14_IM_LEVEL4_I                         = 3588,
  NV_C1_BC14_TX_CAL_CHAN_I                       = 3589,
  NV_C1_BC14_RX_CAL_CHAN_I                       = 3590,
  NV_C1_BC14_LNA_1_OFFSET_VS_FREQ_I              = 3591,
  NV_C1_BC14_LNA_2_OFFSET_VS_FREQ_I              = 3592,
  NV_C1_BC14_LNA_3_OFFSET_VS_FREQ_I              = 3593,
  NV_C1_BC14_LNA_4_OFFSET_VS_FREQ_I              = 3594,
  NV_C1_BC14_LNA_1_OFFSET_I                      = 3595,
  NV_C1_BC14_LNA_2_OFFSET_I                      = 3596,
  NV_C1_BC14_LNA_3_OFFSET_I                      = 3597,
  NV_C1_BC14_LNA_4_OFFSET_I                      = 3598,
  NV_C1_BC14_IM2_I_VALUE_I                       = 3599,
  NV_C1_BC14_IM2_Q_VALUE_I                       = 3600,
  NV_C1_BC14_VGA_GAIN_OFFSET_I                   = 3601,
  NV_C1_BC14_VGA_GAIN_OFFSET_VS_FREQ_I           = 3602,
  NV_C1_BC14_IM2_TRANSCONDUCTOR_VALUE_I          = 3603,
  NV_C1_BC14_LNA_1_RISE_I                        = 3604,
  NV_C1_BC14_LNA_1_FALL_I                        = 3605,
  NV_C1_BC14_LNA_2_RISE_I                        = 3606,
  NV_C1_BC14_LNA_2_FALL_I                        = 3607,
  NV_C1_BC14_LNA_3_RISE_I                        = 3608,
  NV_C1_BC14_LNA_3_FALL_I                        = 3609,
  NV_C1_BC14_LNA_4_RISE_I                        = 3610,
  NV_C1_BC14_LNA_4_FALL_I                        = 3611,
  NV_C1_BC14_IM_LEVEL1_I                         = 3612,
  NV_C1_BC14_IM_LEVEL2_I                         = 3613,
  NV_C1_BC14_IM_LEVEL3_I                         = 3614,
  NV_C1_BC14_IM_LEVEL4_I                         = 3615,
  NV_C1_BC14_VCO_COARSE_TUNE_TABLE_I             = 3616,
  NV_BC14_ANT_QUALITY_I                          = 3617,
  NV_BC14_PA_DVS_VOLTAGE_I                       = 3618,
  NV_C0_BC14_LNA_SWITCHPOINTS_LPM_1_I            = 3619,
  NV_C0_BC14_LNA_SWITCHPOINTS_LPM_2_I            = 3620,
  NV_C0_BC14_IM2_LPM_1_I                         = 3621,
  NV_C0_BC14_IM2_LPM_2_I                         = 3622,
  NV_C0_BC14_INTELLICEIVER_CAL_I                 = 3623,
  NV_C0_BC14_INTELLICEIVER_DET_THRESH_I          = 3624,
  NV_C1_BC14_RX_CAL_CHAN_LRU_I                   = 3625,
  NV_SYS_VARIANT_NAME_I                          = 3626,
  NV_SET_SSAVER_AUTO_KEYLOCK_I                   = 3627,
  NV_DTM_FEATURE_SUPPORT_I                       = 3628,
  NV_DTM_MULTISLOT_CLASS_I                       = 3629,
  NV_EDA_FEATURE_SUPPORT_I                       = 3630,
  NV_MF_MRU_CHAN_I                               = 3631,
  NV_SRCH_DBG_MASK_I                             = 3632,
  NV_STRIDE_ACTIVE_I                             = 3633,
  NV_DDTM_SETTINGS_I                             = 3634,
  NV_SD_CFG_ITEMS_I                              = 3635,
  NV_VOIP_QOS_EVDO_SIP_PROFILE_ID_I              = 3636,
  NV_VOIP_QOS_EVDO_RTP_PROFILE_ID_I              = 3637,
  NV_VOIP_QOS_EVDO_DSCP_I                        = 3638,
  NV_VOIP_DTX_ENABLED_I                          = 3639,
  NV_MF_AFC_INNER_LOOP_GAIN_I                    = 3640,
  NV_MF_AFC_INIT_FREQ_OFFSET_I                   = 3641,
  NV_MF_C0_IM2_I_VALUE_I                         = 3642,
  NV_MF_C0_IM2_Q_VALUE_I                         = 3643,
  NV_MF_C0_IM2_TRANSCONDUCTOR_VALUE_I            = 3644,
  NV_MF_C1_IM2_I_VALUE_I                         = 3645,
  NV_MF_C1_IM2_Q_VALUE_I                         = 3646,
  NV_MF_C1_IM2_TRANSCONDUCTOR_VALUE_I            = 3647,
  NV_MF_ACQ_PARAMETERS_I                         = 3648,
  NV_WCDMA_RRC_VERSION_I                         = 3649,
  NV_WCDMA_900_VGA_GAIN_OFFSET_I                 = 3650,
  NV_WCDMA_900_VGA_GAIN_OFFSET_VS_FREQ_I         = 3651,
  NV_WCDMA_900_VGA_GAIN_OFFSET_VS_TEMP_I         = 3652,
  NV_WCDMA_900_LNA_RANGE_RISE_2_I                = 3653,
  NV_WCDMA_900_LNA_RANGE_RISE_3_I                = 3654,
  NV_WCDMA_900_LNA_RANGE_FALL_2_I                = 3655,
  NV_WCDMA_900_LNA_RANGE_FALL_3_I                = 3656,
  NV_WCDMA_900_IM_LEVEL_2_I                      = 3657,
  NV_WCDMA_900_IM_LEVEL_3_I                      = 3658,
  NV_WCDMA_900_LNA_RANGE_OFFSET_2_I              = 3659,
  NV_WCDMA_900_LNA_RANGE_OFFSET_3_I              = 3660,
  NV_WCDMA_900_LNA_OFFSET_VS_FREQ_2_I            = 3661,
  NV_WCDMA_900_LNA_OFFSET_VS_FREQ_3_I            = 3662,
  NV_WCDMA_900_IM2_I_VALUE_I                     = 3663,
  NV_WCDMA_900_IM2_Q_VALUE_I                     = 3664,
  NV_WCDMA_900_IM2_TRANSCONDUCTOR_VALUE_I        = 3665,
  NV_WCDMA_900_RX_AGC_MIN_2_I                    = 3666,
  NV_WCDMA_900_RX_AGC_MIN_3_I                    = 3667,
  NV_WCDMA_900_MAX_TX_POWER_I                    = 3668,
  NV_WCDMA_900_OUT_OF_SERVICE_THRESH_I           = 3669,
  NV_WCDMA_900_LNA_RANGE_RISE_I                  = 3670,
  NV_WCDMA_900_LNA_RANGE_FALL_I                  = 3671,
  NV_WCDMA_900_IM_LEVEL_I                        = 3672,
  NV_WCDMA_900_NONBYPASS_TIMER_I                 = 3673,
  NV_WCDMA_900_BYPASS_TIMER_I                    = 3674,
  NV_WCDMA_900_LNA_RANGE_OFFSET_I                = 3675,
  NV_WCDMA_900_LNA_OFFSET_VS_FREQ_I              = 3676,
  NV_WCDMA_900_RX_AGC_MIN_I                      = 3677,
  NV_WCDMA_900_RX_AGC_MAX_I                      = 3678,
  NV_WCDMA_900_AGC_PHASE_OFFSET_I                = 3679,
  NV_WCDMA_900_TX_LIN_MASTER_0_I                 = 3680,
  NV_WCDMA_900_TX_LIN_MASTER_1_I                 = 3681,
  NV_WCDMA_900_TX_COMP_VS_FREQ_0_I               = 3682,
  NV_WCDMA_900_TX_COMP_VS_FREQ_1_I               = 3683,
  NV_WCDMA_900_TX_LIN_VS_TEMP_0_I                = 3684,
  NV_WCDMA_900_TX_LIN_VS_TEMP_1_I                = 3685,
  NV_WCDMA_900_TX_SLP_VS_TEMP_0_I                = 3686,
  NV_WCDMA_900_TX_SLP_VS_TEMP_1_I                = 3687,
  NV_WCDMA_900_R1_RISE_I                         = 3688,
  NV_WCDMA_900_R1_FALL_I                         = 3689,
  NV_WCDMA_900_TX_LIM_VS_TEMP_I                  = 3690,
  NV_WCDMA_900_TX_LIM_VS_FREQ_I                  = 3691,
  NV_WCDMA_900_ADJ_FACTOR_I                      = 3692,
  NV_WCDMA_900_EXP_HDET_VS_AGC_I                 = 3693,
  NV_WCDMA_900_HDET_OFF_I                        = 3694,
  NV_WCDMA_900_HDET_SPN_I                        = 3695,
  NV_WCDMA_900_ENC_BTF_I                         = 3696,
  NV_WCDMA_900_AGC_PA_ON_RISE_DELAY_I            = 3697,
  NV_WCDMA_900_AGC_PA_ON_FALL_DELAY_I            = 3698,
  NV_WCDMA_900_AGC_TX_ON_RISE_DELAY_I            = 3699,
  NV_WCDMA_900_AGC_TX_ON_FALL_DELAY_I            = 3700,
  NV_WCDMA_900_AGC_UPDATE_TX_AGC_TIME_I          = 3701,
  NV_WCDMA_900_PRACH_R1_RISE_OFFSET_I            = 3702,
  NV_WCDMA_900_PRACH_R1_FALL_OFFSET_I            = 3703,
  NV_WCDMA_900_TX_CAL_CHAN_I                     = 3704,
  NV_WCDMA_900_RX_CAL_CHAN_I                     = 3705,
  NV_WCDMA_900_TX_LIN_MASTER_2_I                 = 3706,
  NV_WCDMA_900_TX_LIN_MASTER_3_I                 = 3707,
  NV_WCDMA_900_TX_COMP_VS_FREQ_2_I               = 3708,
  NV_WCDMA_900_TX_COMP_VS_FREQ_3_I               = 3709,
  NV_WCDMA_900_TX_LIN_VS_TEMP_2_I                = 3710,
  NV_WCDMA_900_TX_LIN_VS_TEMP_3_I                = 3711,
  NV_WCDMA_900_TX_SLP_VS_TEMP_2_I                = 3712,
  NV_WCDMA_900_TX_SLP_VS_TEMP_3_I                = 3713,
  NV_WCDMA_900_R2_RISE_I                         = 3714,
  NV_WCDMA_900_R2_FALL_I                         = 3715,
  NV_WCDMA_900_R3_RISE_I                         = 3716,
  NV_WCDMA_900_R3_FALL_I                         = 3717,
  NV_WCDMA_900_PA_COMPENSATE_UP_R2_I             = 3718,
  NV_WCDMA_900_PA_COMPENSATE_DOWN_R2_I           = 3719,
  NV_WCDMA_900_PA_COMPENSATE_UP_R3_I             = 3720,
  NV_WCDMA_900_PA_COMPENSATE_DOWN_R3_I           = 3721,
  NV_WCDMA_900_TX_ROT_ANGLE_PA_STATE_00_I        = 3722,
  NV_WCDMA_900_TX_ROT_ANGLE_PA_STATE_01_I        = 3723,
  NV_WCDMA_900_TX_ROT_ANGLE_PA_STATE_10_I        = 3724,
  NV_WCDMA_900_TX_ROT_ANGLE_PA_STATE_11_I        = 3725,
  NV_WCDMA_900_PRACH_R2_RISE_OFFSET_I            = 3726,
  NV_WCDMA_900_PRACH_R2_FALL_OFFSET_I            = 3727,
  NV_WCDMA_900_PRACH_R3_RISE_OFFSET_I            = 3728,
  NV_WCDMA_900_PRACH_R3_FALL_OFFSET_I            = 3729,
  NV_WCDMA_900_PA_RANGE_MAP_I                    = 3730,
  NV_WCDMA_900_DCH_AGC_UPDATE_TX_AGC_TIME_I      = 3731,
  NV_WCDMA_900_AGC_TX_ADJ_PDM_DELAY_I            = 3732,
  NV_WCDMA_900_UTRAN_TX_LIM_VS_TEMP_OFFSET_I     = 3733,
  NV_WCDMA_900_PA_GAIN_UP_TIME_I                 = 3734,
  NV_WCDMA_900_PA_GAIN_DOWN_TIME_I               = 3735,
  NV_WCDMA_900_PA_COMPENSATE_UP_I                = 3736,
  NV_WCDMA_900_PA_COMPENSATE_DOWN_I              = 3737,
  NV_WCDMA_900_RX_DELAY_I                        = 3738,
  NV_WCDMA_900_PA_RANGE_FOR_DVS_I                = 3739,
  NV_WCDMA_900_PA_COMPENSATE_UP_WITH_DVS_I       = 3740,
  NV_WCDMA_900_PA_COMPENSATE_DN_WITH_DVS_I       = 3741,
  NV_WCDMA_900_MAX_PWR_BACKOFF_VOLTAGES_I        = 3742,
  NV_WCDMA_900_MAX_PWR_BACKOFF_VOLT1_I           = 3743,
  NV_WCDMA_900_MAX_PWR_BACKOFF_VOLT2_I           = 3744,
  NV_WCDMA_900_MAX_PWR_BACKOFF_VOLT3_I           = 3745,
  NV_WCDMA_900_HS_R1_RISE_I                      = 3746,
  NV_WCDMA_900_HS_R1_FALL_I                      = 3747,
  NV_WCDMA_900_HS_R2_RISE_I                      = 3748,
  NV_WCDMA_900_HS_R2_FALL_I                      = 3749,
  NV_WCDMA_900_HS_R3_RISE_I                      = 3750,
  NV_WCDMA_900_HS_R3_FALL_I                      = 3751,
  NV_RFR_VCO_COARSE_TUNING_900_I                 = 3752,
  NV_NITZ_NW_INFO_I                              = 3753,
  NV_CBS_MAX_MSGS_PER_TOPIC_I                    = 3754,
  NV_CAMERA_TYPE_I                               = 3755,
  NV_GPS1_DYNAMIC_MODE_I                         = 3756,
  NV_DQOS_SUPPORTED_I                            = 3757,
  NV_AAGPS_USE_TRANSPORT_SECURITY_I              = 3758,
  NV_C1_WCDMA_2100_VGA_GAIN_OFFSET_I             = 3759,
  NV_C1_WCDMA_2100_LNA_RANGE_RISE_I              = 3760,
  NV_C1_WCDMA_2100_LNA_RANGE_FALL_I              = 3761,
  NV_C1_WCDMA_2100_IM_LEVEL_I                    = 3762,
  NV_C1_WCDMA_2100_NONBYPASS_TIMER_I             = 3763,
  NV_C1_WCDMA_2100_BYPASS_TIMER_I                = 3764,
  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_I            = 3765,
  NV_C1_WCDMA_2100_LNA_OFFSET_VS_FREQ_I          = 3766,
  NV_C1_WCDMA_2100_VGA_GAIN_OFFSET_VS_FREQ_I     = 3767,
  NV_C1_WCDMA_2100_VGA_GAIN_OFFSET_VS_TEMP_I     = 3768,
  NV_C1_WCDMA_2100_LNA_RANGE_RISE_2_I            = 3769,
  NV_C1_WCDMA_2100_LNA_RANGE_RISE_3_I            = 3770,
  NV_C1_WCDMA_2100_LNA_RANGE_RISE_4_I            = 3771,
  NV_C1_WCDMA_2100_LNA_RANGE_FALL_2_I            = 3772,
  NV_C1_WCDMA_2100_LNA_RANGE_FALL_3_I            = 3773,
  NV_C1_WCDMA_2100_LNA_RANGE_FALL_4_I            = 3774,
  NV_C1_WCDMA_2100_IM_LEVEL_2_I                  = 3775,
  NV_C1_WCDMA_2100_IM_LEVEL_3_I                  = 3776,
  NV_C1_WCDMA_2100_IM_LEVEL_4_I                  = 3777,
  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_2_I          = 3778,
  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_3_I          = 3779,
  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_4_I          = 3780,
  NV_C1_WCDMA_2100_LNA_OFFSET_VS_FREQ_2_I        = 3781,
  NV_C1_WCDMA_2100_LNA_OFFSET_VS_FREQ_3_I        = 3782,
  NV_C1_WCDMA_2100_LNA_OFFSET_VS_FREQ_4_I        = 3783,
  NV_C1_WCDMA_2100_IM2_I_VALUE_I                 = 3784,
  NV_C1_WCDMA_2100_IM2_Q_VALUE_I                 = 3785,
  NV_C1_WCDMA_2100_IM2_TRANSCONDUCTOR_VALUE_I    = 3786,
  NV_C1_WCDMA_2100_RX_CAL_CHAN_I                 = 3787,
  NV_C1_RF_ANTSEL_UMTS_2100_I                    = 3788,
  NV_C1_WCDMA_1900_VGA_GAIN_OFFSET_I             = 3789,
  NV_C1_WCDMA_1900_VGA_GAIN_OFFSET_VS_FREQ_I     = 3790,
  NV_C1_WCDMA_1900_VGA_GAIN_OFFSET_VS_TEMP_I     = 3791,
  NV_C1_WCDMA_1900_LNA_RANGE_RISE_I              = 3792,
  NV_C1_WCDMA_1900_LNA_RANGE_RISE_2_I            = 3793,
  NV_C1_WCDMA_1900_LNA_RANGE_RISE_3_I            = 3794,
  NV_C1_WCDMA_1900_LNA_RANGE_RISE_4_I            = 3795,
  NV_C1_WCDMA_1900_LNA_RANGE_FALL_I              = 3796,
  NV_C1_WCDMA_1900_LNA_RANGE_FALL_2_I            = 3797,
  NV_C1_WCDMA_1900_LNA_RANGE_FALL_3_I            = 3798,
  NV_C1_WCDMA_1900_LNA_RANGE_FALL_4_I            = 3799,
  NV_C1_WCDMA_1900_IM_LEVEL_I                    = 3800,
  NV_C1_WCDMA_1900_IM_LEVEL_2_I                  = 3801,
  NV_C1_WCDMA_1900_IM_LEVEL_3_I                  = 3802,
  NV_C1_WCDMA_1900_IM_LEVEL_4_I                  = 3803,
  NV_C1_WCDMA_1900_LNA_RANGE_OFFSET_2_I          = 3804,
  NV_C1_WCDMA_1900_LNA_RANGE_OFFSET_3_I          = 3805,
  NV_C1_WCDMA_1900_LNA_RANGE_OFFSET_4_I          = 3806,
  NV_C1_WCDMA_1900_LNA_OFFSET_VS_FREQ_2_I        = 3807,
  NV_C1_WCDMA_1900_LNA_OFFSET_VS_FREQ_3_I        = 3808,
  NV_C1_WCDMA_1900_LNA_OFFSET_VS_FREQ_4_I        = 3809,
  NV_C1_WCDMA_1900_IM2_I_VALUE_I                 = 3810,
  NV_C1_WCDMA_1900_IM2_Q_VALUE_I                 = 3811,
  NV_C1_WCDMA_1900_IM2_TRANSCONDUCTOR_VALUE_I    = 3812,
  NV_C1_WCDMA_1900_NONBYPASS_TIMER_I             = 3813,
  NV_C1_WCDMA_1900_BYPASS_TIMER_I                = 3814,
  NV_C1_WCDMA_1900_LNA_RANGE_OFFSET_I            = 3815,
  NV_C1_WCDMA_1900_LNA_OFFSET_VS_FREQ_I          = 3816,
  NV_C1_WCDMA_1900_RX_CAL_CHAN_I                 = 3817,
  NV_C1_RF_ANTSEL_UMTS_1900_I                    = 3818,
  NV_C1_WCDMA_800_VGA_GAIN_OFFSET_I              = 3819,
  NV_C1_WCDMA_800_VGA_GAIN_OFFSET_VS_FREQ_I      = 3820,
  NV_C1_WCDMA_800_VGA_GAIN_OFFSET_VS_TEMP_I      = 3821,
  NV_C1_WCDMA_800_LNA_RANGE_RISE_I               = 3822,
  NV_C1_WCDMA_800_LNA_RANGE_RISE_2_I             = 3823,
  NV_C1_WCDMA_800_LNA_RANGE_RISE_3_I             = 3824,
  NV_C1_WCDMA_800_LNA_RANGE_RISE_4_I             = 3825,
  NV_C1_WCDMA_800_LNA_RANGE_FALL_I               = 3826,
  NV_C1_WCDMA_800_LNA_RANGE_FALL_2_I             = 3827,
  NV_C1_WCDMA_800_LNA_RANGE_FALL_3_I             = 3828,
  NV_C1_WCDMA_800_LNA_RANGE_FALL_4_I             = 3829,
  NV_C1_WCDMA_800_IM_LEVEL_I                     = 3830,
  NV_C1_WCDMA_800_IM_LEVEL_2_I                   = 3831,
  NV_C1_WCDMA_800_IM_LEVEL_3_I                   = 3832,
  NV_C1_WCDMA_800_IM_LEVEL_4_I                   = 3833,
  NV_C1_WCDMA_800_LNA_RANGE_OFFSET_I             = 3834,
  NV_C1_WCDMA_800_LNA_RANGE_OFFSET_2_I           = 3835,
  NV_C1_WCDMA_800_LNA_RANGE_OFFSET_3_I           = 3836,
  NV_C1_WCDMA_800_LNA_RANGE_OFFSET_4_I           = 3837,
  NV_C1_WCDMA_800_LNA_OFFSET_VS_FREQ_I           = 3838,
  NV_C1_WCDMA_800_LNA_OFFSET_VS_FREQ_2_I         = 3839,
  NV_C1_WCDMA_800_LNA_OFFSET_VS_FREQ_3_I         = 3840,
  NV_C1_WCDMA_800_LNA_OFFSET_VS_FREQ_4_I         = 3841,
  NV_C1_WCDMA_800_IM2_I_VALUE_I                  = 3842,
  NV_C1_WCDMA_800_IM2_Q_VALUE_I                  = 3843,
  NV_C1_WCDMA_800_IM2_TRANSCONDUCTOR_VALUE_I     = 3844,
  NV_C1_WCDMA_800_NONBYPASS_TIMER_I              = 3845,
  NV_C1_WCDMA_800_BYPASS_TIMER_I                 = 3846,
  NV_C1_WCDMA_800_RX_CAL_CHAN_I                  = 3847,
  NV_C1_RF_ANTSEL_UMTS_800_I                     = 3848,
  NV_RFR_VCO_COARSE_TUNE_2_1900_I                = 3849,
  NV_RFR_WCDMA_C0_C1_DELAY_I                     = 3850,
  NV_WCDMA_RX_DIVERSITY_CTRL_I                   = 3851,
  NV_WCDMA_EQUALIZER_CTRL_I                      = 3852,
  NV_BC11_GPS1_RF_DELAY_I                        = 3853,
  NV_BC11_TX_LIM_VS_TEMP_I                       = 3854,
  NV_BC11_TX_LIN_MASTER0_I                       = 3855,
  NV_BC11_TX_LIN_MASTER1_I                       = 3856,
  NV_BC11_TX_LIN_MASTER2_I                       = 3857,
  NV_BC11_TX_LIN_MASTER3_I                       = 3858,
  NV_BC11_TX_COMP0_I                             = 3859,
  NV_BC11_TX_COMP1_I                             = 3860,
  NV_BC11_TX_COMP2_I                             = 3861,
  NV_BC11_TX_COMP3_I                             = 3862,
  NV_BC11_TX_LIM_VS_FREQ_I                       = 3863,
  NV_BC11_PA_R1_RISE_I                           = 3864,
  NV_BC11_PA_R1_FALL_I                           = 3865,
  NV_BC11_PA_R2_RISE_I                           = 3866,
  NV_BC11_PA_R2_FALL_I                           = 3867,
  NV_BC11_PA_R3_RISE_I                           = 3868,
  NV_BC11_PA_R3_FALL_I                           = 3869,
  NV_BC11_HDET_OFF_I                             = 3870,
  NV_BC11_HDET_SPN_I                             = 3871,
  NV_BC11_EXP_HDET_VS_AGC_I                      = 3872,
  NV_BC11_ENC_BTF_I                              = 3873,
  NV_BC11_VCO_COARSE_TUNE_TABLE_I                = 3874,
  NV_BC11_P1_RISE_FALL_OFF_I                     = 3875,
  NV_C0_BC11_TX_CAL_CHAN_I                       = 3876,
  NV_C0_BC11_RX_CAL_CHAN_I                       = 3877,
  NV_C0_BC11_LNA_1_OFFSET_VS_FREQ_I              = 3878,
  NV_C0_BC11_LNA_2_OFFSET_VS_FREQ_I              = 3879,
  NV_C0_BC11_LNA_3_OFFSET_VS_FREQ_I              = 3880,
  NV_C0_BC11_LNA_4_OFFSET_VS_FREQ_I              = 3881,
  NV_C0_BC11_LNA_1_OFFSET_I                      = 3882,
  NV_C0_BC11_LNA_2_OFFSET_I                      = 3883,
  NV_C0_BC11_LNA_3_OFFSET_I                      = 3884,
  NV_C0_BC11_LNA_4_OFFSET_I                      = 3885,
  NV_C0_BC11_IM2_I_VALUE_I                       = 3886,
  NV_C0_BC11_IM2_Q_VALUE_I                       = 3887,
  NV_C0_BC11_VGA_GAIN_OFFSET_I                   = 3888,
  NV_C0_BC11_VGA_GAIN_OFFSET_VS_FREQ_I           = 3889,
  NV_C0_BC11_IM2_TRANSCONDUCTOR_VALUE_I          = 3890,
  NV_C0_BC11_LNA_1_RISE_I                        = 3891,
  NV_C0_BC11_LNA_1_FALL_I                        = 3892,
  NV_C0_BC11_LNA_2_RISE_I                        = 3893,
  NV_C0_BC11_LNA_2_FALL_I                        = 3894,
  NV_C0_BC11_LNA_3_RISE_I                        = 3895,
  NV_C0_BC11_LNA_3_FALL_I                        = 3896,
  NV_C0_BC11_LNA_4_RISE_I                        = 3897,
  NV_C0_BC11_LNA_4_FALL_I                        = 3898,
  NV_C0_BC11_IM_LEVEL1_I                         = 3899,
  NV_C0_BC11_IM_LEVEL2_I                         = 3900,
  NV_C0_BC11_IM_LEVEL3_I                         = 3901,
  NV_C0_BC11_IM_LEVEL4_I                         = 3902,
  NV_C1_BC11_TX_CAL_CHAN_I                       = 3903,
  NV_C1_BC11_RX_CAL_CHAN_I                       = 3904,
  NV_C1_BC11_LNA_1_OFFSET_VS_FREQ_I              = 3905,
  NV_C1_BC11_LNA_2_OFFSET_VS_FREQ_I              = 3906,
  NV_C1_BC11_LNA_3_OFFSET_VS_FREQ_I              = 3907,
  NV_C1_BC11_LNA_4_OFFSET_VS_FREQ_I              = 3908,
  NV_C1_BC11_LNA_1_OFFSET_I                      = 3909,
  NV_C1_BC11_LNA_2_OFFSET_I                      = 3910,
  NV_C1_BC11_LNA_3_OFFSET_I                      = 3911,
  NV_C1_BC11_LNA_4_OFFSET_I                      = 3912,
  NV_C1_BC11_IM2_I_VALUE_I                       = 3913,
  NV_C1_BC11_IM2_Q_VALUE_I                       = 3914,
  NV_C1_BC11_VGA_GAIN_OFFSET_I                   = 3915,
  NV_C1_BC11_VGA_GAIN_OFFSET_VS_FREQ_I           = 3916,
  NV_C1_BC11_IM2_TRANSCONDUCTOR_VALUE_I          = 3917,
  NV_C1_BC11_LNA_1_RISE_I                        = 3918,
  NV_C1_BC11_LNA_1_FALL_I                        = 3919,
  NV_C1_BC11_LNA_2_RISE_I                        = 3920,
  NV_C1_BC11_LNA_2_FALL_I                        = 3921,
  NV_C1_BC11_LNA_3_RISE_I                        = 3922,
  NV_C1_BC11_LNA_3_FALL_I                        = 3923,
  NV_C1_BC11_LNA_4_RISE_I                        = 3924,
  NV_C1_BC11_LNA_4_FALL_I                        = 3925,
  NV_C1_BC11_IM_LEVEL1_I                         = 3926,
  NV_C1_BC11_IM_LEVEL2_I                         = 3927,
  NV_C1_BC11_IM_LEVEL3_I                         = 3928,
  NV_C1_BC11_IM_LEVEL4_I                         = 3929,
  NV_BC11_VCO_TUNE_2_I                           = 3930,
  NV_BC11_HDR_P1_RISE_FALL_OFF_I                 = 3931,
  NV_C0_BC11_RX_CAL_CHAN_LRU_I                   = 3932,
  NV_C1_BC11_RX_CAL_CHAN_LRU_I                   = 3933,
  NV_BC11_ANT_QUALITY_I                          = 3934,
  NV_C0_BC11_IM2_LPM_1_I                         = 3935,
  NV_C0_BC11_IM2_LPM_2_I                         = 3936,
  NV_C0_BC11_INTELLICEIVER_CAL_I                 = 3937,
  NV_C0_BC11_LNA_SWITCHPOINTS_LPM_1_I            = 3938,
  NV_C0_BC11_LNA_SWITCHPOINTS_LPM_2_I            = 3939,
  NV_C0_BC11_INTELLICEIVER_DET_THRESH_I          = 3940,
  NV_BC11_PA_DVS_VOLTAGE_I                       = 3941,
  NV_C1_BC11_VCO_COARSE_TUNE_TABLE_I             = 3942,
  NV_VOIP_WLAN_PRFRD_CODEC_I                     = 3943,
  NV_VOIP_EVDO_PRFRD_CODEC_I                     = 3944,
  NV_WCDMA_PA_COMP_UP_VS_FREQ_I                  = 3945,
  NV_WCDMA_PA_COMP_DOWN_VS_FREQ_I                = 3946,
  NV_WCDMA_PA_COMP_UP_R2_VS_FREQ_I               = 3947,
  NV_WCDMA_PA_COMP_DOWN_R2_VS_FREQ_I             = 3948,
  NV_WCDMA_PA_COMP_UP_R3_VS_FREQ_I               = 3949,
  NV_WCDMA_PA_COMP_DOWN_R3_VS_FREQ_I             = 3950,
  NV_WCDMA_800_PA_COMP_UP_VS_FREQ_I              = 3951,
  NV_WCDMA_800_PA_COMP_DOWN_VS_FREQ_I            = 3952,
  NV_WCDMA_800_PA_COMP_UP_R2_VS_FREQ_I           = 3953,
  NV_WCDMA_800_PA_COMP_DOWN_R2_VS_FREQ_I         = 3954,
  NV_WCDMA_800_PA_COMP_UP_R3_VS_FREQ_I           = 3955,
  NV_WCDMA_800_PA_COMP_DOWN_R3_VS_FREQ_I         = 3956,
  NV_WCDMA_1900_PA_COMP_UP_VS_FREQ_I             = 3957,
  NV_WCDMA_1900_PA_COMP_DOWN_VS_FREQ_I           = 3958,
  NV_WCDMA_1900_PA_COMP_UP_R2_VS_FREQ_I          = 3959,
  NV_WCDMA_1900_PA_COMP_DOWN_R2_VS_FREQ_I        = 3960,
  NV_WCDMA_1900_PA_COMP_UP_R3_VS_FREQ_I          = 3961,
  NV_WCDMA_1900_PA_COMP_DOWN_R3_VS_FREQ_I        = 3962,
  NV_WCDMA_900_PA_COMP_UP_VS_FREQ_I              = 3963,
  NV_WCDMA_900_PA_COMP_DOWN_VS_FREQ_I            = 3964,
  NV_WCDMA_900_PA_COMP_UP_R2_VS_FREQ_I           = 3965,
  NV_WCDMA_900_PA_COMP_DOWN_R2_VS_FREQ_I         = 3966,
  NV_WCDMA_900_PA_COMP_UP_R3_VS_FREQ_I           = 3967,
  NV_WCDMA_900_PA_COMP_DOWN_R3_VS_FREQ_I         = 3968,
  NV_WCDMA_TX_PDM_LIN_0_I                        = 3969,
  NV_WCDMA_TX_PDM_LIN_1_I                        = 3970,
  NV_WCDMA_TX_PDM_LIN_2_I                        = 3971,
  NV_WCDMA_TX_PDM_LIN_3_I                        = 3972,
  NV_WCDMA_800_TX_PDM_LIN_0_I                    = 3973,
  NV_WCDMA_800_TX_PDM_LIN_1_I                    = 3974,
  NV_WCDMA_800_TX_PDM_LIN_2_I                    = 3975,
  NV_WCDMA_800_TX_PDM_LIN_3_I                    = 3976,
  NV_WCDMA_1900_TX_PDM_LIN_0_I                   = 3977,
  NV_WCDMA_1900_TX_PDM_LIN_1_I                   = 3978,
  NV_WCDMA_1900_TX_PDM_LIN_2_I                   = 3979,
  NV_WCDMA_1900_TX_PDM_LIN_3_I                   = 3980,
  NV_WCDMA_900_TX_PDM_LIN_0_I                    = 3981,
  NV_WCDMA_900_TX_PDM_LIN_1_I                    = 3982,
  NV_WCDMA_900_TX_PDM_LIN_2_I                    = 3983,
  NV_WCDMA_900_TX_PDM_LIN_3_I                    = 3984,
  NV_WCDMA_1800_PA_COMP_UP_VS_FREQ_I             = 3985,
  NV_WCDMA_1800_PA_COMP_DOWN_VS_FREQ_I           = 3986,
  NV_WCDMA_1800_PA_COMP_UP_R2_VS_FREQ_I          = 3987,
  NV_WCDMA_1800_PA_COMP_DOWN_R2_VS_FREQ_I        = 3988,
  NV_WCDMA_1800_PA_COMP_UP_R3_VS_FREQ_I          = 3989,
  NV_WCDMA_1800_PA_COMP_DOWN_R3_VS_FREQ_I        = 3990,
  NV_WCDMA_1800_TX_PDM_LIN_0_I                   = 3991,
  NV_WCDMA_1800_TX_PDM_LIN_1_I                   = 3992,
  NV_WCDMA_1800_TX_PDM_LIN_2_I                   = 3993,
  NV_WCDMA_1800_TX_PDM_LIN_3_I                   = 3994,
  NV_WCDMA_BC4_VGA_GAIN_OFFSET_I                 = 3995,
  NV_WCDMA_BC4_VGA_GAIN_OFFSET_VS_FREQ_I         = 3996,
  NV_WCDMA_BC4_VGA_GAIN_OFFSET_VS_TEMP_I         = 3997,
  NV_WCDMA_BC4_LNA_RANGE_RISE_2_I                = 3998,
  NV_WCDMA_BC4_LNA_RANGE_RISE_3_I                = 3999,
  NV_WCDMA_BC4_LNA_RANGE_FALL_2_I                = 4000,
  NV_WCDMA_BC4_LNA_RANGE_FALL_3_I                = 4001,
  NV_WCDMA_BC4_IM_LEVEL_2_I                      = 4002,
  NV_WCDMA_BC4_IM_LEVEL_3_I                      = 4003,
  NV_WCDMA_BC4_LNA_RANGE_OFFSET_2_I              = 4004,
  NV_WCDMA_BC4_LNA_RANGE_OFFSET_3_I              = 4005,
  NV_WCDMA_BC4_LNA_OFFSET_VS_FREQ_2_I            = 4006,
  NV_WCDMA_BC4_LNA_OFFSET_VS_FREQ_3_I            = 4007,
  NV_WCDMA_BC4_IM2_I_VALUE_I                     = 4008,
  NV_WCDMA_BC4_IM2_Q_VALUE_I                     = 4009,
  NV_WCDMA_BC4_IM2_TRANSCONDUCTOR_VALUE_I        = 4010,
  NV_WCDMA_BC4_RX_AGC_MIN_2_I                    = 4011,
  NV_WCDMA_BC4_RX_AGC_MIN_3_I                    = 4012,
  NV_WCDMA_BC4_MAX_TX_POWER_I                    = 4013,
  NV_WCDMA_BC4_OUT_OF_SERVICE_THRESH_I           = 4014,
  NV_WCDMA_BC4_LNA_RANGE_RISE_I                  = 4015,
  NV_WCDMA_BC4_LNA_RANGE_FALL_I                  = 4016,
  NV_WCDMA_BC4_IM_LEVEL_I                        = 4017,
  NV_WCDMA_BC4_NONBYPASS_TIMER_I                 = 4018,
  NV_WCDMA_BC4_BYPASS_TIMER_I                    = 4019,
  NV_WCDMA_BC4_LNA_RANGE_OFFSET_I                = 4020,
  NV_WCDMA_BC4_LNA_OFFSET_VS_FREQ_I              = 4021,
  NV_WCDMA_BC4_RX_AGC_MIN_I                      = 4022,
  NV_WCDMA_BC4_RX_AGC_MAX_I                      = 4023,
  NV_WCDMA_BC4_AGC_PHASE_OFFSET_I                = 4024,
  NV_WCDMA_BC4_TX_LIN_MASTER_0_I                 = 4025,
  NV_WCDMA_BC4_TX_LIN_MASTER_1_I                 = 4026,
  NV_WCDMA_BC4_TX_COMP_VS_FREQ_0_I               = 4027,
  NV_WCDMA_BC4_TX_COMP_VS_FREQ_1_I               = 4028,
  NV_WCDMA_BC4_TX_LIN_VS_TEMP_0_I                = 4029,
  NV_WCDMA_BC4_TX_LIN_VS_TEMP_1_I                = 4030,
  NV_WCDMA_BC4_TX_SLP_VS_TEMP_0_I                = 4031,
  NV_WCDMA_BC4_TX_SLP_VS_TEMP_1_I                = 4032,
  NV_WCDMA_BC4_R1_RISE_I                         = 4033,
  NV_WCDMA_BC4_R1_FALL_I                         = 4034,
  NV_WCDMA_BC4_TX_LIM_VS_TEMP_I                  = 4035,
  NV_WCDMA_BC4_TX_LIM_VS_FREQ_I                  = 4036,
  NV_WCDMA_BC4_ADJ_FACTOR_I                      = 4037,
  NV_WCDMA_BC4_EXP_HDET_VS_AGC_I                 = 4038,
  NV_WCDMA_BC4_HDET_OFF_I                        = 4039,
  NV_WCDMA_BC4_HDET_SPN_I                        = 4040,
  NV_WCDMA_BC4_ENC_BTF_I                         = 4041,
  NV_WCDMA_BC4_AGC_PA_ON_RISE_DELAY_I            = 4042,
  NV_WCDMA_BC4_AGC_PA_ON_FALL_DELAY_I            = 4043,
  NV_WCDMA_BC4_AGC_TX_ON_RISE_DELAY_I            = 4044,
  NV_WCDMA_BC4_AGC_TX_ON_FALL_DELAY_I            = 4045,
  NV_WCDMA_BC4_AGC_UPDATE_TX_AGC_TIME_I          = 4046,
  NV_WCDMA_BC4_PRACH_R1_RISE_OFFSET_I            = 4047,
  NV_WCDMA_BC4_PRACH_R1_FALL_OFFSET_I            = 4048,
  NV_WCDMA_BC4_TX_CAL_CHAN_I                     = 4049,
  NV_WCDMA_BC4_RX_CAL_CHAN_I                     = 4050,
  NV_WCDMA_BC4_TX_LIN_MASTER_2_I                 = 4051,
  NV_WCDMA_BC4_TX_LIN_MASTER_3_I                 = 4052,
  NV_WCDMA_BC4_TX_COMP_VS_FREQ_2_I               = 4053,
  NV_WCDMA_BC4_TX_COMP_VS_FREQ_3_I               = 4054,
  NV_WCDMA_BC4_TX_LIN_VS_TEMP_2_I                = 4055,
  NV_WCDMA_BC4_TX_LIN_VS_TEMP_3_I                = 4056,
  NV_WCDMA_BC4_TX_SLP_VS_TEMP_2_I                = 4057,
  NV_WCDMA_BC4_TX_SLP_VS_TEMP_3_I                = 4058,
  NV_WCDMA_BC4_R2_RISE_I                         = 4059,
  NV_WCDMA_BC4_R2_FALL_I                         = 4060,
  NV_WCDMA_BC4_R3_RISE_I                         = 4061,
  NV_WCDMA_BC4_R3_FALL_I                         = 4062,
  NV_WCDMA_BC4_PA_COMPENSATE_UP_R2_I             = 4063,
  NV_WCDMA_BC4_PA_COMPENSATE_DOWN_R2_I           = 4064,
  NV_WCDMA_BC4_PA_COMPENSATE_UP_R3_I             = 4065,
  NV_WCDMA_BC4_PA_COMPENSATE_DOWN_R3_I           = 4066,
  NV_WCDMA_BC4_TX_ROT_ANGLE_PA_STATE_00_I        = 4067,
  NV_WCDMA_BC4_TX_ROT_ANGLE_PA_STATE_01_I        = 4068,
  NV_WCDMA_BC4_TX_ROT_ANGLE_PA_STATE_10_I        = 4069,
  NV_WCDMA_BC4_TX_ROT_ANGLE_PA_STATE_11_I        = 4070,
  NV_WCDMA_BC4_PRACH_R2_RISE_OFFSET_I            = 4071,
  NV_WCDMA_BC4_PRACH_R2_FALL_OFFSET_I            = 4072,
  NV_WCDMA_BC4_PRACH_R3_RISE_OFFSET_I            = 4073,
  NV_WCDMA_BC4_PRACH_R3_FALL_OFFSET_I            = 4074,
  NV_WCDMA_BC4_PA_RANGE_MAP_I                    = 4075,
  NV_WCDMA_BC4_DCH_AGC_UPDATE_TX_AGC_TIME_I      = 4076,
  NV_WCDMA_BC4_AGC_TX_ADJ_PDM_DELAY_I            = 4077,
  NV_WCDMA_BC4_UTRAN_TX_LIM_VS_TEMP_OFFSET_I     = 4078,
  NV_WCDMA_BC4_PA_GAIN_UP_TIME_I                 = 4079,
  NV_WCDMA_BC4_PA_GAIN_DOWN_TIME_I               = 4080,
  NV_WCDMA_BC4_PA_COMPENSATE_UP_I                = 4081,
  NV_WCDMA_BC4_PA_COMPENSATE_DOWN_I              = 4082,
  NV_WCDMA_BC4_RX_DELAY_I                        = 4083,
  NV_WCDMA_BC4_PA_RANGE_FOR_DVS_I                = 4084,
  NV_WCDMA_BC4_PA_COMPENSATE_UP_WITH_DVS_I       = 4085,
  NV_WCDMA_BC4_PA_COMPENSATE_DN_WITH_DVS_I       = 4086,
  NV_WCDMA_BC4_MAX_PWR_BACKOFF_VOLTAGES_I        = 4087,
  NV_WCDMA_BC4_MAX_PWR_BACKOFF_VOLT1_I           = 4088,
  NV_WCDMA_BC4_MAX_PWR_BACKOFF_VOLT2_I           = 4089,
  NV_WCDMA_BC4_MAX_PWR_BACKOFF_VOLT3_I           = 4090,
  NV_WCDMA_BC4_HS_R1_RISE_I                      = 4091,
  NV_WCDMA_BC4_HS_R1_FALL_I                      = 4092,
  NV_WCDMA_BC4_HS_R2_RISE_I                      = 4093,
  NV_WCDMA_BC4_HS_R2_FALL_I                      = 4094,
  NV_WCDMA_BC4_HS_R3_RISE_I                      = 4095,
  NV_WCDMA_BC4_HS_R3_FALL_I                      = 4096,
  NV_RFR_VCO_COARSE_TUNING_BC4_I                 = 4097,
  NV_RF_ANTSEL_UMTS_900_I                        = 4098,
  NV_RF_ANTSEL_UMTS_BC4_I                        = 4099,
  NV_GPS1_NMEA_OUTPUT_I                          = 4100,
  NV_ROAM_IND_CUSTOM_HOME_I                      = 4101,
  NV_CDMA_SO68_ENABLED_I                         = 4102,
  NV_RTR_BB_FILTER_I                             = 4103,
  NV_MF_CHAN_SUPPORT_I                           = 4104,
  NV_MF_RF_PATH_CONFIG_I                         = 4105,
  NV_MF_RSSI_CAL_VS_FREQ_0_I                     = 4106,
  NV_MF_RSSI_CAL_VS_FREQ_1_I                     = 4107,
  NV_MF_RSSI_CAL_VS_FREQ_2_I                     = 4108,
  NV_MF_RSSI_CAL_VS_FREQ_3_I                     = 4109,
  NV_UPLOADMEDIA_POSTCARD_SERVER_READONLY_I      = 4110,
  NV_UMTS_CALL_VT_CODEC_LIST_I                   = 4111,
  NV_WCDMA_BC4_TX_PDM_LIN_0_I                    = 4112,
  NV_WCDMA_BC4_TX_PDM_LIN_1_I                    = 4113,
  NV_WCDMA_BC4_TX_PDM_LIN_2_I                    = 4114,
  NV_WCDMA_BC4_TX_PDM_LIN_3_I                    = 4115,
  NV_INTERRAT_NACC_SUPPORT_I                     = 4116,
  NV_DARP_FEATURE_SUPPORT_I                      = 4117,
  NV_HSDPA_CAT_I                                 = 4118,
  NV_SET_DISPLAY_LAYOUT_I                        = 4119,
  NV_SET_CHINESE_ASSOCIATED_SWITCH_I             = 4120,
  NV_SET_CHINESE_INPUT_METHODS_I                 = 4121,
  NV_WLAN_QOS_MODE_I                             = 4122,
  NV_GAME_MODE_PERSIST_I                         = 4123,
  NV_GAME_MODE_I                                 = 4124,
  NV_GSM_850_GMSK_MULTISLOT_2_TX_PWR_I           = 4125,
  NV_GSM_850_GMSK_MULTISLOT_3_TX_PWR_I           = 4126,
  NV_GSM_850_GMSK_MULTISLOT_4_TX_PWR_I           = 4127,
  NV_GSM_850_GMSK_MULTISLOT_5_TX_PWR_I           = 4128,
  NV_GSM_GMSK_MULTISLOT_2_TX_PWR_I               = 4129,
  NV_GSM_GMSK_MULTISLOT_3_TX_PWR_I               = 4130,
  NV_GSM_GMSK_MULTISLOT_4_TX_PWR_I               = 4131,
  NV_GSM_GMSK_MULTISLOT_5_TX_PWR_I               = 4132,
  NV_DCS_GMSK_MULTISLOT_2_TX_PWR_I               = 4133,
  NV_DCS_GMSK_MULTISLOT_3_TX_PWR_I               = 4134,
  NV_DCS_GMSK_MULTISLOT_4_TX_PWR_I               = 4135,
  NV_DCS_GMSK_MULTISLOT_5_TX_PWR_I               = 4136,
  NV_GSM_1900_GMSK_MULTISLOT_2_TX_PWR_I          = 4137,
  NV_GSM_1900_GMSK_MULTISLOT_3_TX_PWR_I          = 4138,
  NV_GSM_1900_GMSK_MULTISLOT_4_TX_PWR_I          = 4139,
  NV_GSM_1900_GMSK_MULTISLOT_5_TX_PWR_I          = 4140,
  NV_GSM_850_8PSK_MULTISLOT_2_TX_PWR_I           = 4141,
  NV_GSM_850_8PSK_MULTISLOT_3_TX_PWR_I           = 4142,
  NV_GSM_850_8PSK_MULTISLOT_4_TX_PWR_I           = 4143,
  NV_GSM_850_8PSK_MULTISLOT_5_TX_PWR_I           = 4144,
  NV_GSM_8PSK_MULTISLOT_2_TX_PWR_I               = 4145,
  NV_GSM_8PSK_MULTISLOT_3_TX_PWR_I               = 4146,
  NV_GSM_8PSK_MULTISLOT_4_TX_PWR_I               = 4147,
  NV_GSM_8PSK_MULTISLOT_5_TX_PWR_I               = 4148,
  NV_DCS_8PSK_MULTISLOT_2_TX_PWR_I               = 4149,
  NV_DCS_8PSK_MULTISLOT_3_TX_PWR_I               = 4150,
  NV_DCS_8PSK_MULTISLOT_4_TX_PWR_I               = 4151,
  NV_DCS_8PSK_MULTISLOT_5_TX_PWR_I               = 4152,
  NV_GSM_1900_8PSK_MULTISLOT_2_TX_PWR_I          = 4153,
  NV_GSM_1900_8PSK_MULTISLOT_3_TX_PWR_I          = 4154,
  NV_GSM_1900_8PSK_MULTISLOT_4_TX_PWR_I          = 4155,
  NV_GSM_1900_8PSK_MULTISLOT_5_TX_PWR_I          = 4156,
  NV_MULTISLOT_GMSK_POWER_PROFILE_I              = 4157,
  NV_MULTISLOT_8PSK_POWER_PROFILE_I              = 4158,
  NV_HSDPA_COMPRESSED_MODE_ENABLED_I             = 4159,
  NV_LOCK_CODE_EXT_I                             = 4160,
  NV_WCDMA_IACCUM_I                              = 4161,
  NV_WCDMA_QACCUM_I                              = 4162,
  NV_WCDMA_1900_IACCUM_I                         = 4163,
  NV_WCDMA_1900_QACCUM_I                         = 4164,
  NV_WCDMA_1800_IACCUM_I                         = 4165,
  NV_WCDMA_1800_QACCUM_I                         = 4166,
  NV_WCDMA_BC4_IACCUM_I                          = 4167,
  NV_WCDMA_BC4_QACCUM_I                          = 4168,
  NV_WCDMA_800_IACCUM_I                          = 4169,
  NV_WCDMA_800_QACCUM_I                          = 4170,
  NV_WCDMA_900_IACCUM_I                          = 4171,
  NV_WCDMA_900_QACCUM_I                          = 4172,
  NV_WCDMA_RRC_PDCP_DISABLED_I                   = 4173,
  NV_GSM_IM2_850_I                               = 4174,
  NV_GSM_IM2_900_I                               = 4175,
  NV_GSM_IM2_1800_I                              = 4176,
  NV_GSM_IM2_1900_I                              = 4177,
  NV_MARKET_REGION_UI_I                          = 4178,
  NV_GSM_TX_RSB_CORR_I                           = 4179,
  NV_DCS_TX_RSB_CORR_I                           = 4180,
  NV_GSM_850_TX_RSB_CORR_I                       = 4181,
  NV_GSM_1900_TX_RSB_CORR_I                      = 4182,
  NV_VOIP_QOS_ENABLED_I                          = 4183,
  NV_SEC_CSPRNG_INIT_SEED_I                      = 4184,
  NV_HDR_MIN_UATI_MODE_I                         = 4185,
  NV_VOIP_WRITE_MEDIA_FILE_ENABLED_I             = 4186,
  NV_VOIP_READ_MEDIA_FILE_ENABLED_I              = 4187,
  NV_RDB_LOCK_TO_USER_I                          = 4188,
  NV_MS_MESSAGINGDAEMON_LOG_ENABLED_I            = 4189,
  NV_JAVA_POSITIONING_ENABLED_I                  = 4190,
  NV_LOCK_CODE_EXT_DIGITS_I                      = 4191,
  NV_CDMA_SO70_ENABLED_I                         = 4192,
  NV_HDRIDLE_DESIRED_SLOTTED_MODE_CONFIG_I       = 4193,
  NV_WCDMA_1800_DRX_MODE_SEL_I                   = 4194,
  NV_WCDMA_1900_DRX_MODE_SEL_I                   = 4195,
  NV_WCDMA_2100_DRX_MODE_SEL_I                   = 4196,
  NV_WCDMA_800_DRX_MODE_SEL_I                    = 4197,
  NV_WCDMA_900_DRX_MODE_SEL_I                    = 4198,
  NV_WCDMA_BC4_DRX_MODE_SEL_I                    = 4199,
  NV_GPS_DRX_MODE_SEL_I                          = 4200,
  NV_APPS_PWRC_DISABLE_I                         = 4201,
  NV_WLAN_OEM_INDEX_I                            = 4202,
  NV_MS_NOTIFY_FIRST_RETRY_I                     = 4203,
  NV_HDRSCP_FORCE_REL0_CONFIG_I                  = 4204,
  NV_UIM_CONFIG_PARAMS_I                         = 4205,
  NV_HDRSCMDB_SECURE_CONFIG_I                    = 4206,
  NV_HDRAMP_LOCATION_I                           = 4207,
  NV_CRASH_DEBUG_DISALLOWED_I                    = 4208,
  NV_EDTM_FEATURE_SUPPORT_I                      = 4209,
  NV_WCDMA_HSUPA_CATEGORY_I                      = 4210,
  NV_WCDMA_OPTIONAL_FEATURE_LIST_I               = 4211,
  NV_XO_TRIM_VALUES_I                            = 4212,
  NV_GSM_PATH_DELAY_COMP_FREQ_TBL_I              = 4213,
  NV_GSM_850_PATH_DELAY_COMP_FREQ_TBL_I          = 4214,
  NV_GSM_PATH_DELAY_COLD_TEMP_VS_FREQ_I          = 4215,
  NV_GSM_PATH_DELAY_ROOM_TEMP_VS_FREQ_I          = 4216,
  NV_GSM_PATH_DELAY_HOT_TEMP_VS_FREQ_I           = 4217,
  NV_GSM_850_PATH_DELAY_COLD_TEMP_VS_FREQ_I      = 4218,
  NV_GSM_850_PATH_DELAY_ROOM_TEMP_VS_FREQ_I      = 4219,
  NV_GSM_850_PATH_DELAY_HOT_TEMP_VS_FREQ_I       = 4220,
  NV_THERM_VALUE_T1_I                            = 4221,
  NV_THERM_VALUE_T2_I                            = 4222,
  NV_THERM_VALUE_T3_I                            = 4223,
  NV_THERM_VALUE_T4_I                            = 4224,
  NV_THERM_TEMP_MIN_I                            = 4225,
  NV_THERM_TEMP_MAX_I                            = 4226,
  NV_SMS_MAX_PAYLOAD_LENGTH_I                    = 4227,
  NV_SMS_MO_ON_ACCESS_CHANNEL_I                  = 4228,
  NV_SMS_MO_ON_TRAFFIC_CHANNEL_I                 = 4229,
  NV_VOIP_CONFRD_URI_I                           = 4230,
  NV_HDRL1_DBG_MSK_I                             = 4231,
  NV_BUS_PROF_EBI1_ENABLE_I                      = 4232,
  NV_BUS_PROF_SMI_ENABLE_I                       = 4233,
  NV_BUS_PROF_EBI1_MODE_I                        = 4234,
  NV_BUS_PROF_SMI_MODE_I                         = 4235,
  NV_BUS_PROF_EBI1_TRIGGER_ID_I                  = 4236,
  NV_BUS_PROF_SMI_TRIGGER_ID_I                   = 4237,
  NV_BUS_PROF_EBI1_BUS_COUNT_I                   = 4238,
  NV_BUS_PROF_SMI_BUS_COUNT_I                    = 4239,
  NV_BUS_PROF_EBI1_SIMPLE_SETTINGS_0_I           = 4240,
  NV_BUS_PROF_EBI1_SIMPLE_SETTINGS_1_I           = 4241,
  NV_BUS_PROF_EBI1_SIMPLE_SETTINGS_2_I           = 4242,
  NV_BUS_PROF_EBI1_SIMPLE_SETTINGS_3_I           = 4243,
  NV_BUS_PROF_SMI_SIMPLE_SETTINGS_0_I            = 4244,
  NV_BUS_PROF_SMI_SIMPLE_SETTINGS_1_I            = 4245,
  NV_BUS_PROF_SMI_SIMPLE_SETTINGS_2_I            = 4246,
  NV_BUS_PROF_SMI_SIMPLE_SETTINGS_3_I            = 4247,
  NV_BUS_PROF_EBI1_ADVANCE_SETTINGS_0_I          = 4248,
  NV_BUS_PROF_EBI1_ADVANCE_SETTINGS_1_I          = 4249,
  NV_BUS_PROF_EBI1_ADVANCE_SETTINGS_2_I          = 4250,
  NV_BUS_PROF_EBI1_ADVANCE_SETTINGS_3_I          = 4251,
  NV_BUS_PROF_SMI_ADVANCE_SETTINGS_0_I           = 4252,
  NV_BUS_PROF_SMI_ADVANCE_SETTINGS_1_I           = 4253,
  NV_BUS_PROF_SMI_ADVANCE_SETTINGS_2_I           = 4254,
  NV_BUS_PROF_SMI_ADVANCE_SETTINGS_3_I           = 4255,
  NV_HDR_QOS_FLOW_PRIORITY_I                     = 4256,
  NV_RF_PM_CONFIG_I                              = 4257,
  NV_SMS_TL_ACK_ENABLED_I                        = 4258,
  NV_WLAN_BSS_TYPE_PREF_I                        = 4259,
  NV_HDRIDLE_PREF_SLOTTED_MODE_CONFIG_I          = 4260,
  NV_CPU_BASED_FLOW_CONTROL_I                    = 4261,
  NV_PAT_ACQ_TIMEOUT_I                           = 4262,
  NV_PMT_ACQ_TIMEOUT_I                           = 4263,
  NV_INT_ACQ_TIMEOUT_I                           = 4264,
  NV_VOIP_REGISTRATION_MODE_I                    = 4265,
  NV_GPS1_CME_MAX_THROTTLE_DURATION_I            = 4266,
  NV_TIME_TOD_OFFSET_I                           = 4267,
  NV_BC15_TX_LIN_MASTER0_I                       = 4268,
  NV_BC15_TX_LIN_MASTER1_I                       = 4269,
  NV_BC15_TX_LIN_MASTER2_I                       = 4270,
  NV_BC15_TX_LIN_MASTER3_I                       = 4271,
  NV_BC15_GPS1_RF_DELAY_I                        = 4272,
  NV_BC15_TX_LIM_VS_TEMP_I                       = 4273,
  NV_BC15_TX_COMP0_I                             = 4274,
  NV_BC15_TX_COMP1_I                             = 4275,
  NV_BC15_TX_COMP2_I                             = 4276,
  NV_BC15_TX_COMP3_I                             = 4277,
  NV_BC15_TX_LIM_VS_FREQ_I                       = 4278,
  NV_BC15_PA_R1_RISE_I                           = 4279,
  NV_BC15_PA_R1_FALL_I                           = 4280,
  NV_BC15_PA_R2_RISE_I                           = 4281,
  NV_BC15_PA_R2_FALL_I                           = 4282,
  NV_BC15_PA_R3_RISE_I                           = 4283,
  NV_BC15_PA_R3_FALL_I                           = 4284,
  NV_BC15_HDET_OFF_I                             = 4285,
  NV_BC15_HDET_SPN_I                             = 4286,
  NV_BC15_EXP_HDET_VS_AGC_I                      = 4287,
  NV_BC15_ENC_BTF_I                              = 4288,
  NV_BC15_VCO_COARSE_TUNE_TABLE_I                = 4289,
  NV_BC15_VCO_TUNE_2_I                           = 4290,
  NV_BC15_P1_RISE_FALL_OFF_I                     = 4291,
  NV_BC15_HDR_P1_RISE_FALL_OFF_I                 = 4292,
  NV_C0_BC15_TX_CAL_CHAN_I                       = 4293,
  NV_C0_BC15_RX_CAL_CHAN_I                       = 4294,
  NV_C0_BC15_RX_CAL_CHAN_LRU_I                   = 4295,
  NV_C0_BC15_LNA_1_OFFSET_I                      = 4296,
  NV_C0_BC15_LNA_2_OFFSET_I                      = 4297,
  NV_C0_BC15_LNA_3_OFFSET_I                      = 4298,
  NV_C0_BC15_LNA_4_OFFSET_I                      = 4299,
  NV_C0_BC15_LNA_1_OFFSET_VS_FREQ_I              = 4300,
  NV_C0_BC15_LNA_2_OFFSET_VS_FREQ_I              = 4301,
  NV_C0_BC15_LNA_3_OFFSET_VS_FREQ_I              = 4302,
  NV_C0_BC15_LNA_4_OFFSET_VS_FREQ_I              = 4303,
  NV_C0_BC15_IM2_I_VALUE_I                       = 4304,
  NV_C0_BC15_IM2_Q_VALUE_I                       = 4305,
  NV_C0_BC15_VGA_GAIN_OFFSET_I                   = 4306,
  NV_C0_BC15_VGA_GAIN_OFFSET_VS_FREQ_I           = 4307,
  NV_C0_BC15_IM2_TRANSCONDUCTOR_VALUE_I          = 4308,
  NV_C0_BC15_LNA_1_RISE_I                        = 4309,
  NV_C0_BC15_LNA_1_FALL_I                        = 4310,
  NV_C0_BC15_LNA_2_RISE_I                        = 4311,
  NV_C0_BC15_LNA_2_FALL_I                        = 4312,
  NV_C0_BC15_LNA_3_RISE_I                        = 4313,
  NV_C0_BC15_LNA_3_FALL_I                        = 4314,
  NV_C0_BC15_LNA_4_RISE_I                        = 4315,
  NV_C0_BC15_LNA_4_FALL_I                        = 4316,
  NV_C0_BC15_IM_LEVEL1_I                         = 4317,
  NV_C0_BC15_IM_LEVEL2_I                         = 4318,
  NV_C0_BC15_IM_LEVEL3_I                         = 4319,
  NV_C0_BC15_IM_LEVEL4_I                         = 4320,
  NV_C1_BC15_TX_CAL_CHAN_I                       = 4321,
  NV_C1_BC15_RX_CAL_CHAN_I                       = 4322,
  NV_C1_BC15_LNA_1_OFFSET_VS_FREQ_I              = 4323,
  NV_C1_BC15_LNA_2_OFFSET_VS_FREQ_I              = 4324,
  NV_C1_BC15_LNA_3_OFFSET_VS_FREQ_I              = 4325,
  NV_C1_BC15_LNA_4_OFFSET_VS_FREQ_I              = 4326,
  NV_C1_BC15_LNA_1_OFFSET_I                      = 4327,
  NV_C1_BC15_LNA_2_OFFSET_I                      = 4328,
  NV_C1_BC15_LNA_3_OFFSET_I                      = 4329,
  NV_C1_BC15_LNA_4_OFFSET_I                      = 4330,
  NV_C1_BC15_IM2_I_VALUE_I                       = 4331,
  NV_C1_BC15_IM2_Q_VALUE_I                       = 4332,
  NV_C1_BC15_VGA_GAIN_OFFSET_I                   = 4333,
  NV_C1_BC15_VGA_GAIN_OFFSET_VS_FREQ_I           = 4334,
  NV_C1_BC15_IM2_TRANSCONDUCTOR_VALUE_I          = 4335,
  NV_C1_BC15_LNA_1_RISE_I                        = 4336,
  NV_C1_BC15_LNA_1_FALL_I                        = 4337,
  NV_C1_BC15_LNA_2_RISE_I                        = 4338,
  NV_C1_BC15_LNA_2_FALL_I                        = 4339,
  NV_C1_BC15_LNA_3_RISE_I                        = 4340,
  NV_C1_BC15_LNA_3_FALL_I                        = 4341,
  NV_C1_BC15_LNA_4_RISE_I                        = 4342,
  NV_C1_BC15_LNA_4_FALL_I                        = 4343,
  NV_C1_BC15_IM_LEVEL1_I                         = 4344,
  NV_C1_BC15_IM_LEVEL2_I                         = 4345,
  NV_C1_BC15_IM_LEVEL3_I                         = 4346,
  NV_C1_BC15_IM_LEVEL4_I                         = 4347,
  NV_C1_BC15_VCO_COARSE_TUNE_TABLE_I             = 4348,
  NV_BC15_ANT_QUALITY_I                          = 4349,
  NV_BC15_PA_DVS_VOLTAGE_I                       = 4350,
  NV_C0_BC15_LNA_SWITCHPOINTS_LPM_1_I            = 4351,
  NV_C0_BC15_LNA_SWITCHPOINTS_LPM_2_I            = 4352,
  NV_C0_BC15_IM2_LPM_1_I                         = 4353,
  NV_C0_BC15_IM2_LPM_2_I                         = 4354,
  NV_C0_BC15_INTELLICEIVER_CAL_I                 = 4355,
  NV_C0_BC15_INTELLICEIVER_DET_THRESH_I          = 4356,
  NV_C1_BC15_RX_CAL_CHAN_LRU_I                   = 4357,
  NV_DCVS_ACPU_ENABLE_I                          = 4358,
  NV_GPSONE_PASSWORD_I                           = 4359,
  NV_VOIP_CALLERID_MODE_I                        = 4360,
  NV_WLAN_MULTIDOMAIN_CAPABILITY_PREF_I          = 4361,
  NV_UMTS_NBNS_ENABLE_I                          = 4362,
  NV_SCUDIF_CALLSETUP_PREF_I                     = 4363,
  NV_VOIP_REFER_SUBSCRIPTION_EXPIRES_DURATION_I  = 4364,
  NV_VOIP_NOTIFY_REFER_RESPONSE_DURATION_I       = 4365,
  NV_SMS_SERVICE_OPTION_I                        = 4366,
  NV_DRM_BIND_SIM_RIGHTS_I                       = 4367,
  NV_GSM_850_PA_TEMP_COMP_MAX_PWR_I              = 4368,
  NV_GSM_PA_TEMP_COMP_MAX_PWR_I                  = 4369,
  NV_DCS_PA_TEMP_COMP_MAX_PWR_I                  = 4370,
  NV_GSM_1900_PA_TEMP_COMP_MAX_PWR_I             = 4371,
  NV_GSM_RSSI_TEMP_VALUES_I                      = 4372,
  NV_GSM_850_RX_GAIN_RANGE_1_TEMP_COMP_I         = 4373,
  NV_GSM_RX_GAIN_RANGE_1_TEMP_COMP_I             = 4374,
  NV_DCS_RX_GAIN_RANGE_1_TEMP_COMP_I             = 4375,
  NV_GSM_1900_RX_GAIN_RANGE_1_TEMP_COMP_I        = 4376,
  NV_GSM_850_RX_GAIN_RANGE_2_TEMP_COMP_I         = 4377,
  NV_GSM_RX_GAIN_RANGE_2_TEMP_COMP_I             = 4378,
  NV_DCS_RX_GAIN_RANGE_2_TEMP_COMP_I             = 4379,
  NV_GSM_1900_RX_GAIN_RANGE_2_TEMP_COMP_I        = 4380,
  NV_GSM_850_RX_GAIN_RANGE_3_TEMP_COMP_I         = 4381,
  NV_GSM_RX_GAIN_RANGE_3_TEMP_COMP_I             = 4382,
  NV_DCS_RX_GAIN_RANGE_3_TEMP_COMP_I             = 4383,
  NV_GSM_1900_RX_GAIN_RANGE_3_TEMP_COMP_I        = 4384,
  NV_GSM_850_RX_GAIN_RANGE_4_TEMP_COMP_I         = 4385,
  NV_GSM_RX_GAIN_RANGE_4_TEMP_COMP_I             = 4386,
  NV_DCS_RX_GAIN_RANGE_4_TEMP_COMP_I             = 4387,
  NV_GSM_1900_RX_GAIN_RANGE_4_TEMP_COMP_I        = 4388,
  NV_GSM_850_RX_GAIN_RANGE_5_TEMP_COMP_I         = 4389,
  NV_GSM_RX_GAIN_RANGE_5_TEMP_COMP_I             = 4390,
  NV_DCS_RX_GAIN_RANGE_5_TEMP_COMP_I             = 4391,
  NV_GSM_1900_RX_GAIN_RANGE_5_TEMP_COMP_I        = 4392,
  NV_DCVSAPPS_NV_I                               = 4393,
  NV_GPS1_SEC_UPDATE_RATE_I                      = 4394,
  NV_MMGSDI_ME_CONFIG_PARAM_I                    = 4395,
  NV_DS_MIP_DEREG_RETRIES_I                      = 4396,
  NV_RUIM_NO_SUPPORT_I                           = 4397,
  NV_UIM_SELECT_DEFAULT_USIM_APP_I               = 4398,
  NV_DETECT_HW_RESET_I                           = 4399,
  NV_WCDMA_IM_LEVEL_4_I                          = 4400,
  NV_WCDMA_LNA_OFFSET_VS_FREQ_4_I                = 4401,
  NV_WCDMA_LNA_RANGE_FALL_4_I                    = 4402,
  NV_WCDMA_LNA_RANGE_OFFSET_4_I                  = 4403,
  NV_WCDMA_LNA_RANGE_RISE_4_I                    = 4404,
  NV_WCDMA_1900_IM_LEVEL_4_I                     = 4405,
  NV_WCDMA_1900_LNA_OFFSET_VS_FREQ_4_I           = 4406,
  NV_WCDMA_1900_LNA_RANGE_FALL_4_I               = 4407,
  NV_WCDMA_1900_LNA_RANGE_OFFSET_4_I             = 4408,
  NV_WCDMA_1900_LNA_RANGE_RISE_4_I               = 4409,
  NV_WCDMA_800_IM_LEVEL_4_I                      = 4410,
  NV_WCDMA_800_LNA_OFFSET_VS_FREQ_4_I            = 4411,
  NV_WCDMA_800_LNA_RANGE_FALL_4_I                = 4412,
  NV_WCDMA_800_LNA_RANGE_OFFSET_4_I              = 4413,
  NV_WCDMA_800_LNA_RANGE_RISE_4_I                = 4414,
  NV_WCDMA_1800_IM_LEVEL_4_I                     = 4415,
  NV_WCDMA_1800_LNA_OFFSET_VS_FREQ_4_I           = 4416,
  NV_WCDMA_1800_LNA_RANGE_FALL_4_I               = 4417,
  NV_WCDMA_1800_LNA_RANGE_OFFSET_4_I             = 4418,
  NV_WCDMA_1800_LNA_RANGE_RISE_4_I               = 4419,
  NV_WCDMA_900_IM_LEVEL_4_I                      = 4420,
  NV_WCDMA_900_LNA_OFFSET_VS_FREQ_4_I            = 4421,
  NV_WCDMA_900_LNA_RANGE_FALL_4_I                = 4422,
  NV_WCDMA_900_LNA_RANGE_OFFSET_4_I              = 4423,
  NV_WCDMA_900_LNA_RANGE_RISE_4_I                = 4424,
  NV_WCDMA_BC4_IM_LEVEL_4_I                      = 4425,
  NV_WCDMA_BC4_LNA_OFFSET_VS_FREQ_4_I            = 4426,
  NV_WCDMA_BC4_LNA_RANGE_FALL_4_I                = 4427,
  NV_WCDMA_BC4_LNA_RANGE_OFFSET_4_I              = 4428,
  NV_WCDMA_BC4_LNA_RANGE_RISE_4_I                = 4429,
  NV_IPV6_PRIVACY_EXTENSIONS_ENABLED_I           = 4430,
  NV_IPV6_PRIVATE_ADDRESS_CONFIG_I               = 4431,
  NV_GPRS_GEA_ALGORITHMS_SUPPORTED_I             = 4432,
  NV_REX_TRACE_I                                 = 4433,
  NV_C1_WCDMA_1800_VGA_GAIN_OFFSET_I             = 4434,
  NV_C1_WCDMA_1800_VGA_GAIN_OFFSET_VS_FREQ_I     = 4435,
  NV_C1_WCDMA_1800_VGA_GAIN_OFFSET_VS_TEMP_I     = 4436,
  NV_C1_WCDMA_1800_LNA_RANGE_RISE_I              = 4437,
  NV_C1_WCDMA_1800_LNA_RANGE_RISE_2_I            = 4438,
  NV_C1_WCDMA_1800_LNA_RANGE_RISE_3_I            = 4439,
  NV_C1_WCDMA_1800_LNA_RANGE_RISE_4_I            = 4440,
  NV_C1_WCDMA_1800_LNA_RANGE_FALL_I              = 4441,
  NV_C1_WCDMA_1800_LNA_RANGE_FALL_2_I            = 4442,
  NV_C1_WCDMA_1800_LNA_RANGE_FALL_3_I            = 4443,
  NV_C1_WCDMA_1800_LNA_RANGE_FALL_4_I            = 4444,
  NV_C1_WCDMA_1800_IM_LEVEL_I                    = 4445,
  NV_C1_WCDMA_1800_IM_LEVEL_2_I                  = 4446,
  NV_C1_WCDMA_1800_IM_LEVEL_3_I                  = 4447,
  NV_C1_WCDMA_1800_IM_LEVEL_4_I                  = 4448,
  NV_C1_WCDMA_1800_LNA_RANGE_OFFSET_2_I          = 4449,
  NV_C1_WCDMA_1800_LNA_RANGE_OFFSET_3_I          = 4450,
  NV_C1_WCDMA_1800_LNA_RANGE_OFFSET_4_I          = 4451,
  NV_C1_WCDMA_1800_LNA_OFFSET_VS_FREQ_2_I        = 4452,
  NV_C1_WCDMA_1800_LNA_OFFSET_VS_FREQ_3_I        = 4453,
  NV_C1_WCDMA_1800_LNA_OFFSET_VS_FREQ_4_I        = 4454,
  NV_C1_WCDMA_1800_IM2_I_VALUE_I                 = 4455,
  NV_C1_WCDMA_1800_IM2_Q_VALUE_I                 = 4456,
  NV_C1_WCDMA_1800_IM2_TRANSCONDUCTOR_VALUE_I    = 4457,
  NV_C1_WCDMA_1800_NONBYPASS_TIMER_I             = 4458,
  NV_C1_WCDMA_1800_BYPASS_TIMER_I                = 4459,
  NV_C1_WCDMA_1800_LNA_RANGE_OFFSET_I            = 4460,
  NV_C1_WCDMA_1800_LNA_OFFSET_VS_FREQ_I          = 4461,
  NV_C1_WCDMA_1800_RX_CAL_CHAN_I                 = 4462,
  NV_C1_WCDMA_900_VGA_GAIN_OFFSET_I              = 4463,
  NV_C1_WCDMA_900_VGA_GAIN_OFFSET_VS_FREQ_I      = 4464,
  NV_C1_WCDMA_900_VGA_GAIN_OFFSET_VS_TEMP_I      = 4465,
  NV_C1_WCDMA_900_LNA_RANGE_RISE_I               = 4466,
  NV_C1_WCDMA_900_LNA_RANGE_RISE_2_I             = 4467,
  NV_C1_WCDMA_900_LNA_RANGE_RISE_3_I             = 4468,
  NV_C1_WCDMA_900_LNA_RANGE_RISE_4_I             = 4469,
  NV_C1_WCDMA_900_LNA_RANGE_FALL_I               = 4470,
  NV_C1_WCDMA_900_LNA_RANGE_FALL_2_I             = 4471,
  NV_C1_WCDMA_900_LNA_RANGE_FALL_3_I             = 4472,
  NV_C1_WCDMA_900_LNA_RANGE_FALL_4_I             = 4473,
  NV_C1_WCDMA_900_IM_LEVEL_I                     = 4474,
  NV_C1_WCDMA_900_IM_LEVEL_2_I                   = 4475,
  NV_C1_WCDMA_900_IM_LEVEL_3_I                   = 4476,
  NV_C1_WCDMA_900_IM_LEVEL_4_I                   = 4477,
  NV_C1_WCDMA_900_LNA_RANGE_OFFSET_2_I           = 4478,
  NV_C1_WCDMA_900_LNA_RANGE_OFFSET_3_I           = 4479,
  NV_C1_WCDMA_900_LNA_RANGE_OFFSET_4_I           = 4480,
  NV_C1_WCDMA_900_LNA_OFFSET_VS_FREQ_2_I         = 4481,
  NV_C1_WCDMA_900_LNA_OFFSET_VS_FREQ_3_I         = 4482,
  NV_C1_WCDMA_900_LNA_OFFSET_VS_FREQ_4_I         = 4483,
  NV_C1_WCDMA_900_IM2_I_VALUE_I                  = 4484,
  NV_C1_WCDMA_900_IM2_Q_VALUE_I                  = 4485,
  NV_C1_WCDMA_900_IM2_TRANSCONDUCTOR_VALUE_I     = 4486,
  NV_C1_WCDMA_900_NONBYPASS_TIMER_I              = 4487,
  NV_C1_WCDMA_900_BYPASS_TIMER_I                 = 4488,
  NV_C1_WCDMA_900_LNA_RANGE_OFFSET_I             = 4489,
  NV_C1_WCDMA_900_LNA_OFFSET_VS_FREQ_I           = 4490,
  NV_C1_WCDMA_900_RX_CAL_CHAN_I                  = 4491,
  NV_C1_WCDMA_BC4_VGA_GAIN_OFFSET_I              = 4492,
  NV_C1_WCDMA_BC4_VGA_GAIN_OFFSET_VS_FREQ_I      = 4493,
  NV_C1_WCDMA_BC4_VGA_GAIN_OFFSET_VS_TEMP_I      = 4494,
  NV_C1_WCDMA_BC4_LNA_RANGE_RISE_I               = 4495,
  NV_C1_WCDMA_BC4_LNA_RANGE_RISE_2_I             = 4496,
  NV_C1_WCDMA_BC4_LNA_RANGE_RISE_3_I             = 4497,
  NV_C1_WCDMA_BC4_LNA_RANGE_RISE_4_I             = 4498,
  NV_C1_WCDMA_BC4_LNA_RANGE_FALL_I               = 4499,
  NV_C1_WCDMA_BC4_LNA_RANGE_FALL_2_I             = 4500,
  NV_C1_WCDMA_BC4_LNA_RANGE_FALL_3_I             = 4501,
  NV_C1_WCDMA_BC4_LNA_RANGE_FALL_4_I             = 4502,
  NV_C1_WCDMA_BC4_IM_LEVEL_I                     = 4503,
  NV_C1_WCDMA_BC4_IM_LEVEL_2_I                   = 4504,
  NV_C1_WCDMA_BC4_IM_LEVEL_3_I                   = 4505,
  NV_C1_WCDMA_BC4_IM_LEVEL_4_I                   = 4506,
  NV_C1_WCDMA_BC4_LNA_RANGE_OFFSET_2_I           = 4507,
  NV_C1_WCDMA_BC4_LNA_RANGE_OFFSET_3_I           = 4508,
  NV_C1_WCDMA_BC4_LNA_RANGE_OFFSET_4_I           = 4509,
  NV_C1_WCDMA_BC4_LNA_OFFSET_VS_FREQ_2_I         = 4510,
  NV_C1_WCDMA_BC4_LNA_OFFSET_VS_FREQ_3_I         = 4511,
  NV_C1_WCDMA_BC4_LNA_OFFSET_VS_FREQ_4_I         = 4512,
  NV_C1_WCDMA_BC4_IM2_I_VALUE_I                  = 4513,
  NV_C1_WCDMA_BC4_IM2_Q_VALUE_I                  = 4514,
  NV_C1_WCDMA_BC4_IM2_TRANSCONDUCTOR_VALUE_I     = 4515,
  NV_C1_WCDMA_BC4_NONBYPASS_TIMER_I              = 4516,
  NV_C1_WCDMA_BC4_BYPASS_TIMER_I                 = 4517,
  NV_C1_WCDMA_BC4_LNA_RANGE_OFFSET_I             = 4518,
  NV_C1_WCDMA_BC4_LNA_OFFSET_VS_FREQ_I           = 4519,
  NV_C1_WCDMA_BC4_RX_CAL_CHAN_I                  = 4520,
  NV_MF_PREF_RF_CHAN_LIST_I                      = 4521,
  NV_MF_IC_UPDATE_RATE_I                         = 4522,
  NV_NPT_COUNT_I                                 = 4523,
  NV_SMS_BEARER_PREFS_I                          = 4524,
  NV_BT_DISABLED_I                               = 4525,
  NV_HS_USB_CURRENT_COMPOSITION_I                = 4526,
  NV_WLAN_ENABLE_BT_COEX_I                       = 4527,
  NV_HDR_EMPA_SUPPORTED_I                        = 4528,
  NV_AAGPS_XTRA_ENABLED_I                        = 4529,
  NV_AAGPS_XTRA_DOWNLOAD_INTERVAL_I              = 4530,
  NV_AAGPS_XTRA_NUM_DOWNLOAD_ATTEMPTS_I          = 4531,
  NV_AAGPS_XTRA_PRIMARY_SERVER_URL_I             = 4532,
  NV_AAGPS_XTRA_SECONDARY_SERVER_URL_I           = 4533,
  NV_AAGPS_XTRA_TIME_BETWEEN_ATTEMPTS_I          = 4534,
  NV_AAGPS_XTRA_TERTIARY_SERVER_URL_I            = 4535,
  NV_AAGPS_XTRA_AUTO_DOWNLOAD_ENABLED_I          = 4536,
  NV_AAGPS_XTRA_TIME_INFO_ENABLED_I              = 4537,
  NV_AAGPS_XTRA_TIME_INFO_UNC_THRESH_I           = 4538,
  NV_AAGPS_XTRA_TIME_INFO_DELAY_THRESH_I         = 4539,
  NV_AAGPS_XTRA_PRIMARY_SNTP_SERVER_URL_I        = 4540,
  NV_AAGPS_XTRA_SECONDARY_SNTP_SERVER_URL_I      = 4541,
  NV_AAGPS_XTRA_TERTIARY_SNTP_SERVER_URL_I       = 4542,
  NV_VOIP_PRECONDITION_ENABLE_I                  = 4543,
  NV_AAGPS_IPC_DM_THREAD_MASK_I                  = 4544,
  NV_MF_RF_OVERRIDE_DESC_I                       = 4545,
  NV_MF_DMTT_PARAMS_I                            = 4546,
  NV_CAMERA_DEFAULT_PREVIEW_ROTATION_I           = 4547,
  NV_RF_BC_CONFIG_DIV_I                          = 4548,
  NV_BCX_BLOCK_GPS1_RF_DELAY_I                   = 4549,
  NV_BCX_BLOCK_RF_TUNE_RESERVED_I                = 4550,
  NV_BCX_BLOCK_TX_LIM_VS_TEMP_I                  = 4551,
  NV_BCX_BLOCK_TX_LIN_MASTER0_I                  = 4552,
  NV_BCX_BLOCK_TX_LIN_MASTER1_I                  = 4553,
  NV_BCX_BLOCK_TX_LIN_MASTER2_I                  = 4554,
  NV_BCX_BLOCK_TX_LIN_MASTER3_I                  = 4555,
  NV_BCX_BLOCK_TX_COMP0_I                        = 4556,
  NV_BCX_BLOCK_TX_COMP1_I                        = 4557,
  NV_BCX_BLOCK_TX_COMP2_I                        = 4558,
  NV_BCX_BLOCK_TX_COMP3_I                        = 4559,
  NV_BCX_BLOCK_TX_LIM_VS_FREQ_I                  = 4560,
  NV_BCX_BLOCK_PA_R1_RISE_I                      = 4561,
  NV_BCX_BLOCK_PA_R1_FALL_I                      = 4562,
  NV_BCX_BLOCK_PA_R2_RISE_I                      = 4563,
  NV_BCX_BLOCK_PA_R2_FALL_I                      = 4564,
  NV_BCX_BLOCK_PA_R3_RISE_I                      = 4565,
  NV_BCX_BLOCK_PA_R3_FALL_I                      = 4566,
  NV_BCX_BLOCK_HDET_OFF_I                        = 4567,
  NV_BCX_BLOCK_HDET_SPN_I                        = 4568,
  NV_BCX_BLOCK_EXP_HDET_VS_AGC_I                 = 4569,
  NV_BCX_BLOCK_ENC_BTF_I                         = 4570,
  NV_BCX_BLOCK_VCO_COARSE_TUNE_TABLE_I           = 4571,
  NV_BCX_BLOCK_P1_RISE_FALL_OFF_I                = 4572,
  NV_C0_BCX_BLOCK_TX_CAL_CHAN_I                  = 4573,
  NV_C0_BCX_BLOCK_RX_CAL_CHAN_I                  = 4574,
  NV_C0_BCX_BLOCK_LNA_1_OFFSET_VS_FREQ_I         = 4575,
  NV_C0_BCX_BLOCK_LNA_2_OFFSET_VS_FREQ_I         = 4576,
  NV_C0_BCX_BLOCK_LNA_3_OFFSET_VS_FREQ_I         = 4577,
  NV_C0_BCX_BLOCK_LNA_4_OFFSET_VS_FREQ_I         = 4578,
  NV_C0_BCX_BLOCK_LNA_1_OFFSET_I                 = 4579,
  NV_C0_BCX_BLOCK_LNA_2_OFFSET_I                 = 4580,
  NV_C0_BCX_BLOCK_LNA_3_OFFSET_I                 = 4581,
  NV_C0_BCX_BLOCK_LNA_4_OFFSET_I                 = 4582,
  NV_C0_BCX_BLOCK_IM2_I_VALUE_I                  = 4583,
  NV_C0_BCX_BLOCK_IM2_Q_VALUE_I                  = 4584,
  NV_C0_BCX_BLOCK_VGA_GAIN_OFFSET_I              = 4585,
  NV_C0_BCX_BLOCK_VGA_GAIN_OFFSET_VS_FREQ_I      = 4586,
  NV_C0_BCX_BLOCK_IM2_TRANSCONDUCTOR_VALUE_I     = 4587,
  NV_C0_BCX_BLOCK_LNA_1_RISE_I                   = 4588,
  NV_C0_BCX_BLOCK_LNA_1_FALL_I                   = 4589,
  NV_C0_BCX_BLOCK_LNA_2_RISE_I                   = 4590,
  NV_C0_BCX_BLOCK_LNA_2_FALL_I                   = 4591,
  NV_C0_BCX_BLOCK_LNA_3_RISE_I                   = 4592,
  NV_C0_BCX_BLOCK_LNA_3_FALL_I                   = 4593,
  NV_C0_BCX_BLOCK_LNA_4_RISE_I                   = 4594,
  NV_C0_BCX_BLOCK_LNA_4_FALL_I                   = 4595,
  NV_C0_BCX_BLOCK_IM_LEVEL1_I                    = 4596,
  NV_C0_BCX_BLOCK_IM_LEVEL2_I                    = 4597,
  NV_C0_BCX_BLOCK_IM_LEVEL3_I                    = 4598,
  NV_C0_BCX_BLOCK_IM_LEVEL4_I                    = 4599,
  NV_C1_BCX_BLOCK_TX_CAL_CHAN_I                  = 4600,
  NV_C1_BCX_BLOCK_RX_CAL_CHAN_I                  = 4601,
  NV_C1_BCX_BLOCK_LNA_1_OFFSET_VS_FREQ_I         = 4602,
  NV_C1_BCX_BLOCK_LNA_2_OFFSET_VS_FREQ_I         = 4603,
  NV_C1_BCX_BLOCK_LNA_3_OFFSET_VS_FREQ_I         = 4604,
  NV_C1_BCX_BLOCK_LNA_4_OFFSET_VS_FREQ_I         = 4605,
  NV_C1_BCX_BLOCK_LNA_1_OFFSET_I                 = 4606,
  NV_C1_BCX_BLOCK_LNA_2_OFFSET_I                 = 4607,
  NV_C1_BCX_BLOCK_LNA_3_OFFSET_I                 = 4608,
  NV_C1_BCX_BLOCK_LNA_4_OFFSET_I                 = 4609,
  NV_C1_BCX_BLOCK_IM2_I_VALUE_I                  = 4610,
  NV_C1_BCX_BLOCK_IM2_Q_VALUE_I                  = 4611,
  NV_C1_BCX_BLOCK_VGA_GAIN_OFFSET_I              = 4612,
  NV_C1_BCX_BLOCK_VGA_GAIN_OFFSET_VS_FREQ_I      = 4613,
  NV_C1_BCX_BLOCK_IM2_TRANSCONDUCTOR_VALUE_I     = 4614,
  NV_C1_BCX_BLOCK_LNA_1_RISE_I                   = 4615,
  NV_C1_BCX_BLOCK_LNA_1_FALL_I                   = 4616,
  NV_C1_BCX_BLOCK_LNA_2_RISE_I                   = 4617,
  NV_C1_BCX_BLOCK_LNA_2_FALL_I                   = 4618,
  NV_C1_BCX_BLOCK_LNA_3_RISE_I                   = 4619,
  NV_C1_BCX_BLOCK_LNA_3_FALL_I                   = 4620,
  NV_C1_BCX_BLOCK_LNA_4_RISE_I                   = 4621,
  NV_C1_BCX_BLOCK_LNA_4_FALL_I                   = 4622,
  NV_C1_BCX_BLOCK_IM_LEVEL1_I                    = 4623,
  NV_C1_BCX_BLOCK_IM_LEVEL2_I                    = 4624,
  NV_C1_BCX_BLOCK_IM_LEVEL3_I                    = 4625,
  NV_C1_BCX_BLOCK_IM_LEVEL4_I                    = 4626,
  NV_GPS1_XTRA_ENABLED_I                         = 4627,
  NV_GPS1_XTRA_DOWNLOAD_INTERVAL_I               = 4628,
  NV_GPS1_XTRA_NUM_DOWNLOAD_ATTEMPTS_I           = 4629,
  NV_GPS1_XTRA_TIME_BETWEEN_ATTEMPTS_I           = 4630,
  NV_GPS1_XTRA_AUTO_DOWNLOAD_ENABLED_I           = 4631,
  NV_GPS1_XTRA_PRIMARY_SERVER_URL_I              = 4632,
  NV_GPS1_XTRA_SECONDARY_SERVER_URL_I            = 4633,
  NV_GPS1_XTRA_TERTIARY_SERVER_URL_I             = 4634,
  NV_DB_LP_SEC_I                                 = 4635,
  NV_DB_LTM_OFF_I                                = 4636,
  NV_DB_DAYLT_I                                  = 4637,
  NV_BC0_TX_PDM_LIN_0_I                          = 4638,
  NV_BC0_TX_PDM_LIN_1_I                          = 4639,
  NV_BC0_TX_PDM_LIN_2_I                          = 4640,
  NV_BC0_TX_PDM_LIN_3_I                          = 4641,
  NV_BC1_TX_PDM_LIN_0_I                          = 4642,
  NV_BC1_TX_PDM_LIN_1_I                          = 4643,
  NV_BC1_TX_PDM_LIN_2_I                          = 4644,
  NV_BC1_TX_PDM_LIN_3_I                          = 4645,
  NV_BC3_TX_PDM_LIN_0_I                          = 4646,
  NV_BC3_TX_PDM_LIN_1_I                          = 4647,
  NV_BC3_TX_PDM_LIN_2_I                          = 4648,
  NV_BC3_TX_PDM_LIN_3_I                          = 4649,
  NV_BC4_TX_PDM_LIN_0_I                          = 4650,
  NV_BC4_TX_PDM_LIN_1_I                          = 4651,
  NV_BC4_TX_PDM_LIN_2_I                          = 4652,
  NV_BC4_TX_PDM_LIN_3_I                          = 4653,
  NV_BC5_TX_PDM_LIN_0_I                          = 4654,
  NV_BC5_TX_PDM_LIN_1_I                          = 4655,
  NV_BC5_TX_PDM_LIN_2_I                          = 4656,
  NV_BC5_TX_PDM_LIN_3_I                          = 4657,
  NV_BC6_TX_PDM_LIN_0_I                          = 4658,
  NV_BC6_TX_PDM_LIN_1_I                          = 4659,
  NV_BC6_TX_PDM_LIN_2_I                          = 4660,
  NV_BC6_TX_PDM_LIN_3_I                          = 4661,
  NV_BC11_TX_PDM_LIN_0_I                         = 4662,
  NV_BC11_TX_PDM_LIN_1_I                         = 4663,
  NV_BC11_TX_PDM_LIN_2_I                         = 4664,
  NV_BC11_TX_PDM_LIN_3_I                         = 4665,
  NV_BC14_TX_PDM_LIN_0_I                         = 4666,
  NV_BC14_TX_PDM_LIN_1_I                         = 4667,
  NV_BC14_TX_PDM_LIN_2_I                         = 4668,
  NV_BC14_TX_PDM_LIN_3_I                         = 4669,
  NV_BC15_TX_PDM_LIN_0_I                         = 4670,
  NV_BC15_TX_PDM_LIN_1_I                         = 4671,
  NV_BC15_TX_PDM_LIN_2_I                         = 4672,
  NV_BC15_TX_PDM_LIN_3_I                         = 4673,
  NV_HIT_ENABLE_I                                = 4674,
  NV_VCI_PARAMETERS_I                            = 4675,
  NV_DS707_GO_NULL_TIMER_1X_I                    = 4676,
  NV_DS707_GO_NULL_TIMER_DO_I                    = 4677,
  NV_WLAN_MAC_ADDRESS_I                          = 4678,
  NV_CLK_REGIME_TEST_CFG_I                       = 4679,
  NV_DVBH_PAT_ACQ_TIMEOUT_I                      = 4680,
  NV_DVBH_PMT_ACQ_TIMEOUT_I                      = 4681,
  NV_DVBH_INT_ACQ_TIMEOUT_I                      = 4682,
  NV_DVBH_UHF_FREQ_BAND_RANGE_I                  = 4683,
  NV_DVBH_VHF_FREQ_BAND_RANGE_I                  = 4684,
  NV_DVBH_L_FREQ_BAND_RANGE_I                    = 4685,
  NV_DVBH_UHF_BAND_BW_I                          = 4686,
  NV_DVBH_UHF_BAND_OFFSET_I                      = 4687,
  NV_DVBH_VHF_BAND_BW_I                          = 4688,
  NV_DVBH_VHF_BAND_OFFSET_I                      = 4689,
  NV_DVBH_L_BAND_BW_I                            = 4690,
  NV_DVBH_L_BAND_OFFSET_I                        = 4691,
  NV_DVBH_PLATFORM_NW_ID_LIST_I                  = 4692,
  NV_HTTP_PROXY_SERVER_ADDR_I                    = 4693,
  NV_HTTP_PROXY_SERVER_ADDR_ALTERNATE_I          = 4694,
  NV_CGPS_1X_PDE_SERVER_ADDR_IPV4_I              = 4695,
  NV_CGPS_1X_PDE_SERVER_ADDR_IPV6_I              = 4696,
  NV_CGPS_1X_PDE_SERVER_ADDR_URL_I               = 4697,
  NV_CGPS_1X_MPC_SERVER_ADDR_IPV4_I              = 4698,
  NV_CGPS_1X_MPC_SERVER_ADDR_IPV6_I              = 4699,
  NV_CGPS_1X_MPC_SERVER_ADDR_URL_I               = 4700,
  NV_CGPS_UMTS_PDE_SERVER_ADDR_IPV4_I            = 4701,
  NV_CGPS_UMTS_PDE_SERVER_ADDR_IPV6_I            = 4702,
  NV_CGPS_UMTS_PDE_SERVER_ADDR_URL_I             = 4703,
  NV_CGPS_1X_PDE_SERVER_PORT_I                   = 4704,
  NV_CGPS_1X_MPC_SERVER_PORT_I                   = 4705,
  NV_CGPS_UMTS_PDE_SERVER_PORT_I                 = 4706,
  NV_CGPS_MO_METHOD_I                            = 4707,
  NV_CGPS_NMEA_SENTENCE_TYPE_I                   = 4708,
  NV_CGPS_MAX_OSC_UNC_ACTIVE_SYS_I               = 4709,
  NV_CGPS_MAX_OSC_UNC_RGS_I                      = 4710,
  NV_CGPS_MAX_OSC_UNC_TEMP_TBL_I                 = 4711,
  NV_CGPS_MAX_OSC_UNC_RGS_OLD_I                  = 4712,
  NV_CGPS_MAX_CARRIER_CODE_FILTER_I              = 4713,
  NV_CGPS_MAX_INTEGRATE_MS_I                     = 4714,
  NV_CGPS_ME_RESERVED1_I                         = 4715,
  NV_CGPS_ME_RESERVED2_I                         = 4716,
  NV_CGPS_ME_RESERVED3_I                         = 4717,
  NV_CGPS_ME_RESERVED4_I                         = 4718,
  NV_FTM_MODE_BOOT_COUNT_I                       = 4719,
  NV_MF_RSSI_CAL_VS_FREQ_4_I                     = 4720,
  NV_MF_RSSI_CAL_VS_FREQ_5_I                     = 4721,
  NV_NAS_RELEASE_COMPLIANCE_I                    = 4722,
  NV_WCDMA_BC4_HS_IM_LEVEL_4_I                   = 4723,
  NV_WCDMA_BC4_HS_IM_LEVEL_3_I                   = 4724,
  NV_WCDMA_BC4_HS_IM_LEVEL_2_I                   = 4725,
  NV_WCDMA_BC4_HS_IM_LEVEL_I                     = 4726,
  NV_WCDMA_BC4_HS_LNA_RANGE_RISE_4_I             = 4727,
  NV_WCDMA_BC4_HS_LNA_RANGE_RISE_3_I             = 4728,
  NV_WCDMA_BC4_HS_LNA_RANGE_RISE_2_I             = 4729,
  NV_WCDMA_BC4_HS_LNA_RANGE_RISE_I               = 4730,
  NV_WCDMA_BC4_HS_LNA_RANGE_FALL_2_I             = 4731,
  NV_WCDMA_BC4_HS_LNA_RANGE_FALL_3_I             = 4732,
  NV_WCDMA_BC4_HS_LNA_RANGE_FALL_4_I             = 4733,
  NV_WCDMA_BC4_HS_LNA_RANGE_FALL_I               = 4734,
  NV_WCDMA_900_HS_LNA_RANGE_RISE_2_I             = 4735,
  NV_WCDMA_900_HS_LNA_RANGE_RISE_I               = 4736,
  NV_WCDMA_900_HS_LNA_RANGE_RISE_3_I             = 4737,
  NV_WCDMA_900_HS_LNA_RANGE_RISE_4_I             = 4738,
  NV_WCDMA_900_HS_LNA_RANGE_FALL_4_I             = 4739,
  NV_WCDMA_900_HS_LNA_RANGE_FALL_3_I             = 4740,
  NV_WCDMA_900_HS_LNA_RANGE_FALL_2_I             = 4741,
  NV_WCDMA_900_HS_LNA_RANGE_FALL_I               = 4742,
  NV_WCDMA_900_HS_IM_LEVEL_2_I                   = 4743,
  NV_WCDMA_900_HS_IM_LEVEL_3_I                   = 4744,
  NV_WCDMA_900_HS_IM_LEVEL_I                     = 4745,
  NV_WCDMA_900_HS_IM_LEVEL_4_I                   = 4746,
  NV_WCDMA_1800_HS_LNA_RANGE_RISE_3_I            = 4747,
  NV_WCDMA_1800_HS_LNA_RANGE_RISE_4_I            = 4748,
  NV_WCDMA_1800_HS_LNA_RANGE_RISE_2_I            = 4749,
  NV_WCDMA_1800_HS_LNA_RANGE_RISE_I              = 4750,
  NV_WCDMA_1800_HS_LNA_RANGE_FALL_3_I            = 4751,
  NV_WCDMA_1800_HS_LNA_RANGE_FALL_2_I            = 4752,
  NV_WCDMA_1800_HS_LNA_RANGE_FALL_4_I            = 4753,
  NV_WCDMA_1800_HS_LNA_RANGE_FALL_I              = 4754,
  NV_WCDMA_1800_HS_IM_LEVEL_4_I                  = 4755,
  NV_WCDMA_1800_HS_IM_LEVEL_3_I                  = 4756,
  NV_WCDMA_1800_HS_IM_LEVEL_2_I                  = 4757,
  NV_WCDMA_1800_HS_IM_LEVEL_I                    = 4758,
  NV_WCDMA_1900_HS_LNA_RANGE_FALL_4_I            = 4759,
  NV_WCDMA_1900_HS_LNA_RANGE_FALL_3_I            = 4760,
  NV_WCDMA_1900_HS_LNA_RANGE_FALL_2_I            = 4761,
  NV_WCDMA_1900_HS_LNA_RANGE_FALL_I              = 4762,
  NV_WCDMA_1900_HS_LNA_RANGE_RISE_4_I            = 4763,
  NV_WCDMA_1900_HS_LNA_RANGE_RISE_3_I            = 4764,
  NV_WCDMA_1900_HS_LNA_RANGE_RISE_2_I            = 4765,
  NV_WCDMA_1900_HS_LNA_RANGE_RISE_I              = 4766,
  NV_WCDMA_1900_HS_IM_LEVEL_2_I                  = 4767,
  NV_WCDMA_1900_HS_IM_LEVEL_I                    = 4768,
  NV_WCDMA_1900_HS_IM_LEVEL_3_I                  = 4769,
  NV_WCDMA_1900_HS_IM_LEVEL_4_I                  = 4770,
  NV_WCDMA_800_HS_LNA_RANGE_RISE_4_I             = 4771,
  NV_WCDMA_800_HS_LNA_RANGE_RISE_3_I             = 4772,
  NV_WCDMA_800_HS_LNA_RANGE_RISE_2_I             = 4773,
  NV_WCDMA_800_HS_LNA_RANGE_RISE_I               = 4774,
  NV_WCDMA_800_HS_LNA_RANGE_FALL_2_I             = 4775,
  NV_WCDMA_800_HS_LNA_RANGE_FALL_I               = 4776,
  NV_WCDMA_800_HS_LNA_RANGE_FALL_3_I             = 4777,
  NV_WCDMA_800_HS_LNA_RANGE_FALL_4_I             = 4778,
  NV_WCDMA_800_HS_IM_LEVEL_3_I                   = 4779,
  NV_WCDMA_800_HS_IM_LEVEL_2_I                   = 4780,
  NV_WCDMA_800_HS_IM_LEVEL_I                     = 4781,
  NV_WCDMA_800_HS_IM_LEVEL_4_I                   = 4782,
  NV_WCDMA_HS_IM_LEVEL_2_I                       = 4783,
  NV_WCDMA_HS_IM_LEVEL_3_I                       = 4784,
  NV_WCDMA_HS_IM_LEVEL_4_I                       = 4785,
  NV_WCDMA_HS_IM_LEVEL_I                         = 4786,
  NV_WCDMA_HS_LNA_RANGE_FALL_4_I                 = 4787,
  NV_WCDMA_HS_LNA_RANGE_FALL_3_I                 = 4788,
  NV_WCDMA_HS_LNA_RANGE_FALL_2_I                 = 4789,
  NV_WCDMA_HS_LNA_RANGE_FALL_I                   = 4790,
  NV_WCDMA_HS_LNA_RANGE_RISE_4_I                 = 4791,
  NV_WCDMA_HS_LNA_RANGE_RISE_3_I                 = 4792,
  NV_WCDMA_HS_LNA_RANGE_RISE_2_I                 = 4793,
  NV_WCDMA_HS_LNA_RANGE_RISE_I                   = 4794,
  NV_BC0_TX_PDM_0_I                              = 4795,
  NV_BC0_TX_PDM_1_I                              = 4796,
  NV_BC0_TX_PDM_2_I                              = 4797,
  NV_BC0_TX_PDM_3_I                              = 4798,
  NV_BC1_TX_PDM_0_I                              = 4799,
  NV_BC1_TX_PDM_1_I                              = 4800,
  NV_BC1_TX_PDM_2_I                              = 4801,
  NV_BC1_TX_PDM_3_I                              = 4802,
  NV_BC3_TX_PDM_0_I                              = 4803,
  NV_BC3_TX_PDM_1_I                              = 4804,
  NV_BC3_TX_PDM_2_I                              = 4805,
  NV_BC3_TX_PDM_3_I                              = 4806,
  NV_BC4_TX_PDM_0_I                              = 4807,
  NV_BC4_TX_PDM_1_I                              = 4808,
  NV_BC4_TX_PDM_2_I                              = 4809,
  NV_BC4_TX_PDM_3_I                              = 4810,
  NV_BC5_TX_PDM_0_I                              = 4811,
  NV_BC5_TX_PDM_1_I                              = 4812,
  NV_BC5_TX_PDM_2_I                              = 4813,
  NV_BC5_TX_PDM_3_I                              = 4814,
  NV_BC6_TX_PDM_0_I                              = 4815,
  NV_BC6_TX_PDM_1_I                              = 4816,
  NV_BC6_TX_PDM_2_I                              = 4817,
  NV_BC6_TX_PDM_3_I                              = 4818,
  NV_BC11_TX_PDM_0_I                             = 4819,
  NV_BC11_TX_PDM_1_I                             = 4820,
  NV_BC11_TX_PDM_2_I                             = 4821,
  NV_BC11_TX_PDM_3_I                             = 4822,
  NV_BC14_TX_PDM_0_I                             = 4823,
  NV_BC14_TX_PDM_1_I                             = 4824,
  NV_BC14_TX_PDM_2_I                             = 4825,
  NV_BC14_TX_PDM_3_I                             = 4826,
  NV_BC15_TX_PDM_0_I                             = 4827,
  NV_BC15_TX_PDM_1_I                             = 4828,
  NV_BC15_TX_PDM_2_I                             = 4829,
  NV_BC15_TX_PDM_3_I                             = 4830,
  NV_BC0_TX_LIN_0_I                              = 4831,
  NV_BC0_TX_LIN_1_I                              = 4832,
  NV_BC0_TX_LIN_2_I                              = 4833,
  NV_BC0_TX_LIN_3_I                              = 4834,
  NV_BC1_TX_LIN_0_I                              = 4835,
  NV_BC1_TX_LIN_1_I                              = 4836,
  NV_BC1_TX_LIN_2_I                              = 4837,
  NV_BC1_TX_LIN_3_I                              = 4838,
  NV_BC3_TX_LIN_0_I                              = 4839,
  NV_BC3_TX_LIN_1_I                              = 4840,
  NV_BC3_TX_LIN_2_I                              = 4841,
  NV_BC3_TX_LIN_3_I                              = 4842,
  NV_BC4_TX_LIN_0_I                              = 4843,
  NV_BC4_TX_LIN_1_I                              = 4844,
  NV_BC4_TX_LIN_2_I                              = 4845,
  NV_BC4_TX_LIN_3_I                              = 4846,
  NV_BC5_TX_LIN_0_I                              = 4847,
  NV_BC5_TX_LIN_1_I                              = 4848,
  NV_BC5_TX_LIN_2_I                              = 4849,
  NV_BC5_TX_LIN_3_I                              = 4850,
  NV_BC6_TX_LIN_0_I                              = 4851,
  NV_BC6_TX_LIN_1_I                              = 4852,
  NV_BC6_TX_LIN_2_I                              = 4853,
  NV_BC6_TX_LIN_3_I                              = 4854,
  NV_BC11_TX_LIN_0_I                             = 4855,
  NV_BC11_TX_LIN_1_I                             = 4856,
  NV_BC11_TX_LIN_2_I                             = 4857,
  NV_BC11_TX_LIN_3_I                             = 4858,
  NV_BC14_TX_LIN_0_I                             = 4859,
  NV_BC14_TX_LIN_1_I                             = 4860,
  NV_BC14_TX_LIN_2_I                             = 4861,
  NV_BC14_TX_LIN_3_I                             = 4862,
  NV_BC15_TX_LIN_0_I                             = 4863,
  NV_BC15_TX_LIN_1_I                             = 4864,
  NV_BC15_TX_LIN_2_I                             = 4865,
  NV_BC15_TX_LIN_3_I                             = 4866,
  NV_HDR_RX_DIV_BC_ENABLE_MASK_I                 = 4867,
  NV_CDMA_RX_DIV_BC_ENABLE_MASK_I                = 4868,
  NV_GSM_CARRIER_SUPPRESSION_I                   = 4869,
  NV_GSM_850_CARRIER_SUPPRESSION_I               = 4870,
  NV_GSM_DCS_CARRIER_SUPPRESSION_I               = 4871,
  NV_GSM_1900_CARRIER_SUPPRESSION_I              = 4872,
  NV_DVBH_STORE_NW_INFO_TO_EFS_I                 = 4873,
  NV_DVBH_EFS_NW_INFO_EXPIRY_TIME_I              = 4874,
  NV_DVBH_NW_ACQ_ON_CELL_ID_MISMATCH_I           = 4875,
  NV_DVBH_WAIT_FOR_NIT_OTHER_I                   = 4876,
  NV_DVBH_ALL_NIT_ACQ_TIMEOUT_I                  = 4877,
  NV_DVBH_LNKG_ACQ_TIMEOUT_I                     = 4878,
  NV_DISPLAY_UPDATE_POWER_TEST_MODE_I            = 4879,
  NV_BC0_PA_R_MAP_I                              = 4880,
  NV_BC1_PA_R_MAP_I                              = 4881,
  NV_BC3_PA_R_MAP_I                              = 4882,
  NV_BC4_PA_R_MAP_I                              = 4883,
  NV_BC5_PA_R_MAP_I                              = 4884,
  NV_BC6_PA_R_MAP_I                              = 4885,
  NV_BC11_PA_R_MAP_I                             = 4886,
  NV_BC14_PA_R_MAP_I                             = 4887,
  NV_BC15_PA_R_MAP_I                             = 4888,
  NV_HDRSRCH_DBG_MSK_I                           = 4889,
  NV_AIMS_ON_I                                   = 4890,
  NV_MBP_RF_DVBH_CAL_FREQ_I                      = 4891,
  NV_MBP_RF_DVBH_GS0_CAL_I                       = 4892,
  NV_MBP_RF_DVBH_GS1_CAL_I                       = 4893,
  NV_MBP_RF_DVBH_GS2_CAL_I                       = 4894,
  NV_MBP_RF_DVBH_GS3_CAL_I                       = 4895,
  NV_MBP_RF_DVBH_GS4_CAL_I                       = 4896,
  NV_MBP_RF_DVBH_GS5_CAL_I                       = 4897,
  NV_MBP_RF_MFLO_CAL_FREQ_I                      = 4898,
  NV_MBP_RF_MFLO_GS0_CAL_I                       = 4899,
  NV_MBP_RF_MFLO_GS1_CAL_I                       = 4900,
  NV_MBP_RF_MFLO_GS2_CAL_I                       = 4901,
  NV_MBP_RF_MFLO_GS3_CAL_I                       = 4902,
  NV_MBP_RF_MFLO_GS4_CAL_I                       = 4903,
  NV_MBP_RF_MFLO_GS5_CAL_I                       = 4904,
  NV_QVP_APP_PSVT_ENABLE_FLAG_I                  = 4905,
  NV_CGPS_DGPS_CORRECTIONS_ALLOWED_I             = 4906,
  NV_CGPS_MAXIMUM_DGPS_INTERVAL_I                = 4907,
  NV_CGPS_USE_FDIC_I                             = 4908,
  NV_CGPS_ALTITUDE_HOLD_MODE_I                   = 4909,
  NV_CGPS_PDOP_MASK_I                            = 4910,
  NV_CGPS_2D_PDOP_MASK_I                         = 4911,
  NV_CGPS_REFERENCE_MODE_I                       = 4912,
  NV_CGPS_OPERATION_MODE_I                       = 4913,
  NV_CGPS_ELEVATION_MASK_I                       = 4914,
  NV_CGPS_MAX_ALMANAC_AGE_IN_WEEKS_I             = 4915,
  NV_CGPS_STEERING_ON_STARTUP_I                  = 4916,
  NV_ICMP6_ND_CONFIG_I                           = 4917,
  NV_HS_USB_REMOTE_WAKEUP_DELAY_I                = 4918,
  NV_DVBH_UHF_BAND_FREQ_RANGE_AND_OFFSET_1_I     = 4919,
  NV_DVBH_UHF_BAND_FREQ_RANGE_AND_OFFSET_2_I     = 4920,
  NV_DVBH_CELL_ID_RANGE_I                        = 4921,
  NV_JCDMA_RUIM_ID_I                             = 4922,
  NV_JCDMA_UIM_LOCK_I                            = 4923,
  NV_DIAG_FTM_MODE_SWITCH_I                      = 4924,
  NV_DHCP4_OPTIONS_MASK_I                        = 4925,
  NV_DHCP6_OPTIONS_MASK_I                        = 4926,
  NV_GPS1_XTRA_TIME_INFO_ENABLED_I               = 4927,
  NV_GPS1_XTRA_TIME_INFO_UNC_THRESH_I            = 4928,
  NV_GPS1_XTRA_TIME_INFO_DELAY_THRESH_I          = 4929,
  NV_GPS1_XTRA_PRIMARY_SNTP_SERVER_URL_I         = 4930,
  NV_GPS1_XTRA_SECONDARY_SNTP_SERVER_URL_I       = 4931,
  NV_GPS1_XTRA_TERTIARY_SNTP_SERVER_URL_I        = 4932,
  NV_MF_PROXY_I                                  = 4933,
  NV_MF_PROXY_LEN_I                              = 4934,
  NV_WCDMA_1900_C0_C1_DELAY_I                    = 4935,
  NV_WCDMA_1800_C0_C1_DELAY_I                    = 4936,
  NV_WCDMA_BC4_C0_C1_DELAY_I                     = 4937,
  NV_WCDMA_900_C0_C1_DELAY_I                     = 4938,
  NV_WCDMA_800_C0_C1_DELAY_I                     = 4939,
  NV_IMS_FW_API_ENABLE_FLAG_I                    = 4940,
  NV_WCDMA_REL6_TX_BETA_SCALING_COMP_I           = 4941,
  NV_WCDMA_REL6_TX_AGC_OFFSET_I                  = 4942,
  NV_WCDMA_REL6_TX_MPR_BACKOFF_I                 = 4943,
  NV_WCDMA_1900_REL6_TX_BETA_SCALING_COMP_I      = 4944,
  NV_WCDMA_1900_REL6_TX_AGC_OFFSET_I             = 4945,
  NV_WCDMA_1900_REL6_TX_MPR_BACKOFF_I            = 4946,
  NV_WCDMA_800_REL6_TX_BETA_SCALING_COMP_I       = 4947,
  NV_WCDMA_800_REL6_TX_AGC_OFFSET_I              = 4948,
  NV_WCDMA_800_REL6_TX_MPR_BACKOFF_I             = 4949,
  NV_WCDMA_BC4_REL6_TX_BETA_SCALING_COMP_I       = 4950,
  NV_WCDMA_BC4_REL6_TX_AGC_OFFSET_I              = 4951,
  NV_WCDMA_BC4_REL6_TX_MPR_BACKOFF_I             = 4952,
  NV_XO_FIELD_CALIBRATION_I                      = 4953,
  NV_XO_FACTORY_CALIBRATION_I                    = 4954,
  NV_XO_CAL_CONV_I                               = 4955,
  NV_WCDMA_LNA_PHASE_CTL_I                       = 4956,
  NV_C1_WCDMA_LNA_PHASE_CTL_I                    = 4957,
  NV_HOME_MCC_I                                  = 4958,
  NV_USR_SID_TO_MCC_ASSOC_TBL_I                  = 4959,
  NV_HS_BASED_PLUS_DIAL_SETTING_I                = 4960,
  NV_DS_AT_V250_REGISTERS_I                      = 4961,
  NV_DS_AT_S_REGISTERS_I                         = 4962,
  NV_PROCESS_RESTART_SWITCH_I                    = 4963,
  NV_HDRSCP_FORCE_AT_CONFIG_I                    = 4964,
  NV_WCDMA_TX_COMP_VS_FREQ_0_SECONDARY_I         = 4965,
  NV_WCDMA_TX_COMP_VS_FREQ_1_SECONDARY_I         = 4966,
  NV_WCDMA_TX_COMP_VS_FREQ_2_SECONDARY_I         = 4967,
  NV_WCDMA_TX_COMP_VS_FREQ_3_SECONDARY_I         = 4968,
  NV_WCDMA_TX_COMP_VS_FREQ_SEC_PDM_LIST_I        = 4969,
  NV_WCDMA_1900_TX_COMP_VS_FREQ_0_SECONDARY_I    = 4970,
  NV_WCDMA_1900_TX_COMP_VS_FREQ_1_SECONDARY_I    = 4971,
  NV_WCDMA_1900_TX_COMP_VS_FREQ_2_SECONDARY_I    = 4972,
  NV_WCDMA_1900_TX_COMP_VS_FREQ_3_SECONDARY_I    = 4973,
  NV_WCDMA_1900_TX_COMP_VS_FREQ_SEC_PDM_LIST_I   = 4974,
  NV_WCDMA_800_TX_COMP_VS_FREQ_0_SECONDARY_I     = 4975,
  NV_WCDMA_800_TX_COMP_VS_FREQ_1_SECONDARY_I     = 4976,
  NV_WCDMA_800_TX_COMP_VS_FREQ_2_SECONDARY_I     = 4977,
  NV_WCDMA_800_TX_COMP_VS_FREQ_3_SECONDARY_I     = 4978,
  NV_WCDMA_800_TX_COMP_VS_FREQ_SEC_PDM_LIST_I    = 4979,
  NV_WCDMA_1800_TX_COMP_VS_FREQ_0_SECONDARY_I    = 4980,
  NV_WCDMA_1800_TX_COMP_VS_FREQ_1_SECONDARY_I    = 4981,
  NV_WCDMA_1800_TX_COMP_VS_FREQ_2_SECONDARY_I    = 4982,
  NV_WCDMA_1800_TX_COMP_VS_FREQ_3_SECONDARY_I    = 4983,
  NV_WCDMA_1800_TX_COMP_VS_FREQ_SEC_PDM_LIST_I   = 4984,
  NV_WCDMA_BC4_TX_COMP_VS_FREQ_0_SECONDARY_I     = 4985,
  NV_WCDMA_BC4_TX_COMP_VS_FREQ_1_SECONDARY_I     = 4986,
  NV_WCDMA_BC4_TX_COMP_VS_FREQ_2_SECONDARY_I     = 4987,
  NV_WCDMA_BC4_TX_COMP_VS_FREQ_3_SECONDARY_I     = 4988,
  NV_WCDMA_BC4_TX_COMP_VS_FREQ_SEC_PDM_LIST_I    = 4989,
  NV_WCDMA_900_TX_COMP_VS_FREQ_0_SECONDARY_I     = 4990,
  NV_WCDMA_900_TX_COMP_VS_FREQ_1_SECONDARY_I     = 4991,
  NV_WCDMA_900_TX_COMP_VS_FREQ_2_SECONDARY_I     = 4992,
  NV_WCDMA_900_TX_COMP_VS_FREQ_3_SECONDARY_I     = 4993,
  NV_WCDMA_900_TX_COMP_VS_FREQ_SEC_PDM_LIST_I    = 4994,
  NV_CUST_UQCN_C2K_VERSION_I                     = 4995,
  NV_CUST_UQCN_UMTS_VERSION_I                    = 4996,
  NV_BC0_TX_PWR_COMP0_I                          = 4997,
  NV_BC0_TX_PWR_COMP1_I                          = 4998,
  NV_BC0_TX_PWR_COMP2_I                          = 4999,
  NV_BC0_TX_PWR_COMP3_I                          = 5000,
  NV_BC1_TX_PWR_COMP0_I                          = 5001,
  NV_BC1_TX_PWR_COMP1_I                          = 5002,
  NV_BC1_TX_PWR_COMP2_I                          = 5003,
  NV_BC1_TX_PWR_COMP3_I                          = 5004,
  NV_BC3_TX_PWR_COMP0_I                          = 5005,
  NV_BC3_TX_PWR_COMP1_I                          = 5006,
  NV_BC3_TX_PWR_COMP2_I                          = 5007,
  NV_BC3_TX_PWR_COMP3_I                          = 5008,
  NV_BC5_TX_PWR_COMP0_I                          = 5009,
  NV_BC5_TX_PWR_COMP1_I                          = 5010,
  NV_BC5_TX_PWR_COMP2_I                          = 5011,
  NV_BC5_TX_PWR_COMP3_I                          = 5012,
  NV_BC6_TX_PWR_COMP0_I                          = 5013,
  NV_BC6_TX_PWR_COMP1_I                          = 5014,
  NV_BC6_TX_PWR_COMP2_I                          = 5015,
  NV_BC6_TX_PWR_COMP3_I                          = 5016,
  NV_BC11_TX_PWR_COMP0_I                         = 5017,
  NV_BC11_TX_PWR_COMP1_I                         = 5018,
  NV_BC11_TX_PWR_COMP2_I                         = 5019,
  NV_BC11_TX_PWR_COMP3_I                         = 5020,
  NV_BC14_TX_PWR_COMP0_I                         = 5021,
  NV_BC14_TX_PWR_COMP1_I                         = 5022,
  NV_BC14_TX_PWR_COMP2_I                         = 5023,
  NV_BC14_TX_PWR_COMP3_I                         = 5024,
  NV_BC15_TX_PWR_COMP0_I                         = 5025,
  NV_BC15_TX_PWR_COMP1_I                         = 5026,
  NV_BC15_TX_PWR_COMP2_I                         = 5027,
  NV_BC15_TX_PWR_COMP3_I                         = 5028,
  NV_THERM_BINS_I                                = 5029,
  NV_BC4_TX_PWR_COMP0_I                          = 5030,
  NV_BC4_TX_PWR_COMP1_I                          = 5031,
  NV_BC4_TX_PWR_COMP2_I                          = 5032,
  NV_BC4_TX_PWR_COMP3_I                          = 5033,
  NV_CGPS_QOS_OVERRIDE_ACC_THRESHOLD_I           = 5034,
  NV_CGPS_QOS_OVERRIDE_TIME_I                    = 5035,
  NV_WEB_INFO_I                                  = 5036,
  NV_SIOTA_CALL_INFO_I                           = 5037,
  NV_PHONE_BOOT_NAIURL_I                         = 5038,
  NV_PHONE_BOOT_URL_I                            = 5039,
  NV_DS_PHONE_RDF_URL_I                          = 5040,
  NV_BROWSER_DOMAIN_TRUSTED_I                    = 5041,
  NV_IOTA_COMMIT_I                               = 5042,
  NV_DVBH_NIT_ACTUAL_ACQ_TIMEOUT_I               = 5043,
  NV_HS_USB_DIAG_ON_LEGACY_USB_PORT_I            = 5044,
  NV_HW_ENTROPY_I                                = 5045,
  NV_CGPS_MEM_CONFIG_I                           = 5046,
  NV_CGPS_NMEA_CONFIG_INFO_I                     = 5047,
  NV_WCDMA_800_TIMER_HYSTERISIS_I                = 5048,
  NV_WCDMA_900_TIMER_HYSTERISIS_I                = 5049,
  NV_WCDMA_BC4_TIMER_HYSTERISIS_I                = 5050,
  NV_WCDMA_1800_TIMER_HYSTERISIS_I               = 5051,
  NV_WCDMA_1900_TIMER_HYSTERISIS_I               = 5052,
  NV_WCDMA_2100_TIMER_HYSTERISIS_I               = 5053,
  NV_WCDMA_800_TX_LIN_MASTER_0_ENH_I             = 5054,
  NV_WCDMA_900_TX_LIN_MASTER_0_ENH_I             = 5055,
  NV_WCDMA_BC4_TX_LIN_MASTER_0_ENH_I             = 5056,
  NV_WCDMA_1800_TX_LIN_MASTER_0_ENH_I            = 5057,
  NV_WCDMA_1900_TX_LIN_MASTER_0_ENH_I            = 5058,
  NV_WCDMA_2100_TX_LIN_MASTER_0_ENH_I            = 5059,
  NV_WCDMA_800_TX_PDM_LIN_0_ENH_I                = 5060,
  NV_WCDMA_900_TX_PDM_LIN_0_ENH_I                = 5061,
  NV_WCDMA_BC4_TX_PDM_LIN_0_ENH_I                = 5062,
  NV_WCDMA_1800_TX_PDM_LIN_0_ENH_I               = 5063,
  NV_WCDMA_1900_TX_PDM_LIN_0_ENH_I               = 5064,
  NV_WCDMA_2100_TX_PDM_LIN_0_ENH_I               = 5065,
  NV_GSM_850_KV_CAL_I                            = 5066,
  NV_GSM_900_KV_CAL_I                            = 5067,
  NV_GSM_1800_KV_CAL_I                           = 5068,
  NV_GSM_1900_KV_CAL_I                           = 5069,
  NV_BC1_BALUN_CTL_I                             = 5070,
  NV_BC2_BALUN_CTL_I                             = 5071,
  NV_BC3_BALUN_CTL_I                             = 5072,
  NV_BC4_BALUN_CTL_I                             = 5073,
  NV_BC6_BALUN_CTL_I                             = 5074,
  NV_BC8_BALUN_CTL_I                             = 5075,
  NV_BC9_BALUN_CTL_I                             = 5076,
  NV_UNDP_HSU_VID_PID_I                          = 5077,
  NV_UNDP_HSU_MFGSTR_I                           = 5078,
  NV_UNDP_HSU_PRODSTR_I                          = 5079,
  NV_RR_ACQ_DB_CHUNK_00_I                        = 5080,
  NV_RR_ACQ_DB_CHUNK_01_I                        = 5081,
  NV_RR_ACQ_DB_CHUNK_02_I                        = 5082,
  NV_RR_ACQ_DB_CHUNK_03_I                        = 5083,
  NV_RR_ACQ_DB_CHUNK_04_I                        = 5084,
  NV_RR_ACQ_DB_CHUNK_05_I                        = 5085,
  NV_RR_ACQ_DB_CHUNK_06_I                        = 5086,
  NV_RR_ACQ_DB_CHUNK_07_I                        = 5087,
  NV_NITZ_NW_INFO_MCC_I                          = 5088,
  NV_NITZ_NW_INFO_MNC_I                          = 5089,
  NV_WCDMA_HSUPA_CM_CTRL_I                       = 5090,
  NV_GSM_850_SMPS_PDM_TBL_I                      = 5091,
  NV_GSM_900_SMPS_PDM_TBL_I                      = 5092,
  NV_GSM_1800_SMPS_PDM_TBL_I                     = 5093,
  NV_GSM_1900_SMPS_PDM_TBL_I                     = 5094,
  NV_WCDMA_1900_LNA_PHASE_CTL_I                  = 5095,
  NV_C1_WCDMA_1900_LNA_PHASE_CTL_I               = 5096,
  NV_WCDMA_800_LNA_PHASE_CTL_I                   = 5097,
  NV_C1_WCDMA_800_LNA_PHASE_CTL_I                = 5098,
  NV_WCDMA_BC4_LNA_PHASE_CTL_I                   = 5099,
  NV_C1_WCDMA_BC4_LNA_PHASE_CTL_I                = 5100,
  NV_WCDMA_900_LNA_PHASE_CTL_I                   = 5101,
  NV_C1_WCDMA_900_LNA_PHASE_CTL_I                = 5102,
  NV_WCDMA_1800_LNA_PHASE_CTL_I                  = 5103,
  NV_C1_WCDMA_1800_LNA_PHASE_CTL_I               = 5104,
  NV_DIAG_DIAGBUF_TX_SLEEP_TIME_NV_I             = 5105,
  NV_DIAG_DIAGBUF_TX_SLEEP_THRESHOLD_NV_I        = 5106,
  NV_REPEATED_ACCH_I                             = 5107,
  NV_BC0_P2_RISE_FALL_OFF_I                      = 5108,
  NV_BC1_P2_RISE_FALL_OFF_I                      = 5109,
  NV_BC3_P2_RISE_FALL_OFF_I                      = 5110,
  NV_BC4_P2_RISE_FALL_OFF_I                      = 5111,
  NV_BC5_P2_RISE_FALL_OFF_I                      = 5112,
  NV_BC6_P2_RISE_FALL_OFF_I                      = 5113,
  NV_BC11_P2_RISE_FALL_OFF_I                     = 5114,
  NV_BC14_P2_RISE_FALL_OFF_I                     = 5115,
  NV_BC15_P2_RISE_FALL_OFF_I                     = 5116,
  NV_BCX_BLOCK_P2_RISE_FALL_OFF_I                = 5117,
  NV_BC0_P3_RISE_FALL_OFF_I                      = 5118,
  NV_BC1_P3_RISE_FALL_OFF_I                      = 5119,
  NV_BC3_P3_RISE_FALL_OFF_I                      = 5120,
  NV_BC4_P3_RISE_FALL_OFF_I                      = 5121,
  NV_BC5_P3_RISE_FALL_OFF_I                      = 5122,
  NV_BC6_P3_RISE_FALL_OFF_I                      = 5123,
  NV_BC11_P3_RISE_FALL_OFF_I                     = 5124,
  NV_BC14_P3_RISE_FALL_OFF_I                     = 5125,
  NV_BC15_P3_RISE_FALL_OFF_I                     = 5126,
  NV_BCX_BLOCK_P3_RISE_FALL_OFF_I                = 5127,
  NV_BC0_HDR_P2_RISE_FALL_OFF_I                  = 5128,
  NV_BC1_HDR_P2_RISE_FALL_OFF_I                  = 5129,
  NV_BC3_HDR_P2_RISE_FALL_OFF_I                  = 5130,
  NV_BC4_HDR_P2_RISE_FALL_OFF_I                  = 5131,
  NV_BC5_HDR_P2_RISE_FALL_OFF_I                  = 5132,
  NV_BC6_HDR_P2_RISE_FALL_OFF_I                  = 5133,
  NV_BC11_HDR_P2_RISE_FALL_OFF_I                 = 5134,
  NV_BC14_HDR_P2_RISE_FALL_OFF_I                 = 5135,
  NV_BC15_HDR_P2_RISE_FALL_OFF_I                 = 5136,
  NV_BCX_BLOCK_HDR_P2_RISE_FALL_OFF_I            = 5137,
  NV_BC0_HDR_P3_RISE_FALL_OFF_I                  = 5138,
  NV_BC1_HDR_P3_RISE_FALL_OFF_I                  = 5139,
  NV_BC3_HDR_P3_RISE_FALL_OFF_I                  = 5140,
  NV_BC4_HDR_P3_RISE_FALL_OFF_I                  = 5141,
  NV_BC5_HDR_P3_RISE_FALL_OFF_I                  = 5142,
  NV_BC6_HDR_P3_RISE_FALL_OFF_I                  = 5143,
  NV_BC11_HDR_P3_RISE_FALL_OFF_I                 = 5144,
  NV_BC14_HDR_P3_RISE_FALL_OFF_I                 = 5145,
  NV_BC15_HDR_P3_RISE_FALL_OFF_I                 = 5146,
  NV_BCX_BLOCK_HDR_P3_RISE_FALL_OFF_I            = 5147,
  NV_BT_TX_RFCAL_I                               = 5148,
  NV_BT_LISBON_DISABLED_I                        = 5149,
  NV_DS_AT_CSAS_CSCA_SETTINGS_I                  = 5150,
  NV_DS_AT_CSAS_CSMP_SETTINGS_I                  = 5151,
  NV_DS_AT_CSAS_CSCB_SETTINGS_I                  = 5152,
  NV_UE_IMEISV_SVN_I                             = 5153,
  NV_GPS_ENGINE_TYPE_I                           = 5154,
  NV_UNDP_HSU_VID_PID2_I                         = 5155,
  NV_UNDP_NOTEBOOK_INFO_I                        = 5156,
  NV_DVBH_DO_FREQ_SCAN_AFTER_SYS_LOST_I          = 5157,
  NV_DVBH_BAT_ACQ_TIMEOUT_I                      = 5158,
  NV_DVBH_USE_NW_IDS_FOR_COMPLETE_NW_ACQ_I       = 5159,
  NV_DVBH_INACTIVITY_TIMEOUT_I                   = 5160,
  NV_DVBH_GET_PLATFORM_LIST_FROM_FIRST_NIT_I     = 5161,
  NV_DVBH_UPDATE_NW_INFO_FROM_TS_I               = 5162,
  NV_BC10_TX_LIN_MASTER0_I                       = 5163,
  NV_BC10_TX_LIN_MASTER1_I                       = 5164,
  NV_BC10_TX_LIN_MASTER2_I                       = 5165,
  NV_BC10_TX_LIN_MASTER3_I                       = 5166,
  NV_BC10_GPS1_RF_DELAY_I                        = 5167,
  NV_BC10_TX_LIM_VS_TEMP_I                       = 5168,
  NV_BC10_TX_COMP0_I                             = 5169,
  NV_BC10_TX_COMP1_I                             = 5170,
  NV_BC10_TX_COMP2_I                             = 5171,
  NV_BC10_TX_COMP3_I                             = 5172,
  NV_BC10_TX_LIM_VS_FREQ_I                       = 5173,
  NV_BC10_PA_R1_RISE_I                           = 5174,
  NV_BC10_PA_R1_FALL_I                           = 5175,
  NV_BC10_PA_R2_RISE_I                           = 5176,
  NV_BC10_PA_R2_FALL_I                           = 5177,
  NV_BC10_PA_R3_RISE_I                           = 5178,
  NV_BC10_PA_R3_FALL_I                           = 5179,
  NV_BC10_HDET_OFF_I                             = 5180,
  NV_BC10_HDET_SPN_I                             = 5181,
  NV_BC10_EXP_HDET_VS_AGC_I                      = 5182,
  NV_BC10_ENC_BTF_I                              = 5183,
  NV_BC10_VCO_COARSE_TUNE_TABLE_I                = 5184,
  NV_BC10_VCO_TUNE_2_I                           = 5185,
  NV_BC10_P1_RISE_FALL_OFF_I                     = 5186,
  NV_BC10_HDR_P1_RISE_FALL_OFF_I                 = 5187,
  NV_BC10_ANT_QUALITY_I                          = 5188,
  NV_BC10_PA_DVS_VOLTAGE_I                       = 5189,
  NV_BC10_TX_PDM_LIN_0_I                         = 5190,
  NV_BC10_TX_PDM_LIN_1_I                         = 5191,
  NV_BC10_TX_PDM_LIN_2_I                         = 5192,
  NV_BC10_TX_PDM_LIN_3_I                         = 5193,
  NV_BC10_TX_PDM_0_I                             = 5194,
  NV_BC10_TX_PDM_1_I                             = 5195,
  NV_BC10_TX_PDM_2_I                             = 5196,
  NV_BC10_TX_PDM_3_I                             = 5197,
  NV_BC10_TX_LIN_0_I                             = 5198,
  NV_BC10_TX_LIN_1_I                             = 5199,
  NV_BC10_TX_LIN_2_I                             = 5200,
  NV_BC10_TX_LIN_3_I                             = 5201,
  NV_BC10_PA_R_MAP_I                             = 5202,
  NV_BC10_TX_PWR_COMP0_I                         = 5203,
  NV_BC10_TX_PWR_COMP1_I                         = 5204,
  NV_BC10_TX_PWR_COMP2_I                         = 5205,
  NV_BC10_TX_PWR_COMP3_I                         = 5206,
  NV_C0_BC10_TX_CAL_CHAN_I                       = 5207,
  NV_C0_BC10_RX_CAL_CHAN_I                       = 5208,
  NV_C0_BC10_RX_CAL_CHAN_LRU_I                   = 5209,
  NV_C0_BC10_LNA_1_OFFSET_I                      = 5210,
  NV_C0_BC10_LNA_2_OFFSET_I                      = 5211,
  NV_C0_BC10_LNA_3_OFFSET_I                      = 5212,
  NV_C0_BC10_LNA_4_OFFSET_I                      = 5213,
  NV_C0_BC10_LNA_1_OFFSET_VS_FREQ_I              = 5214,
  NV_C0_BC10_LNA_2_OFFSET_VS_FREQ_I              = 5215,
  NV_C0_BC10_LNA_3_OFFSET_VS_FREQ_I              = 5216,
  NV_C0_BC10_LNA_4_OFFSET_VS_FREQ_I              = 5217,
  NV_C0_BC10_IM2_I_VALUE_I                       = 5218,
  NV_C0_BC10_IM2_Q_VALUE_I                       = 5219,
  NV_C0_BC10_VGA_GAIN_OFFSET_I                   = 5220,
  NV_C0_BC10_VGA_GAIN_OFFSET_VS_FREQ_I           = 5221,
  NV_C0_BC10_IM2_TRANSCONDUCTOR_VALUE_I          = 5222,
  NV_C0_BC10_LNA_1_RISE_I                        = 5223,
  NV_C0_BC10_LNA_1_FALL_I                        = 5224,
  NV_C0_BC10_LNA_2_RISE_I                        = 5225,
  NV_C0_BC10_LNA_2_FALL_I                        = 5226,
  NV_C0_BC10_LNA_3_RISE_I                        = 5227,
  NV_C0_BC10_LNA_3_FALL_I                        = 5228,
  NV_C0_BC10_LNA_4_RISE_I                        = 5229,
  NV_C0_BC10_LNA_4_FALL_I                        = 5230,
  NV_C0_BC10_IM_LEVEL1_I                         = 5231,
  NV_C0_BC10_IM_LEVEL2_I                         = 5232,
  NV_C0_BC10_IM_LEVEL3_I                         = 5233,
  NV_C0_BC10_IM_LEVEL4_I                         = 5234,
  NV_C0_BC10_LNA_SWITCHPOINTS_LPM_1_I            = 5235,
  NV_C0_BC10_LNA_SWITCHPOINTS_LPM_2_I            = 5236,
  NV_C0_BC10_IM2_LPM_1_I                         = 5237,
  NV_C0_BC10_IM2_LPM_2_I                         = 5238,
  NV_C0_BC10_INTELLICEIVER_CAL_I                 = 5239,
  NV_C0_BC10_INTELLICEIVER_DET_THRESH_I          = 5240,
  NV_C1_BC10_TX_CAL_CHAN_I                       = 5241,
  NV_C1_BC10_RX_CAL_CHAN_I                       = 5242,
  NV_C1_BC10_RX_CAL_CHAN_LRU_I                   = 5243,
  NV_C1_BC10_LNA_1_OFFSET_VS_FREQ_I              = 5244,
  NV_C1_BC10_LNA_2_OFFSET_VS_FREQ_I              = 5245,
  NV_C1_BC10_LNA_3_OFFSET_VS_FREQ_I              = 5246,
  NV_C1_BC10_LNA_4_OFFSET_VS_FREQ_I              = 5247,
  NV_C1_BC10_LNA_1_OFFSET_I                      = 5248,
  NV_C1_BC10_LNA_2_OFFSET_I                      = 5249,
  NV_C1_BC10_LNA_3_OFFSET_I                      = 5250,
  NV_C1_BC10_LNA_4_OFFSET_I                      = 5251,
  NV_C1_BC10_IM2_I_VALUE_I                       = 5252,
  NV_C1_BC10_IM2_Q_VALUE_I                       = 5253,
  NV_C1_BC10_VGA_GAIN_OFFSET_I                   = 5254,
  NV_C1_BC10_VGA_GAIN_OFFSET_VS_FREQ_I           = 5255,
  NV_C1_BC10_IM2_TRANSCONDUCTOR_VALUE_I          = 5256,
  NV_C1_BC10_LNA_1_RISE_I                        = 5257,
  NV_C1_BC10_LNA_1_FALL_I                        = 5258,
  NV_C1_BC10_LNA_2_RISE_I                        = 5259,
  NV_C1_BC10_LNA_2_FALL_I                        = 5260,
  NV_C1_BC10_LNA_3_RISE_I                        = 5261,
  NV_C1_BC10_LNA_3_FALL_I                        = 5262,
  NV_C1_BC10_LNA_4_RISE_I                        = 5263,
  NV_C1_BC10_LNA_4_FALL_I                        = 5264,
  NV_C1_BC10_IM_LEVEL1_I                         = 5265,
  NV_C1_BC10_IM_LEVEL2_I                         = 5266,
  NV_C1_BC10_IM_LEVEL3_I                         = 5267,
  NV_C1_BC10_IM_LEVEL4_I                         = 5268,
  NV_C1_BC10_VCO_COARSE_TUNE_TABLE_I             = 5269,
  NV_GSM_850_KV_CAL_CHAN_I                       = 5270,
  NV_GSM_900_KV_CAL_CHAN_I                       = 5271,
  NV_GSM_1800_KV_CAL_CHAN_I                      = 5272,
  NV_GSM_1900_KV_CAL_CHAN_I                      = 5273,
  NV_WCDMA_900_REL6_TX_BETA_SCALING_COMP_I       = 5274,
  NV_WCDMA_900_REL6_TX_AGC_OFFSET_I              = 5275,
  NV_WCDMA_900_REL6_TX_MPR_BACKOFF_I             = 5276,
  NV_WCDMA_1800_REL6_TX_BETA_SCALING_COMP_I      = 5277,
  NV_WCDMA_1800_REL6_TX_AGC_OFFSET_I             = 5278,
  NV_WCDMA_1800_REL6_TX_MPR_BACKOFF_I            = 5279,
  NV_DISABLE_CM_CALL_TYPE_I                      = 5280,
  NV_MULTI_SEC_CODE_I                            = 5281,
  NV_MULTI_OTKSL_I                               = 5282,
  NV_MULTI_OTKSL_FLAG_I                          = 5283,
  NV_DVBH_DO_FREQ_SCAN_AFTER_INT_ACQ_I           = 5284,
  NV_GSM_850_PADAC_DC_OFFSET_TBL_I               = 5285,
  NV_GSM_900_PADAC_DC_OFFSET_TBL_I               = 5286,
  NV_GSM_1800_PADAC_DC_OFFSET_TBL_I              = 5287,
  NV_GSM_1900_PADAC_DC_OFFSET_TBL_I              = 5288,
  NV_CGPS_VCO_AGE_I                              = 5289,
  NV_CGPS_OPTIMISTIC_PUNC_I                      = 5290,
  NV_GSM_850_RGI_G0_F1_I                         = 5291,
  NV_GSM_850_RGI_G1_F1_I                         = 5292,
  NV_GSM_850_RGI_G2_F1_I                         = 5293,
  NV_GSM_850_RGI_G3_F1_I                         = 5294,
  NV_GSM_850_RGI_G0_F2_I                         = 5295,
  NV_GSM_850_RGI_G1_F2_I                         = 5296,
  NV_GSM_850_RGI_G2_F2_I                         = 5297,
  NV_GSM_850_RGI_G3_F2_I                         = 5298,
  NV_GSM_900_RGI_G0_F1_I                         = 5299,
  NV_GSM_900_RGI_G1_F1_I                         = 5300,
  NV_GSM_900_RGI_G2_F1_I                         = 5301,
  NV_GSM_900_RGI_G3_F1_I                         = 5302,
  NV_GSM_900_RGI_G0_F2_I                         = 5303,
  NV_GSM_900_RGI_G1_F2_I                         = 5304,
  NV_GSM_900_RGI_G2_F2_I                         = 5305,
  NV_GSM_900_RGI_G3_F2_I                         = 5306,
  NV_GSM_1800_RGI_G0_F1_I                        = 5307,
  NV_GSM_1800_RGI_G1_F1_I                        = 5308,
  NV_GSM_1800_RGI_G2_F1_I                        = 5309,
  NV_GSM_1800_RGI_G3_F1_I                        = 5310,
  NV_GSM_1800_RGI_G0_F2_I                        = 5311,
  NV_GSM_1800_RGI_G1_F2_I                        = 5312,
  NV_GSM_1800_RGI_G2_F2_I                        = 5313,
  NV_GSM_1800_RGI_G3_F2_I                        = 5314,
  NV_GSM_1900_RGI_G0_F1_I                        = 5315,
  NV_GSM_1900_RGI_G1_F1_I                        = 5316,
  NV_GSM_1900_RGI_G2_F1_I                        = 5317,
  NV_GSM_1900_RGI_G3_F1_I                        = 5318,
  NV_GSM_1900_RGI_G0_F2_I                        = 5319,
  NV_GSM_1900_RGI_G1_F2_I                        = 5320,
  NV_GSM_1900_RGI_G2_F2_I                        = 5321,
  NV_GSM_1900_RGI_G3_F2_I                        = 5322,
  NV_GSM_850_PMEAS_G0_F1_I                       = 5323,
  NV_GSM_850_PMEAS_G1_F1_I                       = 5324,
  NV_GSM_850_PMEAS_G2_F1_I                       = 5325,
  NV_GSM_850_PMEAS_G3_F1_I                       = 5326,
  NV_GSM_850_PMEAS_G0_F2_I                       = 5327,
  NV_GSM_850_PMEAS_G1_F2_I                       = 5328,
  NV_GSM_850_PMEAS_G2_F2_I                       = 5329,
  NV_GSM_850_PMEAS_G3_F2_I                       = 5330,
  NV_GSM_900_PMEAS_G0_F1_I                       = 5331,
  NV_GSM_900_PMEAS_G1_F1_I                       = 5332,
  NV_GSM_900_PMEAS_G2_F1_I                       = 5333,
  NV_GSM_900_PMEAS_G3_F1_I                       = 5334,
  NV_GSM_900_PMEAS_G0_F2_I                       = 5335,
  NV_GSM_900_PMEAS_G1_F2_I                       = 5336,
  NV_GSM_900_PMEAS_G2_F2_I                       = 5337,
  NV_GSM_900_PMEAS_G3_F2_I                       = 5338,
  NV_GSM_1800_PMEAS_G0_F1_I                      = 5339,
  NV_GSM_1800_PMEAS_G1_F1_I                      = 5340,
  NV_GSM_1800_PMEAS_G2_F1_I                      = 5341,
  NV_GSM_1800_PMEAS_G3_F1_I                      = 5342,
  NV_GSM_1800_PMEAS_G0_F2_I                      = 5343,
  NV_GSM_1800_PMEAS_G1_F2_I                      = 5344,
  NV_GSM_1800_PMEAS_G2_F2_I                      = 5345,
  NV_GSM_1800_PMEAS_G3_F2_I                      = 5346,
  NV_GSM_1900_PMEAS_G0_F1_I                      = 5347,
  NV_GSM_1900_PMEAS_G1_F1_I                      = 5348,
  NV_GSM_1900_PMEAS_G2_F1_I                      = 5349,
  NV_GSM_1900_PMEAS_G3_F1_I                      = 5350,
  NV_GSM_1900_PMEAS_G0_F2_I                      = 5351,
  NV_GSM_1900_PMEAS_G1_F2_I                      = 5352,
  NV_GSM_1900_PMEAS_G2_F2_I                      = 5353,
  NV_GSM_1900_PMEAS_G3_F2_I                      = 5354,
  NV_GSM_1800_PA_R1_TO_R2_I                      = 5355,
  NV_GSM_1800_PA_R2_TO_R4_I                      = 5356,
  NV_GSM_1900_PA_R1_TO_R2_I                      = 5357,
  NV_GSM_1900_PA_R2_TO_R4_I                      = 5358,
  NV_GSM_850_PA_R1_TO_R2_I                       = 5359,
  NV_GSM_850_PA_R2_TO_R3_I                       = 5360,
  NV_GSM_850_PA_R3_TO_R4_I                       = 5361,
  NV_GSM_900_PA_R1_TO_R2_I                       = 5362,
  NV_GSM_900_PA_R2_TO_R3_I                       = 5363,
  NV_GSM_900_PA_R3_TO_R4_I                       = 5364,
  NV_GSM_850_PA_PREDIST_SWPT1_I                  = 5365,
  NV_GSM_850_PA_PREDIST_SWPT2_I                  = 5366,
  NV_GSM_900_PA_PREDIST_SWPT1_I                  = 5367,
  NV_GSM_900_PA_PREDIST_SWPT2_I                  = 5368,
  NV_GSM_1800_PA_PREDIST_SWPT1_I                 = 5369,
  NV_GSM_1800_PA_PREDIST_SWPT2_I                 = 5370,
  NV_GSM_1900_PA_PREDIST_SWPT1_I                 = 5371,
  NV_GSM_1900_PA_PREDIST_SWPT2_I                 = 5372,
  NV_HSUPA_IRQ_FLOW_CTRL_2MS_PDU_SIZE_336_I      = 5373,
  NV_HSUPA_IRQ_FLOW_CTRL_2MS_PDU_SIZE_656_I      = 5374,
  NV_BC10_P2_RISE_FALL_OFF_I                     = 5375,
  NV_BC10_P3_RISE_FALL_OFF_I                     = 5376,
  NV_BC10_HDR_P2_RISE_FALL_OFF_I                 = 5377,
  NV_BC10_HDR_P3_RISE_FALL_OFF_I                 = 5378,
  NV_PSHO_FEATURE_SUPPORT_I                      = 5379,
  NV_GSM_850_KV_VS_TEMP_I                        = 5380,
  NV_GSM_900_KV_VS_TEMP_I                        = 5381,
  NV_GSM_1800_KV_VS_TEMP_I                       = 5382,
  NV_GSM_1900_KV_VS_TEMP_I                       = 5383,
  NV_GSM_900_EDGE_PA_ULTRA_LO_TO_LO_I            = 5384,
  NV_GSM_900_EDGE_PA_LO_TO_MID_I                 = 5385,
  NV_GSM_900_EDGE_PA_MID_TO_HI_I                 = 5386,
  NV_GSM_850_EDGE_PA_ULTRA_LO_TO_LO_I            = 5387,
  NV_GSM_850_EDGE_PA_LO_TO_MID_I                 = 5388,
  NV_GSM_850_EDGE_PA_MID_TO_HI_I                 = 5389,
  NV_GSM_1800_EDGE_PA_LO_TO_MID_I                = 5390,
  NV_GSM_1800_EDGE_PA_MID_TO_HI_I                = 5391,
  NV_GSM_1900_EDGE_PA_LO_TO_MID_I                = 5392,
  NV_GSM_1900_EDGE_PA_MID_TO_HI_I                = 5393,
  NV_UNDP_NOEM_TEST_I                            = 5394,
  NV_GSM_850_LINEAR_PA_TEMP_COMP_I               = 5395,
  NV_GSM_900_LINEAR_PA_TEMP_COMP_I               = 5396,
  NV_GSM_1800_LINEAR_PA_TEMP_COMP_I              = 5397,
  NV_GSM_1900_LINEAR_PA_TEMP_COMP_I              = 5398,
  NV_GSM_850_RGI_G0_F3_I                         = 5399,
  NV_GSM_850_RGI_G1_F3_I                         = 5400,
  NV_GSM_850_RGI_G2_F3_I                         = 5401,
  NV_GSM_850_RGI_G3_F3_I                         = 5402,
  NV_GSM_900_RGI_G0_F3_I                         = 5403,
  NV_GSM_900_RGI_G1_F3_I                         = 5404,
  NV_GSM_900_RGI_G2_F3_I                         = 5405,
  NV_GSM_900_RGI_G3_F3_I                         = 5406,
  NV_GSM_1800_RGI_G0_F3_I                        = 5407,
  NV_GSM_1800_RGI_G1_F3_I                        = 5408,
  NV_GSM_1800_RGI_G2_F3_I                        = 5409,
  NV_GSM_1800_RGI_G3_F3_I                        = 5410,
  NV_GSM_1900_RGI_G0_F3_I                        = 5411,
  NV_GSM_1900_RGI_G1_F3_I                        = 5412,
  NV_GSM_1900_RGI_G2_F3_I                        = 5413,
  NV_GSM_1900_RGI_G3_F3_I                        = 5414,
  NV_GSM_850_PMEAS_G0_F3_I                       = 5415,
  NV_GSM_850_PMEAS_G1_F3_I                       = 5416,
  NV_GSM_850_PMEAS_G2_F3_I                       = 5417,
  NV_GSM_850_PMEAS_G3_F3_I                       = 5418,
  NV_GSM_900_PMEAS_G0_F3_I                       = 5419,
  NV_GSM_900_PMEAS_G1_F3_I                       = 5420,
  NV_GSM_900_PMEAS_G2_F3_I                       = 5421,
  NV_GSM_900_PMEAS_G3_F3_I                       = 5422,
  NV_GSM_1800_PMEAS_G0_F3_I                      = 5423,
  NV_GSM_1800_PMEAS_G1_F3_I                      = 5424,
  NV_GSM_1800_PMEAS_G2_F3_I                      = 5425,
  NV_GSM_1800_PMEAS_G3_F3_I                      = 5426,
  NV_GSM_1900_PMEAS_G0_F3_I                      = 5427,
  NV_GSM_1900_PMEAS_G1_F3_I                      = 5428,
  NV_GSM_1900_PMEAS_G2_F3_I                      = 5429,
  NV_GSM_1900_PMEAS_G3_F3_I                      = 5430,
  NV_MF_IPDC_SUPERCEDES_CLIPCAST_I               = 5431,
  NV_PROCESS_CAL_I                               = 5432,
  NV_C0_BC0_LO_CAL_I                             = 5433,
  NV_C0_BC1_LO_CAL_I                             = 5434,
  NV_C0_BC2_LO_CAL_I                             = 5435,
  NV_C0_BC3_LO_CAL_I                             = 5436,
  NV_C0_BC4_LO_CAL_I                             = 5437,
  NV_C0_BC5_LO_CAL_I                             = 5438,
  NV_C0_BC6_LO_CAL_I                             = 5439,
  NV_C0_BC7_LO_CAL_I                             = 5440,
  NV_C0_BC8_LO_CAL_I                             = 5441,
  NV_C0_BC9_LO_CAL_I                             = 5442,
  NV_C0_BC10_LO_CAL_I                            = 5443,
  NV_C0_BC11_LO_CAL_I                            = 5444,
  NV_C0_BC12_LO_CAL_I                            = 5445,
  NV_C0_BC13_LO_CAL_I                            = 5446,
  NV_C0_BC14_LO_CAL_I                            = 5447,
  NV_C0_BC15_LO_CAL_I                            = 5448,
  NV_DC_CAL_I                                    = 5449,
  NV_MF_BAND_CLASS_SP_INFO_I                     = 5450,
  NV_DS_SIP_PROFILE_I                            = 5451,
  NV_DS_SIP_ACTIVE_PROFILE_INDEX_I               = 5452,
  NV_DS_SIP_NUM_VALID_PROFILES_I                 = 5453,
  NV_DS_SIP_NAI_INFO_I                           = 5454,
  NV_DS_SIP_PPP_SS_INFO_I                        = 5455,
  NV_DIAG_DIAGBUF_TX_SLEEP_THRESHOLD_EXT_I       = 5456,
  NV_WCDMA_CLTD_FBI_BER_THRESH_I                 = 5457,
  NV_WCDMA_TEST_NV_1_I                           = 5458,
  NV_WCDMA_2100_EXP_HDET_VS_AGC_V2_I             = 5459,
  NV_WCDMA_1900_EXP_HDET_VS_AGC_V2_I             = 5460,
  NV_WCDMA_800_EXP_HDET_VS_AGC_V2_I              = 5461,
  NV_WCDMA_BC4_EXP_HDET_VS_AGC_V2_I              = 5462,
  NV_WCDMA_1800_EXP_HDET_VS_AGC_V2_I             = 5463,
  NV_WCDMA_900_EXP_HDET_VS_AGC_V2_I              = 5464,
  NV_WCDMA_2100_HDET_OFF_V2_I                    = 5465,
  NV_WCDMA_1900_HDET_OFF_V2_I                    = 5466,
  NV_WCDMA_800_HDET_OFF_V2_I                     = 5467,
  NV_WCDMA_BC4_HDET_OFF_V2_I                     = 5468,
  NV_WCDMA_1800_HDET_OFF_V2_I                    = 5469,
  NV_WCDMA_900_HDET_OFF_V2_I                     = 5470,
  NV_WCDMA_2100_HDET_SPN_V2_I                    = 5471,
  NV_WCDMA_1900_HDET_SPN_V2_I                    = 5472,
  NV_WCDMA_800_HDET_SPN_V2_I                     = 5473,
  NV_WCDMA_BC4_HDET_SPN_V2_I                     = 5474,
  NV_WCDMA_1800_HDET_SPN_V2_I                    = 5475,
  NV_WCDMA_900_HDET_SPN_V2_I                     = 5476,
  NV_GSM_LINEAR_TX_GAIN_PARAM_I                  = 5477,
  NV_EDGE_LINEAR_TX_GAIN_PARAM_I                 = 5478,
  NV_ENH_THERM_I                                 = 5479,
  NV_EDGE_850_RGI_G0_F1_I                        = 5480,
  NV_EDGE_850_RGI_G1_F1_I                        = 5481,
  NV_EDGE_850_RGI_G2_F1_I                        = 5482,
  NV_EDGE_850_RGI_G3_F1_I                        = 5483,
  NV_EDGE_850_RGI_G0_F2_I                        = 5484,
  NV_EDGE_850_RGI_G1_F2_I                        = 5485,
  NV_EDGE_850_RGI_G2_F2_I                        = 5486,
  NV_EDGE_850_RGI_G3_F2_I                        = 5487,
  NV_EDGE_850_RGI_G0_F3_I                        = 5488,
  NV_EDGE_850_RGI_G1_F3_I                        = 5489,
  NV_EDGE_850_RGI_G2_F3_I                        = 5490,
  NV_EDGE_850_RGI_G3_F3_I                        = 5491,
  NV_EDGE_900_RGI_G0_F1_I                        = 5492,
  NV_EDGE_900_RGI_G1_F1_I                        = 5493,
  NV_EDGE_900_RGI_G2_F1_I                        = 5494,
  NV_EDGE_900_RGI_G3_F1_I                        = 5495,
  NV_EDGE_900_RGI_G0_F2_I                        = 5496,
  NV_EDGE_900_RGI_G1_F2_I                        = 5497,
  NV_EDGE_900_RGI_G2_F2_I                        = 5498,
  NV_EDGE_900_RGI_G3_F2_I                        = 5499,
  NV_EDGE_900_RGI_G0_F3_I                        = 5500,
  NV_EDGE_900_RGI_G1_F3_I                        = 5501,
  NV_EDGE_900_RGI_G2_F3_I                        = 5502,
  NV_EDGE_900_RGI_G3_F3_I                        = 5503,
  NV_EDGE_1800_RGI_G0_F1_I                       = 5504,
  NV_EDGE_1800_RGI_G1_F1_I                       = 5505,
  NV_EDGE_1800_RGI_G2_F1_I                       = 5506,
  NV_EDGE_1800_RGI_G3_F1_I                       = 5507,
  NV_EDGE_1800_RGI_G0_F2_I                       = 5508,
  NV_EDGE_1800_RGI_G1_F2_I                       = 5509,
  NV_EDGE_1800_RGI_G2_F2_I                       = 5510,
  NV_EDGE_1800_RGI_G3_F2_I                       = 5511,
  NV_EDGE_1800_RGI_G0_F3_I                       = 5512,
  NV_EDGE_1800_RGI_G1_F3_I                       = 5513,
  NV_EDGE_1800_RGI_G2_F3_I                       = 5514,
  NV_EDGE_1800_RGI_G3_F3_I                       = 5515,
  NV_EDGE_1900_RGI_G0_F1_I                       = 5516,
  NV_EDGE_1900_RGI_G1_F1_I                       = 5517,
  NV_EDGE_1900_RGI_G2_F1_I                       = 5518,
  NV_EDGE_1900_RGI_G3_F1_I                       = 5519,
  NV_EDGE_1900_RGI_G0_F2_I                       = 5520,
  NV_EDGE_1900_RGI_G1_F2_I                       = 5521,
  NV_EDGE_1900_RGI_G2_F2_I                       = 5522,
  NV_EDGE_1900_RGI_G3_F2_I                       = 5523,
  NV_EDGE_1900_RGI_G0_F3_I                       = 5524,
  NV_EDGE_1900_RGI_G1_F3_I                       = 5525,
  NV_EDGE_1900_RGI_G2_F3_I                       = 5526,
  NV_EDGE_1900_RGI_G3_F3_I                       = 5527,
  NV_EDGE_850_PMEAS_G0_F1_I                      = 5528,
  NV_EDGE_850_PMEAS_G1_F1_I                      = 5529,
  NV_EDGE_850_PMEAS_G2_F1_I                      = 5530,
  NV_EDGE_850_PMEAS_G3_F1_I                      = 5531,
  NV_EDGE_850_PMEAS_G0_F2_I                      = 5532,
  NV_EDGE_850_PMEAS_G1_F2_I                      = 5533,
  NV_EDGE_850_PMEAS_G2_F2_I                      = 5534,
  NV_EDGE_850_PMEAS_G3_F2_I                      = 5535,
  NV_EDGE_850_PMEAS_G0_F3_I                      = 5536,
  NV_EDGE_850_PMEAS_G1_F3_I                      = 5537,
  NV_EDGE_850_PMEAS_G2_F3_I                      = 5538,
  NV_EDGE_850_PMEAS_G3_F3_I                      = 5539,
  NV_EDGE_900_PMEAS_G0_F1_I                      = 5540,
  NV_EDGE_900_PMEAS_G1_F1_I                      = 5541,
  NV_EDGE_900_PMEAS_G2_F1_I                      = 5542,
  NV_EDGE_900_PMEAS_G3_F1_I                      = 5543,
  NV_EDGE_900_PMEAS_G0_F2_I                      = 5544,
  NV_EDGE_900_PMEAS_G1_F2_I                      = 5545,
  NV_EDGE_900_PMEAS_G2_F2_I                      = 5546,
  NV_EDGE_900_PMEAS_G3_F2_I                      = 5547,
  NV_EDGE_900_PMEAS_G0_F3_I                      = 5548,
  NV_EDGE_900_PMEAS_G1_F3_I                      = 5549,
  NV_EDGE_900_PMEAS_G2_F3_I                      = 5550,
  NV_EDGE_900_PMEAS_G3_F3_I                      = 5551,
  NV_EDGE_1800_PMEAS_G0_F1_I                     = 5552,
  NV_EDGE_1800_PMEAS_G1_F1_I                     = 5553,
  NV_EDGE_1800_PMEAS_G2_F1_I                     = 5554,
  NV_EDGE_1800_PMEAS_G3_F1_I                     = 5555,
  NV_EDGE_1800_PMEAS_G0_F2_I                     = 5556,
  NV_EDGE_1800_PMEAS_G1_F2_I                     = 5557,
  NV_EDGE_1800_PMEAS_G2_F2_I                     = 5558,
  NV_EDGE_1800_PMEAS_G3_F2_I                     = 5559,
  NV_EDGE_1800_PMEAS_G0_F3_I                     = 5560,
  NV_EDGE_1800_PMEAS_G1_F3_I                     = 5561,
  NV_EDGE_1800_PMEAS_G2_F3_I                     = 5562,
  NV_EDGE_1800_PMEAS_G3_F3_I                     = 5563,
  NV_EDGE_1900_PMEAS_G0_F1_I                     = 5564,
  NV_EDGE_1900_PMEAS_G1_F1_I                     = 5565,
  NV_EDGE_1900_PMEAS_G2_F1_I                     = 5566,
  NV_EDGE_1900_PMEAS_G3_F1_I                     = 5567,
  NV_EDGE_1900_PMEAS_G0_F2_I                     = 5568,
  NV_EDGE_1900_PMEAS_G1_F2_I                     = 5569,
  NV_EDGE_1900_PMEAS_G2_F2_I                     = 5570,
  NV_EDGE_1900_PMEAS_G3_F2_I                     = 5571,
  NV_EDGE_1900_PMEAS_G0_F3_I                     = 5572,
  NV_EDGE_1900_PMEAS_G1_F3_I                     = 5573,
  NV_EDGE_1900_PMEAS_G2_F3_I                     = 5574,
  NV_EDGE_1900_PMEAS_G3_F3_I                     = 5575,
  NV_SUPPLY_I                                    = 5576,
  NV_C0_BC0_IM2_CAL_I                            = 5577,
  NV_C0_BC1_IM2_CAL_I                            = 5578,
  NV_C0_BC2_IM2_CAL_I                            = 5579,
  NV_C0_BC3_IM2_CAL_I                            = 5580,
  NV_C0_BC4_IM2_CAL_I                            = 5581,
  NV_C0_BC5_IM2_CAL_I                            = 5582,
  NV_C0_BC6_IM2_CAL_I                            = 5583,
  NV_C0_BC7_IM2_CAL_I                            = 5584,
  NV_C0_BC8_IM2_CAL_I                            = 5585,
  NV_C0_BC9_IM2_CAL_I                            = 5586,
  NV_C0_BC10_IM2_CAL_I                           = 5587,
  NV_C0_BC11_IM2_CAL_I                           = 5588,
  NV_C0_BC12_IM2_CAL_I                           = 5589,
  NV_C0_BC13_IM2_CAL_I                           = 5590,
  NV_C0_BC14_IM2_CAL_I                           = 5591,
  NV_C0_BC15_IM2_CAL_I                           = 5592,
  NV_TOOLKIT_ENV_RETRY_FLAG_I                    = 5593,
  NV_CGPS_SBAS_ENABLED_I                         = 5594,
  NV_CGPS_SBAS_USER_PREFERENCE_I                 = 5595,
  NV_CGPS_DPO_CONTROL_I                          = 5596,
  NV_ESN_ME_I                                    = 5597,
  NV_MEID_ME_I                                   = 5598,
  NV_CGPS_ON_DEMAND_ENABLED_I                    = 5599,
  NV_HDRSCP_SELECT_BCMCS_CONFIG_I                = 5600,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEA_F1_SEG1_I     = 5601,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEA_F1_SEG2_I     = 5602,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEB_F1_SEG1_I     = 5603,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEB_F1_SEG2_I     = 5604,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEA_F2_SEG1_I     = 5605,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEA_F2_SEG2_I     = 5606,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEB_F2_SEG1_I     = 5607,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEB_F2_SEG2_I     = 5608,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEA_F3_SEG1_I     = 5609,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEA_F3_SEG2_I     = 5610,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEB_F3_SEG1_I     = 5611,
  NV_GSM_850_AMAM_LINEAR_PA_RANGEB_F3_SEG2_I     = 5612,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEA_F1_SEG1_I     = 5613,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEA_F1_SEG2_I     = 5614,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEB_F1_SEG1_I     = 5615,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEB_F1_SEG2_I     = 5616,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEA_F2_SEG1_I     = 5617,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEA_F2_SEG2_I     = 5618,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEB_F2_SEG1_I     = 5619,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEB_F2_SEG2_I     = 5620,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEA_F3_SEG1_I     = 5621,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEA_F3_SEG2_I     = 5622,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEB_F3_SEG1_I     = 5623,
  NV_GSM_900_AMAM_LINEAR_PA_RANGEB_F3_SEG2_I     = 5624,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEA_F1_SEG1_I    = 5625,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEA_F1_SEG2_I    = 5626,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEB_F1_SEG1_I    = 5627,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEB_F1_SEG2_I    = 5628,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEA_F2_SEG1_I    = 5629,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEA_F2_SEG2_I    = 5630,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEB_F2_SEG1_I    = 5631,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEB_F2_SEG2_I    = 5632,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEA_F3_SEG1_I    = 5633,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEA_F3_SEG2_I    = 5634,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEB_F3_SEG1_I    = 5635,
  NV_GSM_1800_AMAM_LINEAR_PA_RANGEB_F3_SEG2_I    = 5636,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEA_F1_SEG1_I    = 5637,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEA_F1_SEG2_I    = 5638,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEB_F1_SEG1_I    = 5639,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEB_F1_SEG2_I    = 5640,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEA_F2_SEG1_I    = 5641,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEA_F2_SEG2_I    = 5642,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEB_F2_SEG1_I    = 5643,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEB_F2_SEG2_I    = 5644,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEA_F3_SEG1_I    = 5645,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEA_F3_SEG2_I    = 5646,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEB_F3_SEG1_I    = 5647,
  NV_GSM_1900_AMAM_LINEAR_PA_RANGEB_F3_SEG2_I    = 5648,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEA_F1_SEG1_I     = 5649,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEA_F1_SEG2_I     = 5650,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEB_F1_SEG1_I     = 5651,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEB_F1_SEG2_I     = 5652,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEA_F2_SEG1_I     = 5653,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEA_F2_SEG2_I     = 5654,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEB_F2_SEG1_I     = 5655,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEB_F2_SEG2_I     = 5656,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEA_F3_SEG1_I     = 5657,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEA_F3_SEG2_I     = 5658,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEB_F3_SEG1_I     = 5659,
  NV_GSM_850_AMPM_LINEAR_PA_RANGEB_F3_SEG2_I     = 5660,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEA_F1_SEG1_I     = 5661,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEA_F1_SEG2_I     = 5662,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEB_F1_SEG1_I     = 5663,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEB_F1_SEG2_I     = 5664,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEA_F2_SEG1_I     = 5665,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEA_F2_SEG2_I     = 5666,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEB_F2_SEG1_I     = 5667,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEB_F2_SEG2_I     = 5668,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEA_F3_SEG1_I     = 5669,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEA_F3_SEG2_I     = 5670,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEB_F3_SEG1_I     = 5671,
  NV_GSM_900_AMPM_LINEAR_PA_RANGEB_F3_SEG2_I     = 5672,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEA_F1_SEG1_I    = 5673,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEA_F1_SEG2_I    = 5674,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEB_F1_SEG1_I    = 5675,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEB_F1_SEG2_I    = 5676,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEA_F2_SEG1_I    = 5677,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEA_F2_SEG2_I    = 5678,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEB_F2_SEG1_I    = 5679,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEB_F2_SEG2_I    = 5680,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEA_F3_SEG1_I    = 5681,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEA_F3_SEG2_I    = 5682,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEB_F3_SEG1_I    = 5683,
  NV_GSM_1800_AMPM_LINEAR_PA_RANGEB_F3_SEG2_I    = 5684,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEA_F1_SEG1_I    = 5685,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEA_F1_SEG2_I    = 5686,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEB_F1_SEG1_I    = 5687,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEB_F1_SEG2_I    = 5688,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEA_F2_SEG1_I    = 5689,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEA_F2_SEG2_I    = 5690,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEB_F2_SEG1_I    = 5691,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEB_F2_SEG2_I    = 5692,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEA_F3_SEG1_I    = 5693,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEA_F3_SEG2_I    = 5694,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEB_F3_SEG1_I    = 5695,
  NV_GSM_1900_AMPM_LINEAR_PA_RANGEB_F3_SEG2_I    = 5696,
  NV_GSM_850_TX_AGC_SETTING_FOR_PRED_I           = 5697,
  NV_GSM_900_TX_AGC_SETTING_FOR_PRED_I           = 5698,
  NV_GSM_1800_TX_AGC_SETTING_FOR_PRED_I          = 5699,
  NV_GSM_1900_TX_AGC_SETTING_FOR_PRED_I          = 5700,
  NV_MIPV6_BEHAVIOR_I                            = 5701,
  NV_MIPV6_ACTIVE_USER_I                         = 5702,
  NV_MIPV6_GEN_USER_PROFILE_I                    = 5703,
  NV_MIPV6_NAI_0_I                               = 5704,
  NV_MIPV6_NAI_1_I                               = 5705,
  NV_MIPV6_NAI_2_I                               = 5706,
  NV_MIPV6_NAI_3_I                               = 5707,
  NV_MIPV6_NAI_4_I                               = 5708,
  NV_MIPV6_EAP_AKA_CREDENTIAL_I                  = 5709,
  NV_MIPV6_HA_I                                  = 5710,
  NV_MIPV6_HOA_I                                 = 5711,
  NV_MIPV6_PRIMARY_DNS_I                         = 5712,
  NV_MIPV6_SECONDARY_DNS_I                       = 5713,
  NV_MIPV6_IPSEC_CONFIG_I                        = 5714,
  NV_MIPV6_REGISTRATION_CONFIG_I                 = 5715,
  NV_MIPV6_IPSEC_ON_PAYLOAD_I                    = 5716,
  NV_MIPV6_REQUEST_VISITED_NETWORK_HA_I          = 5717,
  NV_MIPV6_PROTECTION_METHOD_I                   = 5718,
  NV_MIPV6_MN_AAA_SHARED_SECRET_I                = 5719,
  NV_MIPV6_MN_HA_SHARED_SECRET_I                 = 5720,
  NV_MIPV6_AUTH_PROTO_CONFIG_I                   = 5721,
  NV_BC0_EXP_HDET_VS_AGC_V2_I                    = 5722,
  NV_BC1_EXP_HDET_VS_AGC_V2_I                    = 5723,
  NV_BC2_EXP_HDET_VS_AGC_V2_I                    = 5724,
  NV_BC3_EXP_HDET_VS_AGC_V2_I                    = 5725,
  NV_BC4_EXP_HDET_VS_AGC_V2_I                    = 5726,
  NV_BC5_EXP_HDET_VS_AGC_V2_I                    = 5727,
  NV_BC6_EXP_HDET_VS_AGC_V2_I                    = 5728,
  NV_BC7_EXP_HDET_VS_AGC_V2_I                    = 5729,
  NV_BC8_EXP_HDET_VS_AGC_V2_I                    = 5730,
  NV_BC9_EXP_HDET_VS_AGC_V2_I                    = 5731,
  NV_BC10_EXP_HDET_VS_AGC_V2_I                   = 5732,
  NV_BC11_EXP_HDET_VS_AGC_V2_I                   = 5733,
  NV_BC12_EXP_HDET_VS_AGC_V2_I                   = 5734,
  NV_BC13_EXP_HDET_VS_AGC_V2_I                   = 5735,
  NV_BC14_EXP_HDET_VS_AGC_V2_I                   = 5736,
  NV_BC15_EXP_HDET_VS_AGC_V2_I                   = 5737,
  NV_BC0_HDET_OFF_V2_I                           = 5738,
  NV_BC1_HDET_OFF_V2_I                           = 5739,
  NV_BC2_HDET_OFF_V2_I                           = 5740,
  NV_BC3_HDET_OFF_V2_I                           = 5741,
  NV_BC4_HDET_OFF_V2_I                           = 5742,
  NV_BC5_HDET_OFF_V2_I                           = 5743,
  NV_BC6_HDET_OFF_V2_I                           = 5744,
  NV_BC7_HDET_OFF_V2_I                           = 5745,
  NV_BC8_HDET_OFF_V2_I                           = 5746,
  NV_BC9_HDET_OFF_V2_I                           = 5747,
  NV_BC10_HDET_OFF_V2_I                          = 5748,
  NV_BC11_HDET_OFF_V2_I                          = 5749,
  NV_BC12_HDET_OFF_V2_I                          = 5750,
  NV_BC13_HDET_OFF_V2_I                          = 5751,
  NV_BC14_HDET_OFF_V2_I                          = 5752,
  NV_BC15_HDET_OFF_V2_I                          = 5753,
  NV_BC0_HDET_SPN_V2_I                           = 5754,
  NV_BC1_HDET_SPN_V2_I                           = 5755,
  NV_BC2_HDET_SPN_V2_I                           = 5756,
  NV_BC3_HDET_SPN_V2_I                           = 5757,
  NV_BC4_HDET_SPN_V2_I                           = 5758,
  NV_BC5_HDET_SPN_V2_I                           = 5759,
  NV_BC6_HDET_SPN_V2_I                           = 5760,
  NV_BC7_HDET_SPN_V2_I                           = 5761,
  NV_BC8_HDET_SPN_V2_I                           = 5762,
  NV_BC9_HDET_SPN_V2_I                           = 5763,
  NV_BC10_HDET_SPN_V2_I                          = 5764,
  NV_BC11_HDET_SPN_V2_I                          = 5765,
  NV_BC12_HDET_SPN_V2_I                          = 5766,
  NV_BC13_HDET_SPN_V2_I                          = 5767,
  NV_BC14_HDET_SPN_V2_I                          = 5768,
  NV_BC15_HDET_SPN_V2_I                          = 5769,
  NV_TOOLKIT_CS_PS_PARALLEL_I                    = 5770,
  NV_DVBH_MAX_TS_ACQ_ATTEMPTS_I                  = 5771,
  NV_DVBH_MAX_SYS_ACQ_ATTEMPTS_I                 = 5772,
  NV_DSAT707_CTA_TIMER_I                         = 5773,
  NV_DATA_AGG_TIMER_I                            = 5774,
  NV_DHCP6_INFORM_REQ_TRIES_I                    = 5775,
  NV_DHCP6_INFORM_REQ_INIT_RETRY_INTERVAL_I      = 5776,
  NV_WCDMA_MIMO_CTRL_I                           = 5777,
  NV_UBM_DVBH_L1_CFG_EBI2_WS_I                   = 5778,
  NV_UBM_DVBH_L1_CFG_DEBUG_I                     = 5779,
  NV_UBM_DVBH_L1_CFG_USE_ACQ_TIMEOUT_I           = 5780,
  NV_UBM_DVBH_L1_CFG_SNOOZE_I                    = 5781,
  NV_UBM_DVBH_L1_CFG_SLEEP_I                     = 5782,
  NV_UBM_DVBH_L1_CFG_BW_I                        = 5783,
  NV_UBM_DVBH_L1_CFG_T_SCAN_LOCKOUT_MS_I         = 5784,
  NV_UBM_DVBH_L1_CFG_T_SCAN_NO_AGC_MS_I          = 5785,
  NV_UBM_DVBH_L1_CFG_SCAN_NO_SIG_TRS_DB_Q6_I     = 5786,
  NV_UBM_DVBH_L1_CFG_T_SCAN_AGC_MS_I             = 5787,
  NV_UBM_DVBH_L1_CFG_T_SCAN_TPS_MS_I             = 5788,
  NV_UBM_DVBH_L1_CFG_SCAN_ENBLD_TRS_DB_Q6_I      = 5789,
  NV_UBM_DVBH_L1_CFG_HANDOFF_THRESH_DB_Q6_I      = 5790,
  NV_UBM_DVBH_L1_CFG_ACQ_TIMEOUT_MS_I            = 5791,
  NV_UBM_DVBH_L1_CFG_RECOVERY_RETRIES_I          = 5792,
  NV_UBM_DVBH_L1_CFG_TOTAL_RECOVERY_CNT_I        = 5793,
  NV_UBM_DVBH_L1_CFG_ACQ_BAILOUT_I               = 5794,
  NV_UBM_DVBH_L1_CFG_PRE_JAMMER_CFG_I            = 5795,
  NV_UBM_DVBH_L1_CFG_JAMMER_NOTCH_GAIN_I         = 5796,
  NV_UBM_DVBH_L1_CFG_POST_JAMMER_CFG_I           = 5797,
  NV_UBM_DVBH_L1_CFG_CPCE_ENABLED_I              = 5798,
  NV_UBM_DVBH_L1_CFG_FAP_LAP_SENS_I              = 5799,
  NV_UBM_DVBH_L1_CFG_MAX_CAND_PATHS_I            = 5800,
  NV_UBM_DVBH_L1_CFG_SIG_RECOVERED_TRSH_Q7_I     = 5801,
  NV_UBM_DVBH_L1_CFG_DISABLE_CPCE_IIR_I          = 5802,
  NV_UBM_DVBH_L1_CFG_TT_CIR_THRESH_I             = 5803,
  NV_UBM_DVBH_L1_CFG_FULL_SLEEP_REACQ_I          = 5804,
  NV_UBM_DVBH_L1_CFG_JAMMER_DETECT_THRESH_I      = 5805,
  NV_UBM_DVBH_L1_CFG_CPCE_LNA_THRESH_I           = 5806,
  NV_UBM_DVBH_L1_CFG_CE_IRR_FILT_GAIN_I          = 5807,
  NV_UBM_DVBH_L1_CFG_CPCE_CHECK_SYM_COUNT_I      = 5808,
  NV_UBM_DVBH_L1_CFG_CPCE_CAND_PS_QPSK_TRS_I     = 5809,
  NV_UBM_DVBH_L1_CFG_ADD_RAMPUP_SYMBOLS_I        = 5810,
  NV_UBM_DVBH_L1_CFG_CPCE_CHCK_SYM_IGNRE_CNT_I   = 5811,
  NV_UBM_DVBH_L1_CFG_RECOVERY_MIN_GOOD_RS1_I     = 5812,
  NV_UBM_DVBH_L1_CFG_RECOVERY_MAX_DROP_COUNT_I   = 5813,
  NV_UBM_DVBH_L1_CFG_T_RECOVERY_SCAN_MS_I        = 5814,
  NV_UBM_DVBH_L1_CFG_CAND_PER_TRS_QPSK_Q14_I     = 5815,
  NV_UBM_DVBH_L1_CFG_CPCE_AGC_VAR_THRESH_I       = 5816,
  NV_UBM_DVBH_L1_CFG_CPCE_AGC_IGNORE_CNT_I       = 5817,
  NV_UBM_DVBH_L1_CFG_CPCE_CAND_PS_16QAM_TRS_I    = 5818,
  NV_UBM_DVBH_L1_CFG_CAND_PER_TRS_16QAM_Q14_I    = 5819,
  NV_UBM_DVBH_L1_JAMMER_SYMBOLS_TO_IIR_I         = 5820,
  NV_UBM_DVBH_L1_JAMMER_IIR_GAIN_I               = 5821,
  NV_UBM_DVBH_L1_CFG_JAMMER_PEAK_ABS_TRS_I       = 5822,
  NV_MAO_TEST_CFG_I                              = 5823,
  NV_WWAN_ACCESS_OVER_WIFI_PREFERRED_I           = 5824,
  NV_WIFI_LOCAL_BREAKOUT_ALLOWED_I               = 5825,
  NV_IWLAN_OPERATOR_ID_I                         = 5826,
  NV_IWLAN_REALM_I                               = 5827,
  NV_IWLAN_AUTH_MODE_I                           = 5828,
  NV_IWLAN_SOFT_IKE_REKEY_TIME_I                 = 5829,
  NV_IWLAN_HARD_IKE_REKEY_TIME_I                 = 5830,
  NV_IWLAN_CHILD_SA_SOFT_LIFETIME_SEC_I          = 5831,
  NV_IWLAN_CHILD_SA_HARD_LIFETIME_SEC_I          = 5832,
  NV_IWLAN_CHILD_SA_SOFT_LIFETIME_BYTES_I        = 5833,
  NV_IWLAN_CHILD_SA_HARD_LIFETIME_BYTES_I        = 5834,
  NV_IWLAN_NAT_KEEPALIVE_INTERVAL_I              = 5835,
  NV_IWLAN_IKE_RETRANSMISSION_INTERVAL_I         = 5836,
  NV_IWLAN_IKE_MAX_RETRANSMISSIONS_I             = 5837,
  NV_IWLAN_IKEV2_IP_CONFIG_MASK_I                = 5838,
  NV_IWLAN_DHCP_IP_CONFIG_MASK_I                 = 5839,
  NV_IWLAN_CHILD_SA_ENC_ALGO_PROPOSAL_MASK_I     = 5840,
  NV_IWLAN_IKE_SA_ENC_ALGO_PROPOSAL_MASK_I       = 5841,
  NV_IWLAN_IKE_SA_PRF_ALGO_PROPOSAL_MASK_I       = 5842,
  NV_IWLAN_CHILD_SA_AUTH_ALGO_PROPOSAL_MASK_I    = 5843,
  NV_IWLAN_IKE_SA_AUTH_ALGO_PROPOSAL_MASK_I      = 5844,
  NV_IWLAN_IKE_DH_MODE_I                         = 5845,
  NV_IWLAN_PDIF_ADDRESS_I                        = 5846,
  NV_IWLAN_MULTI_AUTH_SUPPORTED_I                = 5847,
  NV_IWLAN_PDIF_FQDN_I                           = 5848,
  NV_CGPS_SBAS_WAAS_AREA_NODE1_I                 = 5849,
  NV_CGPS_SBAS_WAAS_AREA_NODE2_I                 = 5850,
  NV_CGPS_SBAS_WAAS_AREA_NODE3_I                 = 5851,
  NV_CGPS_SBAS_WAAS_AREA_NODE4_I                 = 5852,
  NV_CGPS_SBAS_WAAS_AREA_NODE5_I                 = 5853,
  NV_CGPS_SBAS_WAAS_AREA_NODE6_I                 = 5854,
  NV_CGPS_SBAS_EGNOS_AREA_NODE1_I                = 5855,
  NV_CGPS_SBAS_EGNOS_AREA_NODE2_I                = 5856,
  NV_CGPS_SBAS_EGNOS_AREA_NODE3_I                = 5857,
  NV_CGPS_SBAS_EGNOS_AREA_NODE4_I                = 5858,
  NV_CGPS_SBAS_EGNOS_AREA_NODE5_I                = 5859,
  NV_CGPS_SBAS_EGNOS_AREA_NODE6_I                = 5860,
  NV_CGPS_SBAS_MSAS_AREA_NODE1_I                 = 5861,
  NV_CGPS_SBAS_MSAS_AREA_NODE2_I                 = 5862,
  NV_CGPS_SBAS_MSAS_AREA_NODE3_I                 = 5863,
  NV_CGPS_SBAS_MSAS_AREA_NODE4_I                 = 5864,
  NV_CGPS_SBAS_MSAS_AREA_NODE5_I                 = 5865,
  NV_CGPS_SBAS_MSAS_AREA_NODE6_I                 = 5866,
  NV_CGPS_SBAS_GAGAN_AREA_NODE1_I                = 5867,
  NV_CGPS_SBAS_GAGAN_AREA_NODE2_I                = 5868,
  NV_CGPS_SBAS_GAGAN_AREA_NODE3_I                = 5869,
  NV_CGPS_SBAS_GAGAN_AREA_NODE4_I                = 5870,
  NV_CGPS_SBAS_GAGAN_AREA_NODE5_I                = 5871,
  NV_CGPS_SBAS_GAGAN_AREA_NODE6_I                = 5872,
  NV_IWLAN_DPD_ENABLED_I                         = 5873,
  NV_IWLAN_DPD_TIME_SECS_I                       = 5874,
  NV_BT_SOC_REFCLOCK_TYPE_I                      = 5875,
  NV_BT_SOC_CLK_SHARING_TYPE_I                   = 5876,
  NV_BT_SOC_INBAND_SLEEP_I                       = 5877,
  NV_BT_SOC_LOGGING_ENABLED_I                    = 5878,
  NV_BT_SOC_PM_MODE_I                            = 5879,
  NV_TCP_DEFAULT_ROUND_TRIP_TIME_I               = 5880,
  NV_GPS1_GPS_RFIC_IM2CAL_IM2DAC_I_CHANNEL_I     = 5881,
  NV_GPS1_GPS_RFIC_IM2CAL_IM2DAC_Q_CHANNEL_I     = 5882,
  NV_BC0_HDR_REVA_TX_PREDISTORT_I                = 5883,
  NV_BC1_HDR_REVA_TX_PREDISTORT_I                = 5884,
  NV_BC3_HDR_REVA_TX_PREDISTORT_I                = 5885,
  NV_BC4_HDR_REVA_TX_PREDISTORT_I                = 5886,
  NV_BC6_HDR_REVA_TX_PREDISTORT_I                = 5887,
  NV_BC5_HDR_REVA_TX_PREDISTORT_I                = 5888,
  NV_BC10_HDR_REVA_TX_PREDISTORT_I               = 5889,
  NV_BC11_HDR_REVA_TX_PREDISTORT_I               = 5890,
  NV_BC14_HDR_REVA_TX_PREDISTORT_I               = 5891,
  NV_BC15_HDR_REVA_TX_PREDISTORT_I               = 5892,
  NV_BCX_HDR_REVA_TX_PREDISTORT_I                = 5893,
  NV_HDRMRLPARDA_PARAM_I                         = 5894,
  NV_MGRF_SUPPORTED_I                            = 5895,
  NV_WCDMA_RXF_MIS_COMP_A_COEFF_I                = 5896,
  NV_WCDMA_RXF_MIS_COMP_B_COEFF_I                = 5897,
  NV_C1_WCDMA_2100_RXF_MIS_COMP_A_COEFF_I        = 5898,
  NV_C1_WCDMA_2100_RXF_MIS_COMP_B_COEFF_I        = 5899,
  NV_WCDMA_1900_RXF_MIS_COMP_A_COEFF_I           = 5900,
  NV_WCDMA_1900_RXF_MIS_COMP_B_COEFF_I           = 5901,
  NV_C1_WCDMA_1900_RXF_MIS_COMP_A_COEFF_I        = 5902,
  NV_C1_WCDMA_1900_RXF_MIS_COMP_B_COEFF_I        = 5903,
  NV_WCDMA_BC4_RXF_MIS_COMP_A_COEFF_I            = 5904,
  NV_WCDMA_BC4_RXF_MIS_COMP_B_COEFF_I            = 5905,
  NV_C1_WCDMA_BC4_RXF_MIS_COMP_A_COEFF_I         = 5906,
  NV_C1_WCDMA_BC4_RXF_MIS_COMP_B_COEFF_I         = 5907,
  NV_WCDMA_800_RXF_MIS_COMP_A_COEFF_I            = 5908,
  NV_WCDMA_800_RXF_MIS_COMP_B_COEFF_I            = 5909,
  NV_C1_WCDMA_800_RXF_MIS_COMP_A_COEFF_I         = 5910,
  NV_C1_WCDMA_800_RXF_MIS_COMP_B_COEFF_I         = 5911,
  NV_WCDMA_RXF_ICI_I_COEF0_1_I                   = 5912,
  NV_WCDMA_RXF_ICI_I_COEF2_3_I                   = 5913,
  NV_WCDMA_RXF_ICI_I_COEF4_5_I                   = 5914,
  NV_WCDMA_RXF_ICI_I_COEF6_7_I                   = 5915,
  NV_WCDMA_RXF_ICI_I_COEF8_9_I                   = 5916,
  NV_WCDMA_RXF_ICI_I_COEF10_11_I                 = 5917,
  NV_WCDMA_RXF_ICI_I_COEF12_13_I                 = 5918,
  NV_WCDMA_RXF_ICI_I_COEF14_15_I                 = 5919,
  NV_WCDMA_RXF_ICI_Q_COEF0_1_I                   = 5920,
  NV_WCDMA_RXF_ICI_Q_COEF2_3_I                   = 5921,
  NV_WCDMA_RXF_ICI_Q_COEF4_5_I                   = 5922,
  NV_WCDMA_RXF_ICI_Q_COEF6_7_I                   = 5923,
  NV_WCDMA_RXF_ICI_Q_COEF8_9_I                   = 5924,
  NV_WCDMA_RXF_ICI_Q_COEF10_11_I                 = 5925,
  NV_WCDMA_RXF_ICI_Q_COEF12_13_I                 = 5926,
  NV_WCDMA_RXF_ICI_Q_COEF14_15_I                 = 5927,
  NV_C1_WCDMA_2100_RXF_ICI_I_COEF0_1_I           = 5928,
  NV_C1_WCDMA_2100_RXF_ICI_I_COEF2_3_I           = 5929,
  NV_C1_WCDMA_2100_RXF_ICI_I_COEF4_5_I           = 5930,
  NV_C1_WCDMA_2100_RXF_ICI_I_COEF6_7_I           = 5931,
  NV_C1_WCDMA_2100_RXF_ICI_I_COEF8_9_I           = 5932,
  NV_C1_WCDMA_2100_RXF_ICI_I_COEF10_11_I         = 5933,
  NV_C1_WCDMA_2100_RXF_ICI_I_COEF12_13_I         = 5934,
  NV_C1_WCDMA_2100_RXF_ICI_I_COEF14_15_I         = 5935,
  NV_C1_WCDMA_2100_RXF_ICI_Q_COEF0_1_I           = 5936,
  NV_C1_WCDMA_2100_RXF_ICI_Q_COEF2_3_I           = 5937,
  NV_C1_WCDMA_2100_RXF_ICI_Q_COEF4_5_I           = 5938,
  NV_C1_WCDMA_2100_RXF_ICI_Q_COEF6_7_I           = 5939,
  NV_C1_WCDMA_2100_RXF_ICI_Q_COEF8_9_I           = 5940,
  NV_C1_WCDMA_2100_RXF_ICI_Q_COEF10_11_I         = 5941,
  NV_C1_WCDMA_2100_RXF_ICI_Q_COEF12_13_I         = 5942,
  NV_C1_WCDMA_2100_RXF_ICI_Q_COEF14_15_I         = 5943,
  NV_WCDMA_RXF_ICI_IQ_TRUNC_I                    = 5944,
  NV_C1_WCDMA_2100_RXF_ICI_IQ_TRUNC_I            = 5945,
  NV_WCDMA_1900_RXF_ICI_I_COEF0_1_I              = 5946,
  NV_WCDMA_1900_RXF_ICI_I_COEF2_3_I              = 5947,
  NV_WCDMA_1900_RXF_ICI_I_COEF4_5_I              = 5948,
  NV_WCDMA_1900_RXF_ICI_I_COEF6_7_I              = 5949,
  NV_WCDMA_1900_RXF_ICI_I_COEF8_9_I              = 5950,
  NV_WCDMA_1900_RXF_ICI_I_COEF10_11_I            = 5951,
  NV_WCDMA_1900_RXF_ICI_I_COEF12_13_I            = 5952,
  NV_WCDMA_1900_RXF_ICI_I_COEF14_15_I            = 5953,
  NV_WCDMA_1900_RXF_ICI_Q_COEF0_1_I              = 5954,
  NV_WCDMA_1900_RXF_ICI_Q_COEF2_3_I              = 5955,
  NV_WCDMA_1900_RXF_ICI_Q_COEF4_5_I              = 5956,
  NV_WCDMA_1900_RXF_ICI_Q_COEF6_7_I              = 5957,
  NV_WCDMA_1900_RXF_ICI_Q_COEF8_9_I              = 5958,
  NV_WCDMA_1900_RXF_ICI_Q_COEF10_11_I            = 5959,
  NV_WCDMA_1900_RXF_ICI_Q_COEF12_13_I            = 5960,
  NV_WCDMA_1900_RXF_ICI_Q_COEF14_15_I            = 5961,
  NV_C1_WCDMA_1900_RXF_ICI_I_COEF0_1_I           = 5962,
  NV_C1_WCDMA_1900_RXF_ICI_I_COEF2_3_I           = 5963,
  NV_C1_WCDMA_1900_RXF_ICI_I_COEF4_5_I           = 5964,
  NV_C1_WCDMA_1900_RXF_ICI_I_COEF6_7_I           = 5965,
  NV_C1_WCDMA_1900_RXF_ICI_I_COEF8_9_I           = 5966,
  NV_C1_WCDMA_1900_RXF_ICI_I_COEF10_11_I         = 5967,
  NV_C1_WCDMA_1900_RXF_ICI_I_COEF12_13_I         = 5968,
  NV_C1_WCDMA_1900_RXF_ICI_I_COEF14_15_I         = 5969,
  NV_C1_WCDMA_1900_RXF_ICI_Q_COEF0_1_I           = 5970,
  NV_C1_WCDMA_1900_RXF_ICI_Q_COEF2_3_I           = 5971,
  NV_C1_WCDMA_1900_RXF_ICI_Q_COEF4_5_I           = 5972,
  NV_C1_WCDMA_1900_RXF_ICI_Q_COEF6_7_I           = 5973,
  NV_C1_WCDMA_1900_RXF_ICI_Q_COEF8_9_I           = 5974,
  NV_C1_WCDMA_1900_RXF_ICI_Q_COEF10_11_I         = 5975,
  NV_C1_WCDMA_1900_RXF_ICI_Q_COEF12_13_I         = 5976,
  NV_C1_WCDMA_1900_RXF_ICI_Q_COEF14_15_I         = 5977,
  NV_WCDMA_1900_RXF_ICI_IQ_TRUNC_I               = 5978,
  NV_C1_WCDMA_1900_RXF_ICI_IQ_TRUNC_I            = 5979,
  NV_WCDMA_BC4_RXF_ICI_I_COEF0_1_I               = 5980,
  NV_WCDMA_BC4_RXF_ICI_I_COEF2_3_I               = 5981,
  NV_WCDMA_BC4_RXF_ICI_I_COEF4_5_I               = 5982,
  NV_WCDMA_BC4_RXF_ICI_I_COEF6_7_I               = 5983,
  NV_WCDMA_BC4_RXF_ICI_I_COEF8_9_I               = 5984,
  NV_WCDMA_BC4_RXF_ICI_I_COEF10_11_I             = 5985,
  NV_WCDMA_BC4_RXF_ICI_I_COEF12_13_I             = 5986,
  NV_WCDMA_BC4_RXF_ICI_I_COEF14_15_I             = 5987,
  NV_WCDMA_BC4_RXF_ICI_Q_COEF0_1_I               = 5988,
  NV_WCDMA_BC4_RXF_ICI_Q_COEF2_3_I               = 5989,
  NV_WCDMA_BC4_RXF_ICI_Q_COEF4_5_I               = 5990,
  NV_WCDMA_BC4_RXF_ICI_Q_COEF6_7_I               = 5991,
  NV_WCDMA_BC4_RXF_ICI_Q_COEF8_9_I               = 5992,
  NV_WCDMA_BC4_RXF_ICI_Q_COEF10_11_I             = 5993,
  NV_WCDMA_BC4_RXF_ICI_Q_COEF12_13_I             = 5994,
  NV_WCDMA_BC4_RXF_ICI_Q_COEF14_15_I             = 5995,
  NV_C1_WCDMA_BC4_RXF_ICI_I_COEF0_1_I            = 5996,
  NV_C1_WCDMA_BC4_RXF_ICI_I_COEF2_3_I            = 5997,
  NV_C1_WCDMA_BC4_RXF_ICI_I_COEF4_5_I            = 5998,
  NV_C1_WCDMA_BC4_RXF_ICI_I_COEF6_7_I            = 5999,
  NV_C1_WCDMA_BC4_RXF_ICI_I_COEF8_9_I            = 6000,
  NV_C1_WCDMA_BC4_RXF_ICI_I_COEF10_11_I          = 6001,
  NV_C1_WCDMA_BC4_RXF_ICI_I_COEF12_13_I          = 6002,
  NV_C1_WCDMA_BC4_RXF_ICI_I_COEF14_15_I          = 6003,
  NV_C1_WCDMA_BC4_RXF_ICI_Q_COEF0_1_I            = 6004,
  NV_C1_WCDMA_BC4_RXF_ICI_Q_COEF2_3_I            = 6005,
  NV_C1_WCDMA_BC4_RXF_ICI_Q_COEF4_5_I            = 6006,
  NV_C1_WCDMA_BC4_RXF_ICI_Q_COEF6_7_I            = 6007,
  NV_C1_WCDMA_BC4_RXF_ICI_Q_COEF8_9_I            = 6008,
  NV_C1_WCDMA_BC4_RXF_ICI_Q_COEF10_11_I          = 6009,
  NV_C1_WCDMA_BC4_RXF_ICI_Q_COEF12_13_I          = 6010,
  NV_C1_WCDMA_BC4_RXF_ICI_Q_COEF14_15_I          = 6011,
  NV_WCDMA_BC4_RXF_ICI_IQ_TRUNC_I                = 6012,
  NV_C1_WCDMA_BC4_RXF_ICI_IQ_TRUNC_I             = 6013,
  NV_WCDMA_800_RXF_ICI_I_COEF0_1_I               = 6014,
  NV_WCDMA_800_RXF_ICI_I_COEF2_3_I               = 6015,
  NV_WCDMA_800_RXF_ICI_I_COEF4_5_I               = 6016,
  NV_WCDMA_800_RXF_ICI_I_COEF6_7_I               = 6017,
  NV_WCDMA_800_RXF_ICI_I_COEF8_9_I               = 6018,
  NV_WCDMA_800_RXF_ICI_I_COEF10_11_I             = 6019,
  NV_WCDMA_800_RXF_ICI_I_COEF12_13_I             = 6020,
  NV_WCDMA_800_RXF_ICI_I_COEF14_15_I             = 6021,
  NV_WCDMA_800_RXF_ICI_Q_COEF0_1_I               = 6022,
  NV_WCDMA_800_RXF_ICI_Q_COEF2_3_I               = 6023,
  NV_WCDMA_800_RXF_ICI_Q_COEF4_5_I               = 6024,
  NV_WCDMA_800_RXF_ICI_Q_COEF6_7_I               = 6025,
  NV_WCDMA_800_RXF_ICI_Q_COEF8_9_I               = 6026,
  NV_WCDMA_800_RXF_ICI_Q_COEF10_11_I             = 6027,
  NV_WCDMA_800_RXF_ICI_Q_COEF12_13_I             = 6028,
  NV_WCDMA_800_RXF_ICI_Q_COEF14_15_I             = 6029,
  NV_C1_WCDMA_800_RXF_ICI_I_COEF0_1_I            = 6030,
  NV_C1_WCDMA_800_RXF_ICI_I_COEF2_3_I            = 6031,
  NV_C1_WCDMA_800_RXF_ICI_I_COEF4_5_I            = 6032,
  NV_C1_WCDMA_800_RXF_ICI_I_COEF6_7_I            = 6033,
  NV_C1_WCDMA_800_RXF_ICI_I_COEF8_9_I            = 6034,
  NV_C1_WCDMA_800_RXF_ICI_I_COEF10_11_I          = 6035,
  NV_C1_WCDMA_800_RXF_ICI_I_COEF12_13_I          = 6036,
  NV_C1_WCDMA_800_RXF_ICI_I_COEF14_15_I          = 6037,
  NV_C1_WCDMA_800_RXF_ICI_Q_COEF0_1_I            = 6038,
  NV_C1_WCDMA_800_RXF_ICI_Q_COEF2_3_I            = 6039,
  NV_C1_WCDMA_800_RXF_ICI_Q_COEF4_5_I            = 6040,
  NV_C1_WCDMA_800_RXF_ICI_Q_COEF6_7_I            = 6041,
  NV_C1_WCDMA_800_RXF_ICI_Q_COEF8_9_I            = 6042,
  NV_C1_WCDMA_800_RXF_ICI_Q_COEF10_11_I          = 6043,
  NV_C1_WCDMA_800_RXF_ICI_Q_COEF12_13_I          = 6044,
  NV_C1_WCDMA_800_RXF_ICI_Q_COEF14_15_I          = 6045,
  NV_WCDMA_800_RXF_ICI_IQ_TRUNC_I                = 6046,
  NV_C1_WCDMA_800_RXF_ICI_IQ_TRUNC_I             = 6047,
  NV_WCDMA_2100_HS_SWITCHPOINTS_SHIFT_I          = 6048,
  NV_WCDMA_1900_HS_SWITCHPOINTS_SHIFT_I          = 6049,
  NV_WCDMA_1800_HS_SWITCHPOINTS_SHIFT_I          = 6050,
  NV_WCDMA_900_HS_SWITCHPOINTS_SHIFT_I           = 6051,
  NV_WCDMA_800_HS_SWITCHPOINTS_SHIFT_I           = 6052,
  NV_WCDMA_BC4_HS_SWITCHPOINTS_SHIFT_I           = 6053,
  NV_BCX_BLOCK_1_GPS1_RF_DELAY_I                 = 6054,
  NV_BCX_BLOCK_1_RF_TUNE_RESERVED_I              = 6055,
  NV_BCX_BLOCK_1_TX_LIM_VS_TEMP_I                = 6056,
  NV_BCX_BLOCK_1_TX_LIN_MASTER0_I                = 6057,
  NV_BCX_BLOCK_1_TX_LIN_MASTER1_I                = 6058,
  NV_BCX_BLOCK_1_TX_LIN_MASTER2_I                = 6059,
  NV_BCX_BLOCK_1_TX_LIN_MASTER3_I                = 6060,
  NV_BCX_BLOCK_1_TX_COMP0_I                      = 6061,
  NV_BCX_BLOCK_1_TX_COMP1_I                      = 6062,
  NV_BCX_BLOCK_1_TX_COMP2_I                      = 6063,
  NV_BCX_BLOCK_1_TX_COMP3_I                      = 6064,
  NV_BCX_BLOCK_1_TX_LIM_VS_FREQ_I                = 6065,
  NV_BCX_BLOCK_1_PA_R1_RISE_I                    = 6066,
  NV_BCX_BLOCK_1_PA_R1_FALL_I                    = 6067,
  NV_BCX_BLOCK_1_PA_R2_RISE_I                    = 6068,
  NV_BCX_BLOCK_1_PA_R2_FALL_I                    = 6069,
  NV_BCX_BLOCK_1_PA_R3_RISE_I                    = 6070,
  NV_BCX_BLOCK_1_PA_R3_FALL_I                    = 6071,
  NV_BCX_BLOCK_1_HDET_OFF_I                      = 6072,
  NV_BCX_BLOCK_1_HDET_SPN_I                      = 6073,
  NV_BCX_BLOCK_1_EXP_HDET_VS_AGC_I               = 6074,
  NV_BCX_BLOCK_1_ENC_BTF_I                       = 6075,
  NV_BCX_BLOCK_1_VCO_COARSE_TUNE_TABLE_I         = 6076,
  NV_BCX_BLOCK_1_P1_RISE_FALL_OFF_I              = 6077,
  NV_C0_BCX_BLOCK_1_TX_CAL_CHAN_I                = 6078,
  NV_C0_BCX_BLOCK_1_RX_CAL_CHAN_I                = 6079,
  NV_C0_BCX_BLOCK_1_LNA_1_OFFSET_VS_FREQ_I       = 6080,
  NV_C0_BCX_BLOCK_1_LNA_2_OFFSET_VS_FREQ_I       = 6081,
  NV_C0_BCX_BLOCK_1_LNA_3_OFFSET_VS_FREQ_I       = 6082,
  NV_C0_BCX_BLOCK_1_LNA_4_OFFSET_VS_FREQ_I       = 6083,
  NV_C0_BCX_BLOCK_1_LNA_1_OFFSET_I               = 6084,
  NV_C0_BCX_BLOCK_1_LNA_2_OFFSET_I               = 6085,
  NV_C0_BCX_BLOCK_1_LNA_3_OFFSET_I               = 6086,
  NV_C0_BCX_BLOCK_1_LNA_4_OFFSET_I               = 6087,
  NV_C0_BCX_BLOCK_1_IM2_I_VALUE_I                = 6088,
  NV_C0_BCX_BLOCK_1_IM2_Q_VALUE_I                = 6089,
  NV_C0_BCX_BLOCK_1_VGA_GAIN_OFFSET_I            = 6090,
  NV_C0_BCX_BLOCK_1_VGA_GAIN_OFFSET_VS_FREQ_I    = 6091,
  NV_C0_BCX_BLOCK_1_IM2_TRANSCONDUCTOR_VALUE_I   = 6092,
  NV_C0_BCX_BLOCK_1_LNA_1_RISE_I                 = 6093,
  NV_C0_BCX_BLOCK_1_LNA_1_FALL_I                 = 6094,
  NV_C0_BCX_BLOCK_1_LNA_2_RISE_I                 = 6095,
  NV_C0_BCX_BLOCK_1_LNA_2_FALL_I                 = 6096,
  NV_C0_BCX_BLOCK_1_LNA_3_RISE_I                 = 6097,
  NV_C0_BCX_BLOCK_1_LNA_3_FALL_I                 = 6098,
  NV_C0_BCX_BLOCK_1_LNA_4_RISE_I                 = 6099,
  NV_C0_BCX_BLOCK_1_LNA_4_FALL_I                 = 6100,
  NV_C0_BCX_BLOCK_1_IM_LEVEL1_I                  = 6101,
  NV_C0_BCX_BLOCK_1_IM_LEVEL2_I                  = 6102,
  NV_C0_BCX_BLOCK_1_IM_LEVEL3_I                  = 6103,
  NV_C0_BCX_BLOCK_1_IM_LEVEL4_I                  = 6104,
  NV_C1_BCX_BLOCK_1_TX_CAL_CHAN_I                = 6105,
  NV_C1_BCX_BLOCK_1_RX_CAL_CHAN_I                = 6106,
  NV_C1_BCX_BLOCK_1_LNA_1_OFFSET_VS_FREQ_I       = 6107,
  NV_C1_BCX_BLOCK_1_LNA_2_OFFSET_VS_FREQ_I       = 6108,
  NV_C1_BCX_BLOCK_1_LNA_3_OFFSET_VS_FREQ_I       = 6109,
  NV_C1_BCX_BLOCK_1_LNA_4_OFFSET_VS_FREQ_I       = 6110,
  NV_C1_BCX_BLOCK_1_LNA_1_OFFSET_I               = 6111,
  NV_C1_BCX_BLOCK_1_LNA_2_OFFSET_I               = 6112,
  NV_C1_BCX_BLOCK_1_LNA_3_OFFSET_I               = 6113,
  NV_C1_BCX_BLOCK_1_LNA_4_OFFSET_I               = 6114,
  NV_C1_BCX_BLOCK_1_IM2_I_VALUE_I                = 6115,
  NV_C1_BCX_BLOCK_1_IM2_Q_VALUE_I                = 6116,
  NV_C1_BCX_BLOCK_1_VGA_GAIN_OFFSET_I            = 6117,
  NV_C1_BCX_BLOCK_1_VGA_GAIN_OFFSET_VS_FREQ_I    = 6118,
  NV_C1_BCX_BLOCK_1_IM2_TRANSCONDUCTOR_VALUE_I   = 6119,
  NV_C1_BCX_BLOCK_1_LNA_1_RISE_I                 = 6120,
  NV_C1_BCX_BLOCK_1_LNA_1_FALL_I                 = 6121,
  NV_C1_BCX_BLOCK_1_LNA_2_RISE_I                 = 6122,
  NV_C1_BCX_BLOCK_1_LNA_2_FALL_I                 = 6123,
  NV_C1_BCX_BLOCK_1_LNA_3_RISE_I                 = 6124,
  NV_C1_BCX_BLOCK_1_LNA_3_FALL_I                 = 6125,
  NV_C1_BCX_BLOCK_1_LNA_4_RISE_I                 = 6126,
  NV_C1_BCX_BLOCK_1_LNA_4_FALL_I                 = 6127,
  NV_C1_BCX_BLOCK_1_IM_LEVEL1_I                  = 6128,
  NV_C1_BCX_BLOCK_1_IM_LEVEL2_I                  = 6129,
  NV_C1_BCX_BLOCK_1_IM_LEVEL3_I                  = 6130,
  NV_C1_BCX_BLOCK_1_IM_LEVEL4_I                  = 6131,
  NV_BCX_BLOCK_1_P2_RISE_FALL_OFF_I              = 6132,
  NV_BCX_BLOCK_1_P3_RISE_FALL_OFF_I              = 6133,
  NV_BCX_BLOCK_1_HDR_P2_RISE_FALL_OFF_I          = 6134,
  NV_BCX_BLOCK_1_HDR_P3_RISE_FALL_OFF_I          = 6135,
  NV_BCX_BLOCK_VCO_COARSE_TUNE_2_I               = 6136,
  NV_C1_BCX_BLOCK_VCO_COARSE_TUNE_TABLE_I        = 6137,
  NV_C0_BCX_BLOCK_RX_CAL_CHAN_LRU_I              = 6138,
  NV_C1_BCX_BLOCK_RX_CAL_CHAN_LRU_I              = 6139,
  NV_BCX_BLOCK_HDR_P1_RISE_FALL_OFF_I            = 6140,
  NV_BCX_BLOCK_PA_DVS_VOLTAGE_I                  = 6141,
  NV_BCX_BLOCK_VCO_TUNE_2_I                      = 6142,
  NV_C0_BCX_BLOCK_IM2_LPM_1_I                    = 6143,
  NV_C0_BCX_BLOCK_IM2_LPM_2_I                    = 6144,
  NV_C0_BCX_BLOCK_INTELLICEIVER_CAL_I            = 6145,
  NV_C0_BCX_BLOCK_LNA_SWITCHPOINTS_LPM_1_I       = 6146,
  NV_C0_BCX_BLOCK_LNA_SWITCHPOINTS_LPM_2_I       = 6147,
  NV_BCX_BLOCK_ANT_QUALITY_I                     = 6148,
  NV_C0_BCX_BLOCK_INTELLICEIVER_DET_THRESH_I     = 6149,
  NV_BCX_BLOCK_TX_PDM_LIN_0_I                    = 6150,
  NV_BCX_BLOCK_TX_PDM_LIN_1_I                    = 6151,
  NV_BCX_BLOCK_TX_PDM_LIN_2_I                    = 6152,
  NV_BCX_BLOCK_TX_PDM_LIN_3_I                    = 6153,
  NV_BCX_BLOCK_TX_PDM_0_I                        = 6154,
  NV_BCX_BLOCK_TX_PDM_1_I                        = 6155,
  NV_BCX_BLOCK_TX_PDM_2_I                        = 6156,
  NV_BCX_BLOCK_TX_PDM_3_I                        = 6157,
  NV_BCX_BLOCK_TX_LIN_0_I                        = 6158,
  NV_BCX_BLOCK_TX_LIN_1_I                        = 6159,
  NV_BCX_BLOCK_TX_LIN_2_I                        = 6160,
  NV_BCX_BLOCK_TX_LIN_3_I                        = 6161,
  NV_BCX_BLOCK_PA_R_MAP_I                        = 6162,
  NV_BCX_BLOCK_TX_PWR_COMP0_I                    = 6163,
  NV_BCX_BLOCK_TX_PWR_COMP1_I                    = 6164,
  NV_BCX_BLOCK_TX_PWR_COMP2_I                    = 6165,
  NV_BCX_BLOCK_TX_PWR_COMP3_I                    = 6166,
  NV_C0_BCX_BLOCK_LO_CAL_I                       = 6167,
  NV_C0_BCX_BLOCK_IM2_CAL_I                      = 6168,
  NV_BCX_BLOCK_EXP_HDET_VS_AGC_V2_I              = 6169,
  NV_BCX_BLOCK_HDET_OFF_V2_I                     = 6170,
  NV_BCX_BLOCK_HDET_SPN_V2_I                     = 6171,
  NV_BCX_BLOCK_1_VCO_COARSE_TUNE_2_I             = 6172,
  NV_C1_BCX_BLOCK_1_VCO_COARSE_TUNE_TABLE_I      = 6173,
  NV_C0_BCX_BLOCK_1_RX_CAL_CHAN_LRU_I            = 6174,
  NV_C1_BCX_BLOCK_1_RX_CAL_CHAN_LRU_I            = 6175,
  NV_BCX_BLOCK_1_HDR_P1_RISE_FALL_OFF_I          = 6176,
  NV_BCX_BLOCK_1_PA_DVS_VOLTAGE_I                = 6177,
  NV_BCX_BLOCK_1_VCO_TUNE_2_I                    = 6178,
  NV_C0_BCX_BLOCK_1_IM2_LPM_1_I                  = 6179,
  NV_C0_BCX_BLOCK_1_IM2_LPM_2_I                  = 6180,
  NV_C0_BCX_BLOCK_1_INTELLICEIVER_CAL_I          = 6181,
  NV_C0_BCX_BLOCK_1_LNA_SWITCHPOINTS_LPM_1_I     = 6182,
  NV_C0_BCX_BLOCK_1_LNA_SWITCHPOINTS_LPM_2_I     = 6183,
  NV_BCX_BLOCK_1_ANT_QUALITY_I                   = 6184,
  NV_C0_BCX_BLOCK_1_INTELLICEIVER_DET_THRESH_I   = 6185,
  NV_BCX_BLOCK_1_TX_PDM_LIN_0_I                  = 6186,
  NV_BCX_BLOCK_1_TX_PDM_LIN_1_I                  = 6187,
  NV_BCX_BLOCK_1_TX_PDM_LIN_2_I                  = 6188,
  NV_BCX_BLOCK_1_TX_PDM_LIN_3_I                  = 6189,
  NV_BCX_BLOCK_1_TX_PDM_0_I                      = 6190,
  NV_BCX_BLOCK_1_TX_PDM_1_I                      = 6191,
  NV_BCX_BLOCK_1_TX_PDM_2_I                      = 6192,
  NV_BCX_BLOCK_1_TX_PDM_3_I                      = 6193,
  NV_BCX_BLOCK_1_TX_LIN_0_I                      = 6194,
  NV_BCX_BLOCK_1_TX_LIN_1_I                      = 6195,
  NV_BCX_BLOCK_1_TX_LIN_2_I                      = 6196,
  NV_BCX_BLOCK_1_TX_LIN_3_I                      = 6197,
  NV_BCX_BLOCK_1_PA_R_MAP_I                      = 6198,
  NV_BCX_BLOCK_1_TX_PWR_COMP0_I                  = 6199,
  NV_BCX_BLOCK_1_TX_PWR_COMP1_I                  = 6200,
  NV_BCX_BLOCK_1_TX_PWR_COMP2_I                  = 6201,
  NV_BCX_BLOCK_1_TX_PWR_COMP3_I                  = 6202,
  NV_C0_BCX_BLOCK_1_LO_CAL_I                     = 6203,
  NV_C0_BCX_BLOCK_1_IM2_CAL_I                    = 6204,
  NV_BCX_BLOCK_1_EXP_HDET_VS_AGC_V2_I            = 6205,
  NV_BCX_BLOCK_1_HDET_OFF_V2_I                   = 6206,
  NV_BCX_BLOCK_1_HDET_SPN_V2_I                   = 6207,
  NV_BCX_BLOCK_BAND_CLASS_I                      = 6208,
  NV_BCX_BLOCK_1_BAND_CLASS_I                    = 6209,
  NV_BCX_BLOCK_SUBCLASS_MASK_I                   = 6210,
  NV_BCX_BLOCK_1_SUBCLASS_MASK_I                 = 6211,
  NV_UIM_PAR_ERR_WORKAROUND_I                    = 6212,
  NV_GPS1_ER_CURVE_FIT_INTERVAL_I                = 6213,
  NV_CGPS_ER_ENABLE_I                            = 6214,
  NV_CGPS_ER_START_TIME_I                        = 6215,
  NV_CGPS_ER_SLOT_INTERVAL_I                     = 6216,
  NV_CGPS_ER_SLOT_PERIOD_I                       = 6217,
  NV_UW_FMC_NAT_REFRESH_TIMER_I                  = 6218,
  NV_BC0_SUBCLASS_MASK_I                         = 6219,
  NV_BC1_SUBCLASS_MASK_I                         = 6220,
  NV_BC2_SUBCLASS_MASK_I                         = 6221,
  NV_BC3_SUBCLASS_MASK_I                         = 6222,
  NV_BC4_SUBCLASS_MASK_I                         = 6223,
  NV_BC5_SUBCLASS_MASK_I                         = 6224,
  NV_BC6_SUBCLASS_MASK_I                         = 6225,
  NV_BC7_SUBCLASS_MASK_I                         = 6226,
  NV_BC8_SUBCLASS_MASK_I                         = 6227,
  NV_BC9_SUBCLASS_MASK_I                         = 6228,
  NV_BC10_SUBCLASS_MASK_I                        = 6229,
  NV_BC11_SUBCLASS_MASK_I                        = 6230,
  NV_BC12_SUBCLASS_MASK_I                        = 6231,
  NV_BC13_SUBCLASS_MASK_I                        = 6232,
  NV_BC14_SUBCLASS_MASK_I                        = 6233,
  NV_BC15_SUBCLASS_MASK_I                        = 6234,
  NV_HS_USB_USE_PMIC_OTG_COMPARATORS_I           = 6235,
  NV_RFR_MULTI_CHIPSET_1_BB_FILTER_I             = 6236,
  NV_C1_RFR_MULTI_CHIPSET_1_BB_FILTER_I          = 6237,
  NV_RFR_MULTI_CHIPSET_1_IQ_LINE_RESISTOR_I      = 6238,
  NV_HS_USB_NUMBER_OF_SDCC_LUNS_I                = 6239,
  NV_THERMAL_MONITOR_THRESHOLDS_I                = 6240,
  NV_THERMAL_MONITOR_TIMERS_I                    = 6241,
  NV_DELTA_TX_POWER_I                            = 6242,
  NV_THERMAL_CURRENT_MONITOR_CONFIG_I            = 6243,
  NV_THERMAL_MONITOR_MAX_TEMP_I                  = 6244,
  NV_PPP_EAP_SHARED_SECRET_I                     = 6245,
  NV_PPP_EAP_USER_ID_I                           = 6246,
  NV_PPP_VSNCP_CONFIG_DATA_I                     = 6247,
  NV_EHRPD_ENABLED_I                             = 6248,
  NV_WLAN_ATHEROS_SPECIFIC_CFG_I                 = 6249,
  NV_GAN_MODE_PREFERENCE_I                       = 6250,
  NV_IWLAN_ENFORCE_PEER_CERT_AUTH_I              = 6251,
  NV_LPM_PERSISTENCE_I                           = 6252,
  NV_CSIM_SUPPORT_I                              = 6253,
  NV_QMI_ROAM_PREF_I                             = 6254,
  NV_UW_FMC_V4_MTU_I                             = 6255,
  NV_AAGPS_GLOBAL_ALTITUDE_I                     = 6256,
  NV_AAGPS_GLOBAL_ALT_UNC_I                      = 6257,
  NV_WWWAN_CONFIG_I                              = 6258,
  NV_HS_USB_HOST_MODE_ENABLED_I                  = 6259,
  NV_WLAN_CPU_FLOW_CONTROL_CFG_I                 = 6260,
  NV_ADSP_DYN_CLOCK_VOLTAGE_I                    = 6261,
  NV_MTPDP_APP_I                                 = 6262,
  NV_AAGPS_ACQUISITION_TIMER_I                   = 6263,
  NV_CGPS_MINIMUM_GPS_WEEK_NUMBER_I              = 6264,
  NV_CURRENT_MONITOR_THRESHOLDS_I                = 6265,
  NV_THERMAL_CURRENT_MONITOR_CFG_MITIGATION_I    = 6266,
  NV_CGPS_QWIP_LOC_ENGINE_CONFIG_I               = 6267,
  NV_CGPS_QWIP_SERVER_CONFIG_I                   = 6268,
  NV_CGPS_QWIP_TILE_CONFIG_I                     = 6269,
  NV_CGPS_QWIP_RESERVED_1_I                      = 6270,
  NV_CGPS_QWIP_RESERVED_2_I                      = 6271,
  NV_CGPS_XTRA_T_CONTROL_I                       = 6272,
  NV_GPS_DEFAULT_OPERATING_MODE_I                = 6273,
  NV_GPS_DEFAULT_TBF_I                           = 6274,
  NV_BC0_INTELLICEIVER_RC_TUNE_CAL_I             = 6275,
  NV_BC1_INTELLICEIVER_RC_TUNE_CAL_I             = 6276,
  NV_BC2_INTELLICEIVER_RC_TUNE_CAL_I             = 6277,
  NV_BC3_INTELLICEIVER_RC_TUNE_CAL_I             = 6278,
  NV_BC4_INTELLICEIVER_RC_TUNE_CAL_I             = 6279,
  NV_BC5_INTELLICEIVER_RC_TUNE_CAL_I             = 6280,
  NV_BC6_INTELLICEIVER_RC_TUNE_CAL_I             = 6281,
  NV_BC7_INTELLICEIVER_RC_TUNE_CAL_I             = 6282,
  NV_BC8_INTELLICEIVER_RC_TUNE_CAL_I             = 6283,
  NV_BC9_INTELLICEIVER_RC_TUNE_CAL_I             = 6284,
  NV_BC10_INTELLICEIVER_RC_TUNE_CAL_I            = 6285,
  NV_BC11_INTELLICEIVER_RC_TUNE_CAL_I            = 6286,
  NV_BC12_INTELLICEIVER_RC_TUNE_CAL_I            = 6287,
  NV_BC13_INTELLICEIVER_RC_TUNE_CAL_I            = 6288,
  NV_BC14_INTELLICEIVER_RC_TUNE_CAL_I            = 6289,
  NV_BC15_INTELLICEIVER_RC_TUNE_CAL_I            = 6290,
  NV_BCX_BLOCK_INTELLICEIVER_RC_TUNE_CAL_I       = 6291,
  NV_BCX_BLOCK_1_INTELLICEIVER_RC_TUNE_CAL_I     = 6292,
  NV_ADSP_PWRC_DISABLE_I                         = 6293,
  NV_GSM_850_LINEAR_ENVDC_CAL_VAL_I              = 6294,
  NV_GSM_900_LINEAR_ENVDC_CAL_VAL_I              = 6295,
  NV_GSM_1800_LINEAR_ENVDC_CAL_VAL_I             = 6296,
  NV_GSM_1900_LINEAR_ENVDC_CAL_VAL_I             = 6297,
  NV_HS_USB_RECONNECT_ON_RESET_DURING_SUSPEND_I  = 6298,
  NV_MF_RSSI_CAL_VS_FREQ_6_I                     = 6299,
  NV_MF_CHAN_SUPPORT_L_BAND_I                    = 6300,
  NV_MF_RSSI_CAL_VS_L_BAND_FREQ_0_I              = 6301,
  NV_MF_RSSI_CAL_VS_L_BAND_FREQ_1_I              = 6302,
  NV_MF_RSSI_CAL_VS_L_BAND_FREQ_2_I              = 6303,
  NV_MF_RSSI_CAL_VS_L_BAND_FREQ_3_I              = 6304,
  NV_MF_RSSI_CAL_VS_L_BAND_FREQ_4_I              = 6305,
  NV_MF_RSSI_CAL_VS_L_BAND_FREQ_5_I              = 6306,
  NV_MF_RSSI_CAL_VS_L_BAND_FREQ_6_I              = 6307,
  NV_MF_CHAN_SUPPORT_VHF_I                       = 6308,
  NV_MF_RSSI_CAL_VS_VHF_FREQ_0_I                 = 6309,
  NV_MF_RSSI_CAL_VS_VHF_FREQ_1_I                 = 6310,
  NV_MF_RSSI_CAL_VS_VHF_FREQ_2_I                 = 6311,
  NV_MF_RSSI_CAL_VS_VHF_FREQ_3_I                 = 6312,
  NV_MF_RSSI_CAL_VS_VHF_FREQ_4_I                 = 6313,
  NV_MF_RSSI_CAL_VS_VHF_FREQ_5_I                 = 6314,
  NV_MF_RSSI_CAL_VS_VHF_FREQ_6_I                 = 6315,
  NV_MF_PLATFORM_CONFIG_I                        = 6316,
  NV_MBP_RF_ISDBT_CAL_FREQ_I                     = 6317,
  NV_MBP_RF_ISDBT_GS0_CAL_I                      = 6318,
  NV_MBP_RF_ISDBT_GS1_CAL_I                      = 6319,
  NV_MBP_RF_ISDBT_GS2_CAL_I                      = 6320,
  NV_MBP_RF_ISDBT_GS3_CAL_I                      = 6321,
  NV_MBP_RF_ISDBT_GS4_CAL_I                      = 6322,
  NV_MBP_RF_ISDBT_GS5_CAL_I                      = 6323,
  NV_MBP_RF_ISDBT_GS6_CAL_I                      = 6324,
  NV_MBP_RF_DVBH_GS6_CAL_I                       = 6325,
  NV_RTP_MANAGER_MAX_DEJITTER_DELAY_I            = 6326,
  NV_HS_USB_DISABLE_SLEEP_VOTING_I               = 6327,
  NV_WB_CAL_PASSED_I                             = 6328,
  NV_ALL_OUTLIERS_I                              = 6329,
  NV_RG_ADJ_RATIO_I                              = 6330,
  NV_BG_ADJ_RATIO_I                              = 6331,
  NV_RG_HIGH_TOL_I                               = 6332,
  NV_RG_LOW_TOL_I                                = 6333,
  NV_BG_HIGH_TOL_I                               = 6334,
  NV_BG_LOW_TOL_I                                = 6335,
  NV_UIM_ICCID_TPL_I                             = 6336,
  NV_EHRPD_MILENAGE_OP_I                         = 6337,
  NV_EHRPD_IMSI_I                                = 6338,
  NV_CGPS_ME_SHALLOW_INTEG_STAGE1_I              = 6339,
  NV_CGPS_ME_SHALLOW_INTEG_STAGE2_I              = 6340,
  NV_CGPS_ME_SHALLOW_INTEG_STAGE3_I              = 6341,
  NV_GSM_850_LINEAR_PA_R0_TEMP_COMP_I            = 6342,
  NV_GSM_850_LINEAR_PA_R1_TEMP_COMP_I            = 6343,
  NV_GSM_850_LINEAR_PA_R2_TEMP_COMP_I            = 6344,
  NV_GSM_850_LINEAR_PA_R3_TEMP_COMP_I            = 6345,
  NV_GSM_900_LINEAR_PA_R0_TEMP_COMP_I            = 6346,
  NV_GSM_900_LINEAR_PA_R1_TEMP_COMP_I            = 6347,
  NV_GSM_900_LINEAR_PA_R2_TEMP_COMP_I            = 6348,
  NV_GSM_900_LINEAR_PA_R3_TEMP_COMP_I            = 6349,
  NV_GSM_1800_LINEAR_PA_R0_TEMP_COMP_I           = 6350,
  NV_GSM_1800_LINEAR_PA_R1_TEMP_COMP_I           = 6351,
  NV_GSM_1800_LINEAR_PA_R2_TEMP_COMP_I           = 6352,
  NV_GSM_1800_LINEAR_PA_R3_TEMP_COMP_I           = 6353,
  NV_GSM_1900_LINEAR_PA_R0_TEMP_COMP_I           = 6354,
  NV_GSM_1900_LINEAR_PA_R1_TEMP_COMP_I           = 6355,
  NV_GSM_1900_LINEAR_PA_R2_TEMP_COMP_I           = 6356,
  NV_GSM_1900_LINEAR_PA_R3_TEMP_COMP_I           = 6357,
  NV_GSM_850_LINEAR_PA_R0_VBATT_LO_COMP_I        = 6358,
  NV_GSM_850_LINEAR_PA_R0_VBATT_HI_COMP_I        = 6359,
  NV_GSM_850_LINEAR_PA_R1_VBATT_LO_COMP_I        = 6360,
  NV_GSM_850_LINEAR_PA_R1_VBATT_HI_COMP_I        = 6361,
  NV_GSM_850_LINEAR_PA_R2_VBATT_LO_COMP_I        = 6362,
  NV_GSM_850_LINEAR_PA_R2_VBATT_HI_COMP_I        = 6363,
  NV_GSM_850_LINEAR_PA_R3_VBATT_LO_COMP_I        = 6364,
  NV_GSM_850_LINEAR_PA_R3_VBATT_HI_COMP_I        = 6365,
  NV_GSM_900_LINEAR_PA_R0_VBATT_LO_COMP_I        = 6366,
  NV_GSM_900_LINEAR_PA_R0_VBATT_HI_COMP_I        = 6367,
  NV_GSM_900_LINEAR_PA_R1_VBATT_LO_COMP_I        = 6368,
  NV_GSM_900_LINEAR_PA_R1_VBATT_HI_COMP_I        = 6369,
  NV_GSM_900_LINEAR_PA_R2_VBATT_LO_COMP_I        = 6370,
  NV_GSM_900_LINEAR_PA_R2_VBATT_HI_COMP_I        = 6371,
  NV_GSM_900_LINEAR_PA_R3_VBATT_LO_COMP_I        = 6372,
  NV_GSM_900_LINEAR_PA_R3_VBATT_HI_COMP_I        = 6373,
  NV_GSM_1800_LINEAR_PA_R0_VBATT_LO_COMP_I       = 6374,
  NV_GSM_1800_LINEAR_PA_R0_VBATT_HI_COMP_I       = 6375,
  NV_GSM_1800_LINEAR_PA_R1_VBATT_LO_COMP_I       = 6376,
  NV_GSM_1800_LINEAR_PA_R1_VBATT_HI_COMP_I       = 6377,
  NV_GSM_1800_LINEAR_PA_R2_VBATT_LO_COMP_I       = 6378,
  NV_GSM_1800_LINEAR_PA_R2_VBATT_HI_COMP_I       = 6379,
  NV_GSM_1800_LINEAR_PA_R3_VBATT_LO_COMP_I       = 6380,
  NV_GSM_1800_LINEAR_PA_R3_VBATT_HI_COMP_I       = 6381,
  NV_GSM_1900_LINEAR_PA_R0_VBATT_LO_COMP_I       = 6382,
  NV_GSM_1900_LINEAR_PA_R0_VBATT_HI_COMP_I       = 6383,
  NV_GSM_1900_LINEAR_PA_R1_VBATT_LO_COMP_I       = 6384,
  NV_GSM_1900_LINEAR_PA_R1_VBATT_HI_COMP_I       = 6385,
  NV_GSM_1900_LINEAR_PA_R2_VBATT_LO_COMP_I       = 6386,
  NV_GSM_1900_LINEAR_PA_R2_VBATT_HI_COMP_I       = 6387,
  NV_GSM_1900_LINEAR_PA_R3_VBATT_LO_COMP_I       = 6388,
  NV_GSM_1900_LINEAR_PA_R3_VBATT_HI_COMP_I       = 6389,
  NV_WCDMA_1800_RXF_MIS_COMP_A_COEFF_I           = 6390,
  NV_WCDMA_1800_RXF_MIS_COMP_B_COEFF_I           = 6391,
  NV_C1_WCDMA_1800_RXF_MIS_COMP_A_COEFF_I        = 6392,
  NV_C1_WCDMA_1800_RXF_MIS_COMP_B_COEFF_I        = 6393,
  NV_WCDMA_1800_RXF_ICI_I_COEF0_1_I              = 6394,
  NV_WCDMA_1800_RXF_ICI_I_COEF2_3_I              = 6395,
  NV_WCDMA_1800_RXF_ICI_I_COEF4_5_I              = 6396,
  NV_WCDMA_1800_RXF_ICI_I_COEF6_7_I              = 6397,
  NV_WCDMA_1800_RXF_ICI_I_COEF8_9_I              = 6398,
  NV_WCDMA_1800_RXF_ICI_I_COEF10_11_I            = 6399,
  NV_WCDMA_1800_RXF_ICI_I_COEF12_13_I            = 6400,
  NV_WCDMA_1800_RXF_ICI_I_COEF14_15_I            = 6401,
  NV_WCDMA_1800_RXF_ICI_Q_COEF0_1_I              = 6402,
  NV_WCDMA_1800_RXF_ICI_Q_COEF2_3_I              = 6403,
  NV_WCDMA_1800_RXF_ICI_Q_COEF4_5_I              = 6404,
  NV_WCDMA_1800_RXF_ICI_Q_COEF6_7_I              = 6405,
  NV_WCDMA_1800_RXF_ICI_Q_COEF8_9_I              = 6406,
  NV_WCDMA_1800_RXF_ICI_Q_COEF10_11_I            = 6407,
  NV_WCDMA_1800_RXF_ICI_Q_COEF12_13_I            = 6408,
  NV_WCDMA_1800_RXF_ICI_Q_COEF14_15_I            = 6409,
  NV_WCDMA_1800_RXF_ICI_IQ_TRUNC_I               = 6410,
  NV_C1_WCDMA_1800_RXF_ICI_I_COEF0_1_I           = 6411,
  NV_C1_WCDMA_1800_RXF_ICI_I_COEF2_3_I           = 6412,
  NV_C1_WCDMA_1800_RXF_ICI_I_COEF4_5_I           = 6413,
  NV_C1_WCDMA_1800_RXF_ICI_I_COEF6_7_I           = 6414,
  NV_C1_WCDMA_1800_RXF_ICI_I_COEF8_9_I           = 6415,
  NV_C1_WCDMA_1800_RXF_ICI_I_COEF10_11_I         = 6416,
  NV_C1_WCDMA_1800_RXF_ICI_I_COEF12_13_I         = 6417,
  NV_C1_WCDMA_1800_RXF_ICI_I_COEF14_15_I         = 6418,
  NV_C1_WCDMA_1800_RXF_ICI_Q_COEF0_1_I           = 6419,
  NV_C1_WCDMA_1800_RXF_ICI_Q_COEF2_3_I           = 6420,
  NV_C1_WCDMA_1800_RXF_ICI_Q_COEF4_5_I           = 6421,
  NV_C1_WCDMA_1800_RXF_ICI_Q_COEF6_7_I           = 6422,
  NV_C1_WCDMA_1800_RXF_ICI_Q_COEF8_9_I           = 6423,
  NV_C1_WCDMA_1800_RXF_ICI_Q_COEF10_11_I         = 6424,
  NV_C1_WCDMA_1800_RXF_ICI_Q_COEF12_13_I         = 6425,
  NV_C1_WCDMA_1800_RXF_ICI_Q_COEF14_15_I         = 6426,
  NV_C1_WCDMA_1800_RXF_ICI_IQ_TRUNC_I            = 6427,
  NV_WLAN_UUID_I                                 = 6428,
  NV_HDR_IS683A_SCAN_LIST_I                      = 6429,
  NV_CGPS_VEL_UNC_MASK_I                         = 6430,
  NV_WCDMA_900_RXF_MIS_COMP_A_COEFF_I            = 6431,
  NV_WCDMA_900_RXF_MIS_COMP_B_COEFF_I            = 6432,
  NV_C1_WCDMA_900_RXF_MIS_COMP_A_COEFF_I         = 6433,
  NV_C1_WCDMA_900_RXF_MIS_COMP_B_COEFF_I         = 6434,
  NV_WCDMA_900_RXF_ICI_I_COEF0_1_I               = 6435,
  NV_WCDMA_900_RXF_ICI_I_COEF2_3_I               = 6436,
  NV_WCDMA_900_RXF_ICI_I_COEF4_5_I               = 6437,
  NV_WCDMA_900_RXF_ICI_I_COEF6_7_I               = 6438,
  NV_WCDMA_900_RXF_ICI_I_COEF8_9_I               = 6439,
  NV_WCDMA_900_RXF_ICI_I_COEF10_11_I             = 6440,
  NV_WCDMA_900_RXF_ICI_I_COEF12_13_I             = 6441,
  NV_WCDMA_900_RXF_ICI_I_COEF14_15_I             = 6442,
  NV_WCDMA_900_RXF_ICI_Q_COEF0_1_I               = 6443,
  NV_WCDMA_900_RXF_ICI_Q_COEF2_3_I               = 6444,
  NV_WCDMA_900_RXF_ICI_Q_COEF4_5_I               = 6445,
  NV_WCDMA_900_RXF_ICI_Q_COEF6_7_I               = 6446,
  NV_WCDMA_900_RXF_ICI_Q_COEF8_9_I               = 6447,
  NV_WCDMA_900_RXF_ICI_Q_COEF10_11_I             = 6448,
  NV_WCDMA_900_RXF_ICI_Q_COEF12_13_I             = 6449,
  NV_WCDMA_900_RXF_ICI_Q_COEF14_15_I             = 6450,
  NV_WCDMA_900_RXF_ICI_IQ_TRUNC_I                = 6451,
  NV_C1_WCDMA_900_RXF_ICI_I_COEF0_1_I            = 6452,
  NV_C1_WCDMA_900_RXF_ICI_I_COEF2_3_I            = 6453,
  NV_C1_WCDMA_900_RXF_ICI_I_COEF4_5_I            = 6454,
  NV_C1_WCDMA_900_RXF_ICI_I_COEF6_7_I            = 6455,
  NV_C1_WCDMA_900_RXF_ICI_I_COEF8_9_I            = 6456,
  NV_C1_WCDMA_900_RXF_ICI_I_COEF10_11_I          = 6457,
  NV_C1_WCDMA_900_RXF_ICI_I_COEF12_13_I          = 6458,
  NV_C1_WCDMA_900_RXF_ICI_I_COEF14_15_I          = 6459,
  NV_C1_WCDMA_900_RXF_ICI_Q_COEF0_1_I            = 6460,
  NV_C1_WCDMA_900_RXF_ICI_Q_COEF2_3_I            = 6461,
  NV_C1_WCDMA_900_RXF_ICI_Q_COEF4_5_I            = 6462,
  NV_C1_WCDMA_900_RXF_ICI_Q_COEF6_7_I            = 6463,
  NV_C1_WCDMA_900_RXF_ICI_Q_COEF8_9_I            = 6464,
  NV_C1_WCDMA_900_RXF_ICI_Q_COEF10_11_I          = 6465,
  NV_C1_WCDMA_900_RXF_ICI_Q_COEF12_13_I          = 6466,
  NV_C1_WCDMA_900_RXF_ICI_Q_COEF14_15_I          = 6467,
  NV_C1_WCDMA_900_RXF_ICI_IQ_TRUNC_I             = 6468,
  NV_CGPS_QWIP_HEPE_PARAMS_I                     = 6469,
  NV_CACHE_WT_I                                  = 6470,
  NV_QDJ_DEQUEUE_LOG_ENABLED_I                   = 6471,
  NV_GSM_850_LINEAR_TX_GAIN_PARAM_I              = 6472,
  NV_GSM_1800_LINEAR_TX_GAIN_PARAM_I             = 6473,
  NV_GSM_1900_LINEAR_TX_GAIN_PARAM_I             = 6474,
  NV_EDGE_850_LINEAR_TX_GAIN_PARAM_I             = 6475,
  NV_EDGE_1800_LINEAR_TX_GAIN_PARAM_I            = 6476,
  NV_EDGE_1900_LINEAR_TX_GAIN_PARAM_I            = 6477,
  NV_PDP_DEACTIVATE_BEFORE_DETACH_SUPPORTED_I    = 6478,
  NV_STA_TEST_MODE_I                             = 6479,
  NV_MIPV6_SEC_HA_I                              = 6480,
  NV_MIPV6_HOA_PREFIX_LEN_I                      = 6481,
  NV_WCDMA_QICE_CTRL_I                           = 6482,
  NV_WCDMA_QICE_LMMSE_ORIDE_I                    = 6483,
  NV_WCDMA_QICE_SF16_ORIDE_I                     = 6484,
  NV_WCDMA_QICE_SF16_NONLINEAR_ORIDE_I           = 6485,
  NV_CGPS_UTC_GPS_TIME_OFFSET_I                  = 6486,
  NV_BT_QSOC_NVM_MODE_I                          = 6487,
  NV_BT_QSOC_CLASS_TYPE_I                        = 6488,
  NV_UNDP_FEATURE_CONFIGS_I                      = 6489,
  NV_LTE_B13_RX_CAL_CHAN_I                       = 6490,
  NV_LTE_B13_RX_DELAY_I                          = 6491,
  NV_LTE_B13_LNA_RANGE_RISE_FALL_I               = 6492,
  NV_LTE_B13_NONBYPASS_BYPASS_TIMER_I            = 6493,
  NV_LTE_B13_IM_LEVEL_I                          = 6494,
  NV_LTE_B13_RX_GAIN_VS_TEMP_I                   = 6495,
  NV_LTE_B13_RX_GAIN_I                           = 6496,
  NV_LTE_B13_RX_GAIN_VS_FREQ_I                   = 6497,
  NV_LTE_B13_LNA_PHASE_CTRL_I                    = 6498,
  NV_LTE_B13_IM2_VALUES_I                        = 6499,
  NV_LTE_B13_RXF_MISMATCH_COMP_I                 = 6500,
  NV_LTE_B13_ENC_BTF_I                           = 6501,
  NV_LTE_B13_MAX_TX_POWER_I                      = 6502,
  NV_LTE_B13_AGC_PA_ON_RISE_FALL_DELAY_I         = 6503,
  NV_LTE_B13_AGC_TX_ON_RISE_FALL_DELAY_I         = 6504,
  NV_LTE_B13_PA_GAIN_UP_DOWN_TIME_I              = 6505,
  NV_LTE_B13_TX_ROT_ANGLE_PA_STATE_I             = 6506,
  NV_LTE_B13_PA_COMPENSATE_UP_DOWN_I             = 6507,
  NV_LTE_B13_TX_LIN_VS_TEMP_I                    = 6508,
  NV_LTE_B13_PA_RANGE_MAP_I                      = 6509,
  NV_LTE_B13_TIMER_HYSTERISIS_I                  = 6510,
  NV_LTE_B13_PA_RISE_FALL_THRESHOLD_I            = 6511,
  NV_LTE_B13_TX_CAL_CHAN_I                       = 6512,
  NV_LTE_B13_TX_LIMIT_VS_TEMP_I                  = 6513,
  NV_LTE_B13_MPR_BASED_PA_SWITCHPOINTS_SHIFT_I   = 6514,
  NV_LTE_B13_TX_MPR_BACKOFF_I                    = 6515,
  NV_LTE_B13_TX_DIGITAL_GAIN_COMP_I              = 6516,
  NV_LTE_B13_TX_AGC_OFFSET_I                     = 6517,
  NV_LTE_B13_TX_LIN_MASTER_0_I                   = 6518,
  NV_LTE_B13_TX_LIN_MASTER_1_I                   = 6519,
  NV_LTE_B13_TX_LIN_MASTER_2_I                   = 6520,
  NV_LTE_B13_TX_LIN_MASTER_3_I                   = 6521,
  NV_LTE_B13_TX_GAIN_INDEX_0_I                   = 6522,
  NV_LTE_B13_TX_GAIN_INDEX_1_I                   = 6523,
  NV_LTE_B13_TX_GAIN_INDEX_2_I                   = 6524,
  NV_LTE_B13_TX_GAIN_INDEX_3_I                   = 6525,
  NV_LTE_B13_TX_COMP_VS_FREQ_I                   = 6526,
  NV_LTE_B13_EXP_HDET_VS_AGC_I                   = 6527,
  NV_LTE_B13_TX_LIMIT_VS_FREQ_I                  = 6528,
  NV_LTE_B13_HDET_OFF_SPAN_I                     = 6529,
  NV_LTE_B13_ANTSEL_I                            = 6530,
  NV_LTE_B13_C1_ANTSEL_I                         = 6531,
  NV_LTE_B13_C1_NONBYPASS_BYPASS_TIMER_I         = 6532,
  NV_LTE_B13_C1_LNA_RANGE_RISE_FALL_I            = 6533,
  NV_LTE_B13_C1_IM_LEVEL_I                       = 6534,
  NV_LTE_B13_C1_RX_GAIN_VS_TEMP_I                = 6535,
  NV_LTE_B13_C1_LNA_PHASE_CTRL_I                 = 6536,
  NV_LTE_B13_C1_RX_GAIN_I                        = 6537,
  NV_LTE_B13_C1_RX_GAIN_VS_FREQ_I                = 6538,
  NV_LTE_B13_C1_IM2_VALUES_I                     = 6539,
  NV_LTE_B13_C1_RX_CAL_CHAN_I                    = 6540,
  NV_LTE_B7_NONBYPASS_BYPASS_TIMER_I             = 6541,
  NV_LTE_B7_RX_DELAY_I                           = 6542,
  NV_LTE_B7_RX_CAL_CHAN_I                        = 6543,
  NV_LTE_B7_LNA_RANGE_RISE_FALL_I                = 6544,
  NV_LTE_B7_IM_LEVEL_I                           = 6545,
  NV_LTE_B7_RX_GAIN_VS_TEMP_I                    = 6546,
  NV_LTE_B7_RX_GAIN_I                            = 6547,
  NV_LTE_B7_RX_GAIN_VS_FREQ_I                    = 6548,
  NV_LTE_B7_LNA_PHASE_CTRL_I                     = 6549,
  NV_LTE_B7_IM2_VALUES_I                         = 6550,
  NV_LTE_B7_RXF_MISMATCH_COMP_I                  = 6551,
  NV_LTE_B7_ENC_BTF_I                            = 6552,
  NV_LTE_B7_MAX_TX_POWER_I                       = 6553,
  NV_LTE_B7_AGC_PA_ON_RISE_FALL_DELAY_I          = 6554,
  NV_LTE_B7_AGC_TX_ON_RISE_FALL_DELAY_I          = 6555,
  NV_LTE_B7_PA_GAIN_UP_DOWN_TIME_I               = 6556,
  NV_LTE_B7_TX_ROT_ANGLE_PA_STATE_I              = 6557,
  NV_LTE_B7_PA_COMPENSATE_UP_DOWN_I              = 6558,
  NV_LTE_B7_TX_LIN_VS_TEMP_I                     = 6559,
  NV_LTE_B7_PA_RANGE_MAP_I                       = 6560,
  NV_LTE_B7_TIMER_HYSTERISIS_I                   = 6561,
  NV_LTE_B7_PA_RISE_FALL_THRESHOLD_I             = 6562,
  NV_LTE_B7_TX_CAL_CHAN_I                        = 6563,
  NV_LTE_B7_TX_LIMIT_VS_TEMP_I                   = 6564,
  NV_LTE_B7_MPR_BASED_PA_SWITCHPOINTS_SHIFT_I    = 6565,
  NV_LTE_B7_TX_MPR_BACKOFF_I                     = 6566,
  NV_LTE_B7_TX_DIGITAL_GAIN_COMP_I               = 6567,
  NV_LTE_B7_TX_AGC_OFFSET_I                      = 6568,
  NV_LTE_B7_TX_LIN_MASTER_0_I                    = 6569,
  NV_LTE_B7_TX_LIN_MASTER_1_I                    = 6570,
  NV_LTE_B7_TX_LIN_MASTER_2_I                    = 6571,
  NV_LTE_B7_TX_LIN_MASTER_3_I                    = 6572,
  NV_LTE_B7_TX_GAIN_INDEX_0_I                    = 6573,
  NV_LTE_B7_TX_GAIN_INDEX_1_I                    = 6574,
  NV_LTE_B7_TX_GAIN_INDEX_2_I                    = 6575,
  NV_LTE_B7_TX_GAIN_INDEX_3_I                    = 6576,
  NV_LTE_B7_TX_COMP_VS_FREQ_I                    = 6577,
  NV_LTE_B7_EXP_HDET_VS_AGC_I                    = 6578,
  NV_LTE_B7_TX_LIMIT_VS_FREQ_I                   = 6579,
  NV_LTE_B7_HDET_OFF_SPAN_I                      = 6580,
  NV_LTE_B7_ANTSEL_I                             = 6581,
  NV_LTE_B7_C1_ANTSEL_I                          = 6582,
  NV_LTE_B7_C1_NONBYPASS_BYPASS_TIMER_I          = 6583,
  NV_LTE_B7_C0_C1_DELAY_I                        = 6584,
  NV_LTE_B13_C0_C1_DELAY_I                       = 6585,
  NV_LTE_B7_C1_LNA_RANGE_RISE_FALL_I             = 6586,
  NV_LTE_B7_C1_IM_LEVEL_I                        = 6587,
  NV_LTE_B7_C1_RX_GAIN_VS_TEMP_I                 = 6588,
  NV_LTE_B7_C1_LNA_PHASE_CTRL_I                  = 6589,
  NV_LTE_B7_C1_RX_GAIN_I                         = 6590,
  NV_LTE_B7_C1_RX_GAIN_VS_FREQ_I                 = 6591,
  NV_LTE_B7_C1_IM2_VALUES_I                      = 6592,
  NV_LTE_B7_C1_RX_CAL_CHAN_I                     = 6593,
  NV_LTE_B17_NONBYPASS_BYPASS_TIMER_I            = 6594,
  NV_LTE_B17_RX_DELAY_I                          = 6595,
  NV_LTE_B17_RX_CAL_CHAN_I                       = 6596,
  NV_LTE_B17_LNA_RANGE_RISE_FALL_I               = 6597,
  NV_LTE_B17_IM_LEVEL_I                          = 6598,
  NV_LTE_B17_RX_GAIN_VS_TEMP_I                   = 6599,
  NV_LTE_B17_RX_GAIN_I                           = 6600,
  NV_LTE_B17_RX_GAIN_VS_FREQ_I                   = 6601,
  NV_LTE_B17_LNA_PHASE_CTRL_I                    = 6602,
  NV_LTE_B17_IM2_VALUES_I                        = 6603,
  NV_LTE_B17_RXF_MISMATCH_COMP_I                 = 6604,
  NV_LTE_B17_ENC_BTF_I                           = 6605,
  NV_LTE_B17_MAX_TX_POWER_I                      = 6606,
  NV_LTE_B17_AGC_PA_ON_RISE_FALL_DELAY_I         = 6607,
  NV_LTE_B17_AGC_TX_ON_RISE_FALL_DELAY_I         = 6608,
  NV_LTE_B17_PA_GAIN_UP_DOWN_TIME_I              = 6609,
  NV_LTE_B17_TX_ROT_ANGLE_PA_STATE_I             = 6610,
  NV_LTE_B17_PA_COMPENSATE_UP_DOWN_I             = 6611,
  NV_LTE_B17_TX_LIN_VS_TEMP_I                    = 6612,
  NV_LTE_B17_PA_RANGE_MAP_I                      = 6613,
  NV_LTE_B17_TIMER_HYSTERISIS_I                  = 6614,
  NV_LTE_B17_PA_RISE_FALL_THRESHOLD_I            = 6615,
  NV_LTE_B17_TX_CAL_CHAN_I                       = 6616,
  NV_LTE_B17_TX_LIMIT_VS_TEMP_I                  = 6617,
  NV_LTE_B17_TX_LIN_MASTER_0_I                   = 6618,
  NV_LTE_B17_MPR_BASED_PA_SWITCHPOINTS_SHIFT_I   = 6619,
  NV_LTE_B17_TX_MPR_BACKOFF_I                    = 6620,
  NV_LTE_B17_TX_DIGITAL_GAIN_COMP_I              = 6621,
  NV_LTE_B17_TX_AGC_OFFSET_I                     = 6622,
  NV_LTE_B17_TX_LIN_MASTER_1_I                   = 6623,
  NV_LTE_B17_TX_LIN_MASTER_2_I                   = 6624,
  NV_LTE_B17_TX_LIN_MASTER_3_I                   = 6625,
  NV_LTE_B17_TX_GAIN_INDEX_0_I                   = 6626,
  NV_LTE_B17_TX_GAIN_INDEX_1_I                   = 6627,
  NV_LTE_B17_TX_GAIN_INDEX_2_I                   = 6628,
  NV_LTE_B17_TX_GAIN_INDEX_3_I                   = 6629,
  NV_LTE_B17_TX_COMP_VS_FREQ_I                   = 6630,
  NV_LTE_B17_EXP_HDET_VS_AGC_I                   = 6631,
  NV_LTE_B17_TX_LIMIT_VS_FREQ_I                  = 6632,
  NV_LTE_B17_HDET_OFF_SPAN_I                     = 6633,
  NV_LTE_B17_ANTSEL_I                            = 6634,
  NV_LTE_B17_C1_ANTSEL_I                         = 6635,
  NV_LTE_B17_C0_C1_DELAY_I                       = 6636,
  NV_LTE_B17_C1_LNA_RANGE_RISE_FALL_I            = 6637,
  NV_LTE_B17_C1_IM_LEVEL_I                       = 6638,
  NV_LTE_B17_C1_RX_GAIN_VS_TEMP_I                = 6639,
  NV_LTE_B17_C1_LNA_PHASE_CTRL_I                 = 6640,
  NV_LTE_B17_C1_RX_GAIN_I                        = 6641,
  NV_LTE_B17_C1_RX_GAIN_VS_FREQ_I                = 6642,
  NV_LTE_B17_C1_IM2_VALUES_I                     = 6643,
  NV_LTE_B17_C1_RX_CAL_CHAN_I                    = 6644,
  NV_LTE_B17_C1_NONBYPASS_BYPASS_TIMER_I         = 6645,
  NV_LTE_B40_NONBYPASS_BYPASS_TIMER_I            = 6646,
  NV_LTE_B40_RX_DELAY_I                          = 6647,
  NV_LTE_B40_RX_CAL_CHAN_I                       = 6648,
  NV_LTE_B40_LNA_RANGE_RISE_FALL_I               = 6649,
  NV_LTE_B40_IM_LEVEL_I                          = 6650,
  NV_LTE_B40_RX_GAIN_VS_TEMP_I                   = 6651,
  NV_LTE_B40_RX_GAIN_I                           = 6652,
  NV_LTE_B40_RX_GAIN_VS_FREQ_I                   = 6653,
  NV_LTE_B40_LNA_PHASE_CTRL_I                    = 6654,
  NV_LTE_B40_IM2_VALUES_I                        = 6655,
  NV_LTE_B40_RXF_MISMATCH_COMP_I                 = 6656,
  NV_LTE_B40_ENC_BTF_I                           = 6657,
  NV_LTE_B40_MAX_TX_POWER_I                      = 6658,
  NV_LTE_B40_AGC_PA_ON_RISE_FALL_DELAY_I         = 6659,
  NV_LTE_B40_AGC_TX_ON_RISE_FALL_DELAY_I         = 6660,
  NV_LTE_B40_PA_GAIN_UP_DOWN_TIME_I              = 6661,
  NV_LTE_B40_TX_ROT_ANGLE_PA_STATE_I             = 6662,
  NV_LTE_B40_PA_COMPENSATE_UP_DOWN_I             = 6663,
  NV_LTE_B40_TX_LIN_VS_TEMP_I                    = 6664,
  NV_LTE_B40_PA_RANGE_MAP_I                      = 6665,
  NV_LTE_B40_TIMER_HYSTERISIS_I                  = 6666,
  NV_LTE_B40_PA_RISE_FALL_THRESHOLD_I            = 6667,
  NV_LTE_B40_TX_CAL_CHAN_I                       = 6668,
  NV_LTE_B40_TX_LIMIT_VS_TEMP_I                  = 6669,
  NV_LTE_B40_MPR_BASED_PA_SWITCHPOINTS_SHIFT_I   = 6670,
  NV_LTE_B40_TX_MPR_BACKOFF_I                    = 6671,
  NV_LTE_B40_TX_DIGITAL_GAIN_COMP_I              = 6672,
  NV_LTE_B40_TX_AGC_OFFSET_I                     = 6673,
  NV_LTE_B40_TX_LIN_MASTER_0_I                   = 6674,
  NV_LTE_B40_TX_LIN_MASTER_1_I                   = 6675,
  NV_LTE_B40_TX_LIN_MASTER_2_I                   = 6676,
  NV_LTE_B40_TX_LIN_MASTER_3_I                   = 6677,
  NV_LTE_B40_TX_GAIN_INDEX_0_I                   = 6678,
  NV_LTE_B40_TX_GAIN_INDEX_1_I                   = 6679,
  NV_LTE_B40_TX_GAIN_INDEX_2_I                   = 6680,
  NV_LTE_B40_TX_GAIN_INDEX_3_I                   = 6681,
  NV_LTE_B40_TX_COMP_VS_FREQ_I                   = 6682,
  NV_LTE_B40_EXP_HDET_VS_AGC_I                   = 6683,
  NV_LTE_B40_TX_LIMIT_VS_FREQ_I                  = 6684,
  NV_LTE_B40_HDET_OFF_SPAN_I                     = 6685,
  NV_LTE_B40_ANTSEL_I                            = 6686,
  NV_LTE_B40_C1_ANTSEL_I                         = 6687,
  NV_LTE_B40_C0_C1_DELAY_I                       = 6688,
  NV_LTE_B40_C1_NONBYPASS_BYPASS_TIMER_I         = 6689,
  NV_LTE_B40_C1_LNA_RANGE_RISE_FALL_I            = 6690,
  NV_LTE_B40_C1_IM_LEVEL_I                       = 6691,
  NV_LTE_B40_C1_RX_GAIN_VS_TEMP_I                = 6692,
  NV_LTE_B40_C1_LNA_PHASE_CTRL_I                 = 6693,
  NV_LTE_B40_C1_RX_GAIN_I                        = 6694,
  NV_LTE_B40_C1_RX_GAIN_VS_FREQ_I                = 6695,
  NV_LTE_B40_C1_IM2_VALUES_I                     = 6696,
  NV_LTE_B40_C1_RX_CAL_CHAN_I                    = 6697,
  NV_LTE_B1_NONBYPASS_BYPASS_TIMER_I             = 6698,
  NV_LTE_B1_RX_DELAY_I                           = 6699,
  NV_LTE_B1_RX_CAL_CHAN_I                        = 6700,
  NV_LTE_B1_LNA_RANGE_RISE_FALL_I                = 6701,
  NV_LTE_B1_IM_LEVEL_I                           = 6702,
  NV_LTE_B1_RX_GAIN_VS_TEMP_I                    = 6703,
  NV_LTE_B1_RX_GAIN_I                            = 6704,
  NV_LTE_B1_RX_GAIN_VS_FREQ_I                    = 6705,
  NV_LTE_B1_LNA_PHASE_CTRL_I                     = 6706,
  NV_LTE_B1_IM2_VALUES_I                         = 6707,
  NV_LTE_B1_RXF_MISMATCH_COMP_I                  = 6708,
  NV_LTE_B1_ENC_BTF_I                            = 6709,
  NV_LTE_B1_MAX_TX_POWER_I                       = 6710,
  NV_LTE_B1_AGC_PA_ON_RISE_FALL_DELAY_I          = 6711,
  NV_LTE_B1_AGC_TX_ON_RISE_FALL_DELAY_I          = 6712,
  NV_LTE_B1_PA_GAIN_UP_DOWN_TIME_I               = 6713,
  NV_LTE_B1_TX_ROT_ANGLE_PA_STATE_I              = 6714,
  NV_LTE_B1_PA_COMPENSATE_UP_DOWN_I              = 6715,
  NV_LTE_B1_TX_LIN_VS_TEMP_I                     = 6716,
  NV_LTE_B1_PA_RANGE_MAP_I                       = 6717,
  NV_LTE_B1_TIMER_HYSTERISIS_I                   = 6718,
  NV_LTE_B1_PA_RISE_FALL_THRESHOLD_I             = 6719,
  NV_LTE_B1_TX_CAL_CHAN_I                        = 6720,
  NV_LTE_B1_TX_LIMIT_VS_TEMP_I                   = 6721,
  NV_LTE_B1_MPR_BASED_PA_SWITCHPOINTS_SHIFT_I    = 6722,
  NV_LTE_B1_TX_MPR_BACKOFF_I                     = 6723,
  NV_LTE_B1_TX_DIGITAL_GAIN_COMP_I               = 6724,
  NV_LTE_B1_TX_AGC_OFFSET_I                      = 6725,
  NV_LTE_B1_TX_LIN_MASTER_0_I                    = 6726,
  NV_LTE_B1_TX_LIN_MASTER_1_I                    = 6727,
  NV_LTE_B1_TX_LIN_MASTER_2_I                    = 6728,
  NV_LTE_B1_TX_LIN_MASTER_3_I                    = 6729,
  NV_LTE_B1_TX_GAIN_INDEX_0_I                    = 6730,
  NV_LTE_B1_TX_GAIN_INDEX_1_I                    = 6731,
  NV_LTE_B1_TX_GAIN_INDEX_2_I                    = 6732,
  NV_LTE_B1_TX_GAIN_INDEX_3_I                    = 6733,
  NV_LTE_B1_TX_COMP_VS_FREQ_I                    = 6734,
  NV_LTE_B1_EXP_HDET_VS_AGC_I                    = 6735,
  NV_LTE_B1_TX_LIMIT_VS_FREQ_I                   = 6736,
  NV_LTE_B1_HDET_OFF_SPAN_I                      = 6737,
  NV_LTE_B1_ANTSEL_I                             = 6738,
  NV_LTE_B1_C1_ANTSEL_I                          = 6739,
  NV_LTE_B1_C0_C1_DELAY_I                        = 6740,
  NV_LTE_B1_C1_NONBYPASS_BYPASS_TIMER_I          = 6741,
  NV_LTE_B1_C1_LNA_RANGE_RISE_FALL_I             = 6742,
  NV_LTE_B1_C1_IM_LEVEL_I                        = 6743,
  NV_LTE_B1_C1_RX_GAIN_VS_TEMP_I                 = 6744,
  NV_LTE_B1_C1_LNA_PHASE_CTRL_I                  = 6745,
  NV_LTE_B1_C1_RX_GAIN_I                         = 6746,
  NV_LTE_B1_C1_RX_GAIN_VS_FREQ_I                 = 6747,
  NV_LTE_B1_C1_IM2_VALUES_I                      = 6748,
  NV_LTE_B1_C1_RX_CAL_CHAN_I                     = 6749,
  NV_LTE_B13_DRX_MODE_SEL_I                      = 6750,
  NV_LTE_B7_DRX_MODE_SEL_I                       = 6751,
  NV_LTE_B17_DRX_MODE_SEL_I                      = 6752,
  NV_LTE_B40_DRX_MODE_SEL_I                      = 6753,
  NV_LTE_B1_DRX_MODE_SEL_I                       = 6754,
  NV_CGPS_SENSORS_ENABLE_I                       = 6755,
  NV_WCDMA_REL7_PA_MPR_BACKOFF_I                 = 6756,
  NV_WCDMA_IQ_GAIN_I                             = 6757,
  NV_GNSS_GPS_RXD_ENABLE_I                       = 6758,
  NV_GNSS_SYSTEM_CONTROL_I                       = 6759,
  NV_GNSS_GLO_CONTROL_I                          = 6760,
  NV_GNSS_RXD_PATH_LOSS_I                        = 6761,
  NV_GNSS_HBW_PATH_LOSS_I                        = 6762,
  NV_GNSS_GLO_PATH_LOSS_CENTER_MINUS7_I          = 6763,
  NV_GNSS_GLO_PATH_LOSS_CENTER_0_I               = 6764,
  NV_GNSS_GLO_PATH_LOSS_CENTER_PLUS6_I           = 6765,
  NV_GNSS_LBW_RXD_GROUP_DELAY_DIFF_I             = 6766,
  NV_GNSS_TIMED_OUTPUT_MODE_SELECTION_I          = 6767,
  NV_GNSS_TIMED_OUTPUT_FIXED_BIAS_OFFSET_I       = 6768,
  NV_GNSS_MAX_M_RXD_TASKS_I                      = 6769,
  NV_GNSS_MAX_GNSS_TASKS_I                       = 6770,
  NV_GNSS_SHALLOW_FIRST_DWELL_DURATION_I         = 6771,
  NV_GNSS_SHALLOW_SUCCESSIVE_DWELLS_DURATION_I   = 6772,
  NV_GNSS_DEEP_FIRST_DWELL_DURATION_I            = 6773,
  NV_GNSS_DEEP_SECOND_DWELL_DURATION_I           = 6774,
  NV_GNSS_DEEP_THIRD_DWELL_DURATION_I            = 6775,
  NV_GNSS_VERIFICATION_DWELL_DURATION_I          = 6776,
  NV_GNSS_PROBATIONARY_SCAN_DWELL_DURATION_I     = 6777,
  NV_GNSS_ACQUISITION_SAMPLING_MODE_I            = 6778,
  NV_GNSS_PP_RESERVED_I                          = 6779,
  NV_GNSS_MAX_NUM_GPS_SV_MEASUREMENTS_IN_FIX_I   = 6780,
  NV_GNSS_SPCFC_GPS_SV_MEASURES_NOT_IN_FIX_I     = 6781,
  NV_GNSS_MAX_NUM_GLO_SV_MEASUREMENTS_IN_FIX_I   = 6782,
  NV_GNSS_SPCFC_GLO_SV_MEASURES_NOT_IN_FIX_I     = 6783,
  NV_GNSS_DISABLE_GGTB_CONSTRAINT_IN_WLS_I       = 6784,
  NV_GNSS_DISABLE_GLO_ONLY_KF_I                  = 6785,
  NV_GNSS_ENABLE_EXTENDED_ON_FEATURE_FOR_GNSS_I  = 6786,
  NV_GNSS_SPCFC_GLO_SV_NAV_DATA_NOT_DECODED_I    = 6787,
  NV_GNSS_SPCFC_GPS_SV_NAV_DATA_NOT_DECODED_I    = 6788,
  NV_GNSS_NMEA_SENTENCE_TYPE_I                   = 6789,
  NV_GNSS_NMEA_EXTENDED_SENTENCE_TYPE_I          = 6790,
  NV_GNSS_801_B_PROTOCOL_SUPPORT_I               = 6791,
  NV_GNSS_SUPL_VERSION_I                         = 6792,
  NV_GNSS_RRLP8_RRC8_SUPPORTED_I                 = 6793,
  NV_GNSS_DPO_DWELL_DURATION_I                   = 6794,
  NV_CGPS_DPO_ENTRY_CRITERIA_CONTROL_I           = 6795,
  NV_CGPS_DEFAULT_REGION_SIZE_I                  = 6796,
  NV_CGPS_USE_QWIP_FOR_ODP_I                     = 6797,
  NV_MULTIMODE_SYSTEM_PREFERENCE_I               = 6798,
  NV_CLKRGM_DEBUG_I                              = 6799,
  NV_BOARD_CAPABILITIES_I                        = 6800,
  NV_CSIM_STATIC_1X_APP_I                        = 6801,
  NV_CSIM_STATIC_GW_APP_I                        = 6802,
  NV_SLIP_PREF_MODE_I                            = 6803,
  NV_BUS_PROF_IMEM_ENABLE_I                      = 6804,
  NV_BUS_PROF_IMEM_MODE_I                        = 6805,
  NV_BUS_PROF_IMEM_TRIGGER_ID_I                  = 6806,
  NV_BUS_PROF_IMEM_BUS_COUNT_I                   = 6807,
  NV_BUS_PROF_IMEM_SIMPLE_SETTINGS_0_I           = 6808,
  NV_BUS_PROF_IMEM_SIMPLE_SETTINGS_1_I           = 6809,
  NV_BUS_PROF_IMEM_SIMPLE_SETTINGS_2_I           = 6810,
  NV_BUS_PROF_IMEM_SIMPLE_SETTINGS_3_I           = 6811,
  NV_BUS_PROF_IMEM_ADVANCE_SETTINGS_0_I          = 6812,
  NV_BUS_PROF_IMEM_ADVANCE_SETTINGS_1_I          = 6813,
  NV_BUS_PROF_IMEM_ADVANCE_SETTINGS_2_I          = 6814,
  NV_BUS_PROF_IMEM_ADVANCE_SETTINGS_3_I          = 6815,
  NV_GNSS_MGP_ERROR_RECOVERY_I                   = 6816,
  NV_GNSS_HBW_CONTROL_I                          = 6817,
  NV_LTE_B13_TX_MISMATCH_COMP_I                  = 6818,
  NV_LTE_B7_TX_MISMATCH_COMP_I                   = 6819,
  NV_LTE_B17_TX_MISMATCH_COMP_I                  = 6820,
  NV_LTE_B40_TX_MISMATCH_COMP_I                  = 6821,
  NV_LTE_B1_TX_MISMATCH_COMP_I                   = 6822,
  NV_LTE_B13_TX_CARRIER_FEEDTHROUGH_COMP_I       = 6823,
  NV_LTE_B7_TX_CARRIER_FEEDTHROUGH_COMP_I        = 6824,
  NV_LTE_B17_TX_CARRIER_FEEDTHROUGH_COMP_I       = 6825,
  NV_LTE_B40_TX_CARRIER_FEEDTHROUGH_COMP_I       = 6826,
  NV_LTE_B1_TX_CARRIER_FEEDTHROUGH_COMP_I        = 6827,
  NV_LTE_BC_CONFIG_I                             = 6828,
  NV_LTE_BC_CONFIG_DIV_I                         = 6829,
  NV_CS_TO_VOIP_FALLBACK_TIMER_I                 = 6830,
  NV_VOIP_CANCEL_RETRY_TIMER_I                   = 6831,
  NV_HDRSCP_FORCE_RESTRICTED_CF_I                = 6832,
  NV_ADC_VBATT_SLOPE_I                           = 6833,
  NV_ADC_VBATT_OFFSET_I                          = 6834,
  NV_CGPS_SENSORS_SPI_OPINTERVAL_I               = 6835,
  NV_CGPS_SENSORS_SPI_DETECTTHRESHOLD_I          = 6836,
  NV_SNSD_MOTION_SCALE_FACTOR_I                  = 6837,
  NV_SNSD_MOTION_ZMD_WINDOW_SAMPLES_I            = 6838,
  NV_SNSD_MOTION_ZMD_METHOD_I                    = 6839,
  NV_SNSD_MOTION_TRANSIENT_LENGTH_I              = 6840,
  NV_HS_USB_PERFORMANCE_SETTING_I                = 6841,
  NV_WLAN_PAL_LINK_PREF_I                        = 6842,
  NV_HS_USB_DISABLE_LPM_I                        = 6843,
  NV_ENHANCED_HPLMN_SRCH_TBL_I                   = 6844,
  NV_GNSS_EMBEDDED_XTRA_CLIENT_ENABLED_I         = 6845,
  NV_GNSS_WWAN_NETWORK_PREFERENCE_I              = 6846,
  NV_GNSS_MEDIUM_PREFERENCES_NUMBER_I            = 6847,
  NV_GNSS_MEDIUM_PREFERENCE_LIST_I               = 6848,
  NV_GNSS_AUTO_NMEA_COMPORT_ENABLED_I            = 6849,
  NV_UMTS_AMR_CODEC_PREFERENCE_CONFIG_I          = 6850,
  NV_GNSS_EMBEDDED_XTRA_TIME_CLIENT_ENABLED_I    = 6851,
  NV_GNSS_1XUP_MSA_TRUSTED_MODE_DISABLE_I        = 6852,
  NV_OEM_ITEM_1_I                                = 6853,
  NV_OEM_ITEM_2_I                                = 6854,
  NV_OEM_ITEM_3_I                                = 6855,
  NV_OEM_ITEM_4_I                                = 6856,
  NV_OEM_ITEM_5_I                                = 6857,
  NV_OEM_ITEM_6_I                                = 6858,
  NV_OEM_ITEM_7_I                                = 6859,
  NV_OEM_ITEM_8_I                                = 6860,
  NV_RC_PROCESS_ERRORS_I                         = 6861,
  NV_EHRPD_AUTH_IN_USIM_I                        = 6862,
  NV_BC0_PA_SMPS_PDM_LEVEL_I                     = 6863,
  NV_BC1_PA_SMPS_PDM_LEVEL_I                     = 6864,
  NV_BC3_PA_SMPS_PDM_LEVEL_I                     = 6865,
  NV_BC4_PA_SMPS_PDM_LEVEL_I                     = 6866,
  NV_BC5_PA_SMPS_PDM_LEVEL_I                     = 6867,
  NV_BC6_PA_SMPS_PDM_LEVEL_I                     = 6868,
  NV_BC10_PA_SMPS_PDM_LEVEL_I                    = 6869,
  NV_BC14_PA_SMPS_PDM_LEVEL_I                    = 6870,
  NV_BC15_PA_SMPS_PDM_LEVEL_I                    = 6871,
  NV_HS_USB_PHY_CONFIG_I                         = 6872,
  NV_QMI_PORT_LIST_I                             = 6873,
  NV_AS_ID_1_DATA_I                              = 6874,
  NV_AS_ID_2_DATA_I                              = 6875,
  NV_DUAL_STANDBY_CFG_ITEMS_I                    = 6876,
  NV_HARD_FAIL_THR_TIME_I                        = 6877,
  NV_WCDMA_CS_VOICE_OVER_HSPA_ENABLED_I          = 6878,
  NV_WCDMA_2100_LNA_RANGE_OFFSET_CAR0_I          = 6879,
  NV_WCDMA_2100_LNA_RANGE_OFFSET_2_CAR0_I        = 6880,
  NV_WCDMA_2100_LNA_RANGE_OFFSET_3_CAR0_I        = 6881,
  NV_WCDMA_2100_LNA_RANGE_OFFSET_4_CAR0_I        = 6882,
  NV_WCDMA_2100_LNA_RANGE_OFFSET_5_CAR0_I        = 6883,
  NV_WCDMA_2100_LNA_RANGE_OFFSET_CAR1_I          = 6884,
  NV_WCDMA_2100_LNA_RANGE_OFFSET_2_CAR1_I        = 6885,
  NV_WCDMA_2100_LNA_RANGE_OFFSET_3_CAR1_I        = 6886,
  NV_WCDMA_2100_LNA_RANGE_OFFSET_4_CAR1_I        = 6887,
  NV_WCDMA_2100_LNA_RANGE_OFFSET_5_CAR1_I        = 6888,
  NV_WCDMA_2100_VGA_GAIN_OFFSET_CAR0_I           = 6889,
  NV_WCDMA_2100_VGA_GAIN_OFFSET_CAR1_I           = 6890,
  NV_WCDMA_2100_LNA_RANGE_RISE_CAR0_I            = 6891,
  NV_WCDMA_2100_LNA_RANGE_RISE_2_CAR0_I          = 6892,
  NV_WCDMA_2100_LNA_RANGE_RISE_3_CAR0_I          = 6893,
  NV_WCDMA_2100_LNA_RANGE_RISE_4_CAR0_I          = 6894,
  NV_WCDMA_2100_LNA_RANGE_RISE_CAR1_I            = 6895,
  NV_WCDMA_2100_LNA_RANGE_RISE_2_CAR1_I          = 6896,
  NV_WCDMA_2100_LNA_RANGE_RISE_3_CAR1_I          = 6897,
  NV_WCDMA_2100_LNA_RANGE_RISE_4_CAR1_I          = 6898,
  NV_WCDMA_2100_LNA_RANGE_FALL_CAR0_I            = 6899,
  NV_WCDMA_2100_LNA_RANGE_FALL_2_CAR0_I          = 6900,
  NV_WCDMA_2100_LNA_RANGE_FALL_4_CAR0_I          = 6901,
  NV_WCDMA_2100_LNA_RANGE_FALL_3_CAR0_I          = 6902,
  NV_WCDMA_2100_LNA_RANGE_FALL_CAR1_I            = 6903,
  NV_WCDMA_2100_LNA_RANGE_FALL_2_CAR1_I          = 6904,
  NV_WCDMA_2100_LNA_RANGE_FALL_3_CAR1_I          = 6905,
  NV_WCDMA_2100_LNA_RANGE_FALL_4_CAR1_I          = 6906,
  NV_UIM_HW_SIM_CONFIG_I                         = 6907,
  NV_WCDMA_1500_VGA_GAIN_OFFSET_I                = 6908,
  NV_WCDMA_1500_VGA_GAIN_OFFSET_VS_FREQ_I        = 6909,
  NV_WCDMA_1500_VGA_GAIN_OFFSET_VS_TEMP_I        = 6910,
  NV_WCDMA_1500_LNA_RANGE_RISE_2_I               = 6911,
  NV_WCDMA_1500_LNA_RANGE_RISE_3_I               = 6912,
  NV_WCDMA_1500_LNA_RANGE_FALL_2_I               = 6913,
  NV_WCDMA_1500_LNA_RANGE_FALL_3_I               = 6914,
  NV_WCDMA_1500_IM_LEVEL_2_I                     = 6915,
  NV_WCDMA_1500_IM_LEVEL_3_I                     = 6916,
  NV_WCDMA_1500_LNA_RANGE_OFFSET_2_I             = 6917,
  NV_WCDMA_1500_LNA_RANGE_OFFSET_3_I             = 6918,
  NV_WCDMA_1500_LNA_OFFSET_VS_FREQ_2_I           = 6919,
  NV_WCDMA_1500_LNA_OFFSET_VS_FREQ_3_I           = 6920,
  NV_WCDMA_1500_IM2_I_VALUE_I                    = 6921,
  NV_WCDMA_1500_IM2_Q_VALUE_I                    = 6922,
  NV_WCDMA_1500_IM2_TRANSCONDUCTOR_VALUE_I       = 6923,
  NV_WCDMA_1500_RX_AGC_MIN_2_I                   = 6924,
  NV_WCDMA_1500_RX_AGC_MIN_3_I                   = 6925,
  NV_WCDMA_1500_MAX_TX_POWER_I                   = 6926,
  NV_WCDMA_1500_OUT_OF_SERVICE_THRESH_I          = 6927,
  NV_WCDMA_1500_LNA_RANGE_RISE_I                 = 6928,
  NV_WCDMA_1500_LNA_RANGE_FALL_I                 = 6929,
  NV_WCDMA_1500_IM_LEVEL_I                       = 6930,
  NV_WCDMA_1500_NONBYPASS_TIMER_I                = 6931,
  NV_WCDMA_1500_BYPASS_TIMER_I                   = 6932,
  NV_WCDMA_1500_LNA_RANGE_OFFSET_I               = 6933,
  NV_WCDMA_1500_LNA_OFFSET_VS_FREQ_I             = 6934,
  NV_WCDMA_1500_RX_AGC_MIN_I                     = 6935,
  NV_WCDMA_1500_RX_AGC_MAX_I                     = 6936,
  NV_WCDMA_1500_AGC_PHASE_OFFSET_I               = 6937,
  NV_WCDMA_1500_TX_LIN_MASTER_0_I                = 6938,
  NV_WCDMA_1500_TX_LIN_MASTER_1_I                = 6939,
  NV_WCDMA_1500_TX_COMP_VS_FREQ_0_I              = 6940,
  NV_WCDMA_1500_TX_COMP_VS_FREQ_1_I              = 6941,
  NV_WCDMA_1500_TX_LIN_VS_TEMP_0_I               = 6942,
  NV_WCDMA_1500_TX_LIN_VS_TEMP_1_I               = 6943,
  NV_WCDMA_1500_TX_SLP_VS_TEMP_0_I               = 6944,
  NV_WCDMA_1500_TX_SLP_VS_TEMP_1_I               = 6945,
  NV_WCDMA_1500_R1_RISE_I                        = 6946,
  NV_WCDMA_1500_R1_FALL_I                        = 6947,
  NV_WCDMA_1500_TX_LIM_VS_TEMP_I                 = 6948,
  NV_WCDMA_1500_TX_LIM_VS_FREQ_I                 = 6949,
  NV_WCDMA_1500_ADJ_FACTOR_I                     = 6950,
  NV_WCDMA_1500_EXP_HDET_VS_AGC_I                = 6951,
  NV_WCDMA_1500_HDET_OFF_I                       = 6952,
  NV_WCDMA_1500_HDET_SPN_I                       = 6953,
  NV_WCDMA_1500_ENC_BTF_I                        = 6954,
  NV_WCDMA_1500_PA_COMPENSATE_UP_I               = 6955,
  NV_WCDMA_1500_PA_COMPENSATE_DOWN_I             = 6956,
  NV_WCDMA_1500_AGC_PA_ON_RISE_DELAY_I           = 6957,
  NV_WCDMA_1500_AGC_PA_ON_FALL_DELAY_I           = 6958,
  NV_WCDMA_1500_AGC_TX_ON_RISE_DELAY_I           = 6959,
  NV_WCDMA_1500_AGC_TX_ON_FALL_DELAY_I           = 6960,
  NV_WCDMA_1500_AGC_UPDATE_TX_AGC_TIME_I         = 6961,
  NV_WCDMA_1500_PRACH_R1_RISE_OFFSET_I           = 6962,
  NV_WCDMA_1500_PRACH_R1_FALL_OFFSET_I           = 6963,
  NV_WCDMA_1500_RX_DELAY_I                       = 6964,
  NV_WCDMA_1500_TX_LIN_MASTER_2_I                = 6965,
  NV_WCDMA_1500_TX_LIN_MASTER_3_I                = 6966,
  NV_WCDMA_1500_TX_COMP_VS_FREQ_2_I              = 6967,
  NV_WCDMA_1500_TX_COMP_VS_FREQ_3_I              = 6968,
  NV_WCDMA_1500_TX_LIN_VS_TEMP_2_I               = 6969,
  NV_WCDMA_1500_TX_LIN_VS_TEMP_3_I               = 6970,
  NV_WCDMA_1500_TX_SLP_VS_TEMP_2_I               = 6971,
  NV_WCDMA_1500_TX_SLP_VS_TEMP_3_I               = 6972,
  NV_WCDMA_1500_R2_RISE_I                        = 6973,
  NV_WCDMA_1500_R2_FALL_I                        = 6974,
  NV_WCDMA_1500_R3_RISE_I                        = 6975,
  NV_WCDMA_1500_R3_FALL_I                        = 6976,
  NV_WCDMA_1500_PA_COMPENSATE_UP_R2_I            = 6977,
  NV_WCDMA_1500_PA_COMPENSATE_DOWN_R2_I          = 6978,
  NV_WCDMA_1500_PA_COMPENSATE_UP_R3_I            = 6979,
  NV_WCDMA_1500_PA_COMPENSATE_DOWN_R3_I          = 6980,
  NV_WCDMA_1500_TX_ROT_ANGLE_PA_STATE_00_I       = 6981,
  NV_WCDMA_1500_TX_ROT_ANGLE_PA_STATE_01_I       = 6982,
  NV_WCDMA_1500_TX_ROT_ANGLE_PA_STATE_10_I       = 6983,
  NV_WCDMA_1500_TX_ROT_ANGLE_PA_STATE_11_I       = 6984,
  NV_WCDMA_1500_PRACH_R2_RISE_OFFSET_I           = 6985,
  NV_WCDMA_1500_PRACH_R2_FALL_OFFSET_I           = 6986,
  NV_WCDMA_1500_PRACH_R3_RISE_OFFSET_I           = 6987,
  NV_WCDMA_1500_PRACH_R3_FALL_OFFSET_I           = 6988,
  NV_WCDMA_1500_PA_RANGE_MAP_I                   = 6989,
  NV_WCDMA_1500_TX_CAL_CHAN_I                    = 6990,
  NV_WCDMA_1500_RX_CAL_CHAN_I                    = 6991,
  NV_WCDMA_1500_PA_RANGE_FOR_DVS_I               = 6992,
  NV_WCDMA_1500_PA_COMPENSATE_UP_WITH_DVS_I      = 6993,
  NV_WCDMA_1500_PA_COMPENSATE_DN_WITH_DVS_I      = 6994,
  NV_WCDMA_1500_DCH_AGC_UPDATE_TX_AGC_TIME_I     = 6995,
  NV_WCDMA_1500_AGC_TX_ADJ_PDM_DELAY_I           = 6996,
  NV_WCDMA_1500_UTRAN_TX_LIM_VS_TEMP_OFFSET_I    = 6997,
  NV_WCDMA_1500_MAX_PWR_BACKOFF_VOLTAGES_I       = 6998,
  NV_WCDMA_1500_MAX_PWR_BACKOFF_VOLT1_I          = 6999,
  NV_WCDMA_1500_MAX_PWR_BACKOFF_VOLT2_I          = 7000,
  NV_WCDMA_1500_MAX_PWR_BACKOFF_VOLT3_I          = 7001,
  NV_WCDMA_1500_PA_GAIN_UP_TIME_I                = 7002,
  NV_WCDMA_1500_PA_GAIN_DOWN_TIME_I              = 7003,
  NV_WCDMA_1500_TX_PDM_LIN_0_I                   = 7004,
  NV_WCDMA_1500_TX_PDM_LIN_1_I                   = 7005,
  NV_WCDMA_1500_TX_PDM_LIN_2_I                   = 7006,
  NV_WCDMA_1500_TX_PDM_LIN_3_I                   = 7007,
  NV_WCDMA_1500_IACCUM_I                         = 7008,
  NV_WCDMA_1500_QACCUM_I                         = 7009,
  NV_WCDMA_1500_IM_LEVEL_4_I                     = 7010,
  NV_WCDMA_1500_LNA_OFFSET_VS_FREQ_4_I           = 7011,
  NV_WCDMA_1500_LNA_RANGE_FALL_4_I               = 7012,
  NV_WCDMA_1500_LNA_RANGE_OFFSET_4_I             = 7013,
  NV_WCDMA_1500_LNA_RANGE_RISE_4_I               = 7014,
  NV_WCDMA_1500_C0_C1_DELAY_I                    = 7015,
  NV_WCDMA_1500_REL6_TX_BETA_SCALING_COMP_I      = 7016,
  NV_WCDMA_1500_REL6_TX_AGC_OFFSET_I             = 7017,
  NV_WCDMA_1500_REL6_TX_MPR_BACKOFF_I            = 7018,
  NV_WCDMA_1500_TX_COMP_VS_FREQ_0_SECONDARY_I    = 7019,
  NV_WCDMA_1500_TX_COMP_VS_FREQ_1_SECONDARY_I    = 7020,
  NV_WCDMA_1500_TX_COMP_VS_FREQ_2_SECONDARY_I    = 7021,
  NV_WCDMA_1500_TX_COMP_VS_FREQ_3_SECONDARY_I    = 7022,
  NV_WCDMA_1500_TX_COMP_VS_FREQ_SEC_PDM_LIST_I   = 7023,
  NV_WCDMA_1500_TX_LIN_MASTER_0_ENH_I            = 7024,
  NV_WCDMA_1500_TX_PDM_LIN_0_ENH_I               = 7025,
  NV_WCDMA_1500_LNA_PHASE_CTL_I                  = 7026,
  NV_WCDMA_1500_TIMER_HYSTERISIS_I               = 7027,
  NV_WCDMA_1500_RXF_MIS_COMP_A_COEFF_I           = 7028,
  NV_WCDMA_1500_RXF_MIS_COMP_B_COEFF_I           = 7029,
  NV_WCDMA_1500_RXF_ICI_I_COEF0_1_I              = 7030,
  NV_WCDMA_1500_RXF_ICI_I_COEF2_3_I              = 7031,
  NV_WCDMA_1500_RXF_ICI_I_COEF4_5_I              = 7032,
  NV_WCDMA_1500_RXF_ICI_I_COEF6_7_I              = 7033,
  NV_WCDMA_1500_RXF_ICI_I_COEF8_9_I              = 7034,
  NV_WCDMA_1500_RXF_ICI_I_COEF10_11_I            = 7035,
  NV_WCDMA_1500_RXF_ICI_I_COEF12_13_I            = 7036,
  NV_WCDMA_1500_RXF_ICI_I_COEF14_15_I            = 7037,
  NV_WCDMA_1500_RXF_ICI_Q_COEF0_1_I              = 7038,
  NV_WCDMA_1500_RXF_ICI_Q_COEF2_3_I              = 7039,
  NV_WCDMA_1500_RXF_ICI_Q_COEF4_5_I              = 7040,
  NV_WCDMA_1500_RXF_ICI_Q_COEF6_7_I              = 7041,
  NV_WCDMA_1500_RXF_ICI_Q_COEF8_9_I              = 7042,
  NV_WCDMA_1500_RXF_ICI_Q_COEF10_11_I            = 7043,
  NV_WCDMA_1500_RXF_ICI_Q_COEF12_13_I            = 7044,
  NV_WCDMA_1500_RXF_ICI_Q_COEF14_15_I            = 7045,
  NV_WCDMA_1500_RXF_ICI_IQ_TRUNC_I               = 7046,
  NV_WCDMA_1500_HS_R1_RISE_I                     = 7047,
  NV_WCDMA_1500_HS_R1_FALL_I                     = 7048,
  NV_WCDMA_1500_HS_R2_RISE_I                     = 7049,
  NV_WCDMA_1500_HS_R2_FALL_I                     = 7050,
  NV_WCDMA_1500_HS_R3_RISE_I                     = 7051,
  NV_WCDMA_1500_HS_R3_FALL_I                     = 7052,
  NV_WCDMA_1500_HS_LNA_RANGE_FALL_4_I            = 7053,
  NV_WCDMA_1500_HS_LNA_RANGE_FALL_3_I            = 7054,
  NV_WCDMA_1500_HS_LNA_RANGE_FALL_2_I            = 7055,
  NV_WCDMA_1500_HS_LNA_RANGE_FALL_I              = 7056,
  NV_WCDMA_1500_HS_LNA_RANGE_RISE_4_I            = 7057,
  NV_WCDMA_1500_HS_LNA_RANGE_RISE_3_I            = 7058,
  NV_WCDMA_1500_HS_LNA_RANGE_RISE_2_I            = 7059,
  NV_WCDMA_1500_HS_LNA_RANGE_RISE_I              = 7060,
  NV_WCDMA_1500_HS_IM_LEVEL_2_I                  = 7061,
  NV_WCDMA_1500_HS_IM_LEVEL_I                    = 7062,
  NV_WCDMA_1500_HS_IM_LEVEL_3_I                  = 7063,
  NV_WCDMA_1500_HS_IM_LEVEL_4_I                  = 7064,
  NV_WCDMA_1500_HS_SWITCHPOINTS_SHIFT_I          = 7065,
  NV_WCDMA_1500_DRX_MODE_SEL_I                   = 7066,
  NV_C1_WCDMA_1500_VGA_GAIN_OFFSET_I             = 7067,
  NV_C1_WCDMA_1500_VGA_GAIN_OFFSET_VS_FREQ_I     = 7068,
  NV_C1_WCDMA_1500_VGA_GAIN_OFFSET_VS_TEMP_I     = 7069,
  NV_C1_WCDMA_1500_LNA_RANGE_RISE_I              = 7070,
  NV_C1_WCDMA_1500_LNA_RANGE_RISE_2_I            = 7071,
  NV_C1_WCDMA_1500_LNA_RANGE_RISE_3_I            = 7072,
  NV_C1_WCDMA_1500_LNA_RANGE_RISE_4_I            = 7073,
  NV_C1_WCDMA_1500_LNA_RANGE_FALL_I              = 7074,
  NV_C1_WCDMA_1500_LNA_RANGE_FALL_2_I            = 7075,
  NV_C1_WCDMA_1500_LNA_RANGE_FALL_3_I            = 7076,
  NV_C1_WCDMA_1500_LNA_RANGE_FALL_4_I            = 7077,
  NV_C1_WCDMA_1500_IM_LEVEL_I                    = 7078,
  NV_C1_WCDMA_1500_IM_LEVEL_2_I                  = 7079,
  NV_C1_WCDMA_1500_IM_LEVEL_3_I                  = 7080,
  NV_C1_WCDMA_1500_IM_LEVEL_4_I                  = 7081,
  NV_C1_WCDMA_1500_LNA_RANGE_OFFSET_2_I          = 7082,
  NV_C1_WCDMA_1500_LNA_RANGE_OFFSET_3_I          = 7083,
  NV_C1_WCDMA_1500_LNA_RANGE_OFFSET_4_I          = 7084,
  NV_C1_WCDMA_1500_LNA_OFFSET_VS_FREQ_2_I        = 7085,
  NV_C1_WCDMA_1500_LNA_OFFSET_VS_FREQ_3_I        = 7086,
  NV_C1_WCDMA_1500_LNA_OFFSET_VS_FREQ_4_I        = 7087,
  NV_C1_WCDMA_1500_IM2_I_VALUE_I                 = 7088,
  NV_C1_WCDMA_1500_IM2_Q_VALUE_I                 = 7089,
  NV_C1_WCDMA_1500_IM2_TRANSCONDUCTOR_VALUE_I    = 7090,
  NV_C1_WCDMA_1500_NONBYPASS_TIMER_I             = 7091,
  NV_C1_WCDMA_1500_BYPASS_TIMER_I                = 7092,
  NV_C1_WCDMA_1500_LNA_RANGE_OFFSET_I            = 7093,
  NV_C1_WCDMA_1500_LNA_OFFSET_VS_FREQ_I          = 7094,
  NV_C1_WCDMA_1500_RX_CAL_CHAN_I                 = 7095,
  NV_C1_RF_ANTSEL_UMTS_1500_I                    = 7096,
  NV_C1_WCDMA_1500_LNA_PHASE_CTL_I               = 7097,
  NV_C1_WCDMA_1500_RXF_MIS_COMP_A_COEFF_I        = 7098,
  NV_C1_WCDMA_1500_RXF_MIS_COMP_B_COEFF_I        = 7099,
  NV_C1_WCDMA_1500_RXF_ICI_I_COEF0_1_I           = 7100,
  NV_C1_WCDMA_1500_RXF_ICI_I_COEF2_3_I           = 7101,
  NV_C1_WCDMA_1500_RXF_ICI_I_COEF4_5_I           = 7102,
  NV_C1_WCDMA_1500_RXF_ICI_I_COEF6_7_I           = 7103,
  NV_C1_WCDMA_1500_RXF_ICI_I_COEF8_9_I           = 7104,
  NV_C1_WCDMA_1500_RXF_ICI_I_COEF10_11_I         = 7105,
  NV_C1_WCDMA_1500_RXF_ICI_I_COEF12_13_I         = 7106,
  NV_C1_WCDMA_1500_RXF_ICI_I_COEF14_15_I         = 7107,
  NV_C1_WCDMA_1500_RXF_ICI_Q_COEF0_1_I           = 7108,
  NV_C1_WCDMA_1500_RXF_ICI_Q_COEF2_3_I           = 7109,
  NV_C1_WCDMA_1500_RXF_ICI_Q_COEF4_5_I           = 7110,
  NV_C1_WCDMA_1500_RXF_ICI_Q_COEF6_7_I           = 7111,
  NV_C1_WCDMA_1500_RXF_ICI_Q_COEF8_9_I           = 7112,
  NV_C1_WCDMA_1500_RXF_ICI_Q_COEF10_11_I         = 7113,
  NV_C1_WCDMA_1500_RXF_ICI_Q_COEF12_13_I         = 7114,
  NV_C1_WCDMA_1500_RXF_ICI_Q_COEF14_15_I         = 7115,
  NV_C1_WCDMA_1500_RXF_ICI_IQ_TRUNC_I            = 7116,
  NV_WCDMA_1500_PA_COMP_UP_VS_FREQ_I             = 7117,
  NV_WCDMA_1500_PA_COMP_DOWN_VS_FREQ_I           = 7118,
  NV_WCDMA_1500_PA_COMP_UP_R2_VS_FREQ_I          = 7119,
  NV_WCDMA_1500_PA_COMP_DOWN_R2_VS_FREQ_I        = 7120,
  NV_WCDMA_1500_PA_COMP_UP_R3_VS_FREQ_I          = 7121,
  NV_WCDMA_1500_PA_COMP_DOWN_R3_VS_FREQ_I        = 7122,
  NV_WCDMA_1500_EXP_HDET_VS_AGC_V2_I             = 7123,
  NV_WCDMA_1500_HDET_OFF_V2_I                    = 7124,
  NV_WCDMA_1500_HDET_SPN_V2_I                    = 7125,
  NV_WCDMA_2100_TX_LIN_MASTER_3_ENH_I            = 7126,
  NV_WCDMA_800_TX_LIN_MASTER_3_ENH_I             = 7127,
  NV_WCDMA_900_TX_LIN_MASTER_3_ENH_I             = 7128,
  NV_WCDMA_BC4_TX_LIN_MASTER_3_ENH_I             = 7129,
  NV_WCDMA_1800_TX_LIN_MASTER_3_ENH_I            = 7130,
  NV_WCDMA_1900_TX_LIN_MASTER_3_ENH_I            = 7131,
  NV_WCDMA_1500_TX_LIN_MASTER_3_ENH_I            = 7132,
  NV_WCDMA_2100_TX_PDM_LIN_3_ENH_I               = 7133,
  NV_WCDMA_800_TX_PDM_LIN_3_ENH_I                = 7134,
  NV_WCDMA_900_TX_PDM_LIN_3_ENH_I                = 7135,
  NV_WCDMA_BC4_TX_PDM_LIN_3_ENH_I                = 7136,
  NV_WCDMA_1800_TX_PDM_LIN_3_ENH_I               = 7137,
  NV_WCDMA_1900_TX_PDM_LIN_3_ENH_I               = 7138,
  NV_WCDMA_1500_TX_PDM_LIN_3_ENH_I               = 7139,
  NV_UNDP_UIM_DRVSTR_I                           = 7140,
  NV_GNSS_ENABLE_EXTERNAL_CONFIDENCE_INFOR_I     = 7141,
  NV_GNSS_INTERNAL_CONFIDENCE_STATIONARY_I       = 7142,
  NV_GNSS_INTERNAL_CONFIDENCE_NON_STATIONARY_I   = 7143,
  NV_GNSS_XSPI_INJECTION_TIMEOUT_I               = 7144,
  NV_LU_REJECT_AUTO_ENABLED_I                    = 7145,
  NV_EXTENDED_EQUIVALENT_PLMN_LIST_I             = 7146,
  NV_DATA_CALL_OVER_EHRPD_ONLY_I                 = 7147,
  NV_WCDMA_2100_RXF_ICI_CAL_DATA_CAR0_I          = 7148,
  NV_WCDMA_2100_RXF_ICI_CAL_DATA_CAR1_I          = 7149,
  NV_C1_WCDMA_2100_RXF_ICI_CAL_DATA_CAR0_I       = 7150,
  NV_C1_WCDMA_2100_RXF_ICI_CAL_DATA_CAR1_I       = 7151,
  NV_GOBI_QDL_INDEX_I                            = 7152,
  NV_GOBI_BOOT_CONFIG_I                          = 7153,
  NV_GOBI_BOOT_UQCN_FILENAME_I                   = 7154,
  NV_GOBI_BOOT_AMSS_PART_INDEX_I                 = 7155,
  NV_GOBI_IMAGE_TABLE_I                          = 7156,
  NV_RODEM_OFF_DISPLAY_I                         = 7157,
  NV_WCDMA_800_RXF_ICI_CAL_DATA_CAR0_I           = 7158,
  NV_WCDMA_800_RXF_ICI_CAL_DATA_CAR1_I           = 7159,
  NV_C1_WCDMA_800_RXF_ICI_CAL_DATA_CAR0_I        = 7160,
  NV_C1_WCDMA_800_RXF_ICI_CAL_DATA_CAR1_I        = 7161,
  NV_DDTM_ALLOW_SO_PAGES_I                       = 7162,
  NV_CGPS_SM_SUPL_NETWORK_PARAMS_I               = 7163,
  NV_HDET_AUTOCAL_OFFSET_I                       = 7164,
  NV_GNSS_OEM_FEATURE_MASK_I                     = 7165,
  NV_CDMA_SO73_ENABLED_I                         = 7166,
  NV_WCDMA_DC1_LNA_RANGE_OFFSET_CAR1_I           = 7167,
  NV_WCDMA_DC2_LNA_RANGE_OFFSET_CAR1_I           = 7168,
  NV_WCDMA_DC1_LNA_RANGE_OFFSET_2_CAR1_I         = 7169,
  NV_WCDMA_DC2_LNA_RANGE_OFFSET_2_CAR1_I         = 7170,
  NV_WCDMA_DC1_LNA_RANGE_OFFSET_3_CAR1_I         = 7171,
  NV_WCDMA_DC2_LNA_RANGE_OFFSET_3_CAR1_I         = 7172,
  NV_WCDMA_DC1_LNA_RANGE_OFFSET_4_CAR1_I         = 7173,
  NV_WCDMA_DC2_LNA_RANGE_OFFSET_4_CAR1_I         = 7174,
  NV_WCDMA_DC1_LNA_RANGE_OFFSET_5_CAR1_I         = 7175,
  NV_WCDMA_DC2_LNA_RANGE_OFFSET_5_CAR1_I         = 7176,
  NV_WCDMA_DC1_VGA_GAIN_OFFSET_CAR1_I            = 7177,
  NV_WCDMA_DC2_VGA_GAIN_OFFSET_CAR1_I            = 7178,
  NV_WCDMA_DC1_LNA_RANGE_RISE_CAR1_I             = 7179,
  NV_WCDMA_DC2_LNA_RANGE_RISE_CAR1_I             = 7180,
  NV_WCDMA_DC1_LNA_RANGE_RISE_2_CAR1_I           = 7181,
  NV_WCDMA_DC2_LNA_RANGE_RISE_2_CAR1_I           = 7182,
  NV_WCDMA_DC1_LNA_RANGE_RISE_3_CAR1_I           = 7183,
  NV_WCDMA_DC2_LNA_RANGE_RISE_3_CAR1_I           = 7184,
  NV_WCDMA_DC1_LNA_RANGE_RISE_4_CAR1_I           = 7185,
  NV_WCDMA_DC2_LNA_RANGE_RISE_4_CAR1_I           = 7186,
  NV_WCDMA_DC1_LNA_RANGE_RISE_5_CAR1_I           = 7187,
  NV_WCDMA_DC2_LNA_RANGE_RISE_5_CAR1_I           = 7188,
  NV_WCDMA_DC1_LNA_RANGE_FALL_CAR1_I             = 7189,
  NV_WCDMA_DC2_LNA_RANGE_FALL_CAR1_I             = 7190,
  NV_WCDMA_DC1_LNA_RANGE_FALL_2_CAR1_I           = 7191,
  NV_WCDMA_DC2_LNA_RANGE_FALL_2_CAR1_I           = 7192,
  NV_WCDMA_DC1_LNA_RANGE_FALL_3_CAR1_I           = 7193,
  NV_WCDMA_DC2_LNA_RANGE_FALL_3_CAR1_I           = 7194,
  NV_WCDMA_DC1_LNA_RANGE_FALL_4_CAR1_I           = 7195,
  NV_WCDMA_DC2_LNA_RANGE_FALL_4_CAR1_I           = 7196,
  NV_WCDMA_DC1_LNA_RANGE_FALL_5_CAR1_I           = 7197,
  NV_WCDMA_DC2_LNA_RANGE_FALL_5_CAR1_I           = 7198,
  NV_WCDMA_DC1_RXF_ICI_CAL_DATA_CAR0_I           = 7199,
  NV_WCDMA_DC2_RXF_ICI_CAL_DATA_CAR0_I           = 7200,
  NV_WCDMA_DC1_RXF_ICI_CAL_DATA_CAR1_I           = 7201,
  NV_WCDMA_DC2_RXF_ICI_CAL_DATA_CAR1_I           = 7202,
  NV_C1_WCDMA_DC1_RXF_ICI_CAL_DATA_CAR0_I        = 7203,
  NV_C1_WCDMA_DC2_RXF_ICI_CAL_DATA_CAR0_I        = 7204,
  NV_C1_WCDMA_DC1_RXF_ICI_CAL_DATA_CAR1_I        = 7205,
  NV_C1_WCDMA_DC2_RXF_ICI_CAL_DATA_CAR1_I        = 7206,
  NV_C1_WCDMA_DC1_LNA_RANGE_OFFSET_CAR1_I        = 7207,
  NV_C1_WCDMA_DC2_LNA_RANGE_OFFSET_CAR1_I        = 7208,
  NV_C1_WCDMA_DC1_LNA_RANGE_OFFSET_2_CAR1_I      = 7209,
  NV_C1_WCDMA_DC2_LNA_RANGE_OFFSET_2_CAR1_I      = 7210,
  NV_C1_WCDMA_DC1_LNA_RANGE_OFFSET_3_CAR1_I      = 7211,
  NV_C1_WCDMA_DC2_LNA_RANGE_OFFSET_3_CAR1_I      = 7212,
  NV_C1_WCDMA_DC1_LNA_RANGE_OFFSET_4_CAR1_I      = 7213,
  NV_C1_WCDMA_DC2_LNA_RANGE_OFFSET_4_CAR1_I      = 7214,
  NV_C1_WCDMA_DC1_LNA_RANGE_OFFSET_5_CAR1_I      = 7215,
  NV_C1_WCDMA_DC2_LNA_RANGE_OFFSET_5_CAR1_I      = 7216,
  NV_C1_WCDMA_DC1_VGA_GAIN_OFFSET_CAR1_I         = 7217,
  NV_C1_WCDMA_DC2_VGA_GAIN_OFFSET_CAR1_I         = 7218,
  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_CAR1_I       = 7219,
  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_2_CAR1_I     = 7220,
  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_3_CAR1_I     = 7221,
  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_4_CAR1_I     = 7222,
  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_5_CAR1_I     = 7223,
  NV_C1_WCDMA_2100_VGA_GAIN_OFFSET_CAR1_I        = 7224,
  NV_LTE_B17_C1_RX_GAIN_VS_FREQ_I_I              = 7225,
  NV_LTE_B13_EXP_LPM_HDET_VS_AGC_I               = 7226,
  NV_LTE_B13_HDET_HPM_LPM_SWITCH_POINT_I         = 7227,
  NV_LTE_B13_TX_LIMIT_VS_FREQ_LPM_I              = 7228,
  NV_LTE_B1_HDET_HPM_LPM_SWITCH_POINT_I          = 7229,
  NV_LTE_B1_EXP_LPM_HDET_VS_AGC_I                = 7230,
  NV_LTE_B1_TX_LIMIT_VS_FREQ_LPM_I               = 7231,
  NV_THERM_BINS_2_I                              = 7232,
 /* FIH;Tiger;2009/10/1 { */
  /* port ADQ.FC185 */
  #ifdef CONFIG_FIH_FXX
  NV_BSP_ADB_USER_RIGHT_I			 = 8028,
  NV_FTM_BOOT_CONDITION_I                        = 8029, 
  NV_FIH_VERSION_I                               = 8030,
  NV_RES_TCH_BOUNDARY_I                          = 8031, 
  NV_M_SENSOR_CALIBRATION_I						= 8032,
  NV_FIH_SW_BC_I                                 = 8033, 
  NV_OPERATOR_REG_I                              = 8034,
  NV_FORMER_UIMID_I                              = 8035,
  NV_FIH_HOST_EXCLUSIVE_I                        = 8036,
  NV_CMCS_VBATT_I                                = 8037,
  NV_FIH_4G2G_OR_4G4G_I                          = 8038,
  NV_MOTO_TRACK_NUMBER_I			 = 8039,
  NV_MAX_I                                       = 8040
  #else
  NV_MAX_I                                       = 7233
  #endif
  /* } FIH;Tiger;2009/10/1 */
/*~ SENTINEL nv_items_enum_type.NV_MAX_I */ 
   , NV_ITEMS_ENUM_MAX                             = 0x7fffffff
} nv_items_enum_type;

/* Type for generic minimum/maximum type */
typedef PACKED struct PACKED_POST{ 
  /* minimum */
  byte                                             min;
  /* maximum */
  byte                                             max;
} nv_minmax_type;

/* Type to hold security code. */
/* 
 * The security code is fixed length and is stored as ASCII string.
 */
typedef PACKED struct PACKED_POST{ 
  /* Security code array */
  byte                                             digits[NV_SEC_CODE_SIZE];
} nv_sec_code_type;

/* Generic enabled/disabled per NAM type */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Enabled flag */
  byte                                             enabled;
} nv_enabled_type;

/* Type to hold authentication A key and the associated NAM id. */
/* 
 * The number is 64 bits per IS-54 appendix A (CAI Appendix X).
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* A key array */
  qword                                            key;
} nv_a_key_type;

/* Type to hold authentication A key 16 bit CRC chksum. */
/* 
 * The checksum is generated with a generator polynomial 
 * as used for CDMA reverse and forward traffic signaling messages, 
 * per CAI sections 6.7.2.2.2 and 7.8.3.2. Exact security and protection 
 * of the A-Key is for now TBD.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Chcksum */
  word                                             chksum;
} nv_a_key_chksum_type;

/* Type to hold SSD (A or B) variable and the associated NAM id. */
/* 
 * Each SSD is 64 bits, per CAI sections 2.3.12.1.1 and 6.3.12.1.1
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* SSD array */
  qword                                            ssd;
} nv_ssd_type;

/* Type to hold user id for Password Authentication Protocol */
typedef PACKED struct PACKED_POST{ 
  /* Length of user_id */
  byte                                             user_id_len;
  /* The user_id */
  byte                                             user_id[NV_MAX_PAP_USER_ID_LENGTH];
} nv_pap_user_id_type;

/* Type to hold password for Password Authentication Protocol */
typedef PACKED struct PACKED_POST{ 
  /* Length of Password */
  byte                                             password_len;
  /* The Password */
  byte                                             password[NV_MAX_PAP_PASSWORD_LENGTH];
} nv_pap_password_type;

/* Type to hold simple IP PPP password */
typedef PACKED struct PACKED_POST{ 
  /* Length of Password */
  byte                                             password_len;
  /* The Password */
  byte                                             password[NV_MAX_PPP_PASSWORD_LENGTH];
} nv_ppp_password_type;

/* Type to hold user id for PPP authentication */
typedef PACKED struct PACKED_POST{ 
  /* Length of user id */
  byte                                             user_id_len;
  /* The user id */
  byte                                             user_id[NV_MAX_PPP_USER_ID_LENGTH];
} nv_ppp_user_id_type;

/* Type for NV_SEC_DEVICE_KEY_I */
typedef PACKED struct PACKED_POST{ 
  
  uint8                                            device_key_len;
  
  uint8                                            device_key_data[NV_SEC_DEVICE_KEY_MAX_LEN];
} nv_sec_device_key_type;

/* Type to hold ESN */
/* 
 * The ESN and its checksum are write-once protected and the NV
 * task will not write to NV an ESN or its checksum if the stored ESN or its
 * checksum are non-zero
 */
typedef PACKED struct PACKED_POST{ 
  /* esn */
  dword                                            esn;
} nv_esn_type;

/* Type to hold ESN checksum */
/* 
 * The checksum is 30 bit CRC with generator polynomial as used for
 * CDMA sync channel signalling, per CAI section 7.7.1.2.2. The ESN 
 * and its checksum are write-once proteted and the NV task will not 
 * write to NV an ESN or its checksum if the stored ESN, or its checksum 
 * or the internal valid flag are not valid. This item can be written 
 * only once internally, by the NV task.
 * The status of this item can be read externally by other tasks to verify 
 * that the ESN has been correctly programmed to NV.
 */
typedef PACKED struct PACKED_POST{ 
  /* esn chksum */
  dword                                            chksum;
} nv_esn_chksum_type;

/* Type to hold configuration checksum */
/* 
 * The checksum is a simple 0xFFFF marker which indicates that
 * configuration parameters have been programmed and are valid
 */
typedef PACKED struct PACKED_POST{ 
  /* Config checksum */
  word                                             chksum;
} nv_config_chksum_type;

/* Type to hold NAM data checksum. */
/* 
 * The checksum is a simple 0xFFFF marker which is set to 
 * indicate that NAM parameters have been programmed and are valid.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* The checksum */
  word                                             chksum;
} nv_nam_chksum_type;

/* Type to hold run timer, with units as shown. */
/* 
 * The range is a zillion years.
 * Timer             units
 * -----             -----
 * Run Time          minutes
 */
typedef PACKED struct PACKED_POST{ 
  /* hold the run timer */
  dword                                            time;
} nv_run_time_type;

/* Type to hold error log. */
/* 
 * Up to NV_MAX_ERR_LOG error codes are stored, each with number of times
 * detected, file name, and line number
 */
typedef PACKED struct PACKED_POST{ 
  /* Storage address from 0 to NV_MAX_ERR_LOG-1 */
  byte                                             address;
  /* Number of occurrences (0=full, FF=empty) */
  byte                                             err_count;
  /* File name string */
  byte                                             file_name[NV_ERR_FILE_NAME_LEN];
  /* Line number in file */
  word                                             line_num;
  /* TRUE if fatal error */
  boolean                                          fatal;
} nv_err_log_type;

/* Type to hold Field Service Code */
/* 
 * Fixed length and is stored as ASCII string.
 */
typedef PACKED struct PACKED_POST{ 
  /* Field Service Code */
  byte                                             fsc[NV_FSC_SIZ];
} nv_fsc_type;

/* Type to hold fsc2 */
typedef PACKED struct PACKED_POST{ 
  /* fsc2 */
  dword                                            fsc2;
} nv_fsc2_type;

/* Type to hold fsc2 checksum */
typedef PACKED struct PACKED_POST{ 
  /* fsc2_chksum */
  dword                                            fsc2_chksum;
} nv_fsc2_chksum_type;

/* Type to hold warranty date code and changes */
typedef PACKED struct PACKED_POST{ 
  /* Warranty date code */
  byte                                             wdc[NV_WDC_LTRS];
  /* in case the wdc def. changes */
  byte                                             extra[3];
} nv_wdc_type;

/* UP encryption key */
typedef PACKED struct PACKED_POST{ 
  /* UP link info table index */
  byte                                             index;
  /* Access key */
  byte                                             key[NV_UP_MAX_KEY_SIZE];
} nv_up_key_type;

/* DATA SERVICES default SIO baud rate */
typedef  word  nv_sio_baudrate_type;
  
  #define  NV_SIO_BAUDRATE_AUTO                          ((nv_sio_baudrate_type)0)
  
  #define  NV_SIO_BAUDRATE_45                            ((nv_sio_baudrate_type)1)
  
  #define  NV_SIO_BAUDRATE_50                            ((nv_sio_baudrate_type)2)
  
  #define  NV_SIO_BAUDRATE_75                            ((nv_sio_baudrate_type)3)
  
  #define  NV_SIO_BAUDRATE_110                           ((nv_sio_baudrate_type)4)
  
  #define  NV_SIO_BAUDRATE_150                           ((nv_sio_baudrate_type)5)
  
  #define  NV_SIO_BAUDRATE_300                           ((nv_sio_baudrate_type)6)
  
  #define  NV_SIO_BAUDRATE_600                           ((nv_sio_baudrate_type)7)
  
  #define  NV_SIO_BAUDRATE_1200                          ((nv_sio_baudrate_type)8)
  
  #define  NV_SIO_BAUDRATE_2400                          ((nv_sio_baudrate_type)9)
  
  #define  NV_SIO_BAUDRATE_4800                          ((nv_sio_baudrate_type)10)
  
  #define  NV_SIO_BAUDRATE_9600                          ((nv_sio_baudrate_type)11)
  
  #define  NV_SIO_BAUDRATE_14400                         ((nv_sio_baudrate_type)12)
  
  #define  NV_SIO_BAUDRATE_19200                         ((nv_sio_baudrate_type)13)
  
  #define  NV_SIO_BAUDRATE_38400                         ((nv_sio_baudrate_type)14)
  
  #define  NV_SIO_BAUDRATE_57600                         ((nv_sio_baudrate_type)15)
  
  #define  NV_SIO_BAUDRATE_76800                         ((nv_sio_baudrate_type)16)
  
  #define  NV_SIO_BAUDRATE_115200                        ((nv_sio_baudrate_type)17)
  
  #define  NV_SIO_BAUDRATE_230400                        ((nv_sio_baudrate_type)18)
  
  #define  NV_SIO_BAUDRATE_BEST                          ((nv_sio_baudrate_type)32766)
  
  #define  NV_SIO_BAUDRATE_MAX                           ((nv_sio_baudrate_type)32767)
  /* Async/Fax 9600bps */
  #define  NV_JCDMA_DS_F92_ASYNC_FAX_96                  ((nv_jcdma_ds_f92_enum_type)0)
  /* Async/Fax 14400bps */
  #define  NV_JCDMA_DS_F92_ASYNC_FAX_144                 ((nv_jcdma_ds_f92_enum_type)1)
  /* Packet 9600bps */
  #define  NV_JCDMA_DS_F92_PACKET_96                     ((nv_jcdma_ds_f92_enum_type)2)
  /* Packet 14400bps */
  #define  NV_JCDMA_DS_F92_PACKET_144                    ((nv_jcdma_ds_f92_enum_type)3)
  /* Packet 64kbps */
  #define  NV_JCDMA_DS_F92_PACKET_HIGH                   ((nv_jcdma_ds_f92_enum_type)4)

  /* Priority: EVRC first */
  #define  NV_EVRC_1ST                                   ((nv_evrc_pri_enum_type)0)
  /* Priority: 13K first */
  #define  NV_EVRC_13K_1ST                               ((nv_evrc_pri_enum_type)1)

  /* A only */
  #define  NV_SYS_A_ONLY                                 ((nv_sys_enum_type)0)
  /* A then B */
  #define  NV_SYS_A_PREF                                 ((nv_sys_enum_type)1)
  /* B only */
  #define  NV_SYS_B_ONLY                                 ((nv_sys_enum_type)2)
  /* B then A */
  #define  NV_SYS_B_PREF                                 ((nv_sys_enum_type)3)
  /* Home SID only */
  #define  NV_SYS_HOME_ONLY                              ((nv_sys_enum_type)4)
  /* Home SID preferred */
  #define  NV_SYS_HOME_PREF                              ((nv_sys_enum_type)5)


/* Type to hold SID(s) for lockout. */
/* 
 * The phone will reject acquisition if any of these SID(s) is acquired.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* SID */
  word                                             sid[NV_MAX_SID_LOCK];
} nv_sid_lock_type;

/* Type to hold SID(s) for acquisition. */
/* 
 * The phone will allow acquisition only on these SID(s).
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* SID */
  word                                             sid[NV_MAX_SID_ACQ];
} nv_sid_acq_type;

/* Type to hold MIN1p for 2 MINs along with the associated NAM id. */
/* 
 * The number is 24 bits, per CAI section 2.3.1.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* MIN1 */
  dword                                            min1[NV_MAX_MINS];
} nv_min1_type;

/* Type to hold MIN2p for 2 MINs along with the associated NAM id. */
/* 
 * The number is 10 bits, per CAI section 2.3.1.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* MIN2 */
  word                                             min2[NV_MAX_MINS];
} nv_min2_type;

/* Type to hold FIRSTCHPp and associated NAM. */
/* 
 * Value is 11 bits, per CAI section 2.3.7.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* FIRSTCHPp channel */
  word                                             channel;
} nv_firstchp_type;

/* Type to hold SID and associated NAM. */
/* 
 * The SID is 15 bits, per CAI section 2.3.8.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* SID */
  word                                             sid;
} nv_sid_type;

/* Enumeration for possible registration values. */
typedef  word  nv_analog_reg_enum_type;
  /* Autonomous registration disabled */
  #define  NV_DISABLED                                   ((nv_analog_reg_enum_type)0)
  /* Autonomuos registration enabled, tell location */
  #define  NV_WHEREABOUTS_KNOWN                          ((nv_analog_reg_enum_type)1)
  /* Autonomous registration enabled, hide location */
  #define  NV_WHEREABOUTS_UNKNOWN                        ((nv_analog_reg_enum_type)2)

/* Type to hold analog registration type, along with associated NAM id */
/* 
 * Type includes enumeration for possible registration values.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Registration kind per enum above */
  nv_analog_reg_enum_type                          kind;
} nv_analog_reg_type;

/* Type to hold CDMA channel and associated NAM. */
/* 
 * Value is 11 bits for Primary and Secondary channels, 
 * per CAI section 6.1.1.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* A carrier channel number */
  word                                             channel_a;
  /* B carrier channel number */
  word                                             channel_b;
} nv_cdmach_type;

/* Type to hold CDMA mobile termination type along with associated NAM. */
/* 
 * To be used for the MOB_TERM_... variables for registration.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Registration enabled */
  boolean                                          enabled[NV_MAX_MINS];
} nv_mob_term_type;

/* Type for ACCOLCp, along with associated NAM id. */
/* 
 * Value is 4 bit, per CAI section 2.3.5
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* ACCLOCp class */
  byte                                             ACCOLCpClass[NV_MAX_MINS];
} nv_accolc_type;
  /* PCS Block A */
  #define  NV_PCS_BLOCK_A                                ((nv_block_or_sys_enum_type)0)
  /* PCS Block B */
  #define  NV_PCS_BLOCK_B                                ((nv_block_or_sys_enum_type)1)
  /* PCS Block C */
  #define  NV_PCS_BLOCK_C                                ((nv_block_or_sys_enum_type)2)
  /* PCS Block D */
  #define  NV_PCS_BLOCK_D                                ((nv_block_or_sys_enum_type)3)
  /* PCS Block E */
  #define  NV_PCS_BLOCK_E                                ((nv_block_or_sys_enum_type)4)
  /* PCS Block F */
  #define  NV_PCS_BLOCK_F                                ((nv_block_or_sys_enum_type)5)
  /* Cellular System A */
  #define  NV_CELLULAR_SYS_A                             ((nv_block_or_sys_enum_type)6)
  /* Cellular System B */
  #define  NV_CELLULAR_SYS_B                             ((nv_block_or_sys_enum_type)7)
  /* Invalid System */
  #define  NV_BLOCK_OR_SYS_INVALID                       ((nv_block_or_sys_enum_type)8)
  /* PCS Block G */
  #define  NV_PCS_BLOCK_G                                ((nv_block_or_sys_enum_type)9)
  /* PCS Block H */
  #define  NV_PCS_BLOCK_H                                ((nv_block_or_sys_enum_type)10)
  
  #define  NV_PCS_BLOCK_I                                ((nv_block_or_sys_enum_type)11)
  
  #define  NV_PCS_BLOCK_J                                ((nv_block_or_sys_enum_type)12)
  
  #define  NV_PCS_BLOCK_K                                ((nv_block_or_sys_enum_type)13)
  
  #define  NV_PCS_BLOCK_L                                ((nv_block_or_sys_enum_type)14)
  
  #define  NV_BLOCK_OR_SYS_MAX                           ((nv_block_or_sys_enum_type)15)

/* Type to hold call timers and associated NAM id. */
/* 
 * Each NAM has its own set of these timers with units as shown.
 * The range of these timers is more than 100 years.
 *    Timer                     units
 *    -----                     -----
 *    Call Time                 seconds
 *    Air Time                  minutes
 *    Roam Time                 minutes
 *    Life Time                 minutes
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Time */
  dword                                            time;
} nv_call_time_type;

/* Type to hold SID+NID pairs. */
/* 
 * The SID is 15 bits, per CAI 2.3.8, and the NID is 16 bits, 
 * per CAI section 2.3.10.3.
 */
typedef PACKED struct PACKED_POST{ 
  /* 15 bits, per CAI 2.3.8 */
  word                                             sid;
  /* 16 bits, per CAI section 2.3.10.3 */
  word                                             nid;
} nv_sid_nid_pair_type;

/* Type to hold 'home' SID+NID pairs for CDMA acquisition */
/* 
 * The type also holds NAM id. Note that this item is NOT
 * 'per-MIN'
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* SID+NID pair */
  nv_sid_nid_pair_type                             pair[NV_MAX_HOME_SID_NID];
} nv_home_sid_nid_type;

/* Type to hold SID+NID pairs to be locked out from CDMA acquisition. */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* SID+NID Pair */
  nv_sid_nid_pair_type                             pair[NV_MAX_SID_NID_LOCK];
} nv_sid_nid_lock_type;
  /* System A */
  #define  NV_SYSTEM_A                                   ((nv_system_type)0)
  /* System B */
  #define  NV_SYSTEM_B                                   ((nv_system_type)1)


/* Type for EVRC preferred voice service options. */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* evrc_capability_enabled */
  boolean                                          evrc_capability_enabled;
  /* home_page_voice_so */
  word                                             home_page_voice_so;
  /* home_orig_voice_so */
  word                                             home_orig_voice_so;
  /* roam_orig_voice_so */
  word                                             roam_orig_voice_so;
} nv_pref_voice_so_type;

/* Type to hold IMSI MCC , along with the associated NAM id. */
/* 
 * The number is 24 bits
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* imsi_mcc */
  word                                             imsi_mcc;
} nv_imsi_mcc_type;

/* Type to hold IMSI_11_12 for 4 MINs along with the associated NAM id */
/* 
 * The number is 8 bits.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* imsi_11_12 */
  byte                                             imsi_11_12;
} nv_imsi_11_12_type;

/* Type to hold IMSI length along with associated NAM id */
/* 
 * The number is 3 bits, per J-STD-008 section 2.3.1.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Length of the IMSI for this NAM */
  byte                                             num;
} nv_imsi_addr_num_type;

/* Type to hold DIR_NUMBER with associated NAM id */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Directory Number */
  byte                                             dir_number[NV_DIR_NUMB_SIZ];
} nv_dir_number_type;

/* Type to hold mobile directory number */
/* 
 * (per IS-683) section 3.5.2.2).
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Number of digits */
  byte                                             n_digits;
  /* The digits */
  byte                                             digitn[NV_DIR_NUMB_PCS_SIZ];
} nv_mob_dir_data_type;
  /* class 0, System A */
  #define  NV_BAND_PREF_BC0_A                            ((nv_band_pref_enum_type)1)
  /* class 0, System B */
  #define  NV_BAND_PREF_BC0_B                            ((nv_band_pref_enum_type)2)
  /* class 0 */
  #define  NV_BAND_PREF_BC0                              ((nv_band_pref_enum_type)3)
  /* class 1 */
  #define  NV_BAND_PREF_BC1                              ((nv_band_pref_enum_type)4)
  /* class 3 */
  #define  NV_BAND_PREF_BC3                              ((nv_band_pref_enum_type)16)
  /* class 4 */
  #define  NV_BAND_PREF_BC4                              ((nv_band_pref_enum_type)32)
  /* class 5 */
  #define  NV_BAND_PREF_BC5                              ((nv_band_pref_enum_type)64)
  /* class 8 - DCS 1800 Band */
  #define  NV_BAND_PREF_GSM_DCS_1800                     ((nv_band_pref_enum_type)128)
  /* class 9 - Extended GSM (E-GSM) 900 Band */
  #define  NV_BAND_PREF_GSM_EGSM_900                     ((nv_band_pref_enum_type)256)
  /* class 9P - Standard or Primary GSM (P-GSM) 900 Band */
  #define  NV_BAND_PREF_GSM_PGSM_900                     ((nv_band_pref_enum_type)512)
  /* any class */
  #define  NV_BAND_PREF_ANY                              ((nv_band_pref_enum_type)65535)

  
  #define  NV_ROAM_PREF_HOME                             ((nv_roam_pref_enum_type)1)
  
  #define  NV_ROAM_PREF_ROAM_ONLY                        ((nv_roam_pref_enum_type)2)
  
  #define  NV_ROAM_PREF_AFFIL                            ((nv_roam_pref_enum_type)3)
  
  #define  NV_ROAM_PREF_ANY                              ((nv_roam_pref_enum_type)255)

typedef PACKED struct PACKED_POST{ 
  /* nam ID 0-n */
  byte                                             nam;
  /* prl_version */
  word                                             prl_version;
  /* size */
  dword                                            size;
  /* valid bit */
  boolean                                          valid;
  /* roaming list */
  byte                                             roaming_list[NV_SIZE_OF_ROAMING_LIST_IN_UNION_TYPE];
} nv_roaming_list_union_type;

/* Type to hold analog/digital prefered mode, and the associated NAM */
typedef  word  nv_mode_enum_type;
  /* CDMA then Analog */
  #define  NV_MODE_DIGITAL_PREF                          ((nv_mode_enum_type)0)
  /* CDMA only */
  #define  NV_MODE_DIGITAL_ONLY                          ((nv_mode_enum_type)1)
  /* Analog then CDMA */
  #define  NV_MODE_ANALOG_PREF                           ((nv_mode_enum_type)2)
  /* Analog only */
  #define  NV_MODE_ANALOG_ONLY                           ((nv_mode_enum_type)3)
  /* Determine mode automatically */
  #define  NV_MODE_AUTOMATIC                             ((nv_mode_enum_type)4)
  /* Emergency mode */
  #define  NV_MODE_E911                                  ((nv_mode_enum_type)5)
  /* Restrict to home only */
  #define  NV_MODE_HOME_ONLY                             ((nv_mode_enum_type)6)
  /* Restrict to PCS home only */
  #define  NV_MODE_PCS_CDMA_ONLY                         ((nv_mode_enum_type)7)
  /* Restrict to cellular home only */
  #define  NV_MODE_CELL_CDMA_ONLY                        ((nv_mode_enum_type)8)
  
  #define  NV_MODE_CDMA_ONLY                             ((nv_mode_enum_type)9)
  
  #define  NV_MODE_HDR_ONLY                              ((nv_mode_enum_type)10)
  
  #define  NV_MODE_CDMA_AMPS_ONLY                        ((nv_mode_enum_type)11)
  
  #define  NV_MODE_GPS_ONLY                              ((nv_mode_enum_type)12)
  /* Service is limited to GSM only */
  #define  NV_MODE_GSM_ONLY                              ((nv_mode_enum_type)13)
  /* Service is limited to WCDMA only */
  #define  NV_MODE_WCDMA_ONLY                            ((nv_mode_enum_type)14)
  
  #define  NV_MODE_WLAN_ONLY                             ((nv_mode_enum_type)15)
  
  #define  NV_MODE_ANY_BUT_HDR                           ((nv_mode_enum_type)16)
  
  #define  NV_MODE_GSM_WCDMA_ONLY                        ((nv_mode_enum_type)17)
  
  #define  NV_MODE_DIGITAL_LESS_HDR_ONLY                 ((nv_mode_enum_type)18)
  
  #define  NV_MODE_CDMA_HDR_ONLY                         ((nv_mode_enum_type)19)
  
  #define  NV_MODE_CDMA_AMPS_HDR_ONLY                    ((nv_mode_enum_type)20)
  
  #define  NV_MODE_CDMA_WLAN_ONLY                        ((nv_mode_enum_type)21)
  
  #define  NV_MODE_HDR_WLAN_ONLY                         ((nv_mode_enum_type)22)
  
  #define  NV_MODE_CDMA_HDR_WLAN_ONLY                    ((nv_mode_enum_type)23)
  
  #define  NV_MODE_GSM_WLAN_ONLY                         ((nv_mode_enum_type)24)
  
  #define  NV_MODE_WCDMA_WLAN_ONLY                       ((nv_mode_enum_type)25)
  
  #define  NV_MODE_GW_WLAN_ONLY                          ((nv_mode_enum_type)26)
  
  #define  NV_MODE_CDMA_AMPS_HDR_WLAN_ONLY               ((nv_mode_enum_type)27)
  
  #define  NV_MODE_CDMA_AMPS_WLAN_ONLY                   ((nv_mode_enum_type)28)
  
  #define  NV_MODE_ANY_BUT_HDR_WLAN                      ((nv_mode_enum_type)29)
  
  #define  NV_MODE_LTE_ONLY                              ((nv_mode_enum_type)30)
  
  #define  NV_MODE_GWL                                   ((nv_mode_enum_type)31)
  
  #define  NV_MODE_CDMA_LTE_ONLY                         ((nv_mode_enum_type)32)
  
  #define  NV_MODE_HDR_LTE_ONLY                          ((nv_mode_enum_type)33)
  
  #define  NV_MODE_GSM_LTE_ONLY                          ((nv_mode_enum_type)34)
  
  #define  NV_MODE_WCDMA_LTE_ONLY                        ((nv_mode_enum_type)35)
  
  #define  NV_MODE_CDMA_HDR_LTE_ONLY                     ((nv_mode_enum_type)36)
  
  #define  NV_MODE_CDMA_GSM_LTE_ONLY                     ((nv_mode_enum_type)37)
  
  #define  NV_MODE_CDMA_WCDMA_LTE_ONLY                   ((nv_mode_enum_type)38)
  
  #define  NV_MODE_HDR_GSM_LTE_ONLY                      ((nv_mode_enum_type)39)
  
  #define  NV_MODE_HDR_WCDMA_LTE_ONLY                    ((nv_mode_enum_type)40)
  
  #define  NV_MODE_CDMA_LTE_WLAN_ONLY                    ((nv_mode_enum_type)41)
  
  #define  NV_MODE_HDR_LTE_WLAN_ONLY                     ((nv_mode_enum_type)42)
  
  #define  NV_MODE_GSM_LTE_WLAN_ONLY                     ((nv_mode_enum_type)43)
  
  #define  NV_MODE_WCDMA_LTE_WLAN_ONLY                   ((nv_mode_enum_type)44)
  
  #define  NV_MODE_CDMA_HDR_LTE_WLAN_ONLY                ((nv_mode_enum_type)45)
  
  #define  NV_MODE_CDMA_GSM_LTE_WLAN_ONLY                ((nv_mode_enum_type)46)
  
  #define  NV_MODE_CDMA_WCDMA_LTE_WLAN_ONLY              ((nv_mode_enum_type)47)
  
  #define  NV_MODE_HDR_GSM_LTE_WLAN_ONLY                 ((nv_mode_enum_type)48)
  
  #define  NV_MODE_HDR_WCDMA_LTE_WLAN_ONLY               ((nv_mode_enum_type)49)
  
  #define  NV_MODE_ANY_BUT_WLAN                          ((nv_mode_enum_type)50)
  
  #define  NV_MODE_CDMA_GSM_WCDMA                        ((nv_mode_enum_type)51)
  
  #define  NV_MODE_CDMA_HDR_GSM_WCDMA                    ((nv_mode_enum_type)52)

/* Preferred mode */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Preferred mode per enum above */
  nv_mode_enum_type                                mode;
} nv_pref_mode_type;

/* Type to hold the call history */
/* 
 * COUNT parameter and the associated NAM id, per CAI section 2.3.12.1.3.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* COUNTsp */
  byte                                             count;
} nv_count_type;

/* Type to hold SID+NID pairs for CDMA acquisition along with NAM id. */
/* 
 * NID is 16 bits, per CAI section 2.3.10.3.  There are up to 4 SID+NID
 * pairs, in descending preferrence (0=first, 3=last).
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* SID+NID Pair */
  nv_sid_nid_pair_type                             pair[NV_MAX_MINS][NV_MAX_SID_NID];
} nv_sid_nid_type;

/* Type to hold MIN data checksum. */
/* 
 * The checksum is a simple 0xFFFF marker which specifies that MIN
 * parameters have been programmed and are valid.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Checksum */
  word                                             chksum[NV_MAX_MINS];
} nv_min_chksum_type;

/* Type to hold the name of each NAM, along with the associated NAM id */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* NAM name string */
  byte                                             name[NV_MAX_LTRS];
} nv_name_nam_type;

/* System Preference */
typedef  word  nv_sys_pref_enum_type;
  /* A only */
  #define  NV_SP_A_ONLY                                  ((nv_sys_pref_enum_type)0)
  /* B only */
  #define  NV_SP_B_ONLY                                  ((nv_sys_pref_enum_type)1)
  /* Home only */
  #define  NV_SP_HOME_ONLY                               ((nv_sys_pref_enum_type)2)
  /* Home preferred */
  #define  NV_SP_STANDARD                                ((nv_sys_pref_enum_type)3)

/* Type to hold the system preference and the associated NAM. */
/* 
 * This item replaces NV_CDMA_PREF_SERV_I and NV_ANALOG_PREF_SERV_I for 
 * SSPR 800.
 */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* Preferred system per above enum */
  nv_sys_pref_enum_type                            sys;
} nv_sys_pref_type;
  
  #define  NV_PS_DATA_ORIG_PREF_CDMA_ONLY                ((nv_ps_data_orig_pref_enum_type)0)
  
  #define  NV_PS_DATA_ORIG_PREF_CDMA_HDR                 ((nv_ps_data_orig_pref_enum_type)1)
  
  #define  NV_PS_DATA_ORIG_PREF_CDMA_HDR_IF_CHINA        ((nv_ps_data_orig_pref_enum_type)2)
  
  #define  NV_PS_DATA_ORIG_PREF_GW_ONLY                  ((nv_ps_data_orig_pref_enum_type)3)
  
  #define  NV_PS_DATA_ORIG_PREF_ANY                      ((nv_ps_data_orig_pref_enum_type)4)
  
  #define  NV_PS_DATA_ORIG_PREF_WLAN_ONLY                ((nv_ps_data_orig_pref_enum_type)5)
  
  #define  NV_PS_DATA_ORIG_PREF_WLAN_LESS_PREF           ((nv_ps_data_orig_pref_enum_type)6)
  
  #define  NV_SIO_BITRATE_AUTO                           ((nv_sio_baud_type)0)
  
  #define  NV_SIO_BITRATE_45                             ((nv_sio_baud_type)1)
  
  #define  NV_SIO_BITRATE_50                             ((nv_sio_baud_type)2)
  
  #define  NV_SIO_BITRATE_75                             ((nv_sio_baud_type)3)
  
  #define  NV_SIO_BITRATE_110                            ((nv_sio_baud_type)4)
  
  #define  NV_SIO_BITRATE_150                            ((nv_sio_baud_type)5)
  
  #define  NV_SIO_BITRATE_300                            ((nv_sio_baud_type)6)
  
  #define  NV_SIO_BITRATE_600                            ((nv_sio_baud_type)7)
  
  #define  NV_SIO_BITRATE_1200                           ((nv_sio_baud_type)8)
  
  #define  NV_SIO_BITRATE_2400                           ((nv_sio_baud_type)9)
  
  #define  NV_SIO_BITRATE_4800                           ((nv_sio_baud_type)10)
  
  #define  NV_SIO_BITRATE_9600                           ((nv_sio_baud_type)11)
  
  #define  NV_SIO_BITRATE_19200                          ((nv_sio_baud_type)12)
  
  #define  NV_SIO_BITRATE_38400                          ((nv_sio_baud_type)13)
  
  #define  NV_SIO_BITRATE_57600                          ((nv_sio_baud_type)14)
  
  #define  NV_SIO_BITRATE_115200                         ((nv_sio_baud_type)15)
  
  #define  NV_SIO_BITRATE_230400                         ((nv_sio_baud_type)16)
  
  #define  NV_SIO_BITRATE_BEST                           ((nv_sio_baud_type)17)
  
  #define  NV_SIO_BITRATE_MAX                            ((nv_sio_baud_type)18)
  /* V5.2 support disabled, functionality bypassed */
  #define  NV_V52_DISABLED                               ((nv_v52_control_enum_type)0)
  /* V5.2 support enabled, with no local buffering */
  #define  NV_V52_ENABLED                                ((nv_v52_control_enum_type)1)
  /* V5.2 support enabled, with local buffering */
  #define  NV_V52_LOCAL_BUFFERING                        ((nv_v52_control_enum_type)2)
  /* V5.2 support reserved field */
  #define  NV_V52_FUTURE_SUPPORT                         ((nv_v52_control_enum_type)3)

  /* Analog Fax end-to-end */
  #define  NV_AFAX_ETE                                   ((nv_afax_type)0)
  /* Analog Fax Class 2.0 */
  #define  NV_AFAX_CLASS2                                ((nv_afax_type)1)

/* Type to hold the dial string used for originating packet data calls */
typedef PACKED struct PACKED_POST{ 
  /* Number of digits */
  byte                                             num_digits;
  /* The digit array */
  byte                                             digits[NV_MAX_PKT_ORIG_DIGITS];
} nv_data_pkt_orig_str_type;

/* Type to hold the general info. of a Mobile IP user prof */
typedef PACKED struct PACKED_POST{ 
  /* entry index */
  byte                                             index;
  /* Length of User NAI field */
  byte                                             nai_length;
  /* Network Access Identifier */
  byte                                             nai[NV_MAX_NAI_LENGTH];
  /* SPI set 1 bit */
  boolean                                          mn_ha_spi_set;
  /* Security Parameter Index for MN-HA authentication */
  dword                                            mn_ha_spi;
  /* SPI set 1 bit */
  boolean                                          mn_aaa_spi_set;
  /* Security Parameter Index for MN-AAA authentication */
  dword                                            mn_aaa_spi;
  /* Reverse tunneling preference */
  boolean                                          rev_tun_pref;
  /* IP address of mobile set to 0 for dynamic home address */
  dword                                            home_addr;
  /* Primary Home Agent IP address */
  dword                                            primary_ha_addr;
  /* Secondary Home Agent IP address */
  dword                                            secondary_ha_addr;
} nv_ds_mip_gen_user_prof_type;

/* Type to hold the shared secret info. of a Mobile IP user prof */
typedef PACKED struct PACKED_POST{ 
  /* entry index */
  byte                                             index;
  /* Length of MN-HA shared secret */
  byte                                             mn_ha_shared_secret_length;
  /* MN-HA shared secret */
  byte                                             mn_ha_shared_secret[NV_MAX_MN_HA_SHARED_SECRET_LEN];
  /* Length of MN-AAA shared secret */
  byte                                             mn_aaa_shared_secret_length;
  /* MN_AAA shared secret */
  byte                                             mn_aaa_shared_secret[NV_MAX_MN_AAA_SHARED_SECRET_LEN];
} nv_ds_mip_ss_user_prof_type;

/* Type for timebase diff. between home agent and mobile */
typedef PACKED struct PACKED_POST{ 
  /* entry index */
  byte                                             index;
  /* time difference */
  uint32                                           time_delta;
} nv_ds_mip_mn_ha_time_delta_type;
  
  #define  NV_NO_AUTH                                    ((nv_ppp_auth_enum_type)0)
  
  #define  NV_PAP                                        ((nv_ppp_auth_enum_type)1)
  
  #define  NV_CHAP                                       ((nv_ppp_auth_enum_type)2)

/* Type for Public Key Organization Identifier */
typedef PACKED struct PACKED_POST{ 
  /* entry index */
  byte                                             index;
  
  byte                                             pkoid;
} nv_ds_mip_dmu_pkoid_type;

/* Type for Mobile Node Authenticator */
typedef PACKED struct PACKED_POST{ 
  /* entry index */
  byte                                             index;
  
  byte                                             mn_auth[3];
} nv_ds_mip_dmu_mn_auth_type;

typedef  word  nv_rtsp_proxy_server_flag_type;
  
  #define  NV_ADDR_INVALID                               ((nv_rtsp_proxy_server_flag_type)0)
  
  #define  NV_IPV4_ADDR_MASK                             ((nv_rtsp_proxy_server_flag_type)1)
  
  #define  NV_IPV6_ADDR_MASK                             ((nv_rtsp_proxy_server_flag_type)2)

typedef PACKED union PACKED_POST{ 
  
  uint32                                           v4;
  
  uint64                                           v6[2];
} nv_rtsp_proxy_server_addr;

/* Type for NV_RTSP_PROXY_SERVER_ADDR_I */
typedef PACKED struct PACKED_POST{ 
  
  nv_rtsp_proxy_server_flag_type                   flags;
  
  uint16                                           port;
  
  nv_rtsp_proxy_server_addr                        addr;
} nv_rtsp_proxy_server_addr_type;

/* Operating Mode Type */
typedef  word  nv_operating_mode_enum_type;
  /* GSM/GPRS Mode */
  #define  NV_OPMODE_GPRS                                ((nv_operating_mode_enum_type)1)
  /* WCDMA Mode */
  #define  NV_OPMODE_WCDMA                               ((nv_operating_mode_enum_type)2)
  /* CDMA/1x Mode */
  #define  NV_OPMODE_CDMA                                ((nv_operating_mode_enum_type)4)

/* Type for NV_PKT_DIAL_STRINGS_I */
typedef PACKED struct PACKED_POST{ 
  /* DS Packet Dial String */
  byte                                             dial_string[NV_PKT_DIAL_STRING_SIZE];
  /* DS Call Type Operating Modes */
  nv_operating_mode_enum_type                      call_type;
  /* DS Permitted Operating Modes */
  nv_operating_mode_enum_type                      modes_permitted;
} nv_pkt_dial_string_type;

/* Type for NV_PPP_CONFIG_DATA_I */
typedef PACKED struct PACKED_POST{ 
  /* entry index */
  byte                                             index;
  
  uint16                                           lcp_term_timeout;
  
  uint16                                           lcp_ack_timeout;
  
  uint8                                            lcp_req_try;
  
  uint8                                            lcp_nak_try;
  
  uint8                                            lcp_term_try;
  
  uint8                                            auth_retry;
  
  uint16                                           auth_timeout;
  
  uint16                                           ipcp_term_timeout;
  
  uint16                                           ipcp_ack_timeout;
  
  uint8                                            ipcp_req_try;
  
  uint8                                            ipcp_nak_try;
  
  uint8                                            ipcp_term_try;
  
  uint8                                            ipcp_compression_enable;
  
  uint16                                           ipv6cp_term_timeout;
  
  uint16                                           ipv6cp_ack_timeout;
  
  uint8                                            ipv6cp_req_try;
  
  uint8                                            ipv6cp_nak_try;
  
  uint8                                            ipv6cp_term_try;
  
  uint8                                            ipv6cp_compression_enable;
} nv_ppp_configure_data_type;

/* Type for NV_PS_IPV6_IID_I */
typedef PACKED struct PACKED_POST{ 
  
  byte                                             ipv6_iid_enum_type;
  
  uint64                                           iid_val;
} nv_ps_ipv6_iid_type;

/* Type for NV_IPV6_SM_CONFIG_I  */
typedef PACKED struct PACKED_POST{ 
  
  int16                                            init_sol_delay;
  
  int16                                            sol_interval;
  
  int16                                            resol_interval;
  
  int16                                            max_sol_attempts;
  
  int16                                            max_resol_attempts;
  
  int16                                            pre_ra_exp_resol_time;
} nv_ip6_sm_config_type;

/* Type for NV_IPV6_PRIMARY_DNS_I, NV_IPV6_SECONDARY_DNS_I  */
typedef PACKED struct PACKED_POST{ 
  
  uint64                                           prefix;
  
  uint64                                           iid;
} nv_ipv6_address_type;

typedef PACKED struct PACKED_POST{ 
  
  uint32                                           session_seed;
  
  uint32                                           transmit_ati;
  
  uint32                                           receive_mati;
  
  uint32                                           receive_rati;
  
  uint32                                           receive_current_uati;
  
  uint32                                           receive_new_uati;
  
  boolean                                          new_uati_valid;
  
  uint8                                            uati[NV_UATI_LENGTH];
  
  uint8                                            uati_color_code;
  
  uint8                                            uati_subnet_mask;
} nv_hdramp_address_data_type;

typedef  word  nv_hdrscp_session_status_enum_type;
  
  #define  NV_SCP_SESSION_INACTIVE                       ((nv_hdrscp_session_status_enum_type)0)
  
  #define  NV_SCP_SESSION_DEFAULT                        ((nv_hdrscp_session_status_enum_type)1)
  
  #define  NV_SCP_SESSION_ACTIVE                         ((nv_hdrscp_session_status_enum_type)2)
  
  #define  NV_SCP_SESSION_MAX                            ((nv_hdrscp_session_status_enum_type)32767)

/* Type for NAI for 1xEV(HDR) Access Network CHAP authentication */
typedef PACKED struct PACKED_POST{ 
  /* length of NAI */
  byte                                             nai_len;
  /* the NAI */
  byte                                             nai[NV_MAX_AN_AUTH_NAI_LENGTH];
} nv_hdr_an_auth_nai_type;

/* Type for password for 1xEV(HDR) Access Network CHAP authentication */
typedef PACKED struct PACKED_POST{ 
  /* length of password */
  byte                                             password_len;
  /* the password */
  byte                                             password[NV_MAX_AN_AUTH_PASSWORD_LENGTH];
} nv_hdr_an_auth_password_type;

/* Password for AN authentication */
typedef PACKED struct PACKED_POST{ 
  /* length of password */
  byte                                             password_len;
  /* the password */
  byte                                             password[NV_MAX_AN_PPP_PASSWORD_LENGTH];
} nv_hdr_an_ppp_password_type;

/* Type of NV_HDR_AN_AUTH_PASSWD_LONG_I */
typedef PACKED struct PACKED_POST{ 
  /* length of password */
  byte                                             passwd_len;
  /* the password */
  byte                                             passwd[NV_MAX_AN_AUTH_PASSWD_LONG_LENGTH];
} nv_hdr_an_auth_passwd_long_type;

/* Type of NV_HDR_AN_AUTH_USER_ID_LONG_I */
typedef PACKED struct PACKED_POST{ 
  /* length of user id */
  byte                                             user_id_len;
  /* the user id */
  byte                                             user_id[NV_MAX_AN_AUTH_USER_ID_LONG_LENGTH];
} nv_hdr_an_auth_user_id_long_type;
  
  #define  NV_CAI_RC_1                                   ((nv_rc_pref_type)1)
  
  #define  NV_CAI_RC_2                                   ((nv_rc_pref_type)2)
  
  #define  NV_CAI_RC_3                                   ((nv_rc_pref_type)3)
  
  #define  NV_CAI_RC_4                                   ((nv_rc_pref_type)4)
  
  #define  NV_CAI_RC_5                                   ((nv_rc_pref_type)5)

/* Type for SMS broadcast service table entry */
typedef PACKED struct PACKED_POST{ 
  /* entry index */
  byte                                             index;
  /* for delete operation */
  boolean                                          active_service;
  /* type of service */
  word                                             service;
  /* type of language */
  byte                                             language;
  /* for */
  boolean                                          selected;
  /* priority of the service */
  byte                                             priority;
  /* a UI text label for each service/language pair */
  byte                                             label[NV_SMS_BC_SRV_LABEL_SIZE];
} nv_sms_bc_service_table_type;

/* Type for GSM/WCDMA SMS voice mail center phone number */
typedef PACKED struct PACKED_POST{ 
  /* number of digits in the phone number */
  uint8                                            num_digits;
  /* the value of all digits in the phone number */
  uint8                                            digits[NV_MAX_DIAL_DIGITS];
} nv_sms_vm_number_type;

/* Type to store GSM/WCDMA SMS routing configurations */
typedef PACKED struct PACKED_POST{ 
  
  uint8                                            pp_routes[NV_SMS_MAX_ROUTES];
  
  uint8                                            pp_mem_stores[NV_SMS_MAX_ROUTES];
  
  uint8                                            bc_routes[NV_SMS_MAX_ROUTES];
  
  uint8                                            bc_mem_stores[NV_SMS_MAX_ROUTES];
  
  boolean                                          transfer_status_report;
} nv_sms_routing_type;

/* type to hold speed dial number. */
/* 
 * 'num_digits' and 'num_letters' indicate the actual number of digits
 * and letters, or zero if none.
 * The storage address is in the range 0-99 for speed dial numbers
 */
typedef PACKED struct PACKED_POST{ 
  /* Address (index) */
  byte                                             address;
  /* flag bits */
  byte                                             status;
  /* Number of digits */
  byte                                             num_digits;
  /* Array of digits */
  byte                                             digits[NV_MAX_DIAL_DIGITS];
  /* Name associated with number */
  byte                                             letters[NV_MAX_LTRS];
} nv_dial_type;

/* Type to hold call stack dial number */
/* 
 * 'num_digits' and 'num_letters' indicates the actual number of
 * digits and letters, or zero if none. The storage address is in the 
 * range of 0-9 for a stack number.
 */
typedef PACKED struct PACKED_POST{ 
  /* Storage address */
  byte                                             address;
  /* flag bits */
  byte                                             status;
  /* years to seconds */
  dword                                            time_stamp;
  /* Number of digits */
  byte                                             num_digits;
  /* Array of digits */
  byte                                             digits[NV_MAX_DIAL_DIGITS];
  /* Name associated with number */
  byte                                             letters[NV_MAX_LTRS];
  /* Duration of the call */
  dword                                            duration;
} nv_stdial_type;

/* Type to hold call stack index. */
/* 
 * The array of bytes allows sorting the call stack by 
 * order of dialing and resorting as it is being used. The secret field 
 * indicates if a secret number is in that stack location.
 */
typedef PACKED struct PACKED_POST{ 
  /* Index array */
  byte                                             index[NV_MAX_STACK_DIALS];
  /* TRUE if a secret number */
  boolean                                          secret[NV_MAX_STACK_DIALS];
} nv_stack_idx_type;

/* Type to specify page answer rings and answer mode. */
typedef PACKED struct PACKED_POST{ 
  /* paging mode */
  byte                                             enable;
  /* Number of rings when to accept page */
  byte                                             rings;
} nv_page_set_type;

/* Type to hold page message. */
/* 
 * The page characters are stored as ASCII string.
 */
typedef PACKED struct PACKED_POST{ 
  /* Storage address 0-19 */
  byte                                             address;
  /* Time stamp */
  dword                                            time_stamp;
  /* New page status */
  boolean                                          newPage;
  /* Number of characters */
  byte                                             num_chars;
  /* Array of characters */
  byte                                             chars[NV_MAX_PAGE_CHARS];
} nv_page_msg_type;

/* Type to hold display banner. */
/* 
 * The banner is fixed length and is stored as ASCII string.
 */
typedef PACKED struct PACKED_POST{ 
  /* Banner */
  byte                                             letters[NV_MAX_LTRS];
} nv_banner_type;

/* Type to specify auto answer rings and enable/disable. */
typedef PACKED struct PACKED_POST{ 
  /* TRUE if auto answer enabled */
  boolean                                          enable;
  /* Number of rings when to answer call */
  byte                                             rings;
} nv_auto_answer_type;

/* Type to specify auto redial rings and enable/disable */
typedef PACKED struct PACKED_POST{ 
  /* TRUE if auto redial enabled */
  boolean                                          enable;
  /* Number of 10 seconds system busy before redial */
  byte                                             rings;
} nv_auto_redial_type;

/* Type to hold user lock code. */
/* 
 * The lock code is fixed length and is stored as ASCII string.
 */
typedef PACKED struct PACKED_POST{ 
  /* Lock code array */
  byte                                             digits[NV_LOCK_CODE_SIZE];
} nv_lock_code_type;

/* Air time counter */
typedef PACKED struct PACKED_POST{ 
  /* NAM id 0-N */
  byte                                             nam;
  /* count */
  dword                                            cnt;
} nv_call_cnt_type;

/* Type to specify which type of keypress sound should be emitted. */
typedef  word  nv_key_sound_enum_type;
  /* Emit clicks for key presses */
  #define  NV_KEY_SOUND_CLICK                            ((nv_key_sound_enum_type)0)
  /* Emit tones for key presses */
  #define  NV_KEY_SOUND_TONES                            ((nv_key_sound_enum_type)1)

  /* Sort entries alphabetically */
  #define  NV_SORT_ALPHABETICAL                          ((nv_dials_sort_enum_type)0)
  /* Sort entries by location */
  #define  NV_SORT_BY_LOCATION                           ((nv_dials_sort_enum_type)1)

/* Type to specify which language to use for the user interface */
typedef  word  nv_language_enum_type;
  /* Use English language */
  #define  NV_LANGUAGE_ENGLISH                           ((nv_language_enum_type)0)
  /* Use Spanish language */
  #define  NV_LANGUAGE_SPANISH                           ((nv_language_enum_type)1)
  /* Use French language */
  #define  NV_LANGUAGE_FRENCH                            ((nv_language_enum_type)2)
  /* Use Portuguese language */
  #define  NV_LANGUAGE_PORTUGUESE                        ((nv_language_enum_type)3)

/* Type to specify the user interface menu format */
typedef  word  nv_menu_format_enum_type;
  /* Display full menus */
  #define  NV_MENU_FULL                                  ((nv_menu_format_enum_type)0)
  /* Display short menus */
  #define  NV_MENU_SHORT                                 ((nv_menu_format_enum_type)1)

  /* DTACO disabled */
  #define  NV_DTACO_DISABLED                             ((nv_dtaco_enum_type)0)
  /* DTACO enabled */
  #define  NV_DTACO_ENABLED                              ((nv_dtaco_enum_type)1)
  /* DTACO enabled on flip */
  #define  NV_DTACO_ENABLED_ON_FLIP                      ((nv_dtaco_enum_type)2)

  /*  Use 12MMDD  */
  #define  NV_TIME_FMT_12MMDD                            ((nv_time_fmt_enum_type)0)
  /*  Use 12DDMM  */
  #define  NV_TIME_FMT_12DDMM                            ((nv_time_fmt_enum_type)1)
  /*  Use 24MMDD  */
  #define  NV_TIME_FMT_24MMDD                            ((nv_time_fmt_enum_type)2)
  /*  Use 24DDMM  */
  #define  NV_TIME_FMT_24DDMM                            ((nv_time_fmt_enum_type)3)

/* Type definitions for R-UIM CHV. */
typedef PACKED struct PACKED_POST{ 
  
  byte                                             digits[NV_RUIM_CHV_SIZE];
} nv_ruim_chv_type;

/* Type definitions for gpsOne transport mechanism */
typedef  word  nv_gps1_transport_type;
  /*  Use IP  */
  #define  NV_IP_TRANSPORT                               ((nv_gps1_transport_type)0)
  /*  Use DBM  */
  #define  NV_DBM_TRANSPORT                              ((nv_gps1_transport_type)1)

  /*  Use Mobile based Position Calculations  */
  #define  NV_POSITION_CALC_MOBILE                       ((nv_gps1_position_calc_type)0)
  /*  Use PDE based Position Calculations  */
  #define  NV_POSITION_CALC_PDE                          ((nv_gps1_position_calc_type)1)

/* Type definitions for Bluetooth address */
typedef PACKED struct PACKED_POST{ 
  
  byte                                             bd_addr[NV_BD_ADDR_SIZE];
} nv_bd_addr_type;
  /* Determine acquisition order automatically */
  #define  NV_ACQ_ORDER_PREF_AUTOMATIC                   ((nv_acq_order_pref_enum_type)0)
  /* Acquisition order is GSM first, followed by WCDMA */
  #define  NV_ACQ_ORDER_PREF_GSM_WCDMA                   ((nv_acq_order_pref_enum_type)1)
  /* Acquisition order is WCDMA first, followed by GSM */
  #define  NV_ACQ_ORDER_PREF_WCDMA_GSM                   ((nv_acq_order_pref_enum_type)2)

  /* Select network automatically */
  #define  NV_NET_SEL_MODE_PREF_AUTOMATIC                ((nv_net_sel_mode_pref_enum_type)0)
  /* Select network manually */
  #define  NV_NET_SEL_MODE_PREF_MANUAL                   ((nv_net_sel_mode_pref_enum_type)1)
  /* Select network for limited service */
  #define  NV_NET_SEL_MODE_PREF_LIMITED_SRV              ((nv_net_sel_mode_pref_enum_type)2)


typedef  word  nv_srv_domain_pref_enum_type;
  /* Prefer Circuit Switched only */
  #define  NV_SRV_DOMAIN_PREF_CS_ONLY                    ((nv_srv_domain_pref_enum_type)0)
  /* Prefer Packet Switched only */
  #define  NV_SRV_DOMAIN_PREF_PS_ONLY                    ((nv_srv_domain_pref_enum_type)1)
  /* Prefer Circuit and Packet Switched only */
  #define  NV_SRV_DOMAIN_PREF_CS_PS                      ((nv_srv_domain_pref_enum_type)2)
  /* Prefer Any service domain */
  #define  NV_SRV_DOMAIN_PREF_ANY                        ((nv_srv_domain_pref_enum_type)3)

/* service domain pref type */
typedef PACKED struct PACKED_POST{ 
  /* NAM */
  byte                                             nam;
  /* service domain preference */
  nv_srv_domain_pref_enum_type                     srv_domain;
} nv_srv_domain_pref_type;

typedef  word  nv_rtre_configuration_type;
  /* RTRE configuration: use R-UIM only */
  #define  NV_RTRE_CONFIG_RUIM_ONLY                      ((nv_rtre_configuration_type)0)
  /* RTRE configuration: use NV only */
  #define  NV_RTRE_CONFIG_NV_ONLY                        ((nv_rtre_configuration_type)1)
  /* RTRE configuration: use R-UIM if available or NV */
  #define  NV_RTRE_CONFIG_RUIM_OR_DROP_BACK              ((nv_rtre_configuration_type)2)
  /* RTRE configuration: GSM on 1x */
  #define  NV_RTRE_CONFIG_SIM_ACCESS                     ((nv_rtre_configuration_type)3)

/* RTRE control type */
typedef  word  nv_rtre_control_type;
  /* Use the R-UIM */
  #define  NV_RTRE_CONTROL_USE_RUIM                      ((nv_rtre_control_type)0)
  /* Do not use the R-UIM */
  #define  NV_RTRE_CONTROL_NO_RUIM                       ((nv_rtre_control_type)1)
  /* Use a GSM card for provisioning, no R-UIM functions */
  #define  NV_RTRE_CONTROL_SIM_ACCESS                    ((nv_rtre_control_type)2)

/* RTRE polling control type */
typedef  word  nv_rtre_polling_control_type;
  /* Do not poll the UIM card */
  #define  NV_RTRE_POLLING_CONTROL_NO_POLL               ((nv_rtre_polling_control_type)0)
  /* Poll the UIM card */
  #define  NV_RTRE_POLLING_CONTROL_POLL                  ((nv_rtre_polling_control_type)1)

  /* First UIM instruction class: GSM SIM */
  #define  NV_UIM_FIRST_INST_CLASS_GSM_SIM               ((nv_uim_first_inst_class_type)0)
  /* First UIM instruction class: UMTS SIM */
  #define  NV_UIM_FIRST_INST_CLASS_UMTS_SIM              ((nv_uim_first_inst_class_type)1)
  
  #define  NV_UIM_FIRST_INST_CLASS_USB_UICC              ((nv_uim_first_inst_class_type)2)
  
  #define  NV_UIM_FIRST_INST_CLASS_USB_UICC_RST_HIGH     ((nv_uim_first_inst_class_type)3)

typedef PACKED struct PACKED_POST{ 
  
  word                                             option;
} nv_err_fatal_options_type;

typedef  word  nv_uim_pref_protocol_type;
  /* Preferred Protocol T=0 */
  #define  NV_UIM_PREF_PROTOCOL_T_0                      ((nv_uim_pref_protocol_type)0)
  /* Preferred Protocol T=1 */
  #define  NV_UIM_PREF_PROTOCOL_T_1                      ((nv_uim_pref_protocol_type)1)
  /* Preferred Protocol None */
  #define  NV_UIM_PREF_PROTOCOL_NONE                     ((nv_uim_pref_protocol_type)2)

  /* Preferred slot None */
  #define  NV_UIM_SLOT_NONE                              ((nv_uim_slot_type)0)
  /* Preferred slot 1 */
  #define  NV_UIM_SLOT_1                                 ((nv_uim_slot_type)1)
  /* Preferred slot 2 */
  #define  NV_UIM_SLOT_2                                 ((nv_uim_slot_type)2)


/* Type to hold UE IMEI */
typedef PACKED struct PACKED_POST{ 
  /* International Mobile Equipment Identity */
  byte                                             ue_imei[NV_UE_IMEI_SIZE];
} nv_ue_imei_type;
  
  #define  NV_SYS_BAND_EGSM_900                          ((nv_sys_band_T)0)
  
  #define  NV_SYS_BAND_PGSM_900                          ((nv_sys_band_T)1)
  
  #define  NV_SYS_BAND_PCS_1900                          ((nv_sys_band_T)2)
  
  #define  NV_SYS_BAND_DCS_1800                          ((nv_sys_band_T)3)
  
  #define  NV_SYS_BAND_CELL_850                          ((nv_sys_band_T)4)

/* RF capability */
typedef  word  nv_trm_rf_enum;
  
  #define  NV_TRM_RF_SINGLE                              ((nv_trm_rf_enum)0)
  
  #define  NV_TRM_RF_DIVERSITY_ONLY                      ((nv_trm_rf_enum)1)
  
  #define  NV_TRM_RF_DUAL_RX                             ((nv_trm_rf_enum)2)
  
  #define  NV_TRM_RF_DUAL_RX_EQUIV_SENSITIVITY           ((nv_trm_rf_enum)3)
  
  #define  DDTM_PREF_OFF                                 ((nv_ddtm_pref_type)0)
  
  #define  DDTM_PREF_ON                                  ((nv_ddtm_pref_type)1)
  
  #define  DDTM_ACT_EMPTY                                ((nv_ddtm_act)0)
  
  #define  DDTM_ACT_SUPPRESS_L2ACK                       ((nv_ddtm_act)1)
  
  #define  DDTM_ACT_SUPPRESS_REG                         ((nv_ddtm_act)2)
  
  #define  DDTM_ACT_IGN_SO_PAGES                         ((nv_ddtm_act)4)
  
  #define  DDTM_ACT_SUPPRESS_MO_DBM                      ((nv_ddtm_act)8)
  
  #define  DDTM_ACT_ALL                                  ((nv_ddtm_act)16383)
  
  #define  NV_SMS_BEARER_USAGE_PREFERRED                 ((nv_sms_bearer_usage_type)0)
  
  #define  NV_SMS_BEARER_USAGE_USED                      ((nv_sms_bearer_usage_type)1)
  
  #define  NV_SMS_BEARER_USAGE_NOT_USED                  ((nv_sms_bearer_usage_type)2)
  
  #define  NV_XO_CAL_FT_QUAL_NOT_CAL                     ((nv_xo_ft_qual_enum_type)0)
  
  #define  NV_XO_CAL_FT_QUAL_FAC1                        ((nv_xo_ft_qual_enum_type)1)
  
  #define  NV_XO_CAL_FT_QUAL_FT1                         ((nv_xo_ft_qual_enum_type)2)
  
  #define  NV_XO_CAL_FT_QUAL_FT2                         ((nv_xo_ft_qual_enum_type)3)
  
  #define  NV_XO_CAL_FT_QUAL_FAILED                      ((nv_xo_ft_qual_enum_type)4)
  
  #define  NV_TCXOMGR_FIELD0                             ((nv_xo_field_state_type)0)
  
  #define  NV_TCXOMGR_FIELD1                             ((nv_xo_field_state_type)1)
  
  #define  NV_TCXOMGR_FIELD2                             ((nv_xo_field_state_type)2)
  
  #define  NV_TCXOMGR_FIELD3                             ((nv_xo_field_state_type)3)
  
  #define  NV_TCXOMGR_FIELD4                             ((nv_xo_field_state_type)4)

/* Clock frequency configuration for WLAN Atheros module. */
typedef  word  nv_atheros_clk_freq_type;
  
  #define  ATHEROS_CLK_FREQ_26_MHZ                       ((nv_atheros_clk_freq_type)0)
  
  #define  ATHEROS_CLK_FREQ_19P2_MHZ                     ((nv_atheros_clk_freq_type)1)

/* Policy to ignore/stick/normal DTIM processing */
typedef  word  nv_atheros_dtim_policy_type;
  
  #define  WLAN_ATHEROS_IGNORE_DTIM                      ((nv_atheros_dtim_policy_type)1)
  
  #define  WLAN_ATHEROS_NORMAL_DTIM                      ((nv_atheros_dtim_policy_type)2)
  
  #define  WLAN_ATHEROS_STICK_DTIM                       ((nv_atheros_dtim_policy_type)3)
  
  #define  NV_QMI_FRAME_MODE_IF1                         ((nv_qmi_frame_mode_type)1)
  
  #define  NV_QMI_FRAME_MODE_IF2                         ((nv_qmi_frame_mode_type)2)
  
  #define  NV_QMI_DEVSTREAM_CONTROL                      ((nv_qmi_device_stream_type)1)
  
  #define  NV_QMI_DEVSTREAM_PRIMARY                      ((nv_qmi_device_stream_type)2)

/* Enumeration of supported EPZID types */
typedef  word  nv_epzid_enum_type;
  
  #define  NV_EPZID_PZID                                 ((nv_epzid_enum_type)0)
  
  #define  NV_EPZID_PZID_SID                             ((nv_epzid_enum_type)1)
  
  #define  NV_EPZID_PZID_SID_NID                         ((nv_epzid_enum_type)2)

/* current active device */
typedef  word  nv_usbdc_supported_device_type;
  
  #define  NV_USBDC_MODEM_DEVICE                         ((nv_usbdc_supported_device_type)0)
  
  #define  NV_USBDC_NETWORK_DEVICE                       ((nv_usbdc_supported_device_type)1)
  
  #define  NV_USBDC_MASS_STORAGE_DEVICE                  ((nv_usbdc_supported_device_type)2)
  
  #define  NV_USBDC_BREW_EXTENDED_DEVICE                 ((nv_usbdc_supported_device_type)3)
  
  #define  NV_USBDC_PTP_DEVICE                           ((nv_usbdc_supported_device_type)4)
  
  #define  NV_USBDC_MTP_DEVICE                           ((nv_usbdc_supported_device_type)5)
  
  #define  NV_USBDC_MULTI_NETWORK_DEVICE                 ((nv_usbdc_supported_device_type)6)
  
  #define  NV_SET_DATE_FORMAT_INVALID                    ((nv_set_date_format_enum_type)0)
  
  #define  NV_SET_DATE_FORMAT_DD_MM_YYYY                 ((nv_set_date_format_enum_type)1)
  
  #define  NV_SET_DATE_FORMAT_MM_DD_YYYY                 ((nv_set_date_format_enum_type)2)
  
  #define  NV_SET_DATE_FORMAT_YYYY_MM_DD_1               ((nv_set_date_format_enum_type)3)
  
  #define  NV_SET_DATE_FORMAT_YYYY_MM_DD_2               ((nv_set_date_format_enum_type)4)
  
  #define  NV_SET_DATE_FORMAT_DD_MM_YYYY_2               ((nv_set_date_format_enum_type)5)
  
  #define  NV_SET_TIME_FORMAT_INVALID                    ((nv_set_time_format_enum_type)0)
  
  #define  NV_SET_TIME_FORMAT_24_HOUR                    ((nv_set_time_format_enum_type)1)
  
  #define  NV_SET_TIME_FORMAT_12_HOUR                    ((nv_set_time_format_enum_type)2)

typedef  word  nv_chg_usb_nvswitch_type;
  
  #define  NV_CHG_USB_NVSWITCH_ENA                       ((nv_chg_usb_nvswitch_type)0)
  
  #define  NV_CHG_USB_NVSWITCH_DIS                       ((nv_chg_usb_nvswitch_type)1)
  
  #define  NV_WC_AUTO                                    ((nv_wclock_auto_nitz_enum_type)0)
  
  #define  NV_WC_PROMPT                                  ((nv_wclock_auto_nitz_enum_type)1)
  
  #define  NV_WC_OFF                                     ((nv_wclock_auto_nitz_enum_type)2)

typedef  word  nv_timezone_enum_type;
  
  #define  NV_TZ_INVALID                                 ((nv_timezone_enum_type)0)
  
  #define  NV_TZ_GMT_MINUS_1100                          ((nv_timezone_enum_type)1)
  
  #define  NV_TZ_GMT_MINUS_1000_1                        ((nv_timezone_enum_type)2)
  
  #define  NV_TZ_GMT_MINUS_1000                          ((nv_timezone_enum_type)3)
  
  #define  NV_TZ_GMT_MINUS_0930                          ((nv_timezone_enum_type)4)
  
  #define  NV_TZ_GMT_MINUS_0900_1                        ((nv_timezone_enum_type)5)
  
  #define  NV_TZ_GMT_MINUS_0900                          ((nv_timezone_enum_type)6)
  
  #define  NV_TZ_GMT_MINUS_0800_1                        ((nv_timezone_enum_type)7)
  
  #define  NV_TZ_GMT_MINUS_0800                          ((nv_timezone_enum_type)8)
  
  #define  NV_TZ_GMT_MINUS_0700_1                        ((nv_timezone_enum_type)9)
  
  #define  NV_TZ_GMT_MINUS_0700                          ((nv_timezone_enum_type)10)
  
  #define  NV_TZ_GMT_MINUS_0600_1                        ((nv_timezone_enum_type)11)
  
  #define  NV_TZ_GMT_MINUS_0600_2                        ((nv_timezone_enum_type)12)
  
  #define  NV_TZ_GMT_MINUS_0600_3                        ((nv_timezone_enum_type)13)
  
  #define  NV_TZ_GMT_MINUS_0600                          ((nv_timezone_enum_type)14)
  
  #define  NV_TZ_GMT_MINUS_0500_1                        ((nv_timezone_enum_type)15)
  
  #define  NV_TZ_GMT_MINUS_0500_2                        ((nv_timezone_enum_type)16)
  
  #define  NV_TZ_GMT_MINUS_0500_3                        ((nv_timezone_enum_type)17)
  
  #define  NV_TZ_GMT_MINUS_0500                          ((nv_timezone_enum_type)18)
  
  #define  NV_TZ_GMT_MINUS_0400_1                        ((nv_timezone_enum_type)19)
  
  #define  NV_TZ_GMT_MINUS_0400_2                        ((nv_timezone_enum_type)20)
  
  #define  NV_TZ_GMT_MINUS_0400_3                        ((nv_timezone_enum_type)21)
  
  #define  NV_TZ_GMT_MINUS_0400_4                        ((nv_timezone_enum_type)22)
  
  #define  NV_TZ_GMT_MINUS_0400_5                        ((nv_timezone_enum_type)23)
  
  #define  NV_TZ_GMT_MINUS_0400                          ((nv_timezone_enum_type)24)
  
  #define  NV_TZ_GMT_MINUS_0330_1                        ((nv_timezone_enum_type)25)
  
  #define  NV_TZ_GMT_MINUS_0300_1                        ((nv_timezone_enum_type)26)
  
  #define  NV_TZ_GMT_MINUS_0300_2                        ((nv_timezone_enum_type)27)
  
  #define  NV_TZ_GMT_MINUS_0300                          ((nv_timezone_enum_type)28)
  
  #define  NV_TZ_GMT_MINUS_0200                          ((nv_timezone_enum_type)29)
  
  #define  NV_TZ_GMT_MINUS_0100_1                        ((nv_timezone_enum_type)30)
  
  #define  NV_TZ_GMT_MINUS_0100                          ((nv_timezone_enum_type)31)
  
  #define  NV_TZ_GMT_MINUS_0000_1                        ((nv_timezone_enum_type)32)
  
  #define  NV_TZ_GMT_MINUS_0000                          ((nv_timezone_enum_type)33)
  
  #define  NV_TZ_GMT_PLUS_0100_1                         ((nv_timezone_enum_type)34)
  
  #define  NV_TZ_GMT_PLUS_0100_2                         ((nv_timezone_enum_type)35)
  
  #define  NV_TZ_GMT_PLUS_0100                           ((nv_timezone_enum_type)36)
  
  #define  NV_TZ_GMT_PLUS_0200_1                         ((nv_timezone_enum_type)37)
  
  #define  NV_TZ_GMT_PLUS_0200_2                         ((nv_timezone_enum_type)38)
  
  #define  NV_TZ_GMT_PLUS_0200_3                         ((nv_timezone_enum_type)39)
  
  #define  NV_TZ_GMT_PLUS_0200_5                         ((nv_timezone_enum_type)40)
  
  #define  NV_TZ_GMT_PLUS_0200_6                         ((nv_timezone_enum_type)41)
  
  #define  NV_TZ_GMT_PLUS_0200_7                         ((nv_timezone_enum_type)42)
  
  #define  NV_TZ_GMT_PLUS_0200                           ((nv_timezone_enum_type)43)
  
  #define  NV_TZ_GMT_PLUS_0300_1                         ((nv_timezone_enum_type)44)
  
  #define  NV_TZ_GMT_PLUS_0300_2                         ((nv_timezone_enum_type)45)
  
  #define  NV_TZ_GMT_PLUS_0300_3                         ((nv_timezone_enum_type)46)
  
  #define  NV_TZ_GMT_PLUS_0300                           ((nv_timezone_enum_type)47)
  
  #define  NV_TZ_GMT_PLUS_0330_1                         ((nv_timezone_enum_type)48)
  
  #define  NV_TZ_GMT_PLUS_0400_1                         ((nv_timezone_enum_type)49)
  
  #define  NV_TZ_GMT_PLUS_0400                           ((nv_timezone_enum_type)50)
  
  #define  NV_TZ_GMT_PLUS_0430                           ((nv_timezone_enum_type)51)
  
  #define  NV_TZ_GMT_PLUS_0500_1                         ((nv_timezone_enum_type)52)
  
  #define  NV_TZ_GMT_PLUS_0500_2                         ((nv_timezone_enum_type)53)
  
  #define  NV_TZ_GMT_PLUS_0530                           ((nv_timezone_enum_type)54)
  
  #define  NV_TZ_GMT_PLUS_0545                           ((nv_timezone_enum_type)55)
  
  #define  NV_TZ_GMT_PLUS_0600_1                         ((nv_timezone_enum_type)56)
  
  #define  NV_TZ_GMT_PLUS_0600                           ((nv_timezone_enum_type)57)
  
  #define  NV_TZ_GMT_PLUS_0630                           ((nv_timezone_enum_type)58)
  
  #define  NV_TZ_GMT_PLUS_0700_1                         ((nv_timezone_enum_type)59)
  
  #define  NV_TZ_GMT_PLUS_0700_2                         ((nv_timezone_enum_type)60)
  
  #define  NV_TZ_GMT_PLUS_0700                           ((nv_timezone_enum_type)61)
  
  #define  NV_TZ_GMT_PLUS_0800_1                         ((nv_timezone_enum_type)62)
  
  #define  NV_TZ_GMT_PLUS_0800                           ((nv_timezone_enum_type)63)
  
  #define  NV_TZ_GMT_PLUS_0900                           ((nv_timezone_enum_type)64)
  
  #define  NV_TZ_GMT_PLUS_0930_1                         ((nv_timezone_enum_type)65)
  
  #define  NV_TZ_GMT_PLUS_0930                           ((nv_timezone_enum_type)66)
  
  #define  NV_TZ_GMT_PLUS_1000_1                         ((nv_timezone_enum_type)67)
  
  #define  NV_TZ_GMT_PLUS_1000_2                         ((nv_timezone_enum_type)68)
  
  #define  NV_TZ_GMT_PLUS_1000_3                         ((nv_timezone_enum_type)69)
  
  #define  NV_TZ_GMT_PLUS_1000                           ((nv_timezone_enum_type)70)
  
  #define  NV_TZ_GMT_PLUS_1030                           ((nv_timezone_enum_type)71)
  
  #define  NV_TZ_GMT_PLUS_1100_1                         ((nv_timezone_enum_type)72)
  
  #define  NV_TZ_GMT_PLUS_1100                           ((nv_timezone_enum_type)73)
  
  #define  NV_TZ_GMT_PLUS_1130                           ((nv_timezone_enum_type)74)
  
  #define  NV_TZ_GMT_PLUS_1200_1                         ((nv_timezone_enum_type)75)
  
  #define  NV_TZ_GMT_PLUS_1200_2                         ((nv_timezone_enum_type)76)
  
  #define  NV_TZ_GMT_PLUS_1200                           ((nv_timezone_enum_type)77)
  
  #define  NV_TZ_GMT_PLUS_1245_1                         ((nv_timezone_enum_type)78)
  
  #define  NV_TZ_GMT_PLUS_1300_1                         ((nv_timezone_enum_type)79)
  
  #define  NV_TZ_GMT_PLUS_1400                           ((nv_timezone_enum_type)80)

typedef PACKED struct PACKED_POST{ 
  /* entry index poiting to the profile to which the nai is applicable */
  uint8                                            index;
  /* length of the NAI in number of bytes */
  uint8                                            nai_length;
  /* nai bytes */
  uint8                                            nai[NV_MAX_NAI_LENGTH];
} nv_ds_mip_rm_nai_type;
  
  #define  NV_MMS_SENDER_VISIBILITY_HIDE                 ((nv_mms_hide_number_enum_type)0)
  
  #define  NV_MMS_SENDER_VISIBILITY_SHOW                 ((nv_mms_hide_number_enum_type)1)
  
  #define  NV_MMS_PRIORITY_NOT_SET                       ((nv_mms_default_priority_enum_type)0)
  
  #define  NV_MMS_PRIORITY_HIGHEST                       ((nv_mms_default_priority_enum_type)1)
  
  #define  NV_MMS_PRIORITY_HIGH                          ((nv_mms_default_priority_enum_type)2)
  
  #define  NV_MMS_PRIORITY_NORMAL                        ((nv_mms_default_priority_enum_type)3)
  
  #define  NV_MMS_PRIORITY_LOW                           ((nv_mms_default_priority_enum_type)4)
  
  #define  NV_MMS_PRIORITY_LOWEST                        ((nv_mms_default_priority_enum_type)5)
  
  #define  NV_MMS_VALIDITY_PERIOD_MAX                    ((nv_mms_relative_validity_period_enum_type)0)
  
  #define  NV_MMS_VALIDITY_PERIOD_1_WEEK                 ((nv_mms_relative_validity_period_enum_type)1)
  
  #define  NV_MMS_VALIDITY_PERIOD_2_DAYS                 ((nv_mms_relative_validity_period_enum_type)2)
  
  #define  NV_MMS_VALIDITY_PERIOD_1_DAY                  ((nv_mms_relative_validity_period_enum_type)3)
  
  #define  NV_MMS_SLIDE_DURATION_2_SECONDS               ((nv_mms_slide_default_duration_enum_type)0)
  
  #define  NV_MMS_SLIDE_DURATION_5_SECONDS               ((nv_mms_slide_default_duration_enum_type)1)
  
  #define  NV_MMS_SLIDE_DURATION_10_SECONDS              ((nv_mms_slide_default_duration_enum_type)2)
  
  #define  NV_MMS_SLIDE_DURATION_20_SECONDS              ((nv_mms_slide_default_duration_enum_type)3)
  
  #define  NV_MMS_SLIDE_DURATION_30_SECONDS              ((nv_mms_slide_default_duration_enum_type)4)
  
  #define  NV_MMS_RETRIEVAL_AUTOMATIC                    ((nv_mms_retrieval_enum_type)0)
  
  #define  NV_MMS_RETRIEVAL_ALWAYS_ASK                   ((nv_mms_retrieval_enum_type)1)
  
  #define  NV_MMS_RETRIEVAL_RESTRICTED                   ((nv_mms_retrieval_enum_type)2)
  
  #define  NV_MMS_DELIVERY_TIME_IMMEDIATE                ((nv_mms_delivery_time_enum_type)0)
  
  #define  NV_MMS_DELIVERY_TIME_1_HOUR                   ((nv_mms_delivery_time_enum_type)1)
  
  #define  NV_MMS_DELIVERY_TIME_3_HOURS                  ((nv_mms_delivery_time_enum_type)2)
  
  #define  NV_MMS_DELIVERY_TIME_6_HOURS                  ((nv_mms_delivery_time_enum_type)3)
  
  #define  NV_MMS_DELIVERY_TIME_12_HOURS                 ((nv_mms_delivery_time_enum_type)4)
  
  #define  NV_MMS_DELIVERY_TIME_1_DAY                    ((nv_mms_delivery_time_enum_type)5)
  
  #define  NV_MMS_DELIVERY_TIME_3_DAYS                   ((nv_mms_delivery_time_enum_type)6)
  
  #define  NV_MMS_DELIVERY_TIME_7_DAYS                   ((nv_mms_delivery_time_enum_type)7)
  
  #define  NV_MMS_CREATION_MODE_FREE                     ((nv_mms_creation_mode_enum_type)0)
  
  #define  NV_MMS_CREATION_MODE_WARN                     ((nv_mms_creation_mode_enum_type)1)
  
  #define  NV_MMS_CREATION_MODE_RESTRICTED               ((nv_mms_creation_mode_enum_type)2)
  
  #define  NV_SCREENSAVER_STYLE_NONE                     ((nv_screensaver_style_enum_type)0)
  
  #define  NV_SCREENSAVER_STYLE_PICTURE                  ((nv_screensaver_style_enum_type)1)
  
  #define  NV_SCREENSAVER_STYLE_ENERGY_SAVING            ((nv_screensaver_style_enum_type)2)
  
  #define  NV_SCREENSAVER_STYLE_DIGITAL_CLOCK            ((nv_screensaver_style_enum_type)3)
  
  #define  NV_SCREENSAVER_STYLE_ANALOG_CLOCK             ((nv_screensaver_style_enum_type)4)
  
  #define  NV_MMS_FONT_SIZE_LARGE                        ((nv_messaging_font_enum_type)0)
  
  #define  NV_MMS_FONT_SIZE_STANDARD                     ((nv_messaging_font_enum_type)1)
  
  #define  NV_MMS_FONT_SIZE_SMALL                        ((nv_messaging_font_enum_type)2)
  
  #define  NV_SYNCDIRECTION_TWO_WAY                      ((nv_syncml_syncdirection_enum_type)0)
  
  #define  NV_SYNCDIRECTION_MOBILE_OVERWRITES            ((nv_syncml_syncdirection_enum_type)1)
  
  #define  NV_SYNCDIRECTION_SERVER_OVERWRITES            ((nv_syncml_syncdirection_enum_type)2)
  
  #define  NV_DATATOSYNC_MODIFIED_ONLY                   ((nv_syncml_datatosync_enum_type)0)
  
  #define  NV_DATATOSYNC_ALL_DATA                        ((nv_syncml_datatosync_enum_type)1)
  
  #define  NV_APPSTOSYNC_NONE                            ((nv_syncml_appstosync_enum_type)0)
  
  #define  NV_APPSTOSYNC_CONTACTS                        ((nv_syncml_appstosync_enum_type)1)
  
  #define  NV_APPSTOSYNC_CALENDAR                        ((nv_syncml_appstosync_enum_type)2)
  
  #define  NV_APPSTOSYNC_CONTACTS_CALENDAR               ((nv_syncml_appstosync_enum_type)3)
  
  #define  NV_SMS_TEXT_SIZE_SMALL                        ((nv_ms_sms_text_size_enum_type)0)
  
  #define  NV_SMS_TEXT_SIZE_MEDIUM                       ((nv_ms_sms_text_size_enum_type)1)
  
  #define  NV_SMS_TEXT_SIZE_LARGE                        ((nv_ms_sms_text_size_enum_type)2)
  
  #define  NV_IM_ENCODING_METHOD_UNKNOWN                 ((nv_im_encoding_method_enum_type)0)
  
  #define  NV_IM_ENCODING_METHOD_XML                     ((nv_im_encoding_method_enum_type)1)
  
  #define  NV_IM_ENCODING_METHOD_SMS                     ((nv_im_encoding_method_enum_type)2)
  
  #define  NV_IM_ENCODING_METHOD_WBXML                   ((nv_im_encoding_method_enum_type)3)
  
  #define  NV_IM_WV_VERSION_WV1_1                        ((nv_im_wv_version_enum_type)0)
  
  #define  NV_IM_WV_VERSION_WV1_2                        ((nv_im_wv_version_enum_type)1)

typedef PACKED struct PACKED_POST{ 
  /* Length of NAI in no. of bytes */
  uint8                                            nai_length;
  /* bytes ( characters) of NAI */
  uint8                                            nai[NV_MAX_NAI_LENGTH];
} nv_ds_sip_rm_nai_type;
  
  #define  NV_IRDA_FILE_LOCATION_INVALID                 ((nv_irda_file_location_enum_type)0)
  
  #define  NV_IRDA_FILE_LOCATION_PHONE                   ((nv_irda_file_location_enum_type)1)
  
  #define  NV_IRDA_FILE_LOCATION_MMC_CARD                ((nv_irda_file_location_enum_type)2)
  
  #define  NV_WB_MAILTO_PHONENUM_SMS                     ((nv_wb_mailto_phonenum_enum_type)0)
  
  #define  NV_WB_MAILTO_PHONENUM_MMS                     ((nv_wb_mailto_phonenum_enum_type)1)
  
  #define  NV_WB_MAILTO_PHONENUM_PROMPT                  ((nv_wb_mailto_phonenum_enum_type)2)

typedef  word  nv_wb_mailto_email_enum_type;
  
  #define  NV_WB_MAILTO_EMAIL_EMAIL                      ((nv_wb_mailto_email_enum_type)0)
  
  #define  NV_WB_MAILTO_EMAIL_MMS                        ((nv_wb_mailto_email_enum_type)1)
  
  #define  NV_WB_MAILTO_EMAIL_PROMPT                     ((nv_wb_mailto_email_enum_type)2)
  
  #define  NV_ENV_ACTIVE_PROFILE_GENERAL                 ((nv_currently_active_profile_enum_type)1)
  
  #define  NV_ENV_ACTIVE_PROFILE_SILENT                  ((nv_currently_active_profile_enum_type)2)
  
  #define  NV_ENV_ACTIVE_PROFILE_MEETING                 ((nv_currently_active_profile_enum_type)3)
  
  #define  NV_ENV_ACTIVE_PROFILE_OUTDOOR                 ((nv_currently_active_profile_enum_type)4)
  
  #define  NV_ENV_ACTIVE_PROFILE_USER_PROFILE_1          ((nv_currently_active_profile_enum_type)5)
  
  #define  NV_ENV_ACTIVE_PROFILE_USER_PROFILE_2          ((nv_currently_active_profile_enum_type)6)
  
  #define  NV_ENV_ACTIVE_PROFILE_CAR_KIT                 ((nv_currently_active_profile_enum_type)7)
  
  #define  NV_ENV_ACTIVE_PROFILE_HEADSET                 ((nv_currently_active_profile_enum_type)8)
  
  #define  NV_POC_AUTO_LOGIN_ALWAYS                      ((nv_auto_login_enum_type)0)
  
  #define  NV_POC_AUTO_LOGIN_NEVER                       ((nv_auto_login_enum_type)1)
  
  #define  NV_POC_AUTO_LOGIN_HOME_NETWORK                ((nv_auto_login_enum_type)2)
  
  #define  NV_POC_WILDCARD_OFF                           ((nv_poc_wildcards_enum_type)0)
  
  #define  NV_POC_WILDCARD_ACCEPT_ALL                    ((nv_poc_wildcards_enum_type)1)
  
  #define  NV_POC_WILDCARD_BLOCK_ALL                     ((nv_poc_wildcards_enum_type)2)
  
  #define  NV_IM_NOTIFICATION_RECEIVE                    ((nv_im_notification_enum_type)0)
  
  #define  NV_IM_NOTIFICATION_NONE                       ((nv_im_notification_enum_type)1)
  
  #define  NV_IM_NOTIFICATION_AUTH_REQUIRED              ((nv_im_notification_enum_type)2)
  
  #define  NV_IM_LOGIN_NORMAL                            ((nv_im_login_enum_type)0)
  
  #define  NV_IM_LOGIN_AUTO4WAY                          ((nv_im_login_enum_type)1)
  
  #define  NV_IM_LOGIN_AUTOAOL                           ((nv_im_login_enum_type)2)
  
  #define  NV_IM_LOGIN_LAST                              ((nv_im_login_enum_type)3)
  
  #define  NV_IM_DELIVERY_METHOD_NOT_SET                 ((nv_im_delivery_method_enum_type)0)
  
  #define  NV_IM_DELIVERY_METHOD_PUSH                    ((nv_im_delivery_method_enum_type)1)
  
  #define  NV_IM_DELIVERY_METHOD_NOTIFY_GET              ((nv_im_delivery_method_enum_type)2)
  
  #define  NV_RINGTONE_TONE_SETTING_INVALID              ((nv_ringtone_tone_setting_enum_type)0)
  
  #define  NV_RINGTONE_TONE_SETTING_ON                   ((nv_ringtone_tone_setting_enum_type)1)
  
  #define  NV_RINGTONE_TONE_SETTING_OFF                  ((nv_ringtone_tone_setting_enum_type)2)
  
  #define  NV_RINGTONE_TONE_SETTING_BEEP                 ((nv_ringtone_tone_setting_enum_type)3)
  
  #define  NV_RINGTONE_TONE_SETTING_ASCENDING            ((nv_ringtone_tone_setting_enum_type)4)
  
  #define  NV_WB_SEND_URL_BKMARK_SMS                     ((nv_wb_send_url_bkmark_enum_type)0)
  
  #define  NV_WB_SEND_URL_BKMARK_MMS                     ((nv_wb_send_url_bkmark_enum_type)1)
  
  #define  NV_WB_SEND_URL_BKMARK_EMAIL                   ((nv_wb_send_url_bkmark_enum_type)2)
  
  #define  NV_WB_SEND_URL_BKMARK_PROMPT                  ((nv_wb_send_url_bkmark_enum_type)3)
  
  #define  NV_WB_WAPTIMEOUT_30                           ((nv_wb_browser_timeout_enum_type)0)
  
  #define  NV_WB_WAPTIMEOUT_60                           ((nv_wb_browser_timeout_enum_type)1)
  
  #define  NV_WB_WAPTIMEOUT_NO_LIMIT                     ((nv_wb_browser_timeout_enum_type)2)
  
  #define  NV_WB_FONTSIZE_VERY_SMALL                     ((nv_wb_fontsize_enum_type)0)
  
  #define  NV_WB_FONTSIZE_SMALL                          ((nv_wb_fontsize_enum_type)1)
  
  #define  NV_WB_FONTSIZE_MEDIUM                         ((nv_wb_fontsize_enum_type)2)
  
  #define  NV_WB_FONTSIZE_LARGE                          ((nv_wb_fontsize_enum_type)3)
  
  #define  NV_WB_TEXTWRAP_CHAR                           ((nv_wb_textwrap_enum_type)0)
  
  #define  NV_WB_TEXTWRAP_WORD                           ((nv_wb_textwrap_enum_type)1)
  
  #define  NV_WB_SCROLLSTEP_SINGLE                       ((nv_wb_scrollstep_enum_type)0)
  
  #define  NV_WB_SCROLLSTEP_HALF                         ((nv_wb_scrollstep_enum_type)1)
  
  #define  NV_WB_SCROLLSTEP_WHOLE                        ((nv_wb_scrollstep_enum_type)2)

typedef  word  nv_ringer_volume_enum_type;
  
  #define  NV_RINGER_VOLUME_INVALID                      ((nv_ringer_volume_enum_type)0)
  
  #define  NV_RINGER_VOLUME_LEVEL_1                      ((nv_ringer_volume_enum_type)1)
  
  #define  NV_RINGER_VOLUME_LEVEL_2                      ((nv_ringer_volume_enum_type)2)
  
  #define  NV_RINGER_VOLUME_LEVEL_3                      ((nv_ringer_volume_enum_type)3)
  
  #define  NV_RINGER_VOLUME_LEVEL_4                      ((nv_ringer_volume_enum_type)4)
  
  #define  NV_RINGER_VOLUME_LEVEL_5                      ((nv_ringer_volume_enum_type)5)
  
  #define  NV_RINGER_VOLUME_OFF                          ((nv_ringer_volume_enum_type)6)
  
  #define  NV_SET_SIM_PHONENUMBER_INVALID                ((nv_set_sim_phone_number_enum_type)0)
  
  #define  NV_SET_SIM_PHONENUMBER_PRIVATE                ((nv_set_sim_phone_number_enum_type)1)
  
  #define  NV_SET_SIM_PHONENUMBER_MOBILEPRIVATE          ((nv_set_sim_phone_number_enum_type)2)
  
  #define  NV_SET_SIM_PHONENUMBER_BUSINESS               ((nv_set_sim_phone_number_enum_type)3)
  
  #define  NV_PB_SORT_FIRST_NAME                         ((nv_pb_default_sort_order_enum_type)0)
  
  #define  NV_PB_SORT_LAST_NAME                          ((nv_pb_default_sort_order_enum_type)1)
  
  #define  NV_LC_TICKERSPEED_FAST                        ((nv_lc_tickerspeed_type)1)
  
  #define  NV_LC_TICKERSPEED_MEDIUM                      ((nv_lc_tickerspeed_type)3)
  
  #define  NV_LC_TICKERSPEED_SLOW                        ((nv_lc_tickerspeed_type)5)
  
  #define  NV_LC_NUMTICKERMSGS_1                         ((nv_lc_numtickermsgs_enum_type)1)
  
  #define  NV_LC_NUMTICKERMSGS_3                         ((nv_lc_numtickermsgs_enum_type)3)
  
  #define  NV_LC_NUMTICKERMSGS_5                         ((nv_lc_numtickermsgs_enum_type)5)
  
  #define  NV_LC_NUMTICKERMSGS_10                        ((nv_lc_numtickermsgs_enum_type)10)
  
  #define  SCREEN_LAYOUT_ORANGE                          ((nv_home_screen_enum_type)0)
  
  #define  SCREEN_LAYOUT_ORANGE_BUSINESS                 ((nv_home_screen_enum_type)1)
  
  #define  SCREEN_LAYOUT_STANDARD                        ((nv_home_screen_enum_type)2)
  
  #define  NV_MMS_TEXT_SIZE_SMALL                        ((nv_mms_text_size_enum_type)0)
  
  #define  NV_MMS_TEXT_SIZE_MEDIUM                       ((nv_mms_text_size_enum_type)1)
  
  #define  NV_MMS_TEXT_SIZE_LARGE                        ((nv_mms_text_size_enum_type)2)
  
  #define  NV_SET_VOLUME_INVALID                         ((nv_set_volume_enum_type)0)
  
  #define  NV_SET_VOLUME_LEVEL_1                         ((nv_set_volume_enum_type)1)
  
  #define  NV_SET_VOLUME_LEVEL_2                         ((nv_set_volume_enum_type)2)
  
  #define  NV_SET_VOLUME_LEVEL_3                         ((nv_set_volume_enum_type)3)
  
  #define  NV_SET_VOLUME_LEVEL_4                         ((nv_set_volume_enum_type)4)
  
  #define  NV_SET_VOLUME_LEVEL_5                         ((nv_set_volume_enum_type)5)
  
  #define  NV_SET_VOLUME_OFF                             ((nv_set_volume_enum_type)6)

typedef PACKED struct PACKED_POST{ 
  /* Limit RF assignments for simulating reduced h/w capability. */
  nv_trm_rf_enum                                   rf_config;
  /* Bit field for disallowing certain mode combinations */
  uint32                                           mask;
} nv_trm_config_type;

typedef PACKED struct PACKED_POST{ 
  /* Autoconnect settings for rmnet devices */
  uint8                                            index;
  /* When true, rmnet device will automatically make a call when connected/enabled */
  boolean                                          enable;
} nv_rmnet_autoconnect_type;

typedef PACKED struct PACKED_POST{ 
  /* PLMN Name from NITZ */
  uint8                                            plmn_name[NV_MAX_NW_NAME_CHARS];
} nv_nitz_plmn_type;

/* Enumeration of supported QoS modes */
typedef  word  nv_wlan_qos_mode_enum_type;
  
  #define  NV_WLAN_QOS_MODE_AUTO                         ((nv_wlan_qos_mode_enum_type)0)
  
  #define  NV_WLAN_QOS_MODE_QBSS_ONLY                    ((nv_wlan_qos_mode_enum_type)1)
  
  #define  NV_WLAN_QOS_MODE_NO_QOS                       ((nv_wlan_qos_mode_enum_type)2)

/* Enumeration of supported OEM index */
typedef  word  nv_wlan_oem_index_enum_type;
  
  #define  NV_WLAN_OEM_INDEX_PHG                         ((nv_wlan_oem_index_enum_type)0)
  
  #define  NV_WLAN_OEM_INDEX_ATH                         ((nv_wlan_oem_index_enum_type)1)

typedef PACKED struct PACKED_POST{ 
  /* Key length in octets - either 96 or 128 */
  uint16                                           key_len;
  /* If the keys (rpc_auth_key) are valid */
  boolean                                          keys_are_valid;
  /* Storage for the derived keys */
  uint8                                            rpc_auth_key[NV_HDRKEP_KEY_SIG_LEN];
} nv_hdrkep_config_params_type;

typedef PACKED struct PACKED_POST{ 
  
  nv_hdrkep_config_params_type                     kep_config[NV_HDRSCMDB_MAX_PERSONALITIES];
  /* SHA-1 Hash of SCM DB */
  uint8                                            hash[NV_SECAPI_HSH_SHA_DIGEST_SIZE];
} nv_hdrscmdb_secure_config_type;
  
  #define  NV_SCUDIF_PREFER_NONE                         ((nv_scudif_callsetup_pref_enum_type)0)
  
  #define  NV_SCUDIF_PREFER_VOICE                        ((nv_scudif_callsetup_pref_enum_type)1)
  
  #define  NV_SCUDIF_PREFER_VIDEO                        ((nv_scudif_callsetup_pref_enum_type)2)
  
  #define  NV_SCUDIF_PREFER_VOICE_ONLY                   ((nv_scudif_callsetup_pref_enum_type)3)
  
  #define  NV_SCUDIF_PREFER_VIDEO_ONLY                   ((nv_scudif_callsetup_pref_enum_type)4)

typedef PACKED struct PACKED_POST{ 
  /* length of password */
  uint8                                            password_len;
  /* the password */
  uint8                                            password[NV_MAX_GPSONE_PASSWORD_LENGTH];
} nv_gpsone_password_type;

typedef PACKED struct PACKED_POST{ 
  /* type of the apps DCVS algo. implemented */
  uint8                                            type;
  /* the profiling timer period */
  uint32                                           timer_period;
  /* lower votes in decision history */
  uint8                                            lower_n;
  /* raise votes in decision history */
  uint8                                            raise_n;
  /* high threshhold for lowering the performance level */
  uint32                                           high_watermark;
  /* low threshhold for lowing the performance level */
  uint32                                           low_watermark;
} nv_dcvsapps_type;

typedef PACKED struct PACKED_POST{ 
  /* IPv6 Privacy Extensions Configuration */
  uint32                                           ipv6_priv_preferred_lifetime;
  /* IPv6 Privacy Extensions Valid Lifetime */
  uint32                                           ipv6_priv_valid_lifetime;
} nv_ipv6_priv_addr_config;

/* Type for the Supported High Speed USB Compositions */
typedef  word  nv_hs_usb_supported_compositions_type;
  
  #define  NV_HS_USB_DIAG_NMEA_MDM                       ((nv_hs_usb_supported_compositions_type)0)
  
  #define  NV_HS_USB_DIAG_NMEA_MDM_NET                   ((nv_hs_usb_supported_compositions_type)1)
  
  #define  NV_HS_USB_DIAG_NMEA_MS_MDM_NET                ((nv_hs_usb_supported_compositions_type)2)
  
  #define  NV_HS_USB_MS                                  ((nv_hs_usb_supported_compositions_type)3)
  
  #define  NV_HS_USB_MTP                                 ((nv_hs_usb_supported_compositions_type)4)
  
  #define  NV_HS_USB_DIAG_MDM                            ((nv_hs_usb_supported_compositions_type)5)
  
  #define  NV_HS_USB_DIAG_MDM_NET                        ((nv_hs_usb_supported_compositions_type)6)
  
  #define  NV_HS_USB_DIAG_MS                             ((nv_hs_usb_supported_compositions_type)7)
  
  #define  NV_HS_USB_LOOPBACK                            ((nv_hs_usb_supported_compositions_type)8)
  
  #define  NV_HS_USB_DIAG_NMEA_MS_MDM_NET_AUDIO          ((nv_hs_usb_supported_compositions_type)9)
  
  #define  NV_HS_USB_DIAG_NMEA_SER3_MDM_NET              ((nv_hs_usb_supported_compositions_type)10)
  
  #define  NV_HS_USB_NET_DIAG_MDM_NMEA                   ((nv_hs_usb_supported_compositions_type)11)
  
  #define  NV_HS_USB_NET_DIAG_MDM                        ((nv_hs_usb_supported_compositions_type)12)
  
  #define  NV_HS_USB_NET_DIAG_NMEA                       ((nv_hs_usb_supported_compositions_type)13)
  
  #define  NV_HS_USB_NET_DIAG                            ((nv_hs_usb_supported_compositions_type)14)
  
  #define  NV_HS_USB_STD_NET                             ((nv_hs_usb_supported_compositions_type)15)
  
  #define  NV_HS_USB_DIAG_MTP                            ((nv_hs_usb_supported_compositions_type)16)
  
  #define  NV_HS_USB_DIAG_NMEA_MS_MDM_NET3               ((nv_hs_usb_supported_compositions_type)17)
  
  #define  NV_HS_USB_DIAG_NMEA_MS_STD_MDM_STD_NET        ((nv_hs_usb_supported_compositions_type)18)
  
  #define  NV_HS_USB_DIAG_AUDIO                          ((nv_hs_usb_supported_compositions_type)19)
  
  #define  NV_HS_USB_DIAG_NMEA_MDM_NET3                  ((nv_hs_usb_supported_compositions_type)20)
  
  #define  NV_HS_USB_DIAG_NMEA_MS_MDM_NET2               ((nv_hs_usb_supported_compositions_type)21)
  
  #define  NV_HS_USB_DIAG_NMEA_MDM_NET2                  ((nv_hs_usb_supported_compositions_type)22)
  
  #define  NV_HS_USB_BREWMP_COMPOSITION                  ((nv_hs_usb_supported_compositions_type)23)

typedef PACKED struct PACKED_POST{ 
  
  uint16                                           max_nd_solicits;
  
  uint16                                           max_nd_retransmits;
  
  uint16                                           max_nd_reachable_time;
  
  uint16                                           max_nd_delay_first_probe_time;
  
  uint16                                           max_nd_retransmit_interval;
} nv_nd_config_items;

typedef PACKED struct PACKED_POST{ 
  
  uint32                                           ruim_id;
} nv_jcdma_ruimid;

typedef PACKED struct PACKED_POST{ 
  
  uint32                                           ruim_id;
  
  uint16                                           imsi_mcc1;
  
  uint16                                           imsi_mcc2;
  
  uint8                                            sp_id;
  
  uint8                                            ug_id;
  
  boolean                                          indicator[NUM_OF_LOCKS];
} nv_jcdma_uim_lock_data;

/* List of configurations supported by the AT */
typedef  word  nv_hdrscp_force_at_config_type;
  
  #define  NV_HDRSCP_REV0_PROTOCOLS_ONLY                 ((nv_hdrscp_force_at_config_type)0)
  
  #define  NV_HDRSCP_REVA_PROTOCOLS_WITH_MFPA            ((nv_hdrscp_force_at_config_type)1)
  
  #define  NV_HDRSCP_REVA_PROTOCOLS_WITH_MFPA_AND_EMPA   ((nv_hdrscp_force_at_config_type)2)
  
  #define  NV_HDRSCP_REVB_PROTOCOLS_WITH_MMPA            ((nv_hdrscp_force_at_config_type)3)
  
  #define  NV_HDRSCP_REVA_PROTOCOLS_WITH_EHRPD           ((nv_hdrscp_force_at_config_type)4)
  
  #define  NV_HDRSCP_REVB_PROTOCOLS_WITH_EHRPD           ((nv_hdrscp_force_at_config_type)5)

typedef PACKED struct PACKED_POST{ 
  /* DS AT V.250 Registers */
  uint8                                            e_reg_val;
  /* Q Register */
  uint8                                            q_reg_val;
  /* V Register */
  uint8                                            v_reg_val;
  /* X Register */
  uint8                                            x_reg_val;
  /* &C Register */
  uint8                                            amp_c_reg_val;
  /* &D Register */
  uint8                                            amp_d_reg_val;
  /* &S Register */
  uint8                                            amp_s_reg_val;
  /* +IFC Value */
  uint8                                            ifc_reg_val[2];
  /* \V Register */
  uint8                                            slash_v_reg_val;
} nv_ds_at_v250_registers_type;

typedef PACKED struct PACKED_POST{ 
  /* DS AT S Registers */
  uint8                                            s0_reg_val;
  /* S7 Register */
  uint8                                            s7_reg_val;
  /* S10 Register */
  uint8                                            s10_reg_val;
} nv_ds_at_s_registers_type;

typedef PACKED struct PACKED_POST{ 
  /* NV item for AMSS RESTART */
  uint8                                            enable;
  /* timer for resetting the amss restart counts  */
  uint32                                           timer_period;
  /* maximum number of modem restart requests  */
  uint32                                           modem_restart_count;
  /* maximum number of apps restart requests */
  uint32                                           apps_restart_count;
} nv_process_restart_switch_type;

typedef PACKED struct PACKED_POST{ 
  /* CSCA <sca> value */
  uint8                                            sca[NV_CSCA_SCA_STR_MAX_LEN];
  /* CSCA <tosca> value */
  uint8                                            tosca[NV_CSCA_TOSCA_STR_MAX_LEN];
} nv_ds_at_csas_csca_register;

typedef PACKED struct PACKED_POST{ 
  /* CSMP <fo> value */
  uint8                                            fo[NV_CSMP_FO_STR_MAX_LEN];
  /* CMSP <vp> value */
  uint8                                            vp[NV_CSMP_VP_STR__MAX_LEN];
  /* CSMP <pid> value */
  uint8                                            pid;
  /* CSMP <dcs> value */
  uint8                                            dcs;
} nv_ds_at_csas_csmp_settings;

typedef PACKED struct PACKED_POST{ 
  /* CSCB <mode> value */
  uint8                                            mode;
  /* CSCB <mids> value */
  uint8                                            mids[NV_CSCB_MIDS_STR_MAX_LEN];
  /* CSCB <dcss> value */
  uint8                                            dcss[NV_CSCB_DCSS_STR_MAX_LEN];
} nv_ds_at_csas_cscb_settings;

typedef PACKED struct PACKED_POST{ 
  
  uint8                                            index;
  
  uint8                                            app_priority;
  
  uint8                                            data_rate_mode;
  
  uint8                                            data_bearer;
  
  uint8                                            auth_algorithm;
  
  uint32                                           app_type;
} nv_ds_sip_profile_type;

typedef PACKED struct PACKED_POST{ 
  
  uint8                                            index;
  
  uint8                                            nai_length;
  
  uint8                                            nai[126];
} nv_ds_sip_profile_nai_info_type;

typedef PACKED struct PACKED_POST{ 
  
  uint8                                            index;
  
  uint8                                            ss_length;
  
  uint8                                            ss[32];
} nv_ds_sip_ppp_ss_info_type;
  
  #define  NV_HDRSCP_DISABLE_BCMCS                       ((nv_hdrscp_bcmcs_config_enum_type)0)
  
  #define  NV_HDRSCP_ENABLE_GOLD_BCMCS                   ((nv_hdrscp_bcmcs_config_enum_type)1)
  
  #define  NV_HDRSCP_ENABLE_GOLD_AND_PLATINUM_BCMCS      ((nv_hdrscp_bcmcs_config_enum_type)2)
  
  #define  NV_MIPV6_DISABLED                             ((nv_mipv6_behavior_enum_type)0)
  
  #define  NV_MIPV6_TO_SIPV6_FAILOVER                    ((nv_mipv6_behavior_enum_type)1)
  
  #define  NV_MIPV6_REQUIRED                             ((nv_mipv6_behavior_enum_type)2)
  
  #define  NV_MIPV6_IPSEC_PROTECTION                     ((nv_mipv6_protection_method_enum_type)0)
  
  #define  NV_MIPV6_AUTH_PROTECTION                      ((nv_mipv6_protection_method_enum_type)1)

/* WiFi access is allowed/not_allowed for Default Interface.  */
typedef  word  nv_wifi_local_breakout_allowed_enum_type;
  
  #define  NV_BREAKOUT_ALLOWED                           ((nv_wifi_local_breakout_allowed_enum_type)0)
  
  #define  NV_BREAKOUT_NOT_ALLOWED                       ((nv_wifi_local_breakout_allowed_enum_type)1)

/* The IWLAN AUTH Mode used for tunnel establishment */
typedef  word  nv_iwlan_auth_mode_enum_type;
  
  #define  NV_IWLAN_AUTH_EAP_SIM                         ((nv_iwlan_auth_mode_enum_type)1)
  
  #define  NV_IWLAN_AUTH_EAP_AKA                         ((nv_iwlan_auth_mode_enum_type)2)
  
  #define  NV_IWLAN_AUTH_PSK                             ((nv_iwlan_auth_mode_enum_type)3)
  
  #define  NV_IWLAN_AUTH_EAP_TLS                         ((nv_iwlan_auth_mode_enum_type)4)
  
  #define  NV_IWLAN_AUTH_EAP_AKA_CAVE                    ((nv_iwlan_auth_mode_enum_type)5)

/* DH mode type used in IKE. */
typedef  word  nv_iwlan_ike_dh_mode_enum_type;
  
  #define  NV_IWLAN_IKE_DH_GROUP_MODP1024                ((nv_iwlan_ike_dh_mode_enum_type)1)

typedef PACKED struct PACKED_POST{ 
  /* The length of Operator ID. */
  uint8                                            length;
  /* Operator ID String */
  uint8                                            value[NV_IWLAN_MAX_OPERATOR_ID];
} nv_iwlan_operator_id_type;

typedef PACKED struct PACKED_POST{ 
  /* Carrier provided realm string that is used to create NAI. */
  uint8                                            length;
  /* Realm String */
  uint8                                            value[NV_IWLAN_MAX_REALM_LENGTH];
} nv_iwlan_realm_type;

/* BTS Master Clock Reference Value */
typedef  word  nv_ps_bt_soc_refclock_enum_type;
  
  #define  NV_PS_BT_SOC_REFCLOCK_32MHZ                   ((nv_ps_bt_soc_refclock_enum_type)0)
  
  #define  NV_PS_BT_SOC_REFCLOCK_19P2MHZ                 ((nv_ps_bt_soc_refclock_enum_type)1)

/* Provides Information of BTS clk sharing */
typedef  word  nv_ps_bt_soc_clock_sharing_enum_type;
  
  #define  NV_PS_BT_SOC_CLOCK_SHARING_DISABLED           ((nv_ps_bt_soc_clock_sharing_enum_type)0)
  
  #define  NV_PS_BT_SOC_CLOCK_SHARING_ENABLED            ((nv_ps_bt_soc_clock_sharing_enum_type)1)

/* Provides information whether s/w or h/w inband sleep is enabled */
typedef  word  nv_ps_bt_soc_inband_sleep_enum_type;
  
  #define  NV_PS_BT_SOC_HW_INBAND_SLEEP                  ((nv_ps_bt_soc_inband_sleep_enum_type)0)
  
  #define  NV_PS_BT_SOC_SW_INBAND_SLEEP                  ((nv_ps_bt_soc_inband_sleep_enum_type)1)

/* There are three possible modes SMPS, Linear and Bypass (LDO) */
typedef  word  nv_ps_bt_soc_pm_mode_enum_type;
  
  #define  NV_PS_BT_SOC_PM_SMPS_MODE                     ((nv_ps_bt_soc_pm_mode_enum_type)0)
  
  #define  NV_PS_BT_SOC_PM_LINEAR_MODE                   ((nv_ps_bt_soc_pm_mode_enum_type)1)
  
  #define  NV_PS_BT_SOC_PM_LDO_MODE                      ((nv_ps_bt_soc_pm_mode_enum_type)2)

typedef PACKED struct PACKED_POST{ 
  /* The FQDN of the PDIF */
  uint8                                            length;
  /* The FQDN String */
  uint8                                            value[NV_IWLAN_MAX_DOMAIN_NAME_SIZE];
} nv_iwlan_pdif_fqdn_type;

/* Mode of operation of the UE - GAN preferred or cellular only */
typedef  word  NV_GAN_MODE_PREFERENCE;
  
  #define  GAN_DISABLED_MODE                             ((NV_GAN_MODE_PREFERENCE)0)
  
  #define  GAN_PREFERED_MODE                             ((NV_GAN_MODE_PREFERENCE)1)

typedef PACKED struct PACKED_POST{ 
  /* Time to wait after sending a VSNCP Term Request */
  uint32                                           vsncp_term_timeout;
  /* Time to wait for a VSNCP Ack */
  uint32                                           vsncp_ack_timeout;
  /* Number of tries to send out a VSNCP Config Request */
  uint16                                           vsncp_req_try;
  /* Number of tries to send out a VSNCP Termination Request */
  uint16                                           vsncp_term_try;
} nv_ppp_vsncp_config_data_type;

typedef PACKED struct PACKED_POST{ 
  /* Length of the EAP Shared Secret */
  uint8                                            eap_shared_secret_len;
  /* EAP Shared Secret */
  uint8                                            eap_shared_secret[NV_PPP_EAP_MAX_SHARED_SECRET_LENGTH];
} nv_eap_shared_secret_type;

typedef PACKED struct PACKED_POST{ 
  /* WLAN Atheros clk freq, power save mode parameters */
  nv_atheros_clk_freq_type                         atheros_clk_freq_index;
  /* Time the module remains awake between last tx/rx and sleep in milliseconds */
  uint16                                           idle_period;
  /* No. of ps poll msgs to send before awake notification to AP */
  uint16                                           ps_poll_number;
  /* Policy to ignore/stick/normal DTIM processing */
  nv_atheros_dtim_policy_type                      dtim_policy;
} nv_wlan_atheros_specific_cfg;

typedef PACKED struct PACKED_POST{ 
  /* Operator Variant Algorithm Configuration Field */
  uint8                                            ehrpd_milenage_op[NV_EHRPD_MILENAGE_MAX_OP_LENGTH];
  /* OP length */
  uint8                                            ehrpd_milenage_op_length;
} nv_ehrpd_milenage_op_type;

typedef PACKED struct PACKED_POST{ 
  /* MCC part of the IMSI */
  uint8                                            ehrpd_mcc[MAX_MCC_DIGITS];
  /* Number of mcc digits */
  uint8                                            num_of_mcc_digits;
  /* MNC part of IMSI */
  uint8                                            ehrpd_mnc[MAX_MNC_DIGITS];
  /* Number of MNC digits */
  uint8                                            num_of_mnc_digits;
  /* MSIN part of the IMSI */
  uint8                                            ehrpd_msin[MAX_MSIN_DIGITS];
  /* Number of MSIN digits */
  uint8                                            num_of_msin_digits;
} nv_ehrpd_imsi_type;

typedef  word  nv_bt_qsoc_nvm_mode;
  
  #define  BT_QSOC_NVM_AUTO_MODE                         ((nv_bt_qsoc_nvm_mode)0)
  
  #define  BT_QSOC_NVM_EFS_MODE                          ((nv_bt_qsoc_nvm_mode)1)
  
  #define  BT_QSOC_NVM_HYBRID_MODE                       ((nv_bt_qsoc_nvm_mode)2)

typedef  word  nv_bt_qsoc_class_type;
  
  #define  BT_QSOC_CLASS1_TYPE                           ((nv_bt_qsoc_class_type)0)
  
  #define  BT_QSOC_CLASS2_TYPE                           ((nv_bt_qsoc_class_type)1)
  
  #define  nv_prefer_cdma                                ((nv_multimode_system_preference_type)0)
  
  #define  nv_prefer_wcdma                               ((nv_multimode_system_preference_type)1)

/* HS USB Performance Setting Level */
typedef  word  nv_hs_usb_perf_set_level_enum_type;
  
  #define  NV_HS_USB_PERF_SET_LEVEL_LOW                  ((nv_hs_usb_perf_set_level_enum_type)0)
  
  #define  NV_HS_USB_PERF_SET_LEVEL_MID                  ((nv_hs_usb_perf_set_level_enum_type)1)
  
  #define  NV_HS_USB_PERF_SET_LEVEL_HIGH                 ((nv_hs_usb_perf_set_level_enum_type)2)

/* Enumeration of supported PAL link preferences */
typedef  word  nv_wlan_pal_link_pref_enum_type;
  
  #define  WLAN_PAL_IFACE_PREF_WLAN_ONLY                 ((nv_wlan_pal_link_pref_enum_type)0)
  
  #define  WLAN_PAL_IFACE_PREF_PAL                       ((nv_wlan_pal_link_pref_enum_type)1)
  
  #define  WLAN_PAL_IFACE_PREF_WLAN                      ((nv_wlan_pal_link_pref_enum_type)2)
  
  #define  NV_WWAN_NO_PREFERENCE                         ((nv_gnss_wwan_network_pref_enum_type)0)
  
  #define  NV_WWAN_HOME_ONLY                             ((nv_gnss_wwan_network_pref_enum_type)1)
  
  #define  NV_WWAN_ROAM_ONLY                             ((nv_gnss_wwan_network_pref_enum_type)2)
  
  #define  nv_uim_hw_single_sim_ffa                      ((NV_UIM_HW_SIM_CONFIG)0)
  
  #define  nv_uim_hw_dual_sim_ffa                        ((NV_UIM_HW_SIM_CONFIG)1)

typedef PACKED struct PACKED_POST{ 
  /* HSUSB PHY configuration parameters */
  uint8                                            pre_emphasis_enable;
  /* Pre-emphasis value */
  uint8                                            pre_emphasis_value;
  /* Amplitude adjustment enable */
  uint8                                            amplitude_adjustment_enable;
  /* Amplitude adjustment value */
  uint8                                            amplitude_adjustment_value;
} nv_hs_usb_phy_config_type;

typedef PACKED struct PACKED_POST{ 
  
  boolean                                          ehrpd_only_flag;
  
  uint8                                            max_failure_count;
  
  uint8                                            max_failure_total_count;
  
  uint8                                            new_attempt_max_timer;
} nv_data_call_over_ehrpd_only_type;

/*=========================================================================*/
/* NVM Items Union Type.                                                   */
/*=========================================================================*/

typedef PACKED union PACKED_POST{
  nv_esn_type                                      esn;
  /* Checksum for Electronic Serial Number */
  nv_esn_chksum_type                               esn_chksum;
  byte                                             scm;
  /* The mobile Slot Cycle index is 8 bits, per CAI section 1.1.2.2 */
  int8                                             slot_cycle_index;
  /* Mobile CAI revision number (8 bits) */
  byte                                             mob_cai_rev;
  /* Mobile firmware revision number (16 bits) */
  word                                             mob_firm_rev;
  /* Mobile model (8 bits) */
  byte                                             mob_model;
  /* Physical configuration checksum */
  nv_config_chksum_type                            config_chksum;
  /* System preferred mode */
  nv_pref_mode_type                                pref_mode;
  nv_sid_lock_type                                 cdma_sid_lock;
  /* CDMA SID Acquisition list for the given NAM */
  nv_sid_acq_type                                  cdma_sid_acq;
  /* Analog SID lockout list */
  nv_sid_lock_type                                 analog_sid_lock;
  /* Analog SID acquisition */
  nv_sid_acq_type                                  analog_sid_acq;
  /* First analog channel for the given NAM */
  nv_firstchp_type                                 analog_firstchp;
  /* Analog home system ID for the given NAM */
  nv_sid_type                                      analog_home_sid;
  /* Analog reg setting (disabled, whereabouts known, whereabouts unknown) */
  nv_analog_reg_type                               analog_reg;
  /* Primary CDMA channel for the given NAM */
  nv_cdmach_type                                   pcdmach;
  /* Secondary CDMA channel for the given NAM */
  nv_cdmach_type                                   scdmach;
  nv_nam_chksum_type                               nam_chksum;
  /* Authentication A key (2 words) */
  nv_a_key_type                                    a_key;
  /* Authenitcation A Key chksum */
  nv_a_key_chksum_type                             a_key_chksum;
  /* Shared Secret Data A - used for authentication (2 dwords) */
  nv_ssd_type                                      ssd_a;
  nv_ssd_type                                      ssd_b;
  nv_count_type                                    count;
  /* MIN 1 (phone number) for the given NAM, in quotes, or encoded MIN1 */
  nv_min1_type                                     min1;
  /* MIN 2 (area code) for the given NAM, in quotes, or encoded MIN2 */
  nv_min2_type                                     min2;
  /* CDMA Mobile terminated home SID for the given NAM (true, false) */
  nv_mob_term_type                                 mob_term_home;
  /* CDMA Mobile terminated foreign SID for the given NAM (true, false) */
  nv_mob_term_type                                 mob_term_for_sid;
  /* CDMA Mobile terminated foreign NID for the given NAM (true, false) */
  nv_mob_term_type                                 mob_term_for_nid;
  /* Access overload class for the given nam */
  nv_accolc_type                                   accolc;
  /* Up to 4 CDMA SID/NID pairs for the given NAM */
  nv_sid_nid_type                                  sid_nid;
  /* MIN Checksum for the given NAM */
  nv_min_chksum_type                               min_chksum;
  /* Current NAM */
  byte                                             curr_nam;
  boolean                                          auto_nam;
  /* This item holds the name of each NAM. */
  nv_name_nam_type                                 name_nam;
  nv_call_time_type                                air_timer;
  /* Resettable cumulative roam time */
  nv_call_time_type                                roam_timer;
  nv_run_time_type                                 run_timer;
  /* Speed dial number */
  nv_dial_type                                     dial;
  /* Call stack number */
  nv_stdial_type                                   stack;
  /* Call stack last number index */
  nv_stack_idx_type                                stack_idx;
  /* OBSOLETE Page settings */
  nv_page_set_type                                 page_set;
  /* Page message and time (new = true, false) */
  nv_page_msg_type                                 page_msg;
  /* Hanset earpiece volume level (1 min - 255 max, 0 = off) */
  byte                                             ear_level;
  /* Hanset earpiece volume level (1 min - 255 max, 0 = off) */
  byte                                             speaker_level;
  /* External speaker ringer volume (1 min - 255 max, 0 = off) */
  byte                                             ringer_level;
  /* Key beep volume level(1 min - 255 max, 0 = off) */
  byte                                             beep_level;
  /* One minute call beeper select (on, off) */
  boolean                                          call_beep;
  /* Continuous keypad DTMF tones select (on, off) */
  boolean                                          cont_key_dtmf;
  /* Continuous string (memory) DTMF tones select (on, off) */
  boolean                                          cont_str_dtmf;
  /* Service area enter/exit alert select (on, off) */
  boolean                                          svc_area_alert;
  /* Call fade alert select (on, off) */
  boolean                                          call_fade_alert;
  /* Idle banner to display */
  nv_banner_type                                   banner;
  /* Specifies handset brightness with 0 to 255 (0 equals blank). */
  byte                                             lcd;
  nv_auto_answer_type                              auto_answer;
  /* Auto redial setting, time in 10 second units */
  nv_auto_redial_type                              auto_redial;
  /* Auto hyphen setting (on, off) */
  boolean                                          auto_hyphen;
  /* Backlight (0: never on, 1-10: secs before going off, 255: never off) */
  byte                                             back_light;
  /* Auto radio mute setting (on, off) */
  boolean                                          auto_mute;
  byte                                             lock;
  /* Lock code string (4 characters 0-9, representing the lock code) */
  nv_lock_code_type                                lock_code;
  /* Auto lock setting (on, off) */
  boolean                                          auto_lock;
  /* Call restrictions (word, 0 = no restrictions) */
  word                                             call_rstrc;
  /* 6 digit security code, represented by a string of digits (0-9) */
  nv_sec_code_type                                 sec_code;
  /* Horn alert setting (on, off) */
  boolean                                          horn_alert;
  /* Retrievs and adds an entry to the error log */
  nv_err_log_type                                  err_log;
  nv_minmax_type                                   vbatt;
  word                                             spare_2;
  byte                                             max_tx_adj;
  /* Initial mute setting (norm, mute, spkr) */
  byte                                             init_mute;
  /* Free form factory info - 100 bytes in a file */
  byte                                             fact_info[NV_FACTORY_INFO_SIZ];
  byte                                             dm_addr;
  boolean                                          onetouch_dial;
  byte                                             alerts_lvl;
  /* Alerts level shadow - 1 byte */
  byte                                             alerts_lvl_shadow;
  byte                                             beep_lvl_shadow;
  /* Ear level shadow - 1 byte */
  byte                                             ear_lvl_shadow;
  nv_call_cnt_type                                 air_cnt;
  /* Roam count - 1 byte for the given nam */
  nv_call_cnt_type                                 roam_cnt;
  /* Life count - 1 byte */
  dword                                            life_cnt;
  nv_imsi_mcc_type                                 imsi_mcc;
  /* True IMSI Mobile Network Code for given NAM */
  nv_imsi_11_12_type                               imsi_11_12;
  /* Directory Number: string of 10 digits */
  nv_dir_number_type                               dir_number;
  /* Voice privacy - 1 byte */
  byte                                             voice_priv;
  nv_fsc_type                                      fsc;
  nv_run_time_type                                 life_timer_g;
  /* Last call time for given NAM */
  nv_run_time_type                                 call_timer_g;
  /* Power Down count - 1 dword */
  dword                                            pwr_dwn_cnt;
  nv_fsc2_type                                     fsc2;
  /* FSC2 checksum, future use - 1 dword */
  nv_fsc2_chksum_type                              fsc2_chksum;
  /* Warranty Date Code - string of 5 chars - 3 date code, 2 swap count */
  nv_wdc_type                                      wdc;
  nv_imsi_addr_num_type                            imsi_addr_num;
  nv_mob_dir_data_type                             mob_dir_number;
  
  nv_roaming_list_union_type                       roaming_list;
  nv_sec_code_type                                 otksl;
  /* Used with PREF_MODE. */
  boolean                                          timed_pref_mode;
  /* Ringer type setting. type is a byte */
  byte                                             ringer_type;
  byte                                             back_light_hfk;
  /* Type of keypress sound emitted. type: 0-Emit tones, 1-Emit clicks */
  nv_key_sound_enum_type                           key_sound;
  nv_language_enum_type                            language_selection;
  /* Type of user interface. format: 0-Disp full menus, 1-Disp short menus */
  nv_menu_format_enum_type                         menu_format;
  /* External speaker ringer volume */
  byte                                             ringer_spkr_lvl;
  /* External speaker key beep volume */
  byte                                             beep_spkr_lvl;
  byte                                             vibrator;
  boolean                                          data_qnc_enabled;
  /* Data services Service Option (byte) */
  byte                                             data_so_set;
  nv_sid_nid_lock_type                             sid_nid_lock;
  /* Roaming list enabled/disabled */
  nv_enabled_type                                  prl_enabled;
  /* IS-683-A format roaming list */
  nv_roaming_list_union_type                       roaming_list_683;
  /* System preference (A only, B only, Home only, Standard) */
  nv_sys_pref_type                                 system_pref;
  /* Home SID+NID pair item */
  nv_home_sid_nid_type                             home_sid_nid;
  nv_min1_type                                     imsi_t_s1;
  /* True IMSI MIN2, in quotes, or encoded value, for given NAM */
  nv_min2_type                                     imsi_t_s2;
  /* True IMSI MCC, 3 digits in quotes, or encoded MCC, for given NAM */
  nv_imsi_mcc_type                                 imsi_t_mcc;
  /* True IMSI Mobile Network Code for given NAM */
  nv_imsi_11_12_type                               imsi_t_11_12;
  /* True IMSI Int'l Mobile Station ID length for given NAM */
  nv_imsi_addr_num_type                            imsi_t_addr_num;
  boolean                                          sms_utc;
  /* Distinctive ringer sound for incoming roaming calls */
  byte                                             roam_ringer;
  nv_pref_voice_so_type                            pref_voice_so;
  boolean                                          spc_change_enabled;
  /* Medium Data Rate mode */
  byte                                             data_mdr_mode;
  /* Packet data call origination string. Maximum 16 digits. */
  nv_data_pkt_orig_str_type                        data_pkt_orig_str;
  /* Unwired Planet encryption key */
  nv_up_key_type                                   up_key;
  boolean                                          auto_volume_enabled;
  nv_pap_user_id_type                              pap_user_id;
  /* Actual Password for Password Authentication Protocol */
  nv_pap_password_type                             pap_password;
  word                                             sms_bc_service_table_size;
  /* Broadcast SMS service table to contain service/language details */
  nv_sms_bc_service_table_type                     sms_bc_service_table;
  nv_ruim_chv_type                                 ruim_chv_1;
  /* Card Holder Verification 2 for R-UIM */
  nv_ruim_chv_type                                 ruim_chv_2;
  dword                                            gps1_pde_address;
  nv_gps1_transport_type                           gps1_pde_transport;
  byte                                             tty;
  byte                                             mm_sdac_lvl;
  /* Stereo DAC key beep volume level */
  byte                                             beep_sdac_lvl;
  /* Stereo DAC volume level */
  byte                                             sdac_lvl;
  /* Handset Multimedia volume level */
  byte                                             mm_lvl;
  /* Headset Multimedia volume level */
  byte                                             mm_lvl_shadow;
  /* HFK Multimedia volume level */
  byte                                             mm_speaker_lvl;
  dword                                            primary_dns;
  /* The Secondary IP Address of the DNS Server */
  dword                                            secondary_dns;
  dword                                            gps1_pde_port;
  /* Multimedia ringer filename */
  byte                                             mm_ringer_file[40];
  boolean                                          data_scrm_enabled;
  nv_bd_addr_type                                  bd_addr;
  boolean                                          data_trtl_enabled;
  dword                                            gps1_lock;
  /* Determines boot up mode of a factory testmode phone */
  byte                                             ftm_mode;
  /* Default Data Services port baud rate */
  nv_sio_baudrate_type                             ds_default_baudrate;
  /* Default diag port baud rate */
  nv_sio_baudrate_type                             diag_default_baudrate;
  byte                                             ds_qcmip;
  /* The number of Mobile IP Registration Retries attempted */
  byte                                             ds_mip_retries;
  /* The initial interval between mobile IP registration attempts */
  byte                                             ds_mip_retry_int;
  /* The time before Mobile IP reg. expiration to attempt re-registration. */
  byte                                             ds_mip_pre_re_rrq_time;
  byte                                             ds_mip_active_prof;
  /* Active Mobile IP profile settings */
  nv_ds_mip_gen_user_prof_type                     ds_mip_gen_user_prof;
  /* Active Mobile IP profile settings */
  nv_ds_mip_ss_user_prof_type                      ds_mip_ss_user_prof;
  nv_hdramp_address_data_type                      hdramp_address_data;
  /* SCP - status of the session */
  nv_hdrscp_session_status_enum_type               hdrscp_session_status;
  nv_ds_mip_mn_ha_time_delta_type                  ds_mip_mn_ha_time_delta;
  /* Qualcomm PREV 6 MIP handoff optimization enable */
  boolean                                          ds_mip_qc_drs_opt;
  boolean                                          ds_mip_2002bis_mn_ha_auth;
  nv_ue_imei_type                                  ue_imei;
  byte                                             gsm_a5_algorithms_supported;
  nv_sms_vm_number_type                            sms_vm_number;
  byte                                             hybrid_pref;
  /* Service Provider ECC is enabled */
  boolean                                          sp_ecc_enabled;
  /* ECC phone numbers */
  byte                                             ecc_list[NV_MAX_NUM_OF_ECC_NUMBER][NV_ECC_NUMBER_SIZE];
  byte                                             rf_cal_ver[NV_SIZE_OF_VERSION];
  dword                                            rf_cal_date;
  byte                                             domain_name[NV_DOMAIN_NAME_SIZE];
  nv_hdr_an_auth_nai_type                          hdr_an_auth_nai;
  /* Stores the password for 1xEV(HDR) Access Network CHAP Authentication */
  nv_hdr_an_auth_password_type                     hdr_an_auth_password;
  boolean                                          ds_mip_rrq_if_tfrk;
  byte                                             ds_mip_enable_prof[NV_DS_MIP_MAX_NUM_PROF];
  uint8                                            hdr_rx_diversity_ctrl;
  nv_sms_routing_type                              sms_cfg_routing;
  nv_srv_domain_pref_type                          service_domain_pref;
  nv_ds_mip_dmu_pkoid_type                         ds_mip_dmu_pkoid;
  /* RTRE configuration */
  nv_rtre_configuration_type                       rtre_config;
  int2                                             cdma_dynamic_range;
  /* Min Rx RSSI in 1/10 dB increments. */
  int2                                             cdma_min_rx_rssi;
  uint32                                           last_tx_data_count;
  /* Remember the amount of data call bytes received */
  uint32                                           last_rx_data_count;
  /* Remember the accumulated data call bytes transmitted */
  uint32                                           total_tx_data_count;
  /* Remember the accumulated data call bytes received */
  uint32                                           total_rx_data_count;
  /* Mobile Node Authenticator */
  nv_ds_mip_dmu_mn_auth_type                       ds_mip_dmu_mn_auth;
  uint8                                            jcdma_m511_mode;
  /* M512 mode setting */
  uint8                                            jcdma_m512_mode;
  /* M513 mode setting */
  uint8                                            jcdma_m513_mode;
  nv_err_fatal_options_type                        err_fatal_options;
  /* Simple IP PPP password */
  nv_ppp_password_type                             ppp_password;
  nv_ppp_user_id_type                              ppp_user_id;
  nv_uim_pref_protocol_type                        uim_pref_protocol;
  /* WCDMA Circuit Switched Data Synchronous Test App */
  boolean                                          wcdmacs_sync_test_app_enabled;
  nv_hdr_an_ppp_password_type                      hdr_an_ppp_password;
  nv_rtsp_proxy_server_addr_type                   rtsp_proxy_server_addr;
  uint16                                           hysterisis_activation_timer;
  /* Defines the PZID hysterisis timer in seconds */
  uint16                                           hysterisis_timer;
  /* Packet Call Dial String Lookup Table */
  nv_pkt_dial_string_type                          pkt_dial_strings[NV_PKT_DIAL_STRING_LIST_SIZE];
  boolean                                          data_incoming_csd_call_is_internal;
  byte                                             sspr_p_rev;
  /* IP address and port of RTSP protocol proxy server */
  nv_rtsp_proxy_server_addr_type                   rtsp_proxy_server_addr_alternate;
  boolean                                          gprs_anite_gcf;
  word                                             cdma_rx_diversity_ctrl;
  /* Enable/disable tolerance to long PDP context setup time for TE calls */
  boolean                                          long_pdpact_tolerance_for_te;
  nv_hdr_an_auth_passwd_long_type                  hdr_an_auth_passwd_long;
  /* Flag to do PPP resync on HDR to 1X handdown */
  boolean                                          ds_mip_qc_handdown_to_1x_opt;
  /* User ID used in HDR for Access Network stream CHAP authentication */
  nv_hdr_an_auth_user_id_long_type                 hdr_an_auth_user_id_long;
  nv_ppp_configure_data_type                       ppp_config_data;
  boolean                                          gsm_amr_call_config;
  nv_sec_device_key_type                           sec_device_key;
  boolean                                          tcp_graceful_dormant_close;
  boolean                                          eplmn_enabled;
  /* Dtmf values can be set to 3 values */
  uint8                                            dtmf;
  boolean                                          sn_ppp_status;
  byte                                             ds_ucsd_rlp_version_gsm;
  /* Default WCDMA RLP version */
  byte                                             ds_ucsd_rlp_version_wcdma;
  /* Default ATCOP CRLP version */
  byte                                             ds_atcop_rlp_version_default;
  /* UMTS CS Data using SREJ recovery */
  boolean                                          ds_ucsd_recovery_mode_srej;
  /* Idle time before sending keepalive probes */
  uint32                                           tcp_keepalive_idle_time;
  nv_data_pkt_orig_str_type                        data_force_cdma_pkt_str;
  nv_ps_ipv6_iid_type                              ps_ipv6_iid;
  uint8                                            diag_debug_control;
  /* Gives the default video capability settings for QVideoPhone */
  word                                             qvp_app_default_capability_type;
  uint8                                            diag_debug_detail;
  /* IPV6 Enable/Disable */
  boolean                                          ipv6_enabled;
  /* IPV6 SM Configuration Struct */
  nv_ip6_sm_config_type                            ipv6_sm_config;
  nv_ipv6_address_type                             ipv6_primary_dns;
  /* IPv6 DNS server addresses */
  nv_ipv6_address_type                             ipv6_secondary_dns;
  /* Require Encrypted password */
  boolean                                          auth_require_password_encryption;
  boolean                                          pdsn_as_proxy_ipv6_dns_server;
  byte                                             ipv6_failover_config;
  qword                                            meid;
  uint8                                            diag_debug_max_files;
  dword                                            brew_carrier_id;
  /* Brew platform id */
  dword                                            brew_platform_id;
  /* Brew bkey */
  byte                                             brew_bkey[NV_BREW_BKEY_SIZ];
  /* Brew server */
  byte                                             brew_server[NV_BREW_SERVER_SIZ];
  /* Brew download flags */
  word                                             brew_download_flags;
  /* Brew auth policy */
  dword                                            brew_auth_policy;
  /* Brew privacy policy */
  dword                                            brew_privacy_policy;
  /* Brew subscriber Id */
  byte                                             brew_subscriber_id[NV_BREW_SID_SIZ];
  uint32                                           ds_ucsd_rlp_adm_idle;
  /* CCP reject behavior */
  uint8                                            ppp_ccp_reject;
  nv_usbdc_supported_device_type                   usb_current_device;
  nv_epzid_enum_type                               active_epzid_type;
  uint8                                            sw_version_info[NV_MAX_SW_VERSION_INFO_SIZ];
  boolean                                          set_auto_time;
  uint32                                           ds_incoming_data_rlp_timeout;
  /* Time period after which RLP idle timeout is set to its original value  */
  uint32                                           ds_default_inactivity_restore_timeout;
  /* When set, it will disable USB charging */
  nv_chg_usb_nvswitch_type                         chg_usb_nvdisable_val;
  uint8                                            device_serial_no[16];
  /* NAI for laptop ( tethered-device) calls */
  nv_ds_mip_rm_nai_type                            ds_mip_rm_nai;
  boolean                                          bt_active;
  /* Bluetooth page scanning or page and inquiry scanning */
  boolean                                          bt_visible;
  /* Bluetooth SIM Access Profile enabled or disabled */
  boolean                                          bt_sap_enable;
  nv_timezone_enum_type                            timezone;
  nv_ds_sip_rm_nai_type                            ds_sip_rm_nai;
  nv_wb_mailto_email_enum_type                     browser_mailto_email;
  uint8                                            irda_pnp_manufacturer[NV_IRDA_PNP_MANUFACTURER_SIZ];
  /* IrDA Plug-N-Play parameters. */
  uint8                                            irda_pnp_name[NV_IRDA_PNP_NAME_SIZ];
  uint8                                            diag_debug_call_trace;
  uint8                                            diag_spc_unlock_ttl;
  uint8                                            ipv6_umts_failover_config;
  nv_ringer_volume_enum_type                       set_ringer_volume;
  boolean                                          manual_plmn_sel;
  /* Displays the Manual PLMN Selection Menu regardless of the info in card */
  boolean                                          manual_plmn_selection;
  uint8                                            wlan_enable_ps_mode;
  uint16                                           hdrmrlp_num_bytes_to_log;
  uint8                                            ds_ucsd_nt_connect_state;
  uint8                                            ccbs_sel;
  nv_trm_config_type                               trm_config;
  boolean                                          ens_enabled;
  /* Timeout value for the DIAG suspend on incorrect SPC */
  uint16                                           diag_spc_timeout;
  uint8                                            back_light_intensity;
  /* Time before LCD shuts off (0 - always on; 1-65535 msec timeout) */
  uint32                                           display_duration;
  uint16                                           timezone_city;
  boolean                                          auto_time_enable;
  /* MO SMS retry period in seconds */
  uint8                                            sms_mo_retry_period;
  /* SMS MO retry interval in seconds */
  uint8                                            sms_mo_retry_interval;
  /* Autoconnect settings for rmnet devices */
  nv_rmnet_autoconnect_type                        rmnet_autoconnect;
  uint16                                           voip_qos_evdo_sip_profile_id;
  /* QoS EvDO RTP profile ID */
  uint16                                           voip_qos_evdo_rtp_profile_id;
  /* QoS DSCP */
  uint16                                           voip_qos_evdo_dscp;
  /* VOIP DTX enabled flag */
  boolean                                          voip_dtx_enabled;
  uint8                                            wcdma_rrc_version;
  nv_nitz_plmn_type                                nitz_nw_info;
  boolean                                          dqos_supported;
  uint16                                           voip_wlan_prfrd_codec;
  /* preferred codec value for evdo */
  uint16                                           voip_evdo_prfrd_codec;
  nv_wlan_qos_mode_enum_type                       wlan_qos_mode;
  /* Is game mode persistent (0=no) */
  boolean                                          game_mode_persist;
  /* Game mode enabled (0=no) */
  boolean                                          game_mode;
  boolean                                          voip_qos_enabled;
  boolean                                          voip_write_media_file_enabled;
  /* Uplink data transfer - pkt input from media file flag */
  boolean                                          voip_read_media_file_enabled;
  nv_wlan_oem_index_enum_type                      wlan_oem_index;
  uint8                                            hdrscp_force_rel0_config;
  nv_hdrscmdb_secure_config_type                   hdrscmdb_secure_config;
  uint32                                           sms_max_payload_length;
  /* boolean stating if SMS should be sent on access channel */
  uint8                                            sms_mo_on_access_channel;
  /* boolean stating if SMS should be sent on traffic channel */
  boolean                                          sms_mo_on_traffic_channel;
  /* preferred uri type */
  uint16                                           voip_confrd_uri;
  uint8                                            hdr_qos_flow_priority;
  uint8                                            voip_registration_mode;
  uint32                                           dcvs_acpu_enable;
  /* Simple gpsOne PD API password */
  nv_gpsone_password_type                          gpsone_password;
  /* Callerid presemntation/restriction mode */
  uint16                                           voip_callerid_mode;
  /* Enables the multidomain capability flag for 802.11d */
  uint8                                            wlan_multidomain_capability_pref;
  /* Enable/ Disable NBNS */
  boolean                                          umts_nbns_enable;
  uint16                                           voip_refer_subscription_expires_duration;
  /* VOIP NOTIFY (REFER) response duration (sec) */
  uint16                                           voip_notify_refer_response_duration;
  nv_dcvsapps_type                                 dcvsapps_nv;
  /* Rate of security updates sent to client */
  uint8                                            gps1_sec_update_rate;
  uint8                                            ds_mip_dereg_retries;
  boolean                                          ipv6_privacy_extensions_enabled;
  /* IPv6 Privacy Extensions Configuration */
  nv_ipv6_priv_addr_config                         ipv6_private_address_config;
  uint8                                            bt_disabled;
  /* The Current High Speed USB Composition */
  nv_hs_usb_supported_compositions_type            hs_usb_current_composition;
  /* Specifies whether BT coexistence should be enabled or not */
  boolean                                          wlan_enable_bt_coex;
  /* This NV item controls if EMPA is supported */
  uint8                                            hdr_empa_supported;
  boolean                                          voip_precondition_enable;
  uint8                                            db_lp_sec;
  /* Offset local time from System Time */
  uint8                                            db_ltm_off;
  /* Daylight savings time indicator */
  boolean                                          db_daylt;
  uint32                                           ds707_go_null_timer_1x;
  /* Go null timer value for DO */
  uint32                                           ds707_go_null_timer_do;
  /* Mac address for the phone on WLAN interface */
  uint8                                            wlan_mac_address[6];
  boolean                                          display_update_power_test_mode;
  boolean                                          qvp_app_psvt_enable_flag;
  nv_nd_config_items                               icmp6_nd_config;
  /* Timer value used for remote wakeup for conformance testing purposes */
  uint32                                           hs_usb_remote_wakeup_delay;
  nv_jcdma_ruimid                                  jcdma_ruim_id;
  /* jcdma uim lock */
  nv_jcdma_uim_lock_data                           jcdma_uim_lock;
  /* Item to enable switching of Diag master from ARM11 to ARM9. */
  uint8                                            diag_ftm_mode_switch;
  /* dhcp4_options_mask */
  uint32                                           dhcp4_options_mask;
  /* dhcp6_options_mask */
  uint32                                           dhcp6_options_mask;
  nv_ds_at_v250_registers_type                     ds_at_v250_registers;
  /* DS AT S Registers */
  nv_ds_at_s_registers_type                        ds_at_s_registers;
  /* NV item for AMSS RESTART */
  nv_process_restart_switch_type                   process_restart_switch;
  /* Force AT Configuration to Rel 0/A/B */
  nv_hdrscp_force_at_config_type                   hdrscp_force_at_config;
  boolean                                          hs_usb_diag_on_legacy_usb_port;
  uint16                                           diag_diagbuf_tx_sleep_time_nv;
  boolean                                          bt_lisbon_disabled;
  /* CSCA settings for CSAS */
  nv_ds_at_csas_csca_register                      ds_at_csas_csca_settings;
  /* CSMP settings for CSAS */
  nv_ds_at_csas_csmp_settings                      ds_at_csas_csmp_settings;
  /* CSCB settings for CSAS */
  nv_ds_at_csas_cscb_settings                      ds_at_csas_cscb_settings;
  /* SVN indicates Software Version Number */
  uint8                                            ue_imeisv_svn;
  nv_ds_sip_profile_type                           ds_sip_profile;
  /* To indicate which profile is  active  */
  uint8                                            ds_sip_active_profile_index;
  /* To  store how many profiles are valid */
  uint8                                            ds_sip_num_valid_profiles;
  /* ds_sip_profile_nai_info */
  nv_ds_sip_profile_nai_info_type                  ds_sip_nai_info;
  /* ds_sip_chap_ss_info */
  nv_ds_sip_ppp_ss_info_type                       ds_sip_ppp_ss_info;
  /* Dynamic threshold value for Diag */
  uint64                                           diag_diagbuf_tx_sleep_threshold_ext;
  boolean                                          wwan_access_over_wifi_preferred;
  /* Carrier Preference if WiFi access is allowed for Default Interface. */
  nv_wifi_local_breakout_allowed_enum_type         wifi_local_breakout_allowed;
  /* Operator Id(Used for constructing the FQDN of GW in 3GPP) */
  nv_iwlan_operator_id_type                        iwlan_operator_id;
  /* Carrier provided realm string that is used to create NAI. */
  nv_iwlan_realm_type                              iwlan_realm;
  /* The Authentication Algorithm used for iwlan tunnel establishment. */
  nv_iwlan_auth_mode_enum_type                     iwlan_auth_mode;
  /* IKEv2 soft rekey timer value. */
  uint32                                           iwlan_soft_ike_rekey_time;
  /* IKEv2 hard rekey timer value */
  uint32                                           iwlan_hard_ike_rekey_time;
  /* Child SA soft rekey timer value. */
  uint32                                           iwlan_child_sa_soft_lifetime_sec;
  /* Child SA hard rekey timer value */
  uint32                                           iwlan_child_sa_hard_lifetime_sec;
  /* Child SA soft rekey lifetime in bytes. */
  uint32                                           iwlan_child_sa_soft_lifetime_bytes;
  /* Child SA hard rekey lifetime in bytes */
  uint32                                           iwlan_child_sa_hard_lifetime_bytes;
  /* NAT Keepalive messages interval. */
  uint32                                           iwlan_nat_keepalive_interval;
  /* IKEv2 messages retransmission interval */
  uint32                                           iwlan_ike_retransmission_interval;
  /* Maximum number of retransmissions during IKE negotiaion. */
  uint32                                           iwlan_ike_max_retransmissions;
  /* IWLAN IP parameters configured using IKEv2. */
  uint32                                           iwlan_ikev2_ip_config_mask;
  /* IWLAN IP parameters configured using DHCP over the tunnel */
  uint32                                           iwlan_dhcp_ip_config_mask;
  /* Bit mask of encryption algorithms used in Child SA proposal */
  uint32                                           iwlan_child_sa_enc_algo_proposal_mask;
  /* Bit mask of encryption algorithm used in IKE SA proposal */
  uint32                                           iwlan_ike_sa_enc_algo_proposal_mask;
  /* Bit mask of PRF algorithms to be used in IKE SA proposal. */
  uint32                                           iwlan_ike_sa_prf_algo_proposal_mask;
  /* Bit mask of authentication algorithms to be used in Child SA proposal. */
  uint32                                           iwlan_child_sa_auth_algo_proposal_mask;
  /* Bit mask of authentication algorithms to be used in IKE SA proposal. */
  uint32                                           iwlan_ike_sa_auth_algo_proposal_mask;
  /* Diffie Hellman mode to be used in IKE SA. */
  nv_iwlan_ike_dh_mode_enum_type                   iwlan_ike_dh_mode;
  /* PDIF's FQDN or IP address in dotted decimal notation. */
  uint32                                           iwlan_pdif_address;
  /* Boolean indicating if IWLAN client supports multiple auth or not. */
  boolean                                          iwlan_multi_auth_supported;
  /* The FQDN of the PDIF */
  nv_iwlan_pdif_fqdn_type                          iwlan_pdif_fqdn;
  boolean                                          iwlan_dpd_enabled;
  /* DPD timer values in seconds */
  uint32                                           iwlan_dpd_time_secs;
  /* Provides the BTS Master Reference Clock */
  nv_ps_bt_soc_refclock_enum_type                  bt_soc_refclock_type;
  /* Provides Information of BTS Clk sharing  */
  nv_ps_bt_soc_clock_sharing_enum_type             bt_soc_clk_sharing_type;
  /* Provides Information on BTS Inband Sleep Implementation */
  nv_ps_bt_soc_inband_sleep_enum_type              bt_soc_inband_sleep;
  /* Provides Information whether BT SOC logging should be enabled */
  boolean                                          bt_soc_logging_enabled;
  /* Provides the Power Mgmt Mode BT chip is operating SMPS,Linear or LDO */
  nv_ps_bt_soc_pm_mode_enum_type                   bt_soc_pm_mode;
  boolean                                          mgrf_supported;
  boolean                                          hs_usb_use_pmic_otg_comparators;
  uint8                                            hs_usb_number_of_sdcc_luns;
  nv_eap_shared_secret_type                        ppp_eap_shared_secret;
  nv_ppp_vsncp_config_data_type                    ppp_vsncp_config_data;
  /* eHRPD Functionality to be enabled or not across the system */
  boolean                                          ehrpd_enabled;
  /* WLAN Atheros clk freq, power save mode parameters */
  nv_wlan_atheros_specific_cfg                     wlan_atheros_specific_cfg;
  /* Mode of operation of the UE - GAN preferred or cellular only */
  NV_GAN_MODE_PREFERENCE                           gan_mode_preference;
  /* Enforce that the peer uses certificate based authentication. */
  boolean                                          iwlan_enforce_peer_cert_auth;
  boolean                                          hs_usb_host_mode_enabled;
  /* WLAN CPU Flow Control Configuration, Off by default (0 = Off, 1 = 0n) */
  uint16                                           wlan_cpu_flow_control_cfg;
  boolean                                          hs_usb_reconnect_on_reset_during_suspend;
  boolean                                          hs_usb_disable_sleep_voting;
  nv_ehrpd_milenage_op_type                        ehrpd_milenage_op;
  /* IMSI value */
  nv_ehrpd_imsi_type                               ehrpd_imsi;
  uint8                                            wlan_uuid[16];
  /* FIH;Tiger;2009/10/1 { */
  /* port ADQ.FC185 */
  #ifdef CONFIG_FIH_FXX
  uint8						                       bsp_adb_user_right;  
  uint8						                       moto_track_number[128];
  #endif
  /* } FIH;Tiger;2009/10/1 */
  boolean                                          qdj_dequeue_log_enabled;
  nv_bt_qsoc_nvm_mode                              bt_qsoc_nvm_mode;
  /* BT QSOC Class Type */
  nv_bt_qsoc_class_type                            bt_qsoc_class_type;
  uint32                                           m_sensor_calibration[9]; // jones porting
  nv_hs_usb_perf_set_level_enum_type               hs_usb_performance_setting;
  /* WLAN/PAL Link preference settings for BT AMP feature */
  nv_wlan_pal_link_pref_enum_type                  wlan_pal_link_pref;
  /* Defines if the target will enter LPM or not */
  boolean                                          hs_usb_disable_lpm;
  uint32                                           oem_item_1[31];
  /* NV item to store OEM specific data. */
  uint32                                           oem_item_2[31];
  /* NV item to store OEM specific data. */
  uint32                                           oem_item_3[31];
  /* NV item to store OEM specific data. */
  uint32                                           oem_item_4[31];
  /* NV item to store OEM specific data. */
  uint32                                           oem_item_5[31];
  /* NV item to store OEM specific data. */
  uint32                                           oem_item_6[31];
  /* NV item to store OEM specific data. */
  uint32                                           oem_item_7[31];
  /* NV item to store OEM specific data. */
  uint32                                           oem_item_8[31];
  boolean                                          ehrpd_auth_in_usim;
  nv_hs_usb_phy_config_type                        hs_usb_phy_config;
  nv_data_call_over_ehrpd_only_type                data_call_over_ehrpd_only;
} nv_item_type;

#endif  /* NV_ITEMS_H */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

#define  NV_RUIM_ACCESS_SIG   0x0010      /* R-UIM Access Synchronization  */

/*===========================================================================
                                                                         
                              MACROS                                     
                                                                         
===========================================================================*/

#define  NV_RPT_TIMER_SIG     0x0001      /* Watchdog report signal */

/*  Command codes when command is issued to the NV task.                   */
  typedef enum {
    NV_READ_F,          /* Read item */
    NV_WRITE_F,         /* Write item */
    NV_PEEK_F,          /* Peek at a location */
    NV_POKE_F,          /* Poke into a location */
    NV_FREE_F,          /* Free an nv item's memory allocation */
    NV_CHKPNT_DIS_F,    /* Disable cache checkpointing for glitch recovery */
    NV_CHKPNT_ENA_F,    /* Enable cache checkpointing for glitch recovery */
    NV_OTASP_COMMIT_F,  /* Commit (write) OTASP parameters to nv */
    NV_REPLACE_F,       /* Replace (overwrite) a dynamic pool item */
    NV_INCREMENT_F,     /* Increment the rental timer item */
    NV_RTRE_OP_CONFIG_F,/* Set the operational configuration of RTRE */
    NV_FUNC_ENUM_PAD = 0x7FFF,     /* Pad to 16 bits on ARM */
    NV_FUNC_ENUM_MAX = 0x7fffffff /* Pad to 32 bits */

  } nv_func_enum_type;

/*  Returned status codes for requested operation.                         */
  typedef enum {
    NV_DONE_S,          /* Request completed okay */
    NV_BUSY_S,          /* Request is queued */
    NV_BADCMD_S,        /* Unrecognizable command field */
    NV_FULL_S,          /* The NVM is full */
    NV_FAIL_S,          /* Command failed, reason other than NVM was full */
    NV_NOTACTIVE_S,     /* Variable was not active */
    NV_BADPARM_S,       /* Bad parameter in command block */
    NV_READONLY_S,      /* Parameter is write-protected and thus read only */
    NV_BADTG_S,         /* Item not valid for Target */
    NV_NOMEM_S,         /* free memory exhausted */
    NV_NOTALLOC_S,      /* address is not a valid allocation */
    NV_STAT_ENUM_PAD = 0x7FFF,     /* Pad to 16 bits on ARM */
    NV_STAT_ENUM_MAX = 0x7FFFFFFF     /* Pad to 16 bits on ARM */
  } nv_stat_enum_type;

#define     NV_VALID_ESN_CHKSUM     0xFFFFFFFFL

/*===========================================================================

FUNCTION NV_READ_ERR_LOG

DESCRIPTION
  This function reads an error log from NVM.

DEPENDENCIES
  The function MUST NOT USE ANY TASK SERVICES, so that it can be
  called when tasks are not initialized.  The function MUST NOT
  USE ERROR SERVICES.  It returns status to the caller if there
  is a failure.

RETURN VALUE
  NV_DONE_S         if it worked
  NV_NOT_ACTIVE_S   if item was not active
  NV_FAIL_S         if item could not be read

SIDE EFFECTS
  None.

===========================================================================*/

nv_stat_enum_type 
nv_read_err_log (
  nv_err_log_type  *nv_err_log_ptr    /* Pointer where to return read data */
);

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_read_err_log */
/*~ PARAM INOUT nv_err_log_ptr POINTER */

/*===========================================================================

FUNCTION NV_WRITE_ERR_LOG

DESCRIPTION
  This function writes the boot error log to NVM.

DEPENDENCIES
  The function MUST NOT USE ANY TASK SERVICES, so that it can be
  called when tasks are not initialized.  The function MUST NOT
  USE ERROR SERVICES.  It returns status to the caller if there
  is a failure.

RETURN VALUE
  NV_DONE_S - if it worked
  NV_FAIL_S - if item could not be written

SIDE EFFECTS
  None.

===========================================================================*/

nv_stat_enum_type
nv_write_err_log (
  nv_err_log_type  *nv_err_log_ptr    /* Pointer where to get write data */
);

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_write_err_log */
/*~ PARAM INOUT nv_err_log_ptr POINTER */

/*===========================================================================

FUNCTION NV_MAX_SIZE_OF_ROAMING_LIST

DESCRIPTION
  This function returns the maximum number of bytes available for
  storage of a roaming list (per NAM).  The value returned depends 
  on the total amount of NVRAM installed in the phone and the total 
  number of NAMs defined.  

DEPENDENCIES
  The function cannot be called until NV is initialized.  A
  premature call will raise err_fatal.

RETURN VALUE
  The maximum number of bytes available for storage of a roaming list
  (per NAM).

SIDE EFFECTS
  None.

===========================================================================*/

word  nv_max_size_of_roaming_list (void);

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_max_size_of_roaming_list */

/*===========================================================================

FUNCTION NV_PRL_IS_VALID

DESCRIPTION
  This function returns the "valid" indicator from the specified NAM's
  roaming list.  

DEPENDENCIES
  None.

RETURN VALUE
  TRUE         if the roaming list "valid" field is TRUE 
  FALSE        if the roaming list "valid" field is FALSE or if the
                 specified NAM is invalid or if the roaming list
                 is currently NOT_ACTIVE

SIDE EFFECTS
  None.

===========================================================================*/

boolean  
nv_prl_is_valid (
  byte  nam
);

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_prl_is_valid */

/*===========================================================================

FUNCTION NV_BUILT

DESCRIPTION
  This function checks the major version number of the the NV task
  as stored at edit time, against the major version number of the
  NV EEPROM as read from NVM.  If the numbers are different then the
  function returns FALSE, which indicates that the NV is not built
  and it may not be accessed from any external task.  If the numbers
  are the same then the function returns TRUE, which indicates that
  NV is built and it may be accessed.  This function lets other units
  issue direct NV read and write commands if the status returned is
  TRUE, thus allowing NV read and write before the NV task has been
  started.

DEPENDENCIES
  This is a special use function, normally called by error services
  to allow early access to NV, and before the NV task has been started.
  If NV_BUILT returns TRUE the NV may be accessed BUT ONLY USING DIRECT
  READ AND WRITES OF THE ERROR LOG (NV_READ_ERR_LOG and NV_WRITE_ERR_LOG).
  The NV task itself can not be counted upon to be started yet and normal
  NV requests must not be used.  As with all direct read and write
  operation, the data item (here it is the major version number) must
  be contained on a signle physical NV page.

RETURN VALUE
  TRUE      - The NV has been built and direct read/write is allowed
  FALSE     - The NV has not been built and access is not allowed

SIDE EFFECTS
  None.

===========================================================================*/

extern boolean nv_built (void);

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_built */

/*===========================================================================

FUNCTION NV_PRL_VERSION

DESCRIPTION
  This function returns the "prl_version" indicator from the specified NAM's
  roaming list.  

DEPENDENCIES
  None.

RETURN VALUE
  prl_version             if the roaming list for the specified NAM is
                            currently ACTIVE 
  NV_PRL_VERSION_INVALID  if the specified NAM is invalid or if the 
                            roaming list for the specified NAM is 
                            currently NOT_ACTIVE

SIDE EFFECTS
  None.

===========================================================================*/


word  
nv_prl_version (
  byte  nam
);

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_prl_version */

/*===========================================================================

FUNCTION NV_DETERMINE_ESN_VALIDITY

DESCRIPTION
  This function is determines if the current ESN has been programmed with the
  status of this check returned.

DEPENDENCIES
  None.

RETURN VALUE
  TRUE if the current ESN is non-zero with proper checksums, else FALSE

SIDE EFFECTS

===========================================================================*/

boolean nv_determine_esn_validity( void);

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_determine_esn_validity */

/*===========================================================================

FUNCTION NV_CMD_REMOTE

DESCRIPTION
  This is the outside world's interface to the non volatile memory task.

DEPENDENCIES
  The NV task must have been started up already.  All of the items in
  the nv_cmd_type must be already set.

RETURN VALUE

  NV_DONE_S,      -  Request completed okay 
  NV_BUSY_S,      -  Request is queued 
  NV_BADCMD_S,    -  Unrecognizable command field 
  NV_FULL_S,      -  The NVM is full 
  NV_FAIL_S,      -  Command failed, reason other than NVM was full 
  NV_NOTACTIVE_S, -  Variable was not active 
  NV_BADPARM_S,   -  Bad parameter in command block 
  NV_READONLY_S,  -  Parameter is write-protected and thus read only 
  NV_BADTG_S,     -  Item not valid for Target 
  NV_NOMEM_S,     -  free memory exhausted 
  NV_NOTALLOC_S   -  address is not a valid allocation 

SIDE EFFECTS
  The nv_cmd_type is placed on the NV command queue.  It must not be
  modified until the command has been processed!

===========================================================================*/

nv_stat_enum_type nv_cmd_remote 
( 
  nv_func_enum_type cmd, 
  nv_items_enum_type item, 
  nv_item_type *data_ptr 
); 
/*~ FUNCTION nv_cmd_remote */ 
/*~ PARAM INOUT data_ptr POINTER DISC item */ 

/*===========================================================================

FUNCTION NV_CMD_EXT_REMOTE

DESCRIPTION
  This is the outside world's interface to the non volatile memory task.

DEPENDENCIES
  The NV task must have been started up already.  All of the items in
  the nv_cmd_ext_type must be already set.

RETURN VALUE

  NV_DONE_S,      -  Request completed okay 
  NV_BUSY_S,      -  Request is queued 
  NV_BADCMD_S,    -  Unrecognizable command field 
  NV_FULL_S,      -  The NVM is full 
  NV_FAIL_S,      -  Command failed, reason other than NVM was full 
  NV_NOTACTIVE_S, -  Variable was not active 
  NV_BADPARM_S,   -  Bad parameter in command block 
  NV_READONLY_S,  -  Parameter is write-protected and thus read only 
  NV_BADTG_S,     -  Item not valid for Target 
  NV_NOMEM_S,     -  free memory exhausted 
  NV_NOTALLOC_S   -  address is not a valid allocation 

SIDE EFFECTS
  The nv_cmd_ext_type is placed on the NV command queue.  It must not be
  modified until the command has been processed!

===========================================================================*/

nv_stat_enum_type nv_cmd_ext_remote
( 
  nv_func_enum_type cmd, 
  nv_items_enum_type item, 
  nv_item_type *data_ptr,
  uint16 context 
); 
/*~ FUNCTION nv_cmd_ext_remote */ 
/*~ PARAM INOUT data_ptr POINTER DISC item */ 

/*===========================================================================

FUNCTION NV_RTRE_CONTROL

DESCRIPTION
  This function provides the current RTRE control.  The control indicates 
  whether the use the R-UIM in an operation or not.

DEPENDENCIES
  The return value has a default setting and is updated when NV receives
  a NV_RTRE_OP_CONFIG_F command.

RETURN VALUE
  The RTRE control

SIDE EFFECTS
  This function returns the current value of the RTRE control.  It may
  change.

===========================================================================*/

nv_rtre_control_type nv_rtre_control( void );

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_rtre_control */

/*===========================================================================

FUNCTION NV_RTRE_USE_RUIM_FOR_NAM

DESCRIPTION
  This function determines if the R-UIM is to be used (based on RTRE control)
  and the NAM is the R-UIM NAM.
  
DEPENDENCIES
  The return value has a default setting and is updated when NV receives
  a NV_RTRE_OP_CONFIG_F command.

RETURN VALUE
  The RTRE control indicates to use the R-UIM and the NAM matches the R-UIM 
  NAM.

SIDE EFFECTS
  This function uses the current value of the RTRE control.  It may
  change.

===========================================================================*/

boolean nv_rtre_use_ruim_for_nam ( byte nam );

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_rtre_use_ruim_for_nam */

/*===========================================================================

FUNCTION NV_RTRE_POLLING_CONTROL

DESCRIPTION
  This function provides the current RTRE polling control.  The polling control
  indicates whether to poll the UIM card when originating a call or while on 
  the traffic channel.

DEPENDENCIES
  The return value has a default setting and is updated when NV receives
  a NV_RTRE_OP_CONFIG_F command.

RETURN VALUE
  The RTRE polling control

SIDE EFFECTS
  This function returns the current value of the RTRE polling control.  It may
  change.

===========================================================================*/

nv_rtre_polling_control_type nv_rtre_polling_control( void );

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_rtre_polling_control */

/*===========================================================================

FUNCTION NV_RTRE_POLLING_FOR_NAM

DESCRIPTION
  This function provides the current RTRE polling control when the NAM is the 
  R_UIM NAM.  The polling control indicates whether to poll the UIM card when 
  originating a call or while on the traffic channel.

DEPENDENCIES
  The return value has a default setting and is updated when NV receives
  a NV_RTRE_OP_CONFIG_F command.

RETURN VALUE
  The RTRE polling control indicates whether to poll and the NAM matches the
  R-UIM NAM.

SIDE EFFECTS
  This function returns the current value of the RTRE polling control.  It may
  change.

===========================================================================*/

boolean nv_rtre_polling_for_nam ( byte nam );

/*These are HTORPC Meta comments. Do not delete this*/
/*~ FUNCTION nv_rtre_polling_for_nam */

#endif /* NV_H */

#endif /* ! NV_H_trimmed */
