/* port/misc/search.h.  Generated automatically by configure.  */
/*
 * $Id$
 */

#ifndef UD_search_h
#define UD_search_h


#define	UD_SYSTEM_SEARCH_H	"///usr/include/search.h"
/* #undef	UD_NO_SEARCH_H_ENTRY */
/* #undef	UD_NO_SEARCH_H_ACTION */
/* #undef	UD_NO_SEARCH_H_VISIT */
/* #undef	UD_NO_TSEARCH_DECL */
/* #undef	UD_NO_TFIND_DECL */
/* #undef	UD_NO_TDELETE_DECL */
/* #undef	UD_NO_TWALK_DECL */


#include "udposix.h"
#include UD_SYSTEM_SEARCH_H


#ifdef UD_NO_SEARCH_H_ENTRY
    typedef struct entry { char *key, *data; } ENTRY;
#endif

#ifdef UD_NO_SEARCH_H_ACTION
    typedef enum { FIND, ENTER } ACTION;
#endif

#ifdef UD_NO_SEARCH_H_VISIT
    typedef enum { preorder, postorder, endorder, leaf } VISIT;
#endif


#ifdef UD_NO_TSEARCH_DECL
    UD_EXTERN_FUNC(void* tsearch, (const void *key, void **rootp, int (*compar)UD_PROTO((const void*, const void*))));
#endif

#ifdef UD_NO_TFIND_DECL
    UD_EXTERN_FUNC(void* tfind, (const void *key, void *const*rootp, int (*compar)UD_PROTO((const void*, const void*))));
#endif

#ifdef UD_NO_TDELETE_DECL
    UD_EXTERN_FUNC(void *tdelete, (const void *key, void **rp, int (*compar)UD_PROTO((const void*, const void*))));
#endif

#ifdef UD_NO_TWALK_DECL
    UD_EXTERN_FUNC(void twalk, (const void *rt, void (*action)UD_PROTO((const void*, VISIT, int))));
#endif


#endif	/* header-file lockout*/
