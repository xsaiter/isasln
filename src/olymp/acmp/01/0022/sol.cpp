#include <bits/stdc++.h>

using namespace std;

string as_bin(int n) {
  if (n == 0) {
    return "0";
  } else if (n == 1) {
    return "1";
  } else if (n % 2 == 0) { 
    return as_bin(n / 2) + "0";
  }
  return as_bin(n / 2) + "1";
}

int solve(int n) {
  string b = as_bin(n);
  int m = (int)b.size();
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    if (b[i] == '1') {
      ++ans;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}