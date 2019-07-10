#include <algorithm>
#include <queue>

#include "aho_corasick.hh"

namespace isa::str {
Aho_corasick::Aho_corasick(const std::vector<std::string> &patterns)
    : patterns_(patterns), root_(std::make_shared<Node>()) {
  build_machine();
}

std::vector<Aho_corasick::Result>
Aho_corasick::search(const std::string &text) const {
  std::vector<Aho_corasick::Result> result;

  Node_ptr current = root_;
  const std::size_t len = text.size();

  for (std::size_t i = 0; i < len; ++i) {
    char c = text[i];
    bool loop = true;

    while (loop) {
      loop = false;
      Node_ptr next = next_state(current, c);
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

void Aho_corasick::build_machine() {
  build_go();
  build_failure();
}

void Aho_corasick::build_go() {
  unsigned int n = 0;

  root_->n = n++;
  root_->parent = root_;

  for (const std::string &pattern : patterns_) {
    Node_ptr current = root_;

    for (const char c : pattern) {
      Node_ptr next = next_state(current, c);
      if (next) {
        current = next;
      } else {
        Node_ptr node = make_node(c, n++, current);
        current->children.push_back(node);
        current = node;
      }
    }

    current->output.assign(pattern);
    current->has_output = true;
  }
}

void Aho_corasick::build_failure() {
  std::queue<Node_ptr> q;
  bool first = true;

  Node_ptr node = root_;
  q.push(node);

  while (!q.empty()) {
    node = q.front();
    q.pop();

    for (Node_ptr child : node->children) {
      q.push(child);
      if (first) {
        child->failure = root_;
        first = false;
      } else {
        std::vector<Node_ptr> path;

        Node_ptr q = child;
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
          for (Node_ptr p : q->children) {
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

Aho_corasick::Node_ptr Aho_corasick::next_state(Node_ptr node,
                                                      char c) const {
  auto i = std::find_if(node->children.begin(), node->children.end(),
                        [&](const Node_ptr &n) { return n->c == c; });
  if (i != node->children.end()) {
    return *i;
  }
  return nullptr;
}

Aho_corasick::Node_ptr
Aho_corasick::make_node(char c, unsigned int n,
                          Aho_corasick::Node_ptr parent) const {
  Node_ptr node = std::make_shared<Node>();
  node->c = c;
  node->n = n;
  node->parent = parent;
  return node;
}

void Aho_corasick::append(std::vector<Result> &result, Node_ptr node,
                            std::size_t end) const {
  if (node->has_output) {
    result.emplace_back(node->output, end);
  }
}
} // namespace isa::str
