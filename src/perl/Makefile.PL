# Generated automatically from Makefile.PL.in by configure.
use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
$version = `cat ../VERSION`;
WriteMakefile(
    'NAME'	=> 'UDUNITS',
    'VERSION'	=> $version,
    'CC'	=> 'cc',
    'LIBS'	=> "-L../lib -ludunits -lm ",
    'DEFINE'	=> '',     # e.g., '-DHAVE_SOMETHING' 
    'INC'	=> '-I../lib -I../port/misc',     # e.g., '-I/usr/include/other' 
    'LINKTYPE'	=> 'dynamic',	# 'static' or 'dynamic'
    'clean' => {'FILES' => "*.bs *.i"},
    'realclean' => {'FILES' => "*.old"}
);
