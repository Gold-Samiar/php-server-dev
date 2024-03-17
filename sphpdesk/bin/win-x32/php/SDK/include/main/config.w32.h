/*
	Build Configuration Template for Win32.
*/

/* Define the minimum supported version */
#undef _WIN32_WINNT
#undef NTDDI_VERSION
#define _WIN32_WINNT 0x0601
#define NTDDI_VERSION 0x06010000

/* Default PHP / PEAR directories */
#define PHP_CONFIG_FILE_PATH ""
#define CONFIGURATION_FILE_PATH "php.ini"
#define PEAR_INSTALLDIR "C:\\php\\pear"
#define PHP_BINDIR "C:\\php"
#define PHP_DATADIR "C:\\php"
#define PHP_EXTENSION_DIR "C:\\php\\ext"
#define PHP_INCLUDE_PATH	".;C:\\php\\pear"
#define PHP_LIBDIR "C:\\php"
#define PHP_LOCALSTATEDIR "C:\\php"
#define PHP_PREFIX "C:\\php"
#define PHP_SYSCONFDIR "C:\\php"

/* PHP Runtime Configuration */
#define PHP_URL_FOPEN 1
#define USE_CONFIG_FILE 1
#define DEFAULT_SHORT_OPEN_TAG "1"

/* Platform-Specific Configuration. Should not be changed. */
/* Alignment for Zend memory allocator */
#define ZEND_MM_ALIGNMENT (size_t)8
#define ZEND_MM_ALIGNMENT_LOG2 (size_t)3
#define ZEND_MM_NEED_EIGHT_BYTE_REALIGNMENT 0
#define PHP_SIGCHILD 0
#define HAVE_GETSERVBYNAME 1
#define HAVE_GETSERVBYPORT 1
#define HAVE_GETPROTOBYNAME 1
#define HAVE_GETPROTOBYNUMBER 1
#define HAVE_GETHOSTNAME 1
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#define HAVE_ERRMSG_H 0
#undef HAVE_ADABAS
#undef HAVE_SOLID
#undef HAVE_SYMLINK

/* its in win32/time.c */
#define HAVE_USLEEP 1
#define HAVE_NANOSLEEP 1

#define HAVE_GETCWD 1
#define NEED_ISBLANK 1
#define DISCARD_PATH 0
#undef HAVE_SETITIMER
#undef HAVE_SIGSETJMP
#undef HAVE_IODBC
#define HAVE_LIBDL 1
#define HAVE_GETTIMEOFDAY 1
#define HAVE_PUTENV 1
#define HAVE_TZSET 1
#undef HAVE_FLOCK
#define HAVE_ALLOCA 1
#undef HAVE_SYS_TIME_H
#undef HAVE_STRUCT_STAT_ST_BLKSIZE
#undef HAVE_STRUCT_STAT_ST_BLOCKS
#define HAVE_STRUCT_STAT_ST_RDEV 1
#define REGEX 1
#define HSREGEX 1
#define HAVE_GETLOGIN 1
#define HAVE_MEMMOVE 1
#define HAVE_REGCOMP 1
#define HAVE_SHUTDOWN 1
#define HAVE_STRCASECMP 1
#define HAVE_UTIME 1
#undef HAVE_DIRENT_H
#define HAVE_FCNTL_H 1
#define HAVE_GRP_H 0
#undef HAVE_PWD_H
#undef HAVE_SYS_FILE_H
#undef HAVE_SYS_SOCKET_H
#undef HAVE_SYS_WAIT_H
#define HAVE_SYSLOG_H 1
#undef HAVE_UNISTD_H
#define HAVE_SYS_TYPES_H 1
#undef HAVE_ALLOCA_H
#undef HAVE_KILL
#define HAVE_GETPID 1
#define HAVE_LIBM 1
#undef HAVE_RINT
#define SIZEOF_SHORT 2
/* int and long are still 32bit in 64bit compiles */
#define SIZEOF_INT 4
#define SIZEOF_LONG 4
/* MSVC.6/NET don't allow 'long long' or know 'intmax_t' */
#define SIZEOF_LONG_LONG 8 /* defined as __int64 */
#define SIZEOF_INTMAX_T 0
#define ssize_t SSIZE_T
#ifdef _WIN64
# define SIZEOF_SIZE_T 8
# define SIZEOF_PTRDIFF_T 8
#else
# define SIZEOF_SIZE_T 4
# define SIZEOF_PTRDIFF_T 4
#endif
#define SIZEOF_OFF_T 4
#define HAVE_FNMATCH
#define HAVE_GLOB
#define PHP_SHLIB_SUFFIX "dll"
#define PHP_SHLIB_EXT_PREFIX "php_"
#define HAVE_SQLDATASOURCES

