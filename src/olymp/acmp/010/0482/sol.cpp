#include <bits/stdc++.h>

using namespace std;

// 1 12 123 1234 12345

int len(int x) {
  return x * (x + 1) / 2;
}

int solve(int n) {
  int N = 32768;
  vector<int> a(N, 0);
  for (int i = 1; i < 32768; ++i) {    
  }
  return a[n];
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}