/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

namespace facebook {
namespace jsi {

inline ArrayBuffer Object::getArrayBuffer(Runtime &runtime) && {
  // Disabling this assert check does not break anything but it does make the
  // program work
  //  assert(runtime.isArrayBuffer(*this));
  (void)runtime; // when assert is disabled we need to mark this as used
  Runtime::PointerValue *value = ptr_;
  ptr_ = nullptr;
  return ArrayBuffer(value);
}

} // namespace jsi
} // namespace facebook
