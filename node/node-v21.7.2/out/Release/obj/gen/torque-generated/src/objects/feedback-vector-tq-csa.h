#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FEEDBACK_VECTOR_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FEEDBACK_VECTOR_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=35&c=1
TNode<FeedbackVector> Cast_FeedbackVector_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=51&c=1
TNode<FeedbackMetadata> Cast_FeedbackMetadata_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=37&c=9
TNode<Int32T> LoadFeedbackVectorLength_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=38&c=3
TNode<Int32T> LoadFeedbackVectorInvocationCount_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=38&c=3
void StoreFeedbackVectorInvocationCount_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<Int32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=39&c=28
TNode<Uint32T> LoadFeedbackVectorOptionalPadding_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=39&c=28
void StoreFeedbackVectorOptionalPadding_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=41&c=3
TNode<Uint8T> LoadFeedbackVectorPlaceholder0_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=41&c=3
void StoreFeedbackVectorPlaceholder0_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<Uint8T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=42&c=3
TNode<Uint8T> LoadFeedbackVectorOsrState_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=42&c=3
void StoreFeedbackVectorOsrState_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<Uint8T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=43&c=3
TNode<Uint16T> LoadFeedbackVectorFlags_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=43&c=3
void StoreFeedbackVectorFlags_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<Uint16T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=44&c=3
TNode<SharedFunctionInfo> LoadFeedbackVectorSharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=44&c=3
void StoreFeedbackVectorSharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<SharedFunctionInfo> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=45&c=3
TNode<ClosureFeedbackCellArray> LoadFeedbackVectorClosureFeedbackCellArray_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=45&c=3
void StoreFeedbackVectorClosureFeedbackCellArray_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<ClosureFeedbackCellArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=46&c=3
TNode<FeedbackCell> LoadFeedbackVectorParentFeedbackCell_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=46&c=3
void StoreFeedbackVectorParentFeedbackCell_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<FeedbackCell> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=47&c=3
TNode<MaybeObject> LoadFeedbackVectorMaybeOptimizedCode_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=47&c=3
void StoreFeedbackVectorMaybeOptimizedCode_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=48&c=19
TorqueStructSlice_MaybeObject_MutableReference_MaybeObject_0 FieldSliceFeedbackVectorRawFeedbackSlots_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=48&c=19
TNode<MaybeObject> LoadFeedbackVectorRawFeedbackSlots_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=48&c=19
void StoreFeedbackVectorRawFeedbackSlots_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<IntPtrT> p_i, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=35&c=1
TNode<FeedbackVector> DownCastForTorqueClass_FeedbackVector_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=51&c=1
TNode<FeedbackMetadata> DownCastForTorqueClass_FeedbackMetadata_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FEEDBACK_VECTOR_TQ_CSA_H_
