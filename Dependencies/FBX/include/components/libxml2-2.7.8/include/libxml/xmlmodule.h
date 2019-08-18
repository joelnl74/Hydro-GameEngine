/*
 * Summary: dynamic module loading
 * Description: basic API for dynamic module loading, used by
 *              libexslt added in 2.6.17
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Joel W. Reed
 */

#ifndef FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_XMLMODULE_H
#define FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_XMLMODULE_H

//#include <libxml/xmlversion.h>

#ifdef LIBXML_MODULES_ENABLED
#include <fbxsdk/fbxsdk_nsbegin.h>

/**
 * xmlModulePtr:
 *
 * A handle to a dynamically loaded module
 */
typedef struct _xmlModule xmlModule;
typedef xmlModule *xmlModulePtr;

/**
 * xmlModuleOption:
 *
 * enumeration of options that can be passed down to xmlModuleOpen()
 */
typedef enum {
    XML_MODULE_LAZY = 1,	/* lazy binding */
    XML_MODULE_LOCAL= 2		/* local binding */
} xmlModuleOption;

XMLPUBFUN xmlModulePtr XMLCALL xmlModuleOpen	(const char *filename,
						 int options);

XMLPUBFUN int XMLCALL xmlModuleSymbol		(xmlModulePtr module,
						 const char* name,
						 void **result);

XMLPUBFUN int XMLCALL xmlModuleClose		(xmlModulePtr module);

XMLPUBFUN int XMLCALL xmlModuleFree		(xmlModulePtr module);

#include <fbxsdk/fbxsdk_nsend.h>
#endif /* LIBXML_MODULES_ENABLED */

#endif // #ifndef FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_XMLMODULE_H
