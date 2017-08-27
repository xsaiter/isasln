#pragma once

#include <string>
#include <vector>
#include <memory>
#include <list>
#include <map>
#include <set>
#include <algorithm>

namespace isa {
namespace graphs {

template <typename Vertex> struct edge_t {
  edge_t(const Vertex &v1_, const Vertex &v2_) : v1(v1_), v2(v2_) {}
  Vertex v1, v2;
};

template <typename Vertex>
bool operator==(const edge_t<Vertex> &lhs, const edge_t<Vertex> &rhs) {
  return lhs.v1 == rhs.v1 && lhs.v2 == rhs.v2;
}

template <typename Vertex>
bool operator!=(const edge_t<Vertex> &lhs, const edge_t<Vertex> &rhs) {
  return !(lhs == rhs);
}

template <typename Vertex, bool directed = false> class graph_t {
public:
  using edges_t = typename std::vector<edge_t<Vertex>>;
  using edges_ptr_t = typename std::shared_ptr<edges_t>;
  using adj_t = typename std::map<Vertex, edges_ptr_t>;
  using adj_iter_t = typename adj_t::iterator;
  using adj_const_iter_t = typename adj_t::const_iterator;

  std::size_t v() const { return v_; }
  std::size_t e() const { return e_; }
  adj_const_iter_t find(const Vertex &v) const { return adj_.find(v); }
  adj_const_iter_t end() const { return adj_.end(); }

  bool add_edge(const Vertex &v1, const Vertex &v2) {
    add_edge_impl(v1, v2);
    if (directed) {
      add_edge_impl(v2, v1);
    }
    ++e_;
    return true;
  }

  std::vector<edge_t<Vertex>> get_edges() const {
    std::vector<edge_t<Vertex>> res;

    for (adj_const_iter_t i = adj_.begin(); i != adj_.end(); ++i) {
      edges_ptr_t p = (*i).second;
      for (typename edges_t::iterator j = p->begin(); j != p->end(); ++j) {
        if (std::find(res.begin(), res.end(), (*j)) == res.end()) {
          res.push_back((*j));
        }
      }
    }

    return res;
  }

private:
  bool directed_;
  std::size_t v_;
  std::size_t e_;
  adj_t adj_;

  void add_edge_impl(const Vertex &v1, const Vertex &v2) {
    edges_ptr_t edges_ptr = get_or_add_vertex(v1);

    edge_t<Vertex> e(v1, v2);

    auto edge_found = std::find(edges_ptr->begin(), edges_ptr->end(), e);
    if (edge_found == edges_ptr->end()) {
      edges_ptr->push_back(e);
    }
  }

  inline edges_ptr_t get_or_add_vertex(const Vertex &v) {
    adj_iter_t found = adj_.find(v);
    if (found != adj_.end()) {
      return (*found).second;
    }

    edges_ptr_t p(new edges_t);
    adj_.insert(std::make_pair(v, p));
    ++v_;

    return p;
  }
};
}
}
