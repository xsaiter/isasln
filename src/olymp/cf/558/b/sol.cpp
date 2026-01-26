#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve(int n, vector<int> &a, int &l, int &r) {
  int nb = 1e6 + 1;
  vector<int> b(nb);
  for (int i = 0; i < n; ++i) {
    b[a[i]] += 1;
  }  
  int mx = *max_element(b.begin(), b.end());    
  vector<int> ss;
  for (int i = 0; i < nb; ++i) {
    if (b[i] == mx) {      
      ss.push_back(i);
    }
  }  
  int dist = INF;
  for (const auto &x : ss) {
    int ll = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == x) {
        ll = i;
        break;
      }
    }
    int rr = 0;
    for (int i = n - 1; i >= ll; --i) {
      if (a[i] == x) {
        rr = i;
        break;
      }
    }
    if (rr > ll && dist > rr - ll) {
      dist = rr - ll;
      l = ll; r = rr;
    }
  }  
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int l = 0, r = 0;
  solve(n, a, l, r);
  ++l; ++r;
  cout << l << ' ' << r << endl;  
  return 0;
}