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
  int mi = min(abs(dx), abs(dy));
  if (dx > 0) {
    if (dy > 0) {
      for (int i = 1; i <= dx; ++i) {
        cout << "RU";
      }
      for (int i = 1; i <= abs(dy) - abs(dx); ++i) {
        cout << "U";
      }
    } else {
      for (int i = 1; i <= dx; ++i) {
        cout << "RD";
      }
      for (int i = 1; i <= abs(dy) - abs(dx); ++i) {
        cout << "D";
      }
    }
  } else {
    if (dy > 0) {
      for (int i = 1; i <= dx; ++i) {
        cout << "LU";
      }
      for (int i = 1; i <= abs(dy) - abs(dx); ++i) {
        cout << "U";
      }
    } else {
      for (int i = 1; i <= dx; ++i) {
        cout << "LD";
      }
      for (int i = 1; i <= abs(dy) - abs(dx); ++i) {
        cout << "D";
      }
    }
  }
  cout << endl;
  return 0;
}

