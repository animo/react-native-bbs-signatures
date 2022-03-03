#pragma once

#include "TypedArray.h"
#include "bbs.h"
#include "react-native-bbs-signatures.h"

using namespace facebook;
using namespace react;

class TurboModuleUtils {
public:
  // Install the Turbomodule
  static void installTurboModule(jsi::Runtime &runtime,
                                 std::shared_ptr<CallInvoker> jsCallInvoker);

  // Handles an error from within the module and sends it back to the js side
  static void handleError(jsi::Runtime &rt, ExternError *error);

  // Converts jsi values to regular cpp values
  template <typename T>
  static T jsiToValue(jsi::Runtime &rt, jsi::Value value,
                      bool optional = false);

  // Callback function that makes the host function async
  static void callback(uintptr_t result, uint32_t code);

  // Callback function that makes the host function async with response from
  // rust side
  static void callbackWithResponse(uintptr_t result, uint32_t code,
                                   const char *response);

  static jsi::ArrayBuffer byteBufferToArrayBuffer(jsi::Runtime &rt,
                                                  ByteBuffer bb);

  static jsi::ArrayBuffer byteArrayToArrayBuffer(jsi::Runtime &rt,
                                                 ByteArray ba);

  static jsi::Object structureBlsKeyPair(jsi::Runtime &rt,
                                         jsi::ArrayBuffer public_key,
                                         jsi::ArrayBuffer secret_key);
};
