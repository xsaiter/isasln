#include <bits/stdc++.h>

using namespace std;

struct Rec {
  int a, b;
};

bool solve(int n, vector<Rec> &v) {  
  vector<int> h1(n + 1, 0);
  vector<int> h2(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    if (v[i].a == v[i].b) {
      return false;
    }
    if (h1[v[i].a] == 0 && h1[v[i].b] == 0) {
      ++h1[v[i].a]; ++h1[v[i].b];
    } else if (h2[v[i].a] == 0 && h2[v[i].b] == 0) {
      ++h2[v[i].a]; ++h2[v[i].b];
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<Rec> v(n);
    for (int i = 0; i < n; ++i) {
      Rec rec;
      cin >> rec.a >> rec.b;
      v[i] = rec;
    }
    cout << (solve(n, v) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}