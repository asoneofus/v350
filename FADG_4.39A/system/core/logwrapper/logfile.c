/*
 *  system/core/logwrapper/logfile.c
 *
 *  Copyright (C) 2009  by FIHTDC Kenny
 *
 */

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>

#include "cutils/log.h"

#define DEFAULT_LOG_ROTATE_SIZE_KBYTES 128
#define DEFAULT_MAX_ROTATED_LOGS    3
#define PATH_PMLOG      "/proc/pmlog"
#define PATH_KLOG       "/proc/kmsg"
#define PATH_EVENTLOG   "/proc/eventlog"  /* FIH, JiaHao, 2011/07/11 */
#define LOG_LINE_LENGTH    1024

static int g_logFD = -1;
static int g_outFD = -1;
static int g_logSrc = 0;
static int g_logRotateSizeKBytes = DEFAULT_LOG_ROTATE_SIZE_KBYTES;    // 0 means "no log rotation"
static int g_maxRotatedLogs = DEFAULT_MAX_ROTATED_LOGS;               // 0 means "unbounded"
static off_t g_outByteCount = 0;
static const char *g_outputFileName;
static char g_logSrcPath[3][32] = { PATH_PMLOG, PATH_KLOG, PATH_EVENTLOG };  /* FIH, JiaHao, 2011/07/11 */

static void fatal(const char *msg) {
    fprintf(stderr, "%s", msg);
    LOG(LOG_ERROR, "logfile", "%s", msg);
    exit(-1);
}

static void usage() {
    fprintf(stderr,"Usage: logfile [options]\n");
    
    fprintf(stderr, "options include:\n"
                    "  -b              Set logfile source from pmlog\n"
                    "  -k              Set logfile source from kmsg\n"
                    "  -e              Set logfile source from eventlog\n"  /* FIH, JiaHao, 2011/07/11 */
                    "  -f <filename>   Log to file. Default to stdout\n"
                    "  -r [<kbytes>]   Rotate log every kbytes. (128 if unspecified). Requires -f\n"
                    "  -n <count>      Sets max number of rotated logs to <count>, default 3\n");
}

static int openLogFile (const char *pathname)
{
    return open(g_outputFileName, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}

static void rotateLogs()
{
    int err;
    int i;

    // Can't rotate logs if we're not outputting to a file
    if (g_outputFileName == NULL) {
        return;
    }

    close(g_outFD);

    for (i = g_maxRotatedLogs ; i > 0 ; i--) {
        char *file0, *file1;

        asprintf(&file1, "%s.%d", g_outputFileName, i);

        if (i - 1 == 0) {
            asprintf(&file0, "%s", g_outputFileName);
        } else {
            asprintf(&file0, "%s.%d", g_outputFileName, i - 1);
        }

        err = rename (file0, file1);

        if (err < 0 && errno != ENOENT) {
            perror("while rotating log files");
        }

        free(file1);
        free(file0);
    }

    g_outFD = openLogFile (g_outputFileName);

    if (g_outFD < 0) {
        perror ("couldn't open output file");
        LOG(LOG_ERROR, "logfile", "Couldn't open output file\n");
        exit(-1);
    }

    g_outByteCount = 0;

}

static void readLogLines()
{
    int ret;
    size_t size;
    unsigned char buf[LOG_LINE_LENGTH + 1];
    while (1) {
        ret = read(g_logFD, buf, LOG_LINE_LENGTH);
        if (ret < 0) {
            if (errno == EINTR)
                continue;
            if (errno == EAGAIN)
                break;
            perror("logfile read");
            LOG(LOG_ERROR, "logfile", "read proc file failed\n");
            exit(EXIT_FAILURE);
        }
        else if (!ret) {
            fprintf(stderr, "read: Unexpected EOF!\n");
            LOG(LOG_ERROR, "logfile", "read proc file failed\n");
            exit(EXIT_FAILURE);
        }
        size = ret;
        do {
            ret = write(g_outFD, buf, size);
        } while (ret < 0 && errno == EINTR);
        
        g_outByteCount += ret;

        if (g_logRotateSizeKBytes > 0 
            && (g_outByteCount / 1024) >= g_logRotateSizeKBytes
        ) {
            rotateLogs();
        }
    }
}

static void setupOutput()
{

    if (g_outputFileName == NULL) {
        g_outFD = STDOUT_FILENO;

    } else {
        struct stat statbuf;

        g_outFD = openLogFile (g_outputFileName);

        if (g_outFD < 0) {
            perror ("couldn't open output file");
            LOG(LOG_ERROR, "logfile", "Cannot open output file\n");
            exit(-1);
        }

        fstat(g_outFD, &statbuf);

        g_outByteCount = statbuf.st_size;
    }
}

static void setLogSource(void)

{
	struct stat sb;
	/*
	 * First do a stat to determine whether or not the proc based
	 * file system is available to get messages from.
	 */
	if ( ((stat(g_logSrcPath[g_logSrc], &sb) < 0) && (errno == ENOENT)) )
	{
	    fatal("proc based file system is not available\n");
	}
	
	if ( (g_logFD = open(g_logSrcPath[g_logSrc], O_RDONLY)) < 0 )
    {
		fprintf(stderr, "logfile: Cannot open proc file system, " \
			"%d - %s.\n", errno, strerror(errno));
		LOG(LOG_ERROR, "logfile", "Cannot open proc file system\n");
		exit(-1);
    }
	return;
}

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        usage();
        exit(-1);
    }
    
    for (;;) {
        int ret;

        ret = getopt(argc, argv, "bkef:r:n:");  /* FIH, JiaHao, 2011/07/11 */

        if (ret < 0) {
            break;
        }

        switch(ret) {
            case 'b': 
                g_logSrc = 0;
            break;

            case 'k':
                g_logSrc = 1;
            break;

            /* FIH, JiaHao, 2011/07/11 { */
            case 'e':
                g_logSrc = 2;
            break;
            /* FIH, JiaHao, 2011/07/11 } */

            case 'r':
                if (optarg == NULL) {                
                    g_logRotateSizeKBytes = DEFAULT_LOG_ROTATE_SIZE_KBYTES;
                } else {
                    long logRotateSize;
                    char *lastDigit;

                    if (!isdigit(optarg[0])) {
                        fprintf(stderr,"Invalid parameter to -r\n");
                        usage();
                        exit(-1);
                    }
                    g_logRotateSizeKBytes = atoi(optarg);
                }
            break;

            case 'n':
                if (!isdigit(optarg[0])) {
                    fprintf(stderr,"Invalid parameter to -r\n");
                    usage();
                    exit(-1);
                }

                g_maxRotatedLogs = atoi(optarg);
            break;
            
            case 'f':
                // redirect output to a file
                g_outputFileName = optarg;

            break;
            
            default:
                fprintf(stderr,"Unrecognized Option\n");
                usage();
                exit(-1);
            break;
       }
    }    
    LOG(LOG_DEBUG, "logfile", "start logfile for %s", g_logSrcPath[g_logSrc]);
    setupOutput();
    setLogSource();
    readLogLines();
  
    return 0;
}
