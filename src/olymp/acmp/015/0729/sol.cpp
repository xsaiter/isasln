#include <bits/stdc++.h>

using namespace std;

struct P {
  int a, b;
};

struct R {
  int pos, val;
};

vector<R> solve(int n, int m, vector<int> &v, vector<P> &c) {
  vector<R> res;
  vector<bool> visited(n + 1);
  vector<int> w(n + 1);
  for (int i = 0; i < m; ++i) {
    int va = v[c[i].a];
    int vb = v[c[i].b];
    if (va < vb) {
      visited[c[i].b] = true;
      w[c[i].b] += va;
    } else {
      visited[c[i].a] = true;
      w[c[i].a] += vb;
    }
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<P> c(m);
  for (int i = 0; i < m; ++i) {
    cin >> c[i].a >> c[i].b;
  }
  vector<R> res = solve(n, m, v, c);
  for (auto &each : res) {
    cout << each.pos << ' ' << each.val << '\n';
  }
  cout << endl;
  return 0;
}