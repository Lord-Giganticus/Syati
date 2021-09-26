#This Makefile only exits in order to properly list the .o files in Build.cmd

SOURCES = $(CURDIR)

OFILES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.o)))

.PHONEY: all

all: 
	@echo $(OFILES)