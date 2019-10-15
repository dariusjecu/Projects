# File: Makefile
# Author: Benedict R. Gaster
# Date: 9th June 2017
# Desc: Makefile for all examples in this folder. Note that
#       it is possible automatically add a new challenge using the
#       create_challenge.sh script (found in ../templates/challenges) and
#       for this to work correclty there are placeholders in this file:
#
# Copyright: University of West of England 2017
#
ifeq ($(origin ROOTDIR), undefined)
	ROOTDIR=..
endif
include $(ROOTDIR)/MakefileDefs.inc

DIRS = ${add_challenge}

all: ${add_challenge}

# insert new build rule (do not remove this!!!)
001: force_look
	$(ECHO) looking into 001 : $(MAKE) $(MFLAGS)
	cd 001; $(MAKE) $(MFLAGS)

# insert new build rule (do not remove this!!!)
${add_challenge_rule}

install:
	$(ECHO) installing up in .
	-for d in $(DIRS); do (cd $$d; $(MAKE) install ); done

clean:
	$(ECHO) cleaning up in .
	-for d in $(DIRS); do (cd $$d; $(MAKE) clean ); done

force_look:
	true
