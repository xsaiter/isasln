#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  int res = 0;
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    b.push_back();
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);  
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}