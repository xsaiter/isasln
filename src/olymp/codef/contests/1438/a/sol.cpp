#include <bits/stdc++.h>

using namespace std;
using V = vector<int>;

V solve(int n) {
  V res(n);
  for (int i = 0; i < n; ++i) {   
    res[i] = 1;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    V res = solve(n);
    copy(begin(res), end(res), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
  cout << endl;
  return 0;
}