# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := v8_compiler_for_mksnapshot_source_set
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
	$(obj).target/$(TARGET)/deps/v8/src/compiler/access-builder.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/access-info.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/add-type-assertions-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/all-nodes.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/bitcast-elider.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/code-generator.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/frame-elider.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/gap-resolver.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/instruction-scheduler.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/instruction-selector.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/instruction.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/jump-threading.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/mid-tier-register-allocator.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/move-optimizer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/register-allocator-verifier.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/register-allocator.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/spill-placer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/basic-block-instrumentor.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/branch-condition-duplicator.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/branch-elimination.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/bytecode-analysis.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/bytecode-graph-builder.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/bytecode-liveness-map.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/c-linkage.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/checkpoint-elimination.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/code-assembler.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/common-node-cache.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/common-operator-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/common-operator.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/compilation-dependencies.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/compiler-source-position-table.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/constant-folding-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/control-equivalence.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/control-flow-optimizer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/csa-load-elimination.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/dead-code-elimination.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/decompression-optimizer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/effect-control-linearizer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/escape-analysis-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/escape-analysis.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/fast-api-calls.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/feedback-source.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/frame-states.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/frame.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/graph-assembler.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/graph-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/graph-trimmer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/graph-visualizer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/graph.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/heap-refs.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-call-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-context-specialization.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-create-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-generic-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-graph.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-heap-broker.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-inlining-heuristic.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-inlining.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-intrinsic-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-native-context-specialization.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-operator.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-type-hint-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/js-typed-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/late-escape-analysis.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/linkage.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/load-elimination.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/loop-analysis.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/loop-peeling.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/loop-unrolling.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/loop-variable-optimizer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/machine-graph-verifier.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/machine-graph.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/machine-operator-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/machine-operator.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/map-inference.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/memory-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/memory-optimizer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/node-marker.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/node-matchers.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/node-observer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/node-origin-table.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/node-properties.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/node.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/opcodes.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/operation-typer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/operator-properties.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/operator.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/osr.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/pair-load-store-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/pipeline-statistics.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/pipeline.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/property-access-builder.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/raw-machine-assembler.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/redundancy-elimination.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/refs-map.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/representation-change.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/schedule.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/scheduler.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/select-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/simplified-lowering-verifier.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/simplified-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/simplified-operator-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/simplified-operator.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/state-values-utils.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/store-store-elimination.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/string-builder-optimizer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/turbofan-enabled.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/type-cache.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/type-narrowing-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/typed-optimization.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/typer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/types.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/value-numbering-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/verifier.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/zone-stats.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/x64/code-generator-x64.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/x64/instruction-scheduler-x64.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/x64/instruction-selector-x64.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/backend/x64/unwinding-info-writer-x64.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/int64-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/turboshaft/int64-lowering-phase.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/turboshaft/wasm-optimize-phase.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/turboshaft/wasm-turboshaft-compiler.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-address-reassociation.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-call-descriptors.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-compiler-definitions.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-compiler.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-escape-analysis.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-gc-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-gc-operator-reducer.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-graph-assembler.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-inlining-into-js.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-inlining.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-js-lowering.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-load-elimination.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-loop-peeling.o \
	$(obj).target/$(TARGET)/deps/v8/src/compiler/wasm-typer.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# Make sure our dependencies are built before any of us.
$(OBJS): | $(obj).target/tools/v8_gypfiles/generate_bytecode_builtins_list.stamp $(obj).target/tools/v8_gypfiles/run_torque.stamp $(obj).target/tools/v8_gypfiles/v8_maybe_icu.stamp $(obj).target/tools/v8_gypfiles/v8_internal_headers.stamp $(obj).target/tools/v8_gypfiles/v8_shared_internal_headers.stamp $(obj).target/tools/v8_gypfiles/v8_pch.stamp $(obj).target/tools/v8_gypfiles/v8_compiler_sources.stamp

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
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

$(obj).target/tools/v8_gypfiles/libv8_compiler_for_mksnapshot_source_set.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/tools/v8_gypfiles/libv8_compiler_for_mksnapshot_source_set.a: LIBS := $(LIBS)
$(obj).target/tools/v8_gypfiles/libv8_compiler_for_mksnapshot_source_set.a: TOOLSET := $(TOOLSET)
$(obj).target/tools/v8_gypfiles/libv8_compiler_for_mksnapshot_source_set.a: $(OBJS)
	$(call create_thin_archive,$@,$^)

# Add target alias
.PHONY: v8_compiler_for_mksnapshot_source_set
v8_compiler_for_mksnapshot_source_set: $(obj).target/tools/v8_gypfiles/libv8_compiler_for_mksnapshot_source_set.a

