#include <bits/stdc++.h>

using namespace std;

string solve(string &s, int h, int m) {
  int beg_h = atoi(s.substr(0, 2).c_str());
  int beg_m = atoi(s.substr(3, 2).c_str());
  int H = beg_h + h;
  int M = beg_m + m;  
  H += (M - (M % 60)) / 60;
  M = M % 60;  
  H = H % 24;
  ostringstream os;
  if (H < 10) {
    os << '0' << H;
  } else {
    os << H;
  }
  os << ':';
  if (M < 10) {
    os << '0' << M;
  } else {
    os << M;
  }
  return os.str();
}

int main() {
  string s;
  cin >> s;
  int h, m;
  cin >> h >> m;
  cout << solve(s, h, m) << endl;
  return 0;
}