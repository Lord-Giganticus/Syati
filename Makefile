#This Makefile only exits in order to properly list the .o files in Build.cmd

SOURCES = build

OFILES := $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.o))

.PHONEY: all

all: 
	@echo $(OFILES)
