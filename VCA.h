#pragma once

// TODO

#include "Common.h"

class VCA
{
public:
  inline static int8_t clock(int8_t a, uint8_t k)
  {
    return highByte(a * (k << 1));
  }
};
