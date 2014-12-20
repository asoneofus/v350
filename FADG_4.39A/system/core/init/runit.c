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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <cutils/sockets.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DEBUG_SERVICE

#define REPLY_MAX     1024   /* largest reply allowed */
#define BUFFER_MAX    1024+64  /* input buffer for commands */
#define TOKEN_MAX     8     /* max number of arguments in buffer */

static int runit_fd = -1;

#if 0
struct cmdinfo {
    const char *name;
    unsigned numargs;
    int (*func)(char **arg, char reply[REPLY_MAX]);
};


static int do_chmod(char **arg, char reply[REPLY_MAX])
{
	int index = 0;
	mode_t mode_value = 0;
	int mode = strtol(arg[0], NULL, 16);
	
	while (index <= 12)
	{
		switch (mode & (1<<index))
		{
			case 0x400:
			mode_value |= S_IRUSR;
			break;
			case 0x200:
			mode_value |= S_IWUSR;
			break;
			case 0x100:
			mode_value |= S_IXUSR;
			break;
			case 0x40:
			mode_value |= S_IRGRP;
			break;
			case 0x20:
			mode_value |= S_IWGRP;
			break;
			case 0x10:
			mode_value |= S_IXGRP;
			break;
			case 0x4:
			mode_value |= S_IROTH;
			break;
			case 0x2:
			mode_value |= S_IWOTH;
			break;
			case 0x1:
			mode_value |= S_IXOTH;
			break;
		}
		index++;
	}
	
	return chmod(arg[1], mode_value);
}
struct cmdinfo cmds[] = {
    { "chmod",               2, do_chmod },

};
#endif

static int writex(int s, const void *_buf, int count)
{
    const char *buf = _buf;
    int n = 0, r;
    if (count < 0) return -1;
    while (n < count) {
        r = write(s, buf + n, count - n);
        if (r < 0) {
            if (errno == EINTR) continue;
            fprintf(stderr, "write error: %s\n", strerror(errno));
            return -1;
        }
        n += r;
    }
    return 0;
}
static int readx(int s, void *_buf, int count)
{
    char *buf = _buf;
    int n = 0, r;
    if (count < 0) return -1;
    while (n < count) {
        r = read(s, buf + n, count - n);

        if (r < 0) {
            if (errno == EINTR) continue;
            fprintf(stderr, "read error: %s\n", strerror(errno));
            return -1;
        }
        if (r == 0) {
       	fprintf(stderr, "eof\n");
            return -1; /* EOF */
        }
        n += r;
    }
    return 0;
}
static int do_command(int s, char * pcmd)
{
	FILE *fp;
	int status;
	
	int n ,count = 0;
	char path[REPLY_MAX];
	char cmd[BUFFER_MAX];

	fp = popen(pcmd, "r");
	if (fp == NULL)
	return 0;

	int c;
	int index = 0;

	while ((c = fgetc(fp))!= -1)
	{
	
		if (index == (REPLY_MAX - 1))
			break;
		path[index] = c;
		index++;
	}
	
	path[index] = 0;
	
	status = pclose(fp);
	if (status == -1)
	   fprintf(stderr, "path: %s\n", path);
	else 
		fprintf(stderr, "WEXITSTATUS(status): %d\n", WEXITSTATUS(status));
	
	
    if (path[0]) {
        n = snprintf(cmd, BUFFER_MAX, "%d %s", WEXITSTATUS(status), path);
    } else {
        n = snprintf(cmd, BUFFER_MAX, "%d", WEXITSTATUS(status));
    }
    if (n > BUFFER_MAX) n = BUFFER_MAX;
    count = n;
	fprintf(stderr, "reply: '%s'\n", cmd);

    if (writex(s, &count, sizeof(count)))
    	 return 0;

    if (writex(s, cmd, count))
   	 return 0;
	
	return 1;
}
#if 0
static int execute(int s, char cmd[BUFFER_MAX])
{
    char reply[REPLY_MAX];
    char *arg[TOKEN_MAX+1];
    unsigned i;
    unsigned n = 0;
    unsigned short count;
    int ret = -1;

        /* default reply is "" */
    reply[0] = 0;

        /* n is number of args (not counting arg[0]) */
    arg[0] = cmd;
    while (*cmd) {
        if (isspace(*cmd)) {
            *cmd++ = 0;
            n++;
            arg[n] = cmd;
            if (n == TOKEN_MAX) {
            	fprintf(stderr, "too many arguments\n");
                goto done;
            }
        }
        cmd++;
    }

    for (i = 0; i < sizeof(cmds) / sizeof(cmds[0]); i++) {
        if (!strcmp(cmds[i].name,arg[0])) {
            if (n != cmds[i].numargs) {
            	fprintf(stderr, "%s requires %d arguments (%d given)\n", cmds[i].name, cmds[i].numargs, n);
            } else {
                ret = cmds[i].func(arg + 1, reply);
            }
            goto done;
        }
    }
    fprintf(stderr, "unsupported command '%s'\n", arg[0]);
done:
    if (reply[0]) {
        n = snprintf(cmd, BUFFER_MAX, "%d %s", ret, reply);
    } else {
        n = snprintf(cmd, BUFFER_MAX, "%d", ret);
    }
    if (n > BUFFER_MAX) n = BUFFER_MAX;
    count = n;
	fprintf(stderr, "reply: '%s'\n", cmd);

    if (writex(s, &count, sizeof(count)))
    	 return -1;

    if (writex(s, cmd, count))
   	 return -1;

    return 0;
}
#endif

void handle_runit_fd()
{
    int s;
    int r;
    int res;
    struct ucred cr;
    struct sockaddr_un addr;
    socklen_t addr_size = sizeof(addr);
    socklen_t cr_size = sizeof(cr);
    
    
    if ((s = accept(runit_fd, (struct sockaddr *) &addr, &addr_size)) < 0) {
        return;
    }
    /* Check socket options here */
    if (getsockopt(s, SOL_SOCKET, SO_PEERCRED, &cr, &cr_size) < 0) {
        close(s);
        return;
    }
    
    unsigned short count;

    if (readx(s, &count, sizeof(count)))
	return;

    char buf[BUFFER_MAX];	
    if (readx(s, buf, count))
	return;

    buf[count] = 0;
    fprintf(stderr, "buf :%s \n", buf);
    do_command(s, buf);

    close(s);
}

void start_runit_service(void)
{
//#ifdef DEBUG_SERVICE
//    freopen("/dev/kmsg", "w", stdout); setbuf(stdout, NULL);
//    freopen("/dev/kmsg", "w", stderr); setbuf(stderr, NULL);

//#endif
	int fd;
	fd = create_socket("init_runit", SOCK_STREAM, 0666, 0, 0);
    	if(fd < 0) return -1;
    	fcntl(fd, F_SETFD, FD_CLOEXEC);
    	fcntl(fd, F_SETFL, O_NONBLOCK);

    	listen(fd, 8);
	
	runit_fd = fd;
}
int get_runit_fd()
{
    return runit_fd;
}
