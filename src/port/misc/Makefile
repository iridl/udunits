# Generated automatically from Makefile.in by configure.
# This is the makefile for miscellaneous Unidata portability functions.
#
# $Id$


.POSIX:

LIBRARY		= udport

cpp_ldm		= 
CPPFLAGS	= -I. $(cpp_ldm) -D_REENTRANT 
CFLAGS		= -O

PORT_HEADERS	= 
config_headers	= search.h signal.h stdarg.h stddef.h stdio.h stdlib.h \
		  string.h time.h udconfig.h udposix.h uthread.h
made_headers	= float.h
LIBOBJS		= uddummy.o 

MANIFEST        = \
		  Makefile.in \
		   stdarg.h.in udposix.h.in udalloc.c udalloc.h stddef.h.in config.c stdlib.h.in atexit.c strerror.c strstr.c string.h.in memmove.c difftime.c strftime.c time.h.in limits.h.in search.h.in tsearch.c tfind.c tdelete.c twalk.c search-node.h \
		  depend \
		  uddummy.c

all:		$(PORT_HEADERS) library

# We install the portability library modules directly into an installed
# portability library even though the package using this portability library
# (the client package) probably doesn't reference the installed one.  This is
# done because the client package might be another library and linking
# against it might require some modules of this library.  We don't install
# the portability library just created because different packages can require
# different modules.
#
install:	$(LIBOBJS)
	$(MAKE) $(MFLAGS) $(LIBDIR) LIBDIR=$(LIBDIR)
	$(AR) rcuv $(LIBDIR)/libudport.a $(LIBOBJS)
	$(RANLIB) $(LIBDIR)/libudport.a

clean:		default_clean
	rm -f $(made_headers) config

distclean:	default_distclean
	rm -f limits.h $(made_headers) $(config_headers) config

# If the following invocation of `config' exits with a bad
# status, then see the output file for the problem.
#
float.h:	config
	./config -f > $@

# C-compiler information program:
#
# NB: config(1) must be compiled unoptimized.  We first assume that `signed
# char' is valid; if that doesn't work, then we assume it's invalid.  If
# that doesn't work, the user will have to determine the appropriate
# compilation flags (see config.c).
#
# If the following program won't compile, then contact
# support@unidata.ucar.edu (ask for Steve).
#
config:		config.c
	case `uname -s` in \
	sn*) \
	    $(CC) -O0 config.c -o config; \
	    ;; \
	*) \
	    if $(CC) config.c -o config 2> /dev/null; then \
		: true; \
	    else \
		$(CC) -DNO_SC config.c -o config; \
	    fi \
	    ;; \
	esac

# This is the master makefile.  It contains general rules.
#
# $Id$


.SUFFIXES:
.SUFFIXES:	.so .o .S .ln .i .c .fc .f .F .cc .l .y .cdl .nc .sh

############################################################################
# General Macros:
############################################################################
prefix		= /data/hoop/udunits-1.11.7
exec_prefix	= /data/hoop/udunits-1.11.7
AR		= ar
CC		= cc
CPP		= cc -E
CC_MAKEDEPEND	= cc -xM
CXX		= @CXX@
FC		= @FC@
LINT		= lint
LINTFLAGS	= -u
MAKEINFO	= @MAKEINFO@
NCDUMP		= @NCDUMP@
NCGEN		= @NCGEN@
NEQN		= neqn
OS		= sunos5
SHELL		= /bin/sh
TBL		= tbl
WHICH		= @WHICH@



############################################################################
# Recursive make(1)s in Subdirectories:
############################################################################

subdir_dummy_target $(SUBDIR_TARGETS):
	@echo ""
	@dir=`echo $@ | sed 's,/.*,,'`; \
	    target=`echo $@ | sed "s,$$dir/,,"`; \
	    cd $$dir && \
	    echo "making \`$$target' in directory `pwd`" && \
	    echo "" && \
	    $(MAKE) $(MFLAGS) \
		prefix=$(prefix) exec_prefix=$(exec_prefix) \
		$$target || exit 1
	@echo ""
	@echo "returning to directory `pwd`"
	@echo ""

subdirs/all \
subdirs/test \
subdirs/install \
subdirs/clean \
subdirs/distclean:	FORCE
	@case "$(SUBDIRS)" in \
	    '') ;; \
	    *)	filename=`echo $@ | sed 's:.*/::'`; \
		targets=`echo $(SUBDIRS) | tr ' ' '\012' | \
		    sed 's:$$:/'$$filename':'`; \
		$(MAKE) $$targets;; \
	esac


############################################################################
# Compilation:
############################################################################
FORTC		= @FORTC@

# Compile C++ code.
.cc.o:
	$(CXX) -c $(CXXFLAGS) $(CXXCPPFLAGS) $<

# Compile FORTRAN code.
#
.f.o:
	$(FC) -c $(FFLAGS) $<
