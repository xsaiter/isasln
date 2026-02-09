#include <bits/stdc++.h>

using namespace std;

void solve(int n, vector<int> &b) {
  sort(b.begin(), b.end(), 
    [](const int &l, const int &r) {
      return l > r;
    });  
  int c = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] > 0) {
      c++;
    } else {
      c--;
    }
    cout << c << ' ';
  }
  cout << '\n';

  vector<int> x(n + 1);
  for (int i = 0; i < n; ++i) {
    if (b[i] > 0) {
      x[abs(b[i])]++;
    } else {
      x[abs(b[i])]--;
    }
  }
  int ll = 0, rr = 0;  
  for (int i = 0; i < n; ++i) {
    if (x[abs(b[i])] == 0) {
      ++ll;
    } else {
      ++rr;
    }
  }
  bool state = true;
  while (ll--) {
    if (state) {
      cout << '1';
      state = false;
    } else {
      cout << '0';
      state = true;
    }
    cout << ' ';
  }
  c = 0;
  if (!state) {
    c = 1;
  }
  while (rr--) {
    c++;
    cout << c << ' ';    
  }
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    solve(n, b);    
    cout << '\n';
  }
  cout << endl;
  return 0;
}