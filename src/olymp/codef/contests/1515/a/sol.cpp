#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &w, int n, int x, vector<int> &res) {
  sort(begin(w), end(w), greater<int>());  
  int s = 0;  
  int can = true;
  for (int i = 0; i < n; ++i) {
    s += w[i];
    if (s == x) {
      s -= w[i];
      if (i + 1 < n) {
        int t = w[i + 1];
        w[i + 1] = w[i];
        w[i] = t;
        s += w[i];
      } else {
        can = false;
        break;
      }      
    }
    res[i] = w[i];   
  }
  return can;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
      cin >> w[i];
    }
    vector<int> res(n);
    bool can = solve(w, n, x, res);
    if (can) {
      cout << "YES" << '\n';
      copy(begin(res), end(res), ostream_iterator<int>(cout, " "));
      cout << '\n';
    } else {
      cout << "NO" << '\n';
    }    
  }
  cout << endl;
  return 0;
}