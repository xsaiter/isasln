#include <bits/stdc++.h>

using namespace std;

struct R {
  int a, b;
};

R solve(int n, int a, int b) {          
  for (int i = n; i >= 2; --i) {
    int tmp = a;
    a = b - a;
    b = tmp;
  } 
  return R { .a = a, .b = b };  
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;  
  R r = solve(n, a, b);
  cout << r.a << " " << r.b << endl;
  return 0;
}