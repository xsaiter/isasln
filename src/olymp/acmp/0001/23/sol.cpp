#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    if(n % i == 0) {
      res += i;
    }
  }
  cout << res << endl;
  return 0;
}