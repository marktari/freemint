#
# Makefile for crypt I/O initialization
#

SHELL = /bin/sh
SUBDIRS = 

srcdir = .
top_srcdir = ..
subdir = crypto

default: all-here

include $(srcdir)/CRYPTODEFS

include $(top_srcdir)/CONFIGVARS
include $(top_srcdir)/RULES
include $(top_srcdir)/PHONY

all-here: all-targets

# default overwrites

# default definitions
compile_all_dirs = .compile_*
GENFILES = $(compile_all_dirs)


all-targets:
	@set fnord $(MAKEFLAGS); amf=$$2; \
	for i in $(cryptotargets); do \
		echo "Making $$i"; \
		($(MAKE) $$i) \
		|| case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"

$(cryptotargets):
	$(MAKE) buildcrypto crypto=$@

#
# multi target stuff
#

ifneq ($(crypto),)

compile_dir = .compile_$(crypto)
cryptotarget = _stmp_$(crypto)
realtarget = $(cryptotarget)

$(cryptotarget): $(compile_dir)
	cd $(compile_dir); $(MAKE) all

$(compile_dir): Makefile.objs
	$(MKDIR) -p $@
	$(CP) $< $@/Makefile

else

realtarget =

endif

buildcrypto: $(realtarget)
