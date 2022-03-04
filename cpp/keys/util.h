#pragma once

#include "bbs.h"

void handleExternError(ExternError *err);

ByteBuffer byteArrayToByteBuffer(ByteArray ba);

ByteArray byteBufferToByteArray(ByteBuffer bb);
