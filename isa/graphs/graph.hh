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
  edge_t(const Vertex &src_, const Vertex &dest_) : src(src_), dest(dest_) {}
  Vertex src, dest;
  directed_t is_directed = directed;
};

template <class Vertex, directed_t directed>
bool operator==(const edge_t<Vertex, directed> &lhs,
                const edge_t<Vertex, directed> &rhs) {
  return lhs.src == rhs.src && lhs.dest == rhs.dest ||
         (directed == directed_t::undirected && lhs.src == rhs.dest &&
          lhs.dest == rhs.src);
}

template <class Vertex, directed_t directed>
bool operator!=(const edge_t<Vertex, directed> &lhs,
                const edge_t<Vertex, directed> &rhs) {
  return !(lhs == rhs);
}

template <class T> using edge_list_t = std::list<T>;

template <class Pair> struct first_t {
  typename Pair::first_type operator()(const Pair &p) const { return p.first; }
};

template <class Map> auto first(const Map &) {
  return first_t<typename Map::value_type>();
}

template <class Vertex, directed_t directed = directed_t::undirected,
          template <class> class EdgeList = edge_list_t>
class graph_t {
public:
  using edge_t_ = edge_t<Vertex, directed>;
  using edges_t = EdgeList<edge_t_>;
  using edges_ptr_t = typename std::shared_ptr<edges_t>;
  using adj_t = typename std::map<Vertex, edges_ptr_t>;
  using adj_const_iter_t = typename adj_t::const_iterator;
  using vertex_t = Vertex;

  graph_t() {}
  graph_t(const graph_t &) = delete;
  graph_t &operator=(const graph_t &) = delete;

  std::size_t v() const { return adj_.size(); }
  std::size_t e() const { return e_; }
  adj_const_iter_t find(const Vertex &v) const { return adj_.find(v); }
  adj_const_iter_t beg() const { return adj_.begin(); }
  adj_const_iter_t end() const { return adj_.end(); }

  void add_vertex(const Vertex &v) { add_vertex_impl(v); }

  void add_edge(const Vertex &src, const Vertex &dest) {
    edges_ptr_t p_src = add_vertex_impl(src);
    edges_ptr_t p_dest = add_vertex_impl(dest);

    if (directed == directed_t::directed) {
      if (not_exists_edge(p_src, dest)) {
        p_src->emplace_back(src, dest);
        ++e_;
      }
    } else if (directed == directed_t::undirected) {
      if (not_exists_edge(p_src, dest) && not_exists_edge(p_dest, src)) {
        p_src->emplace_back(src, dest);
        p_dest->emplace_back(dest, src);
        ++e_;
      }
    }
  }

  std::vector<Vertex> get_all_vertices() const {
    std::vector<Vertex> res;
    std::transform(beg(), end(), std::back_inserter(res), first(adj_));
    return res;
  }

  std::vector<edge_t_> get_all_edges() const {
    std::vector<edge_t_> res;

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

    auto i(find(v));
    if (i != end()) {
      std::transform((*i).second->begin(), (*i).second->end(),
                     std::back_inserter(res),
                     [](const auto &e) { return e.dest; });
    }

    return res;
  }

  std::vector<edge_t_> get_edges_for(const Vertex &v) const {
    std::vector<edge_t_> res;

    auto i(find(v));
    if (i != end()) {
      edges_ptr_t s = (*i).second;
      std::copy(s->begin(), s->end(), std::back_inserter(res));
    }

    return res;
  }

private:
  std::size_t e_ = 0;
  adj_t adj_;

  inline bool not_exists_edge(const edges_ptr_t edges, const Vertex &v) const {
    return std::find_if(edges->begin(), edges->end(), [&](const edge_t_ &e) {
      return e.dest == v;
    }) == edges->end();
  }

  inline edges_ptr_t add_vertex_impl(const Vertex &v) {
    auto i(find(v));
    if (i != end()) {
      return (*i).second;
    }
    edges_ptr_t ptr(std::make_shared<edges_t>());
    adj_.insert(std::make_pair(v, ptr));
    return ptr;
  }
};
}
