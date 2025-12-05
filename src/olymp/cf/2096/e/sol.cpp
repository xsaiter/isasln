#include <bits/stdc++.h>

using namespace std;

// b p b p p b b p p

// bpp bbb bbb bbb b
// bpp ppppppppppppp

int solve(int n, string &s) {
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'B') {
      a[i] = 0;
    } else {
      a[i] = 1;
    }
  }
  vector<int> b = a;
  sort(begin(a), end(a));
  for (int i = 0; i < n; ++i) {
    
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(n, s) << '\n';
  }
  cout << endl;
  return 0;
}