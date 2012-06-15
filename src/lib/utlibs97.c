/*senya-97--------------------------------------------------------------*/
/* 
 *s97 Set the origin of a unit structure.
 *
 *  This function returns a pointer to the destination unit structure.
 */
    utUnit*
utSetOrigin(source, value, result)
    utUnit	*source;
    double	value;
    utUnit	*result;
{
    assert(source != NULL);
    assert(result != NULL);

    (void) utCopy(source, result);
    result->origin	= value;
    result->hasorigin	= 1;

    return result;
}
/*
 *s97 FORTRAN interface to the above function.
 */

FCALLSCSUB3(utSetOrigin,UTSETO,utseto,PPUNIT,DOUBLE,PPUNIT)

/*
 *s97  Clear an origin
 *
 *  This function returns a pointer to the unit structure.
 */
    utUnit*
utClearOrigin(unit)
    utUnit		*unit;
{
    unit->hasorigin	= 0;
    unit->origin	= 0.0;

    return unit;
}

/*
 *s97 FORTRAN interface to the above function.
 */
FCALLSCSUB1(utClearOrigin,UTCLRO,utclro,PPUNIT)

/*
 *s97 Return an Origin
 *
 */
    UtOrigin
utGetOrigin(up)
    const utUnit  *up;
{
    return up->origin;
}

/*
 *s97 FORTRAN interface to the above function.
 */
FCALLSCFUN1(DOUBLE,utGetOrigin,UTGETO,utgeto,PPUNIT)

/* 
 *s97 Set a direction of a unit structure.
 *
 *  This function returns a pointer to the destination unit structure.
 */
    utUnit*
utSetDirection(source, value, result)
    utUnit	*source;
    int 	  value;
    utUnit	*result;
{
    assert(source != NULL);
    assert(result != NULL);

    (void) utCopy(source, result);
    result->direction = value;

    return result;
}
/*
 *s97 FORTRAN interface to the above function.
 */

FCALLSCSUB3(utSetDirection,UTSETD,utsetd,PPUNIT,INT,PPUNIT)

/*
 *s97  Clear a direction
 *
 *  This function returns a pointer to the unit structure.
 */
    utUnit*
utClearDirection(unit)
    utUnit *unit;
{
    unit->direction = 0;

    return unit;
}

/*
 *s97 FORTRAN interface to the above function.
 */
FCALLSCSUB1(utClearDirection,UTCLRD,utclrd,PPUNIT)

/*
 *s97 Return the Direction of the unit
 *
 */
    int
utGetDirection(up)
    const utUnit  *up;
{
    return up->direction;
}

/*
 *s97 FORTRAN interface to the above function.
 */
FCALLSCFUN1(INT,utGetDirection,UTGETD,utgetd,PPUNIT)

/* 
 *s97  Add two unit-structures.
 *
 *  This function returns
 *	NULL			failure;
 *	pointer to `result'	success.
 */
    utUnit*
utAdd2(term1, term2, result)
    utUnit     *term1, *term2, *result;
{
  double slope, intercept;
  int    i;

  i = utConvert(term1, term2, &slope, &intercept);

  if ( i == UT_ECONVERT || (term1->factor != term2->factor)  ) {
/*    (void) fprintf(stderr, "udunits(3): Can't add incompatible units\n"); */
    return (utUnit *)NULL;
  }
  i = (int)term1->hasorigin + (int)term2->hasorigin;
  if (i == 2 & (term1->origin != term2->origin) ) {
/*    (void) fprintf(stderr, "udunits(3): Can't add incompatible units\n"); */
    return (utUnit *)NULL;
  }
  
  result->direction = term1->direction;

  result->factor = term1->factor;
  
  if ( i ) {  /* one has an origin */
    int iquan;
    result->hasorigin = 1;
    result->origin = (term1->hasorigin ? term1->origin : term2->origin);
	if(term1->hasorigin){
	for (iquan = 0; iquan < UT_MAXNUM_BASE_QUANTITIES; ++iquan)
	    result->opower[iquan]    = term1->opower[iquan];
      }	  
	else {
	for (iquan = 0; iquan < UT_MAXNUM_BASE_QUANTITIES; ++iquan)
	    result->opower[iquan]    = term2->opower[iquan];
      }

  }
  else {
    result->hasorigin = 0;
    result->origin    = 0.;
  }

  for (i = 0; i < UT_MAXNUM_BASE_QUANTITIES; ++i)
    result->power[i] = term1->power[i];
    
  return result;
}

/*
 * FORTRAN interface to the above function.
 */
FCALLSCSUB3(utAdd2,UTADD2,utadd2,PPUNIT,PPUNIT,PPUNIT)

/* 
 *s97  Subtract two unit-structures.
 *
 *  This function returns
 *	NULL			failure;
 *	pointer to `result'	success.
 */
    utUnit*
utSub2(term1, term2, result)
    utUnit     *term1, *term2, *result;
{
  double slope, intercept;
  int    i,j,ipow,iquan;

  if ( utConvert(term1, term2, &slope, &intercept) || 
       term1->factor != term2->factor ) {
/*    (void) fprintf(stderr, "udunits(3): Can't subtract incompatible units\n"); */
    return (utUnit *)NULL;
  }
  
  result->factor = term1->factor;
  result->direction = term1->direction;

  i = (int)term1->hasorigin + (int)term2->hasorigin;

  ipow = 1;
  if (i == 2) {
  for (j = 0; j < UT_MAXNUM_BASE_QUANTITIES; ++j)
    ipow = ipow && ( term1->power[j] ==  term1->opower[j]);
}
 
  if ( i == 1 || !ipow ) {  /* only one has an origin or origin in different units  */
    result->hasorigin = 1;
    result->origin = (term1->hasorigin ? term1->origin : term2->origin);
	if(term1->hasorigin){
	for (iquan = 0; iquan < UT_MAXNUM_BASE_QUANTITIES; ++iquan)
	    result->opower[iquan]    = term1->opower[iquan];
      }	  
	else {
	for (iquan = 0; iquan < UT_MAXNUM_BASE_QUANTITIES; ++iquan)
	    result->opower[iquan]    = term2->opower[iquan];
      }
  }
  else {                    /* both have or don't have origins: */ 
    result->hasorigin = 0;
    result->origin    = 0.;
  }

  for (i = 0; i < UT_MAXNUM_BASE_QUANTITIES; ++i)
    result->power[i] = term1->power[i];
    
  return result;
}

/*
 * FORTRAN interface to the above function.
 */
FCALLSCSUB3(utSub2,UTSUB2,utsub2,PPUNIT,PPUNIT,PPUNIT)

/*senya-97----------------------------------------------------------------*/



