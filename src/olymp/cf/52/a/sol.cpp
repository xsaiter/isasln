#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(3, 0);
  for (int i = 0; i < n; ++i) {
    b[a[i] - 1]++;
  }
  sort(begin(b), end(b));
  cout << b[0] + b[1] << endl;
  return 0;
}