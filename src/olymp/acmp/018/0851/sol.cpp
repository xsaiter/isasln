#include <bits/stdc++.h>

using namespace std;

string solve(int m, int n) {  
  ostringstream oss;  
  int mi = min(n, m);  
  for (int i = 0; i < mi; ++i) {
    oss << 'B';
    oss << 'G';
  }
  char c = 'B';
  if (m < n) {
    c = 'G';
  }
  for (int j = 0; j < n + m - 2 * mi; ++j) {
    oss << c;
  }
  return oss.str();
}

int main() {
  int m, n;
  cin >> m >> n;
  cout << solve(m, n) << endl;
  return 0;
}