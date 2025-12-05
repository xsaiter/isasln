#include <bits/stdc++.h>

#define fi first
#define se second
#define INF INT_MAX

using namespace std;
using pii = pair<int, int>;

int solve(vector<int> &a, int n) {
  vector<int> b(n, 0);
  for (int i = 0; i < n; ++i) {
    b[a[i] - 1]++;
  }
  int res = *min_element(begin(b), end(b));
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(a, n) << "\n";
  }
  cout << endl;
  return 0;
}

