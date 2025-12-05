#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &r, int n) {  
  int s1 = 0, s2 = 0;
  for (int i = 0; i < n; ++i) {
    if (r[i] == 1) ++s1;
    else if (r[i] == 2) ++s2;
    else if (r[i] == 3) ++s1;
  }
  return s1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0 ; i < n; ++i) {
      cin >> r[i];
    }
    cout << solve(r, n) << "\n";
  }
  cout << endl;
  return 0;
}