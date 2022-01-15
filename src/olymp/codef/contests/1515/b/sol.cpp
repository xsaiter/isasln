#include <bits/stdc++.h>

using namespace std;

bool is_sq(int a) {
  int b = sqrt(a);
  return b * b == a;
}

bool solve(int n) {
  if (n % 2 == 0 && is_sq(n / 2)) return true;
  if (n % 4 == 0 && is_sq(n / 4)) return true;
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool can = solve(n);
    if (can) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}