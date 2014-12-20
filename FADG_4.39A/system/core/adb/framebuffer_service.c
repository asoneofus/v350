/*
 * Copyright (C) 2007 The Android Open Source Project
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

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include "fdevent.h"
#include "adb.h"

#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

//#include <cutils/log.h>

//#define LOG_TAG "fb"

// chandler: for qualcomm 3d hw limitation. +++
#define ALIGN(x, a)		__ALIGN_MASK(x, (typeof(x))(a)-1)
#define __ALIGN_MASK(x, mask)	(((x)+(mask))&~(mask))
// chandler: for qualcomm 3d hw limitation. ---

/* TODO:
** - sync with vsync to avoid tearing
*/
/* This version number defines the format of the fbinfo struct.
   It must match versioning in ddms where this data is consumed. */
#define DDMS_RAWIMAGE_VERSION 1
struct fbinfo {
    unsigned int version;
    unsigned int bpp;
    unsigned int size;
    unsigned int width;
    unsigned int height;
    unsigned int red_offset;
    unsigned int red_length;
    unsigned int blue_offset;
    unsigned int blue_length;
    unsigned int green_offset;
    unsigned int green_length;
    unsigned int alpha_offset;
    unsigned int alpha_length;
} __attribute__((packed));

extern void framebuffer_service_dmq(int fd, void *cookie);


void framebuffer_service(int fd, void *cookie)
{
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;	
    int fb, offset;
    int VISUAL_X, REAL_X;
    //Div6-D1-JL-ADB_FRAMEBUFFER-00+{
    //char x[256];
    //unsigned i, bytespp;
	char x;
    void *ptr = MAP_FAILED;
    unsigned bytespp;
    //Div6-D1-JL-ADB_FRAMEBUFFER-00+}

    struct fbinfo fbinfo;
    
    fb = open("/dev/graphics/fb0", O_RDONLY);
    if(fb < 0) goto done;

    if(ioctl(fb, FBIOGET_VSCREENINFO, &vinfo) < 0) goto done;
    if(ioctl(fb, FBIOGET_FSCREENINFO, &finfo) < 0) goto done;

	VISUAL_X=vinfo.xres * vinfo.bits_per_pixel/8;
	REAL_X=finfo.line_length;
	
	if(VISUAL_X==240*2 && REAL_X==256*2){
		//LOGE("%s: resolution (240x320)\n", __func__);		
		close(fb);
		framebuffer_service_dmq(fd,cookie);
		return ;
	}
    fcntl(fb, F_SETFD, FD_CLOEXEC);
	
// chandler: for qualcomm 3d hw limitation+++
	//vinfo.xres=ALIGN(vinfo.xres, 32); 
// chandler: for qualcomm 3d hw limitation---	
    bytespp = vinfo.bits_per_pixel / 8;

    fbinfo.version = DDMS_RAWIMAGE_VERSION;
    fbinfo.bpp = vinfo.bits_per_pixel;
    fbinfo.size = vinfo.xres * vinfo.yres * bytespp;
    fbinfo.width = vinfo.xres;
    fbinfo.height = vinfo.yres;
    fbinfo.red_offset = vinfo.red.offset;
    fbinfo.red_length = vinfo.red.length;
    fbinfo.green_offset = vinfo.green.offset;
    fbinfo.green_length = vinfo.green.length;
    fbinfo.blue_offset = vinfo.blue.offset;
    fbinfo.blue_length = vinfo.blue.length;
    fbinfo.alpha_offset = vinfo.transp.offset;
    fbinfo.alpha_length = vinfo.transp.length;
    
/* FIHTDC-Div2-SW2-BSP, Ming { */    
/* Reverse the offset of RGBA to make DDMS show correct color */
#ifdef CONFIG_FIH_CONFIG_GROUP
    if (fbinfo.bpp == 32) {
        if ((fbinfo.red_offset == 24) &&
            (fbinfo.green_offset == 16) &&
            (fbinfo.blue_offset == 8) &&
            (fbinfo.alpha_offset == 0)) { /* RGBA8888 */
                //LOGI("%s: Reverse the offset of RGBA8888\n", __func__);
                fbinfo.red_offset   = 0;
                fbinfo.green_offset = 8;
                fbinfo.blue_offset  = 16;
                fbinfo.alpha_offset = 24;                
        }
    }
#endif // CONFIG_FIH_CONFIG_GROUP
/* } FIHTDC-Div2-SW2-BSP, Ming */ 

    /* HACK: for several of our 3d cores a specific alignment
     * is required so the start of the fb may not be an integer number of lines
     * from the base.  As a result we are storing the additional offset in
     * xoffset. This is not the correct usage for xoffset, it should be added
     * to each line, not just once at the beginning */
    offset = vinfo.xoffset * bytespp;

    offset += vinfo.xres * vinfo.yoffset * bytespp;

    //Div6-D1-JL-ADB_FRAMEBUFFER-00+{
    /* Multiple framebuffer raw data reading/writing maybe cause the display tearing
     * The tearing raw data may cause adb.exe crash and impact CountDown test
     * Avoid the crash, read framebuffer once and bypass to remote for fully data synchronizing*/
    ptr = mmap(0, fbinfo.size, PROT_READ, MAP_SHARED, fb, 0);
    if(ptr == MAP_FAILED) goto done;
    //Div6-D1-JL-ADB_FRAMEBUFFER-00+}

    if(writex(fd, &fbinfo, sizeof(fbinfo))) goto done;

    //Div6-D1-JL-ADB_FRAMEBUFFER-00+{
    //
    #if 0
    lseek(fb, offset, SEEK_SET);
    for(i = 0; i < fbinfo.size; i += 256) {
      if(readx(fb, &x, 256)) goto done;
      if(writex(fd, &x, 256)) goto done;
    }

    if(readx(fb, &x, fbinfo.size % 256)) goto done;
    if(writex(fd, &x, fbinfo.size % 256)) goto done;
    #else
    for(;;) 
    {
        if(readx(fd, &x, 1)) goto done;
        if(writex(fd, ptr, fbinfo.size)) goto done;
    }
    #endif
    //Div6-D1-JL-ADB_FRAMEBUFFER-00+}


done:
    if(ptr != MAP_FAILED) munmap(ptr, fbinfo.size); //Div6-D1-JL-ADB_FRAMEBUFFER-00+
    if(fb >= 0) close(fb);
    close(fd);
}

