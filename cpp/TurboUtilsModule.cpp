#include "TurboUtilsModule.h"
#include "react-native-bbs-signatures.h"
#include <jsi/jsilib.h>

const char *name = "_bbsSignatures";

using namespace facebook;
using namespace react;

namespace utils {
void installTurboModule(jsi::Runtime &rt,
                        std::shared_ptr<CallInvoker> jsCallInvoker) {

  // Register the turboModule as a pointer
  std::shared_ptr<NativeBbsSignatures> turboModule =
      std::make_shared<NativeBbsSignatures>(jsCallInvoker);

  // Register UtilsTurboModule instance as global.`NAME`
  rt.global().setProperty(rt, name,
                          jsi::Object::createFromHostObject(rt, turboModule));
}
} // namespace utils
