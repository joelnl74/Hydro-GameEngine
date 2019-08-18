/*
 * wincecompat.h : wince compatiblity header file 
 *
 * See Copyright for the status of this software.
 *
 * javier@tiresiassoft.com
 *
 * 17 Sep 2002  created
 */

#ifndef FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_WIN32_WINCE_WINCECOMPAT_H
#define FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_WIN32_WINCE_WINCECOMPAT_H

#include <stdio.h>
#include <winbase.h>
#include <fbxfilesdk/fbxfilesdk_nsbegin.h>
#define MAX_STRERROR 31

#define O_RDONLY       0x0000  /* open for reading only */
#define O_WRONLY       0x0001  /* open for writing only */
#define O_RDWR         0x0002  /* open for reading and writing */
#define O_APPEND       0x0008  /* writes done at eof */

#define O_CREAT        0x0100  /* create and open file */
#define O_TRUNC        0x0200  /* open and truncate */
#define O_EXCL         0x0400  /* open only if file doesn't already exist */

#define BUFSIZ 4096

extern int errno;
/* 
	Prototypes 
*/
int read(int handle, char *buffer, unsigned int len);
int write(int handle, const char *buffer, unsigned int len);
int open(const char *filename,int oflag, ...);
int close(int handle);
char *getenv( const char *varname );
char *getcwd( char *buffer, unsigned int size);
char *strerror(int errnum);

/*
	Macro'ed inexistant funtion names

*/
#define snprintf _snprintf
#define vsnprintf(b,c,f,a) _vsnprintf(b,c,f,a)
#define perror(_t) MessageBox(NULL, _T("_t"), _T("Error/Warning"), MB_OK)

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_WIN32_WINCE_WINCECOMPAT_H

