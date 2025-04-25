#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int a, b;
};

vector<int> solve(int n, int m, vector<int> &e) {
  vector<int> b(n);

  return b;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> e(m);
  for (int  i =0 ; i <m; ++i) {
    cin >> e[i].a >> e[i].b;
  }
  vector<int> b = solve(n, m, e);
  for (int i = 0; i < n; ++i) {
    cout << b[i] << " ";
  }
  cout << endl;
  return 0;
}