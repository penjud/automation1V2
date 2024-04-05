# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := v8_snapshot
### Rules for action "run_mksnapshot":
quiet_cmd__home_penjud_vscode_projects_automation1V2_node_node_v21_7_2_tools_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot = ACTION generating: "$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc" "$(obj).$(TOOLSET)/$(TARGET)/geni/embedded.S" $@
cmd__home_penjud_vscode_projects_automation1V2_node_node_v21_7_2_tools_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot = LD_LIBRARY_PATH=$(builddir)/lib.host:$(builddir)/lib.target:$$LD_LIBRARY_PATH; export LD_LIBRARY_PATH; cd $(srcdir)/tools/v8_gypfiles; mkdir -p $(obj).$(TOOLSET)/v8_snapshot/geni; "$(builddir)/mksnapshot" --turbo_instruction_scheduling "--target_os=linux" "--target_arch=x64" --startup_src "$(obj).$(TOOLSET)/v8_snapshot/geni/snapshot.cc" --embedded_variant Default --embedded_src "$(obj).$(TOOLSET)/v8_snapshot/geni/embedded.S" --no-native-code-counters

$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc: obj := $(abs_obj)
$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc: builddir := $(abs_builddir)
$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc: TOOLSET := $(TOOLSET)
$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc $(obj).$(TOOLSET)/$(TARGET)/geni/embedded.S: 28b0b88980777ed64da8677f804531a72fc7b36a.intermediate
	@:
.INTERMEDIATE: 28b0b88980777ed64da8677f804531a72fc7b36a.intermediate
28b0b88980777ed64da8677f804531a72fc7b36a.intermediate: $(builddir)/mksnapshot FORCE_DO_CMD
	$(call do_cmd,touch)
	$(call do_cmd,_home_penjud_vscode_projects_automation1V2_node_node_v21_7_2_tools_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot)

all_deps += $(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc $(obj).$(TOOLSET)/$(TARGET)/geni/embedded.S
action__home_penjud_vscode_projects_automation1V2_node_node_v21_7_2_tools_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot_outputs := $(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc $(obj).$(TOOLSET)/$(TARGET)/geni/embedded.S


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
	-I$(obj)/gen/generate-bytecode-output-root \
	-I$(obj)/gen \
	-I$(srcdir)/deps/icu-small/source/i18n \
	-I$(srcdir)/deps/icu-small/source/common

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
	-I$(obj)/gen/generate-bytecode-output-root \
	-I$(obj)/gen \
	-I$(srcdir)/deps/icu-small/source/i18n \
	-I$(srcdir)/deps/icu-small/source/common

OBJS := \
	$(obj).target/$(TARGET)/deps/v8/src/init/setup-isolate-deserialize.o \
	$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.o \
	$(obj).$(TOOLSET)/$(TARGET)/geni/embedded.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# Make sure our dependencies are built before any of us.
$(OBJS): | $(obj).target/tools/v8_gypfiles/generate_bytecode_builtins_list.stamp $(obj).target/tools/v8_gypfiles/run_torque.stamp $(builddir)/mksnapshot $(obj).target/tools/v8_gypfiles/v8_maybe_icu.stamp $(obj).target/tools/v8_gypfiles/v8_compiler_for_mksnapshot.stamp

# Make sure our actions/rules run before any of us.
$(OBJS): | $(action__home_penjud_vscode_projects_automation1V2_node_node_v21_7_2_tools_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot_outputs)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.S FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.S FORCE_DO_CMD
	@$(call do_cmd,cc,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.S FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# End of this set of suffix rules
### Rules for final target.
# Build our special outputs first.
$(obj).target/tools/v8_gypfiles/libv8_snapshot.a: | $(action__home_penjud_vscode_projects_automation1V2_node_node_v21_7_2_tools_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot_outputs)

# Preserve order dependency of special output on deps.
$(action__home_penjud_vscode_projects_automation1V2_node_node_v21_7_2_tools_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot_outputs): | $(obj).target/tools/v8_gypfiles/generate_bytecode_builtins_list.stamp $(obj).target/tools/v8_gypfiles/run_torque.stamp $(builddir)/mksnapshot $(obj).target/tools/v8_gypfiles/v8_maybe_icu.stamp $(obj).target/tools/v8_gypfiles/v8_compiler_for_mksnapshot.stamp

LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64 \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64 \
	-m64

LIBS :=

$(obj).target/tools/v8_gypfiles/libv8_snapshot.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/tools/v8_gypfiles/libv8_snapshot.a: LIBS := $(LIBS)
$(obj).target/tools/v8_gypfiles/libv8_snapshot.a: TOOLSET := $(TOOLSET)
$(obj).target/tools/v8_gypfiles/libv8_snapshot.a: $(OBJS)
	$(call create_thin_archive,$@,$^)

# Add target alias
.PHONY: v8_snapshot
v8_snapshot: $(obj).target/tools/v8_gypfiles/libv8_snapshot.a

# Add target alias to "all" target.
.PHONY: all
all: v8_snapshot

