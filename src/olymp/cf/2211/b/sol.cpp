#include <bits/stdc++.h>

using namespace std;

struct R {
  int s;
  vector<int> b;
};

R solve(int x, int y) {  
  int s = 0;
  vector<int> v;
  if (x == y) {
    s = 1;    
    for (int i = 0; i < x + y; ++i) {
      if ((i + 1) % 2 == 0) {
        v.push_back(1);
      } else {
        v.push_back(-1);
      }
    }
  } else if (x < y) {    
    for (int i = 1; i <= x; ++i) {      
      v.push_back(1);      
      v.push_back(-1);      
    }
    y -= x;
    for (int i = 1; i <= y; ++i) {
      v.push_back(-1);
    }
  } else if (x > y) {
    for (int i = 1; i <= y; ++i) { 
      v.push_back(1);      
      v.push_back(-1);
    }
    x -= y;
    for (int i = 1; i <= x; ++i) {
      v.push_back(1);
    }
  }
  return R {.s = s, .b = v};  
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;  
    R r = solve(x, y);
    cout << r.s << '\n';    
    for (int i = 0; i < x + y; ++i) {
      cout << r.b[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}