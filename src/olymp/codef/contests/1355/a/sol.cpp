#include <bits/stdc++.h>

using namespace std;

using X = long long;
using P = pair<int, int>;

P get_digits(X n) {  
  vector<int> ds;
  int rem = n % 10;
  ds.push_back(rem);
  while (n - rem > 0) {
    n = (n - rem) / 10;
    rem = n % 10;
    ds.push_back(rem);
  }
  const auto [mi, ma] = minmax_element(begin(ds), end(ds));
  return {*mi, *ma};
}

X solve(X a1, X k) {
  X res = a1;
  for (X i = 1; i < k; ++i) {
    auto p = get_digits(res);
    res += p.first * p.second;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    X a1, k;
    cin >> a1 >> k;
    cout << solve(a1, k) << "\n";
  }
  cout << endl;  
  return 0;
}