#pragma once

#include <queue>

#include "graph.hh"

namespace isa {
template <class Graph> class bfs_paths_s {
public:
  using vertex_u = typename Graph::vertex_u;

  bfs_paths_s(const Graph &g, const vertex_u &s)
      : g_(g), s_(s), marked_(g.v(), false), dist_(g.v(), 0) {
    g_.create_map(map_);
  }

  void build() {
    std::queue<vertex_u> q;
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

  bool has_path_to(const vertex_u &v) { return marked_[map_[v]]; }
  std::size_t get_dist_to(const vertex_u &v) { return dist_[map_[v]]; }

private:
  const Graph &g_;
  const vertex_u s_;
  std::map<vertex_u, std::size_t> map_;
  std::vector<bool> marked_;
  std::vector<std::size_t> dist_;
};

template <class Graph> class bfs_paths_ss {
public:
  bfs_paths_ss(const Graph &g, int s)
      : g_(g), s_(s), marked_(g.nv(), false), dist_(g.nv(), 0) {}

  void build() {
    std::queue<int> q;
    q.push(s_);

    while (!q.empty()) {
      auto p = q.front();
      q.pop();

      auto nbr = g_.neighbors(p);
      const std::size_t nn = nbr.size();

      for (std::size_t j = 0; j < nn; ++j) {
        auto x = nbr[j];
        if (!marked_[x]) {
          dist_[x] = dist_[p] + 1;
          marked_[x] = true;
          q.push(nbr[j]);
        }
      }
    }
  }

  bool has_path_to(int v) { return marked_[v]; }
  std::size_t get_dist_to(int v) { return dist_[v]; }

private:
  const Graph &g_;
  int s_;
  std::vector<bool> marked_;
  std::vector<std::size_t> dist_;
};
}
