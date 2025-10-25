#include <bits/stdc++.h>

using namespace std;

struct C {
  int x, y;
};

int ord_c(char c) {
  return (int)c - (int)'a' + 1;
}

int ord_d(char c) {
  return (int)c - (int)'0';
}

C parse_c(const string &s) {  
  int x = ord_c(s[0]);
  int y = ord_d(s[1]);
  return C {.x = x, .y = y};
}

C read_c() {
  string s;
  cin >> s;
  return parse_c(s);
}

int solve(const C &a, const C &b) {
  int ans = 0;
  vector<vector<int>> adj(8 * 8, vector<int>());
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {

    }
  }  
  return ans;
}

int main() {    
  C a = read_c();  
  C b = read_c();
  cout << a.x << a.y << endl;
  cout << b.x << b.y << endl;
  return 0;
}