# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := base64_sse42
DEFS_Debug := \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-DNODE_OPENSSL_CONF_NAME=nodejs_conf' \
	'-DNODE_OPENSSL_HAS_QUIC' \
	'-DICU_NO_USER_DATA_OVERRIDE' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DBASE64_STATIC_DEFINE' \
	'-DHAVE_SSE42=1' \
	'-DDEBUG' \
	'-D_DEBUG'

# Flags passed to all source files.
CFLAGS_Debug := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-msse4.2 \
	-m64 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++17

INCS_Debug := \
	-I$(srcdir)/deps/base64/base64/include \
	-I$(srcdir)/deps/base64/base64/lib

DEFS_Release := \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-DNODE_OPENSSL_CONF_NAME=nodejs_conf' \
	'-DNODE_OPENSSL_HAS_QUIC' \
	'-DICU_NO_USER_DATA_OVERRIDE' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DBASE64_STATIC_DEFINE' \
	'-DHAVE_SSE42=1'

# Flags passed to all source files.
CFLAGS_Release := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-msse4.2 \
	-m64 \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++17

INCS_Release := \
	-I$(srcdir)/deps/base64/base64/include \
	-I$(srcdir)/deps/base64/base64/lib

OBJS := \
	$(obj).target/$(TARGET)/deps/base64/base64/lib/arch/sse42/codec.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64

LIBS :=

$(obj).target/deps/base64/libbase64_sse42.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/deps/base64/libbase64_sse42.a: LIBS := $(LIBS)
$(obj).target/deps/base64/libbase64_sse42.a: TOOLSET := $(TOOLSET)
$(obj).target/deps/base64/libbase64_sse42.a: $(OBJS)
	$(call create_thin_archive,$@,$^)

# Add target alias
.PHONY: base64_sse42
base64_sse42: $(obj).target/deps/base64/libbase64_sse42.a

# Add target alias to "all" target.
.PHONY: all
all: base64_sse42

