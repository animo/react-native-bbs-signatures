#pragma once

#include <nativeBbsSignatures.h>

#include <turboModuleUtility.h>
#include <jsi/jsi.h>

using namespace facebook;

class JSI_EXPORT TurboModuleHostObject : public jsi::HostObject {
public:
  TurboModuleHostObject(jsi::Runtime &rt);
  jsi::Function call(jsi::Runtime &rt, const char* name, jsi::Value (*ptr) (jsi::Runtime &rt, jsi::Object options));

public:
  jsi::Value get(jsi::Runtime& rt, const jsi::PropNameID& name) override;
  std::vector<jsi::PropNameID> getPropertyNames(jsi::Runtime& rt) override;
};
