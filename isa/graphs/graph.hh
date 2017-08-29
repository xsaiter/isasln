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
  adj_const_iter_t end() const { return adj_.end(); }

  void add_vertex(const Vertex &v) { add_vertex_impl(v); }

  void add_edge(const Vertex &src, const Vertex &dest) {
    edges_ptr_t pv = add_vertex_impl(src);
    edges_ptr_t pw = add_vertex_impl(dest);

    if (directed == directed_t::directed) {
      if (not_exists_edge(pv, dest)) {
        pv->emplace_back(src, dest);
        ++e_;
      }
    } else if (directed == directed_t::undirected) {
      if (not_exists_edge(pv, dest) && not_exists_edge(pw, src)) {
        pv->emplace_back(src, dest);
        pw->emplace_back(dest, src);
        ++e_;
      }
    }
  }

  std::vector<Vertex> get_all_vertices() const {
    std::vector<Vertex> res;
    for (adj_const_iter_t i = adj_.begin(); i != adj_.end(); ++i) {
      res.push_back(i->first);
      ;
    }
    return res;
  }

  std::vector<edge_t_> get_edges() const {
    std::vector<edge_t_> res;

    for (adj_const_iter_t i = adj_.begin(); i != adj_.end(); ++i) {
      edges_ptr_t p = (*i).second;
      for (typename edges_t::iterator j = p->begin(); j != p->end(); ++j) {
        if (std::find(res.begin(), res.end(), *j) == res.end()) {
          res.push_back(*j);
        }
      }
    }

    return res;
  }

  std::vector<Vertex> get_neighbors(const Vertex &v) const {
    std::vector<Vertex> res;

    auto it = adj_.find(v);
    if (it == adj_.end()) {
      return res;
    }

    edges_ptr_t p = (*it).second;
    for (typename edges_t::iterator j = p->begin(); j != p->end(); ++j) {
      res.push_back((*j).dest);
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
    adj_const_iter_t found = adj_.find(v);
    if (found != adj_.end()) {
      return (*found).second;
    }
    edges_ptr_t ptr(new edges_t);
    adj_.insert(std::make_pair(v, ptr));
    return ptr;
  }
};
}
