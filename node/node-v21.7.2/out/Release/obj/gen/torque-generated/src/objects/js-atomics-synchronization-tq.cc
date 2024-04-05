#include "src/objects/js-atomics-synchronization-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=5&c=1
bool IsJSSynchronizationPrimitive_NonInline(Tagged<HeapObject> o) {
  return IsJSSynchronizationPrimitive(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSSynchronizationPrimitive<JSSynchronizationPrimitive, AlwaysSharedSpaceJSObject>::JSSynchronizationPrimitiveVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSSynchronizationPrimitiveVerify(JSSynchronizationPrimitive::cast(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=11&c=1
bool IsJSAtomicsMutex_NonInline(Tagged<HeapObject> o) {
  return IsJSAtomicsMutex(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSAtomicsMutex<JSAtomicsMutex, JSSynchronizationPrimitive>::JSAtomicsMutexVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSAtomicsMutexVerify(JSAtomicsMutex::cast(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=18&c=1
bool IsJSAtomicsCondition_NonInline(Tagged<HeapObject> o) {
  return IsJSAtomicsCondition(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSAtomicsCondition<JSAtomicsCondition, JSSynchronizationPrimitive>::JSAtomicsConditionVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSAtomicsConditionVerify(JSAtomicsCondition::cast(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
