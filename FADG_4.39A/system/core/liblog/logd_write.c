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
#include <time.h>
#include <stdio.h>
#ifdef HAVE_PTHREADS
#include <pthread.h>
#endif
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include <cutils/logger.h>
#include <cutils/logd.h>
#include <cutils/log.h>

#define LOG_BUF_SIZE	1024

//SW2-5-1-BH-DbgCfgTool-00+[
#include <sys/ioctl.h>
#include <cutils/dbgcfgtool.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cutils/logprint.h>
static int debug_android_uartmsg_enable = 0;
static int console_fd = -1;
//SW2-5-1-BH-DbgCfgTool-00+]

#if FAKE_LOG_DEVICE
// This will be defined when building for the host.
#define log_open(pathname, flags) fakeLogOpen(pathname, flags)
#define log_writev(filedes, vector, count) fakeLogWritev(filedes, vector, count)
#define log_close(filedes) fakeLogClose(filedes)
#else
#define log_open(pathname, flags) open(pathname, flags)
#define log_writev(filedes, vector, count) writev(filedes, vector, count)
#define log_close(filedes) close(filedes)
#endif

static int __write_to_log_init(log_id_t, struct iovec *vec, size_t nr);
static int (*write_to_log)(log_id_t, struct iovec *vec, size_t nr) = __write_to_log_init;
#ifdef HAVE_PTHREADS
static pthread_mutex_t log_init_lock = PTHREAD_MUTEX_INITIALIZER;
#endif

static int log_fds[(int)LOG_ID_MAX] = { -1, -1, -1, -1 };

/*
 * This is used by the C++ code to decide if it should write logs through
 * the C code.  Basically, if /dev/log/... is available, we're running in
 * the simulator rather than a desktop tool and want to use the device.
 */
static enum {
    kLogUninitialized, kLogNotAvailable, kLogAvailable 
} g_log_status = kLogUninitialized;
int __android_log_dev_available(void)
{
    if (g_log_status == kLogUninitialized) {
        if (access("/dev/"LOGGER_LOG_MAIN, W_OK) == 0)
            g_log_status = kLogAvailable;
        else
            g_log_status = kLogNotAvailable;
    }

    return (g_log_status == kLogAvailable);
}

static int __write_to_log_null(log_id_t log_fd, struct iovec *vec, size_t nr)
{
    return -1;
}

static int __write_to_log_kernel(log_id_t log_id, struct iovec *vec, size_t nr)
{
    ssize_t ret;
    int log_fd;

//SW2-5-1-BH-DbgCfgTool-00+[
    char uartmsg_buffer[LOG_BUF_SIZE];
    int pri = *(int*)(vec[0].iov_base);

    if (debug_android_uartmsg_enable && 
        (strcmp(vec[1].iov_base,"klogd") != 0) &&
        (pri >= ANDROID_LOG_VERBOSE && pri <= ANDROID_LOG_SILENT))
    {
        if( 0 > snprintf(uartmsg_buffer, LOG_BUF_SIZE, "%c/%s: %s\r\n",filterPriToChar (pri),(char *)vec[1].iov_base,(char *)vec[2].iov_base))
        {
            fprintf(stderr,"logd_write: snprintf error (%s)\n",strerror(errno));
        }
        else
        {
            if ( 0 > write(console_fd,uartmsg_buffer,strlen(uartmsg_buffer)))
            {
            fprintf(stderr,"logd_write: write error (%s)\n",strerror(errno));
            }
        }

    }
//SW2-5-1-BH-DbgCfgTool-00+]

    if (/*(int)log_id >= 0 &&*/ (int)log_id < (int)LOG_ID_MAX) {
        log_fd = log_fds[(int)log_id];
    } else {
        return EBADF;
    }

    do {
        ret = log_writev(log_fd, vec, nr);
    } while (ret < 0 && errno == EINTR);

    return ret;
}

