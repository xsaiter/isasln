#include <bits/stdc++.h>

using namespace std;

using M = vector<vector<int>>;

bool can_b(int v, const vector<bool> &b, int k) {
  return v >= 0 && v <= k - 1 && !b[v];
}

bool check_h(int n, int k, const M &a) {
  for (int i = 0; i < k; ++i) {
    vector<bool> b(k, false);
    for (int j = 0; j < k; ++j) {
      int v = a[i][j] - 1;
      if (!can_b(v, b, k)) {
        return false;
      }
      b[v] = true;
    }
  }
  return true;
}

bool check_v(int n, int k, const M &a) {
  for (int j = 0; j < k; ++j) {
    vector<bool> b(k, false);
    for (int i = 0; i < k; ++i) {
      int v = a[i][j] - 1;
      if (!can_b(v, b, k)) {
        return false;
      }
      b[v] = true;
    }
  }
  return true;
}

bool check_med(int n, int k, const M &a) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int sii = i * n;
      int sjj = j * n;      
      vector<bool> b(k, false);
      for (int ii = 0; ii < n; ++ii) {
        for (int jj = 0; jj < n; ++jj) {
          int v = a[sii + ii][sjj + jj] - 1;
          if (!can_b(v, b, k)) {
            return false;
          }
          b[v] = true;
        } 
      }      
    }
  }
  return true;
}

bool solve(int n, int k, const M &a) {      
  return check_med(n, k, a) 
    && check_h(n, k, a) 
    && check_v(n, k, a);
}

int main() {
  int n;
  cin >> n;
  int k = n * n;
  M a(k, vector<int>(k));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> a[i][j];
    }
  }  
  cout << (solve(n, k, a)? "Correct" : "Incorrect") << endl;
  return 0;
}