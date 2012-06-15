/* port/misc/time.h.  Generated automatically by configure.  */
/*
 * $Id$
 */

#ifndef UD_SYSTEM_TIME_H
#   define	UD_SYSTEM_TIME_H	"///usr/include/time.h"
#endif
#include UD_SYSTEM_TIME_H


#ifndef UD_time_h
#define UD_time_h


/* #undef	UD_NO_TIME_H_SIZE_T */
/* #undef	UD_NO_TIME_H_TIME_T */
/* #undef	UD_NO_DIFFTIME_DECL */
/* #undef	UD_NO_STRFTIME_DECL */


#include "udposix.h"


#ifdef UD_NO_TIME_H_SIZE_T
#   ifndef UD_SIZE_T
	typedef unsigned int	size_t;
#   endif
#endif
#ifndef UD_SIZE_T
#   define UD_SIZE_T
#endif


#ifdef UD_NO_TIME_H_TIME_T
   typedef long	time_t;
#endif


#ifdef UD_NO_DIFFTIME_DECL
    UD_EXTERN_FUNC(double difftime, (time_t t1, time_t t0));
#endif

#ifdef UD_NO_STRFTIME_DECL
    UD_EXTERN_FUNC(size_t strftime, (char *s, size_t maxsize, const char *format, const struct tm *timeptr));
#endif


#endif	/* UD_time_h not defined above */
