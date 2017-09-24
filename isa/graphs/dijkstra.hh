#pragma once

#include <queue>
#include <stack>
#include <cassert>

#include "graph.hh"

namespace isa {

template <class Graph> class dijkstra_s {
public:
  using edge_u = typename Graph::edge_u;
  using pq_u = std::priority_queue<int, std::vector<int>, std::greater<int>>;

  dijkstra_s(const Graph &g, int s)
      : g_(g), s_(s), dist_(g.nv(), -1), edges_(g.nv()) {
    dist_[s_] = 0;
  }

  void search() {
    pq_u q;
    q.push(s_);

    while (!q.empty()) {
      auto t = q.top();
      q.pop();

      auto edges = g_.incident_edges(t);

      for (const auto &edge : edges) {
        int d = dist_[t] + edge.w;
        int i = edge.b;

        if (dist_[i] == -1 || d < dist_[i]) {
          q.push(edge.b);
          dist_[i] = d;
          edges_[i] = edge;
        }
      }
    }
  }

  bool has_path_to(int v) { return dist_[v] != -1; }

  int dist_to(int v) { return dist_[v]; }

  std::stack<edge_u> get_path_to(int v) {
    assert(has_path_to(v));

    std::stack<edge_u> res;

    auto i = std::next(edges_.begin(), v);
    res.push(*i);

    while (i->a != s_) {
      i = std::next(edges_.begin(), i->a);
      res.push(*i);
    }

    return res;
  }

private:
  const Graph &g_;
  int s_;
  std::vector<int> dist_;
  std::vector<edge_u> edges_;
};
}
