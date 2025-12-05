#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {  
  if (n == 1) {
    return 0;
  }
  vector<int> b(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    b[a[i]]++;
  }
  int mx = *max_element(begin(b), end(b));
  return n - mx;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}