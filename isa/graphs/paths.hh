#pragma once

#include <queue>

#include "graph.hh"

namespace isa {

template <class Graph> class graph_paths_s {
public:
  graph_paths_s(const Graph &g, int s)
      : g_(g), s_(s), marked_(g.nv(), false), dist_(g.nv(), 0) {}

  void bfs() {
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

  void dfs() { dfs(s_); }

  bool has_path_to(int v) { return marked_[v]; }
  std::size_t get_dist_to(int v) { return dist_[v]; }

private:
  const Graph &g_;
  int s_;
  std::vector<bool> marked_;
  std::vector<std::size_t> dist_;

  void dfs(int i) {
    marked_[i] = true;

    auto nbr = g_.neighbors(i);

    for (auto x : nbr) {
      if (!marked_[x]) {
        dist_[x] = dist_[i] + 1;
        dfs(x);
      }
    }
  }
};
}
