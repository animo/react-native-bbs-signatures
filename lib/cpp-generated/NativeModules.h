/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * @generated by codegen project: GenerateModuleH.js
 */

#pragma once

#include <ReactCommon/TurboModule.h>

namespace facebook {
namespace react {
class JSI_EXPORT BbsSignaturesCxxSpecJSI : public TurboModule {
public:
  BbsSignaturesCxxSpecJSI(std::shared_ptr<CallInvoker> jsInvoker);
  virtual double multiply(jsi::Runtime &rt, double a, double b) = 0;
};

} // namespace react
} // namespace facebook
