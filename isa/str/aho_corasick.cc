#include <algorithm>
#include <queue>

#include "aho_corasick.hh"

namespace isa::str {
AhoCorasick::AhoCorasick(const std::vector<std::string> &patterns)
    : patterns_(patterns), root_(std::make_shared<Node>()) {
  build_machine();
}

std::vector<AhoCorasick::Result>
AhoCorasick::search(const std::string &text) const {
  std::vector<AhoCorasick::Result> result;

  NodePtr current = root_;
  const std::size_t len = text.size();

  for (std::size_t i = 0; i < len; ++i) {
    char c = text[i];
    bool loop = true;

    while (loop) {
      loop = false;
      NodePtr next = next_state(current, c);
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

void AhoCorasick::build_machine() {
  build_go();
  build_failure();
}

void AhoCorasick::build_go() {
  unsigned int n = 0;

  root_->n = n++;
  root_->parent = root_;

  for (const std::string &pattern : patterns_) {
    NodePtr current = root_;

    for (const char c : pattern) {
      NodePtr next = next_state(current, c);
      if (next) {
        current = next;
      } else {
        NodePtr node = make_node(c, n++, current);
        current->children.push_back(node);
        current = node;
      }
    }

    current->output.assign(pattern);
    current->has_output = true;
  }
}

void AhoCorasick::build_failure() {
  std::queue<NodePtr> q;
  bool first = true;

  NodePtr node = root_;
  q.push(node);

  while (!q.empty()) {
    node = q.front();
    q.pop();

    for (NodePtr child : node->children) {
      q.push(child);
      if (first) {
        child->failure = root_;
        first = false;
      } else {
        std::vector<NodePtr> path;

        NodePtr q = child;
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
          for (NodePtr p : q->children) {
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

AhoCorasick::NodePtr AhoCorasick::next_state(NodePtr node,
                                                      char c) const {
  auto i = std::find_if(node->children.begin(), node->children.end(),
                        [&](const NodePtr &n) { return n->c == c; });
  if (i != node->children.end()) {
    return *i;
  }
  return nullptr;
}

AhoCorasick::NodePtr
AhoCorasick::make_node(char c, unsigned int n,
                          AhoCorasick::NodePtr parent) const {
  NodePtr node = std::make_shared<Node>();
  node->c = c;
  node->n = n;
  node->parent = parent;
  return node;
}

void AhoCorasick::append(std::vector<Result> &result, NodePtr node,
                            std::size_t end) const {
  if (node->has_output) {
    result.emplace_back(node->output, end);
  }
}
} // namespace isa::str
