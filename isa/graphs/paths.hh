#pragma once

#include <queue>
#include <stack>

#include "graph.hh"

namespace isa {
struct paths_s {
  int nv;
  int s;
  std::vector<bool> marked;
  std::vector<std::size_t> dist;

  paths_s(int nv_, int s_) : nv(nv_), s(s_), marked(nv, false), dist(nv, 0) {}

  bool has_path_to(int v) const { return marked[v]; }

  std::size_t distance_to(int v) const { return dist[v]; }
};

template <typename Edge> struct shortest_paths_s {
  int s;
  std::vector<int> dist;
  std::vector<Edge> edges;

  shortest_paths_s(int s_, int nv_) : s(s_), dist(nv_, -1), edges(nv_) {}

  bool has_path_to(int v) const { return dist[v] != -1; }

  int dist_to(int v) const { return dist[v]; }

  std::stack<Edge> get_path_to(int v) const {
    assert(has_path_to(v));

    std::stack<Edge> res;

    auto i = std::next(edges.begin(), v);
    res.push(*i);

    while (i->a != s) {
      i = std::next(edges.begin(), i->a);
      res.push(*i);
    }

    return res;
  }
};

template <typename Graph> paths_s graph_paths_bfs(const Graph &g, int s) {
  paths_s res(g.nv(), s);

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

template <typename Graph> void dfs(const Graph &g, paths_s &res, int i) {
  res.marked[i] = true;

  auto nbrs = g.neighbors(i);

  for (auto nbr : nbrs) {
    if (!res.marked[nbr]) {
      res.dist[nbr] = res.dist[i] + 1;
      dfs(g, res, nbr);
    }
  }
}

} // namespace details

template <typename Graph> paths_s graph_paths_dfs(const Graph &g, int s) {
  paths_s res(g.nv(), s);
  details::dfs(g, res, s);
  return res;
}
} // namespace isa
