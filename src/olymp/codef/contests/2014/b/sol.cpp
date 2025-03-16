#include <bits/stdc++.h>

using namespace std;

int count_odd(int n) {  
  if (n % 2 == 0) {
    return n / 2;
  }
  return (n + 1) / 2;
}

bool solve(int n, int k) {  
  int a = count_odd(n);
  int b = 0;
  if (n - k > 0) {
    b = count_odd(n - k);
  }  
  int c = a - b; 
  return c % 2 == 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << (solve(n, k) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}