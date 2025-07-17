#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

bool operator==(const P &a, const P &b) {    
  return a.x == b.x && a.y == b.y;
}  

bool operator!=(const P &a, const P &b) {
  return !(a == b);
}

inline P new_p(int x, int y) {
  return P { .x = x, .y = y };
}

int solve(const string &s) {  
  int n = (int)s.size();
  P start = new_p(0, 0);
  P c = start;
  vector<P> a = {c};  
  int step = 0;
  int dir = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'S') {
      step += 1;
      if (dir == 1) {
        c.x += 1;
      } else if (dir == 2) {
        c.y += 1;
      } else if (dir == 3) {
        c.x -= 1;
      } else if (dir == 4) {
        c.y -= 1;
      }      
      if (find(begin(a), end(a), c) != end(a)) {
        return step;
      }
      a.push_back(c);
    } else if (s[i] == 'L') {
      if (dir == 1) {
        dir = 2;
      } else if (dir == 2) {
        dir = 3;
      } else if (dir == 3) {
        dir = 4;
      } else if (dir == 4) {
        dir = 1;
      }
    } else if (s[i] == 'R') {
      if (dir == 1) {
        dir = 4;
      } else if (dir == 2) {
        dir = 1;
      } else if (dir == 3) {
        dir = 2;
      } else if (dir == 4) {
        dir = 3;
      }
    }    
  }
  if (c == start) {
    return 0;
  }
  return -1;
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}