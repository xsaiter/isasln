#pragma once

#include <string>
#include <vector>
#include <memory>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>

namespace isa {
enum class directed_s { directed, undirected, bidirected };

template <class Vertex, directed_s directed> struct edge_s {
  edge_s() {}
  edge_s(const Vertex &a_, const Vertex &b_, int w_ = 0)
      : a(a_), b(b_), w(w_) {}
  Vertex a, b;
  int w;
  directed_s is_directed = directed;

  friend bool operator==(const edge_s<Vertex, directed> &lhs,
                         const edge_s<Vertex, directed> &rhs) {
    return (lhs.a == rhs.a && lhs.b == rhs.b) ||
           (directed == directed_s::undirected && lhs.a == rhs.b &&
            lhs.b == rhs.a);
  }

  friend bool operator!=(const edge_s<Vertex, directed> &lhs,
                         const edge_s<Vertex, directed> &rhs) {
    return !(lhs == rhs);
  }
};

template <directed_s directed = directed_s::undirected> class graph_i_s {
public:
  using edge_u = edge_s<int, directed>;
  using edges_u = std::list<edge_u>;
  using adj_u = std::vector<edges_u>;

  explicit graph_i_s(std::size_t nv) : nv_(nv), ne_(0), adj_(nv_) {}

  int nv() const { return nv_; }
  int ne() const { return ne_; }

  void add_edge(int a, int b, int w = 0) {
    validate_vertex(a);
    validate_vertex(b);

    add_edge_impl(a, b, w);
    if (directed == directed_s::undirected) {
      add_edge_impl(b, a, w);
    }

    ++ne_;
  }

  std::vector<int> neighbors(int v) const {
    validate_vertex(v);
    std::vector<int> res;
    std::transform(adj_[v].begin(), adj_[v].end(), std::back_inserter(res),
                   [](const auto &e) { return e.b; });
    return res;
  }

  std::vector<edge_u> incident_edges(int v) const {
    validate_vertex(v);
    std::vector<edge_u> res;
    std::copy(adj_[v].begin(), adj_[v].end(), std::back_inserter(res));
    return res;
  }

private:
  int nv_;
  int ne_;
  adj_u adj_;

  void add_edge_impl(int a, int b, int w) {
    adj_[a].push_front(edge_u(a, b, w));
  }

  inline void validate_vertex(int v) const { assert(0 < v && v < nv_); }
};

namespace details {

template <class Pair> struct first_s {
  typename Pair::first_type operator()(const Pair &p) const { return p.first; }
};

template <class Map> auto first(const Map &) {
  return first_s<typename Map::value_type>();
}

} // details

template <class T> using edge_list_u = std::list<T>;

template <class Vertex, directed_s directed = directed_s::undirected,
          template <class> class EdgeList = edge_list_u>
class graph_s {
public:
  using vertex_u = Vertex;
  using edge_u = edge_s<vertex_u, directed>;
  using edges_u = EdgeList<edge_u>;
  using edges_ptr_u = typename std::shared_ptr<edges_u>;
  using adj_u = typename std::map<vertex_u, edges_ptr_u>;
  using adj_const_iter_u = typename adj_u::const_iterator;

  graph_s() {}
  graph_s(const graph_s &) = delete;
  graph_s &operator=(const graph_s &) = delete;

  std::size_t v() const { return adj_.size(); }
  std::size_t e() const { return e_; }
  adj_const_iter_u beg() const { return adj_.begin(); }
  adj_const_iter_u end() const { return adj_.end(); }
  adj_const_iter_u find(const vertex_u &v) const { return adj_.find(v); }

  void add_vertex(const vertex_u &v) { add_vertex_impl(v); }

  void add_edge(const vertex_u &a, const vertex_u &b, int w = 0) {
    edges_ptr_u a_ptr = add_vertex_impl(a);
    edges_ptr_u b_ptr = add_vertex_impl(b);

    if (directed == directed_s::directed) {
      if (not_exists_edge(a_ptr, b)) {
        a_ptr->emplace_back(a, b, w);
        ++e_;
      }
    } else if (directed == directed_s::undirected) {
      if (not_exists_edge(a_ptr, b) && not_exists_edge(b_ptr, a)) {
        a_ptr->emplace_back(a, b, w);
        b_ptr->emplace_back(b, a, w);
        ++e_;
      }
    }
  }

  std::vector<vertex_u> get_all_vertices() const {
    std::vector<vertex_u> res;
    std::transform(beg(), end(), std::back_inserter(res), details::first(adj_));
    return res;
  }

  std::vector<edge_u> get_all_edges() const {
    std::vector<edge_u> res;
    std::for_each(beg(), end(), [&](const auto &p) {
      std::copy_if(p.second->begin(), p.second->end(), std::back_inserter(res),
                   [&](const auto &e) {
                     return std::find(res.begin(), res.end(), e) == res.end();
                   });
    });
    return res;
  }

  std::vector<vertex_u> get_neighbors(const vertex_u &v) const {
    std::vector<vertex_u> res;
    auto i = find(v);
    if (i != end()) {
      std::transform(i->second->begin(), i->second->end(),
                     std::back_inserter(res),
                     [](const auto &e) { return e.b; });
    }
    return res;
  }

  std::vector<edge_u> get_incident_edges(const vertex_u &v) const {
    std::vector<edge_u> res;
    auto i = find(v);
    if (i != end()) {
      std::copy(i->second->begin(), i->second->end(), std::back_inserter(res));
    }
    return res;
  }

  void create_map(std::map<vertex_u, std::size_t> &map) const {
    auto vertices = get_all_vertices();
    const std::size_t n = vertices.size();
    for (std::size_t i = 0; i < n; ++i) {
      map.insert(std::make_pair(vertices[i], i));
    }
  }

private:
  std::size_t e_ = 0;
  adj_u adj_;

  inline bool not_exists_edge(const edges_ptr_u edges,
                              const vertex_u &v) const {
    return std::find_if(edges->begin(), edges->end(), [&](const edge_u &e) {
      return e.b == v;
    }) == edges->end();
  }

  inline edges_ptr_u add_vertex_impl(const vertex_u &v) {
    auto i = find(v);
    if (i != end()) {
      return i->second;
    }
    auto ptr = std::make_shared<edges_u>();
    adj_.insert(std::make_pair(v, ptr));
    return ptr;
  }
};
}
