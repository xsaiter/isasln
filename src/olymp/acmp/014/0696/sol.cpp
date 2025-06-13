#include <bits/stdc++.h>

using namespace std;

const int NP = 4;

struct C {
  int x, y;
  int cc(int c) const {
    return (y - 1) * c + x;
  }
};

C new_c(int x, int y) {
  return { .x = x, .y = y };
}

struct Edge {
  C a, b;
  int w;
};

Edge new_edge(const C &a, const C &b, int w) {
  return { .a = a, .b = b, .w = w }; 
}

Edge new_edge(const C &a, int x, int y, int w) {
  C b = new_c(x, y);
  return new_edge(a, b, w);
}

int solve(int r, int c, const vector<int> &p, const vector<string> &q) {
  auto ok = [&](int x, int y) {
    return 1 <= x && x <= c && 1 <= y && y <= r;   
  };
  vector<Edge> edges;
  C s, e;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {      
      char z = q[i];
      if (z == '.') {        
      } else if (z == 'X') {
      } else if (z == 'S') {
      } else if (z == 'E') {
      } else if (z == 'R') {
      } else if (z == 'G') {
      } else if (z == 'B') {
      } else if (z == 'Y') {
      }
    }
  }
  int ans = -1;
  return ans;
}

int main() {
  int r, c;
  cin >> r >> c;
  vector<int> p(NP);
  for (int i = 0; i < NP; ++i) {
    cin >> p[i];
  }
  vector<string> q(r);
  for (int i = 0; i < r; ++i) {
    cin >> q[i];
  }
  int ans = solve(r, c, p, q);
  if (ans == -1) {
    cout << "Sleep";
  } else {
    cout << ans;
  }
  cout << endl;
  return 0;
}