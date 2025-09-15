#include <bits/stdc++.h>

using namespace std;

struct R {
  int a, b;
};

int to_int(const string &s) {
  return atoi(s.c_str());
}

void parse_r(const string &s, R &x) {
  auto pos = s.find(' ');
  if (pos == string::npos) {
    x.a = to_int(s);
    x.b = -1;
  } else {
    x.a = to_int(s.substr(0, pos));
    x.b = to_int(s.substr(pos, s.size() - pos));
  }
}

int main() {
  int n;
  string s;
  getline(cin, s);  
  n = atoi(s.c_str());  
  vector<R> r(n);
  for (int i = 0; i < n; ++i) {
    string ss;
    getline(cin, ss);
    parse_r(ss, r[i]);
  }
  deque<int> d;
  for (int i = 0; i < n; ++i) {
    int x = r[i].a;
    if (x == 1) {
      d.push_front(r[i].b);
    } else if (x == 2) {
      d.push_back(r[i].b);
    } else if (x == 3) {
      cout << d.front() << ' ';
      d.pop_front();
    } else if (x == 4) {
      cout << d.back() << ' ';
      d.pop_back();
    }
  }  
  cout << endl;
  return 0;
}