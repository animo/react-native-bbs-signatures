#include <HostObject.h>

TurboModuleHostObject::TurboModuleHostObject(jsi::Runtime &rt) {
  return;
}

jsi::Function TurboModuleHostObject::call(jsi::Runtime &rt, const char* name, jsi::Value (*ptr) (jsi::Runtime &rt, jsi::Object options)) {
    return jsi::Function::createFromHostFunction(rt,
                                                 jsi::PropNameID::forAscii(rt, name),
                                                 1,
                                                 [this, ptr](jsi::Runtime& rt,
                                                        const jsi::Value& thisValue,
                                                        const jsi::Value* arguments,
                                                        size_t count) -> jsi::Value {
      // TODO: safe assert that there is an object as the first param
      return (*ptr) (rt, arguments[0].getObject(rt));
    });
};

std::vector<jsi::PropNameID> TurboModuleHostObject::getPropertyNames(jsi::Runtime &rt) {
  std::vector<jsi::PropNameID> result;
  result.push_back(jsi::PropNameID::forUtf8(rt, std::string("sign")));
   result.push_back(jsi::PropNameID::forUtf8(rt, std::string("verify")));
   result.push_back(jsi::PropNameID::forUtf8(rt, std::string("createProof")));
   result.push_back(jsi::PropNameID::forUtf8(rt, std::string("verifyProof")));
   result.push_back(jsi::PropNameID::forUtf8(rt, std::string("generateBls12381G1KeyPair")));
   result.push_back(jsi::PropNameID::forUtf8(rt, std::string("generateBls12381G2KeyPair")));
   result.push_back(jsi::PropNameID::forUtf8(rt, std::string("bls12381toBbs")));
  return result;
}

jsi::Value TurboModuleHostObject::get(jsi::Runtime &rt, const jsi::PropNameID &propNameId) {
  auto propName = propNameId.utf8(rt);
  const char* propNameCString = propName.c_str();

  // TODO: tuple
  if (propName == "sign") {
    auto cb = &nativeBbsSignatures::sign;
    return TurboModuleHostObject::call(rt, propNameCString, cb);
  } 
  if (propName == "verify") {
    auto cb = &nativeBbsSignatures::verify;
    return TurboModuleHostObject::call(rt, propNameCString, cb);
  } 
  if (propName == "createProof") {
    auto cb = &nativeBbsSignatures::createProof;
    return TurboModuleHostObject::call(rt, propNameCString, cb);
  } 
  if (propName == "verifyProof") {
    auto cb = &nativeBbsSignatures::verifyProof;
    return TurboModuleHostObject::call(rt, propNameCString, cb);
  } 
  if (propName == "generateBls12381G1KeyPair") {
    auto cb = &nativeBbsSignatures::generateBls12381G1KeyPair;
    return TurboModuleHostObject::call(rt, propNameCString, cb);
  } 
  if (propName == "generateBls12381G2KeyPair") {
    auto cb = &nativeBbsSignatures::generateBls12381G2KeyPair;
    return TurboModuleHostObject::call(rt, propNameCString, cb);
  } 
  if (propName == "bls12381toBbs") {
    auto cb = &nativeBbsSignatures::bls12381toBbs;
    return TurboModuleHostObject::call(rt, propNameCString, cb);
  } 

  return jsi::Value::undefined();
}
