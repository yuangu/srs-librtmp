#pragma once

#ifdef _WIN32
// include windows first.
#include <windows.h>
// the type used by this header for windows.
typedef unsigned long long u_int64_t;
typedef long long int64_t;
typedef unsigned int u_int32_t;
typedef u_int32_t uint32_t;
typedef int int32_t;
typedef unsigned char u_int8_t;
// typedef char int8_t;
typedef unsigned short u_int16_t;
typedef short int16_t;
typedef int64_t ssize_t;
struct iovec {
	void  *iov_base;    /* Starting address */
	size_t iov_len;     /* Number of bytes to transfer */
};
#endif


/*************************************************************
**************************************************************
* Windows SRS-LIBRTMP solution
**************************************************************
*************************************************************/
// for srs-librtmp, @see https://github.com/ossrs/srs/issues/213
#ifdef _WIN32
// for time.
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#include <time.h>
int gettimeofday(struct timeval* tv, struct timezone* tz);
#define PRId64 "lld"

// for inet helpers.
typedef int socklen_t;
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);

// for mkdir().
#include<direct.h>

// for open().
typedef int mode_t;
#define S_IRUSR 0
#define S_IWUSR 0
#define S_IXUSR 0
#define S_IRGRP 0
#define S_IWGRP 0
#define S_IXGRP 0
#define S_IROTH 0
#define S_IXOTH 0

// for file seek.
#include <io.h>
#include <fcntl.h>
#define open _open
#define close _close
#define lseek _lseek
#define write _write
#define read _read

// for pid.
typedef int pid_t;
pid_t getpid(void);

// for socket.
ssize_t writev(int fd, const struct iovec *iov, int iovcnt);
typedef int64_t useconds_t;
int usleep(useconds_t usec);
int socket_setup();
int socket_cleanup();

// others.
//  #define snprintf _snprintf
#endif