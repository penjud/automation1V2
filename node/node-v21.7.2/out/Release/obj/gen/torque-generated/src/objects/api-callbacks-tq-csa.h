#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_API_CALLBACKS_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_API_CALLBACKS_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=5&c=1
TNode<CallHandlerInfo> Cast_CallHandlerInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=23&c=1
TNode<InterceptorInfo> Cast_InterceptorInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=35&c=1
TNode<AccessCheckInfo> Cast_AccessCheckInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=55&c=1
TNode<AccessorInfo> Cast_AccessorInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=6&c=3
TNode<Object> LoadCallHandlerInfoData_0(compiler::CodeAssemblerState* state_, TNode<CallHandlerInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=6&c=3
void StoreCallHandlerInfoData_0(compiler::CodeAssemblerState* state_, TNode<CallHandlerInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=8&c=3
TNode<TemplateInfo> LoadCallHandlerInfoOwnerTemplate_0(compiler::CodeAssemblerState* state_, TNode<CallHandlerInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=8&c=3
void StoreCallHandlerInfoOwnerTemplate_0(compiler::CodeAssemblerState* state_, TNode<CallHandlerInfo> p_o, TNode<TemplateInfo> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=12&c=3
TNode<ExternalPointerT> LoadCallHandlerInfoMaybeRedirectedCallback_0(compiler::CodeAssemblerState* state_, TNode<CallHandlerInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=12&c=3
void StoreCallHandlerInfoMaybeRedirectedCallback_0(compiler::CodeAssemblerState* state_, TNode<CallHandlerInfo> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=24&c=3
TNode<Object> LoadInterceptorInfoGetter_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=24&c=3
void StoreInterceptorInfoGetter_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=25&c=3
TNode<Object> LoadInterceptorInfoSetter_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=25&c=3
void StoreInterceptorInfoSetter_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=26&c=3
TNode<Object> LoadInterceptorInfoQuery_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=26&c=3
void StoreInterceptorInfoQuery_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=27&c=3
TNode<Object> LoadInterceptorInfoDescriptor_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=27&c=3
void StoreInterceptorInfoDescriptor_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=28&c=3
TNode<Object> LoadInterceptorInfoDeleter_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=28&c=3
void StoreInterceptorInfoDeleter_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=29&c=3
TNode<Object> LoadInterceptorInfoEnumerator_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=29&c=3
void StoreInterceptorInfoEnumerator_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=30&c=3
TNode<Object> LoadInterceptorInfoDefiner_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=30&c=3
void StoreInterceptorInfoDefiner_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=31&c=3
TNode<Object> LoadInterceptorInfoData_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=31&c=3
void StoreInterceptorInfoData_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=32&c=3
TNode<Smi> LoadInterceptorInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=32&c=3
void StoreInterceptorInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<InterceptorInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=36&c=3
TNode<Object> LoadAccessCheckInfoCallback_0(compiler::CodeAssemblerState* state_, TNode<AccessCheckInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=36&c=3
void StoreAccessCheckInfoCallback_0(compiler::CodeAssemblerState* state_, TNode<AccessCheckInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=37&c=3
TNode<Object> LoadAccessCheckInfoNamedInterceptor_0(compiler::CodeAssemblerState* state_, TNode<AccessCheckInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=37&c=3
void StoreAccessCheckInfoNamedInterceptor_0(compiler::CodeAssemblerState* state_, TNode<AccessCheckInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=38&c=3
TNode<Object> LoadAccessCheckInfoIndexedInterceptor_0(compiler::CodeAssemblerState* state_, TNode<AccessCheckInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=38&c=3
void StoreAccessCheckInfoIndexedInterceptor_0(compiler::CodeAssemblerState* state_, TNode<AccessCheckInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=39&c=3
TNode<Object> LoadAccessCheckInfoData_0(compiler::CodeAssemblerState* state_, TNode<AccessCheckInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=39&c=3
void StoreAccessCheckInfoData_0(compiler::CodeAssemblerState* state_, TNode<AccessCheckInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=56&c=3
TNode<Name> LoadAccessorInfoName_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=56&c=3
void StoreAccessorInfoName_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o, TNode<Name> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=57&c=3
TNode<Object> LoadAccessorInfoData_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=57&c=3
void StoreAccessorInfoData_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=61&c=3
TNode<ExternalPointerT> LoadAccessorInfoMaybeRedirectedGetter_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=61&c=3
void StoreAccessorInfoMaybeRedirectedGetter_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=62&c=3
TNode<ExternalPointerT> LoadAccessorInfoSetter_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=62&c=3
void StoreAccessorInfoSetter_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=63&c=3
TNode<Uint32T> LoadAccessorInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=63&c=3
void StoreAccessorInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=64&c=28
TNode<Uint32T> LoadAccessorInfoOptionalPadding_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=64&c=28
void StoreAccessorInfoOptionalPadding_0(compiler::CodeAssemblerState* state_, TNode<AccessorInfo> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=5&c=1
TNode<CallHandlerInfo> DownCastForTorqueClass_CallHandlerInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=23&c=1
TNode<InterceptorInfo> DownCastForTorqueClass_InterceptorInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=35&c=1
TNode<AccessCheckInfo> DownCastForTorqueClass_AccessCheckInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=55&c=1
TNode<AccessorInfo> DownCastForTorqueClass_AccessorInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_API_CALLBACKS_TQ_CSA_H_
