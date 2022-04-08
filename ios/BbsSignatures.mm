#import "turboModuleUtility.h"

#import "BbsSignatures.h"
#import <React/RCTBridge+Private.h>
#import <jsi/jsi.h>

using namespace facebook;

@implementation BbsSignatures

RCT_EXPORT_MODULE()

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(install)
{
    RCTBridge* bridge = [RCTBridge currentBridge];
    RCTCxxBridge* cxxBridge = (RCTCxxBridge*)bridge;
    if (cxxBridge == nil) {
        return @false;
    }
    
    jsi::Runtime* jsiRuntime = (jsi::Runtime*) cxxBridge.runtime;
    if (jsiRuntime == nil) {
        return @false;
    }
    turboModuleUtility::registerTurboModule(*jsiRuntime);
    return @true;
}

@end
