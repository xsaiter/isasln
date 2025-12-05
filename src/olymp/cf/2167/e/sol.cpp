#include <bits/stdc++.h>

using namespace std;

struct S {
  int p, q;
};

S new_s(int p, int q) {
  return S {.p = p, .q = q};
}

vector<int> solve(int n, int k, int x, vector<int> &a) {
  vector<int> b(k);  
  vector<S> ss;
  for (int i = 1; i < n; ++i) {
    ss.push_back(new_s());
  }
  return b;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b = solve(n, k, x, a);
    for (int i = 0; i < k; ++i) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}