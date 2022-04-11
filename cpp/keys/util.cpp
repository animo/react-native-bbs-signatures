#include "util.h"

void handleExternError(ExternError *err) {
  if (err->code == 0) {
    return;
  }

  throw err->message;
}

ByteBuffer byteArrayToByteBuffer(ByteArray ba) {
  uintptr_t length = ba.length;
  const uint8_t *data = ba.data;

  return ByteBuffer{(long long)length, (uint8_t *)data};
}

ByteArray byteBufferToByteArray(ByteBuffer bb) {
  auto length = bb.len;
  auto data = bb.data;

  return ByteArray{(unsigned long)length, (const uint8_t *)data};
}