.F.o:
	ln -s $< $*.c && \
	    ($(CPP) -DUD_FORTRAN_SOURCE $(CPPFLAGS) $*.c >$*.i && \
	    sed '/^# *[0-9]/d' $*.i > $*.f) || \
	    (rm -f $*.f $*.i $*.c ; exit 1) && \
	    rm $*.i
	$(FC) -c $(FFLAGS) $*.f && rm $*.f $*.c
.F.f:
	ln -s $< $*.c && \
	    ($(CPP) -DUD_FORTRAN_SOURCE $(CPPFLAGS) $*.c >$*.i && \
	    grep -v '^#' $*.i > $@) || \
	    (rm -f $@ $*.i $*.c; exit 1) && \
	    rm $*.i $*.c
.F.i:
	ln -s $< $*.c && \
	    $(CPP) -DUD_FORTRAN_SOURCE $(CPPFLAGS) $*.c >$*.i

# Generate FORTRAN-callable C code.
#
.fc.o:
	$(FORTC) -O $(OS) $< > $*.c \
	    || ( rm -f $*.c; exit 1)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $*.c
.fc.c:
	$(FORTC) -O $(OS) $< > $@ \
	    || (rm -f $*.c; exit 1)

# Compile assembler code.
#
.S.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $<

# Compile C code.
#
.c.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $<

# Compile lex(1) code.  This rule is here to ensure the use of CPPFLAGS.
# 
.l.o:
	rm -f $*.c
	$(LEX) -t $< > $*.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $*.c
	rm $*.c

# C preprocess.  
#   NB: 
#	1. Line numbering information is kept.
#
.c.i:
	$(CPP) $(CPPFLAGS) $< > $@

.cdl.nc:
	$(NCGEN) -o $*.nc $*.cdl

.sh:
	cp $< $@; chmod +x $@

############################################################################
# Lint:
############################################################################
.c.ln:
	$(LINT) -c $(LINTFLAGS) $(CPPFLAGS) $<


############################################################################
# Libraries:
############################################################################
RANLIB		= ranlib
LIBDIR		= $(exec_prefix)/lib
LIB_A		= lib$(LIBRARY).a
LIBFILE		= dummy-libfile		# to silence GNU make(1)

library:		$(LIB_A)

remote_library:		$(REMOTE_LIBRARY)

# The following rule is forced because the library can be created by a
# makefile in another directory prior to the execution of the following rule.
#
$(LIB_A):		$(LIBOBJS) $(LIBOBJS2) FORCE
	$(AR) rcuv $@ $(LIBOBJS)
	case "$(LIBOBJS2)" in \
	'') ;; \
	*)  $(AR) rucv $@ $(LIBOBJS2);; \
	esac
	$(RANLIB) $@

# The following rule is for those makefiles needing to install object
# modules in a library in another directory.  They need only define 
# REMOTE_LIBRARY and LIBOBJS.  The rule is forced for the same reason as the
# $(LIB_A) rule.
#
lib_dummy $(REMOTE_LIBRARY):	$(LIBOBJS) FORCE
	$(AR) rcuv $@ $(LIBOBJS)
	$(RANLIB) $@

installed_libfiles:	FORCE
	@if [ -n "$(LIBFILES)" ]; then \
	    libfiles="$(LIBFILES)"; \
	    for libfile in $$libfiles; do \
		$(MAKE) $(MFLAGS) \
		    LIBDIR=$(LIBDIR) LIBFILE=$$libfile \
		    installed_libfile || exit 1; \
	    done; \
	else \
	    :; \
	fi

installed_library:	FORCE
	@$(MAKE) $(MFLAGS) \
	    LIBDIR=$(LIBDIR) LIBFILE=$(LIB_A) \
	    installed_libfile

# The following target decouples the previous targets from the actual rule;
# thus, eliminating extraneous make(1) messages.
#
installed_libfile:	$(LIBDIR)/$(LIBFILE)

$(LIBDIR)/dummy.a $(LIBDIR)/$(LIBFILE):	$(LIBDIR) $(LIBFILE)
	cp $(LIBFILE) $@

dummy_libdir $(LIBDIR):
	mkdir -p $@
	chmod u+rwx,g+rws,o=rx $@

LIB_SO		= lib$(LIBRARY).so.$(MAJOR_NO).$(MINOR_NO)
LIB_SA		= lib$(LIBRARY).sa.$(MAJOR_NO).$(MINOR_NO)

#library:		FORCE
#	@so_objs=`echo $(LIBOBJS) | sed 's/\.o/.so/g'`; \
#	if [ -z "$$so_objs" ]; then \
#	    :; \
#	else \
#	    $(MAKE) $(MFLAGS) $(LIB_SO) \
#		SO_OBJS="$$so_objs"; \
#	fi
#	@if [ -z "$(SA_OBJS)" ]; then \
#	    :; \
#	else \
#	    $(MAKE) $(MFLAGS) $(LIB_SA); \
#	fi

$(LIB_SO):	$(SO_OBJS)
	ld -assert pure-text $(SO_OBJS) -o $@
