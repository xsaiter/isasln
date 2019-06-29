#pragma once

#include <string>

namespace isa::crypto {
std::string vigenere_encrypt(const std::string &s, const std::string &key);
std::string vigenere_decrypt(const std::string &s, const std::string &key);
} // namespace isa::crypto
