#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

struct R {
  P a, b;
};

P new_p(int x, int y) {
  return P {.x = x, .y = y};
}

R new_r(cosnt P &a, const P &b) {
  return R {.a = a, .b = b};
}

vector<R> solve(int n, int m, int k, vector<vector<int>> &a) {  
  vector<vector<P>> b(k, vector<P>());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != 0) {
        b[a[i][j]].push_back(new_(i, j));
      }
    }
  }
  vector<R> rr(k);
  for (int i = 0; i < k; ++i) {
  }
  return rr;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<R> rr = solve(n, m, k, a);
  for (int i = 0; i < k; ++i) {
    cout << rr[i].a.x << ' ' << rr[i].a.y << ' ' << rr[i].b.x << ' ' << rr[i].b.y;
  }
  cout << endl;
  return 0;
}