$(LIB_SA):	$(SA_OBJS) FORCE
	$(AR) rcuv $@ $(SA_OBJS)

.fc.so:
	$(FORTC) -O $(OS) $< > $*.c \
	    || (rm -f $*.c; exit 1)
	$(CC) -c -o $$$$.o -pic $(CFLAGS) $(CPPFLAGS) $*.c \
	    || (rm -f $$$$.o; exit 1)
	mv $$$$.o $@
.c.so:
	$(CC) -c -o $$$$.o -pic $(CFLAGS) $(CPPFLAGS) $< \
	    || (rm -f $$$$.o; exit 1)
	mv $$$$.o $@

#installed_library:	$(LIBDIR)/$(LIB_SO)
#	@if [ -z "$(SA_OBJS)" ]; then \
#	    :; \
#	else \
#	    $(MAKE) $(MFLAGS) $(LIBDIR)/$(LIB_SA); \
#	fi

$(LIBDIR)/dummy.so $(LIBDIR)/$(LIB_SO):	$(LIBDIR) $(LIB_SO)
	cp $(LIB_SO) $(LIBDIR)/$(LIB_SO)
$(LIBDIR)/dummy.sa $(LIBDIR)/$(LIB_SA):	$(LIBDIR) $(LIB_SA)
	cp $(LIB_SA) $(LIBDIR)/$(LIB_SA)


############################################################################
# Programs:
############################################################################
BINDIR		= $(exec_prefix)/bin
BINFILE		= dummy-binfile

programs:	$(PROGRAMS)
program:
	@if [ -z "$(PROGRAM)" ]; then \
	    : true; \
	else \
	    $(MAKE) $(MFLAGS) $(PROGRAM); \
	fi

dummy_prog $(PROGRAM):	$(OBJS)
	@if [ -r $@.f -o -r $@.F ]; then \
	    ld='$(FC) -o $@ $(FFLAGS)'; \
	elif [ -r $@.cc -o -r $@.C ]; then \
	    ld='$(CXX) -o $@ $(CXXFLAGS)'; \
	else \
	    ld='$(CC) -o $@ $(CFLAGS)'; \
	fi; \
	cmd="$$ld $(LDFLAGS) $(OBJS) $(LIBS)"; \
	echo $$cmd; \
	$$cmd \
	    || (rm -f $@; exit 1)

installed_programs:	FORCE
	@$(MAKE) $(MFLAGS) installed_binfiles \
	    BINDIR=$(BINDIR) BINFILES="$(PROGRAMS)"

installed_binfiles:	FORCE
	@if [ -n "$(BINFILES)" ]; then \
	    binfiles="$(BINFILES)"; \
	    for binfile in $$binfiles; do \
		$(MAKE) $(MFLAGS) \
		    BINDIR=$(BINDIR) BINFILE=$$binfile \
		    installed_binfile || exit 1; \
	    done; \
	else \
	    :; \
	fi

installed_program:	FORCE
	@$(MAKE) $(MFLAGS) \
	    BINDIR=$(BINDIR) BINFILE=$(PROGRAM) \
	    installed_binfile

# The following target decouples the previous targets from the actual rule;
# thus, eliminating extraneous make(1) messages.
#
installed_binfile:	$(BINDIR)/$(BINFILE)

$(BINDIR)/dummy $(BINDIR)/$(BINFILE):	$(BINDIR) $(BINFILE)
	cp $(BINFILE) $@

dummy_bindir $(BINDIR):
	mkdir -p $@
	chmod u+rwx,g+rws,o=rx $@

$(PROGRAM).pure:	$(OBJS)
	purify -best-effort $(PURIFYFLAGS) $(CC) -o $@ \
	    $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LIBS)

pure:	purify

purify:		$(PROGRAM).pure FORCE
	$(MAKE) $(MFLAGS) PROGRAM=$(PROGRAM).pure test.pure.out


############################################################################
# Header files:
############################################################################
INCDIR		= $(prefix)/include
HEADER		= dummy-header		# to silence GNU make(1)

installed_headers:	FORCE
	@if [ -n "$(HEADERS)" ]; then \
	    headers="$(HEADERS)"; \
	    for header in $$headers; do \
		$(MAKE) $(MFLAGS) \
		    INCDIR=$(INCDIR) HEADER=$$header \
		    installed_header || exit 1; \
	    done; \
	else \
	    :; \
	fi

# The following target decouples the previous targets from the actual rule;
# thus, eliminating extraneous make(1) messages.
#
installed_header:	$(INCDIR)/$(HEADER)

$(INCDIR)/dummy.h $(INCDIR)/$(HEADER):	$(INCDIR) $(HEADER)
	cp $(HEADER) $@

dummy_incdir $(INCDIR):
	mkdir -p $@
	chmod u+rwx,g+rws,o=rx $@


############################################################################
# `etc/' files:
############################################################################
ETCDIR	= $(prefix)/etc
ETCFILE	= dummy-etcfile		# to silence GNU make(1)

