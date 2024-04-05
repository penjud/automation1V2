#include "torque-generated/class-debug-readers.h"

#include "src/objects/all-objects-inl.h"
#include "torque-generated/debug-macros.h"

// Unset a wingdi.h macro that causes conflicts.
#ifdef GetBValue
#undef GetBValue
#endif

namespace i = v8::internal;

namespace v8 {
namespace internal {
namespace debug_helper_internal {

const char* TqHeapObject::GetName() const {
  return "v8::internal::HeapObject";
}

void TqHeapObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitHeapObject(this);
}

bool TqHeapObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqHeapObject*>(other) != nullptr;
}

uintptr_t TqHeapObject::GetMapAddress() const {
  return address_ - i::kHeapObjectTag + 0;
}

Value<uintptr_t> TqHeapObject::GetMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqHeapObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> map_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("map", "v8::internal::Map", "v8::internal::Map", GetMapAddress(), 1, 8, std::move(map_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqContext::GetName() const {
  return "v8::internal::Context";
}

void TqContext::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitContext(this);
}

bool TqContext::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqContext*>(other) != nullptr;
}

uintptr_t TqContext::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqContext::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqContext::GetElementsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqContext::GetElementsValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetElementsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqContext::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::Object", "v8::internal::Object", GetLengthAddress(), 1, 8, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> elements_struct_field_list;
  auto indexed_field_slice_elements = TqDebugFieldSliceContextElements(accessor, address_);
  if (indexed_field_slice_elements.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("elements", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_elements.value), std::get<2>(indexed_field_slice_elements.value), 8, std::move(elements_struct_field_list), GetArrayKind(indexed_field_slice_elements.validity)));
  }
  return result;
}

const char* TqJSReceiver::GetName() const {
  return "v8::internal::JSReceiver";
}

void TqJSReceiver::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSReceiver(this);
}

bool TqJSReceiver::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSReceiver*>(other) != nullptr;
}

uintptr_t TqJSReceiver::GetPropertiesOrHashAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqJSReceiver::GetPropertiesOrHashValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPropertiesOrHashAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSReceiver::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> properties_or_hash_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("properties_or_hash", "v8::internal::Object", "v8::internal::Object", GetPropertiesOrHashAddress(), 1, 8, std::move(properties_or_hash_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqPrimitiveHeapObject::GetName() const {
  return "v8::internal::PrimitiveHeapObject";
}

void TqPrimitiveHeapObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPrimitiveHeapObject(this);
}

bool TqPrimitiveHeapObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPrimitiveHeapObject*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqPrimitiveHeapObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  return result;
}

const char* TqOddball::GetName() const {
  return "v8::internal::Oddball";
}

void TqOddball::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitOddball(this);
}

bool TqOddball::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqOddball*>(other) != nullptr;
}

uintptr_t TqOddball::GetToNumberRawAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqOddball::GetToNumberRawValue(d::MemoryAccessor accessor) const {
  double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetToNumberRawAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqOddball::GetToStringAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqOddball::GetToStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetToStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOddball::GetToNumberAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqOddball::GetToNumberValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetToNumberAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOddball::GetTypeOfAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqOddball::GetTypeOfValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTypeOfAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOddball::GetKindAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqOddball::GetKindValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKindAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqOddball::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPrimitiveHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> to_number_raw_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("to_number_raw", CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), GetToNumberRawAddress(), 1, 8, std::move(to_number_raw_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> to_string_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("to_string", "v8::internal::String", "v8::internal::String", GetToStringAddress(), 1, 8, std::move(to_string_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> to_number_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("to_number", "v8::internal::Object", "v8::internal::Object", GetToNumberAddress(), 1, 8, std::move(to_number_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> type_of_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("type_of", "v8::internal::String", "v8::internal::String", GetTypeOfAddress(), 1, 8, std::move(type_of_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> kind_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("kind", "v8::internal::Object", "v8::internal::Object", GetKindAddress(), 1, 8, std::move(kind_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqUndefined::GetName() const {
  return "v8::internal::Undefined";
}

void TqUndefined::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitUndefined(this);
}

bool TqUndefined::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqUndefined*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqUndefined::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqOddball::GetProperties(accessor);
  return result;
}

const char* TqNull::GetName() const {
  return "v8::internal::Null";
}

void TqNull::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitNull(this);
}

bool TqNull::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqNull*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqNull::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqOddball::GetProperties(accessor);
  return result;
}

const char* TqBoolean::GetName() const {
  return "v8::internal::Boolean";
}

void TqBoolean::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitBoolean(this);
}

bool TqBoolean::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqBoolean*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqBoolean::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqOddball::GetProperties(accessor);
  return result;
}

const char* TqName::GetName() const {
  return "v8::internal::Name";
}

void TqName::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitName(this);
}

bool TqName::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqName*>(other) != nullptr;
}

uintptr_t TqName::GetRawHashFieldAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqName::GetRawHashFieldValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetRawHashFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqName::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPrimitiveHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> raw_hash_field_struct_field_list;
  raw_hash_field_struct_field_list.push_back(std::make_unique<StructProperty>("hash_field_type", CheckTypeName<Name::HashFieldType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Name::HashFieldType"), CheckTypeName<Name::HashFieldType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Name::HashFieldType"), 0, 2, 0));
  raw_hash_field_struct_field_list.push_back(std::make_unique<StructProperty>("array_index_value", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), 0, 24, 2));
  raw_hash_field_struct_field_list.push_back(std::make_unique<StructProperty>("array_index_length", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), 0, 6, 26));
  result.push_back(std::make_unique<ObjectProperty>("raw_hash_field", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetRawHashFieldAddress(), 1, 4, std::move(raw_hash_field_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqSymbol::GetName() const {
  return "v8::internal::Symbol";
}

void TqSymbol::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSymbol(this);
}

bool TqSymbol::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSymbol*>(other) != nullptr;
}

uintptr_t TqSymbol::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSymbol::GetFlagsValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSymbol::GetDescriptionAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSymbol::GetDescriptionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDescriptionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSymbol::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqName::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_private", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 0));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_well_known_symbol", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 1));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_in_public_symbol_table", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 2));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_interesting_symbol", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 3));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_private_name", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 4));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_private_brand", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 5));
  result.push_back(std::make_unique<ObjectProperty>("flags", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetFlagsAddress(), 1, 4, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> description_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("description", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", GetDescriptionAddress(), 1, 8, std::move(description_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqString::GetName() const {
  return "v8::internal::String";
}

void TqString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitString(this);
}

bool TqString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqString*>(other) != nullptr;
}

uintptr_t TqString::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqString::GetLengthValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqName::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetLengthAddress(), 1, 4, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqHeapNumber::GetName() const {
  return "v8::internal::HeapNumber";
}

void TqHeapNumber::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitHeapNumber(this);
}

bool TqHeapNumber::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqHeapNumber*>(other) != nullptr;
}

uintptr_t TqHeapNumber::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqHeapNumber::GetValueValue(d::MemoryAccessor accessor) const {
  double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqHeapNumber::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPrimitiveHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value", CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), GetValueAddress(), 1, 8, std::move(value_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqFixedArrayBase::GetName() const {
  return "v8::internal::FixedArrayBase";
}

void TqFixedArrayBase::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFixedArrayBase(this);
}

bool TqFixedArrayBase::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFixedArrayBase*>(other) != nullptr;
}

uintptr_t TqFixedArrayBase::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqFixedArrayBase::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFixedArrayBase::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::Object", "v8::internal::Object", GetLengthAddress(), 1, 8, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqFixedArray::GetName() const {
  return "v8::internal::FixedArray";
}

void TqFixedArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFixedArray(this);
}

bool TqFixedArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFixedArray*>(other) != nullptr;
}

uintptr_t TqFixedArray::GetObjectsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqFixedArray::GetObjectsValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetObjectsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFixedArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> objects_struct_field_list;
  auto indexed_field_slice_objects = TqDebugFieldSliceFixedArrayObjects(accessor, address_);
  if (indexed_field_slice_objects.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("objects", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_objects.value), std::get<2>(indexed_field_slice_objects.value), 8, std::move(objects_struct_field_list), GetArrayKind(indexed_field_slice_objects.validity)));
  }
  return result;
}

const char* TqJSObject::GetName() const {
  return "v8::internal::JSObject";
}

void TqJSObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSObject(this);
}

bool TqJSObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSObject*>(other) != nullptr;
}

uintptr_t TqJSObject::GetElementsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSObject::GetElementsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetElementsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSReceiver::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> elements_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("elements", "v8::internal::FixedArrayBase", "v8::internal::FixedArrayBase", GetElementsAddress(), 1, 8, std::move(elements_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWeakFixedArray::GetName() const {
  return "v8::internal::WeakFixedArray";
}

void TqWeakFixedArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWeakFixedArray(this);
}

bool TqWeakFixedArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWeakFixedArray*>(other) != nullptr;
}

uintptr_t TqWeakFixedArray::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWeakFixedArray::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakFixedArray::GetObjectsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWeakFixedArray::GetObjectsValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetObjectsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWeakFixedArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::Object", "v8::internal::Object", GetLengthAddress(), 1, 8, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> objects_struct_field_list;
  auto indexed_field_slice_objects = TqDebugFieldSliceWeakFixedArrayObjects(accessor, address_);
  if (indexed_field_slice_objects.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("objects", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_objects.value), std::get<2>(indexed_field_slice_objects.value), 8, std::move(objects_struct_field_list), GetArrayKind(indexed_field_slice_objects.validity)));
  }
  return result;
}

const char* TqForeign::GetName() const {
  return "v8::internal::Foreign";
}

void TqForeign::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitForeign(this);
}

bool TqForeign::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqForeign*>(other) != nullptr;
}

uintptr_t TqForeign::GetForeignAddressAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqForeign::GetForeignAddressValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetForeignAddressAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqForeign::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> foreign_address_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("foreign_address", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetForeignAddressAddress(), 1, 8, std::move(foreign_address_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSProxy::GetName() const {
  return "v8::internal::JSProxy";
}

void TqJSProxy::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSProxy(this);
}

bool TqJSProxy::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSProxy*>(other) != nullptr;
}

uintptr_t TqJSProxy::GetTargetAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSProxy::GetTargetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTargetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSProxy::GetHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSProxy::GetHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSProxy::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSReceiver::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> target_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("target", "v8::internal::HeapObject", "v8::internal::HeapObject", GetTargetAddress(), 1, 8, std::move(target_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> handler_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("handler", "v8::internal::HeapObject", "v8::internal::HeapObject", GetHandlerAddress(), 1, 8, std::move(handler_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSFunctionOrBoundFunctionOrWrappedFunction::GetName() const {
  return "v8::internal::JSFunctionOrBoundFunctionOrWrappedFunction";
}

void TqJSFunctionOrBoundFunctionOrWrappedFunction::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSFunctionOrBoundFunctionOrWrappedFunction(this);
}

bool TqJSFunctionOrBoundFunctionOrWrappedFunction::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSFunctionOrBoundFunctionOrWrappedFunction*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSFunctionOrBoundFunctionOrWrappedFunction::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSWrappedFunction::GetName() const {
  return "v8::internal::JSWrappedFunction";
}

void TqJSWrappedFunction::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSWrappedFunction(this);
}

bool TqJSWrappedFunction::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSWrappedFunction*>(other) != nullptr;
}

uintptr_t TqJSWrappedFunction::GetWrappedTargetFunctionAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSWrappedFunction::GetWrappedTargetFunctionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWrappedTargetFunctionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSWrappedFunction::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSWrappedFunction::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSWrappedFunction::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSFunctionOrBoundFunctionOrWrappedFunction::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> wrapped_target_function_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("wrapped_target_function", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetWrappedTargetFunctionAddress(), 1, 8, std::move(wrapped_target_function_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::NativeContext", "v8::internal::NativeContext", GetContextAddress(), 1, 8, std::move(context_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSBoundFunction::GetName() const {
  return "v8::internal::JSBoundFunction";
}

void TqJSBoundFunction::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSBoundFunction(this);
}

bool TqJSBoundFunction::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSBoundFunction*>(other) != nullptr;
}

uintptr_t TqJSBoundFunction::GetBoundTargetFunctionAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSBoundFunction::GetBoundTargetFunctionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundTargetFunctionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSBoundFunction::GetBoundThisAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSBoundFunction::GetBoundThisValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundThisAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSBoundFunction::GetBoundArgumentsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSBoundFunction::GetBoundArgumentsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundArgumentsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSBoundFunction::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSFunctionOrBoundFunctionOrWrappedFunction::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> bound_target_function_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_target_function", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetBoundTargetFunctionAddress(), 1, 8, std::move(bound_target_function_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bound_this_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_this", "v8::internal::Object", "v8::internal::Object", GetBoundThisAddress(), 1, 8, std::move(bound_this_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bound_arguments_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_arguments", "v8::internal::FixedArray", "v8::internal::FixedArray", GetBoundArgumentsAddress(), 1, 8, std::move(bound_arguments_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSFunction::GetName() const {
  return "v8::internal::JSFunction";
}

void TqJSFunction::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSFunction(this);
}

bool TqJSFunction::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSFunction*>(other) != nullptr;
}

uintptr_t TqJSFunction::GetCodeAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSFunction::GetCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFunction::GetSharedFunctionInfoAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSFunction::GetSharedFunctionInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedFunctionInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFunction::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSFunction::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFunction::GetFeedbackCellAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSFunction::GetFeedbackCellValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFeedbackCellAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFunction::GetPrototypeOrInitialMapAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqJSFunction::GetPrototypeOrInitialMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeOrInitialMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSFunction::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSFunctionOrBoundFunctionOrWrappedFunction::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> code_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("code", "v8::internal::Code", "v8::internal::Code", GetCodeAddress(), 1, 8, std::move(code_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> shared_function_info_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("shared_function_info", "v8::internal::SharedFunctionInfo", "v8::internal::SharedFunctionInfo", GetSharedFunctionInfoAddress(), 1, 8, std::move(shared_function_info_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::Context", "v8::internal::Context", GetContextAddress(), 1, 8, std::move(context_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> feedback_cell_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("feedback_cell", "v8::internal::FeedbackCell", "v8::internal::FeedbackCell", GetFeedbackCellAddress(), 1, 8, std::move(feedback_cell_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> prototype_or_initial_map_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("prototype_or_initial_map", "v8::internal::HeapObject", "v8::internal::HeapObject", GetPrototypeOrInitialMapAddress(), 1, 8, std::move(prototype_or_initial_map_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqHole::GetName() const {
  return "v8::internal::Hole";
}

void TqHole::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitHole(this);
}

bool TqHole::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqHole*>(other) != nullptr;
}

uintptr_t TqHole::GetRawNumericValueAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqHole::GetRawNumericValueValue(d::MemoryAccessor accessor) const {
  double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetRawNumericValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqHole::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> raw_numeric_value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw_numeric_value", CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), GetRawNumericValueAddress(), 1, 8, std::move(raw_numeric_value_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSObjectWithEmbedderSlots::GetName() const {
  return "v8::internal::JSObjectWithEmbedderSlots";
}

void TqJSObjectWithEmbedderSlots::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSObjectWithEmbedderSlots(this);
}

bool TqJSObjectWithEmbedderSlots::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSObjectWithEmbedderSlots*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSObjectWithEmbedderSlots::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSCustomElementsObject::GetName() const {
  return "v8::internal::JSCustomElementsObject";
}

void TqJSCustomElementsObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSCustomElementsObject(this);
}

bool TqJSCustomElementsObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSCustomElementsObject*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSCustomElementsObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSSpecialObject::GetName() const {
  return "v8::internal::JSSpecialObject";
}

void TqJSSpecialObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSpecialObject(this);
}

bool TqJSSpecialObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSpecialObject*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSpecialObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSCustomElementsObject::GetProperties(accessor);
  return result;
}

const char* TqWasmNull::GetName() const {
  return "v8::internal::WasmNull";
}

void TqWasmNull::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmNull(this);
}

bool TqWasmNull::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmNull*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmNull::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  return result;
}

const char* TqWasmInternalFunction::GetName() const {
  return "v8::internal::WasmInternalFunction";
}

void TqWasmInternalFunction::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmInternalFunction(this);
}

bool TqWasmInternalFunction::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmInternalFunction*>(other) != nullptr;
}

