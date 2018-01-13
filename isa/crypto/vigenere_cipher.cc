#include <sstream>

#include "vigenere_cipher.hh"

namespace isa {
namespace crypto {
char char_to_encrypt(char x, char y) {
  int i = x - 'A';
  int j = y - 'A';
  return (char)('A' + (i + j) % 26);
}

/*
char char_to_decrypt(char x, char y) {
  int i = a - 'A';
  return a;
}*/

std::string prepare_key(const std::string &key, int should_size) {
  const int size = key.size();
  if (size > should_size) {
    return key.substr(0, should_size);
  }

  const int mod = should_size % size;
  const int n = should_size / size;

  std::ostringstream ss;

  for (int i = 0; i < n; ++i) {
    ss << key;
  }

  ss << key.substr(0, mod);

  return ss.str();
}

std::string vigenere_encrypt(const std::string &text, const std::string &key) {
  const int size = text.size();
  const std::string prepared_key = prepare_key(key, size);

  std::ostringstream ss;

  for (int i = 0; i < size; ++i) {
    ss << char_to_encrypt(prepared_key[i], text[i]);
  }

  return ss.str();
}

std::string vigenere_decrypt(const std::string &encrypted,
                             const std::string &key) {}
}
}
