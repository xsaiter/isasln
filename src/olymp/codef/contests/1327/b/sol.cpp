#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

void solve(vector<vector<int>> &a, int n) {
  int q = -1;
  int p = -1;
  vector<int> t(n, 0);
  for (int i = 0; i < n; ++i) {
    int k = (int)a[i].size();
    int m = INF;
    for (int j = 0; j < k; ++j) {      
      if (t[a[i][j]] == 0) {
        if (a[i][j] < m) {
          m = a[i][j];
        }
      }
    }
    if (m != INF) {
      t[m] = 1;
    } else {
      p = i;
    }
  }  
  for (int i = 0; i < n; ++i) {
    if (t[i] == 0) {
      q = i;
      break;
    }
  }
  if (q == -1) {
    cout << "OPTIMAL";
  } else {
    cout << "IMPROVE" << "\n";
    cout << p + 1 << " " << q + 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      a[i].resize(k);
      for (int j = 0; j < k; ++j) {
        cin >> a[i][j];
        a[i][j] -= 1;
      }
    }
    solve(a, n);
    cout << "\n";
  }
  cout << endl;
  return 0;
}