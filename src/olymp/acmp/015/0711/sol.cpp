#include <bits/stdc++.h>

using namespace std;

struct R {
  string s;
  vector<int> a;
  int time() const {
    return accumulate(begin(a), end(a), 0);
  }
};

string solve(int n, const vector<R> &a) {  
  int j = 0;
  int mt = a[0].time();
  for (int i = 1; i < n; ++i) {
    int t = a[i].time();
    if (t < mt) {
      mt = t;
      j = i;
    }    
  }
  return a[j].s;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<R> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].s;
    for (int j = 0; j < m; ++j) {
      int x; cin >> x;
      a[i].a.push_back(x);
    }
    
  }
  cout << solve(n, a) << endl;
  return 0;
}