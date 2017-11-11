#pragma once

#include <vector>

#include "graph.hh"
#include "../disjoint_sets.hh"

namespace isa {
namespace graphs {

template <class Graph>
std::vector<typename Graph::edge_u> mst_kruskal(const Graph &g) {
  using edge_u = typename Graph::edge_u;
  using edges_u = std::vector<edge_u>;

  auto edges = g.all_edges();

  std::sort(edges.begin(), edges.end(),
            [](const edge_u &x, const edge_u &y) { return x.w < y.w; });

  disjoint_sets_s<int> ss;

  auto end = edges.end();

  for (auto i = edges.begin(); i != end; ++i) {
    ss.add(i->a);
    ss.add(i->b);
  }

  edges_u res;

  for (auto i = edges.begin(); i != end; ++i) {
    auto root_a = ss.find(i->a);
    auto root_b = ss.find(i->b);

    if (root_a != root_b) {
      res.push_back(*i);
      ss.union_for(root_a, root_b);
    }
  }

  return res;
}
}
}