//SW2-5-1-BH-DbgCfgTool-00+[
void android_dbgcfg_init(void)
{
    int dbgcfgtool_fd = -1;
    dbgcfg_ioctl_arg arg;
    
    arg.id.bit_id = DEBUG_ANDROID_UARTMSG_CFG;

    dbgcfgtool_fd = open(dbgcfgtool_name, O_RDWR);
    
    if (dbgcfgtool_fd < 0) {
        fprintf(stderr,"logd_write: cannot open device (%s)\n",strerror(errno));
        return;
    }

    if (ioctl(dbgcfgtool_fd, DBG_IOCTL_CMD_GET_DBGCFG_BIT, &arg) < 0)
    {
        fprintf(stderr,"logd_write: DBG_IOCTL_CMD_GET_DBGCFG ioctl fails (%s)\n",
                strerror(errno));
        close(dbgcfgtool_fd);
        return;
    }

    close(dbgcfgtool_fd);

    if (arg.value == 1)  //DEBUG_ANDROID_UARTMSG_CFG is ON
    {
        debug_android_uartmsg_enable = 1;

        console_fd = open("/dev/console", O_WRONLY);

        if (console_fd < 0 )
        {
            fprintf(stderr, "logd_write: Unable to open /dev/console (%s)\n",strerror(errno));
            return;
        }
    }

}
//SW2-5-1-BH-DbgCfgTool-00+]

static int __write_to_log_init(log_id_t log_id, struct iovec *vec, size_t nr)
{
#ifdef HAVE_PTHREADS
    pthread_mutex_lock(&log_init_lock);
#endif

    if (write_to_log == __write_to_log_init) {
        log_fds[LOG_ID_MAIN] = log_open("/dev/"LOGGER_LOG_MAIN, O_WRONLY);
        log_fds[LOG_ID_RADIO] = log_open("/dev/"LOGGER_LOG_RADIO, O_WRONLY);
        log_fds[LOG_ID_EVENTS] = log_open("/dev/"LOGGER_LOG_EVENTS, O_WRONLY);
        log_fds[LOG_ID_SYSTEM] = log_open("/dev/"LOGGER_LOG_SYSTEM, O_WRONLY);

        write_to_log = __write_to_log_kernel;

        if (log_fds[LOG_ID_MAIN] < 0 || log_fds[LOG_ID_RADIO] < 0 ||
                log_fds[LOG_ID_EVENTS] < 0) {
            log_close(log_fds[LOG_ID_MAIN]);
            log_close(log_fds[LOG_ID_RADIO]);
            log_close(log_fds[LOG_ID_EVENTS]);
            log_fds[LOG_ID_MAIN] = -1;
            log_fds[LOG_ID_RADIO] = -1;
            log_fds[LOG_ID_EVENTS] = -1;
            write_to_log = __write_to_log_null;
        }

        if (log_fds[LOG_ID_SYSTEM] < 0) {
            log_fds[LOG_ID_SYSTEM] = log_fds[LOG_ID_MAIN];
        }
    }

#ifdef HAVE_PTHREADS
    pthread_mutex_unlock(&log_init_lock);
#endif

    android_dbgcfg_init();  //SW2-5-1-BH-DbgCfgTool-00+

    return write_to_log(log_id, vec, nr);
}

int __android_log_write(int prio, const char *tag, const char *msg)
{
    struct iovec vec[3];
    log_id_t log_id = LOG_ID_MAIN;

    if (!tag)
        tag = "";

    /* XXX: This needs to go! */
    if (!strcmp(tag, "HTC_RIL") ||
        !strncmp(tag, "RIL", 3) || /* Any log tag with "RIL" as the prefix */
        !strcmp(tag, "AT") ||
        !strcmp(tag, "GSM") ||
        !strcmp(tag, "STK") ||
        !strcmp(tag, "CDMA") ||
        !strcmp(tag, "PHONE") ||
        !strcmp(tag, "SMS") ||
        //SW2-5-1-BH-DbgCfgTool-00+[
        /* {{[FB0G.B-1091][Log] Print the log to ADB, PhilipWYHuang, 20111111 */
        !strcmp(tag, "QC-NETMGR-LIB") ||
        !strcmp(tag, "QC-DS-LIB") ||
        /* }}[FB0G.B-1091] PhilipWYHuang, 20111111 */
        !strcmp(tag, "QC-DSS-LIB") ||
        !strcmp(tag, "QC-QMI") ||
        !strcmp(tag, "Dun Auto Boot") ||
        !strcmp(tag, "PORT_BRIDGE") ||
        !strcmp(tag, "CallNotifier") ||
        !strcmp(tag, "GpsLocationProvider") ||
        !strcmp(tag, "QCRIL") ||
        !strcmp(tag, "Phone")
        //SW2-5-1-BH-DbgCfgTool-00+]
        )
            log_id = LOG_ID_RADIO;

    vec[0].iov_base   = (unsigned char *) &prio;
    vec[0].iov_len    = 1;
    vec[1].iov_base   = (void *) tag;
    vec[1].iov_len    = strlen(tag) + 1;
    vec[2].iov_base   = (void *) msg;
    vec[2].iov_len    = strlen(msg) + 1;

    return write_to_log(log_id, vec, 3);
}

