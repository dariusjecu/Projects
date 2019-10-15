# File: Makefile
# Author: Darius Jecu
# Date: 20-10-2017
#
# Copyright: University of West of England 2017
#
ifeq ($(origin ROOTDIR), undefined)
	ROOTDIR=../..
endif
include $(ROOTDIR)/MakefileDefs.inc

# Build path
BUILD_DIR = build

TARGET = crack
CPP_SOURCES = main.cpp

#######################################
# build the application
#######################################
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o))) -lcrypt
vpath %.cpp $(sort $(dir $(CPP_SOURCES)))

CFLAGS += -I$(INCDIR) -I$(JUCEINSTALL)/modules

LIBS =  $(LIBDIR)/libgraphics.a $(JUCELIB) $(LIBDIR)/libufcfgl-30-1.a

$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET): $(OBJECTS) $(LIBS) Makefile
	$(CC) $(OBJECTS) $(LIBS) $(LINUXLIBFALGS) $(LDFLAGS) -o $@

$(BUILD_DIR):
	mkdir -p $@

#######################################
# install
#######################################
install:


#######################################
# clean up
#######################################
clean:
	-rm -fR .dep $(BUILD_DIR)

#######################################
# dependencies
#######################################
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

.PHONY: clean all
