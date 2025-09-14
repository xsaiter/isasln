#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &a, vector<int> &b, int n) {
  if (n <= 5) {    
    return;
  }
  b.push_back(10);
  b.push_back(11);
  b.push_back(12);
  for (int i = 6; i <= n; ++i) {
    int next_a = b[i - 1] + b[i - 3];
    int last_a = a.back();
    a.push_back(next_a);    
    for (int j = last_a + 1; j < next_a; ++j) {
      b.push_back(j);      
    }    
  }
}

int main() {
  int n;
  cin >> n;  
  vector<int> a(6);
  a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 7; a[5] = 13;
  vector<int> b(6);
  b[1] = 1; b[2] = 5; b[3] = 6; b[4] = 8; b[5] = 9;    
  solve(a, b, n);
  cout << a[n] << '\n' << b[n] << endl;  
  return 0;
}