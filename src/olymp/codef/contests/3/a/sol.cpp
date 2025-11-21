#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

int dist(const P &p, const P &q) {
  return abs(p.x - q.x) + abs(p.y - q.y);
}

int to_x(char c) {
  return (int)c - (int)'a' + 1;
}

int to_y(char c) {
  return (int)c - (int)'0';
}

P parse_p(const string &s) {
  return P { .x = to_x(s[0]), .y = to_y(s[1]) };
}
  
int main() {
  string s, t;
  cin >> s >> t;
  P p = parse_p(s);
  P q = parse_p(t);
  int dx = q.x - p.x;
  int dy = q.y - p.y;  
  
  cout << endl;
  return 0;
}

