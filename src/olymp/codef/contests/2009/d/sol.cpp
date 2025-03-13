#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

int solve(int n, vector<P> &a) {
  int res = 0;
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<P> a(n);
    for (int i = 0; i <n; ++i) {
      cin >> a[i].x >> a[i].y;
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}