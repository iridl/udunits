      integer	UT_EOF, UT_ENOFILE, UT_ESYNTAX, UT_EUNKNOWN
      integer	UT_EIO, UT_EINVALID, UT_ENOINIT, UT_ECONVERT
      integer	UT_EALLOC, UT_ENOROOM, UT_ENOTTIME

      parameter (UT_EOF		= 1)
      parameter	(UT_ENOFILE	= -1)
      parameter (UT_ESYNTAX	= -2)
      parameter (UT_EUNKNOWN	= -3)
      parameter (UT_EIO		= -4)
      parameter (UT_EINVALID	= -5)
      parameter (UT_ENOINIT	= -6)
      parameter (UT_ECONVERT	= -7)
      parameter (UT_EALLOC	= -8)
      parameter (UT_ENOROOM	= -9)
      parameter (UT_ENOTTIME	= -10)

      integer	UT_MAXNUM_BASE_QUANTITIES
      parameter	(UT_MAXNUM_BASE_QUANTITIES = 10)

C The FORTRAN API:
C
C NB: `PTR in the following stands for whatever FORTRAN type is
C appropriate for storing a pointer to a structure.  Because this is
C necessarily platform-dependent, IT IS UP TO THE USER TO DECLARE AND USE
C THE CORRECT TYPE.

#ifndef PTR
#   define PTR	integer
#endif

C
C   Initialize the units package:
      external utopen
      integer utopen
C	(character*(*) fpath)

C   Create a new unit:
      external utmake
      PTR utmake
C	()

C   Is a unit a temporal one?
      integer uttime
C	(PTR unit)

C   Indicate whether or not a unit has a non-zero origin (0=>no, 1=>yes).
      integer utorigin
C	  (PTR unit)

C   Clear a unit:
C     utclr
C	(PTR unit)

C   Copy a unit:
C     utcpy
C	(PTR source,
C	PTR dest)

C   Shift the origin of a unit:
C     utorig
C	(PTR source, 
C	doubleprecision amount, 
C	PTR result)

C   Scale a unit:
C     utscal
C	(PTR source, 
C	doubleprecision factor, 
C	PTR result)

C   Multiply two units:
C     utmult
C	(PTR term1,
C	PTR term2, 
C	PTR result)

C   Invert a unit:
C     utinv
C	(PTR source,
C	PTR result)

C   Divide one unit by another:
C     utdiv
C	(PTR numer,
C	PTR denom, 
C	PTR result)

C   Raise a unit to a power:
C     utexp
C	(PTR source,
C	PTR power, 
C	PTR result)

C   Decode a formatted specification into a unit:
      integer utdec
C	(character*(*) fspec,
C	PTR unit)

C   Convert a temporal value into a UTC Gregorian date and time:
      integer utcaltime
C	(real    value,
C	PTR unit,
C	integer year
C	integer month,
C	integer day,
C	integer hour,
C	integer minute,
C	real    second)

C   Convert a Gregorian/Julian date and time into a temporal value:
      integer uticaltime
C       (integer year,
C       integer  month,
C       integer  day,
C       integer  hour,
C       integer  minute,
C       real     second,
C       PTR      unit,
C       doubleprecision value)

C   Encode a unit into a formatted specification:
      integer utenc
C	(PTR unit,
C	char fspec)

C   Convert from one unit to another:
      integer utcvt
C	(PTR from,
C	PTR to, 
C	doubleprecision slope, 
C	doubleprecision intercept)

C   Free a unit thingy created by utmake():
C     utfree
C	(PTR unit)

C   Close the units package:
C     utcls
C	()
c--------------------------------------------------------------
cSB97 upgrade:

	integer	UT_DIR_NULL, UT_DIR_NORTH, UT_DIR_SOUTH, UT_DIR_EAST,
     *          UT_DIR_WEST, UT_DIR_UP, UT_DIR_DOWN, UT_DIR_RIGHT,   
     *	UT_DIR_LEFT, UT_DIR_FORWARD, UT_DIR_BACKWARD

	parameter ( UT_DIR_NULL     = 0)
	parameter ( UT_DIR_NORTH    = 1)
	parameter ( UT_DIR_SOUTH    = 2)
	parameter ( UT_DIR_EAST     = 3)
	parameter ( UT_DIR_WEST     = 4)

	parameter ( UT_DIR_UP       = 10)
	parameter ( UT_DIR_DOWN     = 11)
	parameter ( UT_DIR_RIGHT    = 12)
	parameter ( UT_DIR_LEFT     = 13)
	parameter ( UT_DIR_FORWARD  = 14)
	parameter ( UT_DIR_BACKWARD = 15)
c
        external utseto
c
        external utgeto
        double precision utgeto
c
        external utclro
c
        external utsetd
c
        external utgetd
        INTEGER  utgetd
c
        external utclrd
c
        external utadd2
c
        external utsub2
c end of SB97 upgrade:
c--------------------------------------------------------------
