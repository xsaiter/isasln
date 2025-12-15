#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, const vector<int> &a) {    
  int n0 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      n0++;
    }
  }
  int half = n / 2;
  vector<int> b;
  if (n0 >= half) {
    for (int i = 0; i < n0; ++i) {
      b.push_back(0);
    }
  } else {
    if (half % 2 == 0) {
      for (int i = 0; i < half; ++i) {
        b.push_back(1);
      }
    } else {
      for (int i = 0; i < half + 1; ++i) {
        b.push_back(1);
      }
    }
  }
  return b;
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
    vector<int> b = solve(n, a);
    int m = (int)b.size();
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}