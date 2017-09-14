#pragma once

#include <string>
#include <vector>
#include <memory>
#include <list>
#include <map>
#include <set>
#include <algorithm>

namespace isa {
enum class directed_s { directed, undirected, bidirected };

template <class Vertex, directed_s directed> struct edge_s {
  edge_s() {}
  edge_s(const Vertex &src_, const Vertex &dest_, int w_ = 0)
      : src(src_), dest(dest_), w(w_) {}
  Vertex src, dest;
  int w;
  directed_s is_directed = directed;

  friend bool operator==(const edge_s<Vertex, directed> &lhs,
                         const edge_s<Vertex, directed> &rhs) {
    return (lhs.src == rhs.src && lhs.dest == rhs.dest) ||
           (directed == directed_s::undirected && lhs.src == rhs.dest &&
            lhs.dest == rhs.src);
  }

  friend bool operator!=(const edge_s<Vertex, directed> &lhs,
                         const edge_s<Vertex, directed> &rhs) {
    return !(lhs == rhs);
  }
};

template <class Pair> struct first_s {
  typename Pair::first_type operator()(const Pair &p) const { return p.first; }
};

template <class Map> auto first(const Map &) {
  return first_s<typename Map::value_type>();
}

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

  void add_edge(const vertex_u &src, const vertex_u &dest, int w = 0) {
    edges_ptr_u p_src = add_vertex_impl(src);
    edges_ptr_u p_dest = add_vertex_impl(dest);

    if (directed == directed_s::directed) {
      if (not_exists_edge(p_src, dest)) {
        p_src->emplace_back(src, dest, w);
        ++e_;
      }
    } else if (directed == directed_s::undirected) {
      if (not_exists_edge(p_src, dest) && not_exists_edge(p_dest, src)) {
        p_src->emplace_back(src, dest, w);
        p_dest->emplace_back(dest, src, w);
        ++e_;
      }
    }
  }

  std::vector<vertex_u> get_all_vertices() const {
    std::vector<vertex_u> res;
    std::transform(beg(), end(), std::back_inserter(res), first(adj_));
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
                     [](const auto &e) { return e.dest; });
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
      return e.dest == v;
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
