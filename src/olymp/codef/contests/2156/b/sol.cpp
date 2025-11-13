#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, int q, const string &s, const vector<int> &a) {
  int na = 0, nb = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      ++na;
    } else {
      ++nb;
    }
  }
  vector<int> b(q);  
  for (int i = 0; i < q; ++i) {
    int x = a[i];
    if (nb == 0) {
      b[i] += x;
      continue;
    }    
    int j = 0;
    while (x > 0) {    
      if (s[j] == 'A') {
        x -= 1;
      } else if (s[j] == 'B') {
        if (x % 2 == 0) {
          x /= 2;
        } else {
          x = (x - 1) / 2;
        }
      }
      b[i] += 1;
      j += 1;
      if (j == n) {
        j = 0;
      }
    }
  }
  return b;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(q);
    for (int i = 0; i < q; ++i) {
      cin >> a[i];
    }
    vector<int> b = solve(n, q, s, a);
    for (int i = 0; i < q; ++i) {
      cout << b[i] << '\n';
    }    
  }
  cout << endl;
  return 0;
}