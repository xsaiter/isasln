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

enum class directed_t { directed, undirected, bidirected };

template <class Vertex, directed_t directed> struct edge_t {
  edge_t(const Vertex &v_, const Vertex &w_) : v(v_), w(w_) {}
  Vertex v, w;
  directed_t is_directed = directed;
};

template <class Vertex, directed_t directed>
bool operator==(const edge_t<Vertex, directed> &lhs,
                const edge_t<Vertex, directed> &rhs) {
  return lhs.v == rhs.v && lhs.w == rhs.w;
}

template <class Vertex, directed_t directed>
bool operator!=(const edge_t<Vertex, directed> &lhs,
                const edge_t<Vertex, directed> &rhs) {
  return !(lhs == rhs);
}

template <class T> using edge_list_t = std::list<T>;

template <class Vertex, directed_t directed = directed_t::undirected,
          template <class> class EdgeList = edge_list_t>
class graph_t {
public:
  using edge_t_ = edge_t<Vertex, directed>;
  using edges_t = EdgeList<edge_t_>;
  using edges_ptr_t = typename std::shared_ptr<edges_t>;
  using adj_t = typename std::map<Vertex, edges_ptr_t>;
  using adj_iter_t = typename adj_t::iterator;
  using adj_const_iter_t = typename adj_t::const_iterator;

  std::size_t v() const { return adj_.size(); }
  std::size_t e() const { return e_; }
  adj_const_iter_t find(const Vertex &v) const { return adj_.find(v); }
  adj_const_iter_t end() const { return adj_.end(); }

  void add_vertex(const Vertex &v) { add_vertex_impl(v); }

  void add_edge(const Vertex &v, const Vertex &w) {
    edges_ptr_t pv = add_vertex_impl(v);
    edges_ptr_t pw = add_vertex_impl(w);

    if (directed == directed_t::directed) {
      if (not_exists_edge(pv, w)) {
        pv->emplace_back(v, w);
        ++e_;
      } else if (directed == directed_t::undirected) {
        if (not_exists_edge(pv, w) && not_exists_edge(pw, v)) {
          pv->emplace_back(v, w);
          ++e_;
        }
      }
    }
  }

  std::vector<edge_t_> get_edges() const {
    std::vector<edge_t_> res;

    for (adj_const_iter_t i = adj_.begin(); i != adj_.end(); ++i) {
      edges_ptr_t p = (*i).second;
      for (typename edges_t::iterator j = p->begin(); j != p->end(); ++j) {
        if (std::find(res.begin(), res.end(), (*j)) == res.end()) {
          res.push_back(*j);
        }
      }
    }

    return res;
  }

private:
  std::size_t e_ = 0;
  adj_t adj_;

  inline bool not_exists_edge(const edges_ptr_t edges, const Vertex &v) const {
    return std::find_if(edges->begin(), edges->end(), [&](const edge_t_ &e) {
      return e.w == v;
    }) == edges->end();
  }

  inline edges_ptr_t add_vertex_impl(const Vertex &v) {
    adj_iter_t found = adj_.find(v);
    if (found != adj_.end()) {
      return (*found).second;
    }
    edges_ptr_t ptr(new edges_t);
    adj_.insert(std::make_pair(v, ptr));
    return ptr;
  }
};
}
}
