#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x, const vector<int> &v) {
  if (x > 0 && x < 4) {
    return true;
  }
  int n = v.size();
  for (int i = 0; i < n && v[i] * v[i] <= x; ++i) {
    if (x % v[i] == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, n;
  cin >> m >> n;
  bool has = false;
  vector<int> v;
  for (int i = 2; i <= n; ++i) {
    if (is_prime(i, v)) {
      v.push_back(i);
      if (i >= m) {
        has = true;
        cout << i << "\n";
      }
    }
  }
  if (!has) {
    cout << "Absent";
  }
  cout << endl;
  return 0;
}