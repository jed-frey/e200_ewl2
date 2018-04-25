#
# Tools definition 
#

# Reset environment vars you explicitly want to override
#
export MWCIncludes=

# Library file suffix
#
LIBTYPE = .a

# Library file output path
#
LIBOUT = ../lib

# Object file suffix
#
OBJTYPE = .o

# Object file output path (relative to target directory)
#
OBJOUT = obj

# Root directory for all generated command line output
#
OBJDATA_ROOT = EWL_Cpp.$(PLATFORM)-GCC_CmdLineData

# Common include directories, note -I- required if system directories are to
# be searched ( <> type includes )
#
INCLUDE_ROOT = ../
INCLUDE = -nostdinc -nostdinc++ -isystem $(INCLUDE_ROOT)/EWL_C++/include
INCLUDE += -isystem $(INCLUDE_ROOT)/EWL_C/include 
SYSINCL = $(INCLUDE)

cwd = $(CURDIR)
CD := cd

#GNU make 3.82 defines only SHELL when running the dos shell
#while 3.81 defines SHELL and COMSPEC when running cygwin
ifdef SHELL
SEPARATOR = ;
MKDIR = mkdir -p $(1)
ZPATH = $(1)
RMDIR = rm -fr $(1)
RM    = rm $(1)
else
# stuck will DOS
SEPARATOR := &
MKDIR = if not exist $(1) (md $(1))
RMDIR = if exist $(1) (rd /s /q $(1))
RM = for %%f in ($(1)) do if exist %%f (del /f /q /s %%f)
ZPATH = $(subst /,\,$(1))
endif

ifneq (,$(findstring cygdrive,$(cwd)))
	cwd := $(shell cygpath -m $(CURDIR))
endif

#
# Common build flags
#
CXFLAGS	=   $(PLATFORM_FLAGS) -ffunction-sections -fdata-sections  -fdebug-prefix-map="$(cwd)"="$(DEBUG_PREFIX)/EWL_C++" -fno-threadsafe-statics -fno-use-cxa-atexit -frtti -std=c++0x -c $(SYSINCL)
ARFLAGS	=   -r


# include makefiles that define platform variables.
-include config.$(PLATFORM)-GCC.mak

# Compile and Link command variables
COMPILE = $(CC)
LINK = $(AR)

# Search paths for files
#
vpath %.cpp ./src

# Determine the library components
#
ALLFILES = $(wildcard ./src/*.cpp)
CFILES := $(PLATFORM_CFILES) 

# Filter ALLFILES for excluded files here
#

CFILES :=
CPPFILES := $(ALLFILES) $(PLATFORM_CPPFILES) 
ASMFILES :=

# Create the object file names
#
COBJS = $(addsuffix $(OBJTYPE),$(notdir $(basename $(CFILES))))
CPPOBJS = $(addsuffix $(OBJTYPE),$(notdir $(basename $(CPPFILES))))
ASMOBJS = $(addsuffix $(OBJTYPE),$(notdir $(basename $(ASMFILES))))

# Define the target makefile name
#
TARGET_MAK = EWL_C++.GCC.mak
TARGETS = $(PLATFORM_TARGETS_CPP) $(PLATFORM_TARGETS_STDCPP)


# The common makefile will try to make all targets by recursively calling
# make TARGET=<targetname>. This creates a target consisting of the library
# name with dependencies consisting of all the objects from FILES. A static
# pattern rule defines the .c files for the dependencies of the .o files.
#

# Main target and default target, dependencies expand to 
# e.g. ../lib/<targetname>.a
#
ifndef TARGET
all: $(TARGETS)

libcpp: $(PLATFORM_TARGETS_CPP)

libstdcpp: $(PLATFORM_TARGETS_STDCPP)


$(TARGETS):
	"$(MAKE)" -j6 -f $(TARGET_MAK) TARGET=$@
endif


COBJECTS   = $(addprefix $(OBJDATA_ROOT)/$(TARGET)/$(OBJOUT)/, $(COBJS))
CPPOBJECTS = $(addprefix $(OBJDATA_ROOT)/$(TARGET)/$(OBJOUT)/, $(CPPOBJS))

# Set up target lib object dependencies, e.g. ../Lib/<target>.a : <object dependencies>
#
$(addprefix $(LIBOUT)/, $(addsuffix $(LIBTYPE),$(TARGET))) : $($(TARGET)OBJECTS)
	$(CD) "$(OBJDATA_ROOT)/$(TARGET)/$(OBJOUT)" $(SEPARATOR) $(AR) $(ARFLAGS) "$(cwd)"/$@ $(LFLAGS) $(subst $(OBJDATA_ROOT)/$(TARGET)/$(OBJOUT)/,,$^)

$(OBJDATA_ROOT)/$(TARGET)/$(OBJOUT):
	$(call MKDIR,$(call ZPATH,$(dir $(LIBOUT)/$(TARGET))))
	$(call MKDIR,$(call ZPATH,$@))

# Set up object dependencies, e.g. CmdLine/<target>/obj/file.o : file.c
#

$(COBJECTS) : $(OBJDATA_ROOT)/$(TARGET)/$(OBJOUT)/%.o : %.c | $(OBJDATA_ROOT)/$(TARGET)/$(OBJOUT)
	$(COMPILE) $(CFLAGS) "$<" -o "$@"

$(CPPOBJECTS) : $(OBJDATA_ROOT)/$(TARGET)/$(OBJOUT)/%.o : %.cpp | $(OBJDATA_ROOT)/$(TARGET)/$(OBJOUT)
	$(COMPILE) $(CFLAGS) "$<" -o "$@" 

clean:
# Remove generated data files 
#
	-rm -rf $(OBJDATA_ROOT)

# Remove library files
#
	-rm -rf $(addprefix $(LIBOUT)/, $(addsuffix $(LIBTYPE),$(TARGETS)))

cleanobj:
# Leave the library files intact,  clean up the object files
#
	-rm -rf $(OBJDATA_ROOT)
