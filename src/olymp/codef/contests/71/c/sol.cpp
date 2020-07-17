#include <bits/stdc++.h>

using namespace std;

bool solve(const vector<int> &a, int n) {
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      int step = 0;
      if (n % 3 == 0) step = n / 3;
      else {
       int k = 1;
       while (n % (3 + k)) ++k;
       step = n / (3 + k);
      }      
      while (step > 0) {
        bool f = true;
        for (int j = i + step; j < i + step + n; j += step) {
          if (a[j % n] == 0) { f = false; break; }
        }
        if (f) return true;
        --step;
      }      
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << (solve(a, n) ? "YES" : "NO") << endl;
  return 0;
}