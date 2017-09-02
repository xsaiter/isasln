#pragma once

#include <queue>
#include <stack>
#include <cassert>

#include "graph.hh"

namespace isa {
template <typename Graph> class dijkstra_sp {
public:
  using vertex_t = typename Graph::vertex_t;
  using edge_t = typename Graph::edge_tt;
  using pq_t = std::priority_queue<vertex_t, std::vector<vertex_t>,
                                   std::greater<vertex_t>>;

  dijkstra_sp(const Graph &g, const vertex_t &s)
      : g_(g), s_(s), dist_(g.v(), -1), edges_(g.v()) {
    g_.create_map(map_);
    dist_[map_[s_]] = 0;
  }

  void search() {
    pq_t q;
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

  bool has_path_to(const vertex_t &v) { return dist_[map_[v]] != -1; }

  int dist_to(const vertex_t &v) { return dist_[map_[v]]; }

  std::stack<edge_t> get_path_to(const vertex_t &v) {
    assert(has_path_to(v));

    std::stack<edge_t> res;

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
  const vertex_t s_;
  std::vector<int> dist_;
  std::vector<edge_t> edges_;
  std::map<vertex_t, std::size_t> map_;
};
}
