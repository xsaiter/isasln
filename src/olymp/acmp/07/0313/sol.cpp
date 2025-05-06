#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;  
  vector<int> p(N, -1);
  vector<int> w(N, -1);
  int res = -1;
  int v;
  for (int i = 0; i < n; ++i) {
    cin >> v;
    if (p[v] != -1) {
      w[v] = max(w[v], i - p[v]);
      res = max(res, w[v]);
    }
    p[v] = i;
  }
  cout << res << endl;
  return 0;
}

