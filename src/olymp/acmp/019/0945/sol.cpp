#include <bits/stdc++.h>

using namespace std;

using L = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  L n, k;
  cin >> n >> k;
  vector<L> a(n);
  for (L i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<L> sa(a.begin(), a.end());
  vector<L> b(k);
  for (L i = 0; i < k; ++i) {
    L v;
    cin >> v;
    if (sa.find(v) != sa.end()) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << ' ';
  }
  cout << endl;
  return 0;
}