#pragma once

#include <ReactCommon/TurboModule.h>
#include <jsi/jsi.h>
#include "bbs.h"
#include "TypedArray.h"

using namespace facebook;
using namespace react;

// state of a callback function
struct State {
    jsi::Function cb;
    // TODO: can we not make this a void pointer
    void* rt;
    
    State(jsi::Function *cb_): cb(std::move(*cb_)) {}
};

const char *name = "_bbsSignatures";

class TurboModuleUtils {
public:
    // Install the Turbomodule
    static void installTurboModule(jsi::Runtime &runtime, std::shared_ptr<CallInvoker> jsCallInvoker);

    // Handles an error from within the module and sends it back to the js side
    static void handleError(jsi::Runtime &rt, ExternError *error);

    // Converts jsi values to regular cpp values
    template <typename T>
    static T jsiToValue(jsi::Runtime &rt, jsi::Value value, bool optional = false);

    // Callback function that makes the host function async
    static void callback(uintptr_t result, uint32_t code);
    
    // Callback function that makes the host function async with response from rust side
    static void callbackWithResponse(uintptr_t result, uint32_t code, const char* response);
    
    static jsi::ArrayBuffer bytebufferToArrayBuffer(jsi::Runtime &rt, ByteBuffer *bb);
    
    static jsi::Object structureBlsKeyPair(jsi::Runtime &rt, jsi::ArrayBuffer public_key, jsi::ArrayBuffer secret_key);
};
