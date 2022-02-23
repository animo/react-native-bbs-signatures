#include <ReactCommon/TurboModule.h>
#include <jsi/jsi.h>

namespace utils {
using namespace facebook;
using namespace react;

// Install the Turbomodule
void installTurboModule(jsi::Runtime &runtime,
                        std::shared_ptr<CallInvoker> jsCallInvoker);
} // namespace utils
