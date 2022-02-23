// class "interface" of the generated code. This has to be copied over from
// `../lib/cpp-generated/NativeModules.h`

#include "../lib/cpp-generated/NativeModules.h"
#include "NativeModules.h"
#include "TurboModuleUtils.h"
#include <ReactCommon/TurboModule.h>
#include <jsi/jsi.h>
#include <jsi/jsilib.h>

namespace facebook {
namespace react {

class NativeBbsSignatures : public BbsSignaturesCxxSpecJSI {
public:
  NativeBbsSignatures(std::shared_ptr<CallInvoker> jsInvoker);
  double multiply(jsi::Runtime &rt, double a, double b);
};

} // namespace react
} // namespace facebook
