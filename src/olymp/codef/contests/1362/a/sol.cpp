#include <bits/stdc++.h>

#define ll long long

using namespace std;

int solve(ll a, ll b) {
  if (a == b) {
    return 0;
  }
  int res = 0;
  if (a < b) {
    while (a < b) {
      a <<= 1;
      ++res;
    }
    if (a != b) {
      res = -1;
    }
  } else {
    while (a > b) {
      a >>= 1;
      ++res;
    }
    if (a != b) {
      res = -1;
    }
  }
  
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    int r = solve(a, b);
    cout << r << "\n";
  }
  cout << endl;
  return 0;
}