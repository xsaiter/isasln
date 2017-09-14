#pragma once

#include <queue>
#include <stack>
#include <cassert>

#include "graph.hh"

namespace isa {
template <typename Graph> class dijkstra_sp_s {
public:
  using vertex_u = typename Graph::vertex_u;
  using edge_u = typename Graph::edge_u;
  using pq_u = std::priority_queue<vertex_u, std::vector<vertex_u>,
                                   std::greater<vertex_u>>;

  dijkstra_sp_s(const Graph &g, const vertex_u &s)
      : g_(g), s_(s), dist_(g.v(), -1), edges_(g.v()) {
    g_.create_map(map_);
    dist_[map_[s_]] = 0;
  }

  void search() {
    pq_u q;
    q.push(s_);

    while (!q.empty()) {
      auto t = q.top();
      q.pop();

      auto edges = g_.get_incident_edges(t);

      for (const auto &edge : edges) {
        std::size_t i = map_[edge.dest];
        int d = dist_[map_[t]] + edge.w;
        if (dist_[i] == -1 || d < dist_[i]) {
          q.push(edge.dest);
          dist_[i] = d;
          edges_[i] = edge;
        }
      }
    }
  }

  bool has_path_to(const vertex_u &v) { return dist_[map_[v]] != -1; }

  int dist_to(const vertex_u &v) { return dist_[map_[v]]; }

  std::stack<edge_u> get_path_to(const vertex_u &v) {
    assert(has_path_to(v));

    std::stack<edge_u> res;

    auto i = std::next(edges_.begin(), map_[v]);
    res.push(*i);

    while (i->src != s_) {
      i = std::next(edges_.begin(), map_[i->src]);
      res.push(*i);
    }

    return res;
  }

private:
  const Graph &g_;
  const vertex_u s_;
  std::vector<int> dist_;
  std::vector<edge_u> edges_;
  std::map<vertex_u, std::size_t> map_;
};
}
