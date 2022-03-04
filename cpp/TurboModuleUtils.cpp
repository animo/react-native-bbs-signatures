#include "TurboModuleUtils.h"

using namespace facebook;
using namespace react;

void TurboModuleUtils::installTurboModule(
    jsi::Runtime &rt, std::shared_ptr<CallInvoker> jsCallInvoker) {
  // Register the turboModule as a pointer
  std::shared_ptr<NativeBbsSignatures> turboModule =
      std::make_shared<NativeBbsSignatures>(jsCallInvoker);

  // Register bbsSignatures instance as global.`NAME`
  rt.global().setProperty(rt, "_bbsSignatures",
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
  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
uint64_t TurboModuleUtils::jsiToValue<uint64_t>(jsi::Runtime &rt,
                                                jsi::Value value,
                                                bool optional) {
  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
int32_t TurboModuleUtils::jsiToValue<int32_t>(jsi::Runtime &rt,
                                              jsi::Value value, bool optional) {
  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
uint32_t TurboModuleUtils::jsiToValue<uint32_t>(jsi::Runtime &rt,
                                                jsi::Value value,
                                                bool optional) {
  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
ByteArray TurboModuleUtils::jsiToValue<ByteArray>(jsi::Runtime &rt,
                                                  jsi::Value value,
                                                  bool optional) {
  if (value.isObject() && value.asObject(rt).isArrayBuffer(rt)) {
    jsi::ArrayBuffer arrayBuffer = value.getObject(rt).getArrayBuffer(rt);
    return ByteArray{arrayBuffer.size(rt), arrayBuffer.data(rt)};
  }

  if (optional)
    return ByteArray{0, 0};

  throw jsi::JSError(rt, "Value is not of type ByteArray");
}

template <>
std::vector<ByteArray> TurboModuleUtils::jsiToValue<std::vector<ByteArray>>(
    jsi::Runtime &rt, jsi::Value value, bool optional) {
  if (value.isObject() && value.asObject(rt).isArray(rt)) {
    std::vector<ByteArray> vec = {};
    jsi::Array arr = value.asObject(rt).asArray(rt);
    size_t length = arr.length(rt);
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
  if (optional)
    return {};

  throw jsi::JSError(rt, "Value is not of type []");
}

template <>
std::vector<int32_t> TurboModuleUtils::jsiToValue<std::vector<int32_t>>(
    jsi::Runtime &rt, jsi::Value value, bool optional) {
  if (value.isObject() && value.asObject(rt).isArray(rt)) {
    std::vector<int32_t> vec = {};
    jsi::Array arr = value.asObject(rt).asArray(rt);
    size_t length = arr.length(rt);
    for (int i = 0; i < length; i++) {
      jsi::Value element = arr.getValueAtIndex(rt, i);
      if (element.isNumber()) {
        vec.push_back(element.asNumber());
      } else {
        throw jsi::JSError(rt, "Value in array not of type int64_t");
      }
    }
    return vec;
  }
  if (optional)
    return {};

  throw jsi::JSError(rt, "Value is not of type []");
}

template <>
uint8_t TurboModuleUtils::jsiToValue<uint8_t>(jsi::Runtime &rt,
                                              jsi::Value value, bool optional) {
  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

jsi::ArrayBuffer TurboModuleUtils::byteArrayToArrayBuffer(jsi::Runtime &rt,
                                                          ByteArray ba) {
  const uint8_t *buffer = ba.data;
  size_t length = ba.length;
  jsi::Function arrayBufferCtor =
      rt.global().getPropertyAsFunction(rt, "ArrayBuffer");
  jsi::ArrayBuffer arrayBuffer =
      arrayBufferCtor.callAsConstructor(rt, (int)length)
          .getObject(rt)
          .getArrayBuffer(rt);
  memcpy(arrayBuffer.data(rt), buffer, length);
  return arrayBuffer;
}

jsi::ArrayBuffer TurboModuleUtils::byteBufferToArrayBuffer(jsi::Runtime &rt,
                                                           ByteBuffer bb) {
  const uint8_t *buffer = bb.data;
  size_t length = bb.len;
  jsi::Function arrayBufferCtor =
      rt.global().getPropertyAsFunction(rt, "ArrayBuffer");
  jsi::ArrayBuffer arrayBuffer =
      arrayBufferCtor.callAsConstructor(rt, (int)length)
          .getObject(rt)
          .getArrayBuffer(rt);
  memcpy(arrayBuffer.data(rt), buffer, length);
  return arrayBuffer;
}
