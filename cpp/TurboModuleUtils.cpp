#include "TurboModuleUtils.h"
#include <jsi/jsilib.h>

using namespace facebook;
using namespace react;

void TurboModuleUtils::installTurboModule(
    jsi::Runtime &rt, std::shared_ptr<CallInvoker> jsCallInvoker) {
  // Register the turboModule as a pointer
  std::shared_ptr<NativeBbsSignatures> turboModule =
      std::make_shared<NativeBbsSignatures>(jsCallInvoker);

  // Register IndyVdrCxx instance as global.`NAME`
  rt.global().setProperty(rt, name,
                          jsi::Object::createFromHostObject(rt, turboModule));
}

void TurboModuleUtils::handleError(jsi::Runtime &rt, ExternError *error) {
  int error_code = int(error->code);
  printf("error code: %d\n", error_code);

  if (error_code == 0)
    return;

  // TODO: how can we reformat the error message
  throw jsi::JSError(rt, error->message);
};

template <>
std::string TurboModuleUtils::jsiToValue<std::string>(jsi::Runtime &rt,
                                                      jsi::Value value,
                                                      bool optional) {
  // We return an std::string() because we cannot return a nullptr.
  if ((value.isNull() || value.isUndefined()) && optional)
    return std::string();

  if (value.isString())
    return value.asString(rt).utf8(rt);

  throw jsi::JSError(rt, "Value is not of type string");
}

template <>
int64_t TurboModuleUtils::jsiToValue<int64_t>(jsi::Runtime &rt,
                                              jsi::Value value, bool optional) {
  // We return -1 here as rust interprets this as the optional value was not
  // given.
  if ((value.isNull() || value.isUndefined()) && optional)
    return -1;

  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
uint64_t TurboModuleUtils::jsiToValue<uint64_t>(jsi::Runtime &rt,
                                                jsi::Value value,
                                                bool optional) {
  // We return -1 here as rust interprets this as the optional value was not
  // given.
  if ((value.isNull() || value.isUndefined()) && optional)
    return -1;

  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
int32_t TurboModuleUtils::jsiToValue<int32_t>(jsi::Runtime &rt,
                                              jsi::Value value, bool optional) {
  // We return -1 here as rust interprets this as the optional value was not
  // given.
  if ((value.isNull() || value.isUndefined()) && optional)
    return -1;

  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
uint32_t TurboModuleUtils::jsiToValue<uint32_t>(jsi::Runtime &rt,
                                                jsi::Value value,
                                                bool optional) {
  // We return -1 here as rust interprets this as the optional value was not
  // given.
  if ((value.isNull() || value.isUndefined()) && optional)
    return -1;

  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
ByteArray TurboModuleUtils::jsiToValue<ByteArray>(jsi::Runtime &rt,
                                                  jsi::Value value,
                                                  bool optional) {
  if (optional)
    return ByteArray{0, 0};

  if (value.isObject() && value.asObject(rt).isArrayBuffer(rt)) {
    jsi::ArrayBuffer array_buffer = value.getObject(rt).getArrayBuffer(rt);

    return ByteArray{array_buffer.size(rt), array_buffer.data(rt)};
  }

  throw jsi::JSError(rt, "Value is not of type ByteArray");
}

template <>
std::vector<ByteArray> TurboModuleUtils::jsiToValue<std::vector<ByteArray>>(
    jsi::Runtime &rt, jsi::Value value, bool optional) {
  if (optional)
    return {};

  if (value.isObject() && value.asObject(rt).isArray(rt)) {
    std::vector<ByteArray> vec = {};
    jsi::Array arr = value.asObject(rt).asArray(rt);
    auto length = arr.length(rt);
    for (int i = 0; i < length; i++) {
      jsi::Value element = arr.getValueAtIndex(rt, i);
      if (element.isObject() && element.asObject(rt).isArrayBuffer(rt)) {
        jsi::ArrayBuffer arrayBuffer = element.asObject(rt).getArrayBuffer(rt);
        vec.push_back(ByteArray{arrayBuffer.size(rt), arrayBuffer.data(rt)});
      } else {
        throw jsi::JSError(rt, "Value in array not of type ByteArray");
      }
    }
    return vec;
  }
  throw jsi::JSError(rt, "Value is not of type ByteArray[]");
}

template <>
uint8_t TurboModuleUtils::jsiToValue<uint8_t>(jsi::Runtime &rt,
                                              jsi::Value value, bool optional) {
  // We return -1 here as rust interprets this as the optional value was not
  // given.
  if ((value.isNull() || value.isUndefined()) && optional)
    return -1;

  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

jsi::ArrayBuffer TurboModuleUtils::byteBufferToArrayBuffer(jsi::Runtime &rt,
                                                           ByteBuffer bb) {
  const uint8_t *buffer = bb.data;
  auto size = bb.len;
  auto end = buffer + (size * sizeof(uint8_t));
  std::vector<uint8_t> vector(buffer, end);
  auto array = TypedArray<TypedArrayKind::Uint8Array>(rt, vector);
  return array.getArrayBuffer(rt);
}

jsi::ArrayBuffer TurboModuleUtils::byteArrayToArrayBuffer(jsi::Runtime &rt,
                                                           ByteArray ba) {
  const uint8_t *buffer = ba.data;
  auto size = ba.length;
  auto end = buffer + (size * sizeof(uint8_t));
  std::vector<uint8_t> vector(buffer, end);
  auto array = TypedArray<TypedArrayKind::Uint8Array>(rt, vector);
  return array.getArrayBuffer(rt);
}
