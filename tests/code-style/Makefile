# Root directory
BUILDROOT = ../..

# Build directory
BUILD_DIR = build

# Depth to search for C file
MODULES = * */* */*/* */*/*/* */*/*/*/* */*/*/*/*/*

# Source directories
SOURCE_DIRS = $(addprefix $(BUILDROOT)/, $(MODULES))

# C source files
SOURCE_C += $(foreach d, $(SOURCE_DIRS), $(subst $(d)/,,$(wildcard $(d)/*.c)))

# Fake objects to enable the %.o: %.c rule
OBJECTS += $(foreach m, $(SOURCE_C), $(addprefix $(BUILD_DIR)/, $(addsuffix .o,$(basename $(m)))))

# Vpath to allow out-of-tree build
vpath %.c $(SOURCE_DIRS)

all run check: $(OBJECTS)

$(BUILD_DIR)/%.o: %.c
	uncrustify -q -c $(BUILDROOT)/etc/uncrustify/uncrustify.cfg -f $< | diff -u $< --to-file=/dev/stdin