int __android_log_buf_write(int bufID, int prio, const char *tag, const char *msg)
{
    struct iovec vec[3];

    if (!tag)
        tag = "";

    /* XXX: This needs to go! */
    if (!strcmp(tag, "HTC_RIL") ||
        !strncmp(tag, "RIL", 3) || /* Any log tag with "RIL" as the prefix */
        !strcmp(tag, "AT") ||
        !strcmp(tag, "GSM") ||
        !strcmp(tag, "STK") ||
        !strcmp(tag, "CDMA") ||
        !strcmp(tag, "PHONE") ||
        !strcmp(tag, "SMS") ||
        //SW2-5-1-BH-DbgCfgTool-00+[
        /* {{[FB0G.B-1091][Log] Print the log to ADB, PhilipWYHuang, 20111111 */
        !strcmp(tag, "QC-NETMGR-LIB") ||
        !strcmp(tag, "QC-DS-LIB") ||
        /* }}[FB0G.B-1091] PhilipWYHuang, 20111111 */
        !strcmp(tag, "QC-DSS-LIB") ||
        !strcmp(tag, "QC-QMI") ||
        !strcmp(tag, "Dun Auto Boot") ||
        !strcmp(tag, "PORT_BRIDGE") ||
        !strcmp(tag, "CallNotifier") ||
        !strcmp(tag, "GpsLocationProvider") ||
        !strcmp(tag, "QCRIL") ||
        !strcmp(tag, "Phone")
        //SW2-5-1-BH-DbgCfgTool-00+]
        )
            bufID = LOG_ID_RADIO;

    vec[0].iov_base   = (unsigned char *) &prio;
    vec[0].iov_len    = 1;
    vec[1].iov_base   = (void *) tag;
    vec[1].iov_len    = strlen(tag) + 1;
    vec[2].iov_base   = (void *) msg;
    vec[2].iov_len    = strlen(msg) + 1;

    return write_to_log(bufID, vec, 3);
}

int __android_log_vprint(int prio, const char *tag, const char *fmt, va_list ap)
{
    char buf[LOG_BUF_SIZE];    

    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);

    return __android_log_write(prio, tag, buf);
}

int __android_log_print(int prio, const char *tag, const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);

    return __android_log_write(prio, tag, buf);
}

int __android_log_buf_print(int bufID, int prio, const char *tag, const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);

    return __android_log_buf_write(bufID, prio, tag, buf);
}

void __android_log_assert(const char *cond, const char *tag,
			  const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];    

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);

    __android_log_write(ANDROID_LOG_FATAL, tag, buf);

    __builtin_trap(); /* trap so we have a chance to debug the situation */
}

int __android_log_bwrite(int32_t tag, const void *payload, size_t len)
{
    struct iovec vec[2];

    vec[0].iov_base = &tag;
    vec[0].iov_len = sizeof(tag);
    vec[1].iov_base = (void*)payload;
    vec[1].iov_len = len;

    return write_to_log(LOG_ID_EVENTS, vec, 2);
}

/*
 * Like __android_log_bwrite, but takes the type as well.  Doesn't work
 * for the general case where we're generating lists of stuff, but very
 * handy if we just want to dump an integer into the log.
 */
int __android_log_btwrite(int32_t tag, char type, const void *payload,
    size_t len)
{
    struct iovec vec[3];

    vec[0].iov_base = &tag;
    vec[0].iov_len = sizeof(tag);
    vec[1].iov_base = &type;
    vec[1].iov_len = sizeof(type);
    vec[2].iov_base = (void*)payload;
    vec[2].iov_len = len;

    return write_to_log(LOG_ID_EVENTS, vec, 3);
}
