#include <jsi/jsilib.h>
#include "TurboModuleUtils.h"
#include "react-native-bbs-signatures.h"

using namespace facebook;
using namespace react;

void TurboModuleUtils::installTurboModule(jsi::Runtime &rt, std::shared_ptr<CallInvoker> jsCallInvoker) {
    // Register the turboModule as a pointer
    std::shared_ptr<NativeBbsSignatures> turboModule = std::make_shared<NativeBbsSignatures>(jsCallInvoker);

    // Register IndyVdrCxx instance as global.`NAME`
    rt.global().setProperty(rt, name, jsi::Object::createFromHostObject(rt, turboModule));
}

void TurboModuleUtils::handleError(jsi::Runtime &rt, ExternError *error) {
    int error_code = int(error->code);
    printf("error code: %d\n",error_code);
    
    if (error_code == 0) return;
    
    // TODO: how can we reformat the error message
    throw jsi::JSError(rt, error->message);
};

void TurboModuleUtils::callback(uintptr_t result, uint32_t code) {
    State *s = reinterpret_cast<State*>(result);
    jsi::Function *cb = &s->cb;
    jsi::Runtime *rt = reinterpret_cast<jsi::Runtime*>(s->rt);

    cb->call(*rt, int(code));
}

void TurboModuleUtils::callbackWithResponse(uintptr_t result, uint32_t code, const char* response) {
    State *s = reinterpret_cast<State*>(result);
    jsi::Function *cb = &s->cb;
    jsi::Runtime *rt = reinterpret_cast<jsi::Runtime*>(s->rt);
    
    cb->call(*rt, int(code), response);
}

template <>
std::string TurboModuleUtils::jsiToValue<std::string>(jsi::Runtime &rt, jsi::Value value, bool optional) {
    // We return an std::string() because we cannot return a nullptr.
    if ((value.isNull() || value.isUndefined()) && optional) return std::string();
  
    if (value.isString()) return value.asString(rt).utf8(rt);

    throw jsi::JSError(rt, "Value is not of type string");
}

template <>
int64_t TurboModuleUtils::jsiToValue<int64_t>(jsi::Runtime &rt, jsi::Value value, bool optional) {
    // We return -1 here as rust interprets this as the optional value was not given.
    if ((value.isNull() || value.isUndefined()) && optional) return -1;

    if (value.isNumber()) return value.asNumber();

    throw jsi::JSError(rt, "Value is not of type number");
}

template <>
uint64_t TurboModuleUtils::jsiToValue<uint64_t>(jsi::Runtime &rt, jsi::Value value, bool optional) {
    // We return -1 here as rust interprets this as the optional value was not given.
    if ((value.isNull() || value.isUndefined()) && optional) return -1;

    if (value.isNumber()) return value.asNumber();

    throw jsi::JSError(rt, "Value is not of type number");
}

template <>
int32_t TurboModuleUtils::jsiToValue<int32_t>(jsi::Runtime &rt, jsi::Value value, bool optional) {
    // We return -1 here as rust interprets this as the optional value was not given.
    if ((value.isNull() || value.isUndefined()) && optional) return -1;

    if (value.isNumber()) return value.asNumber();

    throw jsi::JSError(rt, "Value is not of type number");
}

template <>
uint32_t TurboModuleUtils::jsiToValue<uint32_t>(jsi::Runtime &rt, jsi::Value value, bool optional) {
    // We return -1 here as rust interprets this as the optional value was not given.
    if ((value.isNull() || value.isUndefined()) && optional) return -1;

    if (value.isNumber()) return value.asNumber();

    throw jsi::JSError(rt, "Value is not of type number");
}

template <>
ByteArray TurboModuleUtils::jsiToValue<ByteArray>(jsi::Runtime &rt, jsi::Value value, bool optional) {
    if (optional) return ByteArray {0,0};
    
    if (value.isObject() && value.asObject(rt).isArrayBuffer(rt)) {
        jsi::ArrayBuffer array_buffer = value.getObject(rt).getArrayBuffer(rt);
        
        return ByteArray {
            array_buffer.size(rt),
            array_buffer.data(rt)
        };
    }

    throw jsi::JSError(rt, "Value is not of type ByteArray");
}

template <>
uint8_t TurboModuleUtils::jsiToValue<uint8_t>(jsi::Runtime &rt, jsi::Value value, bool optional) {
    // We return -1 here as rust interprets this as the optional value was not given.
    if ((value.isNull() || value.isUndefined()) && optional) return -1;

    if (value.isNumber()) return value.asNumber();

    throw jsi::JSError(rt, "Value is not of type number");
}

jsi::ArrayBuffer TurboModuleUtils::bytebufferToArrayBuffer(jsi::Runtime &rt, ByteBuffer *bb) {
    const uint8_t* buffer = bb->data;
    auto size = bb->len;
    auto end = buffer + (size * sizeof(uint8_t));
    std::vector<uint8_t> vector(buffer, end);
    auto array = TypedArray<TypedArrayKind::Uint8Array>(rt, vector);
    return array.getArrayBuffer(rt);
}

jsi::Object TurboModuleUtils::structureBlsKeyPair(jsi::Runtime &rt, jsi::ArrayBuffer public_key, jsi::ArrayBuffer secret_key) {
    jsi::Object object = jsi::Object(rt);
    object.setProperty(rt, "publicKey", public_key);
    object.setProperty(rt, "secretKey", secret_key);
    return object;
}
