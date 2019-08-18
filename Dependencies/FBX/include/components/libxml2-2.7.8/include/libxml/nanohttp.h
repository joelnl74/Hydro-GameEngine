/*
 * Summary: minimal HTTP implementation
 * Description: minimal HTTP implementation allowing to fetch resources
 *              like external subset.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */
 
#ifndef FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_NANOHTTP_H
#define FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_NANOHTTP_H

#include <components/libxml2-2.7.8/include/libxml/xmlversion.h>

#include <fbxsdk/fbxsdk_nsbegin.h>

#ifdef LIBXML_HTTP_ENABLED

XMLPUBFUN void XMLCALL
	xmlNanoHTTPInit		(void);
XMLPUBFUN void XMLCALL	
	xmlNanoHTTPCleanup	(void);
XMLPUBFUN void XMLCALL	
	xmlNanoHTTPScanProxy	(const char *URL);
XMLPUBFUN int XMLCALL	
	xmlNanoHTTPFetch	(const char *URL,
				 const char *filename,
				 char **contentType);
XMLPUBFUN void * XMLCALL	
	xmlNanoHTTPMethod	(const char *URL,
				 const char *method,
				 const char *input,
				 char **contentType,
				 const char *headers,
				 int   ilen);
XMLPUBFUN void * XMLCALL	
	xmlNanoHTTPMethodRedir	(const char *URL,
				 const char *method,
				 const char *input,
				 char **contentType,
				 char **redir,
				 const char *headers,
				 int   ilen);
XMLPUBFUN void * XMLCALL	
	xmlNanoHTTPOpen		(const char *URL,
				 char **contentType);
XMLPUBFUN void * XMLCALL	
	xmlNanoHTTPOpenRedir	(const char *URL,
				 char **contentType,
				 char **redir);
XMLPUBFUN int XMLCALL	
	xmlNanoHTTPReturnCode	(void *ctx);
XMLPUBFUN const char * XMLCALL 
	xmlNanoHTTPAuthHeader	(void *ctx);
XMLPUBFUN const char * XMLCALL
	xmlNanoHTTPRedir	(void *ctx);
XMLPUBFUN int XMLCALL
	xmlNanoHTTPContentLength( void * ctx );
XMLPUBFUN const char * XMLCALL
	xmlNanoHTTPEncoding	(void *ctx);
XMLPUBFUN const char * XMLCALL
	xmlNanoHTTPMimeType	(void *ctx);
XMLPUBFUN int XMLCALL	
	xmlNanoHTTPRead		(void *ctx,
				 void *dest,
				 int len);
#ifdef LIBXML_OUTPUT_ENABLED
XMLPUBFUN int XMLCALL	
	xmlNanoHTTPSave		(void *ctxt,
				 const char *filename);
#endif /* LIBXML_OUTPUT_ENABLED */
XMLPUBFUN void XMLCALL	
	xmlNanoHTTPClose	(void *ctx);


#endif /* LIBXML_HTTP_ENABLED */
#include <fbxsdk/fbxsdk_nsend.h>

#endif // FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_NANOHTTP_H
