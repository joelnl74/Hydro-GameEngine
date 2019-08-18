/*
 * Summary: the XML document serializer
 * Description: API to save document or subtree of document
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_XMLSAVE_H
#define FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_XMLSAVE_H

#include <components/libxml2-2.7.8/include/libxml/xmlversion.h>
#include <components/libxml2-2.7.8/include/libxml/tree.h>
#include <components/libxml2-2.7.8/include/libxml/encoding.h>
#include <components/libxml2-2.7.8/include/libxml/xmlIO.h>

#ifdef LIBXML_OUTPUT_ENABLED

#include <fbxsdk/fbxsdk_nsbegin.h>

/**
 * xmlSaveOption:
 *
 * This is the set of XML save options that can be passed down
 * to the xmlSaveToFd() and similar calls.
 */
typedef enum {
    XML_SAVE_FORMAT     = 1<<0,	/* format save output */
    XML_SAVE_NO_DECL    = 1<<1,	/* drop the xml declaration */
    XML_SAVE_NO_EMPTY	= 1<<2, /* no empty tags */
    XML_SAVE_NO_XHTML	= 1<<3, /* disable XHTML1 specific rules */
    XML_SAVE_XHTML	= 1<<4, /* force XHTML1 specific rules */
    XML_SAVE_AS_XML     = 1<<5, /* force XML serialization on HTML doc */
    XML_SAVE_AS_HTML    = 1<<6, /* force HTML serialization on XML doc */
    XML_SAVE_WSNONSIG   = 1<<7  /* format with non-significant whitespace */
} xmlSaveOption;


typedef struct _xmlSaveCtxt xmlSaveCtxt;
typedef xmlSaveCtxt *xmlSaveCtxtPtr;

XMLPUBFUN xmlSaveCtxtPtr XMLCALL
		xmlSaveToFd		(int fd,
					 const char *encoding,
					 int options);
XMLPUBFUN xmlSaveCtxtPtr XMLCALL
		xmlSaveToFilename	(const char *filename,
					 const char *encoding,
					 int options);

XMLPUBFUN xmlSaveCtxtPtr XMLCALL
		xmlSaveToBuffer		(xmlBufferPtr buffer,
					 const char *encoding,
					 int options);

XMLPUBFUN xmlSaveCtxtPtr XMLCALL
		xmlSaveToIO		(xmlOutputWriteCallback iowrite,
					 xmlOutputCloseCallback ioclose,
					 void *ioctx,
					 const char *encoding,
					 int options);

XMLPUBFUN long XMLCALL
		xmlSaveDoc		(xmlSaveCtxtPtr ctxt,
					 xmlDocPtr doc);
XMLPUBFUN long XMLCALL
		xmlSaveTree		(xmlSaveCtxtPtr ctxt,
					 xmlNodePtr node);

XMLPUBFUN int XMLCALL
		xmlSaveFlush		(xmlSaveCtxtPtr ctxt);
XMLPUBFUN int XMLCALL
		xmlSaveClose		(xmlSaveCtxtPtr ctxt);
XMLPUBFUN int XMLCALL
		xmlSaveSetEscape	(xmlSaveCtxtPtr ctxt,
					 xmlCharEncodingOutputFunc escape);
XMLPUBFUN int XMLCALL
		xmlSaveSetAttrEscape	(xmlSaveCtxtPtr ctxt,

					 xmlCharEncodingOutputFunc escape);

#include <fbxsdk/fbxsdk_nsend.h>
#endif /* LIBXML_OUTPUT_ENABLED */

#endif // FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_XMLSAVE_H

