#Global Variables, REG is set from command line
TARGET := CustomCode_$(REG).bin
CPPFILES := $(foreach dir,Source,$(wildcard $(dir)/*.cpp)) $(foreach dir, Source,$(wildcard $(dir)/*/*.cpp))
OBJECTS := $(addprefix Build/, $(addsuffix .o, $(notdir $(basename $(CPPFILES)))))
CXX := CodeWarrior\mwcceppc.exe
CXX_FLAGS := -i . -I- -i include -nodefaults -proc gekko -Cpp_exceptions off -enum int -O4,s -fp hard -func_align 4 -str pool -sdata 0 -sdata2 0 -D$(REG) -DGEKKO -DMTX_USE_PS -MMD -rtti off -c
LD := Kamek\Kamek.exe
LD_FLAGS := -externals=symbols/$(REG).txt -output-kamek=$(TARGET)
PROGRAMS = $(CXX) $(LD)

all: $(PROGRAMS) $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p Build
	$(CXX) $(CXX_FLAGS) $(CPPFILES)
	mv *.o Build
	rm *.d
	$(LD) $^ $(LD_FLAGS)

# Yes, this is JUST IN CASE to make run this if CodeWarrior or Kamek are missing.
$(PROGRAMS):
	.\syatisetup.exe

clean:
	rm $(TARGET) $(OBJECTS)

check: $(PROGRAMS)