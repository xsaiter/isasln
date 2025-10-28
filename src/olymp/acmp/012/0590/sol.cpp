#include <bits/stdc++.h>

using namespace std;

struct R {
  int x, y, z;
};

bool solve(int n, vector<R> &a) {
  bool ans = false;
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<R> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].z;
  }
  bool ans = solve(n, a);
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}