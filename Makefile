
SHELL = /bin/sh
NAME = all
MAKEFILE = Makefile 

#ROOT_INCLUDES  = -I$(shell root-config --incdir)
#ROOT_LIBRARIES = $(shell root-config --glibs) -lMinuit -lGeom -lEG
#
#INCLUDES  = $(ROOT_INCLUDES)
#LIBRARIES := $(SYSLIBS) \
#      $(ROOT_LIBRARIES) \
#
#CXX = g++
#LD  = g++
#
#CXXFLAGS      = -m32 -pipe -W -Wall \
#  -fsigned-char -fno-common -undefined warning
##  -fsigned-char -fno-common -flat_namespace -undefined warning
#
#ifeq ($(strip $(GCC_GE_4_1_0)), YES) 
#  CXXFLAGS += -Wno-strict-aliasing -ffriend-injection
#else
##  CXXFLAGS += -Wno-long-double
#endif
#
##LDFLAGS       = -m32 -bind_at_load -undefined warning
#LDFLAGS       = -m32 -undefined warning
#
CXX=g++
LD=g++
CXXFLAGS=-g -c -fpic -Wall `root-config --cflags`
LDFLAGS=-g `root-config --glibs` 

MKDIR_P = mkdir -p

SRC=$(wildcard src/*.cxx)
OBJ=$(patsubst %.cxx,%.o,$(SRC))
OBJDIR=$(addprefix lib/,$(notdir $(OBJ)))



all: directories directories_exe $(OBJDIR) so Selection

lib/%.o: src/%.cxx
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

so:
	@echo "Compiling shared object"
	@$(LD) -shared -o lib/libSelection.so lib/*.o

Selection:
	@echo "Compiling Selection"
	@$(CXX) $(CXXFLAGS) -Isrc -c app/runSelection.cxx -o lib/exe/runSelection.o 
	@$(LD) $(LDFLAGS) -Llib -Wl,-rpath=/dune/app/users/dbrailsf/diffusion/selection/soft/lib lib/exe/runSelection.o -o Selection.exe -lSelection 

directories:
	@$(MKDIR_P) lib

directories_exe:
	@$(MKDIR_P) lib/exe

clean:
	@echo "Cleaning libraries and executables"
	@rm  -r lib *.exe
