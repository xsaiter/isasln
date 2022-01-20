#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, vector<int> &a) {
  int i = 0, j = 0;   
  while (i < n && k > 0) {
    for (j = i + 1; j < n; ++j) {
      if (a[i] > a[j]) {
        a[i] -= a[j];
        a[j] = 0;        
      } else {
        a[j] -= a[i];
        a[i] = 0;
      }
      if (j == n) break;
      i = j;
    }   
  }  
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    solve(n, k, a);
    copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
  cout << endl;
  return 0;
}