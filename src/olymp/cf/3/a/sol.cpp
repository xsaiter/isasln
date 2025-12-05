#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

int dist(const P& p, const P& q) {
  return abs(p.x - q.x) + abs(p.y - q.y);
}

int to_x(char c) {
  return (int)c - (int)'a' + 1;
}

int to_y(char c) {
  return (int)c - (int)'0';
}

P parse_p(const string& s) {
  return P{ .x = to_x(s[0]), .y = to_y(s[1]) };
}

int main() {
  string s, t;
  cin >> s >> t;
  P p = parse_p(s);
  P q = parse_p(t);
  int dx = q.x - p.x;
  int dy = q.y - p.y;

  int a = min(abs(dx), abs(dy));
  int b = max(abs(dy), abs(dx)) - min(abs(dx), abs(dy));

  cout << a + b << '\n';
  
  if (dx >= 0) {
    if (dy >= 0) {      
      for (int i = 1; i <= a; ++i) {
        cout << "RU\n";
      }
      for (int i = 1; i <= b; ++i) {        
        if (abs(dx) < abs(dy)) {
          cout << "U\n";
        } else {
          cout << "R\n";
        }
      }
    } else {      
      for (int i = 1; i <= a; ++i) {
        cout << "RD\n";
      }
      for (int i = 1; i <= b; ++i) {
        if (abs(dx) < abs(dy)) {
          cout << "D\n";
        } else {
          cout << "R\n";
        }
      }
    }
  } else {
    if (dy >= 0) {      
      for (int i = 1; i <= a; ++i) {
        cout << "LU\n";
      }
      for (int i = 1; i <= b; ++i) {
        if (abs(dx) < abs(dy)) {
          cout << "U\n";
        } else {
          cout << "L\n";
        }
      }
    } else {
      for (int i = 1; i <= a; ++i) {
        cout << "LD\n";
      }
      for (int i = 1; i <= b; ++i) {
        if (abs(dx) < abs(dy)) {
          cout << "D\n";
        } else {
          cout << "L\n";
        }
      }
    }
  }
  cout << endl;
  return 0;
}

