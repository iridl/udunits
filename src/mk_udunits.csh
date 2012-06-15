#!/bin/csh -f

# invoke: "mk_udunits ia32"

if ( $argv[1] == "linux" ) then
    setenv CC pgcc
    setenv CC_MAKEDEPEND "pgcc -M"
    cp -p CUSTOMIZE.linux CUSTOMIZE
else if ( ( $argv[1] == "ia32" ) ) then
    setenv CC icc
    setenv CC_MAKEDEPEND "icc -M"
    cp -p CUSTOMIZE.ia32 CUSTOMIZE
else if ( ( $argv[1] == "opt32" ) ) then
    setenv CC icc
    setenv CC_MAKEDEPEND "icc -M"
    cp -p CUSTOMIZE.opt32 CUSTOMIZE
endif

./configure >&! log
make all install clean >>&! log

if ( $argv[1] == "linux" ) then
    mv ./lib/libudunits.a ../../linuxlib
    /bin/rm ./lib/*.o ./port/cfortran/Makefile
else if ( $argv[1] == "ia32" ) then
    mv ./lib/libudunits.a ../../ia32lib
    /bin/rm ./lib/*.o ./port/cfortran/Makefile
else if ( $argv[1] == "opt32" ) then
    mv ./lib/libudunits.a ../../opt32lib
    /bin/rm ./lib/*.o ./port/cfortran/Makefile
else if ( $argv[1] == "opt64" ) then
    mv ./lib/libudunits.a ../../opt64lib
    /bin/rm ./lib/*.o ./port/cfortran/Makefile
endif

exit
