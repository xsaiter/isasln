#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a, int k) {  
  int s = accumulate(begin(a), end(a), 0);
  if (k == 1) {
    return s;
  }
  if (k == n) {                 
    return *max_element(begin(a), end(a));    
  }
  for (int i = 0; i < n; ++i) {
    
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int k;
  cin >> k;
  cout << solve(n, a, k) << endl;
  return 0;
}