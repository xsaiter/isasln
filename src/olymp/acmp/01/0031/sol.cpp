#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k) {
  int res = 0;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i + 1;
  }
  sort(begin(a), end(a));
  do {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == i + 1) {
        ++cnt;
      }
    }
    if (cnt == k) {
      ++res;
    }
  } while (next_permutation(begin(a), end(a)));
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << solve(n, k) << endl;
  return 0;
}