installed_etcfiles:
	@if [ -n "$(ETCFILES)" ]; then \
	    etcfiles="$(ETCFILES)"; \
	    for etcfile in $$etcfiles; do \
		$(MAKE) $(MFLAGS) \
		    ETCDIR=$(ETCDIR) ETCFILE=$$etcfile \
		    installed_etcfile || exit 1; \
	    done; \
	else \
	    :; \
	fi

# The following target decouples the previous targets from the actual rule;
# thus, eliminating extraneous make(1) messages.
#
installed_etcfile:	$(ETCDIR)/$(ETCFILE)

$(ETCDIR)/dummy $(ETCDIR)/$(ETCFILE):	$(ETCDIR) $(ETCFILE)
	cp $(ETCFILE) $@

dummy_etcdir $(ETCDIR):
	mkdir -p $@
	chmod u+rwx,g+rws,o=rx $@


############################################################################
# Manual Pages:
############################################################################
MANDIR		= $(prefix)/man
MANUAL		= dummy-manual	# to slience GNU make
WHATIS		= windex
# The following macro should be empty on systems that don't
# allow users to create their own manual-page indexes.
MAKEWHATIS_CMD	= catman -w -M $(MANDIR)

installed_manuals:	FORCE
	@if [ -n "$(MANUALS)" ]; then \
	    manuals="$(MANUALS)"; \
	    for manual in $$manuals; do \
		extension=`echo $$manual | sed 's/[^.]*\.//'`; \
		chapter=`echo $$extension | sed 's/\(.\).*/\1/'`; \
		subchapter=`echo $$extension | sed 's/.//'`; \
		mandir=$(MANDIR)/man$$chapter; \
		$(MAKE) $(MFLAGS) \
		    MANDIR=$$mandir MANUAL=$$manual \
		    installed_manual || exit 1; \
	    done; \
	else \
	    :; \
	fi

# The following target decouples the previous targets from the actual rule;
# thus, eliminating extraneous make(1) messages.
#
installed_manual:	$(MANDIR)/$(MANUAL)

# The first sed(1) editing command in the following replaces the expanded
# RCS keyword `$Date ...' in the `.TH' macro line with something more 
# appropriate to a manual page.
#
# We don't preprocess the manual page with tbl(1) and neqn(1) on OSF1
# IRIX, and HP-UX systems because their man(1) always does that.
#
# NB: Manual pages like `man3/udunits.3f' cause the subdirectory man3f/
# to be created as a symbolic link to man3/.  This accomodates
# operating-systems like SunOS 5.4 which require files like *.3f to be in
# their own man3f/ subdirectory.
#
$(MANDIR)/dummy.man $(MANDIR)/$(MANUAL):	$(MANDIR) $(MANUAL)
	case `uname -s` in \
	    OSF1*|IRIX*|HP-UX) \
		sed \
     -e '/^\.TH/s/$$D\ate: \([0-9]*\)\/\([0-9]*\)\/\([0-9]*\).*\$$/\1-\2-\3/'\
		 $(MANUAL) > $@;; \
	    *) \
		sed \
     -e '/^\.TH/s/$$D\ate: \([0-9]*\)\/\([0-9]*\)\/\([0-9]*\).*\$$/\1-\2-\3/'\
		 $(MANUAL) | $(TBL) | $(NEQN) > $@;; \
	esac
	extension=`echo $(MANUAL) | sed 's/[^.]*\.//'`; \
	subchapter=`echo $$extension | sed 's/.//'`; \
	case "$$subchapter" in \
	    '') ;; \
	    *)  chapter=`echo $$extension | sed 's/\(.\).*/\1/'`; \
		if test -d $(MANDIR)$$subchapter; then \
		    : true; \
		else \
		    mkdir $(MANDIR)$$subchapter; \
		fi; \
		rm -f $(MANDIR)$$subchapter/$(MANUAL); \
		ln -s ../`basename $(MANDIR)`/$(MANUAL) \
		    $(MANDIR)$$subchapter/$(MANUAL); \
		;; \
	esac

dummy_mandir $(MANDIR):
	mkdir -p $@
	chmod u+rwx,g+rws,o=rx $@

whatis:		$(MANDIR)/$(WHATIS)
$(MANDIR)/$(WHATIS):	$(MANDIR)
	$(MAKEWHATIS_CMD)


############################################################################
# Documents:
############################################################################
DOCDIR		= $(prefix)/doc
DOCUMENT	= dummy-document	# to silence GNU make(1)

installed_documents:	FORCE
	case "$(DOCUMENTS)" in \
	    '') : true \
		;; \
	    *)  documents="$(DOCUMENTS)"; \
		for document in $$documents; do \
		    $(MAKE) $(MFLAGS) \
			DOCUMENT=$$document installed_document || exit 1; \
		done \
		;; \
	esac

