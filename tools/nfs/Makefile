#
# Makefile for nfs
#

SHELL = /bin/sh
SUBDIRS = 

srcdir = .
top_srcdir = ..
subdir = nfs

default: all-here

include $(srcdir)/NFSDEFS

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
	for i in $(nfstargets); do \
		echo "Making $$i"; \
		($(MAKE) $$i) \
		|| case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"

$(nfstargets):
	$(MAKE) buildnfs nfs=$@

#
# multi target stuff
#

ifneq ($(nfs),)

compile_dir = .compile_$(nfs)
nfstarget = _stmp_$(nfs)
realtarget = $(nfstarget)

$(nfstarget): $(compile_dir)
	cd $(compile_dir); $(MAKE) all

$(compile_dir): Makefile.objs
	$(MKDIR) -p $@
	$(CP) $< $@/Makefile

else

realtarget =

endif

buildnfs: $(realtarget)
