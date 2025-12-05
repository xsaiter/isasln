#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n) {
  vector<int> a(n);
  a[0] = 2;
  for (int i = 1; i < n; ++i) {    
    a[i] = a[i - 1] + 1;
  }
  return a;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto a = solve(n);
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " ";
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}