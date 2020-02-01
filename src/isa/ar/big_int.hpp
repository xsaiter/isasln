#include <string>
#include <vector>

namespace isa::ar {
class Big_int {
public:
  using type = unsigned int;
  bool operator>(const Big_int &bi);

private:
  std::vector<int> v_;
  bool sign_;
};
} // namespace isa::ar