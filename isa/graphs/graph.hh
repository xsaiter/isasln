#pragma once

#include <string>
#include <vector>
#include <memory>
#include <list>
#include <map>
#include <set>
#include <algorithm>

namespace isa {
enum class directed_t { directed, undirected, bidirected };

template <class Vertex, directed_t directed> struct edge_t {
  edge_t() {}
  edge_t(const Vertex &src_, const Vertex &dest_, int w_ = 0)
      : src(src_), dest(dest_), w(w_) {}
  Vertex src, dest;
  int w;
  directed_t is_directed = directed;

  friend bool operator==(const edge_t<Vertex, directed> &lhs,
                         const edge_t<Vertex, directed> &rhs) {
    return (lhs.src == rhs.src && lhs.dest == rhs.dest) ||
           (directed == directed_t::undirected && lhs.src == rhs.dest &&
            lhs.dest == rhs.src);
  }

  friend bool operator!=(const edge_t<Vertex, directed> &lhs,
                         const edge_t<Vertex, directed> &rhs) {
    return !(lhs == rhs);
  }
};

template <class T> using edge_list_s = std::list<T>;

template <class Pair> struct first_t {
  typename Pair::first_type operator()(const Pair &p) const { return p.first; }
};

template <class Map> auto first(const Map &) {
  return first_t<typename Map::value_type>();
}

template <class Vertex, directed_t directed = directed_t::undirected,
          template <class> class EdgeList = edge_list_s>
class graph_t {
public:
  using edge_s = edge_t<Vertex, directed>;
  using edges_s = EdgeList<edge_s>;
  using edges_ptr_s = typename std::shared_ptr<edges_s>;
  using adj_s = typename std::map<Vertex, edges_ptr_s>;
  using adj_const_iter_s = typename adj_s::const_iterator;
  using vertex_s = Vertex;

  graph_t() {}
  graph_t(const graph_t &) = delete;
  graph_t &operator=(const graph_t &) = delete;

  std::size_t v() const { return adj_.size(); }
  std::size_t e() const { return e_; }
  adj_const_iter_s beg() const { return adj_.begin(); }
  adj_const_iter_s end() const { return adj_.end(); }
  adj_const_iter_s find(const Vertex &v) const { return adj_.find(v); }

  void add_vertex(const Vertex &v) { add_vertex_impl(v); }

  void add_edge(const Vertex &src, const Vertex &dest, int w = 0) {
    edges_ptr_s p_src = add_vertex_impl(src);
    edges_ptr_s p_dest = add_vertex_impl(dest);

    if (directed == directed_t::directed) {
      if (not_exists_edge(p_src, dest)) {
        p_src->emplace_back(src, dest, w);
        ++e_;
      }
    } else if (directed == directed_t::undirected) {
      if (not_exists_edge(p_src, dest) && not_exists_edge(p_dest, src)) {
        p_src->emplace_back(src, dest, w);
        p_dest->emplace_back(dest, src, w);
        ++e_;
      }
    }
  }

  std::vector<Vertex> get_all_vertices() const {
    std::vector<Vertex> res;
    std::transform(beg(), end(), std::back_inserter(res), first(adj_));
    return res;
  }

  std::vector<edge_s> get_all_edges() const {
    std::vector<edge_s> res;
    std::for_each(beg(), end(), [&](const auto &p) {
      std::copy_if(p.second->begin(), p.second->end(), std::back_inserter(res),
                   [&](const auto &e) {
                     return std::find(res.begin(), res.end(), e) == res.end();
                   });
    });
    return res;
  }

  std::vector<Vertex> get_neighbors(const Vertex &v) const {
    std::vector<Vertex> res;
    auto i = find(v);
    if (i != end()) {
      std::transform(i->second->begin(), i->second->end(),
                     std::back_inserter(res),
                     [](const auto &e) { return e.dest; });
    }
    return res;
  }

  std::vector<edge_s> get_incident_edges(const Vertex &v) const {
    std::vector<edge_s> res;
    auto i = find(v);
    if (i != end()) {
      std::copy(i->second->begin(), i->second->end(), std::back_inserter(res));
    }
    return res;
  }

  void create_map(std::map<Vertex, std::size_t> &map) const {
    auto vertices = get_all_vertices();
    const std::size_t n = vertices.size();
    for (std::size_t i = 0; i < n; ++i) {
      map.insert(std::make_pair(vertices[i], i));
    }
  }

private:
  std::size_t e_ = 0;
  adj_s adj_;

  inline bool not_exists_edge(const edges_ptr_s edges, const Vertex &v) const {
    return std::find_if(edges->begin(), edges->end(), [&](const edge_s &e) {
      return e.dest == v;
    }) == edges->end();
  }

  inline edges_ptr_s add_vertex_impl(const Vertex &v) {
    auto i = find(v);
    if (i != end()) {
      return i->second;
    }
    auto ptr(std::make_shared<edges_s>());
    adj_.insert(std::make_pair(v, ptr));
    return ptr;
  }
};
}
