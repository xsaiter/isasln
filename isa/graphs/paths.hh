#pragma once

#include <queue>

#include "graph.hh"

namespace isa {

struct graph_paths_s {
  graph_paths_s(int nv_, int s_)
      : nv(nv_), s(s_), marked(nv, false), dist(nv, 0) {}

  bool has_path_to(int v) { return marked[v]; }
  std::size_t distance_to(int v) { return dist[v]; }

  int nv;
  int s;
  std::vector<bool> marked;
  std::vector<std::size_t> dist;
};

template <class Graph> graph_paths_s graph_paths_bfs(const Graph &g, int s) {
  graph_paths_s res(g.nv(), s);

  std::queue<int> q;
  q.push(s);

  while (!q.empty()) {
    auto p = q.front();
    q.pop();

    auto nbrs = g.neighbors(p);

    for (auto nbr : nbrs) {
      if (!res.marked[nbr]) {
        res.dist[nbr] = res.dist[p] + 1;
        res.marked[nbr] = true;
        q.push(nbr);
      }
    }
  }

  return res;
}

namespace details {

template <class Graph> void dfs(const Graph &g, graph_paths_s &res, int i) {
  res.marked[i] = true;

  auto nbrs = g.neighbors(i);

  for (auto nbr : nbrs) {
    if (!res.marked[nbr]) {
      res.dist[nbr] = res.dist[i] + 1;
      dfs(g, res, nbr);
    }
  }
}

} // details

template <class Graph> graph_paths_s graph_paths_dfs(const Graph &g, int s) {
  graph_paths_s res(g.nv(), s);
  details::dfs(g, res, s);
  return res;
}
}
