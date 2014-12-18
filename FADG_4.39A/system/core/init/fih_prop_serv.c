// Copyright 2006 The Android Open Source Project

#include <cutils/logger.h>
#include <cutils/logd.h>
#include <cutils/sockets.h>
#include <cutils/logprint.h>
#include <cutils/event_tag_map.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <assert.h>
#include <ctype.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>


#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>


#include "util.h"
#include "log.h"


typedef struct{
    char name[PROP_NAME_MAX];
    char value[PROP_VALUE_MAX];
}fihcda_prop_t;


#define FILE_BUF_MAX 1024
#define PROP_COUNT_MAX  247
#define CDA_PROPERTY_SERV_STATUS_FILE "/hidden/data/CDA/cdaprop_serv_status" 
#define PORP_KEY_CDA_MODEL_NUM "ro.product.model.num"
#define PORP_KEY_PRODUCT_DEVICE "ro.product.device"
#define PORP_KEY_BUILD_PRODUCT "ro.build.product"

#define CDA_PROPERTY_RESULT_FILE "/hidden/data/CDA/cdaprop_result" 

//for Huawei start
#define PORP_HUAWEI_REPLACE_LIST "ro.build.id",\
                                 "ro.build.display.id"

//for Huawei end

fihcda_prop_t *fihcda_prop;
static int    fihcda_prop_count=0;

static char *prop_filter[]={
    "ro.build.version.incremental",
    "ro.build.description",
    "ro.build.fingerprint",
    "ro.product.model.num",
    "ro.product.name",
    PORP_KEY_PRODUCT_DEVICE,
    "ro.product.model",
    "ro.product.brand",
    "ro.product.board",
    PORP_KEY_BUILD_PRODUCT,
    PORP_HUAWEI_REPLACE_LIST,
    NULL
};

static char *model_number_filter[]={
    "ro.build.version.incremental",
    NULL
};

void fih_property_list(void)
{
    int i;
    
    for(i=0;i<fihcda_prop_count;i++)
    {
        ERROR("fihcda_prop[%d] name=%s,value=%s\n",i,fihcda_prop[i].name,fihcda_prop[i].value);
    }
}

int fih_file_isExist(const char *fn)
{
    int fd;

    fd = open(fn, O_RDONLY);
    if(fd < 0) return 0;
        
    close(fd);
    return 1;
}

