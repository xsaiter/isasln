#include <bits/stdc++.h>

using namespace std;

const int N = 6;

struct R {
  int a, b, c;
};

int ord(char c) {
  return (int)c - (int)'0';
}

int ss(int x) {  
  string s = to_string(x);
  int ans = 0;
  int m = (int)s.size();
  for (int i = 0; i < m; ++i) {
    ans += ord(s[i]);
  }
  return ans;
}

R get_r(const string &s, int p, int q) {  
  string t = s.substr(p, q - p);    
  int x = atoi(t.c_str());
  return R { .a = ss(x), .b = ss(x + 1), .c = ss(x - 1) };
}

bool solve(const string &s) {
  R l = get_r(s, 0, 3);
  R r = get_r(s, 3, 6);
  return l.a == r.b || l.a == r.c;
}

int main() {
  int n;
  cin >> n;  
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cout << (solve(s) ? "Yes" : "No") << '\n';
  }  
  cout << endl;
  return 0;
}