# The following target decouples the previous targets from the actual rule;
# thus, eliminating extraneous make(1) messages.
#
installed_document:	$(DOCDIR)/$(DOCUMENT)

$(DOCDIR)/dummy.doc $(DOCDIR)/$(DOCUMENT):	$(DOCDIR) $(DOCUMENT)
	cp $(DOCUMENT) $(DOCDIR)

dummy_docdir $(DOCDIR):
	mkdir -p $@
	chmod u+rwx,g+rws,o=rx $@


############################################################################
# TeX-Info Pages:
############################################################################
INFODIR	= $(prefix)/info
INFO	= dummy-info	# to silence GNU make(1)

installed_infos:	FORCE
	if [ -z "$(MAKEINFO)" ]; then \
	    echo 1>&2 "GNU info-pages won't be installed" \
		"because makeinfo program doesn't exist"; \
	else \
	    if [ -n "$(INFOS)" ]; then \
		infos="$(INFOS)"; \
		for info in $$infos; do \
		    $(MAKE) $(MFLAGS) \
			INFODIR=$(INFODIR) INFO=$$info \
			installed_info || exit 1; \
		done; \
	    else \
		:; \
	    fi; \
	fi;

# The following target decouples the previous targets from the actual rule;
# thus, eliminating extraneous make(1) messages.
#
installed_info:	$(INFODIR)/$(INFO)

$(INFODIR)/dummy.info $(INFODIR)/$(INFO):	$(INFODIR) $(INFO)
	cp $(INFO) $@

dummy_infodir $(INFODIR):
	mkdir -p $@
	chmod u+rwx,g+rws,o=rx $@

# Rules for generating info pages:
#
.SUFFIXES:	.info .texi .texinfo .txn
.texi.info:
	@if [ -z "$(MAKEINFO)" ]; then \
	    echo 1>&2 "Can't create $@ because no makeinfo(1)"; \
	else \
	    $(MAKEINFO) $< --no-split --output=$@; \
	fi
.texinfo.info:
	@if [ -z "$(MAKEINFO)" ]; then \
	    echo 1>&2 "Can't create $@ because no makeinfo(1)"; \
	else \
	    $(MAKEINFO) $< --no-split --output=$@; \
	fi
.txn.info:
	@if [ -z "$(MAKEINFO)" ]; then \
	    echo 1>&2 "Can't create $@ because no makeinfo(1)"; \
	else \
	    $(MAKEINFO) $< --no-split --output=$@; \
	fi

# Ensure that info page depends on canonical TeX-Info macros.
#
dummy_info $(INFO):	texinfo.tex


############################################################################
# Cleanup:
############################################################################
clean:			default_clean
distclean:		realclean
realclean:		default_realclean
default_clean:		FORCE
	rm -f $(GARBAGE) $(PROGRAM) a.out core *.o *.i *.a *.so.* *.sa.* \
	    *.so *.u *.pure *.pure_hardlink *.pure_linkinfo conftest* \
	    test.out test.pure.out \
	    *.aux *.toc *.dvi \
	    config.cache *.Z tags MANIFEST *~
default_distclean:	default_realclean
default_realclean:	FORCE
	rm -f $(GARBAGE) $(PROGRAM) a.out core *.o *.i *.a *.so.* *.sa.* \
	    *.so *.u *.pure *.pure_hardlink *.pure_linkinfo conftest* \
	    test.out \
	    *.aux *.toc *.dvi \
	    config.cache *.Z *.log tags TAGS MANIFEST *~ \
	    Makefile config.status cc_id


############################################################################
# Configuration:
############################################################################

# The following target is touched because config.status won't update it if
# it hasn't changed.
#
# The following is commented-out because the HPUX make(1) goes into a loop.
#
#Makefile:	config.status
#	./config.status
#	touch $@

config.status:	cc_id configure
	./configure --no-create

cc_id:		FORCE
	if test -r $@ && test "`cat $@`" = "$(CC)"; then \
	    :; \
	else \
	    echo "$(CC)" > $@; \
	fi

# The following is commented-out because autoconf is currently only
# available on Zero.
#
#configure:		configure.in
#	autoconf