void framebuffer_service_dmq(int fd, void *cookie)
{
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
	/*
		FIH, Chandler, 2011.2.21
			REAL_X is the x-resolution in FB, 
			VISUAL_X is the visual x-resolution for user.
			In DMQ(240x320), two values are different.
	*/
	int VISUAL_X, REAL_X;
    int fb, offset;
    //char x[REAL_X];
	char *x=0, *fake_fb=0, *ptr_fake_fb=0;

    struct fbinfo fbinfo;
    unsigned i, bytespp;

    fb = open("/dev/graphics/fb0", O_RDONLY);
    if(fb < 0) goto done;

    if(ioctl(fb, FBIOGET_VSCREENINFO, &vinfo) < 0) goto done;
	
    if(ioctl(fb, FBIOGET_FSCREENINFO, &finfo) < 0) goto done;
	
    fcntl(fb, F_SETFD, FD_CLOEXEC);
	
	x=malloc(finfo.line_length);
	if(!x) {
		//LOGE("x malloc failed \n");
		goto done;
	}
	

	VISUAL_X=vinfo.xres * vinfo.bits_per_pixel/8;
	REAL_X=finfo.line_length;

	fake_fb=malloc(VISUAL_X * vinfo.yres);
	if(!fake_fb) {
		//LOGE("fake_fb malloc failed \n");
		goto done;
	}
	
// chandler: for qualcomm 3d hw limitation+++
	//vinfo.xres=ALIGN(vinfo.xres, 32); 
// chandler: for qualcomm 3d hw limitation---	
    bytespp = vinfo.bits_per_pixel / 8;

    fbinfo.version = DDMS_RAWIMAGE_VERSION;
    fbinfo.bpp = vinfo.bits_per_pixel;
    fbinfo.size = vinfo.xres * vinfo.yres * bytespp;
    fbinfo.width = vinfo.xres;
    fbinfo.height = vinfo.yres;
    fbinfo.red_offset = vinfo.red.offset;
    fbinfo.red_length = vinfo.red.length;
    fbinfo.green_offset = vinfo.green.offset;
    fbinfo.green_length = vinfo.green.length;
    fbinfo.blue_offset = vinfo.blue.offset;
    fbinfo.blue_length = vinfo.blue.length;
    fbinfo.alpha_offset = vinfo.transp.offset;
    fbinfo.alpha_length = vinfo.transp.length;
    

    /* HACK: for several of our 3d cores a specific alignment
     * is required so the start of the fb may not be an integer number of lines
     * from the base.  As a result we are storing the additional offset in
     * xoffset. This is not the correct usage for xoffset, it should be added
     * to each line, not just once at the beginning */
    offset = vinfo.xoffset * bytespp;

    //offset += vinfo.xres * vinfo.yoffset * bytespp;
    offset += (REAL_X) * vinfo.yoffset ;

    if(writex(fd, &fbinfo, sizeof(fbinfo))) goto done;

    lseek(fb, offset, SEEK_SET);

	ptr_fake_fb=fake_fb;
	
    for(i = 0; i < fbinfo.size; i += VISUAL_X) {
      if(readx(fb, x, REAL_X)) goto done;
      //if(writex(fd, x, VISUAL_X)) goto done;
      memcpy(ptr_fake_fb,x,VISUAL_X);
	  ptr_fake_fb+=VISUAL_X;
    }
/*
    if(readx(fb, x, fbinfo.size % REAL_X)) goto done;
    //if(writex(fd, x, fbinfo.size % VISUAL_X)) goto done;
      memcpy(ptr_fake_fb,x,VISUAL_X);
	  ptr_fake_fb+=VISUAL_X;
*/
	for(;;) 
    {
		if(readx(fd, x, 1)) goto done;//test
		if(writex(fd, fake_fb, fbinfo.size)) goto done;
	}
done:

    if(fb >= 0) close(fb);
    close(fd);

	if(x) free(x);
	if(fake_fb) free(fake_fb);
}
