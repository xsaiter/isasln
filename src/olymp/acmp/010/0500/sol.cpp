#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

int solve(int n, vector<P> &a) {
  
}

int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  cout << solve(n, a) << endl;
  return 0;
}