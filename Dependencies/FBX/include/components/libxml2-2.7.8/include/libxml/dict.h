/*
 * Summary: string dictionnary
 * Description: dictionary of reusable strings, just used to avoid allocation
 *         and freeing operations.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_DICT_H
#define FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_DICT_H

#include <components/libxml2-2.7.8/include/libxml/xmlversion.h>
#include <components/libxml2-2.7.8/include/libxml/tree.h>

#include <fbxsdk/fbxsdk_nsbegin.h>

/*
 * The dictionnary.
 */
typedef struct _xmlDict xmlDict;
typedef xmlDict *xmlDictPtr;

/*
 * Constructor and destructor.
 */
XMLPUBFUN xmlDictPtr XMLCALL
			xmlDictCreate	(void);
XMLPUBFUN xmlDictPtr XMLCALL
			xmlDictCreateSub(xmlDictPtr sub);
XMLPUBFUN int XMLCALL
			xmlDictReference(xmlDictPtr dict);
XMLPUBFUN void XMLCALL			
			xmlDictFree	(xmlDictPtr dict);

/*
 * Lookup of entry in the dictionnary.
 */
XMLPUBFUN const xmlChar * XMLCALL		
			xmlDictLookup	(xmlDictPtr dict,
		                         const xmlChar *name,
		                         int len);
XMLPUBFUN const xmlChar * XMLCALL		
			xmlDictExists	(xmlDictPtr dict,
		                         const xmlChar *name,
		                         int len);
XMLPUBFUN const xmlChar * XMLCALL		
			xmlDictQLookup	(xmlDictPtr dict,
		                         const xmlChar *prefix,
		                         const xmlChar *name);
XMLPUBFUN int XMLCALL
			xmlDictOwns	(xmlDictPtr dict,
					 const xmlChar *str);
XMLPUBFUN int XMLCALL			
			xmlDictSize	(xmlDictPtr dict);

void xmlDictCleanup(void);

#include <fbxsdk/fbxsdk_nsend.h>

#endif // FBXFILESDK_COMPONENTS_LIBXML2_2_7_8_INCLUDE_LIBXML_DICT_H