uintptr_t TqWasmInternalFunction::GetRefAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmInternalFunction::GetRefValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRefAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmInternalFunction::GetExternalAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmInternalFunction::GetExternalValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExternalAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmInternalFunction::GetCodeAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmInternalFunction::GetCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmInternalFunction::GetFunctionIndexAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmInternalFunction::GetFunctionIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmInternalFunction::GetCallTargetAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmInternalFunction::GetCallTargetValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetCallTargetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmInternalFunction::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> ref_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("ref", "v8::internal::HeapObject", "v8::internal::HeapObject", GetRefAddress(), 1, 8, std::move(ref_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> external_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("external", "v8::internal::HeapObject", "v8::internal::HeapObject", GetExternalAddress(), 1, 8, std::move(external_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> code_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("code", "v8::internal::Code", "v8::internal::Code", GetCodeAddress(), 1, 8, std::move(code_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> function_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("function_index", "v8::internal::Object", "v8::internal::Object", GetFunctionIndexAddress(), 1, 8, std::move(function_index_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> call_target_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("call_target", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetCallTargetAddress(), 1, 8, std::move(call_target_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWeakCell::GetName() const {
  return "v8::internal::WeakCell";
}

void TqWeakCell::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWeakCell(this);
}

bool TqWeakCell::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWeakCell*>(other) != nullptr;
}

uintptr_t TqWeakCell::GetFinalizationRegistryAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWeakCell::GetFinalizationRegistryValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFinalizationRegistryAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetTargetAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWeakCell::GetTargetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTargetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetUnregisterTokenAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWeakCell::GetUnregisterTokenValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUnregisterTokenAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetHoldingsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWeakCell::GetHoldingsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHoldingsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetPrevAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqWeakCell::GetPrevValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrevAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqWeakCell::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetKeyListPrevAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqWeakCell::GetKeyListPrevValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKeyListPrevAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetKeyListNextAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqWeakCell::GetKeyListNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKeyListNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWeakCell::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> finalization_registry_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("finalization_registry", "v8::internal::HeapObject", "v8::internal::HeapObject", GetFinalizationRegistryAddress(), 1, 8, std::move(finalization_registry_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> target_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("target", "v8::internal::HeapObject", "v8::internal::HeapObject", GetTargetAddress(), 1, 8, std::move(target_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> unregister_token_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("unregister_token", "v8::internal::HeapObject", "v8::internal::HeapObject", GetUnregisterTokenAddress(), 1, 8, std::move(unregister_token_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> holdings_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("holdings", "v8::internal::Object", "v8::internal::Object", GetHoldingsAddress(), 1, 8, std::move(holdings_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> prev_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("prev", "v8::internal::HeapObject", "v8::internal::HeapObject", GetPrevAddress(), 1, 8, std::move(prev_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> next_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::HeapObject", "v8::internal::HeapObject", GetNextAddress(), 1, 8, std::move(next_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> key_list_prev_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("key_list_prev", "v8::internal::HeapObject", "v8::internal::HeapObject", GetKeyListPrevAddress(), 1, 8, std::move(key_list_prev_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> key_list_next_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("key_list_next", "v8::internal::HeapObject", "v8::internal::HeapObject", GetKeyListNextAddress(), 1, 8, std::move(key_list_next_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqMap::GetName() const {
  return "v8::internal::Map";
}

void TqMap::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitMap(this);
}

bool TqMap::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqMap*>(other) != nullptr;
}

uintptr_t TqMap::GetInstanceSizeInWordsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqMap::GetInstanceSizeInWordsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetInstanceSizeInWordsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetInobjectPropertiesStartOrConstructorFunctionIndexAddress() const {
  return address_ - i::kHeapObjectTag + 9;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqMap::GetInobjectPropertiesStartOrConstructorFunctionIndexValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetInobjectPropertiesStartOrConstructorFunctionIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetUsedOrUnusedInstanceSizeInWordsAddress() const {
  return address_ - i::kHeapObjectTag + 10;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqMap::GetUsedOrUnusedInstanceSizeInWordsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetUsedOrUnusedInstanceSizeInWordsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetVisitorIdAddress() const {
  return address_ - i::kHeapObjectTag + 11;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqMap::GetVisitorIdValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetVisitorIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetInstanceTypeAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<InstanceType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqMap::GetInstanceTypeValue(d::MemoryAccessor accessor) const {
  InstanceType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetInstanceTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetBitFieldAddress() const {
  return address_ - i::kHeapObjectTag + 14;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqMap::GetBitFieldValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetBitFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetBitField2Address() const {
  return address_ - i::kHeapObjectTag + 15;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqMap::GetBitField2Value(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetBitField2Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetBitField3Address() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqMap::GetBitField3Value(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetBitField3Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqMap::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetPrototypeAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqMap::GetPrototypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMap::GetConstructorOrBackPointerOrNativeContextAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqMap::GetConstructorOrBackPointerOrNativeContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetConstructorOrBackPointerOrNativeContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMap::GetInstanceDescriptorsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqMap::GetInstanceDescriptorsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceDescriptorsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMap::GetDependentCodeAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqMap::GetDependentCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDependentCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMap::GetPrototypeValidityCellAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqMap::GetPrototypeValidityCellValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeValidityCellAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMap::GetTransitionsOrPrototypeInfoAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqMap::GetTransitionsOrPrototypeInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTransitionsOrPrototypeInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqMap::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> instance_size_in_words_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance_size_in_words", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetInstanceSizeInWordsAddress(), 1, 1, std::move(instance_size_in_words_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> inobject_properties_start_or_constructor_function_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("inobject_properties_start_or_constructor_function_index", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetInobjectPropertiesStartOrConstructorFunctionIndexAddress(), 1, 1, std::move(inobject_properties_start_or_constructor_function_index_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> used_or_unused_instance_size_in_words_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("used_or_unused_instance_size_in_words", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetUsedOrUnusedInstanceSizeInWordsAddress(), 1, 1, std::move(used_or_unused_instance_size_in_words_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> visitor_id_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("visitor_id", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetVisitorIdAddress(), 1, 1, std::move(visitor_id_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> instance_type_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance_type", CheckTypeName<InstanceType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("InstanceType"), CheckTypeName<InstanceType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("InstanceType"), GetInstanceTypeAddress(), 1, 2, std::move(instance_type_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bit_field_struct_field_list;
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("has_non_instance_prototype", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 0));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_callable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 1));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("has_named_interceptor", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 2));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("has_indexed_interceptor", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 3));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_undetectable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 4));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_access_check_needed", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 5));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_constructor", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 6));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("has_prototype_slot", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 7));
  result.push_back(std::make_unique<ObjectProperty>("bit_field", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetBitFieldAddress(), 1, 1, std::move(bit_field_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bit_field2_struct_field_list;
  bit_field2_struct_field_list.push_back(std::make_unique<StructProperty>("new_target_is_base", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 0));
  bit_field2_struct_field_list.push_back(std::make_unique<StructProperty>("is_immutable_prototype", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 1));
  bit_field2_struct_field_list.push_back(std::make_unique<StructProperty>("elements_kind", CheckTypeName<ElementsKind /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ElementsKind"), CheckTypeName<ElementsKind /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ElementsKind"), 0, 6, 2));
  result.push_back(std::make_unique<ObjectProperty>("bit_field2", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetBitField2Address(), 1, 1, std::move(bit_field2_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bit_field3_struct_field_list;
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("enum_length", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 10, 0));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("number_of_own_descriptors", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 10, 10));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("is_prototype_map", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 20));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("is_dictionary_map", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 21));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("owns_descriptors", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 22));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("is_in_retained_map_list", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 23));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("is_deprecated", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 24));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("is_unstable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 25));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("is_migration_target", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 26));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("is_extensible", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 27));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("may_have_interesting_properties", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 28));
  bit_field3_struct_field_list.push_back(std::make_unique<StructProperty>("construction_counter", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 3, 29));
  result.push_back(std::make_unique<ObjectProperty>("bit_field3", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetBitField3Address(), 1, 4, std::move(bit_field3_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> prototype_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("prototype", "v8::internal::HeapObject", "v8::internal::HeapObject", GetPrototypeAddress(), 1, 8, std::move(prototype_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> constructor_or_back_pointer_or_native_context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("constructor_or_back_pointer_or_native_context", "v8::internal::Object", "v8::internal::Object", GetConstructorOrBackPointerOrNativeContextAddress(), 1, 8, std::move(constructor_or_back_pointer_or_native_context_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> instance_descriptors_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance_descriptors", "v8::internal::DescriptorArray", "v8::internal::DescriptorArray", GetInstanceDescriptorsAddress(), 1, 8, std::move(instance_descriptors_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> dependent_code_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("dependent_code", "v8::internal::WeakFixedArray", "v8::internal::WeakFixedArray", GetDependentCodeAddress(), 1, 8, std::move(dependent_code_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> prototype_validity_cell_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("prototype_validity_cell", "v8::internal::Object", "v8::internal::Object", GetPrototypeValidityCellAddress(), 1, 8, std::move(prototype_validity_cell_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> transitions_or_prototype_info_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("transitions_or_prototype_info", "v8::internal::Object", "v8::internal::Object", GetTransitionsOrPrototypeInfoAddress(), 1, 8, std::move(transitions_or_prototype_info_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSPromise::GetName() const {
  return "v8::internal::JSPromise";
}

void TqJSPromise::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSPromise(this);
}

bool TqJSPromise::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSPromise*>(other) != nullptr;
}

uintptr_t TqJSPromise::GetReactionsOrResultAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSPromise::GetReactionsOrResultValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetReactionsOrResultAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSPromise::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSPromise::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSPromise::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObjectWithEmbedderSlots::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> reactions_or_result_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("reactions_or_result", "v8::internal::Object", "v8::internal::Object", GetReactionsOrResultAddress(), 1, 8, std::move(reactions_or_result_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("status", CheckTypeName<Promise::PromiseState /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Promise::PromiseState"), CheckTypeName<Promise::PromiseState /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Promise::PromiseState"), 0, 2, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_handler", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 34));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("handled_hint", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 35));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_silent", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 36));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("async_task_id", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 22, 37));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqStruct::GetName() const {
  return "v8::internal::Struct";
}

void TqStruct::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitStruct(this);
}

bool TqStruct::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqStruct*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqStruct::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  return result;
}

const char* TqPromiseCapability::GetName() const {
  return "v8::internal::PromiseCapability";
}

void TqPromiseCapability::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseCapability(this);
}

bool TqPromiseCapability::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseCapability*>(other) != nullptr;
}

uintptr_t TqPromiseCapability::GetPromiseAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPromiseCapability::GetPromiseValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseCapability::GetResolveAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPromiseCapability::GetResolveValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetResolveAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseCapability::GetRejectAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqPromiseCapability::GetRejectValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRejectAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseCapability::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> promise_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("promise", "v8::internal::HeapObject", "v8::internal::HeapObject", GetPromiseAddress(), 1, 8, std::move(promise_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> resolve_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("resolve", "v8::internal::Object", "v8::internal::Object", GetResolveAddress(), 1, 8, std::move(resolve_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> reject_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("reject", "v8::internal::Object", "v8::internal::Object", GetRejectAddress(), 1, 8, std::move(reject_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSArrayBufferView::GetName() const {
  return "v8::internal::JSArrayBufferView";
}

void TqJSArrayBufferView::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSArrayBufferView(this);
}

bool TqJSArrayBufferView::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSArrayBufferView*>(other) != nullptr;
}

uintptr_t TqJSArrayBufferView::GetBufferAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSArrayBufferView::GetBufferValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBufferAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSArrayBufferView::GetRawByteOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSArrayBufferView::GetRawByteOffsetValue(d::MemoryAccessor accessor) const {
  uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetRawByteOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSArrayBufferView::GetRawByteLengthAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSArrayBufferView::GetRawByteLengthValue(d::MemoryAccessor accessor) const {
  uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetRawByteLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSArrayBufferView::GetBitFieldAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSArrayBufferView::GetBitFieldValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetBitFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSArrayBufferView::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 52;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSArrayBufferView::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSArrayBufferView::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObjectWithEmbedderSlots::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> buffer_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("buffer", "v8::internal::JSArrayBuffer", "v8::internal::JSArrayBuffer", GetBufferAddress(), 1, 8, std::move(buffer_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> raw_byte_offset_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw_byte_offset", CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), GetRawByteOffsetAddress(), 1, 8, std::move(raw_byte_offset_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> raw_byte_length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw_byte_length", CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), GetRawByteLengthAddress(), 1, 8, std::move(raw_byte_length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bit_field_struct_field_list;
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_length_tracking", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 0));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_backed_by_rab", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 1));
  result.push_back(std::make_unique<ObjectProperty>("bit_field", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetBitFieldAddress(), 1, 4, std::move(bit_field_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTypedArray::GetName() const {
  return "v8::internal::JSTypedArray";
}

void TqJSTypedArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTypedArray(this);
}

bool TqJSTypedArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTypedArray*>(other) != nullptr;
}

uintptr_t TqJSTypedArray::GetRawLengthAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSTypedArray::GetRawLengthValue(d::MemoryAccessor accessor) const {
  uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetRawLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSTypedArray::GetExternalPointerAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSTypedArray::GetExternalPointerValue(d::MemoryAccessor accessor) const {
  Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetExternalPointerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSTypedArray::GetBasePointerAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqJSTypedArray::GetBasePointerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBasePointerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTypedArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArrayBufferView::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> raw_length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw_length", CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), GetRawLengthAddress(), 1, 8, std::move(raw_length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> external_pointer_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("external_pointer", CheckTypeName<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Address"), CheckTypeName<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Address"), GetExternalPointerAddress(), 1, 8, std::move(external_pointer_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> base_pointer_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("base_pointer", "v8::internal::Object", "v8::internal::Object", GetBasePointerAddress(), 1, 8, std::move(base_pointer_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqDataHandler::GetName() const {
  return "v8::internal::DataHandler";
}

void TqDataHandler::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitDataHandler(this);
}

bool TqDataHandler::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqDataHandler*>(other) != nullptr;
}

uintptr_t TqDataHandler::GetSmiHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqDataHandler::GetSmiHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSmiHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDataHandler::GetValidityCellAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqDataHandler::GetValidityCellValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValidityCellAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDataHandler::GetData1Address() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqDataHandler::GetData1Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetData1Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDataHandler::GetData2Address() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqDataHandler::GetData2Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetData2Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDataHandler::GetData3Address() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqDataHandler::GetData3Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetData3Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqDataHandler::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> smi_handler_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("smi_handler", "v8::internal::Object", "v8::internal::Object", GetSmiHandlerAddress(), 1, 8, std::move(smi_handler_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> validity_cell_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("validity_cell", "v8::internal::Object", "v8::internal::Object", GetValidityCellAddress(), 1, 8, std::move(validity_cell_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> data1_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data1", "v8::internal::Object", "v8::internal::Object", GetData1Address(), 1, 8, std::move(data1_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> data2_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data2", "v8::internal::Object", "v8::internal::Object", GetData2Address(), 1, 8, std::move(data2_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> data3_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data3", "v8::internal::Object", "v8::internal::Object", GetData3Address(), 1, 8, std::move(data3_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqAllocationMemento::GetName() const {
  return "v8::internal::AllocationMemento";
}

void TqAllocationMemento::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAllocationMemento(this);
}

bool TqAllocationMemento::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAllocationMemento*>(other) != nullptr;
}

uintptr_t TqAllocationMemento::GetAllocationSiteAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAllocationMemento::GetAllocationSiteValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAllocationSiteAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAllocationMemento::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> allocation_site_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("allocation_site", "v8::internal::AllocationSite", "v8::internal::AllocationSite", GetAllocationSiteAddress(), 1, 8, std::move(allocation_site_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqCallHandlerInfo::GetName() const {
  return "v8::internal::CallHandlerInfo";
}

void TqCallHandlerInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitCallHandlerInfo(this);
}

bool TqCallHandlerInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqCallHandlerInfo*>(other) != nullptr;
}

uintptr_t TqCallHandlerInfo::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqCallHandlerInfo::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallHandlerInfo::GetOwnerTemplateAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqCallHandlerInfo::GetOwnerTemplateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOwnerTemplateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallHandlerInfo::GetMaybeRedirectedCallbackAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqCallHandlerInfo::GetMaybeRedirectedCallbackValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetMaybeRedirectedCallbackAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqCallHandlerInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::Object", "v8::internal::Object", GetDataAddress(), 1, 8, std::move(data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> owner_template_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("owner_template", "v8::internal::TemplateInfo", "v8::internal::TemplateInfo", GetOwnerTemplateAddress(), 1, 8, std::move(owner_template_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> maybe_redirected_callback_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("maybe_redirected_callback", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetMaybeRedirectedCallbackAddress(), 1, 8, std::move(maybe_redirected_callback_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqInterceptorInfo::GetName() const {
  return "v8::internal::InterceptorInfo";
}

void TqInterceptorInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitInterceptorInfo(this);
}

bool TqInterceptorInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqInterceptorInfo*>(other) != nullptr;
}

uintptr_t TqInterceptorInfo::GetGetterAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqInterceptorInfo::GetGetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetSetterAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqInterceptorInfo::GetSetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetQueryAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqInterceptorInfo::GetQueryValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetQueryAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetDescriptorAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqInterceptorInfo::GetDescriptorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDescriptorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetDeleterAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqInterceptorInfo::GetDeleterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDeleterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetEnumeratorAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqInterceptorInfo::GetEnumeratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEnumeratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetDefinerAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqInterceptorInfo::GetDefinerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDefinerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqInterceptorInfo::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqInterceptorInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqInterceptorInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> getter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("getter", "v8::internal::Object", "v8::internal::Object", GetGetterAddress(), 1, 8, std::move(getter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> setter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("setter", "v8::internal::Object", "v8::internal::Object", GetSetterAddress(), 1, 8, std::move(setter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> query_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("query", "v8::internal::Object", "v8::internal::Object", GetQueryAddress(), 1, 8, std::move(query_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> descriptor_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("descriptor", "v8::internal::Object", "v8::internal::Object", GetDescriptorAddress(), 1, 8, std::move(descriptor_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> deleter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("deleter", "v8::internal::Object", "v8::internal::Object", GetDeleterAddress(), 1, 8, std::move(deleter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> enumerator_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("enumerator", "v8::internal::Object", "v8::internal::Object", GetEnumeratorAddress(), 1, 8, std::move(enumerator_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> definer_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("definer", "v8::internal::Object", "v8::internal::Object", GetDefinerAddress(), 1, 8, std::move(definer_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::Object", "v8::internal::Object", GetDataAddress(), 1, 8, std::move(data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("can_intercept_symbols", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("all_can_read", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 33));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("non_masking", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 34));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("named", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 35));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_no_side_effect", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 36));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqAccessCheckInfo::GetName() const {
  return "v8::internal::AccessCheckInfo";
}

void TqAccessCheckInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAccessCheckInfo(this);
}

bool TqAccessCheckInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAccessCheckInfo*>(other) != nullptr;
}

uintptr_t TqAccessCheckInfo::GetCallbackAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAccessCheckInfo::GetCallbackValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallbackAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessCheckInfo::GetNamedInterceptorAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqAccessCheckInfo::GetNamedInterceptorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNamedInterceptorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessCheckInfo::GetIndexedInterceptorAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqAccessCheckInfo::GetIndexedInterceptorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexedInterceptorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessCheckInfo::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqAccessCheckInfo::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAccessCheckInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> callback_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("callback", "v8::internal::Object", "v8::internal::Object", GetCallbackAddress(), 1, 8, std::move(callback_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> named_interceptor_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("named_interceptor", "v8::internal::Object", "v8::internal::Object", GetNamedInterceptorAddress(), 1, 8, std::move(named_interceptor_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> indexed_interceptor_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("indexed_interceptor", "v8::internal::Object", "v8::internal::Object", GetIndexedInterceptorAddress(), 1, 8, std::move(indexed_interceptor_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::Object", "v8::internal::Object", GetDataAddress(), 1, 8, std::move(data_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqAccessorInfo::GetName() const {
  return "v8::internal::AccessorInfo";
}

void TqAccessorInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAccessorInfo(this);
}

bool TqAccessorInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAccessorInfo*>(other) != nullptr;
}

uintptr_t TqAccessorInfo::GetNameAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAccessorInfo::GetNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessorInfo::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqAccessorInfo::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessorInfo::GetMaybeRedirectedGetterAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqAccessorInfo::GetMaybeRedirectedGetterValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetMaybeRedirectedGetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqAccessorInfo::GetSetterAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqAccessorInfo::GetSetterValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetSetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqAccessorInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqAccessorInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqAccessorInfo::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqAccessorInfo::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAccessorInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("name", "v8::internal::Name", "v8::internal::Name", GetNameAddress(), 1, 8, std::move(name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::Object", "v8::internal::Object", GetDataAddress(), 1, 8, std::move(data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> maybe_redirected_getter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("maybe_redirected_getter", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetMaybeRedirectedGetterAddress(), 1, 8, std::move(maybe_redirected_getter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> setter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("setter", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetSetterAddress(), 1, 8, std::move(setter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("all_can_read", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 0));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("all_can_write", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 1));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_special_data_property", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 2));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_sloppy", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 3));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("replace_on_access", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 4));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("getter_side_effect_type", CheckTypeName<SideEffectType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("SideEffectType"), CheckTypeName<SideEffectType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("SideEffectType"), 0, 2, 5));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("setter_side_effect_type", CheckTypeName<SideEffectType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("SideEffectType"), CheckTypeName<SideEffectType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("SideEffectType"), 0, 2, 7));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("initial_attributes", CheckTypeName<PropertyAttributes /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("PropertyAttributes"), CheckTypeName<PropertyAttributes /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("PropertyAttributes"), 0, 3, 9));
  result.push_back(std::make_unique<ObjectProperty>("flags", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetFlagsAddress(), 1, 4, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSArgumentsObject::GetName() const {
  return "v8::internal::JSArgumentsObject";
}

void TqJSArgumentsObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSArgumentsObject(this);
}

bool TqJSArgumentsObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSArgumentsObject*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSArgumentsObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSStrictArgumentsObject::GetName() const {
  return "v8::internal::JSStrictArgumentsObject";
}

void TqJSStrictArgumentsObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSStrictArgumentsObject(this);
}

bool TqJSStrictArgumentsObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSStrictArgumentsObject*>(other) != nullptr;
}

uintptr_t TqJSStrictArgumentsObject::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSStrictArgumentsObject::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSStrictArgumentsObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArgumentsObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::Object", "v8::internal::Object", GetLengthAddress(), 1, 8, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSSloppyArgumentsObject::GetName() const {
  return "v8::internal::JSSloppyArgumentsObject";
}

void TqJSSloppyArgumentsObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSloppyArgumentsObject(this);
}

bool TqJSSloppyArgumentsObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSloppyArgumentsObject*>(other) != nullptr;
}

uintptr_t TqJSSloppyArgumentsObject::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSSloppyArgumentsObject::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSloppyArgumentsObject::GetCalleeAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSSloppyArgumentsObject::GetCalleeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCalleeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSloppyArgumentsObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArgumentsObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::Object", "v8::internal::Object", GetLengthAddress(), 1, 8, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> callee_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("callee", "v8::internal::Object", "v8::internal::Object", GetCalleeAddress(), 1, 8, std::move(callee_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqSloppyArgumentsElements::GetName() const {
  return "v8::internal::SloppyArgumentsElements";
}

void TqSloppyArgumentsElements::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSloppyArgumentsElements(this);
}

bool TqSloppyArgumentsElements::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSloppyArgumentsElements*>(other) != nullptr;
}

uintptr_t TqSloppyArgumentsElements::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSloppyArgumentsElements::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSloppyArgumentsElements::GetArgumentsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqSloppyArgumentsElements::GetArgumentsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetArgumentsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSloppyArgumentsElements::GetMappedEntriesAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqSloppyArgumentsElements::GetMappedEntriesValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMappedEntriesAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSloppyArgumentsElements::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::Context", "v8::internal::Context", GetContextAddress(), 1, 8, std::move(context_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> arguments_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("arguments", "v8::internal::FixedArray", "v8::internal::FixedArray", GetArgumentsAddress(), 1, 8, std::move(arguments_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> mapped_entries_struct_field_list;
  auto indexed_field_slice_mapped_entries = TqDebugFieldSliceSloppyArgumentsElementsMappedEntries(accessor, address_);
  if (indexed_field_slice_mapped_entries.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("mapped_entries", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_mapped_entries.value), std::get<2>(indexed_field_slice_mapped_entries.value), 8, std::move(mapped_entries_struct_field_list), GetArrayKind(indexed_field_slice_mapped_entries.validity)));
  }
  return result;
}

const char* TqAliasedArgumentsEntry::GetName() const {
  return "v8::internal::AliasedArgumentsEntry";
}

void TqAliasedArgumentsEntry::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAliasedArgumentsEntry(this);
}

bool TqAliasedArgumentsEntry::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAliasedArgumentsEntry*>(other) != nullptr;
}

uintptr_t TqAliasedArgumentsEntry::GetAliasedContextSlotAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAliasedArgumentsEntry::GetAliasedContextSlotValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAliasedContextSlotAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAliasedArgumentsEntry::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> aliased_context_slot_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("aliased_context_slot", "v8::internal::Object", "v8::internal::Object", GetAliasedContextSlotAddress(), 1, 8, std::move(aliased_context_slot_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqCallSiteInfo::GetName() const {
  return "v8::internal::CallSiteInfo";
}

void TqCallSiteInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitCallSiteInfo(this);
}

bool TqCallSiteInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqCallSiteInfo*>(other) != nullptr;
}

uintptr_t TqCallSiteInfo::GetReceiverOrInstanceAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqCallSiteInfo::GetReceiverOrInstanceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetReceiverOrInstanceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallSiteInfo::GetFunctionAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqCallSiteInfo::GetFunctionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallSiteInfo::GetCodeObjectAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqCallSiteInfo::GetCodeObjectValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCodeObjectAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallSiteInfo::GetCodeOffsetOrSourcePositionAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqCallSiteInfo::GetCodeOffsetOrSourcePositionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCodeOffsetOrSourcePositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallSiteInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqCallSiteInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallSiteInfo::GetParametersAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqCallSiteInfo::GetParametersValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParametersAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqCallSiteInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> receiver_or_instance_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("receiver_or_instance", "v8::internal::Object", "v8::internal::Object", GetReceiverOrInstanceAddress(), 1, 8, std::move(receiver_or_instance_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> function_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("function", "v8::internal::Object", "v8::internal::Object", GetFunctionAddress(), 1, 8, std::move(function_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> code_object_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("code_object", "v8::internal::HeapObject", "v8::internal::HeapObject", GetCodeObjectAddress(), 1, 8, std::move(code_object_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> code_offset_or_source_position_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("code_offset_or_source_position", "v8::internal::Object", "v8::internal::Object", GetCodeOffsetOrSourcePositionAddress(), 1, 8, std::move(code_offset_or_source_position_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_wasm", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_asm_js_wasm", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 33));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_strict", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 34));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_constructor", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 35));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_asm_js_at_number_conversion", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 36));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_async", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 37));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_builtin", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 38));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_source_position_computed", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 39));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> parameters_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("parameters", "v8::internal::FixedArray", "v8::internal::FixedArray", GetParametersAddress(), 1, 8, std::move(parameters_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqCell::GetName() const {
  return "v8::internal::Cell";
}

void TqCell::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitCell(this);
}

bool TqCell::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqCell*>(other) != nullptr;
}

uintptr_t TqCell::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqCell::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqCell::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::Object", "v8::internal::Object", GetValueAddress(), 1, 8, std::move(value_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqBytecodeArray::GetName() const {
  return "v8::internal::BytecodeArray";
}

void TqBytecodeArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitBytecodeArray(this);
}

bool TqBytecodeArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqBytecodeArray*>(other) != nullptr;
}

uintptr_t TqBytecodeArray::GetConstantPoolAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqBytecodeArray::GetConstantPoolValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetConstantPoolAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqBytecodeArray::GetHandlerTableAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqBytecodeArray::GetHandlerTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHandlerTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqBytecodeArray::GetSourcePositionTableAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqBytecodeArray::GetSourcePositionTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourcePositionTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqBytecodeArray::GetFrameSizeAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqBytecodeArray::GetFrameSizeValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFrameSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqBytecodeArray::GetParameterSizeAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqBytecodeArray::GetParameterSizeValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetParameterSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqBytecodeArray::GetIncomingNewTargetOrGeneratorRegisterAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqBytecodeArray::GetIncomingNewTargetOrGeneratorRegisterValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetIncomingNewTargetOrGeneratorRegisterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqBytecodeArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> constant_pool_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("constant_pool", "v8::internal::FixedArray", "v8::internal::FixedArray", GetConstantPoolAddress(), 1, 8, std::move(constant_pool_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> handler_table_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("handler_table", "v8::internal::ByteArray", "v8::internal::ByteArray", GetHandlerTableAddress(), 1, 8, std::move(handler_table_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> source_position_table_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("source_position_table", "v8::internal::HeapObject", "v8::internal::HeapObject", GetSourcePositionTableAddress(), 1, 8, std::move(source_position_table_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> frame_size_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("frame_size", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetFrameSizeAddress(), 1, 4, std::move(frame_size_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> parameter_size_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("parameter_size", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetParameterSizeAddress(), 1, 4, std::move(parameter_size_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> incoming_new_target_or_generator_register_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("incoming_new_target_or_generator_register", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetIncomingNewTargetOrGeneratorRegisterAddress(), 1, 4, std::move(incoming_new_target_or_generator_register_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqScopeInfo::GetName() const {
  return "v8::internal::ScopeInfo";
}

void TqScopeInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitScopeInfo(this);
}

bool TqScopeInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqScopeInfo*>(other) != nullptr;
}

uintptr_t TqScopeInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqScopeInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScopeInfo::GetParameterCountAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqScopeInfo::GetParameterCountValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParameterCountAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScopeInfo::GetContextLocalCountAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqScopeInfo::GetContextLocalCountValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextLocalCountAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScopeInfo::GetContextLocalNamesAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqScopeInfo::GetContextLocalNamesValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextLocalNamesAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqScopeInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("scope_type", CheckTypeName<ScopeType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ScopeType"), CheckTypeName<ScopeType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ScopeType"), 0, 4, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("sloppy_eval_can_extend_vars", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 36));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("language_mode", CheckTypeName<LanguageMode /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("LanguageMode"), CheckTypeName<LanguageMode /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("LanguageMode"), 0, 1, 37));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("declaration_scope", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 38));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("receiver_variable", CheckTypeName<VariableAllocationInfo /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("VariableAllocationInfo"), CheckTypeName<VariableAllocationInfo /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("VariableAllocationInfo"), 0, 2, 39));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("class_scope_has_private_brand", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 41));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_saved_class_variable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 42));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_new_target", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 43));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("function_variable", CheckTypeName<VariableAllocationInfo /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("VariableAllocationInfo"), CheckTypeName<VariableAllocationInfo /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("VariableAllocationInfo"), 0, 2, 44));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_inferred_function_name", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 46));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_asm_module", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 47));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_simple_parameters", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 48));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("function_kind", CheckTypeName<FunctionKind /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("FunctionKind"), CheckTypeName<FunctionKind /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("FunctionKind"), 0, 5, 49));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_outer_scope_info", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 54));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_debug_evaluate_scope", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 55));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("force_context_allocation", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 56));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("private_name_lookup_skips_outer_class", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 57));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_context_extension_slot", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 58));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_repl_mode_scope", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 59));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_locals_block_list", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 60));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_empty", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 61));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> parameter_count_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("parameter_count", "v8::internal::Object", "v8::internal::Object", GetParameterCountAddress(), 1, 8, std::move(parameter_count_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> context_local_count_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("context_local_count", "v8::internal::Object", "v8::internal::Object", GetContextLocalCountAddress(), 1, 8, std::move(context_local_count_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> context_local_names_struct_field_list;
  auto indexed_field_slice_context_local_names = TqDebugFieldSliceScopeInfoContextLocalNames(accessor, address_);
  if (indexed_field_slice_context_local_names.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("context_local_names", "v8::internal::String", "v8::internal::String", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_context_local_names.value), std::get<2>(indexed_field_slice_context_local_names.value), 8, std::move(context_local_names_struct_field_list), GetArrayKind(indexed_field_slice_context_local_names.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> context_local_names_hashtable_struct_field_list;
  auto indexed_field_slice_context_local_names_hashtable = TqDebugFieldSliceScopeInfoContextLocalNamesHashtable(accessor, address_);
  if (indexed_field_slice_context_local_names_hashtable.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("context_local_names_hashtable", "v8::internal::NameToIndexHashTable", "v8::internal::NameToIndexHashTable", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_context_local_names_hashtable.value), std::get<2>(indexed_field_slice_context_local_names_hashtable.value), 8, std::move(context_local_names_hashtable_struct_field_list), GetArrayKind(indexed_field_slice_context_local_names_hashtable.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> context_local_infos_struct_field_list;
  context_local_infos_struct_field_list.push_back(std::make_unique<StructProperty>("variable_mode", CheckTypeName<VariableMode /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("VariableMode"), CheckTypeName<VariableMode /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("VariableMode"), 0, 4, 32));
  context_local_infos_struct_field_list.push_back(std::make_unique<StructProperty>("init_flag", CheckTypeName<InitializationFlag /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("InitializationFlag"), CheckTypeName<InitializationFlag /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("InitializationFlag"), 0, 1, 36));
  context_local_infos_struct_field_list.push_back(std::make_unique<StructProperty>("maybe_assigned_flag", CheckTypeName<MaybeAssignedFlag /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("MaybeAssignedFlag"), CheckTypeName<MaybeAssignedFlag /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("MaybeAssignedFlag"), 0, 1, 37));
  context_local_infos_struct_field_list.push_back(std::make_unique<StructProperty>("parameter_number", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), 0, 16, 38));
  context_local_infos_struct_field_list.push_back(std::make_unique<StructProperty>("is_static_flag", CheckTypeName<IsStaticFlag /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("IsStaticFlag"), CheckTypeName<IsStaticFlag /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("IsStaticFlag"), 0, 1, 54));
  auto indexed_field_slice_context_local_infos = TqDebugFieldSliceScopeInfoContextLocalInfos(accessor, address_);
  if (indexed_field_slice_context_local_infos.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("context_local_infos", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_context_local_infos.value), std::get<2>(indexed_field_slice_context_local_infos.value), 8, std::move(context_local_infos_struct_field_list), GetArrayKind(indexed_field_slice_context_local_infos.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> saved_class_variable_info_struct_field_list;
  auto indexed_field_slice_saved_class_variable_info = TqDebugFieldSliceScopeInfoSavedClassVariableInfo(accessor, address_);
  if (indexed_field_slice_saved_class_variable_info.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("saved_class_variable_info", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_saved_class_variable_info.value), std::get<2>(indexed_field_slice_saved_class_variable_info.value), 8, std::move(saved_class_variable_info_struct_field_list), GetArrayKind(indexed_field_slice_saved_class_variable_info.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> function_variable_info_struct_field_list;
  function_variable_info_struct_field_list.push_back(std::make_unique<StructProperty>("name", "v8::internal::Object", "v8::internal::Object", 0, 0, 0));
  function_variable_info_struct_field_list.push_back(std::make_unique<StructProperty>("context_or_stack_slot_index", "v8::internal::Object", "v8::internal::Object", 8, 0, 0));
  auto indexed_field_slice_function_variable_info = TqDebugFieldSliceScopeInfoFunctionVariableInfo(accessor, address_);
  if (indexed_field_slice_function_variable_info.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("function_variable_info", "", "", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_function_variable_info.value), std::get<2>(indexed_field_slice_function_variable_info.value), 16, std::move(function_variable_info_struct_field_list), GetArrayKind(indexed_field_slice_function_variable_info.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> inferred_function_name_struct_field_list;
  auto indexed_field_slice_inferred_function_name = TqDebugFieldSliceScopeInfoInferredFunctionName(accessor, address_);
  if (indexed_field_slice_inferred_function_name.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("inferred_function_name", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_inferred_function_name.value), std::get<2>(indexed_field_slice_inferred_function_name.value), 8, std::move(inferred_function_name_struct_field_list), GetArrayKind(indexed_field_slice_inferred_function_name.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> position_info_struct_field_list;
  position_info_struct_field_list.push_back(std::make_unique<StructProperty>("start", "v8::internal::Object", "v8::internal::Object", 0, 0, 0));
  position_info_struct_field_list.push_back(std::make_unique<StructProperty>("end", "v8::internal::Object", "v8::internal::Object", 8, 0, 0));
  auto indexed_field_slice_position_info = TqDebugFieldSliceScopeInfoPositionInfo(accessor, address_);
  if (indexed_field_slice_position_info.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("position_info", "", "", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_position_info.value), std::get<2>(indexed_field_slice_position_info.value), 16, std::move(position_info_struct_field_list), GetArrayKind(indexed_field_slice_position_info.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> outer_scope_info_struct_field_list;
  auto indexed_field_slice_outer_scope_info = TqDebugFieldSliceScopeInfoOuterScopeInfo(accessor, address_);
  if (indexed_field_slice_outer_scope_info.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("outer_scope_info", "v8::internal::HeapObject", "v8::internal::HeapObject", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_outer_scope_info.value), std::get<2>(indexed_field_slice_outer_scope_info.value), 8, std::move(outer_scope_info_struct_field_list), GetArrayKind(indexed_field_slice_outer_scope_info.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> locals_block_list_struct_field_list;
  auto indexed_field_slice_locals_block_list = TqDebugFieldSliceScopeInfoLocalsBlockList(accessor, address_);
  if (indexed_field_slice_locals_block_list.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("locals_block_list", "v8::internal::FixedArray", "v8::internal::FixedArray", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_locals_block_list.value), std::get<2>(indexed_field_slice_locals_block_list.value), 8, std::move(locals_block_list_struct_field_list), GetArrayKind(indexed_field_slice_locals_block_list.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> module_info_struct_field_list;
  auto indexed_field_slice_module_info = TqDebugFieldSliceScopeInfoModuleInfo(accessor, address_);
  if (indexed_field_slice_module_info.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("module_info", "v8::internal::FixedArray", "v8::internal::FixedArray", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_module_info.value), std::get<2>(indexed_field_slice_module_info.value), 8, std::move(module_info_struct_field_list), GetArrayKind(indexed_field_slice_module_info.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> module_variable_count_struct_field_list;
  auto indexed_field_slice_module_variable_count = TqDebugFieldSliceScopeInfoModuleVariableCount(accessor, address_);
  if (indexed_field_slice_module_variable_count.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("module_variable_count", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_module_variable_count.value), std::get<2>(indexed_field_slice_module_variable_count.value), 8, std::move(module_variable_count_struct_field_list), GetArrayKind(indexed_field_slice_module_variable_count.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> module_variables_struct_field_list;
  module_variables_struct_field_list.push_back(std::make_unique<StructProperty>("name", "v8::internal::String", "v8::internal::String", 0, 0, 0));
  module_variables_struct_field_list.push_back(std::make_unique<StructProperty>("index", "v8::internal::Object", "v8::internal::Object", 8, 0, 0));
  module_variables_struct_field_list.push_back(std::make_unique<StructProperty>("properties", "v8::internal::Object", "v8::internal::Object", 16, 0, 0));
  auto indexed_field_slice_module_variables = TqDebugFieldSliceScopeInfoModuleVariables(accessor, address_);
  if (indexed_field_slice_module_variables.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("module_variables", "", "", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_module_variables.value), std::get<2>(indexed_field_slice_module_variables.value), 24, std::move(module_variables_struct_field_list), GetArrayKind(indexed_field_slice_module_variables.validity)));
  }
  return result;
}

const char* TqFixedDoubleArray::GetName() const {
  return "v8::internal::FixedDoubleArray";
}

void TqFixedDoubleArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFixedDoubleArray(this);
}

bool TqFixedDoubleArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFixedDoubleArray*>(other) != nullptr;
}

uintptr_t TqFixedDoubleArray::GetFloatsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

std::vector<std::unique_ptr<ObjectProperty>> TqFixedDoubleArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> floats_struct_field_list;
  auto indexed_field_slice_floats = TqDebugFieldSliceFixedDoubleArrayFloats(accessor, address_);
  if (indexed_field_slice_floats.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("floats", "", "", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_floats.value), std::get<2>(indexed_field_slice_floats.value), 8, std::move(floats_struct_field_list), GetArrayKind(indexed_field_slice_floats.validity)));
  }
  return result;
}

const char* TqRegExpMatchInfo::GetName() const {
  return "v8::internal::RegExpMatchInfo";
}

void TqRegExpMatchInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitRegExpMatchInfo(this);
}

bool TqRegExpMatchInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqRegExpMatchInfo*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqRegExpMatchInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArray::GetProperties(accessor);
  return result;
}

const char* TqBreakPoint::GetName() const {
  return "v8::internal::BreakPoint";
}

void TqBreakPoint::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitBreakPoint(this);
}

bool TqBreakPoint::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqBreakPoint*>(other) != nullptr;
}

uintptr_t TqBreakPoint::GetIdAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqBreakPoint::GetIdValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqBreakPoint::GetConditionAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqBreakPoint::GetConditionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetConditionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqBreakPoint::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> id_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("id", "v8::internal::Object", "v8::internal::Object", GetIdAddress(), 1, 8, std::move(id_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> condition_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("condition", "v8::internal::String", "v8::internal::String", GetConditionAddress(), 1, 8, std::move(condition_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqBreakPointInfo::GetName() const {
  return "v8::internal::BreakPointInfo";
}

void TqBreakPointInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitBreakPointInfo(this);
}

bool TqBreakPointInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqBreakPointInfo*>(other) != nullptr;
}

uintptr_t TqBreakPointInfo::GetSourcePositionAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqBreakPointInfo::GetSourcePositionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourcePositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqBreakPointInfo::GetBreakPointsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqBreakPointInfo::GetBreakPointsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBreakPointsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqBreakPointInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> source_position_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("source_position", "v8::internal::Object", "v8::internal::Object", GetSourcePositionAddress(), 1, 8, std::move(source_position_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> break_points_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("break_points", "v8::internal::HeapObject", "v8::internal::HeapObject", GetBreakPointsAddress(), 1, 8, std::move(break_points_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqDebugInfo::GetName() const {
  return "v8::internal::DebugInfo";
}

void TqDebugInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitDebugInfo(this);
}

bool TqDebugInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqDebugInfo*>(other) != nullptr;
}

uintptr_t TqDebugInfo::GetSharedAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqDebugInfo::GetSharedValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetDebuggerHintsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqDebugInfo::GetDebuggerHintsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDebuggerHintsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetOriginalBytecodeArrayAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqDebugInfo::GetOriginalBytecodeArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOriginalBytecodeArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetDebugBytecodeArrayAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqDebugInfo::GetDebugBytecodeArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDebugBytecodeArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetBreakPointsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqDebugInfo::GetBreakPointsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBreakPointsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqDebugInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetCoverageInfoAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqDebugInfo::GetCoverageInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCoverageInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqDebugInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> shared_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("shared", "v8::internal::SharedFunctionInfo", "v8::internal::SharedFunctionInfo", GetSharedAddress(), 1, 8, std::move(shared_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> debugger_hints_struct_field_list;
  debugger_hints_struct_field_list.push_back(std::make_unique<StructProperty>("side_effect_state", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 2, 32));
  debugger_hints_struct_field_list.push_back(std::make_unique<StructProperty>("debug_is_blackboxed", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 34));
  debugger_hints_struct_field_list.push_back(std::make_unique<StructProperty>("computed_debug_is_blackboxed", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 35));
  debugger_hints_struct_field_list.push_back(std::make_unique<StructProperty>("debugging_id", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 20, 36));
  result.push_back(std::make_unique<ObjectProperty>("debugger_hints", "v8::internal::Object", "v8::internal::Object", GetDebuggerHintsAddress(), 1, 8, std::move(debugger_hints_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> original_bytecode_array_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("original_bytecode_array", "v8::internal::HeapObject", "v8::internal::HeapObject", GetOriginalBytecodeArrayAddress(), 1, 8, std::move(original_bytecode_array_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> debug_bytecode_array_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("debug_bytecode_array", "v8::internal::HeapObject", "v8::internal::HeapObject", GetDebugBytecodeArrayAddress(), 1, 8, std::move(debug_bytecode_array_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> break_points_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("break_points", "v8::internal::FixedArray", "v8::internal::FixedArray", GetBreakPointsAddress(), 1, 8, std::move(break_points_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_break_info", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("prepared_for_debug_execution", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 33));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_coverage_info", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 34));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("break_at_entry", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 35));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("can_break_at_entry", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 36));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("debug_execution_mode", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 37));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> coverage_info_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("coverage_info", "v8::internal::HeapObject", "v8::internal::HeapObject", GetCoverageInfoAddress(), 1, 8, std::move(coverage_info_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqCoverageInfo::GetName() const {
  return "v8::internal::CoverageInfo";
}

void TqCoverageInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitCoverageInfo(this);
}

bool TqCoverageInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqCoverageInfo*>(other) != nullptr;
}

uintptr_t TqCoverageInfo::GetSlotCountAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqCoverageInfo::GetSlotCountValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetSlotCountAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqCoverageInfo::GetSlotsAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

std::vector<std::unique_ptr<ObjectProperty>> TqCoverageInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> slot_count_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("slot_count", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetSlotCountAddress(), 1, 4, std::move(slot_count_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> slots_struct_field_list;
  slots_struct_field_list.push_back(std::make_unique<StructProperty>("start_source_position", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 0, 0));
  slots_struct_field_list.push_back(std::make_unique<StructProperty>("end_source_position", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 4, 0, 0));
  slots_struct_field_list.push_back(std::make_unique<StructProperty>("block_count", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 8, 0, 0));
  slots_struct_field_list.push_back(std::make_unique<StructProperty>("padding", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 12, 0, 0));
  auto indexed_field_slice_slots = TqDebugFieldSliceCoverageInfoSlots(accessor, address_);
  if (indexed_field_slice_slots.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("slots", "", "", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_slots.value), std::get<2>(indexed_field_slice_slots.value), 16, std::move(slots_struct_field_list), GetArrayKind(indexed_field_slice_slots.validity)));
  }
  return result;
}

const char* TqStackFrameInfo::GetName() const {
  return "v8::internal::StackFrameInfo";
}

void TqStackFrameInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitStackFrameInfo(this);
}

bool TqStackFrameInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqStackFrameInfo*>(other) != nullptr;
}

uintptr_t TqStackFrameInfo::GetSharedOrScriptAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqStackFrameInfo::GetSharedOrScriptValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedOrScriptAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetFunctionNameAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqStackFrameInfo::GetFunctionNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqStackFrameInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqStackFrameInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> shared_or_script_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("shared_or_script", "v8::internal::HeapObject", "v8::internal::HeapObject", GetSharedOrScriptAddress(), 1, 8, std::move(shared_or_script_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> function_name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("function_name", "v8::internal::String", "v8::internal::String", GetFunctionNameAddress(), 1, 8, std::move(function_name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_constructor", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("bytecode_offset_or_source_position", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 30, 33));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqErrorStackData::GetName() const {
  return "v8::internal::ErrorStackData";
}

void TqErrorStackData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitErrorStackData(this);
}

bool TqErrorStackData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqErrorStackData*>(other) != nullptr;
}

uintptr_t TqErrorStackData::GetCallSiteInfosOrFormattedStackAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqErrorStackData::GetCallSiteInfosOrFormattedStackValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallSiteInfosOrFormattedStackAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqErrorStackData::GetLimitOrStackFrameInfosAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqErrorStackData::GetLimitOrStackFrameInfosValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLimitOrStackFrameInfosAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqErrorStackData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> call_site_infos_or_formatted_stack_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("call_site_infos_or_formatted_stack", "v8::internal::Object", "v8::internal::Object", GetCallSiteInfosOrFormattedStackAddress(), 1, 8, std::move(call_site_infos_or_formatted_stack_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> limit_or_stack_frame_infos_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("limit_or_stack_frame_infos", "v8::internal::Object", "v8::internal::Object", GetLimitOrStackFrameInfosAddress(), 1, 8, std::move(limit_or_stack_frame_infos_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqPromiseOnStack::GetName() const {
  return "v8::internal::PromiseOnStack";
}

void TqPromiseOnStack::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseOnStack(this);
}

bool TqPromiseOnStack::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseOnStack*>(other) != nullptr;
}

uintptr_t TqPromiseOnStack::GetPrevAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPromiseOnStack::GetPrevValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrevAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseOnStack::GetPromiseAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPromiseOnStack::GetPromiseValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseOnStack::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> prev_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("prev", "v8::internal::Object", "v8::internal::Object", GetPrevAddress(), 1, 8, std::move(prev_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> promise_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("promise", "v8::internal::Object", "v8::internal::Object", GetPromiseAddress(), 1, 8, std::move(promise_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqEnumCache::GetName() const {
  return "v8::internal::EnumCache";
}

void TqEnumCache::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitEnumCache(this);
}

bool TqEnumCache::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqEnumCache*>(other) != nullptr;
}

uintptr_t TqEnumCache::GetKeysAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqEnumCache::GetKeysValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKeysAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqEnumCache::GetIndicesAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqEnumCache::GetIndicesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndicesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqEnumCache::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> keys_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("keys", "v8::internal::FixedArray", "v8::internal::FixedArray", GetKeysAddress(), 1, 8, std::move(keys_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> indices_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("indices", "v8::internal::FixedArray", "v8::internal::FixedArray", GetIndicesAddress(), 1, 8, std::move(indices_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqClassPositions::GetName() const {
  return "v8::internal::ClassPositions";
}

void TqClassPositions::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitClassPositions(this);
}

bool TqClassPositions::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqClassPositions*>(other) != nullptr;
}

uintptr_t TqClassPositions::GetStartAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqClassPositions::GetStartValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStartAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqClassPositions::GetEndAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqClassPositions::GetEndValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEndAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqClassPositions::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> start_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("start", "v8::internal::Object", "v8::internal::Object", GetStartAddress(), 1, 8, std::move(start_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> end_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("end", "v8::internal::Object", "v8::internal::Object", GetEndAddress(), 1, 8, std::move(end_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqAccessorPair::GetName() const {
  return "v8::internal::AccessorPair";
}

void TqAccessorPair::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAccessorPair(this);
}

bool TqAccessorPair::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAccessorPair*>(other) != nullptr;
}

uintptr_t TqAccessorPair::GetGetterAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAccessorPair::GetGetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessorPair::GetSetterAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqAccessorPair::GetSetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAccessorPair::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> getter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("getter", "v8::internal::Object", "v8::internal::Object", GetGetterAddress(), 1, 8, std::move(getter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> setter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("setter", "v8::internal::Object", "v8::internal::Object", GetSetterAddress(), 1, 8, std::move(setter_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqDescriptorArray::GetName() const {
  return "v8::internal::DescriptorArray";
}

void TqDescriptorArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitDescriptorArray(this);
}

bool TqDescriptorArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqDescriptorArray*>(other) != nullptr;
}

uintptr_t TqDescriptorArray::GetNumberOfAllDescriptorsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqDescriptorArray::GetNumberOfAllDescriptorsValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfAllDescriptorsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqDescriptorArray::GetNumberOfDescriptorsAddress() const {
  return address_ - i::kHeapObjectTag + 10;
}

Value<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqDescriptorArray::GetNumberOfDescriptorsValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfDescriptorsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqDescriptorArray::GetRawGcStateAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqDescriptorArray::GetRawGcStateValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetRawGcStateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqDescriptorArray::GetEnumCacheAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqDescriptorArray::GetEnumCacheValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEnumCacheAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDescriptorArray::GetDescriptorsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

std::vector<std::unique_ptr<ObjectProperty>> TqDescriptorArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> number_of_all_descriptors_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_all_descriptors", CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), GetNumberOfAllDescriptorsAddress(), 1, 2, std::move(number_of_all_descriptors_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> number_of_descriptors_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_descriptors", CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), GetNumberOfDescriptorsAddress(), 1, 2, std::move(number_of_descriptors_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> raw_gc_state_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw_gc_state", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetRawGcStateAddress(), 1, 4, std::move(raw_gc_state_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> enum_cache_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("enum_cache", "v8::internal::EnumCache", "v8::internal::EnumCache", GetEnumCacheAddress(), 1, 8, std::move(enum_cache_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> descriptors_struct_field_list;
  descriptors_struct_field_list.push_back(std::make_unique<StructProperty>("key", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", 0, 0, 0));
  descriptors_struct_field_list.push_back(std::make_unique<StructProperty>("details", "v8::internal::Object", "v8::internal::Object", 8, 0, 0));
  descriptors_struct_field_list.push_back(std::make_unique<StructProperty>("value", "v8::internal::Object", "v8::internal::Object", 16, 0, 0));
  auto indexed_field_slice_descriptors = TqDebugFieldSliceDescriptorArrayDescriptors(accessor, address_);
  if (indexed_field_slice_descriptors.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("descriptors", "", "", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_descriptors.value), std::get<2>(indexed_field_slice_descriptors.value), 24, std::move(descriptors_struct_field_list), GetArrayKind(indexed_field_slice_descriptors.validity)));
  }
  return result;
}

const char* TqStrongDescriptorArray::GetName() const {
  return "v8::internal::StrongDescriptorArray";
}

void TqStrongDescriptorArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitStrongDescriptorArray(this);
}

bool TqStrongDescriptorArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqStrongDescriptorArray*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqStrongDescriptorArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqDescriptorArray::GetProperties(accessor);
  return result;
}

const char* TqEmbedderDataArray::GetName() const {
  return "v8::internal::EmbedderDataArray";
}

void TqEmbedderDataArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitEmbedderDataArray(this);
}

bool TqEmbedderDataArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqEmbedderDataArray*>(other) != nullptr;
}

uintptr_t TqEmbedderDataArray::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqEmbedderDataArray::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqEmbedderDataArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::Object", "v8::internal::Object", GetLengthAddress(), 1, 8, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqFeedbackCell::GetName() const {
  return "v8::internal::FeedbackCell";
}

void TqFeedbackCell::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFeedbackCell(this);
}

bool TqFeedbackCell::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFeedbackCell*>(other) != nullptr;
}

uintptr_t TqFeedbackCell::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqFeedbackCell::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFeedbackCell::GetInterruptBudgetAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqFeedbackCell::GetInterruptBudgetValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetInterruptBudgetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFeedbackCell::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::HeapObject", "v8::internal::HeapObject", GetValueAddress(), 1, 8, std::move(value_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> interrupt_budget_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("interrupt_budget", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetInterruptBudgetAddress(), 1, 4, std::move(interrupt_budget_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqFeedbackVector::GetName() const {
  return "v8::internal::FeedbackVector";
}

void TqFeedbackVector::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFeedbackVector(this);
}

bool TqFeedbackVector::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFeedbackVector*>(other) != nullptr;
}

uintptr_t TqFeedbackVector::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqFeedbackVector::GetLengthValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqFeedbackVector::GetInvocationCountAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqFeedbackVector::GetInvocationCountValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetInvocationCountAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqFeedbackVector::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqFeedbackVector::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqFeedbackVector::GetPlaceholder0Address() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqFeedbackVector::GetPlaceholder0Value(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetPlaceholder0Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqFeedbackVector::GetOsrStateAddress() const {
  return address_ - i::kHeapObjectTag + 21;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqFeedbackVector::GetOsrStateValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOsrStateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqFeedbackVector::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 22;
}

Value<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqFeedbackVector::GetFlagsValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqFeedbackVector::GetSharedFunctionInfoAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqFeedbackVector::GetSharedFunctionInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedFunctionInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFeedbackVector::GetClosureFeedbackCellArrayAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqFeedbackVector::GetClosureFeedbackCellArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetClosureFeedbackCellArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFeedbackVector::GetParentFeedbackCellAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqFeedbackVector::GetParentFeedbackCellValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParentFeedbackCellAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFeedbackVector::GetMaybeOptimizedCodeAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqFeedbackVector::GetMaybeOptimizedCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMaybeOptimizedCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFeedbackVector::GetRawFeedbackSlotsAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqFeedbackVector::GetRawFeedbackSlotsValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRawFeedbackSlotsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFeedbackVector::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetLengthAddress(), 1, 4, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> invocation_count_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("invocation_count", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetInvocationCountAddress(), 1, 4, std::move(invocation_count_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> placeholder0_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("placeholder0", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetPlaceholder0Address(), 1, 1, std::move(placeholder0_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> osr_state_struct_field_list;
  osr_state_struct_field_list.push_back(std::make_unique<StructProperty>("osr_urgency", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), 0, 3, 0));
  osr_state_struct_field_list.push_back(std::make_unique<StructProperty>("maybe_has_maglev_osr_code", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 3));
  osr_state_struct_field_list.push_back(std::make_unique<StructProperty>("maybe_has_turbofan_osr_code", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 4));
  osr_state_struct_field_list.push_back(std::make_unique<StructProperty>("dont_use_these_bits_unless_beneficial", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), 0, 3, 5));
  result.push_back(std::make_unique<ObjectProperty>("osr_state", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetOsrStateAddress(), 1, 1, std::move(osr_state_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("tiering_state", CheckTypeName<TieringState /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("TieringState"), CheckTypeName<TieringState /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("TieringState"), 0, 3, 0));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("log_next_execution", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 3));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("maybe_has_maglev_code", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 4));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("maybe_has_turbofan_code", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 5));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("osr_tiering_state", CheckTypeName<TieringState /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("TieringState"), CheckTypeName<TieringState /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("TieringState"), 0, 1, 6));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("all_your_bits_are_belong_to_jgruber", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), 0, 9, 7));
  result.push_back(std::make_unique<ObjectProperty>("flags", CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), GetFlagsAddress(), 1, 2, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> shared_function_info_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("shared_function_info", "v8::internal::SharedFunctionInfo", "v8::internal::SharedFunctionInfo", GetSharedFunctionInfoAddress(), 1, 8, std::move(shared_function_info_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> closure_feedback_cell_array_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("closure_feedback_cell_array", "v8::internal::ClosureFeedbackCellArray", "v8::internal::ClosureFeedbackCellArray", GetClosureFeedbackCellArrayAddress(), 1, 8, std::move(closure_feedback_cell_array_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> parent_feedback_cell_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("parent_feedback_cell", "v8::internal::FeedbackCell", "v8::internal::FeedbackCell", GetParentFeedbackCellAddress(), 1, 8, std::move(parent_feedback_cell_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> maybe_optimized_code_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("maybe_optimized_code", "v8::internal::Object", "v8::internal::Object", GetMaybeOptimizedCodeAddress(), 1, 8, std::move(maybe_optimized_code_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> raw_feedback_slots_struct_field_list;
  auto indexed_field_slice_raw_feedback_slots = TqDebugFieldSliceFeedbackVectorRawFeedbackSlots(accessor, address_);
  if (indexed_field_slice_raw_feedback_slots.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("raw_feedback_slots", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_raw_feedback_slots.value), std::get<2>(indexed_field_slice_raw_feedback_slots.value), 8, std::move(raw_feedback_slots_struct_field_list), GetArrayKind(indexed_field_slice_raw_feedback_slots.validity)));
  }
  return result;
}

const char* TqByteArray::GetName() const {
  return "v8::internal::ByteArray";
}

void TqByteArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitByteArray(this);
}

bool TqByteArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqByteArray*>(other) != nullptr;
}

uintptr_t TqByteArray::GetBytesAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqByteArray::GetBytesValue(d::MemoryAccessor accessor, size_t offset) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetBytesAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqByteArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> bytes_struct_field_list;
  auto indexed_field_slice_bytes = TqDebugFieldSliceByteArrayBytes(accessor, address_);
  if (indexed_field_slice_bytes.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("bytes", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_bytes.value), std::get<2>(indexed_field_slice_bytes.value), 1, std::move(bytes_struct_field_list), GetArrayKind(indexed_field_slice_bytes.validity)));
  }
  return result;
}

const char* TqExternalPointerArray::GetName() const {
  return "v8::internal::ExternalPointerArray";
}

void TqExternalPointerArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitExternalPointerArray(this);
}

bool TqExternalPointerArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqExternalPointerArray*>(other) != nullptr;
}

uintptr_t TqExternalPointerArray::GetPointersAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqExternalPointerArray::GetPointersValue(d::MemoryAccessor accessor, size_t offset) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetPointersAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqExternalPointerArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> pointers_struct_field_list;
  auto indexed_field_slice_pointers = TqDebugFieldSliceExternalPointerArrayPointers(accessor, address_);
  if (indexed_field_slice_pointers.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("pointers", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_pointers.value), std::get<2>(indexed_field_slice_pointers.value), 8, std::move(pointers_struct_field_list), GetArrayKind(indexed_field_slice_pointers.validity)));
  }
  return result;
}

const char* TqArrayList::GetName() const {
  return "v8::internal::ArrayList";
}

void TqArrayList::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitArrayList(this);
}

bool TqArrayList::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqArrayList*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqArrayList::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArray::GetProperties(accessor);
  return result;
}

const char* TqTemplateList::GetName() const {
  return "v8::internal::TemplateList";
}

void TqTemplateList::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTemplateList(this);
}

bool TqTemplateList::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTemplateList*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqTemplateList::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArray::GetProperties(accessor);
  return result;
}

const char* TqWeakArrayList::GetName() const {
  return "v8::internal::WeakArrayList";
}

void TqWeakArrayList::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWeakArrayList(this);
}

bool TqWeakArrayList::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWeakArrayList*>(other) != nullptr;
}

uintptr_t TqWeakArrayList::GetCapacityAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWeakArrayList::GetCapacityValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCapacityAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakArrayList::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWeakArrayList::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakArrayList::GetObjectsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWeakArrayList::GetObjectsValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetObjectsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWeakArrayList::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> capacity_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("capacity", "v8::internal::Object", "v8::internal::Object", GetCapacityAddress(), 1, 8, std::move(capacity_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::Object", "v8::internal::Object", GetLengthAddress(), 1, 8, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> objects_struct_field_list;
  auto indexed_field_slice_objects = TqDebugFieldSliceWeakArrayListObjects(accessor, address_);
  if (indexed_field_slice_objects.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("objects", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_objects.value), std::get<2>(indexed_field_slice_objects.value), 8, std::move(objects_struct_field_list), GetArrayKind(indexed_field_slice_objects.validity)));
  }
  return result;
}

const char* TqFreeSpace::GetName() const {
  return "v8::internal::FreeSpace";
}

void TqFreeSpace::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFreeSpace(this);
}

bool TqFreeSpace::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFreeSpace*>(other) != nullptr;
}

uintptr_t TqFreeSpace::GetSizeAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqFreeSpace::GetSizeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFreeSpace::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqFreeSpace::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFreeSpace::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> size_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("size", "v8::internal::Object", "v8::internal::Object", GetSizeAddress(), 1, 8, std::move(size_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> next_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::Object", "v8::internal::Object", GetNextAddress(), 1, 8, std::move(next_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSArrayBuffer::GetName() const {
  return "v8::internal::JSArrayBuffer";
}

void TqJSArrayBuffer::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSArrayBuffer(this);
}

bool TqJSArrayBuffer::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSArrayBuffer*>(other) != nullptr;
}

uintptr_t TqJSArrayBuffer::GetDetachKeyAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSArrayBuffer::GetDetachKeyValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDetachKeyAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSArrayBuffer::GetRawByteLengthAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSArrayBuffer::GetRawByteLengthValue(d::MemoryAccessor accessor) const {
  uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetRawByteLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSArrayBuffer::GetRawMaxByteLengthAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSArrayBuffer::GetRawMaxByteLengthValue(d::MemoryAccessor accessor) const {
  uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetRawMaxByteLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSArrayBuffer::GetBackingStoreAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSArrayBuffer::GetBackingStoreValue(d::MemoryAccessor accessor) const {
  Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetBackingStoreAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSArrayBuffer::GetExtensionAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSArrayBuffer::GetExtensionValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetExtensionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSArrayBuffer::GetBitFieldAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSArrayBuffer::GetBitFieldValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetBitFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSArrayBuffer::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 68;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSArrayBuffer::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSArrayBuffer::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObjectWithEmbedderSlots::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> detach_key_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("detach_key", "v8::internal::Object", "v8::internal::Object", GetDetachKeyAddress(), 1, 8, std::move(detach_key_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> raw_byte_length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw_byte_length", CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), GetRawByteLengthAddress(), 1, 8, std::move(raw_byte_length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> raw_max_byte_length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw_max_byte_length", CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), GetRawMaxByteLengthAddress(), 1, 8, std::move(raw_max_byte_length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> backing_store_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("backing_store", CheckTypeName<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Address"), CheckTypeName<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Address"), GetBackingStoreAddress(), 1, 8, std::move(backing_store_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> extension_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("extension", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetExtensionAddress(), 1, 8, std::move(extension_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bit_field_struct_field_list;
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_external", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 0));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_detachable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 1));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("was_detached", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 2));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_asm_js_memory", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 3));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_shared", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 4));
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("is_resizable_by_js", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 5));
  result.push_back(std::make_unique<ObjectProperty>("bit_field", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetBitFieldAddress(), 1, 4, std::move(bit_field_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSDataViewOrRabGsabDataView::GetName() const {
  return "v8::internal::JSDataViewOrRabGsabDataView";
}

void TqJSDataViewOrRabGsabDataView::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSDataViewOrRabGsabDataView(this);
}

bool TqJSDataViewOrRabGsabDataView::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSDataViewOrRabGsabDataView*>(other) != nullptr;
}

uintptr_t TqJSDataViewOrRabGsabDataView::GetDataPointerAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSDataViewOrRabGsabDataView::GetDataPointerValue(d::MemoryAccessor accessor) const {
  Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetDataPointerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSDataViewOrRabGsabDataView::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArrayBufferView::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> data_pointer_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data_pointer", CheckTypeName<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Address"), CheckTypeName<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Address"), GetDataPointerAddress(), 1, 8, std::move(data_pointer_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSDataView::GetName() const {
  return "v8::internal::JSDataView";
}

void TqJSDataView::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSDataView(this);
}

bool TqJSDataView::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSDataView*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSDataView::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSDataViewOrRabGsabDataView::GetProperties(accessor);
  return result;
}

const char* TqJSRabGsabDataView::GetName() const {
  return "v8::internal::JSRabGsabDataView";
}

void TqJSRabGsabDataView::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRabGsabDataView(this);
}

bool TqJSRabGsabDataView::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRabGsabDataView*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRabGsabDataView::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSDataViewOrRabGsabDataView::GetProperties(accessor);
  return result;
}

const char* TqJSArrayIterator::GetName() const {
  return "v8::internal::JSArrayIterator";
}

void TqJSArrayIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSArrayIterator(this);
}

bool TqJSArrayIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSArrayIterator*>(other) != nullptr;
}

uintptr_t TqJSArrayIterator::GetIteratedObjectAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSArrayIterator::GetIteratedObjectValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIteratedObjectAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSArrayIterator::GetNextIndexAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSArrayIterator::GetNextIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSArrayIterator::GetKindAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSArrayIterator::GetKindValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKindAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSArrayIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> iterated_object_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("iterated_object", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetIteratedObjectAddress(), 1, 8, std::move(iterated_object_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> next_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("next_index", "v8::internal::Object", "v8::internal::Object", GetNextIndexAddress(), 1, 8, std::move(next_index_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> kind_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("kind", "v8::internal::Object", "v8::internal::Object", GetKindAddress(), 1, 8, std::move(kind_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSArray::GetName() const {
  return "v8::internal::JSArray";
}

void TqJSArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSArray(this);
}

bool TqJSArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSArray*>(other) != nullptr;
}

uintptr_t TqJSArray::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSArray::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::Object", "v8::internal::Object", GetLengthAddress(), 1, 8, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTemplateLiteralObject::GetName() const {
  return "v8::internal::TemplateLiteralObject";
}

void TqTemplateLiteralObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTemplateLiteralObject(this);
}

bool TqTemplateLiteralObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTemplateLiteralObject*>(other) != nullptr;
}

uintptr_t TqTemplateLiteralObject::GetRawAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqTemplateLiteralObject::GetRawValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRawAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateLiteralObject::GetFunctionLiteralIdAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqTemplateLiteralObject::GetFunctionLiteralIdValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionLiteralIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateLiteralObject::GetSlotIdAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqTemplateLiteralObject::GetSlotIdValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSlotIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTemplateLiteralObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArray::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> raw_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw", "v8::internal::JSArray", "v8::internal::JSArray", GetRawAddress(), 1, 8, std::move(raw_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> function_literal_id_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("function_literal_id", "v8::internal::Object", "v8::internal::Object", GetFunctionLiteralIdAddress(), 1, 8, std::move(function_literal_id_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> slot_id_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("slot_id", "v8::internal::Object", "v8::internal::Object", GetSlotIdAddress(), 1, 8, std::move(slot_id_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqAlwaysSharedSpaceJSObject::GetName() const {
  return "v8::internal::AlwaysSharedSpaceJSObject";
}

void TqAlwaysSharedSpaceJSObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAlwaysSharedSpaceJSObject(this);
}

bool TqAlwaysSharedSpaceJSObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAlwaysSharedSpaceJSObject*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqAlwaysSharedSpaceJSObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSSynchronizationPrimitive::GetName() const {
  return "v8::internal::JSSynchronizationPrimitive";
}

void TqJSSynchronizationPrimitive::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSynchronizationPrimitive(this);
}

bool TqJSSynchronizationPrimitive::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSynchronizationPrimitive*>(other) != nullptr;
}

uintptr_t TqJSSynchronizationPrimitive::GetStateAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSSynchronizationPrimitive::GetStateValue(d::MemoryAccessor accessor) const {
  uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetStateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSynchronizationPrimitive::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqAlwaysSharedSpaceJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> state_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("state", CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), CheckTypeName<uintptr_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uintptr_t"), GetStateAddress(), 1, 8, std::move(state_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSAtomicsMutex::GetName() const {
  return "v8::internal::JSAtomicsMutex";
}

void TqJSAtomicsMutex::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSAtomicsMutex(this);
}

bool TqJSAtomicsMutex::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSAtomicsMutex*>(other) != nullptr;
}

uintptr_t TqJSAtomicsMutex::GetOwnerThreadIdAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSAtomicsMutex::GetOwnerThreadIdValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOwnerThreadIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSAtomicsMutex::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSAtomicsMutex::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSAtomicsMutex::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSSynchronizationPrimitive::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> owner_thread_id_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("owner_thread_id", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetOwnerThreadIdAddress(), 1, 4, std::move(owner_thread_id_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSAtomicsCondition::GetName() const {
  return "v8::internal::JSAtomicsCondition";
}

void TqJSAtomicsCondition::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSAtomicsCondition(this);
}

bool TqJSAtomicsCondition::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSAtomicsCondition*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSAtomicsCondition::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSSynchronizationPrimitive::GetProperties(accessor);
  return result;
}

const char* TqJSCollectionIterator::GetName() const {
  return "v8::internal::JSCollectionIterator";
}

void TqJSCollectionIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSCollectionIterator(this);
}

bool TqJSCollectionIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSCollectionIterator*>(other) != nullptr;
}

uintptr_t TqJSCollectionIterator::GetTableAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSCollectionIterator::GetTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSCollectionIterator::GetIndexAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSCollectionIterator::GetIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSCollectionIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> table_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("table", "v8::internal::Object", "v8::internal::Object", GetTableAddress(), 1, 8, std::move(table_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("index", "v8::internal::Object", "v8::internal::Object", GetIndexAddress(), 1, 8, std::move(index_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSCollection::GetName() const {
  return "v8::internal::JSCollection";
}

void TqJSCollection::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSCollection(this);
}

bool TqJSCollection::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSCollection*>(other) != nullptr;
}

uintptr_t TqJSCollection::GetTableAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSCollection::GetTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSCollection::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> table_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("table", "v8::internal::Object", "v8::internal::Object", GetTableAddress(), 1, 8, std::move(table_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSSet::GetName() const {
  return "v8::internal::JSSet";
}

void TqJSSet::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSet(this);
}

bool TqJSSet::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSet*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSet::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSCollection::GetProperties(accessor);
  return result;
}

const char* TqJSMap::GetName() const {
  return "v8::internal::JSMap";
}

void TqJSMap::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSMap(this);
}

bool TqJSMap::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSMap*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSMap::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSCollection::GetProperties(accessor);
  return result;
}

const char* TqJSWeakCollection::GetName() const {
  return "v8::internal::JSWeakCollection";
}

void TqJSWeakCollection::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSWeakCollection(this);
}

