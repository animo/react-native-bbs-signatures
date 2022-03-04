#include "util.h"

// TODO: Should we construct our own error struct with the code and message?
void handleExternError(ExternError *err) {
  if (err->code == 0) {
    return;
  }

  throw err->message;
}

// TODO: How safe is this conversion?
ByteBuffer byteArrayToByteBuffer(ByteArray ba) {
  uintptr_t length = ba.length;
  const uint8_t *data = ba.data;

  return ByteBuffer{(long long)length, (uint8_t *)data};
}

// TODO: How safe is this conversion?
ByteArray byteBufferToByteArray(ByteBuffer bb) {
  auto length = bb.len;
  auto data = bb.data;

  return ByteArray{(unsigned long)length, (const uint8_t *)data};
}
