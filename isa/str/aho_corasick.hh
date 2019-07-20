#pragma once

#include <memory>
#include <string>
#include <vector>

namespace isa::str {
class Aho_Corasick {
public:
  explicit Aho_Corasick(const std::vector<std::string> &patterns);

  struct Result {
    Result(const std::string &pattern_, std::size_t end_)
        : pattern(pattern_), end(end_) {}
    std::string pattern;
    std::size_t end;
  };

  std::vector<Result> search(const std::string &text) const;

private:
  struct Node;
  using Node_ptr = std::shared_ptr<Node>;

  struct Node {
    char c;
    unsigned int n;
    Node_ptr parent;
    std::vector<Node_ptr> children;
    Node_ptr failure;
    bool has_output;
    std::string output;
  };

  std::vector<std::string> patterns_;
  Node_ptr root_;

  void build_machine();
  void build_go();
  void build_failure();
  Node_ptr next_state(Node_ptr node, char c) const;
  Node_ptr make_node(char c, unsigned int n, Node_ptr parent) const;
  void append(std::vector<Result> &result, Node_ptr node,
              std::size_t end) const;
};
} // namespace isa::str
