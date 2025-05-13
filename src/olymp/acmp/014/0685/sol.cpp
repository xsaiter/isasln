#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, vector<int> &b) {  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int res = 0;
  for (int i = 0; i < 3; ++i) {
    res += a[i] * b[i];
  }
  return res;
}

int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  vector<int> b(3);
  cin >> b[0] >> b[1] >> b[2];
  cout << solve(a, b) << endl;
  return 0;
}
