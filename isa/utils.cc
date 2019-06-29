#include "utils.hh"

namespace isa {
static unsigned int FNV1aHash(char *buf) {
  unsigned int hval = 0x811c9dc5;
  const unsigned FNV_32_PRIME = 0x01000193;
  while (*buf) {
    hval ^= (unsigned int)*buf++;
    hval *= FNV_32_PRIME;
  }
  return hval;
}

int fnv_hash(const std::string &s) { return FNV1aHash((char *)s.c_str()); }
} // namespace isa
