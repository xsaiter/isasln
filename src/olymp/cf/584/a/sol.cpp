#include <bits/stdc++.h>

using namespace std;

string solve(int n, int t) {
  ostringstream os;
  if (t == 10) {
    if (n == 1) {
      return "-1";
    } else {
      for (int i = 0; i < n - 1; ++i) {
        os << '1';
      }
      os << '0';
    }
  } else {
    for (int i = 0; i < n; ++i) {
      os << t;
    }
  }  
  return os.str();
}

int main() {
  int n, t;
  cin >> n >> t;  
  cout << solve(n, t) << endl;
  return 0;
}