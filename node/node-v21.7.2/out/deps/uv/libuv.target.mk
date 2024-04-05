# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := libuv
DEFS_Debug := \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-DNODE_OPENSSL_CONF_NAME=nodejs_conf' \
	'-DNODE_OPENSSL_HAS_QUIC' \
	'-DICU_NO_USER_DATA_OVERRIDE' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-D_GNU_SOURCE' \
	'-DDEBUG' \
	'-D_DEBUG'

# Flags passed to all source files.
CFLAGS_Debug := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-fvisibility=hidden \
	-g \
	--std=gnu89 \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-Wstrict-prototypes \
	-fno-strict-aliasing \
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
	-I$(srcdir)/deps/uv/include \
	-I$(srcdir)/deps/uv/src

DEFS_Release := \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-DNODE_OPENSSL_CONF_NAME=nodejs_conf' \
	'-DNODE_OPENSSL_HAS_QUIC' \
	'-DICU_NO_USER_DATA_OVERRIDE' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-D_GNU_SOURCE'

# Flags passed to all source files.
CFLAGS_Release := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-fvisibility=hidden \
	-g \
	--std=gnu89 \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-Wstrict-prototypes \
	-fno-strict-aliasing \
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
	-I$(srcdir)/deps/uv/include \
	-I$(srcdir)/deps/uv/src

OBJS := \
	$(obj).target/$(TARGET)/deps/uv/src/fs-poll.o \
	$(obj).target/$(TARGET)/deps/uv/src/idna.o \
	$(obj).target/$(TARGET)/deps/uv/src/inet.o \
	$(obj).target/$(TARGET)/deps/uv/src/random.o \
	$(obj).target/$(TARGET)/deps/uv/src/strscpy.o \
	$(obj).target/$(TARGET)/deps/uv/src/strtok.o \
	$(obj).target/$(TARGET)/deps/uv/src/thread-common.o \
	$(obj).target/$(TARGET)/deps/uv/src/threadpool.o \
	$(obj).target/$(TARGET)/deps/uv/src/timer.o \
	$(obj).target/$(TARGET)/deps/uv/src/uv-data-getter-setters.o \
	$(obj).target/$(TARGET)/deps/uv/src/uv-common.o \
	$(obj).target/$(TARGET)/deps/uv/src/version.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/async.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/core.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/dl.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/fs.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/getaddrinfo.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/getnameinfo.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/loop.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/loop-watcher.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/pipe.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/poll.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/process.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/random-devurandom.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/signal.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/stream.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/tcp.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/thread.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/tty.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/udp.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/proctitle.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/linux.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/procfs-exepath.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/random-getrandom.o \
	$(obj).target/$(TARGET)/deps/uv/src/unix/random-sysctl-linux.o

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

$(obj).target/deps/uv/libuv.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/deps/uv/libuv.a: LIBS := $(LIBS)
$(obj).target/deps/uv/libuv.a: TOOLSET := $(TOOLSET)
$(obj).target/deps/uv/libuv.a: $(OBJS)
	$(call create_thin_archive,$@,$^)

# Add target alias
.PHONY: libuv
libuv: $(obj).target/deps/uv/libuv.a

# Add target alias to "all" target.
.PHONY: all
all: libuv

