#pragma once

namespace isa {
const unsigned FNV_32_PRIME = 0x01000193;

unsigned int FNV1aHash(char *buf) {
  unsigned int hval = 0x811c9dc5;

  while (*buf) {
    hval ^= (unsigned int)*buf++;
    hval *= FNV_32_PRIME;
  }

  return hval;
}
}
