#Global Variables, REG is set from command line
TARGET := CustomCode_$(REG).bin
CPPFILES := $(wildcard Source/*.cpp) $(wildcard Source/*/*.cpp)
OBJECTS := $(addprefix Build/, $(addsuffix .o, $(notdir $(basename $(CPPFILES)))))
CXX := CodeWarrior\mwcceppc.exe
CXX_FLAGS := -i . -I- -i include -nodefaults -proc gekko -Cpp_exceptions off -enum int -O4,s \
	-fp hard -func_align 4 -str pool -sdata 0 -sdata2 0 -D$(REG) -DGEKKO -DMTX_USE_PS -MMD -rtti off -c
LD := Kamek\Kamek.exe
LD_FLAGS := -externals=symbols/$(REG).txt -output-kamek=$(TARGET)
PROGRAMS = $(CXX) $(LD)

all: check $(TARGET)

$(TARGET):
	mkdir -p Build
	$(CXX) $(CXX_FLAGS) $(CPPFILES)
	mv *.o Build
	rm *.d
	$(LD) $(OBJECTS) $(LD_FLAGS)

# Yes, this is JUST IN CASE to make run this if CodeWarrior or Kamek are missing.
$(PROGRAMS):
	.\syatisetup.exe

clean:
	rm $(TARGET) $(OBJECTS)

check: $(PROGRAMS)

USA:
	$(MAKE) REG=$@

PAL:
	$(MAKE) REG=$@

JAP:
	$(MAKE) REG=$@

KOR:
	$(MAKE) REG=$@

TWN:
	$(MAKE) REG=$@

ALL: USA PAL JAP KOR TWN