/* Win32 supports socketpair by the emulation in win32/sockets.c */
#define HAVE_SOCKETPAIR 1
#define HAVE_SOCKLEN_T 1

/* Win32 support proc_open */
#define PHP_CAN_SUPPORT_PROC_OPEN 1

/* inet_ntop() / inet_pton() */
#define HAVE_INET_PTON 1
#define HAVE_INET_NTOP 1

/* vs.net 2005 has a 64-bit time_t.  This will likely break
 * 3rdParty libs that were built with older compilers; switch
 * back to 32-bit */
#ifndef _WIN64
# define _USE_32BIT_TIME_T 1
#endif

#define _REENTRANT 1

#define HAVE_GETRUSAGE

#define HAVE_FTOK 1

#define HAVE_NICE

#ifdef __clang__
#define HAVE_FUNC_ATTRIBUTE_TARGET 1
#endif

#define HAVE_GETADDRINFO 1

/* values determined by configure.js */

/* Windows build system version */
#define PHP_BUILD_SYSTEM "Microsoft Windows 11 Home [10.0.22621]"

/* Configure line */
#define CONFIGURE_COMMAND "cscript /nologo /e:jscript configure.js  \"--enable-sphpenc\" \"--with-extra-libs=D:\\mylib\\php\\php-8.2.16-src\\deps\\zlib-1.3.1\\build\\Release\"" " \"--with-extra-includes=D:\\mylib\\php\\php-8.2.16-src\\deps\\zlib-1.3.1\"" " \"--enable-cli\" \"--enable-zlib\" \"--enable-ftp\" \"--enable-sockets\"" " \"--enable-opcache\""

/* Detected compiler version */
#define PHP_BUILD_COMPILER "Visual C++ 2019"

/* Compiler compatibility ID */
#define PHP_COMPILER_ID "VS16"

/* Detected compiler architecture */
#define PHP_BUILD_ARCH "x86"

/* Linker major version */
#define PHP_LINKER_MAJOR 14

/* Linker minor version */
#define PHP_LINKER_MINOR 29

#define HAVE_STRNLEN 1

/* have the wspiapi.h header file */
#define HAVE_WSPIAPI_H 1

#define HAVE_GAI_STRERROR 1

#define HAVE_IPV6 1

#define __SSE__ 1

#define __SSE2__ 1

/* Have BCMATH library */
#define HAVE_BCMATH 1

/* Have calendar */
#define HAVE_CALENDAR 1

/* Have COM_DOTNET support */
#define HAVE_COM_DOTNET 1

/* Have ctype */
#define HAVE_CTYPE 1

/* Have timelib_config.h */
#define HAVE_TIMELIB_CONFIG_H 1

/* Have FTP support */
#define HAVE_FTP 1

/* have the zlib.h header file */
#define HAVE_ZLIB_H 1

/* Compression support */
#define MYSQLND_COMPRESSION_ENABLED 1

/* SSL support */
#define MYSQLND_SSL_SUPPORTED 1

/* Extended SSL support */
#define MYSQLND_HAVE_SSL 1

/* Define to enable JIT */
#define HAVE_JIT 1

/* Using bundled PCRE library */
#define HAVE_BUNDLED_PCRE 1

/* Have PCRE library */
#define PCRE2_CODE_UNIT_WIDTH 8

/*  */
#define PCRE2_STATIC 1

/* PCRE library */
#define HAVE_PCRE_JIT_SUPPORT 1

/* Session support */
#define HAVE_PHP_SESSION 1

#define HAVE_SOCKETS 1

/* sphpenc support enabled */
#define HAVE_SPHPENC 1

#define PHP_CONFIG_FILE_SCAN_DIR ""

#define PHP_USE_PHP_CRYPT_R 1

/* Tokenizer support */
#define HAVE_TOKENIZER 1

/* ZLIB support */
#define HAVE_ZLIB 1

#if __has_include("main/config.pickle.h")
#include "main/config.pickle.h"
#endif