############################################################################
# Dependency maintenance:
############################################################################
.PRECIOUS:	depend
#
# Note: The following rule will only work if the C compiler behaves correctly
# when given the `-M' option.  AIX's cc(1) and SunOS's acc(1) behave
# incorrectly.  --Steve Emmerson 1992-09-24
#
# Furthermore, we do not attempt to maintain dependencies on installed
# header files (e.g. those in $(INCDIR)) for two reasons: 1) the dependency
# list generated at Unidata mightn't correspond to the situation at a client
# site; and 2) clients using broken compilers (c.f. previous note) can't
# regenerate the dependency list.
#
# We try to ensure that all C files exist in a distribution that
# includes fortc(1), yacc(1), or lex(1) sources.
#
depend:		FORCE
#	csrcs=`echo $(MANIFEST) | tr ' ' '\012' | egrep -s '\.fc|\.y|\.l'`; \
	if [ "$$csrcs" ]; then \
	    echo 1>&2 "Ensuring that all C files exist for target depend"; \
	    echo 1>&2 "csrcs = $$csrcs"; \
	    $(MAKE) $(MFLAGS) $$csrcs; \
	fi
	-incdir=`echo $(INCDIR) | sed s',/,\\\/,g'`; \
	(case $(OS) in \
	    aix*) \
		$(CC) -M -E $(CPPFLAGS) *.c > /dev/null; \
		cat *.u; \
		;; \
	    *) \
		$(CC_MAKEDEPEND) $(CPPFLAGS) *.c *.S 2> /dev/null; \
		;; \
	esac) | awk '{ \
		if ($$0 ~ /:/) { \
		    target	= $$1; \
		    if (target ~ /:/) { \
			target	= substr(target,1,length(target)-1); \
			start	= 2; \
		    } else { \
			start	= 3; \
		    } \
		} else { \
		    start	= 1; \
		} \
		for (i = start; i <= NF; ++i) { \
		    if ($$i !~ /^\\/ && \
			$$i !~ /port\// && \
			$$i !~ /^\//) \
		    { \
			if ($$i ~ /^\.\//) \
			    $$i = substr($$i, 3, 99); \
			print target ": " $$i \
		    } \
		} \
	    }' >>$@
	sort -u -o $@ $@
	tag='### DO NOT DELETE THIS LINE.  make depend DEPENDS ON IT ###'; \
	    sed -e "/^$$tag$$/r depend" \
		-e "/^$$tag$$/q" Makefile > Makefile.new
	mv Makefile.new Makefile


############################################################################
# Distributions:
############################################################################
FTPDIR		= /home/ftp/pub/udunits
FTPBINDIR	= /home/ftp/pub/binary/dummy_system
VERSION		= @VERSION@
TARFLAGS	= -chof

zip:		FORCE
	version=`cat VERSION | sed 's/\.//g;s/-//g`; \
	$(MAKE) $(MFLAGS) $(PACKAGE)$$version.zip VERSION=$$version

$(PACKAGE)$(VERSION).zip:	MANIFEST
	id=$(PACKAGE)$(VERSION) \
	&& rm -rf $$id \
	&& mkdir $$id \
	&& ln -s .. $$id/src \
	&& sed "s|^|$$id/src/|" MANIFEST | zip -@ $@ \
	&& rm -r $$id

tar.Z:		FORCE
	version=`cat VERSION`; \
	$(MAKE) $(MFLAGS) $(PACKAGE)-$$version.tar.Z VERSION=$$version

$(FTPDIR)/$(PACKAGE)-$(VERSION).tar.Z:	$(PACKAGE)-$(VERSION).tar.Z
	cp $(PACKAGE)-$(VERSION).tar.Z $@ 
	chmod u+rw,g+rw,o=r $@

ftp:		FORCE
	version=`cat VERSION`; \
	$(MAKE) $(MFLAGS) $(FTPDIR)/$(PACKAGE)-$$version.tar.Z \
	    VERSION=$$version; \
	test -r $(FTPDIR)/$(PACKAGE).tar.Z || exit 0; \
	    cd $(FTPDIR) || exit 1; \
	    rm $(PACKAGE).tar.Z || exit 1; \
	    ln -s $(PACKAGE)-$$version.tar.Z $(PACKAGE).tar.Z;

$(PACKAGE)-$(VERSION).tar.Z:	MANIFEST
	id=$(PACKAGE)-$(VERSION) \
	&& rm -rf $$id \
	&& mkdir $$id \
	&& ln -s .. $$id/src \
	&& tar $(TARFLAGS) - `sed "s|^|$$id/src/|" MANIFEST` | compress > $@ \
	&& rm -r $$id

binftp:		FORCE
	version=`cat VERSION`; \
	$(MAKE) $(MFLAGS) $(FTPBINDIR)/$(PACKAGE)-$$version.tar.Z \
	    VERSION=$$version
ftpbin:		binftp

$(FTPBINDIR)/$(PACKAGE)-$(VERSION).tar.Z:	FORCE
	id=$(PACKAGE)-$(VERSION) \
	&& rm -f $$id \
	&& ln -s $(prefix) $$id \
	&& tar $(TARFLAGS) - README $$id/bin $$id/doc $$id/etc $$id/include \
	    $$id/lib $$id/man | compress > $@ \
	&& rm $$id
	chmod u+rw,g+rw,o=r $@
	test -r $(FTPBINDIR)/$(PACKAGE).tar.Z || exit 0; \
	    cd $(FTPBINDIR) || exit 1; \
	    rm $(PACKAGE).tar.Z || exit 1; \
	    ln -s $(PACKAGE)-$(VERSION).tar.Z $(PACKAGE).tar.Z;

MANIFEST:	FORCE
	@echo 1>&2 Creating MANIFEST
	@$(MAKE) -s $(MFLAGS) MANIFEST.echo > $@

