#include <HostObject.h>
#include <algorithm>
#include <vector>

TurboModuleHostObject::TurboModuleHostObject(jsi::Runtime &rt) { return; }

FunctionMap TurboModuleHostObject::functionMapping(jsi::Runtime &rt) {
  FunctionMap fMap;
  fMap.insert(std::make_tuple("sign", &nativeBbsSignatures::sign));
  fMap.insert(std::make_tuple("verify", &nativeBbsSignatures::verify));
  fMap.insert(
      std::make_tuple("createProof", &nativeBbsSignatures::createProof));
  fMap.insert(
      std::make_tuple("verifyProof", &nativeBbsSignatures::verifyProof));
  fMap.insert(std::make_tuple("generateBls12381G1KeyPair",
                              &nativeBbsSignatures::generateBls12381G1KeyPair));
  fMap.insert(std::make_tuple("generateBls12381G2KeyPair",
                              &nativeBbsSignatures::generateBls12381G2KeyPair));
  fMap.insert(
      std::make_tuple("bls12381toBbs", &nativeBbsSignatures::bls12381toBbs));
  return fMap;
}

jsi::Function TurboModuleHostObject::call(jsi::Runtime &rt, const char *name,
                                          Cb cb) {
  return jsi::Function::createFromHostFunction(
      rt, jsi::PropNameID::forAscii(rt, name), 1,
      [this, cb](jsi::Runtime &rt, const jsi::Value &thisValue,
                 const jsi::Value *arguments, size_t count) -> jsi::Value {
        const jsi::Value *val = &arguments[0];
        turboModuleUtility::assertValueIsObject(rt, val);
        return (*cb)(rt, val->getObject(rt));
      });
};

std::vector<jsi::PropNameID>
TurboModuleHostObject::getPropertyNames(jsi::Runtime &rt) {
  auto fMap = TurboModuleHostObject::functionMapping(rt);
  std::vector<jsi::PropNameID> result;
  for (FunctionMap::iterator it = fMap.begin(); it != fMap.end(); ++it) {
    result.push_back(jsi::PropNameID::forUtf8(rt, it->first));
  }

  return result;
}

jsi::Value TurboModuleHostObject::get(jsi::Runtime &rt,
                                      const jsi::PropNameID &propNameId) {
  auto propName = propNameId.utf8(rt);
  auto fMap = TurboModuleHostObject::functionMapping(rt);
  for (FunctionMap::iterator it = fMap.begin(); it != fMap.end(); ++it) {
    if (it->first == propName) {
      Cb cb = it->second;
      return TurboModuleHostObject::call(rt, it->first, cb);
    }
  }
  // TODO: throw error
  return jsi::Value::undefined();
}
