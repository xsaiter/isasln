#include <bits/stdc++.h>

using namespace std;

int solve(int n, const vector<int> &a) {
  int ans = 0;
  int len = 0;
  for (int i = 0; i < n; ++i) {
   if (a[i] > 0) {
     ++len;
   } else {     
     ans = max(ans, len);
     len = 0;
   }
  }
  ans = max(ans, len);
  return ans;
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