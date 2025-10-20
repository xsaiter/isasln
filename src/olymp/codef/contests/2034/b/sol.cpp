#include <bits/stdc++.h>

using namespace std;

void update_s(int n, string& s, int p, int q) {
  for (int i = p; i < min(n, q); ++i) {
    s[i] = '1';
  }
}

int calc(int n, int m, int k, string& s, int p, int q) {
  int ans = 0;
  int d = q - p + 1;
  if (d <= k) {
    ans += 1;
    int delta = k - d;
    if (delta > 0) {
      update_s(n, s, q + 1, q + delta + 1);
    }
  } else {
    int rem = d % k;
    ans += (d - rem) / k;
  }
  return ans;
}

int solve(int n, int m, int k, string& s) {
  int ans = 0;
  int p = 0, q = 0;
  bool start = false;
  for (int i = 0; i < n; ++i) {
    if (start) {
      if (s[i] == '0') {
        q += 1;
      } else {
        start = false;
        ans += calc(n, m, k, s, p, q);
      }
    } else {
      if (s[i] == '0') {
        p = i;
        q = i;
        start = true;
      } else {
        p += 1;
      }
    }
  }
  ans += calc(n, m, k, s, p, q);
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    cout << solve(n, m, k, s) << '\n';
  }
  cout << endl;
  return 0;
}