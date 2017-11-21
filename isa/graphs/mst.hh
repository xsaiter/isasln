/*
 * minimum spanning tree
 */

#pragma once

#include <vector>
#include <queue>

#include <float.h>

#include "graph.hh"
#include "../disjoint_sets.hh"

namespace isa {
namespace graphs {

template <class Graph>
std::vector<typename Graph::edge_u> mst_kruskal(const Graph &g) {
  using edge_u = typename Graph::edge_u;

  auto edges = g.all_edges();

  std::sort(edges.begin(), edges.end(),
            [](const edge_u &x, const edge_u &y) { return x.w < y.w; });

  disjoint_sets_s<int> sets;

  auto end = edges.end();

  for (auto i = edges.begin(); i != end; ++i) {
    sets.add(i->a);
    sets.add(i->b);
  }

  std::vector<edge_u> res;

  for (auto i = edges.begin(); i != end; ++i) {
    auto ra = sets.find(i->a);
    auto rb = sets.find(i->b);

    if (ra != rb) {
      res.push_back(*i);
      sets.union_for(ra, rb);
    }
  }

  return res;
}

template <class Graph>
std::vector<typename Graph::edge_u> mst_prim(const Graph &g) {
  using edge_u = typename Graph::edge_u;

  std::vector<edge_u> res;

  std::priority_queue<int> q;

  return res;
}
}
}
