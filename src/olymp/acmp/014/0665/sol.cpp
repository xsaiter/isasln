#include <bits/stdc++.h>

using namespace std;

struct Q {
  int h, m;

  void inc_m() {
    if (m == 59) {
      m = 0;
      if (h == 23) {
        h = 0;
      } else {
        h += 1; 
      }
    } else {
     m += 1;
    }
  }

  bool is_mirror() const {    
    string s = format(); 
    return s[0] == s[4] && s[1] == s[3];
  }  

  string format() const {
    ostringstream oss;
    auto Write = [&](int x) {
      if (x >= 10) {
        oss << x;
      } else {
        oss << 0 << x;
      }
    };
    Write(h); 
    oss << ':';
    Write(m);
    return oss.str();
  }  
};

Q parse_q(const string &s) {
  return Q { 
    .h = atoi(s.substr(0, 2).c_str()), 
    .m = atoi(s.substr(3, 2).c_str()) 
  };
}

int main() {
  string s;
  cin >> s;
  Q q = parse_q(s);  
  q.inc_m();
  while (!q.is_mirror()) {
    q.inc_m();
  }
  cout << q.format() << endl;
  return 0;
}