/* port/misc/stdarg.h.  Generated automatically by configure.  */
/*
 * $Id$
 */


#ifndef UD_SYSTEM_STDARG_H
#   define	UD_SYSTEM_STDARG_H	"///usr/include/stdarg.h"
#endif
#include	UD_SYSTEM_STDARG_H


#ifndef UD_stdarg_h
#define UD_stdarg_h

/* #undef	UD_NO_STDARG */

#include	"udposix.h"


/*
 * Macro support for variadic functions.  Define the following if your
 * compiler doesn't support Standard C variadic functions (i.e. if
 * <varargs.h> exists and <stdarg.h> doesn't).
 */

#ifdef	UD_NO_STDARG
#  define UD_VA_START(ap, lastarg)	va_start(ap)
#else
#  define UD_VA_START(ap, lastarg)	va_start(ap, lastarg)
#endif

/*
 * Macro for backwards compatibility:
 */
#ifdef	UD_NO_STDARG
/* #  undef UD_STDARG */
#else
#  define UD_STDARG
#endif


#endif	/* UD_stdarg_h not defined above */
