#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct R {
  int c, l, r;

  bool operator<(const R& other) const {
    if (l == other.l) {
      return r < other.r;
    }
    return l < other.l;
  }
};

vector<int> solve(int n, int k, int q, vector<R>& b) {
  sort(b.begin(), b.end());
  int last = -1;
  vector<int> a(n, INF);
  for (int i = 0; i < q; ++i) {
    if (b[i].c == 1) {
      a[b[i].l] = k;
      last = b[i].r;
    } else {
      int kc = 1;
      for (int j = b[i].l; j <= b[i].r; ++j) {
        if (j <= last) {
          continue;
        }
        if (kc > k) {
          kc = k;
        }
      }
    }
  }
  return a;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, q;
    cin >> n >> k >> q;
    vector<R> b(q);
    for (int i = 0; i < n; ++i) {
      cin >> b[i].c >> b[i].l >> b[i].r;
    }
    vector<int> a = solve(n, k, q, b);
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}