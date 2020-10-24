#include <bits/stdc++.h>

using namespace std;

vector<int> get_divs(int n) {
  vector<int> res;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) res.push_back(i);
  }
  return res;
}

void solve(string &t, int n) {
  auto divs = get_divs(n);
  for (int div : divs) {
    reverse(begin(t), begin(t) + div);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string t;
  cin >> t;
  solve(t, n);
  cout << t << endl;
  return 0;
}