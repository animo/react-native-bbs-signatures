#pragma once

#include <include/bbs.h>

#include <HostObject.h>
#include <jsi/jsi.h>

using namespace facebook;

namespace turboModuleUtility {

void registerTurboModule(jsi::Runtime &rt);

void assertValueIsObject(jsi::Runtime &rt, jsi::Value &val);

template <typename T>
T jsiToValue(jsi::Runtime &rt, jsi::Value value, bool optional = false);

void handleError(jsi::Runtime &rt, ExternError *error);

jsi::ArrayBuffer byteBufferToArrayBuffer(jsi::Runtime &rt, ByteBuffer bb);
jsi::ArrayBuffer byteArrayToArrayBuffer(jsi::Runtime &rt, ByteArray ba);

}
