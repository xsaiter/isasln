#pragma once

#include <memory>
#include <string>
#include <vector>

namespace isa::str {
class AhoCorasick {
public:
  explicit AhoCorasick(const std::vector<std::string> &patterns);

  struct Result {
    Result(const std::string &pattern_, std::size_t end_)
        : pattern(pattern_), end(end_) {}
    std::string pattern;
    std::size_t end;
  };

  std::vector<Result> search(const std::string &text) const;

private:
  struct Node;
  using NodePtr = std::shared_ptr<Node>;

  struct Node {
    char c;
    unsigned int n;
    NodePtr parent;
    std::vector<NodePtr> children;
    NodePtr failure;
    bool has_output;
    std::string output;
  };

  std::vector<std::string> patterns_;
  NodePtr root_;

  void build_machine();
  void build_go();
  void build_failure();
  NodePtr next_state(NodePtr node, char c) const;
  NodePtr make_node(char c, unsigned int n, NodePtr parent) const;
  void append(std::vector<Result> &result, NodePtr node, std::size_t end) const;
};
} // namespace isa::str
