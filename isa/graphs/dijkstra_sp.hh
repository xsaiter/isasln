#pragma once

#include <queue>

#include "graph.hh"

namespace isa {
template <typename Graph> class dijkstra_sp {
public:
  using Vertex = typename Graph::vertex_t;

  dijkstra_sp(const Graph &g, const Vertex &s)
      : g_(g), s_(s), marked_(g.v()), dist_(g.v(), INT64_MAX) {
    create_map();
  }

private:
  const Graph &g_;
  Vertex s_;
  std::vector<bool> marked_;
  std::vector<std::size_t> dist_;
  std::map<Vertex, std::size_t> map_;

  void create_map() {
    auto vers = g_.get_all_vertices();
    const auto n = vers.size();
    for (auto i = 0; i < n; ++i) {
      map_.insert(std::make_pair(vers[i], i));
    }
  }
};
}
