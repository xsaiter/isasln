#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int fin(int n) {
  if (n == 2) return 1;
  int x = n - 1;
  for (int i = x; i < 100000; ++i) {
    if (!is_prime(i)) {
       if (is_prime(x + i)) {
         return i;
       }
    }
  }
  return -1;
}

int main() {  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int f = fin(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) { 
          cout << f;
        } else {
          cout << 1;
        }
        cout << " ";
      }
      cout << '\n';
    }
  }
  cout << endl;
  return 0;
}