bool TqJSWeakCollection::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSWeakCollection*>(other) != nullptr;
}

uintptr_t TqJSWeakCollection::GetTableAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSWeakCollection::GetTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSWeakCollection::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> table_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("table", "v8::internal::Object", "v8::internal::Object", GetTableAddress(), 1, 8, std::move(table_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSWeakSet::GetName() const {
  return "v8::internal::JSWeakSet";
}

void TqJSWeakSet::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSWeakSet(this);
}

bool TqJSWeakSet::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSWeakSet*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSWeakSet::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSWeakCollection::GetProperties(accessor);
  return result;
}

const char* TqJSWeakMap::GetName() const {
  return "v8::internal::JSWeakMap";
}

void TqJSWeakMap::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSWeakMap(this);
}

bool TqJSWeakMap::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSWeakMap*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSWeakMap::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSWeakCollection::GetProperties(accessor);
  return result;
}

const char* TqJSGeneratorObject::GetName() const {
  return "v8::internal::JSGeneratorObject";
}

void TqJSGeneratorObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSGeneratorObject(this);
}

bool TqJSGeneratorObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSGeneratorObject*>(other) != nullptr;
}

uintptr_t TqJSGeneratorObject::GetFunctionAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSGeneratorObject::GetFunctionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSGeneratorObject::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetReceiverAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSGeneratorObject::GetReceiverValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetReceiverAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetInputOrDebugPosAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSGeneratorObject::GetInputOrDebugPosValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInputOrDebugPosAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetResumeModeAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqJSGeneratorObject::GetResumeModeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetResumeModeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetContinuationAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqJSGeneratorObject::GetContinuationValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContinuationAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetParametersAndRegistersAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqJSGeneratorObject::GetParametersAndRegistersValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParametersAndRegistersAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSGeneratorObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> function_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("function", "v8::internal::JSFunction", "v8::internal::JSFunction", GetFunctionAddress(), 1, 8, std::move(function_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::Context", "v8::internal::Context", GetContextAddress(), 1, 8, std::move(context_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> receiver_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("receiver", "v8::internal::Object", "v8::internal::Object", GetReceiverAddress(), 1, 8, std::move(receiver_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> input_or_debug_pos_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("input_or_debug_pos", "v8::internal::Object", "v8::internal::Object", GetInputOrDebugPosAddress(), 1, 8, std::move(input_or_debug_pos_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> resume_mode_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("resume_mode", "v8::internal::Object", "v8::internal::Object", GetResumeModeAddress(), 1, 8, std::move(resume_mode_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> continuation_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("continuation", "v8::internal::Object", "v8::internal::Object", GetContinuationAddress(), 1, 8, std::move(continuation_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> parameters_and_registers_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("parameters_and_registers", "v8::internal::FixedArray", "v8::internal::FixedArray", GetParametersAndRegistersAddress(), 1, 8, std::move(parameters_and_registers_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSAsyncFunctionObject::GetName() const {
  return "v8::internal::JSAsyncFunctionObject";
}

void TqJSAsyncFunctionObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSAsyncFunctionObject(this);
}

bool TqJSAsyncFunctionObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSAsyncFunctionObject*>(other) != nullptr;
}

uintptr_t TqJSAsyncFunctionObject::GetPromiseAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqJSAsyncFunctionObject::GetPromiseValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSAsyncFunctionObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSGeneratorObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> promise_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("promise", "v8::internal::JSPromise", "v8::internal::JSPromise", GetPromiseAddress(), 1, 8, std::move(promise_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSAsyncGeneratorObject::GetName() const {
  return "v8::internal::JSAsyncGeneratorObject";
}

void TqJSAsyncGeneratorObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSAsyncGeneratorObject(this);
}

bool TqJSAsyncGeneratorObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSAsyncGeneratorObject*>(other) != nullptr;
}

uintptr_t TqJSAsyncGeneratorObject::GetQueueAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqJSAsyncGeneratorObject::GetQueueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetQueueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSAsyncGeneratorObject::GetIsAwaitingAddress() const {
  return address_ - i::kHeapObjectTag + 88;
}

