#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &h, int n, int m, int k) {
  if (n <= 1) return true;
  for (int i = 1; i < n; ++i) {
    int d = h[i - 1] - h[i];
    int x = abs(d) - k;
    if (x <= 0) {
      if (d < 0) {
        m += k - abs(d);
      } else {
        if (h[i - 1] - abs(d) - k < 0) {
          m += h[i - 1];
        } else {
          m += abs(d) + k;
        }        
      }      
      continue;
    }    
    if (d < 0) {      
      if (x <= m) {
        m -= x;
      } else {
        return false;
      }            
    } else if (d > 0) {      
      m += x;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
    }
    cout << (solve(h, n, m, k) ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}