MANIFEST.echo:	FORCE
	@echo $(MANIFEST) | tr ' ' '\012'
	@if [ -n "$(SUBDIRS)" ]; then \
	    subdirs="$(SUBDIRS)"; \
	    for subdir in $$subdirs; do \
		(cd $$subdir && \
		echo 1>&2 Creating $@ in `pwd` && \
		$(MAKE) $(MFLAGS) MANIFEST.echo | \
		    sed "s|^|$$subdir/|") || exit 1; \
	    done; \
	else \
	    :; \
	fi

ensure_manifest:	FORCE
	@$(MAKE) $(MFLAGS) \
	    `echo $(MANIFEST) | sed 's/MANIFEST//'`
	@if [ -n "$(SUBDIRS)" ]; then \
	    subdirs="$(SUBDIRS)"; \
	    for subdir in $$subdirs; do \
		(cd $$subdir && \
		echo 1>&2 Creating $@ in `pwd` && \
		$(MAKE) $(MFLAGS) ensure_manifest ) || \
		    exit 1; \
	    done; \
	else \
	    :; \
	fi


############################################################################
# Miscellaneous:
############################################################################

# The following dummy target is useful as a dependency to ensure that a
# rule is always executed.
#
FORCE:

### Everything after the following line might be overwritten ###
### DO NOT DELETE THIS LINE.  make depend DEPENDS ON IT ###
alloca.o: alloca.c
atexit.o: atexit.c
atexit.o: stddef.h
atexit.o: stdlib.h
atexit.o: time.h
atexit.o: udposix.h
config.o: ./config.c
config.o: config.c
config.o: signal.h
config.o: stdarg.h
config.o: stddef.h
config.o: stdio.h
config.o: time.h
config.o: udposix.h
date.o: date.c
date.o: stdarg.h
date.o: stddef.h
date.o: stdio.h
date.o: time.h
date.o: udposix.h
difftime.o: difftime.c
difftime.o: stddef.h
difftime.o: time.h
difftime.o: udposix.h
getuduser.o: getuduser.c
getuduser.o: stdarg.h
getuduser.o: stddef.h
getuduser.o: stdio.h
getuduser.o: stdlib.h
getuduser.o: time.h
getuduser.o: udposix.h
histogram.o: histogram.c
histogram.o: histogram.h
histogram.o: limits.h
histogram.o: stdarg.h
histogram.o: stddef.h
histogram.o: stdio.h
histogram.o: stdlib.h
histogram.o: time.h
histogram.o: udposix.h
inetutil.o: inetutil.c
inetutil.o: inetutil.h
inetutil.o: limits.h
inetutil.o: stdarg.h
inetutil.o: stddef.h
inetutil.o: stdio.h
inetutil.o: string.h
inetutil.o: time.h
inetutil.o: udposix.h
linklist.o: linklist.c
linklist.o: linklist.h
linklist.o: stdarg.h
linklist.o: stddef.h
linklist.o: stdio.h
linklist.o: stdlib.h
linklist.o: string.h
linklist.o: time.h
linklist.o: udalloc.h
linklist.o: udposix.h
memmove.o: memmove.c
memmove.o: stddef.h
memmove.o: string.h
memmove.o: udposix.h
nanosleep.o: nanosleep.c
nanosleep.o: time.h
nanosleep.o: udposix.h
nanosleep.o: uthread.h
pathname.o: limits.h
pathname.o: pathname.c
pathname.o: stddef.h
pathname.o: string.h
pathname.o: udposix.h
regex.o: regex.c
regex.o: regex.h
regex.o: stddef.h
regex.o: stdlib.h
regex.o: string.h
regex.o: time.h
regex.o: udposix.h
setenv.o: setenv.c
setenv.o: stdarg.h
setenv.o: stddef.h
setenv.o: stdio.h
setenv.o: string.h
setenv.o: udposix.h
sigaction.o: sigaction.c
sigaction.o: signal.h
sigaction.o: stddef.h
sigaction.o: time.h
sigaction.o: udposix.h
sigaddset.o: sigaddset.c
sigaddset.o: signal.h
sigaddset.o: stddef.h
sigaddset.o: time.h
sigaddset.o: udposix.h
sigdelset.o: sigdelset.c
sigdelset.o: signal.h
sigdelset.o: stddef.h
sigdelset.o: time.h
sigdelset.o: udposix.h
sigdummy.o: sigdummy.c
sigdummy.o: signal.h
sigdummy.o: stddef.h
sigdummy.o: time.h
sigdummy.o: udposix.h
sigemptyset.o: sigemptyset.c
sigemptyset.o: signal.h
sigemptyset.o: stddef.h
sigemptyset.o: time.h
sigemptyset.o: udposix.h
sigfillset.o: sigfillset.c
sigfillset.o: signal.h
sigfillset.o: stddef.h
sigfillset.o: time.h
sigfillset.o: udposix.h
sigismember.o: sigismember.c
sigismember.o: signal.h
sigismember.o: stddef.h
sigismember.o: time.h
sigismember.o: udposix.h
sigpending.o: signal.h
sigpending.o: sigpending.c
sigpending.o: stddef.h
sigpending.o: time.h
sigpending.o: udposix.h
sigprocmask.o: signal.h
sigprocmask.o: sigprocmask.c
sigprocmask.o: stddef.h
sigprocmask.o: time.h
sigprocmask.o: udposix.h
sigsuspend.o: signal.h
sigsuspend.o: sigsuspend.c
sigsuspend.o: time.h
sigsuspend.o: udposix.h
strbuf.o: stdarg.h
strbuf.o: stddef.h
strbuf.o: stdio.h
strbuf.o: stdlib.h
strbuf.o: strbuf.c
strbuf.o: strbuf.h
strbuf.o: string.h
strbuf.o: time.h
strbuf.o: udalloc.h
strbuf.o: udposix.h
strerror.o: stddef.h
strerror.o: strerror.c
strerror.o: string.h
strerror.o: udposix.h
strftime.o: stdarg.h
strftime.o: stddef.h
strftime.o: stdio.h
strftime.o: strftime.c
strftime.o: string.h
strftime.o: time.h
strftime.o: udposix.h
strstr.o: stddef.h
strstr.o: string.h
strstr.o: strstr.c
strstr.o: udposix.h
strvec.o: stdarg.h
strvec.o: stddef.h
strvec.o: stdio.h
strvec.o: stdlib.h
strvec.o: string.h
strvec.o: strvec.c
strvec.o: strvec.h
strvec.o: time.h
strvec.o: udalloc.h
strvec.o: udposix.h
tdelete.o: search-node.h
tdelete.o: search.h
tdelete.o: stddef.h
tdelete.o: tdelete.c
tdelete.o: udposix.h
tfind.o: search-node.h
tfind.o: search.h
tfind.o: stddef.h
tfind.o: tfind.c
tfind.o: udposix.h
tsearch.o: search-node.h
tsearch.o: search.h
tsearch.o: stddef.h
tsearch.o: tsearch.c
tsearch.o: udposix.h
twalk.o: search-node.h
twalk.o: search.h
twalk.o: stddef.h
twalk.o: twalk.c
twalk.o: udposix.h
udalloc.o: stdarg.h
udalloc.o: stddef.h
udalloc.o: stdio.h
udalloc.o: stdlib.h
udalloc.o: string.h
udalloc.o: time.h
udalloc.o: udalloc.c
udalloc.o: udalloc.h
udalloc.o: udposix.h
uddummy.o: uddummy.c
uderrmsg.o: stdarg.h
uderrmsg.o: stddef.h
uderrmsg.o: stdio.h
uderrmsg.o: stdlib.h
uderrmsg.o: string.h
uderrmsg.o: time.h
uderrmsg.o: uderrmsg.c
uderrmsg.o: uderrmsg.h
uderrmsg.o: udposix.h
udfifo.o: stdarg.h
udfifo.o: stddef.h
udfifo.o: stdio.h
udfifo.o: stdlib.h
udfifo.o: string.h
udfifo.o: time.h
udfifo.o: udfifo.c
udfifo.o: udfifo.h
udfifo.o: udposix.h
udfifo.o: ulog.h
udfifo_err.o: stdarg.h
udfifo_err.o: stddef.h
udfifo_err.o: stdio.h
udfifo_err.o: stdlib.h
udfifo_err.o: time.h
udfifo_err.o: udfifo.h
udfifo_err.o: udfifo_err.c
udfifo_err.o: udposix.h
udqueue.o: stdarg.h
udqueue.o: stddef.h
udqueue.o: stdio.h
udqueue.o: stdlib.h
udqueue.o: time.h
udqueue.o: udfifo.h
udqueue.o: udposix.h
udqueue.o: udqueue.c
udqueue.o: udqueue.h
udqueue.o: ulog.h
udqueue.o: uthread.h
udqueue_err.o: signal.h
udqueue_err.o: stddef.h
udqueue_err.o: stdio.h
udqueue_err.o: stdlib.h
udqueue_err.o: time.h
udqueue_err.o: udfifo.h
udqueue_err.o: udposix.h
udqueue_err.o: udqueue.h
udqueue_err.o: udqueue_err.c
udqueue_err.o: uthread.h
ulog.o: inetutil.h
ulog.o: signal.h
ulog.o: stdarg.h
ulog.o: stddef.h
ulog.o: stdio.h
ulog.o: string.h
ulog.o: time.h
ulog.o: udposix.h
ulog.o: ulog.c
ulog.o: ulog.h
usleep.o: stddef.h
usleep.o: time.h
usleep.o: udposix.h
usleep.o: usleep.c
uthread.o: stddef.h
uthread.o: stdio.h
uthread.o: time.h
uthread.o: udposix.h
uthread.o: uthread.c
uthread.o: uthread.h
