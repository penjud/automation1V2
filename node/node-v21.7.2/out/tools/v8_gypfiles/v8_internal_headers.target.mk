# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := v8_internal_headers
DEFS_Debug := \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-DNODE_OPENSSL_CONF_NAME=nodejs_conf' \
	'-DNODE_OPENSSL_HAS_QUIC' \
	'-DICU_NO_USER_DATA_OVERRIDE' \
	'-DV8_GYP_BUILD' \
	'-DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DV8_TARGET_ARCH_X64' \
	'-DV8_HAVE_TARGET_OS' \
	'-DV8_TARGET_OS_LINUX' \
	'-DV8_EMBEDDER_STRING="-node.20"' \
	'-DENABLE_DISASSEMBLER' \
	'-DV8_PROMISE_INTERNAL_FIELD_COUNT=1' \
	'-DV8_ENABLE_PRIVATE_MAPPING_FORK_OPTIMIZATION' \
	'-DV8_SHORT_BUILTIN_CALLS' \
	'-DOBJECT_PRINT' \
	'-DV8_INTL_SUPPORT' \
	'-DV8_ATOMIC_OBJECT_FIELD_WRITES' \
	'-DV8_ENABLE_LAZY_SOURCE_POSITIONS' \
	'-DV8_USE_SIPHASH' \
	'-DV8_SHARED_RO_HEAP' \
	'-DV8_WIN64_UNWINDING_INFO' \
	'-DV8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH' \
	'-DV8_USE_ZLIB' \
	'-DV8_ENABLE_TURBOFAN' \
	'-DV8_ENABLE_WEBASSEMBLY' \
	'-DV8_ENABLE_JAVASCRIPT_PROMISE_HOOKS' \
	'-DV8_ALLOCATION_FOLDING' \
	'-DV8_ALLOCATION_SITE_TRACKING' \
	'-DV8_ADVANCED_BIGINT_ALGORITHMS' \
	'-DUCONFIG_NO_SERVICE=1' \
	'-DU_ENABLE_DYLOAD=0' \
	'-DU_STATIC_IMPLEMENTATION=1' \
	'-DU_HAVE_STD_STRING=1' \
	'-DUCONFIG_NO_BREAK_ITERATION=0' \
	'-DDEBUG' \
	'-D_DEBUG' \
	'-DV8_ENABLE_CHECKS' \
	'-DV8_TRACE_MAPS' \
	'-DV8_ENABLE_ALLOCATION_TIMEOUT' \
	'-DV8_ENABLE_FORCE_SLOW_PATH' \
	'-DENABLE_HANDLE_ZAPPING'

# Flags passed to all source files.
CFLAGS_Debug := \
	-pthread \
	-Wno-unused-parameter \
	-Wno-return-type \
	-flax-vector-conversions \
	-Wno-invalid-offsetof \
	-fno-strict-aliasing \
	-m64 \
	-m64 \
	-g \
	-fdata-sections \
	-ffunction-sections \
	-O3

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++17

INCS_Debug := \
	-I$(srcdir)/deps/v8 \
	-I$(srcdir)/deps/v8/include \
	-I$(srcdir)/deps/icu-small/source/i18n \
	-I$(srcdir)/deps/icu-small/source/common \
	-I$(obj)/gen/generate-bytecode-output-root \
	-I$(obj)/gen

