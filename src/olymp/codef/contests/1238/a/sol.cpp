#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool solve(ll x, ll y) {
  ll d = x - y;
  return d > 1;  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    ll x, y;
    cin >> x >> y;
    cout << (solve(x, y) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}