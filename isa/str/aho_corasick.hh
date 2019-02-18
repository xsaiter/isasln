#pragma once

#include <memory>
#include <string>
#include <vector>

namespace isa::str {
class aho_corasick_s {
public:
  explicit aho_corasick_s(const std::vector<std::string> &patterns);

  struct result_s {
    result_s(const std::string &pattern_, std::size_t end_)
        : pattern(pattern_), end(end_) {}
    std::string pattern;
    std::size_t end;
  };

  std::vector<result_s> search(const std::string &text) const;

private:
  struct node_s;
  using node_ptr_u = std::shared_ptr<node_s>;

  struct node_s {
    char c;
    unsigned int n;
    node_ptr_u parent;
    std::vector<node_ptr_u> children;
    node_ptr_u failure;
    bool has_output;
    std::string output;
  };

  std::vector<std::string> patterns_;
  node_ptr_u root_;

  void build_machine();

  void build_go();

  void build_failure();

  node_ptr_u next_state(node_ptr_u node, char c) const;

  node_ptr_u make_node(char c, unsigned int n, node_ptr_u parent) const;

  void append(std::vector<result_s> &result, node_ptr_u node,
              std::size_t end) const;
};
}
