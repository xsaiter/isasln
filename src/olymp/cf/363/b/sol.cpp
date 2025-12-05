#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  vector<int> s(n);
  s[0] = h[0];
  for (int i = 1; i < n; ++i) {
    s[i] = s[i - 1] + h[i];
  }
  int min_a = 1e9;
  int j = 0;
  for (int i = 0; i < n - k + 1; ++i) {
    int a = s[i - 1 + k];
    if (i > 0) {
      a -= s[i - 1];
    }
    if (a < min_a) {
      min_a = a;
      j = i;
    }
  }
  cout << j + 1 << endl;
  return 0;
}