void fih_file_writeStatusFile(const char *fn)
{
    int fd;
    char buf[64];

    fd = open(fn, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if (fd < 0) {
        ERROR("Unable to write property to file %s errno: %d\n", fn, errno);
        return;
    }
    
    snprintf(buf, sizeof(buf), "OK");
    write(fd, buf, strlen(buf));   
    
    close(fd);
}

void fih_file_writeResultFile(const char *fn, int result)
{
    int fd;
    char buf[64];

    fd = open(fn, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if (fd < 0) {
        ERROR("Unable to write property to file %s errno: %d\n", fn, errno);
        return;
    }
    
    snprintf(buf, sizeof(buf), "result=%d",result);
    write(fd, buf, strlen(buf));   
    
    close(fd);
}

/* reads a file, making sure it is terminated with \n \0 */
void *fih_read_file(const char *fn, unsigned *_sz)
{
    char *data;
    int sz;
    int fd;

    data = 0;
    fd = open(fn, O_RDONLY);
    if(fd < 0) return 0;

    sz = lseek(fd, 0, SEEK_END);
    if(sz < 0) goto oops;

    if(lseek(fd, 0, SEEK_SET) != 0) goto oops;

    data = (char*) malloc(sz + 2);
    if(data == 0) goto oops;

    if(read(fd, data, sz) != sz) goto oops;
    close(fd);
    data[sz] = '\n';
    data[sz+1] = 0;
    if(_sz) *_sz = sz;
    return data;

oops:
    close(fd);
    if(data != 0) free(data);
    return 0;
}

int fih_property_find(const char *name)
{
    int i, index=-1;
    
    for(i=0;i<fihcda_prop_count;i++)
    {
        if( 0 == strcmp(fihcda_prop[i].name, name) )
        {
            index = i;
        }
    }
    /*if( index >= 0){
        ERROR("fih_property_find name=%s,index=%d,fihcda_prop[%d].name=%s \n",name,index, index,fihcda_prop[index].name);
    }else{
       ERROR("fih_property_find name=%s,index=%d\n",name,index);
    }*/
     
    return index;
}

int fih_property_find_filter(const char *name)
{
    int i, index=-1;
    
    for(i=0;prop_filter[i];i++)
    {
        if( 0 == strcmp(prop_filter[i], name) )
        {
            index = i;
        }
    }
    /*if( index >= 0){
        ERROR("fih_property_find name=%s,index=%d,fihcda_prop[%d].name=%s \n",name,index, index,fihcda_prop[index].name);
    }else{
       ERROR("fih_property_find name=%s,index=%d\n",name,index);
    }*/
     
    return index;
}
    
int fih_property_set(const char *name, const char *value)
{
    int namelen,valuelen, index;
    
    if(name == 0) return -1;
    if(value == 0) return -1;
        
    //ERROR("PROP_VALUE_MAX=%d\n",PROP_VALUE_MAX); 
    //ERROR("fih_property_set name=%s,value=%s\n",name,value); 
    namelen = strlen(name);
    valuelen = strlen(value);
    if(namelen > PROP_NAME_MAX) return -1;
    if(valuelen >= PROP_VALUE_MAX) return -1;
        
    if(fihcda_prop_count >= PROP_COUNT_MAX) return -2;
        
    index = fih_property_find(name);
    if( index >= PROP_COUNT_MAX) return -2;
        
    if( index>=0 )
    {
        strlcpy( fihcda_prop[index].value, value, sizeof(fihcda_prop[index].value)); 
    }
    else
    {
        strlcpy( fihcda_prop[fihcda_prop_count].name, name, sizeof(fihcda_prop[index].name));
        strlcpy( fihcda_prop[fihcda_prop_count].value, value, sizeof(fihcda_prop[index].value)); 
        fihcda_prop_count++;
    }
    //ERROR("fih_property_set end\n"); 
    
    
    return 0;
}
char *fih_property_get(const char *name)
{
    int index;
    
    index = fih_property_find(name);
    if(index <0 || index>fihcda_prop_count)
    {
        return NULL;
    }else {
        return fihcda_prop[index].value;
    }
   
}

//for Huawei start

static void fih_replace_Huawei_BuildVer(char *buildVer)
{  
    char prop_value[PROP_VALUE_MAX];
    
    char *hwt_lver=fih_property_get((const char *)"ro.hwt.lver");
    char *hwt_cver=fih_property_get((const char *)"ro.hwt.cver");

    if(NULL==hwt_lver && NULL ==hwt_cver)
	return;
    
    if(strlen(buildVer)==10)
    { // xxxx_x_xxx
	char bver[4]={0},sver[3]={0};
        bver[0]=buildVer[5];
	bver[1]=buildVer[7];
	bver[2]=buildVer[8];
	if(buildVer[9]>='0' && buildVer[9]<='9')
	{
		sver[0]='0';
		sver[1]=buildVer[9];
	}
	else if(buildVer[9] >= 'A' && buildVer[9] <= 'Z')
	{
		//A->10 B->11 ... Z->35
		sprintf(sver,"%02d",buildVer[9]-55);
	}	
        ERROR("Huawei_BuildVer:%s (%s %s)\n",buildVer,bver,sver);

	if(NULL !=hwt_lver && NULL != hwt_cver)
	   snprintf( prop_value, sizeof(prop_value),"%sC%sB%sSP%s",hwt_lver,hwt_cver,bver,sver);
        else if(NULL !=hwt_cver)
           snprintf( prop_value, sizeof(prop_value),"C%sB%sSP%s",hwt_cver,bver,sver);
        
        INFO("BuildVer:%s --> %s\n",buildVer,prop_value);
    } 
    else if( strlen(buildVer) >= 11 && strlen(buildVer) <= 15)
    {//Huawei format: [LLL]CxxxBxxxSPxx
	char *cptr=strchr(buildVer,'C');
	char *bptr=strchr(buildVer,'B');
	if(NULL != cptr && NULL != bptr && NULL != strchr(buildVer,'S') && NULL != strchr(buildVer,'P'))
	{
	    if(NULL !=hwt_lver && NULL != hwt_cver)
	        snprintf( prop_value, sizeof(prop_value),"%sC%s%s",hwt_lver,hwt_cver,bptr);
            else if(NULL !=hwt_cver)
                snprintf( prop_value, sizeof(prop_value),"C%s%s",hwt_cver,bptr);
	}	
        ERROR("BuildVer:%s --> %s\n",buildVer,prop_value);
    }
    else
    {
        ERROR("BuildVer: unknown format(%s).\n",buildVer);
	return;
    }
    fih_property_set("ro.build.version.incremental", prop_value);
}

static void fih_replace_Huawei_BuildNum()
{
    char *dsp=fih_property_get((const char *)"ro.build.display.id");
    char *pBoard=fih_property_get((const char *)"ro.product.board");
    char *pbv=fih_property_get((const char *)"ro.build.version.incremental");
    char *hwt_vver=fih_property_get((const char *)"ro.hwt.vver");
    char *hwt_rver=fih_property_get((const char *)"ro.hwt.rver");
    char *hwt_lver=fih_property_get((const char *)"ro.hwt.lver");
    char *hwt_cver=fih_property_get((const char *)"ro.hwt.cver");
    char prop_value[PROP_VALUE_MAX];
    int fd;    

    if(NULL==hwt_vver && NULL==hwt_rver && NULL==hwt_lver && NULL ==hwt_cver)
	return;
         
    
    //format :  BOARD_NAME VxxxRxxx[LLL]CxxxBxxxSPxx
    if(NULL != strchr(dsp,'V') && NULL != strchr(dsp,'R') && NULL != strchr(dsp,'C')\
       && NULL != strchr(dsp,'B') && NULL != strchr(dsp,'S') && NULL != strchr(dsp,'P'))
    {
        char *vptr=strchr(dsp,'V');
	char ver[9]={0};
	  
        if(NULL != hwt_vver && NULL != hwt_rver)
	{
           snprintf( ver, sizeof(ver),"V%sR%s",hwt_vver,hwt_rver);
	}
	else if(NULL != hwt_vver)
	{
	   strcpy(ver,hwt_rver);
	   strncat(ver,vptr+4,4);
	}
	else if(NULL != hwt_rver)
        {
	  strncpy(ver,vptr,4);
	  strcat(ver,hwt_rver);
	}
        else
        {
	   strncpy(ver,vptr,8);
	} 
	snprintf( prop_value, sizeof(prop_value),"%s %s%s",pBoard,ver,pbv); 
	ERROR("BuildNum:%s --> %s\n",dsp,prop_value);      	  
    }
    else if(NULL != hwt_vver && NULL != hwt_rver)
    {
	snprintf( prop_value, sizeof(prop_value),"%s V%sR%s%s",pBoard,hwt_vver,hwt_rver,pbv);
        ERROR("BuildNum:%s --> %s\n",dsp,prop_value); 
    }
    else
    {
      ERROR("BuildNum: unknown format(%s).\n",dsp);
      return;
    }
    fih_property_set("ro.build.display.id", prop_value);  
    
    fd = open("/system/build_number", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd < 0) {
        ERROR("Unable to write build_number(%d)\n", errno);
    }
    else
    {
	 write(fd, prop_value, strlen(prop_value)); 
         close(fd);
    }
}    
//for Huawei end


void fih_load_properties(char *data)
{
    char *key, *value, *eol, *sol, *tmp;

    sol = data;
    while((eol = strchr(sol, '\n'))) {
        key = sol;
        *eol++ = 0;
        sol = eol;

        value = strchr(key, '=');
        if(value == 0) continue;
        *value++ = 0;

        while(isspace(*key)) key++;
        if(*key == '#') continue;
        tmp = value - 2;
        while((tmp > key) && isspace(*tmp)) *tmp-- = 0;

        while(isspace(*value)) value++;
        tmp = eol - 2;
        while((tmp > value) && isspace(*tmp)) *tmp-- = 0;

        fih_property_set(key, value);
    }
}

void fih_replace_model_number(char *modelNum)
{
    int  i,index;
    char prop_value[PROP_VALUE_MAX],*part1,*part2,*part3;
    const char *delim="_";
    char *prodName,*buildType,*platVer,*buildId,*buildVer,*buildTag;
    char *proBrand,*proDevice,*proBoard;
    //get model number property value
    
    //replace model number
    for (i = 0; model_number_filter[i]; i++) {
        //ERROR("model_number_filter[%d]=%s\n",i,model_number_filter[i]);
        index = fih_property_find(model_number_filter[i]);
        if(index >=0 && index<fihcda_prop_count)
        {
            strlcpy(prop_value, fihcda_prop[index].value, sizeof(prop_value));
           // ERROR("replace before value=%s\n",prop_value);
            part1 = prop_value;
            part2 = strchr(prop_value,'_');
            if(part2 == 0)
            {
                continue;
            }
            *part2++=0;
            //ERROR("value=%s,part1=%s,part2=%s\n",prop_value,part1,part2);
            part3 = strchr(part2,'_');
            if(part3 == 0)
            {
                continue;
            }
            *part3++=0;            
            //ERROR("22 value=%s,part1=%s,part2=%s,part3=%s\n",prop_value,part1,part2,part3);
            if(strlen(part1) == 1) //version format:X_XXX_XXXX
            {
                snprintf(fihcda_prop[index].value, sizeof(fihcda_prop[index].value), "%s_%s_%s",part1,part2, modelNum);
            }else{ //version format:XXXX_X_XXX
                snprintf(fihcda_prop[index].value, sizeof(fihcda_prop[index].value), "%s_%s_%s",modelNum, part2, part3 );
            }                
            //ERROR("replace after value=%s\n",fihcda_prop[index].value);
            
        }
    }
    
    //replace combined property
    //ro.build.description
    //Froyo
    //=DISPLAY_PRIVATE_BUILD_DESC := $(DISPLAY_PRODUCT_NAME)-$(TARGET_BUILD_VARIANT) $(PLATFORM_VERSION) $(BUILD_ID) $(DISPLAY_BUILD_NUMBER) $(BUILD_VERSION_TAGS)
    //=ro.prodcut.name-ro.build.type ro.build.version.release ro.build.id ro.build.version.incremental ro.build.tags
    //GingerBread
    //=DISPLAY_PRIVATE_BUILD_DESC := $(DISPLAY_PRODUCT_NAME)-$(TARGET_BUILD_VARIANT) $(PLATFORM_VERSION) $(BUILD_ID) $(BUILD_NUMBER) $(BUILD_VERSION_TAGS)
    prodName = fih_property_get((const char *)"ro.product.name");
    buildType = fih_property_get((const char *)"ro.build.type");
    platVer = fih_property_get((const char *)"ro.build.version.release");
    buildId = fih_property_get((const char *)"ro.build.id");
    buildVer = fih_property_get((const char *)"ro.build.version.incremental");
    buildTag = fih_property_get((const char *)"ro.build.tags");
    
    //For Huawei start
    fih_replace_Huawei_BuildVer(buildVer);
    //For Huawei end 
    snprintf( prop_value, sizeof(prop_value), "%s-%s %s %s %s %s",prodName,buildType,platVer,buildId,buildVer,buildTag);
    ERROR("ro.build.description=%s\n",prop_value);
    fih_property_set("ro.build.description", prop_value);
    
    
    //ro.build.fingerprint
    //Froyo
    //=DISPLAY_BUILD_FINGERPRINT := $(DISPLAY_PRODUCT_BRAND)/$(DISPLAY_PRODUCT_NAME)/$(DISPLAY_PRODUCT_DEVICE)/$(DISPLAY_TARGET_BOOTLOADER_BOARD_NAME):$(PLATFORM_VERSION)/$(BUILD_ID)/$(DISPLAY_BUILD_NUMBER):$(TARGET_BUILD_VARIANT)/$(BUILD_VERSION_TAGS)
    //=ro.product.brand/ro.product.name/ro.product.device/ro.product.board: ro.build.version.release/ro.build.id/ ro.build.version.incremental/ro.build.type/ro.build.tags
    //Gingerbread 2.3.3
    //DISPLAY_BUILD_FINGERPRINT := $(PRODUCT_BRAND)/$(DISPLAY_PRODUCT_NAME)/$(DISPLAY_PRODUCT_DEVICE):$(PLATFORM_VERSION)/$(BUILD_ID)/$(BUILD_NUMBER):$(TARGET_BUILD_VARIANT)/$(BUILD_VERSION_TAGS)
    proBrand = fih_property_get((const char *)"ro.product.brand");
    proDevice = fih_property_get((const char *)"ro.product.device");
    proBoard = fih_property_get((const char *)"ro.product.board");
    
    //Froyo
    //snprintf( prop_value, sizeof(prop_value), "%s/%s/%s/%s:%s/%s/%s:%s/%s",proBrand,prodName,proDevice,proBoard,platVer,buildId,buildVer,buildType,buildTag);
    //Gingerbread 2.3.3
    snprintf( prop_value, sizeof(prop_value), "%s/%s/%s:%s/%s/%s:%s/%s",proBrand,prodName,proDevice,platVer,buildId,buildVer,buildType,buildTag);
    ERROR("ro.build.fingerprint=%s\n",prop_value);
    fih_property_set("ro.build.fingerprint", prop_value);
    
}

void fih_replace_build_id(const char *fn,char *modelNum)
{
    int fd;
    char *buildVer;
    
    fd = open(fn, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if (fd < 0) {
        ERROR("Unable to write property to file %s errno: %d\n", fn, errno);
        return;
    }
    
    buildVer = fih_property_get("ro.build.version.incremental");
    if(buildVer != 0)
    {
        write(fd, buildVer, strlen(buildVer));   
    }
    
    close(fd);
}
void fih_replace_build_proj(const char *fn,char *modelNum)
{
    char *data,buf[512];
    unsigned sz;
    char *projName,*part1,*part2,*part3;
    int fd;
    
    data = (char*)fih_read_file(fn, &sz);
    if(data == 0)
    {
        ERROR("read file error!\n");
        return;
    }
    
    ERROR("replace before value=%s\n",data);
    projName = data;
    
    part1 = strchr(projName,'_');
    if(part1 == 0)
    {
        return;
    }
    *part1++=0;
    
    part2 = strchr(part1,'_');
    if(part2 == 0)
    {
        return;
    }
    *part2++=0;
    //ERROR("value=%s,part1=%s,part2=%s\n",prop_value,part1,part2);
    part3 = strchr(part2,'_');
    if(part3 == 0)
    {
        return;
    }
    *part3++=0;            
    fprintf(stderr,"22 value=%s,part1=%s,part2=%s,part3=%s\n",projName,part1,part2,part3);
    if(strlen(part1) == 1) //version format:[PROJname]_[Ver]_[ver]_[ModelNum]
    {
        snprintf(buf, sizeof(buf), "%s_%s_%s_%s",projName,part1,part2, modelNum);
    }else{ //version format:[PROJname]_[ModelNum]_[Ver]_[ver]
        snprintf(buf, sizeof(buf), "%s_%s_%s_%s",projName,modelNum, part2, part3 );
    }                
    ERROR("replace after value=%s\n",buf);
            
                
    fd = open(fn, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if (fd < 0) {
        ERROR("Unable to write property to file %s errno: %d\n", fn, errno);
        return;
    }
    
    write(fd, buf, strlen(buf));   
    
    close(fd);
}
static void fih_load_properties_from_file(const char *fn)
{
    char *data;
    unsigned sz;

    data = (char *)fih_read_file(fn, &sz);

    if(data != 0) {
        fih_load_properties(data);
        free(data);
    }else{
        ERROR("read file error!\n");
    }
}

static void fih_replace_write_properties(const char *fn,char *data)
{
    char *key, *value, *eol, *sol, *tmp;
    int fd, length, i, index;
    char buf[FILE_BUF_MAX];
    
    fd = open(fn, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if (fd < 0) {
        ERROR("Unable to write property to file %s errno: %d\n", fn, errno);
        return;
    }
    
    sol = data;
    while((eol = strchr(sol, '\n'))) {
        key = sol;
        *eol++ = 0;
        sol = eol;

        //ERROR("key=%s,,\n", key);
        value = strchr(key, '=');
        //ERROR("value=%s,,\n", value);
        if(value == 0) 
        {
            length = snprintf(buf, sizeof(buf), "%s\n",key );
            if( length >0)
            {
                write(fd, buf, strlen(buf));
            }
            continue;
        }
        
        *value++ = 0;

        while(isspace(*key)) key++;
        if(*key == '#') continue;
        tmp = value - 2;
        while((tmp > key) && isspace(*tmp)) *tmp-- = 0;

        while(isspace(*value)) value++;
        tmp = eol - 2;
        while((tmp > value) && isspace(*tmp)) *tmp-- = 0;

        //fih_property_set(key, value);
        index = fih_property_find(key);        
        if( index>=0 )
        {
            length = snprintf(buf, sizeof(buf), "%s=%s\n",fihcda_prop[index].name, fihcda_prop[index].value );
            if( length >0)
            {
                write(fd, buf, strlen(buf));
            }
        }
        else
        {
            length = snprintf(buf, sizeof(buf), "%s=%s\n",key, value );
            if( length >0)
            {
                write(fd, buf, strlen(buf));
            }
        }
    }
    
    close(fd);
}

static void fih_replace_write_properties_with_filter(const char *fn,char *data)
{
    char *key, *value, *eol, *sol, *tmp;
    int fd, length, i, index,outModelNum;
    char buf[FILE_BUF_MAX];
    
    outModelNum=0;
    fd = open(fn, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if (fd < 0) {
        ERROR("Unable to write property to file %s errno: %d\n", fn, errno);
        return;
    }
    
    sol = data;
    while((eol = strchr(sol, '\n'))) {
        key = sol;
        *eol++ = 0;
        sol = eol;

        //ERROR("key=%s,,\n", key);
        value = strchr(key, '=');
       // ERROR("value=%s,,\n", value);
        if(value == 0) 
        {
            length = snprintf(buf, sizeof(buf), "%s\n",key );
            if( length >0)
            {
                write(fd, buf, strlen(buf));
            }
            continue;
        }
        
        *value++ = 0;

        while(isspace(*key)) key++;
        if(*key == '#') continue;
        tmp = value - 2;
        while((tmp > key) && isspace(*tmp)) *tmp-- = 0;

        while(isspace(*value)) value++;
        tmp = eol - 2;
        while((tmp > value) && isspace(*tmp)) *tmp-- = 0;

        //fih_property_set(key, value);
        if(fih_property_find_filter(key) >=0 )
        {
            if( 0 == strcmp(PORP_KEY_CDA_MODEL_NUM, key) ){
                outModelNum=1;
            }
                
            index = fih_property_find(key);        
            if( index>=0 )
            {
                length = snprintf(buf, sizeof(buf), "%s=%s\n",fihcda_prop[index].name, fihcda_prop[index].value );
                if( length >0)
                {
                    write(fd, buf, strlen(buf));
                }
            }
            else
            {
                length = snprintf(buf, sizeof(buf), "%s=%s\n",key, value );
                if( length >0)
                {
                    write(fd, buf, strlen(buf));
                }
            }
        }else{
            length = snprintf(buf, sizeof(buf), "%s=%s\n",key, value );
            if( length >0)
            {
                write(fd, buf, strlen(buf));
            }
        }
    }
    
    if(outModelNum==0){
        index = fih_property_find(PORP_KEY_CDA_MODEL_NUM);        
        if( index>=0 )
        {
            length = snprintf(buf, sizeof(buf), "%s=%s",fihcda_prop[index].name, fihcda_prop[index].value );
            if( length >0)
            {
                write(fd, buf, strlen(buf));
            }
        }
    }
    close(fd);
}

static void fih_replace_prop_file(const char *fn)
{
    int fd, length, i;
    char buf[FILE_BUF_MAX];
     
    fd = open(fn, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if (fd < 0) {
        ERROR("Unable to write property to file %s errno: %d\n", fn, errno);
        return;
    }
    
    for(i=0;i<fihcda_prop_count;i++)
    {
        //ERROR("fihcda_prop[%d] name=%s,value=%s\n",i,fihcda_prop[i].name,fihcda_prop[i].value);
        length = snprintf(buf, sizeof(buf), "%s=%s\n",fihcda_prop[i].name, fihcda_prop[i].value );
        if( length >0)
        {
            write(fd, buf, strlen(buf));
        }
    }
    
    close(fd);
}

static void fih_replace_prop_file_1(const char *fn)
{
    char *data;
    unsigned sz;

    data = (char *)fih_read_file(fn, &sz);

    if(data != 0) {
        fih_replace_write_properties(fn, data);
        free(data);
    }else{
        ERROR("read file error!\n");
    }
}

static void fih_replace_prop_file_with_filter(const char *fn)
{
    char *data;
    unsigned sz;

    data = (char *)fih_read_file(fn, &sz);

    if(data != 0) {
        fih_replace_write_properties_with_filter(fn, data);
        free(data);
    }else{
        ERROR("read file error!\n");
    }
}


int fih_prop_serv(void)
{
    int index;
    char *pModelNum=NULL;
    char *pProductDev=NULL;
    
    fprintf(stderr,"Fihcda begin\n");  
    ERROR("fih_prop_serv begin\n");
    /*if (argc == 2 && 0 == strcmp(argv[1], "--test")) {
        //logprint_run_tests();
        exit(0);
    }

    if (argc == 2 && 0 == strcmp(argv[1], "--help")) {
        //android::show_help(argv[0]);
        exit(0);
    }*/
    if( fih_file_isExist( CDA_PROPERTY_SERV_STATUS_FILE) >= 1 )
    {
        ERROR("System property have already replaced!\n");
        fih_file_writeResultFile(CDA_PROPERTY_RESULT_FILE, -1);
        return 0;
    }
        
    fihcda_prop = (fihcda_prop_t *) malloc(sizeof(fihcda_prop_t) * PROP_COUNT_MAX);
    
    if(fihcda_prop == 0) {
        fih_file_writeResultFile(CDA_PROPERTY_RESULT_FILE, -2);
        return 0;
    }
        
    fih_load_properties_from_file(PROP_PATH_SYSTEM_BUILD);
    fih_load_properties_from_file("/hidden/data/CDA/cda.prop");

    pProductDev = fih_property_get(PORP_KEY_PRODUCT_DEVICE);
    if(pProductDev != NULL)
    {
        ERROR("Replace value of ro.build.product in build.prop by value of ro.product.device");
        fih_property_set(PORP_KEY_BUILD_PRODUCT, pProductDev);
    }

    pModelNum = fih_property_get(PORP_KEY_CDA_MODEL_NUM);
    if( pModelNum != NULL)
    {
        if( strlen(pModelNum)>0 )
        {
            ERROR("pModelNum=%s\n",pModelNum); 
            fih_replace_model_number(pModelNum);
            fih_replace_build_id("/system/build_id",pModelNum);
            fih_replace_build_proj("/system/build_proj",pModelNum);
	    //for Huawei start
    	    fih_replace_Huawei_BuildNum();
            //for Huawei end
            fih_replace_prop_file_with_filter(PROP_PATH_SYSTEM_BUILD);
        }else{
            fih_file_writeResultFile(CDA_PROPERTY_RESULT_FILE, -3);
        }
    }else{
        ERROR("pModelNum ==null \n");  
        fih_file_writeResultFile(CDA_PROPERTY_RESULT_FILE, -4);
    }
    //fih_property_list();

    fprintf(stderr,"Fihcda end\n"); 
    ERROR("fih_prop_serv end\n");
    free(fihcda_prop);
    fih_file_writeStatusFile(CDA_PROPERTY_SERV_STATUS_FILE);
    return 1;
}
