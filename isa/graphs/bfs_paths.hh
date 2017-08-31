#pragma once

#include <queue>

#include "graph.hh"

namespace isa {
template <class Graph> class bfs_paths {
public:
  using Vertex = typename Graph::vertex_t;

  bfs_paths(const Graph &g, const Vertex &s)
      : g_(g), s_(s), marked_(g.v(), false), dist_(g.v(), 0) {}

  void build() {
    auto vertices = g_.get_all_vertices();
    const auto n = vertices.size();
    for (auto i = 0; i < n; ++i) {
      map_.insert(std::make_pair(vertices[i], i));
    }

    std::queue<Vertex> q;
    q.push(s_);

    while (!q.empty()) {
      auto p = q.front();
      q.pop();

      auto nbr = g_.get_neighbors(p);
      const auto nn = nbr.size();

      for (auto j = 0; j < nn; ++j) {
        auto x = map_[nbr[j]];
        if (!marked_[x]) {
          dist_[x] = dist_[map_[p]] + 1;
          marked_[x] = true;
          q.push(nbr[j]);
        }
      }
    }
  }

  bool has_path_to(const Vertex &v) { return marked_[map_[v]]; }
  std::size_t get_dist_to(const Vertex &v) { return dist_[map_[v]]; }

private:
  const Graph &g_;
  Vertex s_;
  std::map<Vertex, std::size_t> map_;
  std::vector<bool> marked_;
  std::vector<std::size_t> dist_;
};
}