DEFS_Release := \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-DNODE_OPENSSL_CONF_NAME=nodejs_conf' \
	'-DNODE_OPENSSL_HAS_QUIC' \
	'-DICU_NO_USER_DATA_OVERRIDE' \
	'-DV8_GYP_BUILD' \
	'-DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DV8_TARGET_ARCH_X64' \
	'-DV8_HAVE_TARGET_OS' \
	'-DV8_TARGET_OS_LINUX' \
	'-DV8_EMBEDDER_STRING="-node.20"' \
	'-DENABLE_DISASSEMBLER' \
	'-DV8_PROMISE_INTERNAL_FIELD_COUNT=1' \
	'-DV8_ENABLE_PRIVATE_MAPPING_FORK_OPTIMIZATION' \
	'-DV8_SHORT_BUILTIN_CALLS' \
	'-DOBJECT_PRINT' \
	'-DV8_INTL_SUPPORT' \
	'-DV8_ATOMIC_OBJECT_FIELD_WRITES' \
	'-DV8_ENABLE_LAZY_SOURCE_POSITIONS' \
	'-DV8_USE_SIPHASH' \
	'-DV8_SHARED_RO_HEAP' \
	'-DV8_WIN64_UNWINDING_INFO' \
	'-DV8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH' \
	'-DV8_USE_ZLIB' \
	'-DV8_ENABLE_TURBOFAN' \
	'-DV8_ENABLE_WEBASSEMBLY' \
	'-DV8_ENABLE_JAVASCRIPT_PROMISE_HOOKS' \
	'-DV8_ALLOCATION_FOLDING' \
	'-DV8_ALLOCATION_SITE_TRACKING' \
	'-DV8_ADVANCED_BIGINT_ALGORITHMS' \
	'-DUCONFIG_NO_SERVICE=1' \
	'-DU_ENABLE_DYLOAD=0' \
	'-DU_STATIC_IMPLEMENTATION=1' \
	'-DU_HAVE_STD_STRING=1' \
	'-DUCONFIG_NO_BREAK_ITERATION=0'

# Flags passed to all source files.
CFLAGS_Release := \
	-pthread \
	-Wno-unused-parameter \
	-Wno-return-type \
	-flax-vector-conversions \
	-Wno-invalid-offsetof \
	-fno-strict-aliasing \
	-m64 \
	-m64 \
	-O3 \
	-fno-omit-frame-pointer \
	-fdata-sections \
	-ffunction-sections \
	-O3

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++17

INCS_Release := \
	-I$(srcdir)/deps/v8 \
	-I$(srcdir)/deps/v8/include \
	-I$(srcdir)/deps/icu-small/source/i18n \
	-I$(srcdir)/deps/icu-small/source/common \
	-I$(obj)/gen/generate-bytecode-output-root \
	-I$(obj)/gen

OBJS :=

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# Make sure our dependencies are built before any of us.
$(OBJS): | $(obj).target/tools/v8_gypfiles/torque_runtime_support.stamp $(obj).target/tools/v8_gypfiles/v8_flags.stamp $(obj).target/tools/v8_gypfiles/v8_headers.stamp $(obj).target/tools/v8_gypfiles/v8_maybe_icu.stamp $(obj).target/tools/v8_gypfiles/v8_shared_internal_headers.stamp $(obj).target/tools/v8_gypfiles/v8_heap_base_headers.stamp $(obj).target/tools/v8_gypfiles/generate_bytecode_builtins_list.stamp $(obj).target/tools/v8_gypfiles/run_torque.stamp $(obj).target/tools/v8_gypfiles/libv8_libbase.a


### Rules for final target.
$(obj).target/tools/v8_gypfiles/v8_internal_headers.stamp: TOOLSET := $(TOOLSET)
$(obj).target/tools/v8_gypfiles/v8_internal_headers.stamp: $(obj).target/tools/v8_gypfiles/torque_runtime_support.stamp $(obj).target/tools/v8_gypfiles/v8_flags.stamp $(obj).target/tools/v8_gypfiles/v8_headers.stamp $(obj).target/tools/v8_gypfiles/v8_maybe_icu.stamp $(obj).target/tools/v8_gypfiles/v8_shared_internal_headers.stamp $(obj).target/tools/v8_gypfiles/v8_heap_base_headers.stamp $(obj).target/tools/v8_gypfiles/generate_bytecode_builtins_list.stamp $(obj).target/tools/v8_gypfiles/run_torque.stamp $(obj).target/tools/v8_gypfiles/libv8_libbase.a FORCE_DO_CMD
	$(call do_cmd,touch)

all_deps += $(obj).target/tools/v8_gypfiles/v8_internal_headers.stamp
# Add target alias
.PHONY: v8_internal_headers
v8_internal_headers: $(obj).target/tools/v8_gypfiles/v8_internal_headers.stamp

# Add target alias to "all" target.
.PHONY: all
all: v8_internal_headers

