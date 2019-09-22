#include <functional>
#include <sstream>

#include "vigenere_cipher.hpp"

namespace isa::crypto {
static const char A = 'A';
static const int N = 26;

static inline int idx(char c) { return c - A; }
static inline char sym(int i) { return static_cast<char>(A + i); }

static char char_to_encrypt(char x, char y) {
  return sym((idx(x) + idx(y)) % N);
}

static char char_to_decrypt(char x, char y) {
  auto k = idx(y) - idx(x);
  if (k < 0) {
    k = N + k;
  }
  return sym(k);
}

static std::string prepare_key(const std::string &key, int should_size) {
  const auto size = key.size();
  const auto mod = should_size % size;
  const auto n = should_size / size;
  std::ostringstream ss;
  for (auto i = 0; i < n; ++i) {
    ss << key;
  }
  ss << key.substr(0, mod);
  return ss.str();
}

using fn_u = std::function<char(char, char)>;

static std::string map(const std::string &s, const std::string &key, fn_u fn) {
  const int size = s.size();
  const std::string prepared_key = prepare_key(key, size);
  std::ostringstream ss;
  for (int i = 0; i < size; ++i) {
    ss << fn(prepared_key[i], s[i]);
  }
  return ss.str();
}

std::string vigenere_encrypt(const std::string &s, const std::string &key) {
  return map(s, key, char_to_encrypt);
}

std::string vigenere_decrypt(const std::string &s, const std::string &key) {
  return map(s, key, char_to_decrypt);
}
} // namespace isa::crypto
