#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/file.h>
#include <dirent.h>
#include <errno.h>

#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#include <pwd.h>
#include <grp.h>

#include <linux/kdev_t.h>

#define LOG_TAG "Tool Write"
#include <utils/Log.h>

int write_main(int argc, char **argv)
{
    if(argc == 3)
    {
        char buf[20];
        int file = open(argv[1], O_RDWR );
    
        if (-1 == file)
	    {
		    LOGE("open file %s Failed! ", argv[1]);
		    fprintf(stderr,"open file %s Failed!\n", argv[1]);
		    return 0;
	    }
	
	    LOGE("open file %s OK! and write value is %s ", argv[1], argv[2]);
	    fprintf(stderr,"open file %s OK! and write value is %s \n", argv[1], argv[2]);
	
	    if( strlen(argv[2]) < 10 )
	    {
	    	strcpy(buf, argv[2]);
	    	
	    	buf[strlen(argv[2])] = '\n';
	    	buf[strlen(argv[2]) + 1] = 0;
            	       
    	    write(file, buf, strlen(buf));    	   
        }
    
	    close(file);
    }
    else
    {
        LOGE("parameters are incorrect!");
        fprintf(stderr,"parameters are incorrect!\n");
    }
    
    return 0;
}
