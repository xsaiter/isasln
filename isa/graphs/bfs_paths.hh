#pragma once

#include <queue>
#include <bitset>

#include "graph.hh"

namespace isa {
template <class Graph> class bfs_paths {
public:
  using Vertex = typename Graph::vertex_t;

  bfs_paths(const Graph &g, const Vertex &s)
      : g_(g), s_(s), marked_(g.v()), dist_(g.v()) {}

  void build() {
    std::vector<Vertex> vertices = g_.get_all_vertices();
    const std::size_t n = vertices.size();
    for (std::size_t i = 0; i < n; ++i) {
      map_.insert(std::make_pair(vertices[i], i));
    }

    std::queue<Vertex> q;
    q.push(s_);

    while (!q.empty()) {
      Vertex p = q.front();
      q.pop();

      std::vector<Vertex> nbrs = g_.get_neighbors(p);
      const std::size_t nn = nbrs.size();

      for (std::size_t j = 0; j < nn; ++j) {
        std::size_t x = map_[nbrs[j]];
        if (!marked_[x]) {
          dist_[x] = dist_[map_[p]] + 1;
          marked_[x] = true;
          q.push(nbrs[j]);
        }
      }
    }
  }

  std::size_t get_dist_to(const Vertex &v) { return dist_[map_[v]]; }

private:
  const Graph &g_;
  Vertex s_;
  std::map<Vertex, std::size_t> map_;
  std::vector<bool> marked_;
  std::vector<std::size_t> dist_;
};
}
