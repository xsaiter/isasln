/*
 * minimum spanning tree
 */

#pragma once

#include <queue>
#include <vector>

#include <float.h>

#include "../disjoint_sets.hpp"
#include "graph.hpp"

namespace isa::graphs {
template <typename Graph>
std::vector<typename Graph::edge_u> mst_kruskal(const Graph &g) {
  using edge_u = typename Graph::edge_u;

  auto edges = g.all_edges();

  auto cmp = [](const edge_u &x, const edge_u &y) { return x.w < y.w; };
  std::sort(edges.begin(), edges.end(), cmp);

  Disjoint_sets<int> ds;

  auto end = edges.end();

  for (auto i = edges.begin(); i != end; ++i) {
    ds.add(i->a);
    ds.add(i->b);
  }

  std::vector<edge_u> res;

  for (auto i = edges.begin(); i != end; ++i) {
    auto ra = ds.find(i->a);
    auto rb = ds.find(i->b);

    if (ra != rb) {
      res.push_back(*i);
      ds.unit(ra, rb);
    }
  }

  return res;
}

template <typename Graph>
std::vector<typename Graph::edge_u> mst_prim(const Graph &g) {
  using edge_u = typename Graph::edge_u;
  std::vector<edge_u> res;
  std::priority_queue<int> q;
  return res;
}
} // namespace isa::graphs