Value<uintptr_t> TqJSAsyncGeneratorObject::GetIsAwaitingValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIsAwaitingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSAsyncGeneratorObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSGeneratorObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> queue_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("queue", "v8::internal::HeapObject", "v8::internal::HeapObject", GetQueueAddress(), 1, 8, std::move(queue_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> is_awaiting_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("is_awaiting", "v8::internal::Object", "v8::internal::Object", GetIsAwaitingAddress(), 1, 8, std::move(is_awaiting_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqAsyncGeneratorRequest::GetName() const {
  return "v8::internal::AsyncGeneratorRequest";
}

void TqAsyncGeneratorRequest::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAsyncGeneratorRequest(this);
}

bool TqAsyncGeneratorRequest::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAsyncGeneratorRequest*>(other) != nullptr;
}

uintptr_t TqAsyncGeneratorRequest::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAsyncGeneratorRequest::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAsyncGeneratorRequest::GetResumeModeAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqAsyncGeneratorRequest::GetResumeModeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetResumeModeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAsyncGeneratorRequest::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqAsyncGeneratorRequest::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAsyncGeneratorRequest::GetPromiseAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqAsyncGeneratorRequest::GetPromiseValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAsyncGeneratorRequest::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> next_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::HeapObject", "v8::internal::HeapObject", GetNextAddress(), 1, 8, std::move(next_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> resume_mode_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("resume_mode", "v8::internal::Object", "v8::internal::Object", GetResumeModeAddress(), 1, 8, std::move(resume_mode_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::Object", "v8::internal::Object", GetValueAddress(), 1, 8, std::move(value_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> promise_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("promise", "v8::internal::JSPromise", "v8::internal::JSPromise", GetPromiseAddress(), 1, 8, std::move(promise_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSIteratorHelper::GetName() const {
  return "v8::internal::JSIteratorHelper";
}

void TqJSIteratorHelper::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSIteratorHelper(this);
}

bool TqJSIteratorHelper::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSIteratorHelper*>(other) != nullptr;
}

uintptr_t TqJSIteratorHelper::GetUnderlyingAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSIteratorHelper::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> underlying_struct_field_list;
  underlying_struct_field_list.push_back(std::make_unique<StructProperty>("object", "v8::internal::JSReceiver", "v8::internal::JSReceiver", 0, 0, 0));
  underlying_struct_field_list.push_back(std::make_unique<StructProperty>("next", "v8::internal::Object", "v8::internal::Object", 8, 0, 0));
  result.push_back(std::make_unique<ObjectProperty>("underlying", "", "", GetUnderlyingAddress(), 1, 16, std::move(underlying_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSIteratorMapHelper::GetName() const {
  return "v8::internal::JSIteratorMapHelper";
}

void TqJSIteratorMapHelper::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSIteratorMapHelper(this);
}

bool TqJSIteratorMapHelper::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSIteratorMapHelper*>(other) != nullptr;
}

uintptr_t TqJSIteratorMapHelper::GetMapperAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSIteratorMapHelper::GetMapperValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMapperAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSIteratorMapHelper::GetCounterAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSIteratorMapHelper::GetCounterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCounterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSIteratorMapHelper::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSIteratorHelper::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> mapper_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("mapper", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetMapperAddress(), 1, 8, std::move(mapper_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> counter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("counter", "v8::internal::Object", "v8::internal::Object", GetCounterAddress(), 1, 8, std::move(counter_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSIteratorFilterHelper::GetName() const {
  return "v8::internal::JSIteratorFilterHelper";
}

void TqJSIteratorFilterHelper::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSIteratorFilterHelper(this);
}

bool TqJSIteratorFilterHelper::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSIteratorFilterHelper*>(other) != nullptr;
}

uintptr_t TqJSIteratorFilterHelper::GetPredicateAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSIteratorFilterHelper::GetPredicateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPredicateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSIteratorFilterHelper::GetCounterAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSIteratorFilterHelper::GetCounterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCounterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSIteratorFilterHelper::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSIteratorHelper::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> predicate_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("predicate", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetPredicateAddress(), 1, 8, std::move(predicate_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> counter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("counter", "v8::internal::Object", "v8::internal::Object", GetCounterAddress(), 1, 8, std::move(counter_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSIteratorTakeHelper::GetName() const {
  return "v8::internal::JSIteratorTakeHelper";
}

void TqJSIteratorTakeHelper::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSIteratorTakeHelper(this);
}

bool TqJSIteratorTakeHelper::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSIteratorTakeHelper*>(other) != nullptr;
}

uintptr_t TqJSIteratorTakeHelper::GetRemainingAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSIteratorTakeHelper::GetRemainingValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRemainingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSIteratorTakeHelper::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSIteratorHelper::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> remaining_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("remaining", "v8::internal::Object", "v8::internal::Object", GetRemainingAddress(), 1, 8, std::move(remaining_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSIteratorDropHelper::GetName() const {
  return "v8::internal::JSIteratorDropHelper";
}

void TqJSIteratorDropHelper::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSIteratorDropHelper(this);
}

bool TqJSIteratorDropHelper::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSIteratorDropHelper*>(other) != nullptr;
}

uintptr_t TqJSIteratorDropHelper::GetRemainingAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSIteratorDropHelper::GetRemainingValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRemainingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSIteratorDropHelper::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSIteratorHelper::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> remaining_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("remaining", "v8::internal::Object", "v8::internal::Object", GetRemainingAddress(), 1, 8, std::move(remaining_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSIteratorFlatMapHelper::GetName() const {
  return "v8::internal::JSIteratorFlatMapHelper";
}

void TqJSIteratorFlatMapHelper::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSIteratorFlatMapHelper(this);
}

bool TqJSIteratorFlatMapHelper::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSIteratorFlatMapHelper*>(other) != nullptr;
}

uintptr_t TqJSIteratorFlatMapHelper::GetMapperAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSIteratorFlatMapHelper::GetMapperValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMapperAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSIteratorFlatMapHelper::GetCounterAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSIteratorFlatMapHelper::GetCounterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCounterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSIteratorFlatMapHelper::GetInnerIteratorAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

uintptr_t TqJSIteratorFlatMapHelper::GetInnerAliveAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqJSIteratorFlatMapHelper::GetInnerAliveValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInnerAliveAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSIteratorFlatMapHelper::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSIteratorHelper::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> mapper_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("mapper", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetMapperAddress(), 1, 8, std::move(mapper_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> counter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("counter", "v8::internal::Object", "v8::internal::Object", GetCounterAddress(), 1, 8, std::move(counter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> innerIterator_struct_field_list;
  innerIterator_struct_field_list.push_back(std::make_unique<StructProperty>("object", "v8::internal::JSReceiver", "v8::internal::JSReceiver", 0, 0, 0));
  innerIterator_struct_field_list.push_back(std::make_unique<StructProperty>("next", "v8::internal::Object", "v8::internal::Object", 8, 0, 0));
  result.push_back(std::make_unique<ObjectProperty>("innerIterator", "", "", GetInnerIteratorAddress(), 1, 16, std::move(innerIterator_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> innerAlive_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("innerAlive", "v8::internal::Boolean", "v8::internal::Boolean", GetInnerAliveAddress(), 1, 8, std::move(innerAlive_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSExternalObject::GetName() const {
  return "v8::internal::JSExternalObject";
}

void TqJSExternalObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSExternalObject(this);
}

bool TqJSExternalObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSExternalObject*>(other) != nullptr;
}

uintptr_t TqJSExternalObject::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqJSExternalObject::GetValueValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSExternalObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetValueAddress(), 1, 8, std::move(value_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSGlobalProxy::GetName() const {
  return "v8::internal::JSGlobalProxy";
}

void TqJSGlobalProxy::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSGlobalProxy(this);
}

bool TqJSGlobalProxy::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSGlobalProxy*>(other) != nullptr;
}

uintptr_t TqJSGlobalProxy::GetNativeContextAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSGlobalProxy::GetNativeContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNativeContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSGlobalProxy::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSSpecialObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> native_context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("native_context", "v8::internal::Object", "v8::internal::Object", GetNativeContextAddress(), 1, 8, std::move(native_context_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSGlobalObject::GetName() const {
  return "v8::internal::JSGlobalObject";
}

void TqJSGlobalObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSGlobalObject(this);
}

bool TqJSGlobalObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSGlobalObject*>(other) != nullptr;
}

uintptr_t TqJSGlobalObject::GetNativeContextAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSGlobalObject::GetNativeContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNativeContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGlobalObject::GetGlobalProxyAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSGlobalObject::GetGlobalProxyValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGlobalProxyAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSGlobalObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSSpecialObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> native_context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("native_context", "v8::internal::NativeContext", "v8::internal::NativeContext", GetNativeContextAddress(), 1, 8, std::move(native_context_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> global_proxy_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("global_proxy", "v8::internal::JSGlobalProxy", "v8::internal::JSGlobalProxy", GetGlobalProxyAddress(), 1, 8, std::move(global_proxy_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSPrimitiveWrapper::GetName() const {
  return "v8::internal::JSPrimitiveWrapper";
}

void TqJSPrimitiveWrapper::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSPrimitiveWrapper(this);
}

bool TqJSPrimitiveWrapper::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSPrimitiveWrapper*>(other) != nullptr;
}

uintptr_t TqJSPrimitiveWrapper::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSPrimitiveWrapper::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSPrimitiveWrapper::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSCustomElementsObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::Object", "v8::internal::Object", GetValueAddress(), 1, 8, std::move(value_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSMessageObject::GetName() const {
  return "v8::internal::JSMessageObject";
}

void TqJSMessageObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSMessageObject(this);
}

bool TqJSMessageObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSMessageObject*>(other) != nullptr;
}

uintptr_t TqJSMessageObject::GetMessageTypeAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSMessageObject::GetMessageTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMessageTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetArgumentAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSMessageObject::GetArgumentValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetArgumentAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetScriptAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSMessageObject::GetScriptValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetStackFramesAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSMessageObject::GetStackFramesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStackFramesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetSharedInfoAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqJSMessageObject::GetSharedInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetBytecodeOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqJSMessageObject::GetBytecodeOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBytecodeOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetStartPositionAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqJSMessageObject::GetStartPositionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStartPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetEndPositionAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqJSMessageObject::GetEndPositionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEndPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetErrorLevelAddress() const {
  return address_ - i::kHeapObjectTag + 88;
}

Value<uintptr_t> TqJSMessageObject::GetErrorLevelValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetErrorLevelAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSMessageObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> message_type_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("message_type", "v8::internal::Object", "v8::internal::Object", GetMessageTypeAddress(), 1, 8, std::move(message_type_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> argument_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("argument", "v8::internal::Object", "v8::internal::Object", GetArgumentAddress(), 1, 8, std::move(argument_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> script_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("script", "v8::internal::Script", "v8::internal::Script", GetScriptAddress(), 1, 8, std::move(script_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> stack_frames_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("stack_frames", "v8::internal::Object", "v8::internal::Object", GetStackFramesAddress(), 1, 8, std::move(stack_frames_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> shared_info_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("shared_info", "v8::internal::Object", "v8::internal::Object", GetSharedInfoAddress(), 1, 8, std::move(shared_info_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bytecode_offset_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bytecode_offset", "v8::internal::Object", "v8::internal::Object", GetBytecodeOffsetAddress(), 1, 8, std::move(bytecode_offset_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> start_position_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("start_position", "v8::internal::Object", "v8::internal::Object", GetStartPositionAddress(), 1, 8, std::move(start_position_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> end_position_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("end_position", "v8::internal::Object", "v8::internal::Object", GetEndPositionAddress(), 1, 8, std::move(end_position_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> error_level_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("error_level", "v8::internal::Object", "v8::internal::Object", GetErrorLevelAddress(), 1, 8, std::move(error_level_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSDate::GetName() const {
  return "v8::internal::JSDate";
}

void TqJSDate::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSDate(this);
}

bool TqJSDate::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSDate*>(other) != nullptr;
}

uintptr_t TqJSDate::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSDate::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetYearAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSDate::GetYearValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetYearAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetMonthAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSDate::GetMonthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMonthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetDayAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSDate::GetDayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetWeekdayAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqJSDate::GetWeekdayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWeekdayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetHourAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqJSDate::GetHourValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHourAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetMinAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqJSDate::GetMinValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMinAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetSecAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqJSDate::GetSecValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSecAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetCacheStampAddress() const {
  return address_ - i::kHeapObjectTag + 88;
}

Value<uintptr_t> TqJSDate::GetCacheStampValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCacheStampAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSDate::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::Object", "v8::internal::Object", GetValueAddress(), 1, 8, std::move(value_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> year_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("year", "v8::internal::Object", "v8::internal::Object", GetYearAddress(), 1, 8, std::move(year_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> month_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("month", "v8::internal::Object", "v8::internal::Object", GetMonthAddress(), 1, 8, std::move(month_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> day_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("day", "v8::internal::Object", "v8::internal::Object", GetDayAddress(), 1, 8, std::move(day_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> weekday_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("weekday", "v8::internal::Object", "v8::internal::Object", GetWeekdayAddress(), 1, 8, std::move(weekday_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> hour_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("hour", "v8::internal::Object", "v8::internal::Object", GetHourAddress(), 1, 8, std::move(hour_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> min_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("min", "v8::internal::Object", "v8::internal::Object", GetMinAddress(), 1, 8, std::move(min_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> sec_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("sec", "v8::internal::Object", "v8::internal::Object", GetSecAddress(), 1, 8, std::move(sec_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> cache_stamp_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("cache_stamp", "v8::internal::Object", "v8::internal::Object", GetCacheStampAddress(), 1, 8, std::move(cache_stamp_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSAsyncFromSyncIterator::GetName() const {
  return "v8::internal::JSAsyncFromSyncIterator";
}

void TqJSAsyncFromSyncIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSAsyncFromSyncIterator(this);
}

bool TqJSAsyncFromSyncIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSAsyncFromSyncIterator*>(other) != nullptr;
}

uintptr_t TqJSAsyncFromSyncIterator::GetSyncIteratorAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSAsyncFromSyncIterator::GetSyncIteratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSyncIteratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSAsyncFromSyncIterator::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSAsyncFromSyncIterator::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSAsyncFromSyncIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> sync_iterator_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("sync_iterator", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetSyncIteratorAddress(), 1, 8, std::move(sync_iterator_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> next_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::Object", "v8::internal::Object", GetNextAddress(), 1, 8, std::move(next_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSStringIterator::GetName() const {
  return "v8::internal::JSStringIterator";
}

void TqJSStringIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSStringIterator(this);
}

bool TqJSStringIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSStringIterator*>(other) != nullptr;
}

uintptr_t TqJSStringIterator::GetStringAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSStringIterator::GetStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSStringIterator::GetIndexAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSStringIterator::GetIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSStringIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> string_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("string", "v8::internal::String", "v8::internal::String", GetStringAddress(), 1, 8, std::move(string_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("index", "v8::internal::Object", "v8::internal::Object", GetIndexAddress(), 1, 8, std::move(index_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSValidIteratorWrapper::GetName() const {
  return "v8::internal::JSValidIteratorWrapper";
}

void TqJSValidIteratorWrapper::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSValidIteratorWrapper(this);
}

bool TqJSValidIteratorWrapper::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSValidIteratorWrapper*>(other) != nullptr;
}

uintptr_t TqJSValidIteratorWrapper::GetUnderlyingAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSValidIteratorWrapper::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> underlying_struct_field_list;
  underlying_struct_field_list.push_back(std::make_unique<StructProperty>("object", "v8::internal::JSReceiver", "v8::internal::JSReceiver", 0, 0, 0));
  underlying_struct_field_list.push_back(std::make_unique<StructProperty>("next", "v8::internal::Object", "v8::internal::Object", 8, 0, 0));
  result.push_back(std::make_unique<ObjectProperty>("underlying", "", "", GetUnderlyingAddress(), 1, 16, std::move(underlying_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSProxyRevocableResult::GetName() const {
  return "v8::internal::JSProxyRevocableResult";
}

void TqJSProxyRevocableResult::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSProxyRevocableResult(this);
}

bool TqJSProxyRevocableResult::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSProxyRevocableResult*>(other) != nullptr;
}

uintptr_t TqJSProxyRevocableResult::GetProxyAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSProxyRevocableResult::GetProxyValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetProxyAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSProxyRevocableResult::GetRevokeAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSProxyRevocableResult::GetRevokeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRevokeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSProxyRevocableResult::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> proxy_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("proxy", "v8::internal::Object", "v8::internal::Object", GetProxyAddress(), 1, 8, std::move(proxy_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> revoke_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("revoke", "v8::internal::Object", "v8::internal::Object", GetRevokeAddress(), 1, 8, std::move(revoke_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRawJson::GetName() const {
  return "v8::internal::JSRawJson";
}

void TqJSRawJson::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRawJson(this);
}

bool TqJSRawJson::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRawJson*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRawJson::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSRegExpStringIterator::GetName() const {
  return "v8::internal::JSRegExpStringIterator";
}

void TqJSRegExpStringIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRegExpStringIterator(this);
}

bool TqJSRegExpStringIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRegExpStringIterator*>(other) != nullptr;
}

uintptr_t TqJSRegExpStringIterator::GetIteratingRegExpAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSRegExpStringIterator::GetIteratingRegExpValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIteratingRegExpAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpStringIterator::GetIteratedStringAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSRegExpStringIterator::GetIteratedStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIteratedStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpStringIterator::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSRegExpStringIterator::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRegExpStringIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> iterating_reg_exp_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("iterating_reg_exp", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetIteratingRegExpAddress(), 1, 8, std::move(iterating_reg_exp_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> iterated_string_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("iterated_string", "v8::internal::String", "v8::internal::String", GetIteratedStringAddress(), 1, 8, std::move(iterated_string_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("done", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("global", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 33));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("unicode", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 34));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRegExp::GetName() const {
  return "v8::internal::JSRegExp";
}

void TqJSRegExp::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRegExp(this);
}

bool TqJSRegExp::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRegExp*>(other) != nullptr;
}

uintptr_t TqJSRegExp::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSRegExp::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExp::GetSourceAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSRegExp::GetSourceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExp::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSRegExp::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRegExp::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::HeapObject", "v8::internal::HeapObject", GetDataAddress(), 1, 8, std::move(data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> source_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("source", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", GetSourceAddress(), 1, 8, std::move(source_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRegExpResult::GetName() const {
  return "v8::internal::JSRegExpResult";
}

void TqJSRegExpResult::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRegExpResult(this);
}

bool TqJSRegExpResult::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRegExpResult*>(other) != nullptr;
}

uintptr_t TqJSRegExpResult::GetIndexAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSRegExpResult::GetIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetInputAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSRegExpResult::GetInputValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInputAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetGroupsAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSRegExpResult::GetGroupsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGroupsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetNamesAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqJSRegExpResult::GetNamesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNamesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetRegexpInputAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqJSRegExpResult::GetRegexpInputValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRegexpInputAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetRegexpLastIndexAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqJSRegExpResult::GetRegexpLastIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRegexpLastIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRegExpResult::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArray::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("index", "v8::internal::Object", "v8::internal::Object", GetIndexAddress(), 1, 8, std::move(index_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> input_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("input", "v8::internal::Object", "v8::internal::Object", GetInputAddress(), 1, 8, std::move(input_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> groups_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("groups", "v8::internal::Object", "v8::internal::Object", GetGroupsAddress(), 1, 8, std::move(groups_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> names_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("names", "v8::internal::HeapObject", "v8::internal::HeapObject", GetNamesAddress(), 1, 8, std::move(names_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> regexp_input_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("regexp_input", "v8::internal::String", "v8::internal::String", GetRegexpInputAddress(), 1, 8, std::move(regexp_input_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> regexp_last_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("regexp_last_index", "v8::internal::Object", "v8::internal::Object", GetRegexpLastIndexAddress(), 1, 8, std::move(regexp_last_index_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRegExpResultWithIndices::GetName() const {
  return "v8::internal::JSRegExpResultWithIndices";
}

void TqJSRegExpResultWithIndices::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRegExpResultWithIndices(this);
}

bool TqJSRegExpResultWithIndices::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRegExpResultWithIndices*>(other) != nullptr;
}

uintptr_t TqJSRegExpResultWithIndices::GetIndicesAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqJSRegExpResultWithIndices::GetIndicesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndicesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRegExpResultWithIndices::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSRegExpResult::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> indices_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("indices", "v8::internal::Object", "v8::internal::Object", GetIndicesAddress(), 1, 8, std::move(indices_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRegExpResultIndices::GetName() const {
  return "v8::internal::JSRegExpResultIndices";
}

void TqJSRegExpResultIndices::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRegExpResultIndices(this);
}

bool TqJSRegExpResultIndices::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRegExpResultIndices*>(other) != nullptr;
}

uintptr_t TqJSRegExpResultIndices::GetGroupsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSRegExpResultIndices::GetGroupsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGroupsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRegExpResultIndices::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArray::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> groups_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("groups", "v8::internal::Object", "v8::internal::Object", GetGroupsAddress(), 1, 8, std::move(groups_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSShadowRealm::GetName() const {
  return "v8::internal::JSShadowRealm";
}

void TqJSShadowRealm::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSShadowRealm(this);
}

bool TqJSShadowRealm::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSShadowRealm*>(other) != nullptr;
}

uintptr_t TqJSShadowRealm::GetNativeContextAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSShadowRealm::GetNativeContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNativeContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSShadowRealm::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> native_context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("native_context", "v8::internal::NativeContext", "v8::internal::NativeContext", GetNativeContextAddress(), 1, 8, std::move(native_context_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSSharedArray::GetName() const {
  return "v8::internal::JSSharedArray";
}

void TqJSSharedArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSharedArray(this);
}

bool TqJSSharedArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSharedArray*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSharedArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqAlwaysSharedSpaceJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSSharedStruct::GetName() const {
  return "v8::internal::JSSharedStruct";
}

void TqJSSharedStruct::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSharedStruct(this);
}

bool TqJSSharedStruct::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSharedStruct*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSharedStruct::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqAlwaysSharedSpaceJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSTemporalCalendar::GetName() const {
  return "v8::internal::JSTemporalCalendar";
}

void TqJSTemporalCalendar::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTemporalCalendar(this);
}

bool TqJSTemporalCalendar::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTemporalCalendar*>(other) != nullptr;
}

uintptr_t TqJSTemporalCalendar::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSTemporalCalendar::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTemporalCalendar::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("calendar_index", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 5, 32));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTemporalDuration::GetName() const {
  return "v8::internal::JSTemporalDuration";
}

void TqJSTemporalDuration::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTemporalDuration(this);
}

bool TqJSTemporalDuration::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTemporalDuration*>(other) != nullptr;
}

uintptr_t TqJSTemporalDuration::GetYearsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSTemporalDuration::GetYearsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetYearsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalDuration::GetMonthsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSTemporalDuration::GetMonthsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMonthsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalDuration::GetWeeksAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSTemporalDuration::GetWeeksValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWeeksAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalDuration::GetDaysAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSTemporalDuration::GetDaysValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDaysAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalDuration::GetHoursAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqJSTemporalDuration::GetHoursValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHoursAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalDuration::GetMinutesAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqJSTemporalDuration::GetMinutesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMinutesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalDuration::GetSecondsAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqJSTemporalDuration::GetSecondsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSecondsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalDuration::GetMillisecondsAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqJSTemporalDuration::GetMillisecondsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMillisecondsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalDuration::GetMicrosecondsAddress() const {
  return address_ - i::kHeapObjectTag + 88;
}

Value<uintptr_t> TqJSTemporalDuration::GetMicrosecondsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMicrosecondsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalDuration::GetNanosecondsAddress() const {
  return address_ - i::kHeapObjectTag + 96;
}

Value<uintptr_t> TqJSTemporalDuration::GetNanosecondsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNanosecondsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTemporalDuration::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> years_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("years", "v8::internal::Object", "v8::internal::Object", GetYearsAddress(), 1, 8, std::move(years_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> months_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("months", "v8::internal::Object", "v8::internal::Object", GetMonthsAddress(), 1, 8, std::move(months_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> weeks_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("weeks", "v8::internal::Object", "v8::internal::Object", GetWeeksAddress(), 1, 8, std::move(weeks_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> days_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("days", "v8::internal::Object", "v8::internal::Object", GetDaysAddress(), 1, 8, std::move(days_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> hours_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("hours", "v8::internal::Object", "v8::internal::Object", GetHoursAddress(), 1, 8, std::move(hours_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> minutes_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("minutes", "v8::internal::Object", "v8::internal::Object", GetMinutesAddress(), 1, 8, std::move(minutes_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> seconds_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("seconds", "v8::internal::Object", "v8::internal::Object", GetSecondsAddress(), 1, 8, std::move(seconds_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> milliseconds_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("milliseconds", "v8::internal::Object", "v8::internal::Object", GetMillisecondsAddress(), 1, 8, std::move(milliseconds_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> microseconds_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("microseconds", "v8::internal::Object", "v8::internal::Object", GetMicrosecondsAddress(), 1, 8, std::move(microseconds_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> nanoseconds_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("nanoseconds", "v8::internal::Object", "v8::internal::Object", GetNanosecondsAddress(), 1, 8, std::move(nanoseconds_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTemporalInstant::GetName() const {
  return "v8::internal::JSTemporalInstant";
}

void TqJSTemporalInstant::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTemporalInstant(this);
}

bool TqJSTemporalInstant::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTemporalInstant*>(other) != nullptr;
}

uintptr_t TqJSTemporalInstant::GetNanosecondsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSTemporalInstant::GetNanosecondsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNanosecondsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTemporalInstant::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> nanoseconds_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("nanoseconds", "v8::internal::BigInt", "v8::internal::BigInt", GetNanosecondsAddress(), 1, 8, std::move(nanoseconds_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTemporalPlainDateTime::GetName() const {
  return "v8::internal::JSTemporalPlainDateTime";
}

void TqJSTemporalPlainDateTime::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTemporalPlainDateTime(this);
}

bool TqJSTemporalPlainDateTime::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTemporalPlainDateTime*>(other) != nullptr;
}

uintptr_t TqJSTemporalPlainDateTime::GetYearMonthDayAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSTemporalPlainDateTime::GetYearMonthDayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetYearMonthDayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalPlainDateTime::GetHourMinuteSecondAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSTemporalPlainDateTime::GetHourMinuteSecondValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHourMinuteSecondAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalPlainDateTime::GetSecondPartsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSTemporalPlainDateTime::GetSecondPartsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSecondPartsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalPlainDateTime::GetCalendarAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSTemporalPlainDateTime::GetCalendarValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCalendarAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTemporalPlainDateTime::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> year_month_day_struct_field_list;
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_year", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 20, 32));
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_month", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 4, 52));
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_day", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 5, 56));
  result.push_back(std::make_unique<ObjectProperty>("year_month_day", "v8::internal::Object", "v8::internal::Object", GetYearMonthDayAddress(), 1, 8, std::move(year_month_day_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> hour_minute_second_struct_field_list;
  hour_minute_second_struct_field_list.push_back(std::make_unique<StructProperty>("iso_hour", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 5, 32));
  hour_minute_second_struct_field_list.push_back(std::make_unique<StructProperty>("iso_minute", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 6, 37));
  hour_minute_second_struct_field_list.push_back(std::make_unique<StructProperty>("iso_second", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 6, 43));
  result.push_back(std::make_unique<ObjectProperty>("hour_minute_second", "v8::internal::Object", "v8::internal::Object", GetHourMinuteSecondAddress(), 1, 8, std::move(hour_minute_second_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> second_parts_struct_field_list;
  second_parts_struct_field_list.push_back(std::make_unique<StructProperty>("iso_millisecond", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 10, 32));
  second_parts_struct_field_list.push_back(std::make_unique<StructProperty>("iso_microsecond", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 10, 42));
  second_parts_struct_field_list.push_back(std::make_unique<StructProperty>("iso_nanosecond", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 10, 52));
  result.push_back(std::make_unique<ObjectProperty>("second_parts", "v8::internal::Object", "v8::internal::Object", GetSecondPartsAddress(), 1, 8, std::move(second_parts_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> calendar_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("calendar", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetCalendarAddress(), 1, 8, std::move(calendar_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTemporalPlainDate::GetName() const {
  return "v8::internal::JSTemporalPlainDate";
}

void TqJSTemporalPlainDate::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTemporalPlainDate(this);
}

bool TqJSTemporalPlainDate::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTemporalPlainDate*>(other) != nullptr;
}

uintptr_t TqJSTemporalPlainDate::GetYearMonthDayAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSTemporalPlainDate::GetYearMonthDayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetYearMonthDayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalPlainDate::GetCalendarAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSTemporalPlainDate::GetCalendarValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCalendarAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTemporalPlainDate::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> year_month_day_struct_field_list;
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_year", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 20, 32));
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_month", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 4, 52));
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_day", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 5, 56));
  result.push_back(std::make_unique<ObjectProperty>("year_month_day", "v8::internal::Object", "v8::internal::Object", GetYearMonthDayAddress(), 1, 8, std::move(year_month_day_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> calendar_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("calendar", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetCalendarAddress(), 1, 8, std::move(calendar_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTemporalPlainMonthDay::GetName() const {
  return "v8::internal::JSTemporalPlainMonthDay";
}

void TqJSTemporalPlainMonthDay::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTemporalPlainMonthDay(this);
}

bool TqJSTemporalPlainMonthDay::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTemporalPlainMonthDay*>(other) != nullptr;
}

uintptr_t TqJSTemporalPlainMonthDay::GetYearMonthDayAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSTemporalPlainMonthDay::GetYearMonthDayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetYearMonthDayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalPlainMonthDay::GetCalendarAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSTemporalPlainMonthDay::GetCalendarValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCalendarAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTemporalPlainMonthDay::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> year_month_day_struct_field_list;
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_year", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 20, 32));
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_month", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 4, 52));
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_day", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 5, 56));
  result.push_back(std::make_unique<ObjectProperty>("year_month_day", "v8::internal::Object", "v8::internal::Object", GetYearMonthDayAddress(), 1, 8, std::move(year_month_day_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> calendar_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("calendar", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetCalendarAddress(), 1, 8, std::move(calendar_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTemporalPlainTime::GetName() const {
  return "v8::internal::JSTemporalPlainTime";
}

void TqJSTemporalPlainTime::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTemporalPlainTime(this);
}

bool TqJSTemporalPlainTime::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTemporalPlainTime*>(other) != nullptr;
}

uintptr_t TqJSTemporalPlainTime::GetHourMinuteSecondAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSTemporalPlainTime::GetHourMinuteSecondValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHourMinuteSecondAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalPlainTime::GetSecondPartsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSTemporalPlainTime::GetSecondPartsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSecondPartsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalPlainTime::GetCalendarAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSTemporalPlainTime::GetCalendarValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCalendarAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTemporalPlainTime::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> hour_minute_second_struct_field_list;
  hour_minute_second_struct_field_list.push_back(std::make_unique<StructProperty>("iso_hour", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 5, 32));
  hour_minute_second_struct_field_list.push_back(std::make_unique<StructProperty>("iso_minute", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 6, 37));
  hour_minute_second_struct_field_list.push_back(std::make_unique<StructProperty>("iso_second", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 6, 43));
  result.push_back(std::make_unique<ObjectProperty>("hour_minute_second", "v8::internal::Object", "v8::internal::Object", GetHourMinuteSecondAddress(), 1, 8, std::move(hour_minute_second_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> second_parts_struct_field_list;
  second_parts_struct_field_list.push_back(std::make_unique<StructProperty>("iso_millisecond", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 10, 32));
  second_parts_struct_field_list.push_back(std::make_unique<StructProperty>("iso_microsecond", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 10, 42));
  second_parts_struct_field_list.push_back(std::make_unique<StructProperty>("iso_nanosecond", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 10, 52));
  result.push_back(std::make_unique<ObjectProperty>("second_parts", "v8::internal::Object", "v8::internal::Object", GetSecondPartsAddress(), 1, 8, std::move(second_parts_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> calendar_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("calendar", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetCalendarAddress(), 1, 8, std::move(calendar_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTemporalPlainYearMonth::GetName() const {
  return "v8::internal::JSTemporalPlainYearMonth";
}

void TqJSTemporalPlainYearMonth::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTemporalPlainYearMonth(this);
}

bool TqJSTemporalPlainYearMonth::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTemporalPlainYearMonth*>(other) != nullptr;
}

uintptr_t TqJSTemporalPlainYearMonth::GetYearMonthDayAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSTemporalPlainYearMonth::GetYearMonthDayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetYearMonthDayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalPlainYearMonth::GetCalendarAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSTemporalPlainYearMonth::GetCalendarValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCalendarAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTemporalPlainYearMonth::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> year_month_day_struct_field_list;
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_year", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 20, 32));
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_month", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 4, 52));
  year_month_day_struct_field_list.push_back(std::make_unique<StructProperty>("iso_day", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 5, 56));
  result.push_back(std::make_unique<ObjectProperty>("year_month_day", "v8::internal::Object", "v8::internal::Object", GetYearMonthDayAddress(), 1, 8, std::move(year_month_day_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> calendar_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("calendar", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetCalendarAddress(), 1, 8, std::move(calendar_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTemporalTimeZone::GetName() const {
  return "v8::internal::JSTemporalTimeZone";
}

void TqJSTemporalTimeZone::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTemporalTimeZone(this);
}

bool TqJSTemporalTimeZone::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTemporalTimeZone*>(other) != nullptr;
}

uintptr_t TqJSTemporalTimeZone::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSTemporalTimeZone::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalTimeZone::GetDetailsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSTemporalTimeZone::GetDetailsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDetailsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTemporalTimeZone::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_offset", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("offset_milliseconds_or_time_zone_index", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 28, 33));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> details_struct_field_list;
  details_struct_field_list.push_back(std::make_unique<StructProperty>("offset_sub_milliseconds", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 21, 32));
  result.push_back(std::make_unique<ObjectProperty>("details", "v8::internal::Object", "v8::internal::Object", GetDetailsAddress(), 1, 8, std::move(details_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTemporalZonedDateTime::GetName() const {
  return "v8::internal::JSTemporalZonedDateTime";
}

void TqJSTemporalZonedDateTime::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTemporalZonedDateTime(this);
}

bool TqJSTemporalZonedDateTime::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTemporalZonedDateTime*>(other) != nullptr;
}

uintptr_t TqJSTemporalZonedDateTime::GetNanosecondsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSTemporalZonedDateTime::GetNanosecondsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNanosecondsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalZonedDateTime::GetTimeZoneAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSTemporalZonedDateTime::GetTimeZoneValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTimeZoneAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSTemporalZonedDateTime::GetCalendarAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSTemporalZonedDateTime::GetCalendarValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCalendarAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTemporalZonedDateTime::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> nanoseconds_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("nanoseconds", "v8::internal::BigInt", "v8::internal::BigInt", GetNanosecondsAddress(), 1, 8, std::move(nanoseconds_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> time_zone_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("time_zone", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetTimeZoneAddress(), 1, 8, std::move(time_zone_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> calendar_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("calendar", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetCalendarAddress(), 1, 8, std::move(calendar_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSFinalizationRegistry::GetName() const {
  return "v8::internal::JSFinalizationRegistry";
}

void TqJSFinalizationRegistry::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSFinalizationRegistry(this);
}

bool TqJSFinalizationRegistry::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSFinalizationRegistry*>(other) != nullptr;
}

uintptr_t TqJSFinalizationRegistry::GetNativeContextAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSFinalizationRegistry::GetNativeContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNativeContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationRegistry::GetCleanupAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSFinalizationRegistry::GetCleanupValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCleanupAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationRegistry::GetActiveCellsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSFinalizationRegistry::GetActiveCellsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetActiveCellsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationRegistry::GetClearedCellsAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSFinalizationRegistry::GetClearedCellsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetClearedCellsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationRegistry::GetKeyMapAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqJSFinalizationRegistry::GetKeyMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKeyMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationRegistry::GetNextDirtyAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqJSFinalizationRegistry::GetNextDirtyValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextDirtyAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationRegistry::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqJSFinalizationRegistry::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSFinalizationRegistry::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> native_context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("native_context", "v8::internal::NativeContext", "v8::internal::NativeContext", GetNativeContextAddress(), 1, 8, std::move(native_context_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> cleanup_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("cleanup", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetCleanupAddress(), 1, 8, std::move(cleanup_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> active_cells_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("active_cells", "v8::internal::HeapObject", "v8::internal::HeapObject", GetActiveCellsAddress(), 1, 8, std::move(active_cells_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> cleared_cells_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("cleared_cells", "v8::internal::HeapObject", "v8::internal::HeapObject", GetClearedCellsAddress(), 1, 8, std::move(cleared_cells_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> key_map_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("key_map", "v8::internal::Object", "v8::internal::Object", GetKeyMapAddress(), 1, 8, std::move(key_map_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> next_dirty_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("next_dirty", "v8::internal::HeapObject", "v8::internal::HeapObject", GetNextDirtyAddress(), 1, 8, std::move(next_dirty_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("scheduled_for_cleanup", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSWeakRef::GetName() const {
  return "v8::internal::JSWeakRef";
}

void TqJSWeakRef::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSWeakRef(this);
}

bool TqJSWeakRef::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSWeakRef*>(other) != nullptr;
}

uintptr_t TqJSWeakRef::GetTargetAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSWeakRef::GetTargetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTargetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSWeakRef::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> target_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("target", "v8::internal::HeapObject", "v8::internal::HeapObject", GetTargetAddress(), 1, 8, std::move(target_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqArrayBoilerplateDescription::GetName() const {
  return "v8::internal::ArrayBoilerplateDescription";
}

void TqArrayBoilerplateDescription::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitArrayBoilerplateDescription(this);
}

bool TqArrayBoilerplateDescription::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqArrayBoilerplateDescription*>(other) != nullptr;
}

uintptr_t TqArrayBoilerplateDescription::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqArrayBoilerplateDescription::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqArrayBoilerplateDescription::GetConstantElementsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqArrayBoilerplateDescription::GetConstantElementsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetConstantElementsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqArrayBoilerplateDescription::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> constant_elements_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("constant_elements", "v8::internal::FixedArrayBase", "v8::internal::FixedArrayBase", GetConstantElementsAddress(), 1, 8, std::move(constant_elements_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqRegExpBoilerplateDescription::GetName() const {
  return "v8::internal::RegExpBoilerplateDescription";
}

void TqRegExpBoilerplateDescription::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitRegExpBoilerplateDescription(this);
}

bool TqRegExpBoilerplateDescription::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqRegExpBoilerplateDescription*>(other) != nullptr;
}

uintptr_t TqRegExpBoilerplateDescription::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqRegExpBoilerplateDescription::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqRegExpBoilerplateDescription::GetSourceAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqRegExpBoilerplateDescription::GetSourceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqRegExpBoilerplateDescription::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqRegExpBoilerplateDescription::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqRegExpBoilerplateDescription::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::FixedArray", "v8::internal::FixedArray", GetDataAddress(), 1, 8, std::move(data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> source_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("source", "v8::internal::String", "v8::internal::String", GetSourceAddress(), 1, 8, std::move(source_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("global", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("ignore_case", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 33));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("multiline", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 34));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("sticky", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 35));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("unicode", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 36));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("dot_all", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 37));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("linear", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 38));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_indices", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 39));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("unicode_sets", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 40));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqMegaDomHandler::GetName() const {
  return "v8::internal::MegaDomHandler";
}

void TqMegaDomHandler::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitMegaDomHandler(this);
}

bool TqMegaDomHandler::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqMegaDomHandler*>(other) != nullptr;
}

uintptr_t TqMegaDomHandler::GetAccessorAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqMegaDomHandler::GetAccessorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAccessorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMegaDomHandler::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqMegaDomHandler::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqMegaDomHandler::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> accessor_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("accessor", "v8::internal::Object", "v8::internal::Object", GetAccessorAddress(), 1, 8, std::move(accessor_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::Object", "v8::internal::Object", GetContextAddress(), 1, 8, std::move(context_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqMicrotask::GetName() const {
  return "v8::internal::Microtask";
}

void TqMicrotask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitMicrotask(this);
}

bool TqMicrotask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqMicrotask*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqMicrotask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  return result;
}

const char* TqCallbackTask::GetName() const {
  return "v8::internal::CallbackTask";
}

void TqCallbackTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitCallbackTask(this);
}

bool TqCallbackTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqCallbackTask*>(other) != nullptr;
}

uintptr_t TqCallbackTask::GetCallbackAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqCallbackTask::GetCallbackValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallbackAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallbackTask::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqCallbackTask::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqCallbackTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqMicrotask::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> callback_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("callback", "v8::internal::Foreign", "v8::internal::Foreign", GetCallbackAddress(), 1, 8, std::move(callback_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::Foreign", "v8::internal::Foreign", GetDataAddress(), 1, 8, std::move(data_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqCallableTask::GetName() const {
  return "v8::internal::CallableTask";
}

void TqCallableTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitCallableTask(this);
}

bool TqCallableTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqCallableTask*>(other) != nullptr;
}

uintptr_t TqCallableTask::GetCallableAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqCallableTask::GetCallableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallableTask::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqCallableTask::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqCallableTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqMicrotask::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> callable_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("callable", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetCallableAddress(), 1, 8, std::move(callable_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::Context", "v8::internal::Context", GetContextAddress(), 1, 8, std::move(context_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqModule::GetName() const {
  return "v8::internal::Module";
}

void TqModule::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitModule(this);
}

bool TqModule::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqModule*>(other) != nullptr;
}

uintptr_t TqModule::GetExportsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqModule::GetExportsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExportsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModule::GetHashAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqModule::GetHashValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHashAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModule::GetStatusAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqModule::GetStatusValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStatusAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModule::GetModuleNamespaceAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqModule::GetModuleNamespaceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetModuleNamespaceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModule::GetExceptionAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqModule::GetExceptionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExceptionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModule::GetTopLevelCapabilityAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqModule::GetTopLevelCapabilityValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTopLevelCapabilityAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqModule::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> exports_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("exports", "v8::internal::FixedArray", "v8::internal::FixedArray", GetExportsAddress(), 1, 8, std::move(exports_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> hash_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("hash", "v8::internal::Object", "v8::internal::Object", GetHashAddress(), 1, 8, std::move(hash_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> status_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("status", "v8::internal::Object", "v8::internal::Object", GetStatusAddress(), 1, 8, std::move(status_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> module_namespace_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("module_namespace", "v8::internal::HeapObject", "v8::internal::HeapObject", GetModuleNamespaceAddress(), 1, 8, std::move(module_namespace_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> exception_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("exception", "v8::internal::Object", "v8::internal::Object", GetExceptionAddress(), 1, 8, std::move(exception_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> top_level_capability_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("top_level_capability", "v8::internal::HeapObject", "v8::internal::HeapObject", GetTopLevelCapabilityAddress(), 1, 8, std::move(top_level_capability_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSModuleNamespace::GetName() const {
  return "v8::internal::JSModuleNamespace";
}

void TqJSModuleNamespace::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSModuleNamespace(this);
}

bool TqJSModuleNamespace::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSModuleNamespace*>(other) != nullptr;
}

uintptr_t TqJSModuleNamespace::GetModuleAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSModuleNamespace::GetModuleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetModuleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSModuleNamespace::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSSpecialObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> module_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("module", "v8::internal::Module", "v8::internal::Module", GetModuleAddress(), 1, 8, std::move(module_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqScriptOrModule::GetName() const {
  return "v8::internal::ScriptOrModule";
}

void TqScriptOrModule::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitScriptOrModule(this);
}

bool TqScriptOrModule::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqScriptOrModule*>(other) != nullptr;
}

uintptr_t TqScriptOrModule::GetResourceNameAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqScriptOrModule::GetResourceNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetResourceNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScriptOrModule::GetHostDefinedOptionsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqScriptOrModule::GetHostDefinedOptionsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHostDefinedOptionsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqScriptOrModule::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> resource_name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("resource_name", "v8::internal::Object", "v8::internal::Object", GetResourceNameAddress(), 1, 8, std::move(resource_name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> host_defined_options_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("host_defined_options", "v8::internal::FixedArray", "v8::internal::FixedArray", GetHostDefinedOptionsAddress(), 1, 8, std::move(host_defined_options_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTrue::GetName() const {
  return "v8::internal::True";
}

void TqTrue::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTrue(this);
}

bool TqTrue::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTrue*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqTrue::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqBoolean::GetProperties(accessor);
  return result;
}

const char* TqFalse::GetName() const {
  return "v8::internal::False";
}

void TqFalse::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFalse(this);
}

bool TqFalse::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFalse*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqFalse::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqBoolean::GetProperties(accessor);
  return result;
}

const char* TqSmallOrderedHashTable::GetName() const {
  return "v8::internal::SmallOrderedHashTable";
}

void TqSmallOrderedHashTable::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSmallOrderedHashTable(this);
}

bool TqSmallOrderedHashTable::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSmallOrderedHashTable*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqSmallOrderedHashTable::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  return result;
}

const char* TqSmallOrderedHashSet::GetName() const {
  return "v8::internal::SmallOrderedHashSet";
}

void TqSmallOrderedHashSet::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSmallOrderedHashSet(this);
}

bool TqSmallOrderedHashSet::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSmallOrderedHashSet*>(other) != nullptr;
}

uintptr_t TqSmallOrderedHashSet::GetNumberOfElementsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedHashSet::GetNumberOfElementsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfElementsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedHashSet::GetNumberOfDeletedElementsAddress() const {
  return address_ - i::kHeapObjectTag + 9;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedHashSet::GetNumberOfDeletedElementsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfDeletedElementsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedHashSet::GetNumberOfBucketsAddress() const {
  return address_ - i::kHeapObjectTag + 10;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedHashSet::GetNumberOfBucketsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfBucketsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedHashSet::GetPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 11;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedHashSet::GetPaddingValue(d::MemoryAccessor accessor, size_t offset) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetPaddingAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedHashSet::GetDataTableAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSmallOrderedHashSet::GetDataTableValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataTableAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSmallOrderedHashSet::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqSmallOrderedHashTable::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> number_of_elements_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_elements", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetNumberOfElementsAddress(), 1, 1, std::move(number_of_elements_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> number_of_deleted_elements_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_deleted_elements", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetNumberOfDeletedElementsAddress(), 1, 1, std::move(number_of_deleted_elements_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> number_of_buckets_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_buckets", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetNumberOfBucketsAddress(), 1, 1, std::move(number_of_buckets_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> padding_struct_field_list;
  auto indexed_field_slice_padding = TqDebugFieldSliceSmallOrderedHashSetPadding(accessor, address_);
  if (indexed_field_slice_padding.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("padding", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_padding.value), std::get<2>(indexed_field_slice_padding.value), 1, std::move(padding_struct_field_list), GetArrayKind(indexed_field_slice_padding.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> data_table_struct_field_list;
  auto indexed_field_slice_data_table = TqDebugFieldSliceSmallOrderedHashSetDataTable(accessor, address_);
  if (indexed_field_slice_data_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("data_table", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_data_table.value), std::get<2>(indexed_field_slice_data_table.value), 8, std::move(data_table_struct_field_list), GetArrayKind(indexed_field_slice_data_table.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> hash_table_struct_field_list;
  auto indexed_field_slice_hash_table = TqDebugFieldSliceSmallOrderedHashSetHashTable(accessor, address_);
  if (indexed_field_slice_hash_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("hash_table", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_hash_table.value), std::get<2>(indexed_field_slice_hash_table.value), 1, std::move(hash_table_struct_field_list), GetArrayKind(indexed_field_slice_hash_table.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> chain_table_struct_field_list;
  auto indexed_field_slice_chain_table = TqDebugFieldSliceSmallOrderedHashSetChainTable(accessor, address_);
  if (indexed_field_slice_chain_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("chain_table", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_chain_table.value), std::get<2>(indexed_field_slice_chain_table.value), 1, std::move(chain_table_struct_field_list), GetArrayKind(indexed_field_slice_chain_table.validity)));
  }
  return result;
}

const char* TqSmallOrderedHashMap::GetName() const {
  return "v8::internal::SmallOrderedHashMap";
}

void TqSmallOrderedHashMap::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSmallOrderedHashMap(this);
}

bool TqSmallOrderedHashMap::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSmallOrderedHashMap*>(other) != nullptr;
}

uintptr_t TqSmallOrderedHashMap::GetNumberOfElementsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedHashMap::GetNumberOfElementsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfElementsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedHashMap::GetNumberOfDeletedElementsAddress() const {
  return address_ - i::kHeapObjectTag + 9;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedHashMap::GetNumberOfDeletedElementsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfDeletedElementsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedHashMap::GetNumberOfBucketsAddress() const {
  return address_ - i::kHeapObjectTag + 10;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedHashMap::GetNumberOfBucketsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfBucketsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedHashMap::GetPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 11;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedHashMap::GetPaddingValue(d::MemoryAccessor accessor, size_t offset) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetPaddingAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedHashMap::GetDataTableAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

std::vector<std::unique_ptr<ObjectProperty>> TqSmallOrderedHashMap::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqSmallOrderedHashTable::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> number_of_elements_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_elements", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetNumberOfElementsAddress(), 1, 1, std::move(number_of_elements_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> number_of_deleted_elements_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_deleted_elements", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetNumberOfDeletedElementsAddress(), 1, 1, std::move(number_of_deleted_elements_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> number_of_buckets_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_buckets", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetNumberOfBucketsAddress(), 1, 1, std::move(number_of_buckets_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> padding_struct_field_list;
  auto indexed_field_slice_padding = TqDebugFieldSliceSmallOrderedHashMapPadding(accessor, address_);
  if (indexed_field_slice_padding.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("padding", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_padding.value), std::get<2>(indexed_field_slice_padding.value), 1, std::move(padding_struct_field_list), GetArrayKind(indexed_field_slice_padding.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> data_table_struct_field_list;
  data_table_struct_field_list.push_back(std::make_unique<StructProperty>("key", "v8::internal::Object", "v8::internal::Object", 0, 0, 0));
  data_table_struct_field_list.push_back(std::make_unique<StructProperty>("value", "v8::internal::Object", "v8::internal::Object", 8, 0, 0));
  auto indexed_field_slice_data_table = TqDebugFieldSliceSmallOrderedHashMapDataTable(accessor, address_);
  if (indexed_field_slice_data_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("data_table", "", "", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_data_table.value), std::get<2>(indexed_field_slice_data_table.value), 16, std::move(data_table_struct_field_list), GetArrayKind(indexed_field_slice_data_table.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> hash_table_struct_field_list;
  auto indexed_field_slice_hash_table = TqDebugFieldSliceSmallOrderedHashMapHashTable(accessor, address_);
  if (indexed_field_slice_hash_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("hash_table", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_hash_table.value), std::get<2>(indexed_field_slice_hash_table.value), 1, std::move(hash_table_struct_field_list), GetArrayKind(indexed_field_slice_hash_table.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> chain_table_struct_field_list;
  auto indexed_field_slice_chain_table = TqDebugFieldSliceSmallOrderedHashMapChainTable(accessor, address_);
  if (indexed_field_slice_chain_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("chain_table", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_chain_table.value), std::get<2>(indexed_field_slice_chain_table.value), 1, std::move(chain_table_struct_field_list), GetArrayKind(indexed_field_slice_chain_table.validity)));
  }
  return result;
}

const char* TqSmallOrderedNameDictionary::GetName() const {
  return "v8::internal::SmallOrderedNameDictionary";
}

void TqSmallOrderedNameDictionary::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSmallOrderedNameDictionary(this);
}

bool TqSmallOrderedNameDictionary::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSmallOrderedNameDictionary*>(other) != nullptr;
}

uintptr_t TqSmallOrderedNameDictionary::GetHashAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedNameDictionary::GetHashValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetHashAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedNameDictionary::GetPadding0Address() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedNameDictionary::GetPadding0Value(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetPadding0Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedNameDictionary::GetNumberOfElementsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedNameDictionary::GetNumberOfElementsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfElementsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedNameDictionary::GetNumberOfDeletedElementsAddress() const {
  return address_ - i::kHeapObjectTag + 17;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedNameDictionary::GetNumberOfDeletedElementsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfDeletedElementsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedNameDictionary::GetNumberOfBucketsAddress() const {
  return address_ - i::kHeapObjectTag + 18;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedNameDictionary::GetNumberOfBucketsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfBucketsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedNameDictionary::GetPadding1Address() const {
  return address_ - i::kHeapObjectTag + 19;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSmallOrderedNameDictionary::GetPadding1Value(d::MemoryAccessor accessor, size_t offset) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetPadding1Address() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSmallOrderedNameDictionary::GetDataTableAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

std::vector<std::unique_ptr<ObjectProperty>> TqSmallOrderedNameDictionary::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqSmallOrderedHashTable::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> hash_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("hash", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetHashAddress(), 1, 4, std::move(hash_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> padding_0_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("padding_0", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetPadding0Address(), 1, 4, std::move(padding_0_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> number_of_elements_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_elements", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetNumberOfElementsAddress(), 1, 1, std::move(number_of_elements_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> number_of_deleted_elements_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_deleted_elements", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetNumberOfDeletedElementsAddress(), 1, 1, std::move(number_of_deleted_elements_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> number_of_buckets_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_buckets", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetNumberOfBucketsAddress(), 1, 1, std::move(number_of_buckets_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> padding_1_struct_field_list;
  auto indexed_field_slice_padding_1 = TqDebugFieldSliceSmallOrderedNameDictionaryPadding1(accessor, address_);
  if (indexed_field_slice_padding_1.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("padding_1", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_padding_1.value), std::get<2>(indexed_field_slice_padding_1.value), 1, std::move(padding_1_struct_field_list), GetArrayKind(indexed_field_slice_padding_1.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> data_table_struct_field_list;
  data_table_struct_field_list.push_back(std::make_unique<StructProperty>("key", "v8::internal::Object", "v8::internal::Object", 0, 0, 0));
  data_table_struct_field_list.push_back(std::make_unique<StructProperty>("value", "v8::internal::Object", "v8::internal::Object", 8, 0, 0));
  data_table_struct_field_list.push_back(std::make_unique<StructProperty>("property_details", "v8::internal::Object", "v8::internal::Object", 16, 0, 0));
  auto indexed_field_slice_data_table = TqDebugFieldSliceSmallOrderedNameDictionaryDataTable(accessor, address_);
  if (indexed_field_slice_data_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("data_table", "", "", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_data_table.value), std::get<2>(indexed_field_slice_data_table.value), 24, std::move(data_table_struct_field_list), GetArrayKind(indexed_field_slice_data_table.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> hash_table_struct_field_list;
  auto indexed_field_slice_hash_table = TqDebugFieldSliceSmallOrderedNameDictionaryHashTable(accessor, address_);
  if (indexed_field_slice_hash_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("hash_table", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_hash_table.value), std::get<2>(indexed_field_slice_hash_table.value), 1, std::move(hash_table_struct_field_list), GetArrayKind(indexed_field_slice_hash_table.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> chain_table_struct_field_list;
  auto indexed_field_slice_chain_table = TqDebugFieldSliceSmallOrderedNameDictionaryChainTable(accessor, address_);
  if (indexed_field_slice_chain_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("chain_table", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_chain_table.value), std::get<2>(indexed_field_slice_chain_table.value), 1, std::move(chain_table_struct_field_list), GetArrayKind(indexed_field_slice_chain_table.validity)));
  }
  return result;
}

const char* TqPromiseReaction::GetName() const {
  return "v8::internal::PromiseReaction";
}

void TqPromiseReaction::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseReaction(this);
}

bool TqPromiseReaction::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseReaction*>(other) != nullptr;
}

uintptr_t TqPromiseReaction::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPromiseReaction::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReaction::GetRejectHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPromiseReaction::GetRejectHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRejectHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReaction::GetFulfillHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqPromiseReaction::GetFulfillHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFulfillHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReaction::GetPromiseOrCapabilityAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqPromiseReaction::GetPromiseOrCapabilityValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseOrCapabilityAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReaction::GetContinuationPreservedEmbedderDataAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqPromiseReaction::GetContinuationPreservedEmbedderDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContinuationPreservedEmbedderDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseReaction::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> next_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::Object", "v8::internal::Object", GetNextAddress(), 1, 8, std::move(next_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> reject_handler_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("reject_handler", "v8::internal::HeapObject", "v8::internal::HeapObject", GetRejectHandlerAddress(), 1, 8, std::move(reject_handler_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> fulfill_handler_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("fulfill_handler", "v8::internal::HeapObject", "v8::internal::HeapObject", GetFulfillHandlerAddress(), 1, 8, std::move(fulfill_handler_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> promise_or_capability_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("promise_or_capability", "v8::internal::HeapObject", "v8::internal::HeapObject", GetPromiseOrCapabilityAddress(), 1, 8, std::move(promise_or_capability_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> continuation_preserved_embedder_data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("continuation_preserved_embedder_data", "v8::internal::Object", "v8::internal::Object", GetContinuationPreservedEmbedderDataAddress(), 1, 8, std::move(continuation_preserved_embedder_data_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqPromiseReactionJobTask::GetName() const {
  return "v8::internal::PromiseReactionJobTask";
}

void TqPromiseReactionJobTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseReactionJobTask(this);
}

bool TqPromiseReactionJobTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseReactionJobTask*>(other) != nullptr;
}

uintptr_t TqPromiseReactionJobTask::GetArgumentAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPromiseReactionJobTask::GetArgumentValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetArgumentAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReactionJobTask::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPromiseReactionJobTask::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReactionJobTask::GetHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqPromiseReactionJobTask::GetHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReactionJobTask::GetPromiseOrCapabilityAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqPromiseReactionJobTask::GetPromiseOrCapabilityValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseOrCapabilityAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReactionJobTask::GetContinuationPreservedEmbedderDataAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqPromiseReactionJobTask::GetContinuationPreservedEmbedderDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContinuationPreservedEmbedderDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseReactionJobTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqMicrotask::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> argument_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("argument", "v8::internal::Object", "v8::internal::Object", GetArgumentAddress(), 1, 8, std::move(argument_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::Context", "v8::internal::Context", GetContextAddress(), 1, 8, std::move(context_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> handler_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("handler", "v8::internal::HeapObject", "v8::internal::HeapObject", GetHandlerAddress(), 1, 8, std::move(handler_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> promise_or_capability_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("promise_or_capability", "v8::internal::HeapObject", "v8::internal::HeapObject", GetPromiseOrCapabilityAddress(), 1, 8, std::move(promise_or_capability_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> continuation_preserved_embedder_data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("continuation_preserved_embedder_data", "v8::internal::Object", "v8::internal::Object", GetContinuationPreservedEmbedderDataAddress(), 1, 8, std::move(continuation_preserved_embedder_data_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqPromiseFulfillReactionJobTask::GetName() const {
  return "v8::internal::PromiseFulfillReactionJobTask";
}

void TqPromiseFulfillReactionJobTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseFulfillReactionJobTask(this);
}

bool TqPromiseFulfillReactionJobTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseFulfillReactionJobTask*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseFulfillReactionJobTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPromiseReactionJobTask::GetProperties(accessor);
  return result;
}

const char* TqPromiseRejectReactionJobTask::GetName() const {
  return "v8::internal::PromiseRejectReactionJobTask";
}

void TqPromiseRejectReactionJobTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseRejectReactionJobTask(this);
}

bool TqPromiseRejectReactionJobTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseRejectReactionJobTask*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseRejectReactionJobTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPromiseReactionJobTask::GetProperties(accessor);
  return result;
}

const char* TqPromiseResolveThenableJobTask::GetName() const {
  return "v8::internal::PromiseResolveThenableJobTask";
}

void TqPromiseResolveThenableJobTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseResolveThenableJobTask(this);
}

bool TqPromiseResolveThenableJobTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseResolveThenableJobTask*>(other) != nullptr;
}

uintptr_t TqPromiseResolveThenableJobTask::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPromiseResolveThenableJobTask::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseResolveThenableJobTask::GetPromiseToResolveAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPromiseResolveThenableJobTask::GetPromiseToResolveValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseToResolveAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseResolveThenableJobTask::GetThenableAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqPromiseResolveThenableJobTask::GetThenableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetThenableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseResolveThenableJobTask::GetThenAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqPromiseResolveThenableJobTask::GetThenValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetThenAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseResolveThenableJobTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqMicrotask::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::Context", "v8::internal::Context", GetContextAddress(), 1, 8, std::move(context_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> promise_to_resolve_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("promise_to_resolve", "v8::internal::JSPromise", "v8::internal::JSPromise", GetPromiseToResolveAddress(), 1, 8, std::move(promise_to_resolve_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> thenable_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("thenable", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetThenableAddress(), 1, 8, std::move(thenable_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> then_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("then", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetThenAddress(), 1, 8, std::move(then_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqPropertyArray::GetName() const {
  return "v8::internal::PropertyArray";
}

void TqPropertyArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPropertyArray(this);
}

bool TqPropertyArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPropertyArray*>(other) != nullptr;
}

uintptr_t TqPropertyArray::GetLengthAndHashAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPropertyArray::GetLengthAndHashValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAndHashAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPropertyArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_and_hash_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length_and_hash", "v8::internal::Object", "v8::internal::Object", GetLengthAndHashAddress(), 1, 8, std::move(length_and_hash_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqPropertyCell::GetName() const {
  return "v8::internal::PropertyCell";
}

void TqPropertyCell::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPropertyCell(this);
}

bool TqPropertyCell::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPropertyCell*>(other) != nullptr;
}

uintptr_t TqPropertyCell::GetNameAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPropertyCell::GetNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPropertyCell::GetPropertyDetailsRawAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPropertyCell::GetPropertyDetailsRawValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPropertyDetailsRawAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPropertyCell::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqPropertyCell::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPropertyCell::GetDependentCodeAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqPropertyCell::GetDependentCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDependentCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPropertyCell::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("name", "v8::internal::Name", "v8::internal::Name", GetNameAddress(), 1, 8, std::move(name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> property_details_raw_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("property_details_raw", "v8::internal::Object", "v8::internal::Object", GetPropertyDetailsRawAddress(), 1, 8, std::move(property_details_raw_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::Object", "v8::internal::Object", GetValueAddress(), 1, 8, std::move(value_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> dependent_code_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("dependent_code", "v8::internal::WeakFixedArray", "v8::internal::WeakFixedArray", GetDependentCodeAddress(), 1, 8, std::move(dependent_code_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqPropertyDescriptorObject::GetName() const {
  return "v8::internal::PropertyDescriptorObject";
}

void TqPropertyDescriptorObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPropertyDescriptorObject(this);
}

bool TqPropertyDescriptorObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPropertyDescriptorObject*>(other) != nullptr;
}

uintptr_t TqPropertyDescriptorObject::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPropertyDescriptorObject::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPropertyDescriptorObject::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPropertyDescriptorObject::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPropertyDescriptorObject::GetGetAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqPropertyDescriptorObject::GetGetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPropertyDescriptorObject::GetSetAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqPropertyDescriptorObject::GetSetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPropertyDescriptorObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_enumerable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_enumerable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 33));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_configurable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 34));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_configurable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 35));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_writable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 36));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_writable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 37));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_value", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 38));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_get", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 39));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_set", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 40));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::Object", "v8::internal::Object", GetValueAddress(), 1, 8, std::move(value_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> get_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("get", "v8::internal::Object", "v8::internal::Object", GetGetAddress(), 1, 8, std::move(get_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> set_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("set", "v8::internal::Object", "v8::internal::Object", GetSetAddress(), 1, 8, std::move(set_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqPrototypeInfo::GetName() const {
  return "v8::internal::PrototypeInfo";
}

void TqPrototypeInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPrototypeInfo(this);
}

bool TqPrototypeInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPrototypeInfo*>(other) != nullptr;
}

uintptr_t TqPrototypeInfo::GetModuleNamespaceAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPrototypeInfo::GetModuleNamespaceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetModuleNamespaceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPrototypeInfo::GetPrototypeUsersAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPrototypeInfo::GetPrototypeUsersValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeUsersAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPrototypeInfo::GetPrototypeChainEnumCacheAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqPrototypeInfo::GetPrototypeChainEnumCacheValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeChainEnumCacheAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPrototypeInfo::GetRegistrySlotAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqPrototypeInfo::GetRegistrySlotValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRegistrySlotAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPrototypeInfo::GetBitFieldAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqPrototypeInfo::GetBitFieldValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBitFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPrototypeInfo::GetObjectCreateMapAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqPrototypeInfo::GetObjectCreateMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetObjectCreateMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPrototypeInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> module_namespace_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("module_namespace", "v8::internal::HeapObject", "v8::internal::HeapObject", GetModuleNamespaceAddress(), 1, 8, std::move(module_namespace_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> prototype_users_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("prototype_users", "v8::internal::Object", "v8::internal::Object", GetPrototypeUsersAddress(), 1, 8, std::move(prototype_users_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> prototype_chain_enum_cache_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("prototype_chain_enum_cache", "v8::internal::Object", "v8::internal::Object", GetPrototypeChainEnumCacheAddress(), 1, 8, std::move(prototype_chain_enum_cache_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> registry_slot_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("registry_slot", "v8::internal::Object", "v8::internal::Object", GetRegistrySlotAddress(), 1, 8, std::move(registry_slot_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bit_field_struct_field_list;
  bit_field_struct_field_list.push_back(std::make_unique<StructProperty>("should_be_fast", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  result.push_back(std::make_unique<ObjectProperty>("bit_field", "v8::internal::Object", "v8::internal::Object", GetBitFieldAddress(), 1, 8, std::move(bit_field_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> object_create_map_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("object_create_map", "v8::internal::Object", "v8::internal::Object", GetObjectCreateMapAddress(), 1, 8, std::move(object_create_map_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqScript::GetName() const {
  return "v8::internal::Script";
}

void TqScript::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitScript(this);
}

bool TqScript::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqScript*>(other) != nullptr;
}

uintptr_t TqScript::GetSourceAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqScript::GetSourceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetNameAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqScript::GetNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetLineOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqScript::GetLineOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLineOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetColumnOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqScript::GetColumnOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetColumnOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetContextDataAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqScript::GetContextDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetScriptTypeAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqScript::GetScriptTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetLineEndsAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqScript::GetLineEndsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLineEndsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetIdAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqScript::GetIdValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetEvalFromSharedOrWrappedArgumentsAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqScript::GetEvalFromSharedOrWrappedArgumentsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEvalFromSharedOrWrappedArgumentsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetEvalFromPositionAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqScript::GetEvalFromPositionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEvalFromPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetSharedFunctionInfosAddress() const {
  return address_ - i::kHeapObjectTag + 88;
}

Value<uintptr_t> TqScript::GetSharedFunctionInfosValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedFunctionInfosAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetCompiledLazyFunctionPositionsAddress() const {
  return address_ - i::kHeapObjectTag + 96;
}

Value<uintptr_t> TqScript::GetCompiledLazyFunctionPositionsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCompiledLazyFunctionPositionsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 104;
}

Value<uintptr_t> TqScript::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetSourceUrlAddress() const {
  return address_ - i::kHeapObjectTag + 112;
}

Value<uintptr_t> TqScript::GetSourceUrlValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourceUrlAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetSourceMappingUrlAddress() const {
  return address_ - i::kHeapObjectTag + 120;
}

Value<uintptr_t> TqScript::GetSourceMappingUrlValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourceMappingUrlAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetHostDefinedOptionsAddress() const {
  return address_ - i::kHeapObjectTag + 128;
}

Value<uintptr_t> TqScript::GetHostDefinedOptionsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHostDefinedOptionsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetSourceHashAddress() const {
  return address_ - i::kHeapObjectTag + 136;
}

Value<uintptr_t> TqScript::GetSourceHashValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourceHashAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqScript::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> source_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("source", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", GetSourceAddress(), 1, 8, std::move(source_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("name", "v8::internal::Object", "v8::internal::Object", GetNameAddress(), 1, 8, std::move(name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> line_offset_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("line_offset", "v8::internal::Object", "v8::internal::Object", GetLineOffsetAddress(), 1, 8, std::move(line_offset_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> column_offset_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("column_offset", "v8::internal::Object", "v8::internal::Object", GetColumnOffsetAddress(), 1, 8, std::move(column_offset_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> context_data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("context_data", "v8::internal::Object", "v8::internal::Object", GetContextDataAddress(), 1, 8, std::move(context_data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> script_type_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("script_type", "v8::internal::Object", "v8::internal::Object", GetScriptTypeAddress(), 1, 8, std::move(script_type_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> line_ends_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("line_ends", "v8::internal::Object", "v8::internal::Object", GetLineEndsAddress(), 1, 8, std::move(line_ends_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> id_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("id", "v8::internal::Object", "v8::internal::Object", GetIdAddress(), 1, 8, std::move(id_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> eval_from_shared_or_wrapped_arguments_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("eval_from_shared_or_wrapped_arguments", "v8::internal::HeapObject", "v8::internal::HeapObject", GetEvalFromSharedOrWrappedArgumentsAddress(), 1, 8, std::move(eval_from_shared_or_wrapped_arguments_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> eval_from_position_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("eval_from_position", "v8::internal::Object", "v8::internal::Object", GetEvalFromPositionAddress(), 1, 8, std::move(eval_from_position_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> shared_function_infos_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("shared_function_infos", "v8::internal::HeapObject", "v8::internal::HeapObject", GetSharedFunctionInfosAddress(), 1, 8, std::move(shared_function_infos_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> compiled_lazy_function_positions_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("compiled_lazy_function_positions", "v8::internal::HeapObject", "v8::internal::HeapObject", GetCompiledLazyFunctionPositionsAddress(), 1, 8, std::move(compiled_lazy_function_positions_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("compilation_type", CheckTypeName<Script::CompilationType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Script::CompilationType"), CheckTypeName<Script::CompilationType /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Script::CompilationType"), 0, 1, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("compilation_state", CheckTypeName<Script::CompilationState /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Script::CompilationState"), CheckTypeName<Script::CompilationState /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Script::CompilationState"), 0, 1, 33));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_repl_mode", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 34));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("origin_options", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 4, 35));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("break_on_entry", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 39));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("produce_compile_hints", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 40));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> source_url_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("source_url", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", GetSourceUrlAddress(), 1, 8, std::move(source_url_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> source_mapping_url_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("source_mapping_url", "v8::internal::Object", "v8::internal::Object", GetSourceMappingUrlAddress(), 1, 8, std::move(source_mapping_url_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> host_defined_options_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("host_defined_options", "v8::internal::FixedArray", "v8::internal::FixedArray", GetHostDefinedOptionsAddress(), 1, 8, std::move(host_defined_options_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> source_hash_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("source_hash", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", GetSourceHashAddress(), 1, 8, std::move(source_hash_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqPreparseData::GetName() const {
  return "v8::internal::PreparseData";
}

void TqPreparseData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPreparseData(this);
}

bool TqPreparseData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPreparseData*>(other) != nullptr;
}

uintptr_t TqPreparseData::GetDataLengthAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqPreparseData::GetDataLengthValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetDataLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqPreparseData::GetChildrenLengthAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqPreparseData::GetChildrenLengthValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetChildrenLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPreparseData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> data_length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data_length", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetDataLengthAddress(), 1, 4, std::move(data_length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> children_length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("children_length", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetChildrenLengthAddress(), 1, 4, std::move(children_length_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqInterpreterData::GetName() const {
  return "v8::internal::InterpreterData";
}

void TqInterpreterData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitInterpreterData(this);
}

bool TqInterpreterData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqInterpreterData*>(other) != nullptr;
}

uintptr_t TqInterpreterData::GetBytecodeArrayAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqInterpreterData::GetBytecodeArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBytecodeArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterpreterData::GetInterpreterTrampolineAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqInterpreterData::GetInterpreterTrampolineValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInterpreterTrampolineAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqInterpreterData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> bytecode_array_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bytecode_array", "v8::internal::BytecodeArray", "v8::internal::BytecodeArray", GetBytecodeArrayAddress(), 1, 8, std::move(bytecode_array_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> interpreter_trampoline_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("interpreter_trampoline", "v8::internal::Code", "v8::internal::Code", GetInterpreterTrampolineAddress(), 1, 8, std::move(interpreter_trampoline_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqSharedFunctionInfo::GetName() const {
  return "v8::internal::SharedFunctionInfo";
}

void TqSharedFunctionInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSharedFunctionInfo(this);
}

bool TqSharedFunctionInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSharedFunctionInfo*>(other) != nullptr;
}

uintptr_t TqSharedFunctionInfo::GetFunctionDataAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSharedFunctionInfo::GetFunctionDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSharedFunctionInfo::GetNameOrScopeInfoAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSharedFunctionInfo::GetNameOrScopeInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameOrScopeInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSharedFunctionInfo::GetOuterScopeInfoOrFeedbackMetadataAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqSharedFunctionInfo::GetOuterScopeInfoOrFeedbackMetadataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOuterScopeInfoOrFeedbackMetadataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSharedFunctionInfo::GetScriptAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqSharedFunctionInfo::GetScriptValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSharedFunctionInfo::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<int16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSharedFunctionInfo::GetLengthValue(d::MemoryAccessor accessor) const {
  int16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetFormalParameterCountAddress() const {
  return address_ - i::kHeapObjectTag + 42;
}

Value<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSharedFunctionInfo::GetFormalParameterCountValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFormalParameterCountAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetFunctionTokenOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSharedFunctionInfo::GetFunctionTokenOffsetValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFunctionTokenOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetExpectedNofPropertiesAddress() const {
  return address_ - i::kHeapObjectTag + 46;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSharedFunctionInfo::GetExpectedNofPropertiesValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetExpectedNofPropertiesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetFlags2Address() const {
  return address_ - i::kHeapObjectTag + 47;
}

Value<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSharedFunctionInfo::GetFlags2Value(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFlags2Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSharedFunctionInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetFunctionLiteralIdAddress() const {
  return address_ - i::kHeapObjectTag + 52;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSharedFunctionInfo::GetFunctionLiteralIdValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFunctionLiteralIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetUniqueIdAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSharedFunctionInfo::GetUniqueIdValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetUniqueIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetAgeAddress() const {
  return address_ - i::kHeapObjectTag + 60;
}

Value<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSharedFunctionInfo::GetAgeValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetAgeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 62;
}

Value<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSharedFunctionInfo::GetPaddingValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSharedFunctionInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> function_data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("function_data", "v8::internal::Object", "v8::internal::Object", GetFunctionDataAddress(), 1, 8, std::move(function_data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> name_or_scope_info_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("name_or_scope_info", "v8::internal::Object", "v8::internal::Object", GetNameOrScopeInfoAddress(), 1, 8, std::move(name_or_scope_info_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> outer_scope_info_or_feedback_metadata_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("outer_scope_info_or_feedback_metadata", "v8::internal::HeapObject", "v8::internal::HeapObject", GetOuterScopeInfoOrFeedbackMetadataAddress(), 1, 8, std::move(outer_scope_info_or_feedback_metadata_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> script_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("script", "v8::internal::HeapObject", "v8::internal::HeapObject", GetScriptAddress(), 1, 8, std::move(script_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", CheckTypeName<int16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int16_t"), CheckTypeName<int16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int16_t"), GetLengthAddress(), 1, 2, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> formal_parameter_count_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("formal_parameter_count", CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), GetFormalParameterCountAddress(), 1, 2, std::move(formal_parameter_count_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> function_token_offset_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("function_token_offset", CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), GetFunctionTokenOffsetAddress(), 1, 2, std::move(function_token_offset_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> expected_nof_properties_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("expected_nof_properties", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetExpectedNofPropertiesAddress(), 1, 1, std::move(expected_nof_properties_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags2_struct_field_list;
  flags2_struct_field_list.push_back(std::make_unique<StructProperty>("class_scope_has_private_brand", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 0));
  flags2_struct_field_list.push_back(std::make_unique<StructProperty>("has_static_private_methods_or_accessors", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 1));
  flags2_struct_field_list.push_back(std::make_unique<StructProperty>("is_sparkplug_compiling", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 2));
  flags2_struct_field_list.push_back(std::make_unique<StructProperty>("maglev_compilation_failed", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 3));
  flags2_struct_field_list.push_back(std::make_unique<StructProperty>("sparkplug_compiled", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 4));
  result.push_back(std::make_unique<ObjectProperty>("flags2", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), GetFlags2Address(), 1, 1, std::move(flags2_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("function_kind", CheckTypeName<FunctionKind /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("FunctionKind"), CheckTypeName<FunctionKind /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("FunctionKind"), 0, 5, 0));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_native", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 5));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_strict", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 6));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("function_syntax_kind", CheckTypeName<FunctionSyntaxKind /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("FunctionSyntaxKind"), CheckTypeName<FunctionSyntaxKind /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("FunctionSyntaxKind"), 0, 3, 7));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_class_constructor", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 10));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_duplicate_parameters", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 11));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("allow_lazy_compilation", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 12));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_asm_wasm_broken", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 13));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("function_map_index", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), 0, 5, 14));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("disabled_optimization_reason", CheckTypeName<BailoutReason /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("BailoutReason"), CheckTypeName<BailoutReason /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("BailoutReason"), 0, 4, 19));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("requires_instance_members_initializer", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 23));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("construct_as_builtin", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 24));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("name_should_print_as_anonymous", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 25));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("has_reported_binary_coverage", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 26));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("is_top_level", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 27));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("properties_are_final", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 28));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("private_name_lookup_skips_outer_class", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 29));
  result.push_back(std::make_unique<ObjectProperty>("flags", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetFlagsAddress(), 1, 4, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> function_literal_id_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("function_literal_id", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetFunctionLiteralIdAddress(), 1, 4, std::move(function_literal_id_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> unique_id_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("unique_id", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetUniqueIdAddress(), 1, 4, std::move(unique_id_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> age_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("age", CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), GetAgeAddress(), 1, 2, std::move(age_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("padding", CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), CheckTypeName<uint16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint16_t"), GetPaddingAddress(), 1, 2, std::move(padding_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqUncompiledData::GetName() const {
  return "v8::internal::UncompiledData";
}

void TqUncompiledData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitUncompiledData(this);
}

bool TqUncompiledData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqUncompiledData*>(other) != nullptr;
}

uintptr_t TqUncompiledData::GetInferredNameAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqUncompiledData::GetInferredNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInferredNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqUncompiledData::GetStartPositionAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqUncompiledData::GetStartPositionValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetStartPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqUncompiledData::GetEndPositionAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqUncompiledData::GetEndPositionValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetEndPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqUncompiledData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> inferred_name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("inferred_name", "v8::internal::String", "v8::internal::String", GetInferredNameAddress(), 1, 8, std::move(inferred_name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> start_position_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("start_position", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetStartPositionAddress(), 1, 4, std::move(start_position_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> end_position_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("end_position", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetEndPositionAddress(), 1, 4, std::move(end_position_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqUncompiledDataWithoutPreparseData::GetName() const {
  return "v8::internal::UncompiledDataWithoutPreparseData";
}

void TqUncompiledDataWithoutPreparseData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitUncompiledDataWithoutPreparseData(this);
}

bool TqUncompiledDataWithoutPreparseData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqUncompiledDataWithoutPreparseData*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqUncompiledDataWithoutPreparseData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqUncompiledData::GetProperties(accessor);
  return result;
}

const char* TqUncompiledDataWithPreparseData::GetName() const {
  return "v8::internal::UncompiledDataWithPreparseData";
}

void TqUncompiledDataWithPreparseData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitUncompiledDataWithPreparseData(this);
}

bool TqUncompiledDataWithPreparseData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqUncompiledDataWithPreparseData*>(other) != nullptr;
}

uintptr_t TqUncompiledDataWithPreparseData::GetPreparseDataAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqUncompiledDataWithPreparseData::GetPreparseDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPreparseDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqUncompiledDataWithPreparseData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqUncompiledData::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> preparse_data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("preparse_data", "v8::internal::PreparseData", "v8::internal::PreparseData", GetPreparseDataAddress(), 1, 8, std::move(preparse_data_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqUncompiledDataWithoutPreparseDataWithJob::GetName() const {
  return "v8::internal::UncompiledDataWithoutPreparseDataWithJob";
}

void TqUncompiledDataWithoutPreparseDataWithJob::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitUncompiledDataWithoutPreparseDataWithJob(this);
}

bool TqUncompiledDataWithoutPreparseDataWithJob::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqUncompiledDataWithoutPreparseDataWithJob*>(other) != nullptr;
}

uintptr_t TqUncompiledDataWithoutPreparseDataWithJob::GetJobAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqUncompiledDataWithoutPreparseDataWithJob::GetJobValue(d::MemoryAccessor accessor) const {
  Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetJobAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqUncompiledDataWithoutPreparseDataWithJob::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqUncompiledDataWithoutPreparseData::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> job_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("job", CheckTypeName<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Address"), CheckTypeName<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Address"), GetJobAddress(), 1, 8, std::move(job_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqUncompiledDataWithPreparseDataAndJob::GetName() const {
  return "v8::internal::UncompiledDataWithPreparseDataAndJob";
}

void TqUncompiledDataWithPreparseDataAndJob::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitUncompiledDataWithPreparseDataAndJob(this);
}

bool TqUncompiledDataWithPreparseDataAndJob::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqUncompiledDataWithPreparseDataAndJob*>(other) != nullptr;
}

uintptr_t TqUncompiledDataWithPreparseDataAndJob::GetJobAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqUncompiledDataWithPreparseDataAndJob::GetJobValue(d::MemoryAccessor accessor) const {
  Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetJobAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqUncompiledDataWithPreparseDataAndJob::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqUncompiledDataWithPreparseData::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> job_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("job", CheckTypeName<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Address"), CheckTypeName<Address /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("Address"), GetJobAddress(), 1, 8, std::move(job_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqOnHeapBasicBlockProfilerData::GetName() const {
  return "v8::internal::OnHeapBasicBlockProfilerData";
}

void TqOnHeapBasicBlockProfilerData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitOnHeapBasicBlockProfilerData(this);
}

bool TqOnHeapBasicBlockProfilerData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqOnHeapBasicBlockProfilerData*>(other) != nullptr;
}

uintptr_t TqOnHeapBasicBlockProfilerData::GetBlockIdsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqOnHeapBasicBlockProfilerData::GetBlockIdsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBlockIdsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOnHeapBasicBlockProfilerData::GetCountsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqOnHeapBasicBlockProfilerData::GetCountsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCountsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOnHeapBasicBlockProfilerData::GetBranchesAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqOnHeapBasicBlockProfilerData::GetBranchesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBranchesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOnHeapBasicBlockProfilerData::GetNameAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqOnHeapBasicBlockProfilerData::GetNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOnHeapBasicBlockProfilerData::GetScheduleAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqOnHeapBasicBlockProfilerData::GetScheduleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScheduleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOnHeapBasicBlockProfilerData::GetCodeAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqOnHeapBasicBlockProfilerData::GetCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOnHeapBasicBlockProfilerData::GetHashAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqOnHeapBasicBlockProfilerData::GetHashValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHashAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqOnHeapBasicBlockProfilerData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> block_ids_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("block_ids", "v8::internal::ByteArray", "v8::internal::ByteArray", GetBlockIdsAddress(), 1, 8, std::move(block_ids_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> counts_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("counts", "v8::internal::ByteArray", "v8::internal::ByteArray", GetCountsAddress(), 1, 8, std::move(counts_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> branches_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("branches", "v8::internal::ByteArray", "v8::internal::ByteArray", GetBranchesAddress(), 1, 8, std::move(branches_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("name", "v8::internal::String", "v8::internal::String", GetNameAddress(), 1, 8, std::move(name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> schedule_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("schedule", "v8::internal::String", "v8::internal::String", GetScheduleAddress(), 1, 8, std::move(schedule_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> code_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("code", "v8::internal::String", "v8::internal::String", GetCodeAddress(), 1, 8, std::move(code_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> hash_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("hash", "v8::internal::Object", "v8::internal::Object", GetHashAddress(), 1, 8, std::move(hash_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqSourceTextModule::GetName() const {
  return "v8::internal::SourceTextModule";
}

void TqSourceTextModule::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSourceTextModule(this);
}

bool TqSourceTextModule::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSourceTextModule*>(other) != nullptr;
}

uintptr_t TqSourceTextModule::GetCodeAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqSourceTextModule::GetCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetRegularExportsAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqSourceTextModule::GetRegularExportsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRegularExportsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetRegularImportsAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqSourceTextModule::GetRegularImportsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRegularImportsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetRequestedModulesAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqSourceTextModule::GetRequestedModulesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRequestedModulesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetImportMetaAddress() const {
  return address_ - i::kHeapObjectTag + 88;
}

Value<uintptr_t> TqSourceTextModule::GetImportMetaValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetImportMetaAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetCycleRootAddress() const {
  return address_ - i::kHeapObjectTag + 96;
}

Value<uintptr_t> TqSourceTextModule::GetCycleRootValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCycleRootAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetAsyncParentModulesAddress() const {
  return address_ - i::kHeapObjectTag + 104;
}

Value<uintptr_t> TqSourceTextModule::GetAsyncParentModulesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAsyncParentModulesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetDfsIndexAddress() const {
  return address_ - i::kHeapObjectTag + 112;
}

Value<uintptr_t> TqSourceTextModule::GetDfsIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDfsIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetDfsAncestorIndexAddress() const {
  return address_ - i::kHeapObjectTag + 120;
}

Value<uintptr_t> TqSourceTextModule::GetDfsAncestorIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDfsAncestorIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetPendingAsyncDependenciesAddress() const {
  return address_ - i::kHeapObjectTag + 128;
}

Value<uintptr_t> TqSourceTextModule::GetPendingAsyncDependenciesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPendingAsyncDependenciesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 136;
}

Value<uintptr_t> TqSourceTextModule::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSourceTextModule::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqModule::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> code_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("code", "v8::internal::HeapObject", "v8::internal::HeapObject", GetCodeAddress(), 1, 8, std::move(code_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> regular_exports_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("regular_exports", "v8::internal::FixedArray", "v8::internal::FixedArray", GetRegularExportsAddress(), 1, 8, std::move(regular_exports_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> regular_imports_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("regular_imports", "v8::internal::FixedArray", "v8::internal::FixedArray", GetRegularImportsAddress(), 1, 8, std::move(regular_imports_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> requested_modules_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("requested_modules", "v8::internal::FixedArray", "v8::internal::FixedArray", GetRequestedModulesAddress(), 1, 8, std::move(requested_modules_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> import_meta_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("import_meta", "v8::internal::HeapObject", "v8::internal::HeapObject", GetImportMetaAddress(), 1, 8, std::move(import_meta_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> cycle_root_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("cycle_root", "v8::internal::HeapObject", "v8::internal::HeapObject", GetCycleRootAddress(), 1, 8, std::move(cycle_root_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> async_parent_modules_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("async_parent_modules", "v8::internal::ArrayList", "v8::internal::ArrayList", GetAsyncParentModulesAddress(), 1, 8, std::move(async_parent_modules_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> dfs_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("dfs_index", "v8::internal::Object", "v8::internal::Object", GetDfsIndexAddress(), 1, 8, std::move(dfs_index_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> dfs_ancestor_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("dfs_ancestor_index", "v8::internal::Object", "v8::internal::Object", GetDfsAncestorIndexAddress(), 1, 8, std::move(dfs_ancestor_index_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> pending_async_dependencies_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("pending_async_dependencies", "v8::internal::Object", "v8::internal::Object", GetPendingAsyncDependenciesAddress(), 1, 8, std::move(pending_async_dependencies_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("async", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("async_evaluating_ordinal", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), 0, 30, 33));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqModuleRequest::GetName() const {
  return "v8::internal::ModuleRequest";
}

void TqModuleRequest::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitModuleRequest(this);
}

bool TqModuleRequest::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqModuleRequest*>(other) != nullptr;
}

uintptr_t TqModuleRequest::GetSpecifierAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqModuleRequest::GetSpecifierValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSpecifierAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModuleRequest::GetImportAssertionsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqModuleRequest::GetImportAssertionsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetImportAssertionsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModuleRequest::GetPositionAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqModuleRequest::GetPositionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqModuleRequest::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> specifier_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("specifier", "v8::internal::String", "v8::internal::String", GetSpecifierAddress(), 1, 8, std::move(specifier_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> import_assertions_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("import_assertions", "v8::internal::FixedArray", "v8::internal::FixedArray", GetImportAssertionsAddress(), 1, 8, std::move(import_assertions_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> position_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("position", "v8::internal::Object", "v8::internal::Object", GetPositionAddress(), 1, 8, std::move(position_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqSourceTextModuleInfoEntry::GetName() const {
  return "v8::internal::SourceTextModuleInfoEntry";
}

void TqSourceTextModuleInfoEntry::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSourceTextModuleInfoEntry(this);
}

bool TqSourceTextModuleInfoEntry::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSourceTextModuleInfoEntry*>(other) != nullptr;
}

uintptr_t TqSourceTextModuleInfoEntry::GetExportNameAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetExportNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExportNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetLocalNameAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetLocalNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocalNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetImportNameAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetImportNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetImportNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetModuleRequestAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetModuleRequestValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetModuleRequestAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetCellIndexAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetCellIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCellIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetBegPosAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetBegPosValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBegPosAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetEndPosAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetEndPosValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEndPosAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSourceTextModuleInfoEntry::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> export_name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("export_name", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", GetExportNameAddress(), 1, 8, std::move(export_name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> local_name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("local_name", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", GetLocalNameAddress(), 1, 8, std::move(local_name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> import_name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("import_name", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", GetImportNameAddress(), 1, 8, std::move(import_name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> module_request_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("module_request", "v8::internal::Object", "v8::internal::Object", GetModuleRequestAddress(), 1, 8, std::move(module_request_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> cell_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("cell_index", "v8::internal::Object", "v8::internal::Object", GetCellIndexAddress(), 1, 8, std::move(cell_index_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> beg_pos_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("beg_pos", "v8::internal::Object", "v8::internal::Object", GetBegPosAddress(), 1, 8, std::move(beg_pos_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> end_pos_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("end_pos", "v8::internal::Object", "v8::internal::Object", GetEndPosAddress(), 1, 8, std::move(end_pos_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqConsString::GetName() const {
  return "v8::internal::ConsString";
}

void TqConsString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitConsString(this);
}

bool TqConsString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqConsString*>(other) != nullptr;
}

uintptr_t TqConsString::GetFirstAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqConsString::GetFirstValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFirstAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqConsString::GetSecondAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqConsString::GetSecondValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSecondAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqConsString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> first_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("first", "v8::internal::String", "v8::internal::String", GetFirstAddress(), 1, 8, std::move(first_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> second_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("second", "v8::internal::String", "v8::internal::String", GetSecondAddress(), 1, 8, std::move(second_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqExternalString::GetName() const {
  return "v8::internal::ExternalString";
}

void TqExternalString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitExternalString(this);
}

bool TqExternalString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqExternalString*>(other) != nullptr;
}

uintptr_t TqExternalString::GetResourceAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqExternalString::GetResourceValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetResourceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqExternalString::GetResourceDataAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqExternalString::GetResourceDataValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetResourceDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqExternalString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> resource_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("resource", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetResourceAddress(), 1, 8, std::move(resource_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> resource_data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("resource_data", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetResourceDataAddress(), 1, 8, std::move(resource_data_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqExternalOneByteString::GetName() const {
  return "v8::internal::ExternalOneByteString";
}

void TqExternalOneByteString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitExternalOneByteString(this);
}

bool TqExternalOneByteString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqExternalOneByteString*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqExternalOneByteString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqExternalString::GetProperties(accessor);
  return result;
}

const char* TqExternalTwoByteString::GetName() const {
  return "v8::internal::ExternalTwoByteString";
}

void TqExternalTwoByteString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitExternalTwoByteString(this);
}

bool TqExternalTwoByteString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqExternalTwoByteString*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqExternalTwoByteString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqExternalString::GetProperties(accessor);
  return result;
}

const char* TqInternalizedString::GetName() const {
  return "v8::internal::InternalizedString";
}

void TqInternalizedString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitInternalizedString(this);
}

bool TqInternalizedString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqInternalizedString*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqInternalizedString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  return result;
}

const char* TqSeqString::GetName() const {
  return "v8::internal::SeqString";
}

void TqSeqString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSeqString(this);
}

bool TqSeqString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSeqString*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqSeqString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  return result;
}

const char* TqSeqOneByteString::GetName() const {
  return "v8::internal::SeqOneByteString";
}

void TqSeqOneByteString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSeqOneByteString(this);
}

bool TqSeqOneByteString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSeqOneByteString*>(other) != nullptr;
}

uintptr_t TqSeqOneByteString::GetCharsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<char /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSeqOneByteString::GetCharsValue(d::MemoryAccessor accessor, size_t offset) const {
  char /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetCharsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSeqOneByteString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqSeqString::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> chars_struct_field_list;
  auto indexed_field_slice_chars = TqDebugFieldSliceSeqOneByteStringChars(accessor, address_);
  if (indexed_field_slice_chars.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("chars", CheckTypeName<char /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("char"), CheckTypeName<char /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("char"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_chars.value), std::get<2>(indexed_field_slice_chars.value), 1, std::move(chars_struct_field_list), GetArrayKind(indexed_field_slice_chars.validity)));
  }
  return result;
}

const char* TqSeqTwoByteString::GetName() const {
  return "v8::internal::SeqTwoByteString";
}

void TqSeqTwoByteString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSeqTwoByteString(this);
}

bool TqSeqTwoByteString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSeqTwoByteString*>(other) != nullptr;
}

uintptr_t TqSeqTwoByteString::GetCharsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<char16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSeqTwoByteString::GetCharsValue(d::MemoryAccessor accessor, size_t offset) const {
  char16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetCharsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSeqTwoByteString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqSeqString::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> chars_struct_field_list;
  auto indexed_field_slice_chars = TqDebugFieldSliceSeqTwoByteStringChars(accessor, address_);
  if (indexed_field_slice_chars.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("chars", CheckTypeName<char16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("char16_t"), CheckTypeName<char16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("char16_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_chars.value), std::get<2>(indexed_field_slice_chars.value), 2, std::move(chars_struct_field_list), GetArrayKind(indexed_field_slice_chars.validity)));
  }
  return result;
}

const char* TqSlicedString::GetName() const {
  return "v8::internal::SlicedString";
}

void TqSlicedString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSlicedString(this);
}

bool TqSlicedString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSlicedString*>(other) != nullptr;
}

uintptr_t TqSlicedString::GetParentAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSlicedString::GetParentValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParentAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSlicedString::GetOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqSlicedString::GetOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSlicedString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> parent_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("parent", "v8::internal::String", "v8::internal::String", GetParentAddress(), 1, 8, std::move(parent_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> offset_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("offset", "v8::internal::Object", "v8::internal::Object", GetOffsetAddress(), 1, 8, std::move(offset_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqThinString::GetName() const {
  return "v8::internal::ThinString";
}

void TqThinString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitThinString(this);
}

bool TqThinString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqThinString*>(other) != nullptr;
}

uintptr_t TqThinString::GetActualAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqThinString::GetActualValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetActualAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqThinString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> actual_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("actual", "v8::internal::String", "v8::internal::String", GetActualAddress(), 1, 8, std::move(actual_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTuple2::GetName() const {
  return "v8::internal::Tuple2";
}

void TqTuple2::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTuple2(this);
}

bool TqTuple2::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTuple2*>(other) != nullptr;
}

uintptr_t TqTuple2::GetValue1Address() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqTuple2::GetValue1Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValue1Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTuple2::GetValue2Address() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqTuple2::GetValue2Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValue2Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTuple2::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> value1_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value1", "v8::internal::Object", "v8::internal::Object", GetValue1Address(), 1, 8, std::move(value1_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> value2_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value2", "v8::internal::Object", "v8::internal::Object", GetValue2Address(), 1, 8, std::move(value2_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqSwissNameDictionary::GetName() const {
  return "v8::internal::SwissNameDictionary";
}

void TqSwissNameDictionary::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSwissNameDictionary(this);
}

bool TqSwissNameDictionary::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSwissNameDictionary*>(other) != nullptr;
}

uintptr_t TqSwissNameDictionary::GetHashAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSwissNameDictionary::GetHashValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetHashAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSwissNameDictionary::GetCapacityAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqSwissNameDictionary::GetCapacityValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetCapacityAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSwissNameDictionary::GetMetaTableAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSwissNameDictionary::GetMetaTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMetaTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSwissNameDictionary::GetDataTableAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqSwissNameDictionary::GetDataTableValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataTableAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSwissNameDictionary::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> hash_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("hash", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetHashAddress(), 1, 4, std::move(hash_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> capacity_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("capacity", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetCapacityAddress(), 1, 4, std::move(capacity_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> meta_table_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("meta_table", "v8::internal::ByteArray", "v8::internal::ByteArray", GetMetaTableAddress(), 1, 8, std::move(meta_table_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> data_table_struct_field_list;
  auto indexed_field_slice_data_table = TqDebugFieldSliceSwissNameDictionaryDataTable(accessor, address_);
  if (indexed_field_slice_data_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("data_table", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_data_table.value), std::get<2>(indexed_field_slice_data_table.value), 8, std::move(data_table_struct_field_list), GetArrayKind(indexed_field_slice_data_table.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> ctrl_table_struct_field_list;
  auto indexed_field_slice_ctrl_table = TqDebugFieldSliceSwissNameDictionaryCtrlTable(accessor, address_);
  if (indexed_field_slice_ctrl_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("ctrl_table", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_ctrl_table.value), std::get<2>(indexed_field_slice_ctrl_table.value), 1, std::move(ctrl_table_struct_field_list), GetArrayKind(indexed_field_slice_ctrl_table.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> property_details_table_struct_field_list;
  auto indexed_field_slice_property_details_table = TqDebugFieldSliceSwissNameDictionaryPropertyDetailsTable(accessor, address_);
  if (indexed_field_slice_property_details_table.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("property_details_table", CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), CheckTypeName<uint8_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint8_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_property_details_table.value), std::get<2>(indexed_field_slice_property_details_table.value), 1, std::move(property_details_table_struct_field_list), GetArrayKind(indexed_field_slice_property_details_table.validity)));
  }
  return result;
}

const char* TqSyntheticModule::GetName() const {
  return "v8::internal::SyntheticModule";
}

void TqSyntheticModule::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSyntheticModule(this);
}

bool TqSyntheticModule::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSyntheticModule*>(other) != nullptr;
}

uintptr_t TqSyntheticModule::GetNameAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqSyntheticModule::GetNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSyntheticModule::GetExportNamesAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqSyntheticModule::GetExportNamesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExportNamesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSyntheticModule::GetEvaluationStepsAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqSyntheticModule::GetEvaluationStepsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEvaluationStepsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSyntheticModule::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqModule::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("name", "v8::internal::String", "v8::internal::String", GetNameAddress(), 1, 8, std::move(name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> export_names_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("export_names", "v8::internal::FixedArray", "v8::internal::FixedArray", GetExportNamesAddress(), 1, 8, std::move(export_names_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> evaluation_steps_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("evaluation_steps", "v8::internal::Foreign", "v8::internal::Foreign", GetEvaluationStepsAddress(), 1, 8, std::move(evaluation_steps_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTemplateObjectDescription::GetName() const {
  return "v8::internal::TemplateObjectDescription";
}

void TqTemplateObjectDescription::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTemplateObjectDescription(this);
}

bool TqTemplateObjectDescription::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTemplateObjectDescription*>(other) != nullptr;
}

uintptr_t TqTemplateObjectDescription::GetRawStringsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqTemplateObjectDescription::GetRawStringsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRawStringsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateObjectDescription::GetCookedStringsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqTemplateObjectDescription::GetCookedStringsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCookedStringsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTemplateObjectDescription::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> raw_strings_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw_strings", "v8::internal::FixedArray", "v8::internal::FixedArray", GetRawStringsAddress(), 1, 8, std::move(raw_strings_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> cooked_strings_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("cooked_strings", "v8::internal::FixedArray", "v8::internal::FixedArray", GetCookedStringsAddress(), 1, 8, std::move(cooked_strings_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTemplateInfo::GetName() const {
  return "v8::internal::TemplateInfo";
}

void TqTemplateInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTemplateInfo(this);
}

bool TqTemplateInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTemplateInfo*>(other) != nullptr;
}

uintptr_t TqTemplateInfo::GetTagAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqTemplateInfo::GetTagValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTagAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateInfo::GetSerialNumberAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqTemplateInfo::GetSerialNumberValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSerialNumberAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateInfo::GetNumberOfPropertiesAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqTemplateInfo::GetNumberOfPropertiesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfPropertiesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateInfo::GetPropertyListAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqTemplateInfo::GetPropertyListValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPropertyListAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateInfo::GetPropertyAccessorsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqTemplateInfo::GetPropertyAccessorsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPropertyAccessorsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTemplateInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> tag_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("tag", "v8::internal::Object", "v8::internal::Object", GetTagAddress(), 1, 8, std::move(tag_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> serial_number_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("serial_number", "v8::internal::Object", "v8::internal::Object", GetSerialNumberAddress(), 1, 8, std::move(serial_number_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> number_of_properties_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("number_of_properties", "v8::internal::Object", "v8::internal::Object", GetNumberOfPropertiesAddress(), 1, 8, std::move(number_of_properties_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> property_list_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("property_list", "v8::internal::HeapObject", "v8::internal::HeapObject", GetPropertyListAddress(), 1, 8, std::move(property_list_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> property_accessors_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("property_accessors", "v8::internal::HeapObject", "v8::internal::HeapObject", GetPropertyAccessorsAddress(), 1, 8, std::move(property_accessors_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqFunctionTemplateRareData::GetName() const {
  return "v8::internal::FunctionTemplateRareData";
}

void TqFunctionTemplateRareData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFunctionTemplateRareData(this);
}

bool TqFunctionTemplateRareData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFunctionTemplateRareData*>(other) != nullptr;
}

uintptr_t TqFunctionTemplateRareData::GetPrototypeTemplateAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetPrototypeTemplateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeTemplateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetPrototypeProviderTemplateAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetPrototypeProviderTemplateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeProviderTemplateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetParentTemplateAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetParentTemplateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParentTemplateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetNamedPropertyHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetNamedPropertyHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNamedPropertyHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetIndexedPropertyHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetIndexedPropertyHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexedPropertyHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetInstanceTemplateAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetInstanceTemplateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceTemplateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetInstanceCallHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetInstanceCallHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceCallHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetAccessCheckInfoAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetAccessCheckInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAccessCheckInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetCFunctionOverloadsAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetCFunctionOverloadsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCFunctionOverloadsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFunctionTemplateRareData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> prototype_template_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("prototype_template", "v8::internal::HeapObject", "v8::internal::HeapObject", GetPrototypeTemplateAddress(), 1, 8, std::move(prototype_template_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> prototype_provider_template_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("prototype_provider_template", "v8::internal::HeapObject", "v8::internal::HeapObject", GetPrototypeProviderTemplateAddress(), 1, 8, std::move(prototype_provider_template_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> parent_template_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("parent_template", "v8::internal::HeapObject", "v8::internal::HeapObject", GetParentTemplateAddress(), 1, 8, std::move(parent_template_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> named_property_handler_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("named_property_handler", "v8::internal::HeapObject", "v8::internal::HeapObject", GetNamedPropertyHandlerAddress(), 1, 8, std::move(named_property_handler_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> indexed_property_handler_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("indexed_property_handler", "v8::internal::HeapObject", "v8::internal::HeapObject", GetIndexedPropertyHandlerAddress(), 1, 8, std::move(indexed_property_handler_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> instance_template_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance_template", "v8::internal::HeapObject", "v8::internal::HeapObject", GetInstanceTemplateAddress(), 1, 8, std::move(instance_template_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> instance_call_handler_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance_call_handler", "v8::internal::HeapObject", "v8::internal::HeapObject", GetInstanceCallHandlerAddress(), 1, 8, std::move(instance_call_handler_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> access_check_info_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("access_check_info", "v8::internal::HeapObject", "v8::internal::HeapObject", GetAccessCheckInfoAddress(), 1, 8, std::move(access_check_info_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> c_function_overloads_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("c_function_overloads", "v8::internal::FixedArray", "v8::internal::FixedArray", GetCFunctionOverloadsAddress(), 1, 8, std::move(c_function_overloads_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqFunctionTemplateInfo::GetName() const {
  return "v8::internal::FunctionTemplateInfo";
}

void TqFunctionTemplateInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFunctionTemplateInfo(this);
}

bool TqFunctionTemplateInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFunctionTemplateInfo*>(other) != nullptr;
}

uintptr_t TqFunctionTemplateInfo::GetCallCodeAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetCallCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetClassNameAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetClassNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetClassNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetSignatureAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetSignatureValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSignatureAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetRareDataAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetRareDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRareDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetSharedFunctionInfoAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetSharedFunctionInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedFunctionInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetFlagAddress() const {
  return address_ - i::kHeapObjectTag + 88;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetFlagValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 96;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetCachedPropertyNameAddress() const {
  return address_ - i::kHeapObjectTag + 104;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetCachedPropertyNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCachedPropertyNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetInstanceTypeAddress() const {
  return address_ - i::kHeapObjectTag + 112;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetInstanceTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFunctionTemplateInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTemplateInfo::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> call_code_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("call_code", "v8::internal::HeapObject", "v8::internal::HeapObject", GetCallCodeAddress(), 1, 8, std::move(call_code_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> class_name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("class_name", "v8::internal::PrimitiveHeapObject", "v8::internal::PrimitiveHeapObject", GetClassNameAddress(), 1, 8, std::move(class_name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> signature_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("signature", "v8::internal::HeapObject", "v8::internal::HeapObject", GetSignatureAddress(), 1, 8, std::move(signature_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> rare_data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("rare_data", "v8::internal::HeapObject", "v8::internal::HeapObject", GetRareDataAddress(), 1, 8, std::move(rare_data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> shared_function_info_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("shared_function_info", "v8::internal::HeapObject", "v8::internal::HeapObject", GetSharedFunctionInfoAddress(), 1, 8, std::move(shared_function_info_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flag_struct_field_list;
  flag_struct_field_list.push_back(std::make_unique<StructProperty>("undetectable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  flag_struct_field_list.push_back(std::make_unique<StructProperty>("needs_access_check", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 33));
  flag_struct_field_list.push_back(std::make_unique<StructProperty>("read_only_prototype", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 34));
  flag_struct_field_list.push_back(std::make_unique<StructProperty>("remove_prototype", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 35));
  flag_struct_field_list.push_back(std::make_unique<StructProperty>("accept_any_receiver", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 36));
  flag_struct_field_list.push_back(std::make_unique<StructProperty>("published", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 37));
  flag_struct_field_list.push_back(std::make_unique<StructProperty>("allowed_receiver_instance_type_range_start", CheckTypeName<int16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int16_t"), CheckTypeName<int16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int16_t"), 0, 12, 38));
  flag_struct_field_list.push_back(std::make_unique<StructProperty>("allowed_receiver_instance_type_range_end", CheckTypeName<int16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int16_t"), CheckTypeName<int16_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int16_t"), 0, 12, 50));
  result.push_back(std::make_unique<ObjectProperty>("flag", "v8::internal::Object", "v8::internal::Object", GetFlagAddress(), 1, 8, std::move(flag_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::Object", "v8::internal::Object", GetLengthAddress(), 1, 8, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> cached_property_name_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("cached_property_name", "v8::internal::Object", "v8::internal::Object", GetCachedPropertyNameAddress(), 1, 8, std::move(cached_property_name_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> instance_type_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance_type", "v8::internal::Object", "v8::internal::Object", GetInstanceTypeAddress(), 1, 8, std::move(instance_type_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqObjectTemplateInfo::GetName() const {
  return "v8::internal::ObjectTemplateInfo";
}

void TqObjectTemplateInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitObjectTemplateInfo(this);
}

bool TqObjectTemplateInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqObjectTemplateInfo*>(other) != nullptr;
}

uintptr_t TqObjectTemplateInfo::GetConstructorAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqObjectTemplateInfo::GetConstructorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetConstructorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqObjectTemplateInfo::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqObjectTemplateInfo::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqObjectTemplateInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTemplateInfo::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> constructor_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("constructor", "v8::internal::HeapObject", "v8::internal::HeapObject", GetConstructorAddress(), 1, 8, std::move(constructor_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> data_struct_field_list;
  data_struct_field_list.push_back(std::make_unique<StructProperty>("is_immutable_prototype", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 32));
  data_struct_field_list.push_back(std::make_unique<StructProperty>("is_code_kind", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 33));
  data_struct_field_list.push_back(std::make_unique<StructProperty>("embedder_field_count", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 28, 34));
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::Object", "v8::internal::Object", GetDataAddress(), 1, 8, std::move(data_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTurbofanType::GetName() const {
  return "v8::internal::TurbofanType";
}

void TqTurbofanType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurbofanType(this);
}

bool TqTurbofanType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurbofanType*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurbofanType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  return result;
}

const char* TqTurbofanBitsetType::GetName() const {
  return "v8::internal::TurbofanBitsetType";
}

void TqTurbofanBitsetType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurbofanBitsetType(this);
}

bool TqTurbofanBitsetType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurbofanBitsetType*>(other) != nullptr;
}

uintptr_t TqTurbofanBitsetType::GetBitsetLowAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurbofanBitsetType::GetBitsetLowValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetBitsetLowAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurbofanBitsetType::GetBitsetHighAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurbofanBitsetType::GetBitsetHighValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetBitsetHighAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurbofanBitsetType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurbofanType::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> bitset_low_struct_field_list;
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("_unused_padding_field_1", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 0));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_unsigned31", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 1));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_unsigned32", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 2));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_signed32", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 3));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_number", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 4));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_string", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 5));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("negative31", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 6));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("null", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 7));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("undefined", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 8));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("boolean", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 9));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("unsigned30", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 10));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("minus_zero", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 11));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("naN", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 12));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("symbol", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 13));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("internalized_string", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 14));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_callable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 15));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_object", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 16));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_undetectable", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 17));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("callable_proxy", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 18));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_proxy", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 19));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("callable_function", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 20));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("class_constructor", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 21));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("bound_function", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 22));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_internal", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 23));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("external_pointer", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 24));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("array", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 25));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("unsigned_big_int_63", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 26));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_unsigned_big_int_64", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 27));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("negative_big_int_63", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 28));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("other_big_int", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 29));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("wasm_object", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 30));
  bitset_low_struct_field_list.push_back(std::make_unique<StructProperty>("sandboxed_pointer", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 31));
  result.push_back(std::make_unique<ObjectProperty>("bitset_low", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetBitsetLowAddress(), 1, 4, std::move(bitset_low_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bitset_high_struct_field_list;
  bitset_high_struct_field_list.push_back(std::make_unique<StructProperty>("machine", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 0));
  bitset_high_struct_field_list.push_back(std::make_unique<StructProperty>("the_hole", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 1));
  bitset_high_struct_field_list.push_back(std::make_unique<StructProperty>("property_cell_hole", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 2));
  result.push_back(std::make_unique<ObjectProperty>("bitset_high", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetBitsetHighAddress(), 1, 4, std::move(bitset_high_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTurbofanUnionType::GetName() const {
  return "v8::internal::TurbofanUnionType";
}

void TqTurbofanUnionType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurbofanUnionType(this);
}

bool TqTurbofanUnionType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurbofanUnionType*>(other) != nullptr;
}

uintptr_t TqTurbofanUnionType::GetType1Address() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqTurbofanUnionType::GetType1Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetType1Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTurbofanUnionType::GetType2Address() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqTurbofanUnionType::GetType2Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetType2Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurbofanUnionType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurbofanType::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> type1_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("type1", "v8::internal::TurbofanType", "v8::internal::TurbofanType", GetType1Address(), 1, 8, std::move(type1_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> type2_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("type2", "v8::internal::TurbofanType", "v8::internal::TurbofanType", GetType2Address(), 1, 8, std::move(type2_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTurbofanRangeType::GetName() const {
  return "v8::internal::TurbofanRangeType";
}

void TqTurbofanRangeType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurbofanRangeType(this);
}

bool TqTurbofanRangeType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurbofanRangeType*>(other) != nullptr;
}

uintptr_t TqTurbofanRangeType::GetMinAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurbofanRangeType::GetMinValue(d::MemoryAccessor accessor) const {
  double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetMinAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurbofanRangeType::GetMaxAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurbofanRangeType::GetMaxValue(d::MemoryAccessor accessor) const {
  double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetMaxAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurbofanRangeType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurbofanType::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> min_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("min", CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), GetMinAddress(), 1, 8, std::move(min_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> max_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("max", CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), GetMaxAddress(), 1, 8, std::move(max_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTurbofanHeapConstantType::GetName() const {
  return "v8::internal::TurbofanHeapConstantType";
}

void TqTurbofanHeapConstantType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurbofanHeapConstantType(this);
}

bool TqTurbofanHeapConstantType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurbofanHeapConstantType*>(other) != nullptr;
}

uintptr_t TqTurbofanHeapConstantType::GetConstantAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqTurbofanHeapConstantType::GetConstantValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetConstantAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurbofanHeapConstantType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurbofanType::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> constant_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("constant", "v8::internal::HeapObject", "v8::internal::HeapObject", GetConstantAddress(), 1, 8, std::move(constant_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTurbofanOtherNumberConstantType::GetName() const {
  return "v8::internal::TurbofanOtherNumberConstantType";
}

void TqTurbofanOtherNumberConstantType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurbofanOtherNumberConstantType(this);
}

bool TqTurbofanOtherNumberConstantType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurbofanOtherNumberConstantType*>(other) != nullptr;
}

uintptr_t TqTurbofanOtherNumberConstantType::GetConstantAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurbofanOtherNumberConstantType::GetConstantValue(d::MemoryAccessor accessor) const {
  double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetConstantAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurbofanOtherNumberConstantType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurbofanType::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> constant_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("constant", CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), GetConstantAddress(), 1, 8, std::move(constant_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTurboshaftType::GetName() const {
  return "v8::internal::TurboshaftType";
}

void TqTurboshaftType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurboshaftType(this);
}

bool TqTurboshaftType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurboshaftType*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurboshaftType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  return result;
}

const char* TqTurboshaftWord32Type::GetName() const {
  return "v8::internal::TurboshaftWord32Type";
}

void TqTurboshaftWord32Type::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurboshaftWord32Type(this);
}

bool TqTurboshaftWord32Type::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurboshaftWord32Type*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurboshaftWord32Type::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurboshaftType::GetProperties(accessor);
  return result;
}

const char* TqTurboshaftWord32RangeType::GetName() const {
  return "v8::internal::TurboshaftWord32RangeType";
}

void TqTurboshaftWord32RangeType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurboshaftWord32RangeType(this);
}

bool TqTurboshaftWord32RangeType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurboshaftWord32RangeType*>(other) != nullptr;
}

uintptr_t TqTurboshaftWord32RangeType::GetFromAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftWord32RangeType::GetFromValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFromAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurboshaftWord32RangeType::GetToAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftWord32RangeType::GetToValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetToAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurboshaftWord32RangeType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurboshaftWord32Type::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> from_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("from", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetFromAddress(), 1, 4, std::move(from_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> to_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("to", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetToAddress(), 1, 4, std::move(to_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTurboshaftWord32SetType::GetName() const {
  return "v8::internal::TurboshaftWord32SetType";
}

void TqTurboshaftWord32SetType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurboshaftWord32SetType(this);
}

bool TqTurboshaftWord32SetType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurboshaftWord32SetType*>(other) != nullptr;
}

uintptr_t TqTurboshaftWord32SetType::GetSetSizeAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftWord32SetType::GetSetSizeValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetSetSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurboshaftWord32SetType::GetElementsAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftWord32SetType::GetElementsValue(d::MemoryAccessor accessor, size_t offset) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetElementsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurboshaftWord32SetType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurboshaftWord32Type::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> set_size_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("set_size", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetSetSizeAddress(), 1, 4, std::move(set_size_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> elements_struct_field_list;
  auto indexed_field_slice_elements = TqDebugFieldSliceTurboshaftWord32SetTypeElements(accessor, address_);
  if (indexed_field_slice_elements.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("elements", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_elements.value), std::get<2>(indexed_field_slice_elements.value), 4, std::move(elements_struct_field_list), GetArrayKind(indexed_field_slice_elements.validity)));
  }
  return result;
}

const char* TqTurboshaftWord64Type::GetName() const {
  return "v8::internal::TurboshaftWord64Type";
}

void TqTurboshaftWord64Type::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurboshaftWord64Type(this);
}

bool TqTurboshaftWord64Type::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurboshaftWord64Type*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurboshaftWord64Type::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurboshaftType::GetProperties(accessor);
  return result;
}

const char* TqTurboshaftWord64RangeType::GetName() const {
  return "v8::internal::TurboshaftWord64RangeType";
}

void TqTurboshaftWord64RangeType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurboshaftWord64RangeType(this);
}

bool TqTurboshaftWord64RangeType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurboshaftWord64RangeType*>(other) != nullptr;
}

uintptr_t TqTurboshaftWord64RangeType::GetFromHighAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftWord64RangeType::GetFromHighValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFromHighAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurboshaftWord64RangeType::GetFromLowAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftWord64RangeType::GetFromLowValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetFromLowAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurboshaftWord64RangeType::GetToHighAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftWord64RangeType::GetToHighValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetToHighAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurboshaftWord64RangeType::GetToLowAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftWord64RangeType::GetToLowValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetToLowAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurboshaftWord64RangeType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurboshaftWord64Type::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> from_high_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("from_high", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetFromHighAddress(), 1, 4, std::move(from_high_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> from_low_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("from_low", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetFromLowAddress(), 1, 4, std::move(from_low_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> to_high_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("to_high", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetToHighAddress(), 1, 4, std::move(to_high_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> to_low_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("to_low", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetToLowAddress(), 1, 4, std::move(to_low_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTurboshaftWord64SetType::GetName() const {
  return "v8::internal::TurboshaftWord64SetType";
}

void TqTurboshaftWord64SetType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurboshaftWord64SetType(this);
}

bool TqTurboshaftWord64SetType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurboshaftWord64SetType*>(other) != nullptr;
}

uintptr_t TqTurboshaftWord64SetType::GetSetSizeAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftWord64SetType::GetSetSizeValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetSetSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurboshaftWord64SetType::GetElementsHighAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftWord64SetType::GetElementsHighValue(d::MemoryAccessor accessor, size_t offset) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetElementsHighAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurboshaftWord64SetType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurboshaftWord64Type::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> set_size_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("set_size", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetSetSizeAddress(), 1, 4, std::move(set_size_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> elements_high_struct_field_list;
  auto indexed_field_slice_elements_high = TqDebugFieldSliceTurboshaftWord64SetTypeElementsHigh(accessor, address_);
  if (indexed_field_slice_elements_high.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("elements_high", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_elements_high.value), std::get<2>(indexed_field_slice_elements_high.value), 4, std::move(elements_high_struct_field_list), GetArrayKind(indexed_field_slice_elements_high.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> elements_low_struct_field_list;
  auto indexed_field_slice_elements_low = TqDebugFieldSliceTurboshaftWord64SetTypeElementsLow(accessor, address_);
  if (indexed_field_slice_elements_low.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("elements_low", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_elements_low.value), std::get<2>(indexed_field_slice_elements_low.value), 4, std::move(elements_low_struct_field_list), GetArrayKind(indexed_field_slice_elements_low.validity)));
  }
  return result;
}

const char* TqTurboshaftFloat64Type::GetName() const {
  return "v8::internal::TurboshaftFloat64Type";
}

void TqTurboshaftFloat64Type::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurboshaftFloat64Type(this);
}

bool TqTurboshaftFloat64Type::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurboshaftFloat64Type*>(other) != nullptr;
}

uintptr_t TqTurboshaftFloat64Type::GetSpecialValuesAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftFloat64Type::GetSpecialValuesValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetSpecialValuesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurboshaftFloat64Type::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurboshaftType::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> special_values_struct_field_list;
  special_values_struct_field_list.push_back(std::make_unique<StructProperty>("nan", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 0));
  special_values_struct_field_list.push_back(std::make_unique<StructProperty>("minus_zero", CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), CheckTypeName<bool /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("bool"), 0, 1, 1));
  special_values_struct_field_list.push_back(std::make_unique<StructProperty>("_unused", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), 0, 30, 2));
  result.push_back(std::make_unique<ObjectProperty>("special_values", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetSpecialValuesAddress(), 1, 4, std::move(special_values_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTurboshaftFloat64RangeType::GetName() const {
  return "v8::internal::TurboshaftFloat64RangeType";
}

void TqTurboshaftFloat64RangeType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurboshaftFloat64RangeType(this);
}

bool TqTurboshaftFloat64RangeType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurboshaftFloat64RangeType*>(other) != nullptr;
}

uintptr_t TqTurboshaftFloat64RangeType::GetPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftFloat64RangeType::GetPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurboshaftFloat64RangeType::GetMinAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftFloat64RangeType::GetMinValue(d::MemoryAccessor accessor) const {
  double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetMinAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurboshaftFloat64RangeType::GetMaxAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftFloat64RangeType::GetMaxValue(d::MemoryAccessor accessor) const {
  double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetMaxAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurboshaftFloat64RangeType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurboshaftFloat64Type::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> _padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetPaddingAddress(), 1, 4, std::move(_padding_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> min_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("min", CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), GetMinAddress(), 1, 8, std::move(min_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> max_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("max", CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), GetMaxAddress(), 1, 8, std::move(max_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqTurboshaftFloat64SetType::GetName() const {
  return "v8::internal::TurboshaftFloat64SetType";
}

void TqTurboshaftFloat64SetType::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTurboshaftFloat64SetType(this);
}

bool TqTurboshaftFloat64SetType::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTurboshaftFloat64SetType*>(other) != nullptr;
}

uintptr_t TqTurboshaftFloat64SetType::GetSetSizeAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftFloat64SetType::GetSetSizeValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetSetSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqTurboshaftFloat64SetType::GetElementsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqTurboshaftFloat64SetType::GetElementsValue(d::MemoryAccessor accessor, size_t offset) const {
  double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetElementsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTurboshaftFloat64SetType::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTurboshaftFloat64Type::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> set_size_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("set_size", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetSetSizeAddress(), 1, 4, std::move(set_size_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> elements_struct_field_list;
  auto indexed_field_slice_elements = TqDebugFieldSliceTurboshaftFloat64SetTypeElements(accessor, address_);
  if (indexed_field_slice_elements.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("elements", CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), CheckTypeName<double /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("double"), address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_elements.value), std::get<2>(indexed_field_slice_elements.value), 8, std::move(elements_struct_field_list), GetArrayKind(indexed_field_slice_elements.validity)));
  }
  return result;
}

const char* TqInternalClass::GetName() const {
  return "v8::internal::InternalClass";
}

void TqInternalClass::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitInternalClass(this);
}

bool TqInternalClass::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqInternalClass*>(other) != nullptr;
}

uintptr_t TqInternalClass::GetAAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqInternalClass::GetAValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInternalClass::GetBAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqInternalClass::GetBValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqInternalClass::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> a_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("a", "v8::internal::Object", "v8::internal::Object", GetAAddress(), 1, 8, std::move(a_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> b_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("b", "v8::internal::Object", "v8::internal::Object", GetBAddress(), 1, 8, std::move(b_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqSmiPair::GetName() const {
  return "v8::internal::SmiPair";
}

void TqSmiPair::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSmiPair(this);
}

bool TqSmiPair::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSmiPair*>(other) != nullptr;
}

uintptr_t TqSmiPair::GetAAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSmiPair::GetAValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSmiPair::GetBAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSmiPair::GetBValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSmiPair::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> a_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("a", "v8::internal::Object", "v8::internal::Object", GetAAddress(), 1, 8, std::move(a_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> b_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("b", "v8::internal::Object", "v8::internal::Object", GetBAddress(), 1, 8, std::move(b_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqSmiBox::GetName() const {
  return "v8::internal::SmiBox";
}

void TqSmiBox::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSmiBox(this);
}

bool TqSmiBox::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSmiBox*>(other) != nullptr;
}

uintptr_t TqSmiBox::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSmiBox::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSmiBox::GetUnrelatedAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSmiBox::GetUnrelatedValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUnrelatedAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSmiBox::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> value_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::Object", "v8::internal::Object", GetValueAddress(), 1, 8, std::move(value_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> unrelated_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("unrelated", "v8::internal::Object", "v8::internal::Object", GetUnrelatedAddress(), 1, 8, std::move(unrelated_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqExportedSubClassBase::GetName() const {
  return "v8::internal::ExportedSubClassBase";
}

void TqExportedSubClassBase::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitExportedSubClassBase(this);
}

bool TqExportedSubClassBase::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqExportedSubClassBase*>(other) != nullptr;
}

uintptr_t TqExportedSubClassBase::GetAAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqExportedSubClassBase::GetAValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqExportedSubClassBase::GetBAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqExportedSubClassBase::GetBValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqExportedSubClassBase::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> a_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("a", "v8::internal::HeapObject", "v8::internal::HeapObject", GetAAddress(), 1, 8, std::move(a_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> b_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("b", "v8::internal::HeapObject", "v8::internal::HeapObject", GetBAddress(), 1, 8, std::move(b_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqExportedSubClass::GetName() const {
  return "v8::internal::ExportedSubClass";
}

void TqExportedSubClass::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitExportedSubClass(this);
}

bool TqExportedSubClass::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqExportedSubClass*>(other) != nullptr;
}

uintptr_t TqExportedSubClass::GetCFieldAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqExportedSubClass::GetCFieldValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetCFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqExportedSubClass::GetDFieldAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqExportedSubClass::GetDFieldValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetDFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqExportedSubClass::GetEFieldAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqExportedSubClass::GetEFieldValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqExportedSubClass::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqExportedSubClassBase::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> c_field_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("c_field", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetCFieldAddress(), 1, 4, std::move(c_field_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> d_field_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("d_field", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetDFieldAddress(), 1, 4, std::move(d_field_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> e_field_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("e_field", "v8::internal::Object", "v8::internal::Object", GetEFieldAddress(), 1, 8, std::move(e_field_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqAbstractInternalClass::GetName() const {
  return "v8::internal::AbstractInternalClass";
}

void TqAbstractInternalClass::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAbstractInternalClass(this);
}

bool TqAbstractInternalClass::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAbstractInternalClass*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqAbstractInternalClass::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  return result;
}

const char* TqAbstractInternalClassSubclass1::GetName() const {
  return "v8::internal::AbstractInternalClassSubclass1";
}

void TqAbstractInternalClassSubclass1::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAbstractInternalClassSubclass1(this);
}

bool TqAbstractInternalClassSubclass1::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAbstractInternalClassSubclass1*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqAbstractInternalClassSubclass1::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqAbstractInternalClass::GetProperties(accessor);
  return result;
}

const char* TqAbstractInternalClassSubclass2::GetName() const {
  return "v8::internal::AbstractInternalClassSubclass2";
}

void TqAbstractInternalClassSubclass2::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAbstractInternalClassSubclass2(this);
}

bool TqAbstractInternalClassSubclass2::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAbstractInternalClassSubclass2*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqAbstractInternalClassSubclass2::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqAbstractInternalClass::GetProperties(accessor);
  return result;
}

const char* TqInternalClassWithSmiElements::GetName() const {
  return "v8::internal::InternalClassWithSmiElements";
}

void TqInternalClassWithSmiElements::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitInternalClassWithSmiElements(this);
}

bool TqInternalClassWithSmiElements::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqInternalClassWithSmiElements*>(other) != nullptr;
}

uintptr_t TqInternalClassWithSmiElements::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqInternalClassWithSmiElements::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInternalClassWithSmiElements::GetObjectAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqInternalClassWithSmiElements::GetObjectValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetObjectAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInternalClassWithSmiElements::GetEntriesAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqInternalClassWithSmiElements::GetEntriesValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEntriesAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqInternalClassWithSmiElements::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::Object", "v8::internal::Object", GetDataAddress(), 1, 8, std::move(data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> object_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("object", "v8::internal::Oddball", "v8::internal::Oddball", GetObjectAddress(), 1, 8, std::move(object_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> entries_struct_field_list;
  auto indexed_field_slice_entries = TqDebugFieldSliceInternalClassWithSmiElementsEntries(accessor, address_);
  if (indexed_field_slice_entries.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("entries", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_entries.value), std::get<2>(indexed_field_slice_entries.value), 8, std::move(entries_struct_field_list), GetArrayKind(indexed_field_slice_entries.validity)));
  }
  return result;
}

const char* TqInternalClassWithStructElements::GetName() const {
  return "v8::internal::InternalClassWithStructElements";
}

void TqInternalClassWithStructElements::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitInternalClassWithStructElements(this);
}

bool TqInternalClassWithStructElements::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqInternalClassWithStructElements*>(other) != nullptr;
}

uintptr_t TqInternalClassWithStructElements::GetDummy1Address() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqInternalClassWithStructElements::GetDummy1Value(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetDummy1Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqInternalClassWithStructElements::GetDummy2Address() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqInternalClassWithStructElements::GetDummy2Value(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetDummy2Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqInternalClassWithStructElements::GetCountAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqInternalClassWithStructElements::GetCountValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCountAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInternalClassWithStructElements::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqInternalClassWithStructElements::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInternalClassWithStructElements::GetObjectAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqInternalClassWithStructElements::GetObjectValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetObjectAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInternalClassWithStructElements::GetEntriesAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqInternalClassWithStructElements::GetEntriesValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEntriesAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqInternalClassWithStructElements::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> dummy1_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("dummy1", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetDummy1Address(), 1, 4, std::move(dummy1_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> dummy2_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("dummy2", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetDummy2Address(), 1, 4, std::move(dummy2_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> count_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("count", "v8::internal::Object", "v8::internal::Object", GetCountAddress(), 1, 8, std::move(count_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::Object", "v8::internal::Object", GetDataAddress(), 1, 8, std::move(data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> object_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("object", "v8::internal::Object", "v8::internal::Object", GetObjectAddress(), 1, 8, std::move(object_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> entries_struct_field_list;
  auto indexed_field_slice_entries = TqDebugFieldSliceInternalClassWithStructElementsEntries(accessor, address_);
  if (indexed_field_slice_entries.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("entries", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_entries.value), std::get<2>(indexed_field_slice_entries.value), 8, std::move(entries_struct_field_list), GetArrayKind(indexed_field_slice_entries.validity)));
  }
  std::vector<std::unique_ptr<StructProperty>> more_entries_struct_field_list;
  more_entries_struct_field_list.push_back(std::make_unique<StructProperty>("a", "v8::internal::Object", "v8::internal::Object", 0, 0, 0));
  more_entries_struct_field_list.push_back(std::make_unique<StructProperty>("b", "v8::internal::Object", "v8::internal::Object", 8, 0, 0));
  auto indexed_field_slice_more_entries = TqDebugFieldSliceInternalClassWithStructElementsMoreEntries(accessor, address_);
  if (indexed_field_slice_more_entries.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("more_entries", "", "", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_more_entries.value), std::get<2>(indexed_field_slice_more_entries.value), 16, std::move(more_entries_struct_field_list), GetArrayKind(indexed_field_slice_more_entries.validity)));
  }
  return result;
}

const char* TqExportedSubClass2::GetName() const {
  return "v8::internal::ExportedSubClass2";
}

void TqExportedSubClass2::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitExportedSubClass2(this);
}

bool TqExportedSubClass2::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqExportedSubClass2*>(other) != nullptr;
}

uintptr_t TqExportedSubClass2::GetXFieldAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqExportedSubClass2::GetXFieldValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetXFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqExportedSubClass2::GetYFieldAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqExportedSubClass2::GetYFieldValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetYFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqExportedSubClass2::GetZFieldAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqExportedSubClass2::GetZFieldValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetZFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqExportedSubClass2::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqExportedSubClassBase::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> x_field_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("x_field", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetXFieldAddress(), 1, 4, std::move(x_field_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> y_field_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("y_field", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), GetYFieldAddress(), 1, 4, std::move(y_field_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> z_field_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("z_field", "v8::internal::Object", "v8::internal::Object", GetZFieldAddress(), 1, 8, std::move(z_field_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqSortState::GetName() const {
  return "v8::internal::SortState";
}

void TqSortState::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSortState(this);
}

bool TqSortState::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSortState*>(other) != nullptr;
}

uintptr_t TqSortState::GetReceiverAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSortState::GetReceiverValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetReceiverAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetInitialReceiverMapAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSortState::GetInitialReceiverMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInitialReceiverMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetInitialReceiverLengthAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqSortState::GetInitialReceiverLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInitialReceiverLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetUserCmpFnAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqSortState::GetUserCmpFnValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUserCmpFnAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetSortComparePtrAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqSortState::GetSortComparePtrValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSortComparePtrAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetLoadFnAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqSortState::GetLoadFnValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLoadFnAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetStoreFnAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqSortState::GetStoreFnValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStoreFnAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetDeleteFnAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqSortState::GetDeleteFnValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDeleteFnAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetCanUseSameAccessorFnAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqSortState::GetCanUseSameAccessorFnValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCanUseSameAccessorFnAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetMinGallopAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqSortState::GetMinGallopValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMinGallopAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetPendingRunsSizeAddress() const {
  return address_ - i::kHeapObjectTag + 88;
}

Value<uintptr_t> TqSortState::GetPendingRunsSizeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPendingRunsSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetPendingRunsAddress() const {
  return address_ - i::kHeapObjectTag + 96;
}

Value<uintptr_t> TqSortState::GetPendingRunsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPendingRunsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetWorkArrayAddress() const {
  return address_ - i::kHeapObjectTag + 104;
}

Value<uintptr_t> TqSortState::GetWorkArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWorkArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetTempArrayAddress() const {
  return address_ - i::kHeapObjectTag + 112;
}

Value<uintptr_t> TqSortState::GetTempArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTempArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetSortLengthAddress() const {
  return address_ - i::kHeapObjectTag + 120;
}

Value<uintptr_t> TqSortState::GetSortLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSortLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetNumberOfUndefinedAddress() const {
  return address_ - i::kHeapObjectTag + 128;
}

Value<uintptr_t> TqSortState::GetNumberOfUndefinedValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfUndefinedAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSortState::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> receiver_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("receiver", "v8::internal::JSReceiver", "v8::internal::JSReceiver", GetReceiverAddress(), 1, 8, std::move(receiver_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> initialReceiverMap_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("initialReceiverMap", "v8::internal::Map", "v8::internal::Map", GetInitialReceiverMapAddress(), 1, 8, std::move(initialReceiverMap_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> initialReceiverLength_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("initialReceiverLength", "v8::internal::Object", "v8::internal::Object", GetInitialReceiverLengthAddress(), 1, 8, std::move(initialReceiverLength_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> userCmpFn_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("userCmpFn", "v8::internal::HeapObject", "v8::internal::HeapObject", GetUserCmpFnAddress(), 1, 8, std::move(userCmpFn_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> sortComparePtr_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("sortComparePtr", "v8::internal::Object", "v8::internal::Object", GetSortComparePtrAddress(), 1, 8, std::move(sortComparePtr_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> loadFn_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("loadFn", "v8::internal::Object", "v8::internal::Object", GetLoadFnAddress(), 1, 8, std::move(loadFn_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> storeFn_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("storeFn", "v8::internal::Object", "v8::internal::Object", GetStoreFnAddress(), 1, 8, std::move(storeFn_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> deleteFn_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("deleteFn", "v8::internal::Object", "v8::internal::Object", GetDeleteFnAddress(), 1, 8, std::move(deleteFn_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> canUseSameAccessorFn_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("canUseSameAccessorFn", "v8::internal::Object", "v8::internal::Object", GetCanUseSameAccessorFnAddress(), 1, 8, std::move(canUseSameAccessorFn_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> minGallop_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("minGallop", "v8::internal::Object", "v8::internal::Object", GetMinGallopAddress(), 1, 8, std::move(minGallop_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> pendingRunsSize_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("pendingRunsSize", "v8::internal::Object", "v8::internal::Object", GetPendingRunsSizeAddress(), 1, 8, std::move(pendingRunsSize_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> pendingRuns_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("pendingRuns", "v8::internal::FixedArray", "v8::internal::FixedArray", GetPendingRunsAddress(), 1, 8, std::move(pendingRuns_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> workArray_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("workArray", "v8::internal::FixedArray", "v8::internal::FixedArray", GetWorkArrayAddress(), 1, 8, std::move(workArray_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> tempArray_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("tempArray", "v8::internal::FixedArray", "v8::internal::FixedArray", GetTempArrayAddress(), 1, 8, std::move(tempArray_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> sortLength_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("sortLength", "v8::internal::Object", "v8::internal::Object", GetSortLengthAddress(), 1, 8, std::move(sortLength_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> numberOfUndefined_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("numberOfUndefined", "v8::internal::Object", "v8::internal::Object", GetNumberOfUndefinedAddress(), 1, 8, std::move(numberOfUndefined_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSV8BreakIterator::GetName() const {
  return "v8::internal::JSV8BreakIterator";
}

void TqJSV8BreakIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSV8BreakIterator(this);
}

bool TqJSV8BreakIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSV8BreakIterator*>(other) != nullptr;
}

uintptr_t TqJSV8BreakIterator::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSV8BreakIterator::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBreakIteratorAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBreakIteratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBreakIteratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetUnicodeStringAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSV8BreakIterator::GetUnicodeStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUnicodeStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBoundAdoptTextAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBoundAdoptTextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundAdoptTextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBoundFirstAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBoundFirstValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundFirstAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBoundNextAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBoundNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBoundCurrentAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBoundCurrentValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundCurrentAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBoundBreakTypeAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBoundBreakTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundBreakTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSV8BreakIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::String", "v8::internal::String", GetLocaleAddress(), 1, 8, std::move(locale_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> break_iterator_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("break_iterator", "v8::internal::Foreign", "v8::internal::Foreign", GetBreakIteratorAddress(), 1, 8, std::move(break_iterator_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> unicode_string_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("unicode_string", "v8::internal::Foreign", "v8::internal::Foreign", GetUnicodeStringAddress(), 1, 8, std::move(unicode_string_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bound_adopt_text_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_adopt_text", "v8::internal::HeapObject", "v8::internal::HeapObject", GetBoundAdoptTextAddress(), 1, 8, std::move(bound_adopt_text_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bound_first_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_first", "v8::internal::HeapObject", "v8::internal::HeapObject", GetBoundFirstAddress(), 1, 8, std::move(bound_first_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bound_next_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_next", "v8::internal::HeapObject", "v8::internal::HeapObject", GetBoundNextAddress(), 1, 8, std::move(bound_next_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bound_current_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_current", "v8::internal::HeapObject", "v8::internal::HeapObject", GetBoundCurrentAddress(), 1, 8, std::move(bound_current_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bound_break_type_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_break_type", "v8::internal::HeapObject", "v8::internal::HeapObject", GetBoundBreakTypeAddress(), 1, 8, std::move(bound_break_type_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSCollator::GetName() const {
  return "v8::internal::JSCollator";
}

void TqJSCollator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSCollator(this);
}

bool TqJSCollator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSCollator*>(other) != nullptr;
}

uintptr_t TqJSCollator::GetIcuCollatorAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSCollator::GetIcuCollatorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuCollatorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSCollator::GetBoundCompareAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSCollator::GetBoundCompareValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundCompareAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSCollator::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSCollator::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSCollator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> icu_collator_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_collator", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuCollatorAddress(), 1, 8, std::move(icu_collator_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bound_compare_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_compare", "v8::internal::HeapObject", "v8::internal::HeapObject", GetBoundCompareAddress(), 1, 8, std::move(bound_compare_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::String", "v8::internal::String", GetLocaleAddress(), 1, 8, std::move(locale_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSDateTimeFormat::GetName() const {
  return "v8::internal::JSDateTimeFormat";
}

void TqJSDateTimeFormat::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSDateTimeFormat(this);
}

bool TqJSDateTimeFormat::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSDateTimeFormat*>(other) != nullptr;
}

uintptr_t TqJSDateTimeFormat::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSDateTimeFormat::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDateTimeFormat::GetIcuLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSDateTimeFormat::GetIcuLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDateTimeFormat::GetIcuSimpleDateFormatAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSDateTimeFormat::GetIcuSimpleDateFormatValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuSimpleDateFormatAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDateTimeFormat::GetIcuDateIntervalFormatAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSDateTimeFormat::GetIcuDateIntervalFormatValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuDateIntervalFormatAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDateTimeFormat::GetBoundFormatAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqJSDateTimeFormat::GetBoundFormatValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundFormatAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDateTimeFormat::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqJSDateTimeFormat::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSDateTimeFormat::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::String", "v8::internal::String", GetLocaleAddress(), 1, 8, std::move(locale_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_locale", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuLocaleAddress(), 1, 8, std::move(icu_locale_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_simple_date_format_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_simple_date_format", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuSimpleDateFormatAddress(), 1, 8, std::move(icu_simple_date_format_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_date_interval_format_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_date_interval_format", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuDateIntervalFormatAddress(), 1, 8, std::move(icu_date_interval_format_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bound_format_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_format", "v8::internal::HeapObject", "v8::internal::HeapObject", GetBoundFormatAddress(), 1, 8, std::move(bound_format_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("hour_cycle", CheckTypeName<JSDateTimeFormat::HourCycle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDateTimeFormat::HourCycle"), CheckTypeName<JSDateTimeFormat::HourCycle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDateTimeFormat::HourCycle"), 0, 3, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("date_style", CheckTypeName<JSDateTimeFormat::DateTimeStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDateTimeFormat::DateTimeStyle"), CheckTypeName<JSDateTimeFormat::DateTimeStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDateTimeFormat::DateTimeStyle"), 0, 3, 35));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("time_style", CheckTypeName<JSDateTimeFormat::DateTimeStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDateTimeFormat::DateTimeStyle"), CheckTypeName<JSDateTimeFormat::DateTimeStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDateTimeFormat::DateTimeStyle"), 0, 3, 38));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSDisplayNames::GetName() const {
  return "v8::internal::JSDisplayNames";
}

void TqJSDisplayNames::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSDisplayNames(this);
}

bool TqJSDisplayNames::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSDisplayNames*>(other) != nullptr;
}

uintptr_t TqJSDisplayNames::GetInternalAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSDisplayNames::GetInternalValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInternalAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDisplayNames::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSDisplayNames::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSDisplayNames::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> internal_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("internal", "v8::internal::Foreign", "v8::internal::Foreign", GetInternalAddress(), 1, 8, std::move(internal_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("style", CheckTypeName<JSDisplayNames::Style /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDisplayNames::Style"), CheckTypeName<JSDisplayNames::Style /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDisplayNames::Style"), 0, 2, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("fallback", CheckTypeName<JSDisplayNames::Fallback /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDisplayNames::Fallback"), CheckTypeName<JSDisplayNames::Fallback /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDisplayNames::Fallback"), 0, 1, 34));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("language_display", CheckTypeName<JSDisplayNames::LanguageDisplay /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDisplayNames::LanguageDisplay"), CheckTypeName<JSDisplayNames::LanguageDisplay /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDisplayNames::LanguageDisplay"), 0, 1, 35));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSDurationFormat::GetName() const {
  return "v8::internal::JSDurationFormat";
}

void TqJSDurationFormat::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSDurationFormat(this);
}

bool TqJSDurationFormat::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSDurationFormat*>(other) != nullptr;
}

uintptr_t TqJSDurationFormat::GetStyleFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSDurationFormat::GetStyleFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStyleFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDurationFormat::GetDisplayFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSDurationFormat::GetDisplayFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDisplayFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDurationFormat::GetIcuLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSDurationFormat::GetIcuLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDurationFormat::GetIcuNumberFormatterAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSDurationFormat::GetIcuNumberFormatterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuNumberFormatterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSDurationFormat::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> style_flags_struct_field_list;
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("style", CheckTypeName<JSDurationFormat::Style /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Style"), CheckTypeName<JSDurationFormat::Style /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Style"), 0, 2, 32));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("years_style", CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), 0, 2, 34));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("months_style", CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), 0, 2, 36));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("weeks_style", CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), 0, 2, 38));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("days_style", CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), 0, 2, 40));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("hours_style", CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), 0, 3, 42));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("minutes_style", CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), 0, 3, 45));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("seconds_style", CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), 0, 3, 48));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("milliseconds_style", CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), 0, 2, 51));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("microseconds_style", CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), 0, 2, 53));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("nanoseconds_style", CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), CheckTypeName<JSDurationFormat::FieldStyle /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::FieldStyle"), 0, 2, 55));
  style_flags_struct_field_list.push_back(std::make_unique<StructProperty>("separator", CheckTypeName<JSDurationFormat::Separator /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Separator"), CheckTypeName<JSDurationFormat::Separator /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Separator"), 0, 2, 57));
  result.push_back(std::make_unique<ObjectProperty>("style_flags", "v8::internal::Object", "v8::internal::Object", GetStyleFlagsAddress(), 1, 8, std::move(style_flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> display_flags_struct_field_list;
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("years_display", CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), 0, 1, 32));
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("months_display", CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), 0, 1, 33));
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("weeks_display", CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), 0, 1, 34));
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("days_display", CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), 0, 1, 35));
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("hours_display", CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), 0, 1, 36));
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("minutes_display", CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), 0, 1, 37));
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("seconds_display", CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), 0, 1, 38));
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("milliseconds_display", CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), 0, 1, 39));
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("microseconds_display", CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), 0, 1, 40));
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("nanoseconds_display", CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), CheckTypeName<JSDurationFormat::Display /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSDurationFormat::Display"), 0, 1, 41));
  display_flags_struct_field_list.push_back(std::make_unique<StructProperty>("fractional_digits", CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), CheckTypeName<int32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("int32_t"), 0, 4, 42));
  result.push_back(std::make_unique<ObjectProperty>("display_flags", "v8::internal::Object", "v8::internal::Object", GetDisplayFlagsAddress(), 1, 8, std::move(display_flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_locale", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuLocaleAddress(), 1, 8, std::move(icu_locale_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_number_formatter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_number_formatter", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuNumberFormatterAddress(), 1, 8, std::move(icu_number_formatter_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSListFormat::GetName() const {
  return "v8::internal::JSListFormat";
}

void TqJSListFormat::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSListFormat(this);
}

bool TqJSListFormat::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSListFormat*>(other) != nullptr;
}

uintptr_t TqJSListFormat::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSListFormat::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSListFormat::GetIcuFormatterAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSListFormat::GetIcuFormatterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuFormatterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSListFormat::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSListFormat::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSListFormat::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::String", "v8::internal::String", GetLocaleAddress(), 1, 8, std::move(locale_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_formatter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_formatter", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuFormatterAddress(), 1, 8, std::move(icu_formatter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("style", CheckTypeName<JSListFormat::Style /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSListFormat::Style"), CheckTypeName<JSListFormat::Style /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSListFormat::Style"), 0, 2, 32));
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("Type", CheckTypeName<JSListFormat::Type /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSListFormat::Type"), CheckTypeName<JSListFormat::Type /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSListFormat::Type"), 0, 2, 34));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSLocale::GetName() const {
  return "v8::internal::JSLocale";
}

void TqJSLocale::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSLocale(this);
}

bool TqJSLocale::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSLocale*>(other) != nullptr;
}

uintptr_t TqJSLocale::GetIcuLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSLocale::GetIcuLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSLocale::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> icu_locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_locale", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuLocaleAddress(), 1, 8, std::move(icu_locale_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSNumberFormat::GetName() const {
  return "v8::internal::JSNumberFormat";
}

void TqJSNumberFormat::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSNumberFormat(this);
}

bool TqJSNumberFormat::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSNumberFormat*>(other) != nullptr;
}

uintptr_t TqJSNumberFormat::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSNumberFormat::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSNumberFormat::GetIcuNumberFormatterAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSNumberFormat::GetIcuNumberFormatterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuNumberFormatterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSNumberFormat::GetBoundFormatAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSNumberFormat::GetBoundFormatValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundFormatAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSNumberFormat::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::String", "v8::internal::String", GetLocaleAddress(), 1, 8, std::move(locale_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_number_formatter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_number_formatter", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuNumberFormatterAddress(), 1, 8, std::move(icu_number_formatter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> bound_format_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("bound_format", "v8::internal::HeapObject", "v8::internal::HeapObject", GetBoundFormatAddress(), 1, 8, std::move(bound_format_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSPluralRules::GetName() const {
  return "v8::internal::JSPluralRules";
}

void TqJSPluralRules::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSPluralRules(this);
}

bool TqJSPluralRules::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSPluralRules*>(other) != nullptr;
}

uintptr_t TqJSPluralRules::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSPluralRules::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSPluralRules::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSPluralRules::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSPluralRules::GetIcuPluralRulesAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSPluralRules::GetIcuPluralRulesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuPluralRulesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSPluralRules::GetIcuNumberFormatterAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSPluralRules::GetIcuNumberFormatterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuNumberFormatterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSPluralRules::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::String", "v8::internal::String", GetLocaleAddress(), 1, 8, std::move(locale_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("Type", CheckTypeName<JSPluralRules::Type /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSPluralRules::Type"), CheckTypeName<JSPluralRules::Type /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSPluralRules::Type"), 0, 1, 32));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_plural_rules_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_plural_rules", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuPluralRulesAddress(), 1, 8, std::move(icu_plural_rules_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_number_formatter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_number_formatter", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuNumberFormatterAddress(), 1, 8, std::move(icu_number_formatter_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRelativeTimeFormat::GetName() const {
  return "v8::internal::JSRelativeTimeFormat";
}

void TqJSRelativeTimeFormat::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRelativeTimeFormat(this);
}

bool TqJSRelativeTimeFormat::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRelativeTimeFormat*>(other) != nullptr;
}

uintptr_t TqJSRelativeTimeFormat::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSRelativeTimeFormat::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRelativeTimeFormat::GetNumberingSystemAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSRelativeTimeFormat::GetNumberingSystemValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNumberingSystemAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRelativeTimeFormat::GetIcuFormatterAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSRelativeTimeFormat::GetIcuFormatterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuFormatterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRelativeTimeFormat::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSRelativeTimeFormat::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRelativeTimeFormat::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::String", "v8::internal::String", GetLocaleAddress(), 1, 8, std::move(locale_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> numberingSystem_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("numberingSystem", "v8::internal::String", "v8::internal::String", GetNumberingSystemAddress(), 1, 8, std::move(numberingSystem_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_formatter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_formatter", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuFormatterAddress(), 1, 8, std::move(icu_formatter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("numeric", CheckTypeName<JSRelativeTimeFormat::Numeric /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSRelativeTimeFormat::Numeric"), CheckTypeName<JSRelativeTimeFormat::Numeric /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSRelativeTimeFormat::Numeric"), 0, 1, 32));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSSegmentIterator::GetName() const {
  return "v8::internal::JSSegmentIterator";
}

void TqJSSegmentIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSegmentIterator(this);
}

bool TqJSSegmentIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSegmentIterator*>(other) != nullptr;
}

uintptr_t TqJSSegmentIterator::GetIcuBreakIteratorAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSSegmentIterator::GetIcuBreakIteratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuBreakIteratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSegmentIterator::GetUnicodeStringAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSSegmentIterator::GetUnicodeStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUnicodeStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSegmentIterator::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSSegmentIterator::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSegmentIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> icu_break_iterator_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_break_iterator", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuBreakIteratorAddress(), 1, 8, std::move(icu_break_iterator_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> unicode_string_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("unicode_string", "v8::internal::Foreign", "v8::internal::Foreign", GetUnicodeStringAddress(), 1, 8, std::move(unicode_string_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("granularity", CheckTypeName<JSSegmenter::Granularity /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSSegmenter::Granularity"), CheckTypeName<JSSegmenter::Granularity /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSSegmenter::Granularity"), 0, 2, 32));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSSegmenter::GetName() const {
  return "v8::internal::JSSegmenter";
}

void TqJSSegmenter::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSegmenter(this);
}

bool TqJSSegmenter::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSegmenter*>(other) != nullptr;
}

uintptr_t TqJSSegmenter::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSSegmenter::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSegmenter::GetIcuBreakIteratorAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSSegmenter::GetIcuBreakIteratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuBreakIteratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSegmenter::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSSegmenter::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSegmenter::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> locale_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::String", "v8::internal::String", GetLocaleAddress(), 1, 8, std::move(locale_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> icu_break_iterator_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_break_iterator", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuBreakIteratorAddress(), 1, 8, std::move(icu_break_iterator_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("granularity", CheckTypeName<JSSegmenter::Granularity /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSSegmenter::Granularity"), CheckTypeName<JSSegmenter::Granularity /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSSegmenter::Granularity"), 0, 2, 32));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSSegments::GetName() const {
  return "v8::internal::JSSegments";
}

void TqJSSegments::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSegments(this);
}

bool TqJSSegments::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSegments*>(other) != nullptr;
}

uintptr_t TqJSSegments::GetIcuBreakIteratorAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSSegments::GetIcuBreakIteratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuBreakIteratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSegments::GetUnicodeStringAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSSegments::GetUnicodeStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUnicodeStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSegments::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSSegments::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSegments::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> icu_break_iterator_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("icu_break_iterator", "v8::internal::Foreign", "v8::internal::Foreign", GetIcuBreakIteratorAddress(), 1, 8, std::move(icu_break_iterator_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> unicode_string_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("unicode_string", "v8::internal::Foreign", "v8::internal::Foreign", GetUnicodeStringAddress(), 1, 8, std::move(unicode_string_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> flags_struct_field_list;
  flags_struct_field_list.push_back(std::make_unique<StructProperty>("granularity", CheckTypeName<JSSegmenter::Granularity /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSSegmenter::Granularity"), CheckTypeName<JSSegmenter::Granularity /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("JSSegmenter::Granularity"), 0, 2, 32));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::Object", "v8::internal::Object", GetFlagsAddress(), 1, 8, std::move(flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmApiFunctionRef::GetName() const {
  return "v8::internal::WasmApiFunctionRef";
}

void TqWasmApiFunctionRef::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmApiFunctionRef(this);
}

bool TqWasmApiFunctionRef::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmApiFunctionRef*>(other) != nullptr;
}

uintptr_t TqWasmApiFunctionRef::GetNativeContextAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmApiFunctionRef::GetNativeContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNativeContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmApiFunctionRef::GetCallableAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmApiFunctionRef::GetCallableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmApiFunctionRef::GetInstanceAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmApiFunctionRef::GetInstanceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmApiFunctionRef::GetSuspendAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmApiFunctionRef::GetSuspendValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSuspendAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmApiFunctionRef::GetWrapperBudgetAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqWasmApiFunctionRef::GetWrapperBudgetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWrapperBudgetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmApiFunctionRef::GetCallOriginAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqWasmApiFunctionRef::GetCallOriginValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallOriginAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmApiFunctionRef::GetSigAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqWasmApiFunctionRef::GetSigValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSigAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmApiFunctionRef::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> native_context_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("native_context", "v8::internal::NativeContext", "v8::internal::NativeContext", GetNativeContextAddress(), 1, 8, std::move(native_context_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> callable_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("callable", "v8::internal::HeapObject", "v8::internal::HeapObject", GetCallableAddress(), 1, 8, std::move(callable_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> instance_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance", "v8::internal::HeapObject", "v8::internal::HeapObject", GetInstanceAddress(), 1, 8, std::move(instance_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> suspend_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("suspend", "v8::internal::Object", "v8::internal::Object", GetSuspendAddress(), 1, 8, std::move(suspend_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> wrapper_budget_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("wrapper_budget", "v8::internal::Object", "v8::internal::Object", GetWrapperBudgetAddress(), 1, 8, std::move(wrapper_budget_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> call_origin_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("call_origin", "v8::internal::Object", "v8::internal::Object", GetCallOriginAddress(), 1, 8, std::move(call_origin_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> sig_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("sig", "v8::internal::ByteArray", "v8::internal::ByteArray", GetSigAddress(), 1, 8, std::move(sig_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmFunctionData::GetName() const {
  return "v8::internal::WasmFunctionData";
}

void TqWasmFunctionData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmFunctionData(this);
}

bool TqWasmFunctionData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmFunctionData*>(other) != nullptr;
}

uintptr_t TqWasmFunctionData::GetInternalAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmFunctionData::GetInternalValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInternalAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmFunctionData::GetWrapperCodeAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmFunctionData::GetWrapperCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWrapperCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmFunctionData::GetJsPromiseFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmFunctionData::GetJsPromiseFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetJsPromiseFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmFunctionData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> internal_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("internal", "v8::internal::WasmInternalFunction", "v8::internal::WasmInternalFunction", GetInternalAddress(), 1, 8, std::move(internal_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> wrapper_code_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("wrapper_code", "v8::internal::Code", "v8::internal::Code", GetWrapperCodeAddress(), 1, 8, std::move(wrapper_code_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> js_promise_flags_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("js_promise_flags", "v8::internal::Object", "v8::internal::Object", GetJsPromiseFlagsAddress(), 1, 8, std::move(js_promise_flags_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmExportedFunctionData::GetName() const {
  return "v8::internal::WasmExportedFunctionData";
}

void TqWasmExportedFunctionData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmExportedFunctionData(this);
}

bool TqWasmExportedFunctionData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmExportedFunctionData*>(other) != nullptr;
}

uintptr_t TqWasmExportedFunctionData::GetInstanceAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetInstanceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetFunctionIndexAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetFunctionIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetWrapperBudgetAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetWrapperBudgetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWrapperBudgetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetCWrapperCodeAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetCWrapperCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCWrapperCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetPackedArgsSizeAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetPackedArgsSizeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPackedArgsSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetCanonicalTypeIndexAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetCanonicalTypeIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCanonicalTypeIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetSigAddress() const {
  return address_ - i::kHeapObjectTag + 80;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmExportedFunctionData::GetSigValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetSigAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmExportedFunctionData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqWasmFunctionData::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> instance_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance", "v8::internal::WasmInstanceObject", "v8::internal::WasmInstanceObject", GetInstanceAddress(), 1, 8, std::move(instance_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> function_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("function_index", "v8::internal::Object", "v8::internal::Object", GetFunctionIndexAddress(), 1, 8, std::move(function_index_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> wrapper_budget_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("wrapper_budget", "v8::internal::Object", "v8::internal::Object", GetWrapperBudgetAddress(), 1, 8, std::move(wrapper_budget_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> c_wrapper_code_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("c_wrapper_code", "v8::internal::Code", "v8::internal::Code", GetCWrapperCodeAddress(), 1, 8, std::move(c_wrapper_code_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> packed_args_size_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("packed_args_size", "v8::internal::Object", "v8::internal::Object", GetPackedArgsSizeAddress(), 1, 8, std::move(packed_args_size_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> canonical_type_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("canonical_type_index", "v8::internal::Object", "v8::internal::Object", GetCanonicalTypeIndexAddress(), 1, 8, std::move(canonical_type_index_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> sig_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("sig", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetSigAddress(), 1, 8, std::move(sig_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmJSFunctionData::GetName() const {
  return "v8::internal::WasmJSFunctionData";
}

void TqWasmJSFunctionData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmJSFunctionData(this);
}

bool TqWasmJSFunctionData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmJSFunctionData*>(other) != nullptr;
}

uintptr_t TqWasmJSFunctionData::GetSerializedSignatureAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmJSFunctionData::GetSerializedSignatureValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSerializedSignatureAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmJSFunctionData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqWasmFunctionData::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> serialized_signature_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("serialized_signature", "v8::internal::ByteArray", "v8::internal::ByteArray", GetSerializedSignatureAddress(), 1, 8, std::move(serialized_signature_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmCapiFunctionData::GetName() const {
  return "v8::internal::WasmCapiFunctionData";
}

void TqWasmCapiFunctionData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmCapiFunctionData(this);
}

bool TqWasmCapiFunctionData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmCapiFunctionData*>(other) != nullptr;
}

uintptr_t TqWasmCapiFunctionData::GetEmbedderDataAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmCapiFunctionData::GetEmbedderDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEmbedderDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmCapiFunctionData::GetSerializedSignatureAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqWasmCapiFunctionData::GetSerializedSignatureValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSerializedSignatureAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmCapiFunctionData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqWasmFunctionData::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> embedder_data_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("embedder_data", "v8::internal::Foreign", "v8::internal::Foreign", GetEmbedderDataAddress(), 1, 8, std::move(embedder_data_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> serialized_signature_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("serialized_signature", "v8::internal::ByteArray", "v8::internal::ByteArray", GetSerializedSignatureAddress(), 1, 8, std::move(serialized_signature_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmResumeData::GetName() const {
  return "v8::internal::WasmResumeData";
}

void TqWasmResumeData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmResumeData(this);
}

bool TqWasmResumeData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmResumeData*>(other) != nullptr;
}

uintptr_t TqWasmResumeData::GetSuspenderAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmResumeData::GetSuspenderValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSuspenderAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmResumeData::GetOnResumeAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmResumeData::GetOnResumeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOnResumeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmResumeData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> suspender_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("suspender", "v8::internal::WasmSuspenderObject", "v8::internal::WasmSuspenderObject", GetSuspenderAddress(), 1, 8, std::move(suspender_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> on_resume_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("on_resume", "v8::internal::Object", "v8::internal::Object", GetOnResumeAddress(), 1, 8, std::move(on_resume_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmIndirectFunctionTable::GetName() const {
  return "v8::internal::WasmIndirectFunctionTable";
}

void TqWasmIndirectFunctionTable::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmIndirectFunctionTable(this);
}

bool TqWasmIndirectFunctionTable::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmIndirectFunctionTable*>(other) != nullptr;
}

uintptr_t TqWasmIndirectFunctionTable::GetSigIdsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmIndirectFunctionTable::GetSigIdsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSigIdsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmIndirectFunctionTable::GetTargetsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmIndirectFunctionTable::GetTargetsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTargetsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmIndirectFunctionTable::GetRefsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmIndirectFunctionTable::GetRefsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRefsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmIndirectFunctionTable::GetSizeAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmIndirectFunctionTable::GetSizeValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmIndirectFunctionTable::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmIndirectFunctionTable::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmIndirectFunctionTable::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> sig_ids_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("sig_ids", "v8::internal::ByteArray", "v8::internal::ByteArray", GetSigIdsAddress(), 1, 8, std::move(sig_ids_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> targets_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("targets", "v8::internal::ExternalPointerArray", "v8::internal::ExternalPointerArray", GetTargetsAddress(), 1, 8, std::move(targets_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> refs_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("refs", "v8::internal::FixedArray", "v8::internal::FixedArray", GetRefsAddress(), 1, 8, std::move(refs_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> size_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("size", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetSizeAddress(), 1, 4, std::move(size_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmContinuationObject::GetName() const {
  return "v8::internal::WasmContinuationObject";
}

void TqWasmContinuationObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmContinuationObject(this);
}

bool TqWasmContinuationObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmContinuationObject*>(other) != nullptr;
}

uintptr_t TqWasmContinuationObject::GetStackAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmContinuationObject::GetStackValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStackAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmContinuationObject::GetParentAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmContinuationObject::GetParentValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParentAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmContinuationObject::GetJmpbufAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmContinuationObject::GetJmpbufValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetJmpbufAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmContinuationObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> stack_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("stack", "v8::internal::Foreign", "v8::internal::Foreign", GetStackAddress(), 1, 8, std::move(stack_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> parent_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("parent", "v8::internal::HeapObject", "v8::internal::HeapObject", GetParentAddress(), 1, 8, std::move(parent_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> jmpbuf_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("jmpbuf", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetJmpbufAddress(), 1, 8, std::move(jmpbuf_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmSuspenderObject::GetName() const {
  return "v8::internal::WasmSuspenderObject";
}

void TqWasmSuspenderObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmSuspenderObject(this);
}

bool TqWasmSuspenderObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmSuspenderObject*>(other) != nullptr;
}

uintptr_t TqWasmSuspenderObject::GetContinuationAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmSuspenderObject::GetContinuationValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContinuationAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmSuspenderObject::GetParentAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmSuspenderObject::GetParentValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParentAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmSuspenderObject::GetPromiseAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqWasmSuspenderObject::GetPromiseValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmSuspenderObject::GetResumeAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqWasmSuspenderObject::GetResumeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetResumeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmSuspenderObject::GetRejectAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqWasmSuspenderObject::GetRejectValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRejectAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmSuspenderObject::GetStateAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqWasmSuspenderObject::GetStateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmSuspenderObject::GetWasmToJsCounterAddress() const {
  return address_ - i::kHeapObjectTag + 72;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmSuspenderObject::GetWasmToJsCounterValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetWasmToJsCounterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmSuspenderObject::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 76;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmSuspenderObject::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmSuspenderObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> continuation_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("continuation", "v8::internal::HeapObject", "v8::internal::HeapObject", GetContinuationAddress(), 1, 8, std::move(continuation_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> parent_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("parent", "v8::internal::HeapObject", "v8::internal::HeapObject", GetParentAddress(), 1, 8, std::move(parent_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> promise_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("promise", "v8::internal::JSPromise", "v8::internal::JSPromise", GetPromiseAddress(), 1, 8, std::move(promise_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> resume_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("resume", "v8::internal::HeapObject", "v8::internal::HeapObject", GetResumeAddress(), 1, 8, std::move(resume_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> reject_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("reject", "v8::internal::HeapObject", "v8::internal::HeapObject", GetRejectAddress(), 1, 8, std::move(reject_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> state_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("state", "v8::internal::Object", "v8::internal::Object", GetStateAddress(), 1, 8, std::move(state_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> wasm_to_js_counter_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("wasm_to_js_counter", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetWasmToJsCounterAddress(), 1, 4, std::move(wasm_to_js_counter_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmExceptionTag::GetName() const {
  return "v8::internal::WasmExceptionTag";
}

void TqWasmExceptionTag::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmExceptionTag(this);
}

bool TqWasmExceptionTag::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmExceptionTag*>(other) != nullptr;
}

uintptr_t TqWasmExceptionTag::GetIndexAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmExceptionTag::GetIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmExceptionTag::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("index", "v8::internal::Object", "v8::internal::Object", GetIndexAddress(), 1, 8, std::move(index_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmModuleObject::GetName() const {
  return "v8::internal::WasmModuleObject";
}

void TqWasmModuleObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmModuleObject(this);
}

bool TqWasmModuleObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmModuleObject*>(other) != nullptr;
}

uintptr_t TqWasmModuleObject::GetManagedNativeModuleAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmModuleObject::GetManagedNativeModuleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetManagedNativeModuleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmModuleObject::GetScriptAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmModuleObject::GetScriptValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmModuleObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> managed_native_module_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("managed_native_module", "v8::internal::Foreign", "v8::internal::Foreign", GetManagedNativeModuleAddress(), 1, 8, std::move(managed_native_module_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> script_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("script", "v8::internal::Script", "v8::internal::Script", GetScriptAddress(), 1, 8, std::move(script_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmTableObject::GetName() const {
  return "v8::internal::WasmTableObject";
}

void TqWasmTableObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmTableObject(this);
}

bool TqWasmTableObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmTableObject*>(other) != nullptr;
}

uintptr_t TqWasmTableObject::GetInstanceAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmTableObject::GetInstanceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTableObject::GetEntriesAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmTableObject::GetEntriesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEntriesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTableObject::GetCurrentLengthAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqWasmTableObject::GetCurrentLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCurrentLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTableObject::GetMaximumLengthAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqWasmTableObject::GetMaximumLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMaximumLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTableObject::GetDispatchTablesAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqWasmTableObject::GetDispatchTablesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDispatchTablesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTableObject::GetRawTypeAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqWasmTableObject::GetRawTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRawTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmTableObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> instance_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance", "v8::internal::HeapObject", "v8::internal::HeapObject", GetInstanceAddress(), 1, 8, std::move(instance_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> entries_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("entries", "v8::internal::FixedArray", "v8::internal::FixedArray", GetEntriesAddress(), 1, 8, std::move(entries_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> current_length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("current_length", "v8::internal::Object", "v8::internal::Object", GetCurrentLengthAddress(), 1, 8, std::move(current_length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> maximum_length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("maximum_length", "v8::internal::Object", "v8::internal::Object", GetMaximumLengthAddress(), 1, 8, std::move(maximum_length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> dispatch_tables_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("dispatch_tables", "v8::internal::FixedArray", "v8::internal::FixedArray", GetDispatchTablesAddress(), 1, 8, std::move(dispatch_tables_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> raw_type_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw_type", "v8::internal::Object", "v8::internal::Object", GetRawTypeAddress(), 1, 8, std::move(raw_type_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmMemoryObject::GetName() const {
  return "v8::internal::WasmMemoryObject";
}

void TqWasmMemoryObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmMemoryObject(this);
}

bool TqWasmMemoryObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmMemoryObject*>(other) != nullptr;
}

uintptr_t TqWasmMemoryObject::GetArrayBufferAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmMemoryObject::GetArrayBufferValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetArrayBufferAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmMemoryObject::GetMaximumPagesAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmMemoryObject::GetMaximumPagesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMaximumPagesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmMemoryObject::GetIsMemory64Address() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqWasmMemoryObject::GetIsMemory64Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIsMemory64Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmMemoryObject::GetInstancesAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqWasmMemoryObject::GetInstancesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstancesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmMemoryObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> array_buffer_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("array_buffer", "v8::internal::JSArrayBuffer", "v8::internal::JSArrayBuffer", GetArrayBufferAddress(), 1, 8, std::move(array_buffer_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> maximum_pages_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("maximum_pages", "v8::internal::Object", "v8::internal::Object", GetMaximumPagesAddress(), 1, 8, std::move(maximum_pages_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> is_memory64_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("is_memory64", "v8::internal::Object", "v8::internal::Object", GetIsMemory64Address(), 1, 8, std::move(is_memory64_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> instances_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instances", "v8::internal::HeapObject", "v8::internal::HeapObject", GetInstancesAddress(), 1, 8, std::move(instances_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmGlobalObject::GetName() const {
  return "v8::internal::WasmGlobalObject";
}

void TqWasmGlobalObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmGlobalObject(this);
}

bool TqWasmGlobalObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmGlobalObject*>(other) != nullptr;
}

uintptr_t TqWasmGlobalObject::GetInstanceAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmGlobalObject::GetInstanceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmGlobalObject::GetUntaggedBufferAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmGlobalObject::GetUntaggedBufferValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUntaggedBufferAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmGlobalObject::GetTaggedBufferAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqWasmGlobalObject::GetTaggedBufferValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTaggedBufferAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmGlobalObject::GetOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqWasmGlobalObject::GetOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmGlobalObject::GetRawTypeAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqWasmGlobalObject::GetRawTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRawTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmGlobalObject::GetIsMutableAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqWasmGlobalObject::GetIsMutableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIsMutableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmGlobalObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> instance_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance", "v8::internal::HeapObject", "v8::internal::HeapObject", GetInstanceAddress(), 1, 8, std::move(instance_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> untagged_buffer_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("untagged_buffer", "v8::internal::HeapObject", "v8::internal::HeapObject", GetUntaggedBufferAddress(), 1, 8, std::move(untagged_buffer_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> tagged_buffer_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("tagged_buffer", "v8::internal::HeapObject", "v8::internal::HeapObject", GetTaggedBufferAddress(), 1, 8, std::move(tagged_buffer_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> offset_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("offset", "v8::internal::Object", "v8::internal::Object", GetOffsetAddress(), 1, 8, std::move(offset_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> raw_type_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("raw_type", "v8::internal::Object", "v8::internal::Object", GetRawTypeAddress(), 1, 8, std::move(raw_type_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> is_mutable_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("is_mutable", "v8::internal::Object", "v8::internal::Object", GetIsMutableAddress(), 1, 8, std::move(is_mutable_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmTagObject::GetName() const {
  return "v8::internal::WasmTagObject";
}

void TqWasmTagObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmTagObject(this);
}

bool TqWasmTagObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmTagObject*>(other) != nullptr;
}

uintptr_t TqWasmTagObject::GetSerializedSignatureAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmTagObject::GetSerializedSignatureValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSerializedSignatureAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTagObject::GetTagAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmTagObject::GetTagValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTagAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTagObject::GetCanonicalTypeIndexAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqWasmTagObject::GetCanonicalTypeIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCanonicalTypeIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmTagObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> serialized_signature_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("serialized_signature", "v8::internal::ByteArray", "v8::internal::ByteArray", GetSerializedSignatureAddress(), 1, 8, std::move(serialized_signature_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> tag_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("tag", "v8::internal::HeapObject", "v8::internal::HeapObject", GetTagAddress(), 1, 8, std::move(tag_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> canonical_type_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("canonical_type_index", "v8::internal::Object", "v8::internal::Object", GetCanonicalTypeIndexAddress(), 1, 8, std::move(canonical_type_index_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqAsmWasmData::GetName() const {
  return "v8::internal::AsmWasmData";
}

void TqAsmWasmData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAsmWasmData(this);
}

bool TqAsmWasmData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAsmWasmData*>(other) != nullptr;
}

uintptr_t TqAsmWasmData::GetManagedNativeModuleAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAsmWasmData::GetManagedNativeModuleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetManagedNativeModuleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAsmWasmData::GetUsesBitsetAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqAsmWasmData::GetUsesBitsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUsesBitsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAsmWasmData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> managed_native_module_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("managed_native_module", "v8::internal::Foreign", "v8::internal::Foreign", GetManagedNativeModuleAddress(), 1, 8, std::move(managed_native_module_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> uses_bitset_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("uses_bitset", "v8::internal::HeapNumber", "v8::internal::HeapNumber", GetUsesBitsetAddress(), 1, 8, std::move(uses_bitset_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmTypeInfo::GetName() const {
  return "v8::internal::WasmTypeInfo";
}

void TqWasmTypeInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmTypeInfo(this);
}

bool TqWasmTypeInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmTypeInfo*>(other) != nullptr;
}

uintptr_t TqWasmTypeInfo::GetNativeTypeAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmTypeInfo::GetNativeTypeValue(d::MemoryAccessor accessor) const {
  ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetNativeTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmTypeInfo::GetTypeIndexAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmTypeInfo::GetTypeIndexValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetTypeIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmTypeInfo::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmTypeInfo::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmTypeInfo::GetInstanceAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmTypeInfo::GetInstanceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTypeInfo::GetSupertypesLengthAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWasmTypeInfo::GetSupertypesLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSupertypesLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTypeInfo::GetSupertypesAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqWasmTypeInfo::GetSupertypesValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSupertypesAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmTypeInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> native_type_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("native_type", CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), CheckTypeName<ExternalPointer_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("ExternalPointer_t"), GetNativeTypeAddress(), 1, 8, std::move(native_type_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> type_index_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("type_index", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetTypeIndexAddress(), 1, 4, std::move(type_index_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> instance_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("instance", "v8::internal::HeapObject", "v8::internal::HeapObject", GetInstanceAddress(), 1, 8, std::move(instance_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> supertypes_length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("supertypes_length", "v8::internal::Object", "v8::internal::Object", GetSupertypesLengthAddress(), 1, 8, std::move(supertypes_length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> supertypes_struct_field_list;
  auto indexed_field_slice_supertypes = TqDebugFieldSliceWasmTypeInfoSupertypes(accessor, address_);
  if (indexed_field_slice_supertypes.validity == d::MemoryAccessResult::kOk) {
    result.push_back(std::make_unique<ObjectProperty>("supertypes", "v8::internal::Object", "v8::internal::Object", address_ - i::kHeapObjectTag + std::get<1>(indexed_field_slice_supertypes.value), std::get<2>(indexed_field_slice_supertypes.value), 8, std::move(supertypes_struct_field_list), GetArrayKind(indexed_field_slice_supertypes.validity)));
  }
  return result;
}

const char* TqWasmObject::GetName() const {
  return "v8::internal::WasmObject";
}

void TqWasmObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmObject(this);
}

bool TqWasmObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmObject*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSReceiver::GetProperties(accessor);
  return result;
}

const char* TqWasmStruct::GetName() const {
  return "v8::internal::WasmStruct";
}

void TqWasmStruct::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmStruct(this);
}

bool TqWasmStruct::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmStruct*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmStruct::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqWasmObject::GetProperties(accessor);
  return result;
}

const char* TqWasmArray::GetName() const {
  return "v8::internal::WasmArray";
}

void TqWasmArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmArray(this);
}

bool TqWasmArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmArray*>(other) != nullptr;
}

uintptr_t TqWasmArray::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmArray::GetLengthValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmArray::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmArray::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqWasmObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> length_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("length", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetLengthAddress(), 1, 4, std::move(length_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmStringViewIter::GetName() const {
  return "v8::internal::WasmStringViewIter";
}

void TqWasmStringViewIter::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmStringViewIter(this);
}

bool TqWasmStringViewIter::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmStringViewIter*>(other) != nullptr;
}

uintptr_t TqWasmStringViewIter::GetStringAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmStringViewIter::GetStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmStringViewIter::GetOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmStringViewIter::GetOffsetValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmStringViewIter::GetOptionalPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/> TqWasmStringViewIter::GetOptionalPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/ value{};
  d::MemoryAccessResult validity = accessor(GetOptionalPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmStringViewIter::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  std::vector<std::unique_ptr<StructProperty>> string_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("string", "v8::internal::String", "v8::internal::String", GetStringAddress(), 1, 8, std::move(string_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> offset_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("offset", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOffsetAddress(), 1, 4, std::move(offset_struct_field_list), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> optional_padding_struct_field_list;
  result.push_back(std::make_unique<ObjectProperty>("optional_padding", CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), CheckTypeName<uint32_t /*Failing? Ensure constexpr type name is correct, and the necessary #include is in any .tq file*/>("uint32_t"), GetOptionalPaddingAddress(), 1, 4, std::move(optional_padding_struct_field_list), d::PropertyKind::kSingle));
  return result;
}

const char* kObjectClassNames[] {
  "v8::internal::HeapObject",
  "v8::internal::Context",
  "v8::internal::JSReceiver",
  "v8::internal::PrimitiveHeapObject",
  "v8::internal::Oddball",
  "v8::internal::Undefined",
  "v8::internal::Null",
  "v8::internal::Boolean",
  "v8::internal::Name",
  "v8::internal::Symbol",
  "v8::internal::String",
  "v8::internal::HeapNumber",
  "v8::internal::FixedArrayBase",
  "v8::internal::FixedArray",
  "v8::internal::JSObject",
  "v8::internal::WeakFixedArray",
  "v8::internal::Foreign",
  "v8::internal::JSProxy",
  "v8::internal::JSFunctionOrBoundFunctionOrWrappedFunction",
  "v8::internal::JSWrappedFunction",
  "v8::internal::JSBoundFunction",
  "v8::internal::JSFunction",
  "v8::internal::Hole",
  "v8::internal::JSObjectWithEmbedderSlots",
  "v8::internal::JSCustomElementsObject",
  "v8::internal::JSSpecialObject",
  "v8::internal::WasmNull",
  "v8::internal::WasmInternalFunction",
  "v8::internal::WeakCell",
  "v8::internal::Map",
  "v8::internal::JSPromise",
  "v8::internal::Struct",
  "v8::internal::PromiseCapability",
  "v8::internal::JSArrayBufferView",
  "v8::internal::JSTypedArray",
  "v8::internal::DataHandler",
  "v8::internal::AllocationMemento",
  "v8::internal::CallHandlerInfo",
  "v8::internal::InterceptorInfo",
  "v8::internal::AccessCheckInfo",
  "v8::internal::AccessorInfo",
  "v8::internal::JSArgumentsObject",
  "v8::internal::JSStrictArgumentsObject",
  "v8::internal::JSSloppyArgumentsObject",
  "v8::internal::SloppyArgumentsElements",
  "v8::internal::AliasedArgumentsEntry",
  "v8::internal::CallSiteInfo",
  "v8::internal::Cell",
  "v8::internal::BytecodeArray",
  "v8::internal::ScopeInfo",
  "v8::internal::FixedDoubleArray",
  "v8::internal::RegExpMatchInfo",
  "v8::internal::BreakPoint",
  "v8::internal::BreakPointInfo",
  "v8::internal::DebugInfo",
  "v8::internal::CoverageInfo",
  "v8::internal::StackFrameInfo",
  "v8::internal::ErrorStackData",
  "v8::internal::PromiseOnStack",
  "v8::internal::EnumCache",
  "v8::internal::ClassPositions",
  "v8::internal::AccessorPair",
  "v8::internal::DescriptorArray",
  "v8::internal::StrongDescriptorArray",
  "v8::internal::EmbedderDataArray",
  "v8::internal::FeedbackCell",
  "v8::internal::FeedbackVector",
  "v8::internal::ByteArray",
  "v8::internal::ExternalPointerArray",
  "v8::internal::ArrayList",
  "v8::internal::TemplateList",
  "v8::internal::WeakArrayList",
  "v8::internal::FreeSpace",
  "v8::internal::JSArrayBuffer",
  "v8::internal::JSDataViewOrRabGsabDataView",
  "v8::internal::JSDataView",
  "v8::internal::JSRabGsabDataView",
  "v8::internal::JSArrayIterator",
  "v8::internal::JSArray",
  "v8::internal::TemplateLiteralObject",
  "v8::internal::AlwaysSharedSpaceJSObject",
  "v8::internal::JSSynchronizationPrimitive",
  "v8::internal::JSAtomicsMutex",
  "v8::internal::JSAtomicsCondition",
  "v8::internal::JSCollectionIterator",
  "v8::internal::JSCollection",
  "v8::internal::JSSet",
  "v8::internal::JSMap",
  "v8::internal::JSWeakCollection",
  "v8::internal::JSWeakSet",
  "v8::internal::JSWeakMap",
  "v8::internal::JSGeneratorObject",
  "v8::internal::JSAsyncFunctionObject",
  "v8::internal::JSAsyncGeneratorObject",
  "v8::internal::AsyncGeneratorRequest",
  "v8::internal::JSIteratorHelper",
  "v8::internal::JSIteratorMapHelper",
  "v8::internal::JSIteratorFilterHelper",
  "v8::internal::JSIteratorTakeHelper",
  "v8::internal::JSIteratorDropHelper",
  "v8::internal::JSIteratorFlatMapHelper",
  "v8::internal::JSExternalObject",
  "v8::internal::JSGlobalProxy",
  "v8::internal::JSGlobalObject",
  "v8::internal::JSPrimitiveWrapper",
  "v8::internal::JSMessageObject",
  "v8::internal::JSDate",
  "v8::internal::JSAsyncFromSyncIterator",
  "v8::internal::JSStringIterator",
  "v8::internal::JSValidIteratorWrapper",
  "v8::internal::JSProxyRevocableResult",
  "v8::internal::JSRawJson",
  "v8::internal::JSRegExpStringIterator",
  "v8::internal::JSRegExp",
  "v8::internal::JSRegExpResult",
  "v8::internal::JSRegExpResultWithIndices",
  "v8::internal::JSRegExpResultIndices",
  "v8::internal::JSShadowRealm",
  "v8::internal::JSSharedArray",
  "v8::internal::JSSharedStruct",
  "v8::internal::JSTemporalCalendar",
  "v8::internal::JSTemporalDuration",
  "v8::internal::JSTemporalInstant",
  "v8::internal::JSTemporalPlainDateTime",
  "v8::internal::JSTemporalPlainDate",
  "v8::internal::JSTemporalPlainMonthDay",
  "v8::internal::JSTemporalPlainTime",
  "v8::internal::JSTemporalPlainYearMonth",
  "v8::internal::JSTemporalTimeZone",
  "v8::internal::JSTemporalZonedDateTime",
  "v8::internal::JSFinalizationRegistry",
  "v8::internal::JSWeakRef",
  "v8::internal::ArrayBoilerplateDescription",
  "v8::internal::RegExpBoilerplateDescription",
  "v8::internal::MegaDomHandler",
  "v8::internal::Microtask",
  "v8::internal::CallbackTask",
  "v8::internal::CallableTask",
  "v8::internal::Module",
  "v8::internal::JSModuleNamespace",
  "v8::internal::ScriptOrModule",
  "v8::internal::True",
  "v8::internal::False",
  "v8::internal::SmallOrderedHashTable",
  "v8::internal::SmallOrderedHashSet",
  "v8::internal::SmallOrderedHashMap",
  "v8::internal::SmallOrderedNameDictionary",
  "v8::internal::PromiseReaction",
  "v8::internal::PromiseReactionJobTask",
  "v8::internal::PromiseFulfillReactionJobTask",
  "v8::internal::PromiseRejectReactionJobTask",
  "v8::internal::PromiseResolveThenableJobTask",
  "v8::internal::PropertyArray",
  "v8::internal::PropertyCell",
  "v8::internal::PropertyDescriptorObject",
  "v8::internal::PrototypeInfo",
  "v8::internal::Script",
  "v8::internal::PreparseData",
  "v8::internal::InterpreterData",
  "v8::internal::SharedFunctionInfo",
  "v8::internal::UncompiledData",
  "v8::internal::UncompiledDataWithoutPreparseData",
  "v8::internal::UncompiledDataWithPreparseData",
  "v8::internal::UncompiledDataWithoutPreparseDataWithJob",
  "v8::internal::UncompiledDataWithPreparseDataAndJob",
  "v8::internal::OnHeapBasicBlockProfilerData",
  "v8::internal::SourceTextModule",
  "v8::internal::ModuleRequest",
  "v8::internal::SourceTextModuleInfoEntry",
  "v8::internal::ConsString",
  "v8::internal::ExternalString",
  "v8::internal::ExternalOneByteString",
  "v8::internal::ExternalTwoByteString",
  "v8::internal::InternalizedString",
  "v8::internal::SeqString",
  "v8::internal::SeqOneByteString",
  "v8::internal::SeqTwoByteString",
  "v8::internal::SlicedString",
  "v8::internal::ThinString",
  "v8::internal::Tuple2",
  "v8::internal::SwissNameDictionary",
  "v8::internal::SyntheticModule",
  "v8::internal::TemplateObjectDescription",
  "v8::internal::TemplateInfo",
  "v8::internal::FunctionTemplateRareData",
  "v8::internal::FunctionTemplateInfo",
  "v8::internal::ObjectTemplateInfo",
  "v8::internal::TurbofanType",
  "v8::internal::TurbofanBitsetType",
  "v8::internal::TurbofanUnionType",
  "v8::internal::TurbofanRangeType",
  "v8::internal::TurbofanHeapConstantType",
  "v8::internal::TurbofanOtherNumberConstantType",
  "v8::internal::TurboshaftType",
  "v8::internal::TurboshaftWord32Type",
  "v8::internal::TurboshaftWord32RangeType",
  "v8::internal::TurboshaftWord32SetType",
  "v8::internal::TurboshaftWord64Type",
  "v8::internal::TurboshaftWord64RangeType",
  "v8::internal::TurboshaftWord64SetType",
  "v8::internal::TurboshaftFloat64Type",
  "v8::internal::TurboshaftFloat64RangeType",
  "v8::internal::TurboshaftFloat64SetType",
  "v8::internal::InternalClass",
  "v8::internal::SmiPair",
  "v8::internal::SmiBox",
  "v8::internal::ExportedSubClassBase",
  "v8::internal::ExportedSubClass",
  "v8::internal::AbstractInternalClass",
  "v8::internal::AbstractInternalClassSubclass1",
  "v8::internal::AbstractInternalClassSubclass2",
  "v8::internal::InternalClassWithSmiElements",
  "v8::internal::InternalClassWithStructElements",
  "v8::internal::ExportedSubClass2",
  "v8::internal::SortState",
  "v8::internal::JSV8BreakIterator",
  "v8::internal::JSCollator",
  "v8::internal::JSDateTimeFormat",
  "v8::internal::JSDisplayNames",
  "v8::internal::JSDurationFormat",
  "v8::internal::JSListFormat",
  "v8::internal::JSLocale",
  "v8::internal::JSNumberFormat",
  "v8::internal::JSPluralRules",
  "v8::internal::JSRelativeTimeFormat",
  "v8::internal::JSSegmentIterator",
  "v8::internal::JSSegmenter",
  "v8::internal::JSSegments",
  "v8::internal::WasmApiFunctionRef",
  "v8::internal::WasmFunctionData",
  "v8::internal::WasmExportedFunctionData",
  "v8::internal::WasmJSFunctionData",
  "v8::internal::WasmCapiFunctionData",
  "v8::internal::WasmResumeData",
  "v8::internal::WasmIndirectFunctionTable",
  "v8::internal::WasmContinuationObject",
  "v8::internal::WasmSuspenderObject",
  "v8::internal::WasmExceptionTag",
  "v8::internal::WasmModuleObject",
  "v8::internal::WasmTableObject",
  "v8::internal::WasmMemoryObject",
  "v8::internal::WasmGlobalObject",
  "v8::internal::WasmTagObject",
  "v8::internal::AsmWasmData",
  "v8::internal::WasmTypeInfo",
  "v8::internal::WasmObject",
  "v8::internal::WasmStruct",
  "v8::internal::WasmArray",
  "v8::internal::WasmStringViewIter",
};

const d::ClassList kObjectClassList {
  sizeof(kObjectClassNames) / sizeof(const char*),
  kObjectClassNames,
};
}  // namespace debug_helper_internal
}  // namespace internal
}  // namespace v8
