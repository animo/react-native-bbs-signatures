#include <turboModuleUtility.h>

namespace turboModuleUtility {

void registerTurboModule(jsi::Runtime &rt) {
  // Create a TurboModuleRustHostObject
  auto instance = std::make_shared<TurboModuleHostObject>(rt);
  // Create a JS equivalent object of the instance
  jsi::Object jsInstance = jsi::Object::createFromHostObject(rt, instance);
  // Register the object on global
  rt.global().setProperty(rt, "_bbs_signatures", std::move(jsInstance));
}

void assertValueIsObject(jsi::Runtime &rt, const jsi::Value *val) {
  val->asObject(rt);
}

void handleError(jsi::Runtime &rt, ExternError *error) {
  int error_code = int(error->code);

  if (error_code == 0)
    return;

  throw jsi::JSError(rt, error->message);
};

template <>
uint8_t jsiToValue<uint8_t>(jsi::Runtime &rt, jsi::Value value, bool optional) {
  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
std::string jsiToValue<std::string>(jsi::Runtime &rt, jsi::Value value,
                                    bool optional) {
  if ((value.isNull() || value.isUndefined()) && optional)
    return std::string();

  if (value.isString())
    return value.asString(rt).utf8(rt);

  throw jsi::JSError(rt, "Value is not of type string");
}

template <>
int64_t jsiToValue<int64_t>(jsi::Runtime &rt, jsi::Value value, bool optional) {
  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
uint64_t jsiToValue<uint64_t>(jsi::Runtime &rt, jsi::Value value,
                              bool optional) {
  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
int32_t jsiToValue<int32_t>(jsi::Runtime &rt, jsi::Value value, bool optional) {
  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
uint32_t jsiToValue<uint32_t>(jsi::Runtime &rt, jsi::Value value,
                              bool optional) {
  if (value.isNumber())
    return value.asNumber();

  throw jsi::JSError(rt, "Value is not of type number");
}

template <>
ByteArray jsiToValue<ByteArray>(jsi::Runtime &rt, jsi::Value value,
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
std::vector<ByteArray> jsiToValue<std::vector<ByteArray>>(jsi::Runtime &rt,
                                                          jsi::Value value,
                                                          bool optional) {
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
std::vector<int32_t> jsiToValue<std::vector<int32_t>>(jsi::Runtime &rt,
                                                      jsi::Value value,
                                                      bool optional) {
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

jsi::ArrayBuffer byteArrayToArrayBuffer(jsi::Runtime &rt, ByteArray ba) {
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

jsi::ArrayBuffer byteBufferToArrayBuffer(jsi::Runtime &rt, ByteBuffer bb) {
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

} // namespace turboModuleUtility
