#include <algorithm>
#include <queue>

#include "aho_corasick.hh"

aho_corasick_t::aho_corasick_t(const std::vector<std::string> &patterns)
    : patterns_(patterns), root_(std::make_shared<node_t>()) {
  build_machine();
}

aho_corasick_t::node_ptr_t aho_corasick_t::next_state(node_ptr_t node,
                                                      char c) const {
  auto found = std::find_if(node->children.begin(), node->children.end(),
                            [&](node_ptr_t n) { return n->c == c; });
  if (found != node->children.end()) {
    return *found;
  }
  return nullptr;
}

std::vector<aho_corasick_t::result_t>
aho_corasick_t::search(const std::string &text) const {
  std::vector<aho_corasick_t::result_t> result;

  node_ptr_t current = root_;
  const std::size_t len = text.size();

  for (std::size_t i = 0; i < len; ++i) {
    char c = text[i];
    bool loop = true;

    while (loop) {
      loop = false;
      node_ptr_t next = next_state(current, c);
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

void aho_corasick_t::build_machine() {
  build_go();
  build_failure();
}

void aho_corasick_t::build_go() {
  unsigned int n = 0;

  root_->n = n++;
  root_->parent = root_;

  for (const std::string &pattern : patterns_) {
    node_ptr_t current = root_;

    for (const char c : pattern) {
      node_ptr_t next = next_state(current, c);
      if (next) {
        current = next;
      } else {
        node_ptr_t node = make_node(c, n++, current);
        current->children.push_back(node);
        current = node;
      }
    }

    current->output.assign(pattern);
    current->has_output = true;
  }
}

aho_corasick_t::node_ptr_t
aho_corasick_t::make_node(char c, unsigned int n,
                          aho_corasick_t::node_ptr_t parent) const {
  node_ptr_t node = std::make_shared<node_t>();
  node->c = c;
  node->n = n;
  node->parent = parent;
  return node;
}

void aho_corasick_t::build_failure() {
  std::queue<node_ptr_t> q;
  bool first = true;

  node_ptr_t node = root_;
  q.push(node);

  while (!q.empty()) {
    node = q.front();
    q.pop();

    for (node_ptr_t child : node->children) {
      q.push(child);
      if (first) {
        child->failure = root_;
        first = false;
      } else {
        std::vector<node_ptr_t> path;

        node_ptr_t q = child;
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
          for (node_ptr_t p : q->children) {
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

void aho_corasick_t::append(std::vector<result_t> &result, node_ptr_t node,
                            std::size_t end) const {
  if (node->has_output) {
    result.emplace_back(node->output, end);
  }
}
