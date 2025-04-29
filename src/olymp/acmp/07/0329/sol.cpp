#include <bits/stdc++.h>

using namespace std;

struct R {
  int sum;
  int na;
  vector<int> a;
};

R solve(int n, vector<int> &a) {
  R r;
  return r;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}