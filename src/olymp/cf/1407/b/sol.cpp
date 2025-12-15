#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, const vector<int> &a) {
  vector<int> b;
  vector<bool> used(n, false);
  int x = 0;  
  for (int i = 0; i < n; ++i) {
    int best = -1;
    int best_id = -1;
    for (int j = 0; j < n; ++j) {
      if (!used[j] && gcd(x, a[j]) > best) {
        best = gcd(x, a[j]);
        best_id = j;
      }      
    }
    used[best_id] = true;
    x = best;
    b.push_back(a[best_id]);
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
    for (int i = 0; i < (int)b.size(); ++i) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}