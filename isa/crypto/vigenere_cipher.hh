#pragma once

#include <string>

namespace isa {
namespace crypto {
std::string vigenere_encrypt(const std::string &s, const std::string &key);
std::string vigenere_decrypt(const std::string &s, const std::string &key);
}
}
