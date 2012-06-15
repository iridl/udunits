/* port/misc/stddef.h.  Generated automatically by configure.  */
/*
 * $Id$
 */

#ifndef UD_SYSTEM_STDDEF_H
#   define	UD_SYSTEM_STDDEF_H	"///usr/include/stddef.h"
#endif
#include UD_SYSTEM_STDDEF_H


#ifndef UD_stddef_h
#define UD_stddef_h


/* #undef	UD_NO_STDDEF_H_PTRDIFF_T */
/* #undef	UD_NO_STDDEF_H_SIZE_T */


#include "udposix.h"


#ifndef offsetof
#  define offsetof(type, member)	((size_t)&((type*)0)->member)
#endif

#ifndef NULL
#  define NULL 0
#endif

#ifdef UD_NO_STDDEF_H_SIZE_T
#   ifndef UD_SIZE_T
	typedef unsigned int	size_t;
#   endif
#endif
#ifndef UD_SIZE_T
#   define UD_SIZE_T
#endif

#ifdef UD_NO_STDDEF_H_PTRDIFF_T
    typedef unsigned long	ptrdiff_t;
#endif


#endif	/* UD_stddef_h not defined above */
