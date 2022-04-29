#Global Variables, REG is set from command line
CXX := ../CodeWarrior/mwcceppc
CXX_FLAGS := -i . -I- -i ../include -Cpp_exceptions off -enum int -O4,s -use_lmw_stmw on -fp hard \
	-func_align 4 -str pool -rostr -sdata 0 -sdata2 0 -D$(REG) -c
CPPFILES := $(wildcard *.cpp)
OBJECTS := $(addsuffix .o, $(basename $(CPPFILES)))
LD := ../Kamek/Kamek.exe
LD_FLAGS := -static=0x80001800 -output-riiv=out/riivo_$(REG).xml -input-dol=../dols/$(REG).dol \
	-output-dol=out/$(REG).dol
TARGET = out/riivo_$(REG).dol
PROGRAMS := $(CXX) $(LD)

all: check $(TARGET)

$(TARGET):
	$(CXX) $(CXX_FLAGS) $(CPPFILES)
	mkdir -p out
	$(LD) $(OBJECTS) $(LD_FLAGS)
	rm *.o

$(PROGRAMS):
	cd ../; ./syatisetup.exe

clean:
	rm -rf out

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