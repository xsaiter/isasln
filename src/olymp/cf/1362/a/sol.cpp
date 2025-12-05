#include <bits/stdc++.h>

#define ll long long

using namespace std;

int compress(int x) {
  int res = 0;  
  int a = x % 3;
  res += (x - a) / 3;  
  int b = a % 2;
  res += (a - b) / 2;
  res += b;
  return res;
}

int solve(ll a, ll b) {  
  int res = 0;
  if (a < b) {
    while (a < b) {
      a <<= 1;
      ++res;
    }
    if (a != b) {
      res = -1;
    }
  } else if (a > b) {
    while (a > b && (a & 1) != 1) {
      a >>= 1;      
      ++res;
    }
    if (a != b) {
      res = -1;
    }
  } else {
    res = 0;
  }
  if (res > 0) {
    res = compress(res);
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