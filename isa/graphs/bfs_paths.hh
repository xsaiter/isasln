#pragma once

#include <queue>

#include "graph.hh"

namespace isa {
template <class Graph> class bfs_paths {
public:
  using vertex_t = typename Graph::vertex_t;

  bfs_paths(const Graph &g, const vertex_t &s)
      : g_(g), s_(s), marked_(g.v(), false), dist_(g.v(), 0) {
    g_.create_map(map_);
  }

  void build() {
    std::queue<vertex_t> q;
    q.push(s_);

    while (!q.empty()) {
      auto p = q.front();
      q.pop();

      auto nbr = g_.get_neighbors(p);
      const std::size_t nn = nbr.size();

      for (std::size_t j = 0; j < nn; ++j) {
        auto x = map_[nbr[j]];
        if (!marked_[x]) {
          dist_[x] = dist_[map_[p]] + 1;
          marked_[x] = true;
          q.push(nbr[j]);
        }
      }
    }
  }

  bool has_path_to(const vertex_t &v) { return marked_[map_[v]]; }
  std::size_t get_dist_to(const vertex_t &v) { return dist_[map_[v]]; }

private:
  const Graph &g_;
  const vertex_t s_;
  std::map<vertex_t, std::size_t> map_;
  std::vector<bool> marked_;
  std::vector<std::size_t> dist_;
};
}
