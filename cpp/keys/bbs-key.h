#pragma once

#include "bbs.h"

struct BbsKey {
  ByteArray publicKey;
  uint32_t messageCount;
};
