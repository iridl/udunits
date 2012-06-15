/* port/misc/string.h.  Generated automatically by configure.  */
/*
 * $Id$
 */

#ifndef UD_string_h
#define UD_string_h


#define	UD_SYSTEM_STRING_H	"///usr/include/string.h"
/* #undef	UD_NO_STRCHR_DECL */
/* #undef	UD_NO_STRCPY_DECL */
/* #undef	UD_NO_STRERROR_DECL */
/* #undef	UD_NO_STRING_H_SIZE_T */
/* #undef	UD_NO_STRNCPY_DECL */
/* #undef	UD_NO_STRRCHR_DECL */
/* #undef	UD_NO_STRTOK_DECL */


#include "udposix.h"
#include UD_SYSTEM_STRING_H


#ifdef UD_NO_STRING_H_SIZE_T
#   ifndef UD_SIZE_T
	typedef unsigned int	size_t;
#   endif
#endif
#ifndef UD_SIZE_T
#   define UD_SIZE_T
#endif


#ifdef UD_NO_STRCHR_DECL
    UD_EXTERN_FUNC(char *strchr, (const char *string, int chr));
#endif

#ifdef UD_NO_STRCPY_DECL
    UD_EXTERN_FUNC(char *strcpy, (char *s1, const char *s2));
#endif

#ifdef UD_NO_STRERROR_DECL
    UD_EXTERN_FUNC(char *strerror, (int errno));
#endif

#ifdef UD_NO_STRNCPY_DECL
    UD_EXTERN_FUNC(char *strncpy, (char *s1, const char *s2, size_t n));
#endif

#ifdef UD_NO_STRRCHR_DECL
    UD_EXTERN_FUNC(char *strrchr, (const char *string, int chr));
#endif

#ifdef UD_NO_STRTOK_DECL
    UD_EXTERN_FUNC(char *strtok, (char *string, const char *tokens));
#endif


#endif	/* UD_string_h not defined above */
