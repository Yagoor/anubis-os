# C source files
SOURCE_C += $(APP_C)

BOARD = unittest

C_FLAGS += -fprofile-arcs -ftest-coverage
LDFLAGS += -lcmocka -lgcov --coverage

TARGETS = $(BUILD_DIR)/$(APPNAME)

run: all
	$(TARGETS) > $(BUILD_DIR)/$(APPNAME).xml

check: run
	@if [ "${shell xmllint --xpath 'string(//testsuites/testsuite/@failures)' $(BUILD_DIR)/$(APPNAME).xml}" != "0" ]; then cat $(BUILD_DIR)/$(APPNAME).xml && exit 1; fi

# Include unittest Makefile
include $(BUILDROOT)/base.mk