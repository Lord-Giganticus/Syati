SOURCES = build

OFILES := $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.o))

.PHONEY: all

all: 
	@echo $(OFILES)