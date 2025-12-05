#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &a, int n, int l, int r, int s) {
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    vector<int> a(n);
    bool can = solve(a, n, l, r, s);
    if (can) { copy(begin(a), end(a), ostream_iterator<int>(cout, " ")); } 
    else { cout << "-1"; }
    cout << '\n';
  }
  cout << endl;    
  return 0;
}