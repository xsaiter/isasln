#include <algorithm>
#include <queue>

#include "aho_corasick.hh"

namespace isa {
namespace strings {
aho_corasick_s::aho_corasick_s(const std::vector<std::string> &patterns)
    : patterns_(patterns), root_(std::make_shared<node_s>()) {
  build_machine();
}

std::vector<aho_corasick_s::result_s>
aho_corasick_s::search(const std::string &text) const {
  std::vector<aho_corasick_s::result_s> result;

  node_ptr_u current = root_;
  const std::size_t len = text.size();

  for (std::size_t i = 0; i < len; ++i) {
    char c = text[i];
    bool loop = true;

    while (loop) {
      loop = false;
      node_ptr_u next = next_state(current, c);
      if (next) {
        current = next;
        append(result, current, i);
        if (current->failure) {
          append(result, current->failure, i);
        }
      } else {
        if (current != root_) {
          loop = true;
          current = current->failure;
        }
      }
    }
  }

  return result;
}

void aho_corasick_s::build_machine() {
  build_go();
  build_failure();
}

void aho_corasick_s::build_go() {
  unsigned int n = 0;

  root_->n = n++;
  root_->parent = root_;

  for (const std::string &pattern : patterns_) {
    node_ptr_u current = root_;

    for (const char c : pattern) {
      node_ptr_u next = next_state(current, c);
      if (next) {
        current = next;
      } else {
        node_ptr_u node = make_node(c, n++, current);
        current->children.push_back(node);
        current = node;
      }
    }

    current->output.assign(pattern);
    current->has_output = true;
  }
}

void aho_corasick_s::build_failure() {
  std::queue<node_ptr_u> q;
  bool first = true;

  node_ptr_u node = root_;
  q.push(node);

  while (!q.empty()) {
    node = q.front();
    q.pop();

    for (node_ptr_u child : node->children) {
      q.push(child);
      if (first) {
        child->failure = root_;
        first = false;
      } else {
        std::vector<node_ptr_u> path;

        node_ptr_u q = child;
        path.push_back(q);

        while (q->parent != q) {
          q = q->parent;
          path.push_back(q);
        }

        path.erase(path.end() - 1);
        std::reverse(path.begin(), path.end());

        q = root_;
        const std::size_t path_len = path.size();

        for (std::size_t i = 0; i < path_len; ++i) {
          for (node_ptr_u p : q->children) {
            if (p != path[i] && p->c == path[i]->c) {
              q = p;
              break;
            }
          }
        }

        child->failure = q;
      }
    }
  }

  root_->failure = root_;
}

aho_corasick_s::node_ptr_u aho_corasick_s::next_state(node_ptr_u node,
                                                      char c) const {
  auto i = std::find_if(node->children.begin(), node->children.end(),
                        [&](const node_ptr_u &n) { return n->c == c; });
  if (i != node->children.end()) {
    return *i;
  }
  return nullptr;
}

aho_corasick_s::node_ptr_u
aho_corasick_s::make_node(char c, unsigned int n,
                          aho_corasick_s::node_ptr_u parent) const {
  node_ptr_u node = std::make_shared<node_s>();
  node->c = c;
  node->n = n;
  node->parent = parent;
  return node;
}

void aho_corasick_s::append(std::vector<result_s> &result, node_ptr_u node,
                            std::size_t end) const {
  if (node->has_output) {
    result.emplace_back(node->output, end);
  }
}
}
}
