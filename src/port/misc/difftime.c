/*
 * $Id$
 */

/*LINTLIBRARY*/


#include "udposix.h"
#include "time.h"


/*
 * Return the difference in seconds between two calendar times.
 */
    double
difftime(time1, time0)
    time_t	time1;
    time_t	time0;
{
    double	diff;

    diff	= time1 - time0;

    return diff;
}
