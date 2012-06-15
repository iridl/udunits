/*
 * $Id$
 */

/*LINTLIBRARY*/


#include "udposix.h"
#include "stdlib.h"


    int
atexit(func)
    void	(*func)UD_PROTO((void));
{
    return on_exit(func, (char*)0);
}
