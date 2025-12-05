#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, vector<int> &a) {
  for (int i = 0; i < n - 1 && k > 0; ++i) {
    if (a[i] == 0) continue;
    if (a[i] < k) {
      k -= a[i];      
      a[n - 1] += a[i];      
      a[i] = 0;
    } else {      
      a[i] -= k;
      a[n - 1] += k;      
      k = 0;            
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