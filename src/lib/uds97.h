#ifndef UT_UNITS_HS97_INCLUDED
#define UT_UNITS_HS97_INCLUDED

#define UT_SB97

#define UT_DIR_NULL      0
#define UT_DIR_NORTH     1
#define UT_DIR_SOUTH     2
#define UT_DIR_EAST      3
#define UT_DIR_WEST      4

#define UT_DIR_UP       10
#define UT_DIR_DOWN     11
#define UT_DIR_RIGHT    12
#define UT_DIR_LEFT     13
#define UT_DIR_FORWARD  14
#define UT_DIR_BACKWARD 15

/*senya-97----------------------------------------------------------------*/
/*
 *s97	Set an origin for a unit structure.
 */
extern utUnit*	utSetOrigin	PROTO((
    utUnit	*source,
    double	value,
    utUnit	*result
));

/*
 *s97	Clear an origin of a unit structure.
 */
extern utUnit*	utClearOrigin	PROTO((
    utUnit *unit
));

/*
 *s97	Get an origin of a unit structure.
 */
extern double	utGetOrigin	PROTO((
    utUnit *unit
));

/*
 *s97	Set a direction for a unit structure.
 */
extern utUnit*	utSetDirection	PROTO((
    utUnit	*source,
    int  	value,
    utUnit	*result
));

/*
 *s97	Clear a direction of a unit structure.
 */
extern utUnit*	utClearDirection	PROTO((
    utUnit *unit
));

/*
 *s97	Get a direction of a unit structure.
 */
extern int utGetDirection	PROTO((
    const utUnit *unit
));

/*
 *s97 Add one unit-structure to another (origin and directions could differ).
 */
extern utUnit*	utAdd2	PROTO((
    utUnit	*term1,
    utUnit	*term2, 
    utUnit	*result
));
/*
 *s97  Subtract one unit-structure from another(origin/directions could differ)
 */
extern utUnit*	utSub2	PROTO((
    utUnit	*term1,
    utUnit	*term2, 
    utUnit	*result
));
/*senya-97----------------------------------------------------------------*/
#endif	/* UT_UNITS_HS97_INCLUDED not defined */

