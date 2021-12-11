#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int> &a, int n) {    
  for (int i = 1; i < n - 1; ++i) {
    if (a[i - 1] != a[i]) {
      return (a[i] != a[i + 1]) ? i : (i - 1);      
    } else if (a[i] != a[i + 1]) {
      return i + 1;
    }
  }
  return -1;
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
    cout << (solve(a, n) + 1) << "\n";
  }
  cout << endl;
  return 0;
}