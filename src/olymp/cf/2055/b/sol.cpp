#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

bool solve(int n, const vector<int> &a, const vector<int> &b) {  
  int neg = 0, cnt_neg = 0;
  int min_pos = INF;
  for (int i = 0; i < n; ++i) {
     if (a[i] < b[i]) {       
       if (cnt_neg > 0) {
         return false;
       }
       neg = b[i] - a[i];
       ++cnt_neg;
     } else {
       min_pos = min(min_pos, a[i] - b[i]);
     } 
  }
  if (min_pos >= neg) {
    return true;
  }
  return false;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    cout << (solve(n, a, b) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}