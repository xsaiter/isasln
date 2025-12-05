#include <bits/stdc++.h>

using namespace std;

int solve(int m) {  
  string sm = to_string(m);
  int len = (int)sm.size() - 1;
  int n = (int)pow(10, len);  
  return m - n;
  
}

int main() {  
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    cout << solve(m) << '\n';
  }
  cout << endl;
  return 0;
}
