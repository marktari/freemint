#
# Makefile for XaAES loader
#

SHELL = /bin/sh
SUBDIRS = 

srcdir = .
top_srcdir = ..
subdir = xaloader

default: all-here

include $(srcdir)/XALOADDEFS

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
	for i in $(xaloadtargets); do \
		echo "Making $$i"; \
		($(MAKE) $$i) \
		|| case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"

$(xaloadtargets):
	$(MAKE) buildxaload xaload=$@

#
# multi target stuff
#

ifneq ($(xaload),)

compile_dir = .compile_$(xaload)
xaloadtarget = _stmp_$(xaload)
realtarget = $(xaloadtarget)

$(xaloadtarget): $(compile_dir)
	cd $(compile_dir); $(MAKE) all

$(compile_dir): Makefile.objs
	$(MKDIR) -p $@
	$(CP) $< $@/Makefile

else

realtarget =

endif

buildxaload: $(realtarget)
