#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 9;

bool ok(int c) {
  return 1 <= c && c <= N;
}

bool ok(int x, int y) {
  return ok(x) && ok(y);
}

struct C {
  int x, y;
  bool is_black() const {    
    return 
      (y % 2 == 1 && x % 2 == 1) ||
      (x % 2 == 0 && y % 2 == 0);
  }
  int cc() const {
    return (x - 1) * N + y;
  }  
};

C new_c(int x, int y) {
  return { .x = x, .y = y };
}

struct Edge {
  C a, b;
};

Edge new_edge(const C &a, const C &b) {
  return { .a = a, .b = b };
}

Edge new_edge(const C &a, int x, int y) {
  C b = new_c(x, y);
  return new_edge(a, b);
}

vector<Edge> bishop_edges(const C &a) {
  vector<Edge> res;
  
  auto add = [&](int nx, int ny) {
    res.push_back(new_edge(a, nx, ny));
  };

  int x = a.x;
  int y = a.y;

  int nx = x + 1;
  int ny = y + 1;
  while (ok(nx, ny)) {
    add(nx, ny);    
    nx += 1; ny += 1;
  }

  nx = x + 1;
  ny = y - 1;
  while (ok(nx, ny)) {
    add(nx, ny);    
    nx += 1; ny -= 1;
  }

  nx = x - 1;
  ny = y - 1;
  while (ok(nx, ny)) {
    add(nx, ny);
    nx -= 1; ny -= 1;
  }

  nx = x - 1;
  ny = y + 1;
  while (ok(nx, ny)) {
    add(nx, ny);
    nx -= 1; ny += 1;
  }

  return res;
}

vector<Edge> knight_edges(const C& a) {
  vector<Edge> res;
  
  auto add = [&](int nx, int ny) {
    if (ok(nx, ny)) {
      res.push_back(new_edge(a, nx, ny));
    }
  };

  int x = a.x;
  int y = a.y;

  int nx = x + 1;
  int ny = y + 2;
  add(nx, ny);

  nx = x + 2;
  ny = y + 1;
  add(nx, ny);

  nx = x + 1;
  ny = y - 2;
  add(nx, ny);

  nx = x + 2;
  ny = y - 1;
  add(nx, ny);
  
  nx = x - 1;
  ny = y - 2;
  add(nx, ny);
  
  nx = x - 2;
  ny = y - 1;
  add(nx, ny);
  
  nx = x - 1;
  ny = y + 2;
  add(nx, ny);

  nx = x - 2;
  ny = y + 1;
  add(nx, ny);

  return res;
}

vector<Edge> get_edges(const C& a) {
  if (a.is_black()) {
    return bishop_edges(a);
  }
  return knight_edges(a);
}

vector<Edge> all_edges() {
  vector<Edge> res;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      C a = new_c(i, j);
      vector<Edge> edges = get_edges(a);
      for (const auto &e : edges) {
        res.push_back(e);
      }
    }
  }
  return res;
}

int solve(const C& a, const C& b) {  
  vector<Edge> edges = all_edges();
  int n = N * N;
  vector<int> dist(n + 1);
  for (int i = 1; i <= n; ++i) {
    dist[i] = INF;
  }
  dist[a.cc()] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    for (const auto &e : edges) {
      dist[e.b.cc()] = min(dist[e.b.cc()], dist[e.a.cc()] + 1);
    }
  }
  int ans = dist[b.cc()];
  if (ans == INF) {
    ans = -1;
  }
  return ans;
}

C read_cell() {
  string s;
  cin >> s;
  int x = (int)(s[0] - 'A') + 1;
  int y = (int)(s[1] - '1') + 1;
  return new_c(x, y);
}

int main() {  
  C a = read_cell();  
  C b = read_cell();
  cout << solve(a, b) << endl;
  return 0;
}