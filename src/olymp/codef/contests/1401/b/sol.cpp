#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, vector<int> &b) {
  int res = 0;
  
  int m = min(a[0], b[2]);
	a[0] -= m;
	b[2] -= m;

	m = min(a[1], b[0]);
	a[1] -= m;
	b[0] -= m;

	m = min(a[2], b[1]);
	a[2] -= m;
	b[1] -= m;
	
	res += 2 * m;
	res -= 2 * min(a[1], b[2]);

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    vector<int> a(3);
    vector<int> b(3);
    for (int i = 0; i < 3; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < 3; ++i) {
      cin >> b[i];
    }
    cout << solve(a, b) << "\n";
  }
  cout << endl;
  return 0;
}