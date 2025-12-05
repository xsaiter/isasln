#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int n) { 
  bool all_one = true;
  for (int i = 0; i < n; ++i) {
    if (a[i] != 1) {
      all_one = false;
      break;
    }
  }
  if (all_one) {
    if (n % 2 == 0) return 2; else return 1;
  }
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != 1) {
      break;
    } else {
      ++j;
    }
  }
  if (j % 2 == 0) return 1; else return 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(a, n) == 1 ? "First" : "Second") << "\n";
  }
  cout << endl;
  return 0;
}