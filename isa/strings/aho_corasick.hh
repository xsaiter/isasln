#pragma once

#include <vector>
#include <string>
#include <memory>

class aho_corasick_t {
public:
  explicit aho_corasick_t(const std::vector<std::string> &patterns);

  struct result_t {
    result_t(const std::string &pattern_, std::size_t end_)
        : pattern(pattern_), end(end_) {}
    std::string pattern;
    std::size_t end;
  };

  std::vector<result_t> search(const std::string &text) const;

private:
  struct node_t;
  using node_ptr_s = std::shared_ptr<node_t>;

  struct node_t {
    char c;
    unsigned int n;
    node_ptr_s parent;
    std::vector<node_ptr_s> children;
    node_ptr_s failure;
    bool has_output;
    std::string output;
  };

  std::vector<std::string> patterns_;
  node_ptr_s root_;

  void build_machine();
  void build_go();
  void build_failure();
  node_ptr_s next_state(node_ptr_s node, char c) const;
  node_ptr_s make_node(char c, unsigned int n, node_ptr_s parent) const;
  void append(std::vector<result_t> &result, node_ptr_s node,
              std::size_t end) const;
};
