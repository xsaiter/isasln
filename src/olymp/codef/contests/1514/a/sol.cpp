#include <bits/stdc++.h>

using namespace std;

bool is_sq(int n) {
  int x = (int)sqrt(n);
  if (x * x == n) return true; 
  return false;
}

bool solve(vector<int> &a, int n) {  
  for (int i = 0; i < n; ++i) {
    if (!is_sq(a[i])) {
      return true;
    }
  }
  return false;
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
    cout << (solve(a, n) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}
