/*
 * Summary: old DocBook SGML parser
 * Description: interface for a DocBook SGML non-verifying parser
 * This code is DEPRECATED, and should not be used anymore.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_DOCBPARSER_H
#define FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_DOCBPARSER_H


#ifdef LIBXML_DOCB_ENABLED

#include <components/libxml2-2.7.8/include/libxml/xmlversion.h>
#include <components/libxml2-2.7.8/include/libxml/parser.h>
#include <components/libxml2-2.7.8/include/libxml/parserInternals.h>

#ifndef FBXSDK_SHARED
#ifdef __GNUC__
#warning "The DOCBparser module has been deprecated in libxml2-2.6.0"
#endif
#endif

#include <fbxsdk/fbxsdk_nsbegin.h>

/*
 * Most of the back-end structures from XML and SGML are shared.
 */
typedef xmlParserCtxt docbParserCtxt;
typedef xmlParserCtxtPtr docbParserCtxtPtr;
typedef xmlSAXHandler docbSAXHandler;
typedef xmlSAXHandlerPtr docbSAXHandlerPtr;
typedef xmlParserInput docbParserInput;
typedef xmlParserInputPtr docbParserInputPtr;
typedef xmlDocPtr docbDocPtr;

/*
 * There is only few public functions.
 */
XMLPUBFUN int XMLCALL
		     docbEncodeEntities(unsigned char *out,
                                        int *outlen,
                                        const unsigned char *in,
                                        int *inlen, int quoteChar);

XMLPUBFUN docbDocPtr XMLCALL             
		     docbSAXParseDoc   (xmlChar *cur,
                                        const char *encoding,
                                        docbSAXHandlerPtr sax,
                                        void *userData);
XMLPUBFUN docbDocPtr XMLCALL             
		     docbParseDoc      (xmlChar *cur,
                                        const char *encoding);
XMLPUBFUN docbDocPtr XMLCALL             
		     docbSAXParseFile  (const char *filename,
                                        const char *encoding,
                                        docbSAXHandlerPtr sax,
                                        void *userData);
XMLPUBFUN docbDocPtr XMLCALL             
		     docbParseFile     (const char *filename,
                                        const char *encoding);

/**
 * Interfaces for the Push mode.
 */
XMLPUBFUN void XMLCALL                  
		     docbFreeParserCtxt      (docbParserCtxtPtr ctxt);
XMLPUBFUN docbParserCtxtPtr XMLCALL     
		     docbCreatePushParserCtxt(docbSAXHandlerPtr sax,
                                              void *user_data,
                                              const char *chunk,
                                              int size,
                                              const char *filename,
                                              xmlCharEncoding enc);
XMLPUBFUN int XMLCALL                   
		     docbParseChunk          (docbParserCtxtPtr ctxt,
                                              const char *chunk,
                                              int size,
                                              int terminate);
XMLPUBFUN docbParserCtxtPtr XMLCALL       
		     docbCreateFileParserCtxt(const char *filename,
                                              const char *encoding);
XMLPUBFUN int XMLCALL                   
		     docbParseDocument       (docbParserCtxtPtr ctxt);

#include <fbxsdk/fbxsdk_nsend.h>

#endif /* LIBXML_DOCB_ENABLED */

#endif // FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_DOCBPARSER_H

