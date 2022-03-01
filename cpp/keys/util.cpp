#include "util.h"

// Untested
void handleExternError(ExternError *err) {
  if (err->code == 0) { return; }

  throw err->message;
}

// TODO: How safe is this conversion?
ByteBuffer byteArrayToByteBuffer(ByteArray ba) {
  uintptr_t length = ba.length;
  const uint8_t *data = ba.data;
  // int64_t len;
  // uint8_t *data;

  return ByteBuffer {(long long)length, (uint8_t*)data};
}

// TODO: How safe is this conversion?
ByteArray byteBufferToByteArray(ByteBuffer bb) {
  auto length = bb.len;
  auto data = bb.data;

  return ByteArray {(unsigned long)length, (const uint8_t*)data};
}
