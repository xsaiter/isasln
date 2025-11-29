#include <bits/stdc++.h>

using namespace std;

struct E {
  int a, b;
};

vector<int> solve(int n, int m, const vector<E> &ee) {
  vector<int> cc(n + 1);
  for (int i = 0; i < m; ++i) {
    cc[ee[i].a] += 1;
    cc[ee[i].b] += 1;
  }
  return cc;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<E> ee(m);
  for (int i = 0; i < m; ++i) {
    cin >> ee[i].a >> ee[i].b;
  }
  vector<int> cc = solve(n, m, ee);
  for (int i = 1; i < n + 1; ++i) {
    cout << cc[i] << ' ';
  }
  cout << endl;
  return 0;
}