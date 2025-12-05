#include <bits/stdc++.h>

using namespace std;
using R = long long;

#define N 1000

R m[N][N];

vector<R> solve(int n) {
  vector<R> res(n);
  for (int x = 0; x < n - 2; ++x) {
    int y = x + 1;
    int z = y + 1;
    res[x] = sqrt(m[x][y] * m[x][z] / m[y][z]);
  }
  for (int i = n - 2; i < n; ++i) {
    res[i] = m[i - 1][i] / res[i - 1];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> m[i][j];
    }
  }
  vector<R> res = solve(n);
  copy(begin(res), end(res), ostream_iterator<R>(cout, " "));
  return 0;
}