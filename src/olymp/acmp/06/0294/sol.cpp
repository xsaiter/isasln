#include <bits/stdc++.h>

using namespace std;

int cost(const vector<int> &a) {
  return a[0] * a[1] * a[2] / 100;
}

int cost2(const vector<int> &a, const vector<int> &b) {
  return min(a[0] * a[1] / 100, 0) * b[2];
}

int solve(const vector<int> &a, const vector<int> &b) {  
  return cost(a) + cost(b);
}

int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  vector<int> b(3);
  cin >> b[0] >> b[1] >> b[2];
  cout << solve(a, b) << endl;
  return 0;
}