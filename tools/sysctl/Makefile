#
# Makefile for the syctl system tool
#

SHELL = /bin/sh
SUBDIRS = 

srcdir = .
top_srcdir = ..
subdir = sysctl

default: all-here

include $(srcdir)/SYSCTLDEFS

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
	for i in $(sysctltargets); do \
		echo "Making $$i"; \
		($(MAKE) $$i) \
		|| case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"

$(sysctltargets):
	$(MAKE) buildsysctl sysctl=$@

#
# multi target stuff
#

ifneq ($(sysctl),)

compile_dir = .compile_$(sysctl)
sysctltarget = _stmp_$(sysctl)
realtarget = $(sysctltarget)

$(sysctltarget): $(compile_dir)
	cd $(compile_dir); $(MAKE) all

$(compile_dir): Makefile.objs
	$(MKDIR) -p $@
	$(CP) $< $@/Makefile

else

realtarget =

endif

buildsysctl: $(realtarget)
