#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll calc(ll side, ll a) {
  if (side % a == 0) return side / a; 
  return 1 + (side - (side % a)) / a;
}


ll solve(ll n, ll m, ll a) {
  ll x = 0, y = 0;
  if (n <= a) x = 1;
  if (m <= a) y = 1;
  if (x != 1) {
    x = calc(n, a);
  }
  if (y != 1) {
    y = calc(m, a);
  }
  return x * y;
}

int main() {
  ll n, m, a;
  cin >> n >> m >> a;
  cout << solve(n, m, a) << endl;
  return 0;
}
