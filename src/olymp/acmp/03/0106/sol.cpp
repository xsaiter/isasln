#include <bits/stdc++.h>

using namespace std;

int solve(int n, const vector<int> &a) {  
  int x = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      ++x;
    }
  }
  return min(x, n - x);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int  i =0 ; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}