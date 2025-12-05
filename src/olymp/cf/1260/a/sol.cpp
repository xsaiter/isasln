#include <bits/stdc++.h>

using namespace std;

int sum2(int x, int n) {
  int res = 0;
  while (n--) {
    res += x * x;
  }
  return res;
}

int solve(int c, int s) { 
  int rem = s % c;
  int d = (s - rem) / c;
  if (rem == 0) {
    return sum2(d, c);
  }
  return sum2(d, c - rem) + sum2(d + 1, rem);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, c, s;
  cin >> n;  
  for (int i = 0; i < n; ++i) {
    cin >> c; 
    cin >> s;
    cout << solve(c, s) << endl;
  }
  cout << endl;
  return 0;
}