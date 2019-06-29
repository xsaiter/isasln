#pragma once

#include <cassert>
#include <queue>
#include <stack>

#include "paths.hh"

namespace isa::graphs {
template <typename Graph>
shortest_paths_s<typename Graph::edge_u> dijkstra(const Graph &g, int s) {
  using edge_u = typename Graph::edge_u;
  using pq_u = std::priority_queue<int, std::vector<int>, std::greater<int>>;

  shortest_paths_s<edge_u> paths(s, g.nv());

  pq_u q;
  q.push(s);

  while (!q.empty()) {
    auto t = q.top();
    q.pop();

    auto edges = g.incident_edges(t);

    for (const auto &e : edges) {
      int d = paths.dist[t] + e.w;
      int i = e.b;

      if (paths.dist[i] == -1 || d < paths.dist[i]) {
        q.push(e.b);
        paths.dist[i] = d;
        paths.edges[i] = e;
      }
    }
  }

  return paths;
}
} // namespace isa::graphs
