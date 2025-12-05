#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;    
    string s;
    cin >> s;
    string res(n, s[n - 1]);  
    cout << res << "\n";
  }
  cout << endl;
  return 0;
}

