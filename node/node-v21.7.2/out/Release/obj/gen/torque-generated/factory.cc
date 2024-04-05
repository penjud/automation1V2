#include "src/heap/factory-base.h"
#include "src/heap/factory-base-inl.h"
#include "src/heap/heap.h"
#include "src/heap/heap-inl.h"
#include "src/execution/isolate.h"
#include "src/objects/all-objects-inl.h"

namespace v8 {
namespace internal {

template <typename Impl>
Handle<SloppyArgumentsElements> TorqueGeneratedFactory<Impl>::NewSloppyArgumentsElements(int length, Handle<Context> context, Handle<FixedArray> arguments, AllocationType allocation_type) {
 int size = TorqueGeneratedSloppyArgumentsElements<SloppyArgumentsElements, FixedArrayBase>::SizeFor(length);
  Tagged<Map> map = factory()->read_only_roots().sloppy_arguments_elements_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<SloppyArgumentsElements> result = SloppyArgumentsElements::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_length(length);
  result->TorqueGeneratedClass::set_context(*context, write_barrier_mode);
  result->TorqueGeneratedClass::set_arguments(*arguments, write_barrier_mode);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<SloppyArgumentsElements>TorqueGeneratedFactory<Factory>::NewSloppyArgumentsElements(int length, Handle<Context> context, Handle<FixedArray> arguments, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<SloppyArgumentsElements>TorqueGeneratedFactory<LocalFactory>::NewSloppyArgumentsElements(int length, Handle<Context> context, Handle<FixedArray> arguments, AllocationType allocation_type);


template <typename Impl>
Handle<UncompiledDataWithoutPreparseData> TorqueGeneratedFactory<Impl>::NewUncompiledDataWithoutPreparseData(Handle<String> inferred_name, int32_t start_position, int32_t end_position, AllocationType allocation_type) {
 int size = TorqueGeneratedUncompiledDataWithoutPreparseData<UncompiledDataWithoutPreparseData, UncompiledData>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().uncompiled_data_without_preparse_data_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<UncompiledDataWithoutPreparseData> result = UncompiledDataWithoutPreparseData::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_inferred_name(*inferred_name, write_barrier_mode);
  result->TorqueGeneratedClass::set_start_position(start_position);
  result->TorqueGeneratedClass::set_end_position(end_position);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<UncompiledDataWithoutPreparseData>TorqueGeneratedFactory<Factory>::NewUncompiledDataWithoutPreparseData(Handle<String> inferred_name, int32_t start_position, int32_t end_position, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<UncompiledDataWithoutPreparseData>TorqueGeneratedFactory<LocalFactory>::NewUncompiledDataWithoutPreparseData(Handle<String> inferred_name, int32_t start_position, int32_t end_position, AllocationType allocation_type);


template <typename Impl>
Handle<UncompiledDataWithPreparseData> TorqueGeneratedFactory<Impl>::NewUncompiledDataWithPreparseData(Handle<String> inferred_name, int32_t start_position, int32_t end_position, Handle<PreparseData> preparse_data, AllocationType allocation_type) {
 int size = TorqueGeneratedUncompiledDataWithPreparseData<UncompiledDataWithPreparseData, UncompiledData>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().uncompiled_data_with_preparse_data_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<UncompiledDataWithPreparseData> result = UncompiledDataWithPreparseData::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_inferred_name(*inferred_name, write_barrier_mode);
  result->TorqueGeneratedClass::set_start_position(start_position);
  result->TorqueGeneratedClass::set_end_position(end_position);
  result->TorqueGeneratedClass::set_preparse_data(*preparse_data, write_barrier_mode);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<UncompiledDataWithPreparseData>TorqueGeneratedFactory<Factory>::NewUncompiledDataWithPreparseData(Handle<String> inferred_name, int32_t start_position, int32_t end_position, Handle<PreparseData> preparse_data, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<UncompiledDataWithPreparseData>TorqueGeneratedFactory<LocalFactory>::NewUncompiledDataWithPreparseData(Handle<String> inferred_name, int32_t start_position, int32_t end_position, Handle<PreparseData> preparse_data, AllocationType allocation_type);


template <typename Impl>
Handle<UncompiledDataWithoutPreparseDataWithJob> TorqueGeneratedFactory<Impl>::NewUncompiledDataWithoutPreparseDataWithJob(Handle<String> inferred_name, int32_t start_position, int32_t end_position, Address job, AllocationType allocation_type) {
 int size = TorqueGeneratedUncompiledDataWithoutPreparseDataWithJob<UncompiledDataWithoutPreparseDataWithJob, UncompiledDataWithoutPreparseData>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().uncompiled_data_without_preparse_data_with_job_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<UncompiledDataWithoutPreparseDataWithJob> result = UncompiledDataWithoutPreparseDataWithJob::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_inferred_name(*inferred_name, write_barrier_mode);
  result->TorqueGeneratedClass::set_start_position(start_position);
  result->TorqueGeneratedClass::set_end_position(end_position);
  result->TorqueGeneratedClass::set_job(job);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<UncompiledDataWithoutPreparseDataWithJob>TorqueGeneratedFactory<Factory>::NewUncompiledDataWithoutPreparseDataWithJob(Handle<String> inferred_name, int32_t start_position, int32_t end_position, Address job, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<UncompiledDataWithoutPreparseDataWithJob>TorqueGeneratedFactory<LocalFactory>::NewUncompiledDataWithoutPreparseDataWithJob(Handle<String> inferred_name, int32_t start_position, int32_t end_position, Address job, AllocationType allocation_type);


template <typename Impl>
Handle<UncompiledDataWithPreparseDataAndJob> TorqueGeneratedFactory<Impl>::NewUncompiledDataWithPreparseDataAndJob(Handle<String> inferred_name, int32_t start_position, int32_t end_position, Handle<PreparseData> preparse_data, Address job, AllocationType allocation_type) {
 int size = TorqueGeneratedUncompiledDataWithPreparseDataAndJob<UncompiledDataWithPreparseDataAndJob, UncompiledDataWithPreparseData>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().uncompiled_data_with_preparse_data_and_job_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<UncompiledDataWithPreparseDataAndJob> result = UncompiledDataWithPreparseDataAndJob::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_inferred_name(*inferred_name, write_barrier_mode);
  result->TorqueGeneratedClass::set_start_position(start_position);
  result->TorqueGeneratedClass::set_end_position(end_position);
  result->TorqueGeneratedClass::set_preparse_data(*preparse_data, write_barrier_mode);
  result->TorqueGeneratedClass::set_job(job);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<UncompiledDataWithPreparseDataAndJob>TorqueGeneratedFactory<Factory>::NewUncompiledDataWithPreparseDataAndJob(Handle<String> inferred_name, int32_t start_position, int32_t end_position, Handle<PreparseData> preparse_data, Address job, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<UncompiledDataWithPreparseDataAndJob>TorqueGeneratedFactory<LocalFactory>::NewUncompiledDataWithPreparseDataAndJob(Handle<String> inferred_name, int32_t start_position, int32_t end_position, Handle<PreparseData> preparse_data, Address job, AllocationType allocation_type);


template <typename Impl>
Handle<OnHeapBasicBlockProfilerData> TorqueGeneratedFactory<Impl>::NewOnHeapBasicBlockProfilerData(Handle<FixedInt32Array> block_ids, Handle<FixedUInt32Array> counts, Handle<PodArray<std::pair<int32_t, int32_t>>> branches, Handle<String> name, Handle<String> schedule, Handle<String> code, int hash, AllocationType allocation_type) {
 int size = TorqueGeneratedOnHeapBasicBlockProfilerData<OnHeapBasicBlockProfilerData, HeapObject>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().on_heap_basic_block_profiler_data_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<OnHeapBasicBlockProfilerData> result = OnHeapBasicBlockProfilerData::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_block_ids(*block_ids, write_barrier_mode);
  result->TorqueGeneratedClass::set_counts(*counts, write_barrier_mode);
  result->TorqueGeneratedClass::set_branches(*branches, write_barrier_mode);
  result->TorqueGeneratedClass::set_name(*name, write_barrier_mode);
  result->TorqueGeneratedClass::set_schedule(*schedule, write_barrier_mode);
  result->TorqueGeneratedClass::set_code(*code, write_barrier_mode);
  result->TorqueGeneratedClass::set_hash(hash);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<OnHeapBasicBlockProfilerData>TorqueGeneratedFactory<Factory>::NewOnHeapBasicBlockProfilerData(Handle<FixedInt32Array> block_ids, Handle<FixedUInt32Array> counts, Handle<PodArray<std::pair<int32_t, int32_t>>> branches, Handle<String> name, Handle<String> schedule, Handle<String> code, int hash, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<OnHeapBasicBlockProfilerData>TorqueGeneratedFactory<LocalFactory>::NewOnHeapBasicBlockProfilerData(Handle<FixedInt32Array> block_ids, Handle<FixedUInt32Array> counts, Handle<PodArray<std::pair<int32_t, int32_t>>> branches, Handle<String> name, Handle<String> schedule, Handle<String> code, int hash, AllocationType allocation_type);


template <typename Impl>
Handle<TurbofanBitsetType> TorqueGeneratedFactory<Impl>::NewTurbofanBitsetType(uint32_t bitset_low, uint32_t bitset_high, AllocationType allocation_type) {
 int size = TorqueGeneratedTurbofanBitsetType<TurbofanBitsetType, TurbofanType>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turbofan_bitset_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurbofanBitsetType> result = TurbofanBitsetType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_bitset_low(bitset_low);
  result->TorqueGeneratedClass::set_bitset_high(bitset_high);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurbofanBitsetType>TorqueGeneratedFactory<Factory>::NewTurbofanBitsetType(uint32_t bitset_low, uint32_t bitset_high, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurbofanBitsetType>TorqueGeneratedFactory<LocalFactory>::NewTurbofanBitsetType(uint32_t bitset_low, uint32_t bitset_high, AllocationType allocation_type);


template <typename Impl>
Handle<TurbofanUnionType> TorqueGeneratedFactory<Impl>::NewTurbofanUnionType(Handle<TurbofanType> type1, Handle<TurbofanType> type2, AllocationType allocation_type) {
 int size = TorqueGeneratedTurbofanUnionType<TurbofanUnionType, TurbofanType>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turbofan_union_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurbofanUnionType> result = TurbofanUnionType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_type1(*type1, write_barrier_mode);
  result->TorqueGeneratedClass::set_type2(*type2, write_barrier_mode);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurbofanUnionType>TorqueGeneratedFactory<Factory>::NewTurbofanUnionType(Handle<TurbofanType> type1, Handle<TurbofanType> type2, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurbofanUnionType>TorqueGeneratedFactory<LocalFactory>::NewTurbofanUnionType(Handle<TurbofanType> type1, Handle<TurbofanType> type2, AllocationType allocation_type);


template <typename Impl>
Handle<TurbofanRangeType> TorqueGeneratedFactory<Impl>::NewTurbofanRangeType(double min, double max, AllocationType allocation_type) {
 int size = TorqueGeneratedTurbofanRangeType<TurbofanRangeType, TurbofanType>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turbofan_range_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurbofanRangeType> result = TurbofanRangeType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_min(min);
  result->TorqueGeneratedClass::set_max(max);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurbofanRangeType>TorqueGeneratedFactory<Factory>::NewTurbofanRangeType(double min, double max, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurbofanRangeType>TorqueGeneratedFactory<LocalFactory>::NewTurbofanRangeType(double min, double max, AllocationType allocation_type);


template <typename Impl>
Handle<TurbofanHeapConstantType> TorqueGeneratedFactory<Impl>::NewTurbofanHeapConstantType(Handle<HeapObject> constant, AllocationType allocation_type) {
 int size = TorqueGeneratedTurbofanHeapConstantType<TurbofanHeapConstantType, TurbofanType>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turbofan_heap_constant_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurbofanHeapConstantType> result = TurbofanHeapConstantType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_constant(*constant, write_barrier_mode);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurbofanHeapConstantType>TorqueGeneratedFactory<Factory>::NewTurbofanHeapConstantType(Handle<HeapObject> constant, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurbofanHeapConstantType>TorqueGeneratedFactory<LocalFactory>::NewTurbofanHeapConstantType(Handle<HeapObject> constant, AllocationType allocation_type);


template <typename Impl>
Handle<TurbofanOtherNumberConstantType> TorqueGeneratedFactory<Impl>::NewTurbofanOtherNumberConstantType(double constant, AllocationType allocation_type) {
 int size = TorqueGeneratedTurbofanOtherNumberConstantType<TurbofanOtherNumberConstantType, TurbofanType>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turbofan_other_number_constant_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurbofanOtherNumberConstantType> result = TurbofanOtherNumberConstantType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_constant(constant);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurbofanOtherNumberConstantType>TorqueGeneratedFactory<Factory>::NewTurbofanOtherNumberConstantType(double constant, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurbofanOtherNumberConstantType>TorqueGeneratedFactory<LocalFactory>::NewTurbofanOtherNumberConstantType(double constant, AllocationType allocation_type);


template <typename Impl>
Handle<TurboshaftWord32Type> TorqueGeneratedFactory<Impl>::NewTurboshaftWord32Type(AllocationType allocation_type) {
 int size = TorqueGeneratedTurboshaftWord32Type<TurboshaftWord32Type, TurboshaftType>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turboshaft_word32type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurboshaftWord32Type> result = TurboshaftWord32Type::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord32Type>TorqueGeneratedFactory<Factory>::NewTurboshaftWord32Type(AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord32Type>TorqueGeneratedFactory<LocalFactory>::NewTurboshaftWord32Type(AllocationType allocation_type);


template <typename Impl>
Handle<TurboshaftWord32RangeType> TorqueGeneratedFactory<Impl>::NewTurboshaftWord32RangeType(uint32_t from, uint32_t to, AllocationType allocation_type) {
 int size = TorqueGeneratedTurboshaftWord32RangeType<TurboshaftWord32RangeType, TurboshaftWord32Type>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turboshaft_word32range_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurboshaftWord32RangeType> result = TurboshaftWord32RangeType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_from(from);
  result->TorqueGeneratedClass::set_to(to);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord32RangeType>TorqueGeneratedFactory<Factory>::NewTurboshaftWord32RangeType(uint32_t from, uint32_t to, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord32RangeType>TorqueGeneratedFactory<LocalFactory>::NewTurboshaftWord32RangeType(uint32_t from, uint32_t to, AllocationType allocation_type);


template <typename Impl>
Handle<TurboshaftWord32SetType> TorqueGeneratedFactory<Impl>::NewTurboshaftWord32SetType(uint32_t set_size, AllocationType allocation_type) {
 int size = TorqueGeneratedTurboshaftWord32SetType<TurboshaftWord32SetType, TurboshaftWord32Type>::SizeFor(set_size);
  Tagged<Map> map = factory()->read_only_roots().turboshaft_word32set_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurboshaftWord32SetType> result = TurboshaftWord32SetType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_set_size(set_size);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord32SetType>TorqueGeneratedFactory<Factory>::NewTurboshaftWord32SetType(uint32_t set_size, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord32SetType>TorqueGeneratedFactory<LocalFactory>::NewTurboshaftWord32SetType(uint32_t set_size, AllocationType allocation_type);


template <typename Impl>
Handle<TurboshaftWord64Type> TorqueGeneratedFactory<Impl>::NewTurboshaftWord64Type(AllocationType allocation_type) {
 int size = TorqueGeneratedTurboshaftWord64Type<TurboshaftWord64Type, TurboshaftType>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turboshaft_word64type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurboshaftWord64Type> result = TurboshaftWord64Type::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord64Type>TorqueGeneratedFactory<Factory>::NewTurboshaftWord64Type(AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord64Type>TorqueGeneratedFactory<LocalFactory>::NewTurboshaftWord64Type(AllocationType allocation_type);


template <typename Impl>
Handle<TurboshaftWord64RangeType> TorqueGeneratedFactory<Impl>::NewTurboshaftWord64RangeType(uint32_t from_high, uint32_t from_low, uint32_t to_high, uint32_t to_low, AllocationType allocation_type) {
 int size = TorqueGeneratedTurboshaftWord64RangeType<TurboshaftWord64RangeType, TurboshaftWord64Type>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turboshaft_word64range_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurboshaftWord64RangeType> result = TurboshaftWord64RangeType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_from_high(from_high);
  result->TorqueGeneratedClass::set_from_low(from_low);
  result->TorqueGeneratedClass::set_to_high(to_high);
  result->TorqueGeneratedClass::set_to_low(to_low);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord64RangeType>TorqueGeneratedFactory<Factory>::NewTurboshaftWord64RangeType(uint32_t from_high, uint32_t from_low, uint32_t to_high, uint32_t to_low, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord64RangeType>TorqueGeneratedFactory<LocalFactory>::NewTurboshaftWord64RangeType(uint32_t from_high, uint32_t from_low, uint32_t to_high, uint32_t to_low, AllocationType allocation_type);


template <typename Impl>
Handle<TurboshaftWord64SetType> TorqueGeneratedFactory<Impl>::NewTurboshaftWord64SetType(uint32_t set_size, AllocationType allocation_type) {
 int size = TorqueGeneratedTurboshaftWord64SetType<TurboshaftWord64SetType, TurboshaftWord64Type>::SizeFor(set_size);
  Tagged<Map> map = factory()->read_only_roots().turboshaft_word64set_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurboshaftWord64SetType> result = TurboshaftWord64SetType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_set_size(set_size);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord64SetType>TorqueGeneratedFactory<Factory>::NewTurboshaftWord64SetType(uint32_t set_size, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftWord64SetType>TorqueGeneratedFactory<LocalFactory>::NewTurboshaftWord64SetType(uint32_t set_size, AllocationType allocation_type);


template <typename Impl>
Handle<TurboshaftFloat64Type> TorqueGeneratedFactory<Impl>::NewTurboshaftFloat64Type(uint32_t special_values, AllocationType allocation_type) {
 int size = TorqueGeneratedTurboshaftFloat64Type<TurboshaftFloat64Type, TurboshaftType>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turboshaft_float64type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurboshaftFloat64Type> result = TurboshaftFloat64Type::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_special_values(special_values);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftFloat64Type>TorqueGeneratedFactory<Factory>::NewTurboshaftFloat64Type(uint32_t special_values, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftFloat64Type>TorqueGeneratedFactory<LocalFactory>::NewTurboshaftFloat64Type(uint32_t special_values, AllocationType allocation_type);


template <typename Impl>
Handle<TurboshaftFloat64RangeType> TorqueGeneratedFactory<Impl>::NewTurboshaftFloat64RangeType(uint32_t special_values, uint32_t _padding, double min, double max, AllocationType allocation_type) {
 int size = TorqueGeneratedTurboshaftFloat64RangeType<TurboshaftFloat64RangeType, TurboshaftFloat64Type>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().turboshaft_float64range_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurboshaftFloat64RangeType> result = TurboshaftFloat64RangeType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_special_values(special_values);
  result->TorqueGeneratedClass::set__padding(_padding);
  result->TorqueGeneratedClass::set_min(min);
  result->TorqueGeneratedClass::set_max(max);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftFloat64RangeType>TorqueGeneratedFactory<Factory>::NewTurboshaftFloat64RangeType(uint32_t special_values, uint32_t _padding, double min, double max, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftFloat64RangeType>TorqueGeneratedFactory<LocalFactory>::NewTurboshaftFloat64RangeType(uint32_t special_values, uint32_t _padding, double min, double max, AllocationType allocation_type);


template <typename Impl>
Handle<TurboshaftFloat64SetType> TorqueGeneratedFactory<Impl>::NewTurboshaftFloat64SetType(uint32_t special_values, uint32_t set_size, AllocationType allocation_type) {
 int size = TorqueGeneratedTurboshaftFloat64SetType<TurboshaftFloat64SetType, TurboshaftFloat64Type>::SizeFor(set_size);
  Tagged<Map> map = factory()->read_only_roots().turboshaft_float64set_type_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<TurboshaftFloat64SetType> result = TurboshaftFloat64SetType::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_special_values(special_values);
  result->TorqueGeneratedClass::set_set_size(set_size);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftFloat64SetType>TorqueGeneratedFactory<Factory>::NewTurboshaftFloat64SetType(uint32_t special_values, uint32_t set_size, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<TurboshaftFloat64SetType>TorqueGeneratedFactory<LocalFactory>::NewTurboshaftFloat64SetType(uint32_t special_values, uint32_t set_size, AllocationType allocation_type);


template <typename Impl>
Handle<ExportedSubClassBase> TorqueGeneratedFactory<Impl>::NewExportedSubClassBase(Handle<HeapObject> a, Handle<HeapObject> b, AllocationType allocation_type) {
 int size = TorqueGeneratedExportedSubClassBase<ExportedSubClassBase, HeapObject>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().exported_sub_class_base_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<ExportedSubClassBase> result = ExportedSubClassBase::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_a(*a, write_barrier_mode);
  result->TorqueGeneratedClass::set_b(*b, write_barrier_mode);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<ExportedSubClassBase>TorqueGeneratedFactory<Factory>::NewExportedSubClassBase(Handle<HeapObject> a, Handle<HeapObject> b, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<ExportedSubClassBase>TorqueGeneratedFactory<LocalFactory>::NewExportedSubClassBase(Handle<HeapObject> a, Handle<HeapObject> b, AllocationType allocation_type);


template <typename Impl>
Handle<ExportedSubClass> TorqueGeneratedFactory<Impl>::NewExportedSubClass(Handle<HeapObject> a, Handle<HeapObject> b, int32_t c_field, int32_t d_field, int e_field, AllocationType allocation_type) {
 int size = TorqueGeneratedExportedSubClass<ExportedSubClass, ExportedSubClassBase>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().exported_sub_class_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<ExportedSubClass> result = ExportedSubClass::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_a(*a, write_barrier_mode);
  result->TorqueGeneratedClass::set_b(*b, write_barrier_mode);
  result->TorqueGeneratedClass::set_c_field(c_field);
  result->TorqueGeneratedClass::set_d_field(d_field);
  result->TorqueGeneratedClass::set_e_field(e_field);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<ExportedSubClass>TorqueGeneratedFactory<Factory>::NewExportedSubClass(Handle<HeapObject> a, Handle<HeapObject> b, int32_t c_field, int32_t d_field, int e_field, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<ExportedSubClass>TorqueGeneratedFactory<LocalFactory>::NewExportedSubClass(Handle<HeapObject> a, Handle<HeapObject> b, int32_t c_field, int32_t d_field, int e_field, AllocationType allocation_type);


template <typename Impl>
Handle<ExportedSubClass2> TorqueGeneratedFactory<Impl>::NewExportedSubClass2(Handle<HeapObject> a, Handle<HeapObject> b, int32_t x_field, int32_t y_field, int z_field, AllocationType allocation_type) {
 int size = TorqueGeneratedExportedSubClass2<ExportedSubClass2, ExportedSubClassBase>::SizeFor();
  Tagged<Map> map = factory()->read_only_roots().exported_sub_class2_map();  Tagged<HeapObject> raw_object =
    factory()->AllocateRawWithImmortalMap(size, allocation_type, map);
  Tagged<ExportedSubClass2> result = ExportedSubClass2::cast(raw_object);
  DisallowGarbageCollection no_gc;  WriteBarrierMode write_barrier_mode =
     allocation_type == AllocationType::kYoung
     ? SKIP_WRITE_BARRIER : UPDATE_WRITE_BARRIER;
  USE(write_barrier_mode);
  result->TorqueGeneratedClass::set_a(*a, write_barrier_mode);
  result->TorqueGeneratedClass::set_b(*b, write_barrier_mode);
  result->TorqueGeneratedClass::set_x_field(x_field);
  result->TorqueGeneratedClass::set_y_field(y_field);
  result->TorqueGeneratedClass::set_z_field(z_field);
  return handle(result, factory()->isolate());
}

template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<ExportedSubClass2>TorqueGeneratedFactory<Factory>::NewExportedSubClass2(Handle<HeapObject> a, Handle<HeapObject> b, int32_t x_field, int32_t y_field, int z_field, AllocationType allocation_type);
template EXPORT_TEMPLATE_DEFINE(V8_EXPORT_PRIVATE) Handle<ExportedSubClass2>TorqueGeneratedFactory<LocalFactory>::NewExportedSubClass2(Handle<HeapObject> a, Handle<HeapObject> b, int32_t x_field, int32_t y_field, int z_field, AllocationType allocation_type);


}  // namespace internal
}  // namespace v8
