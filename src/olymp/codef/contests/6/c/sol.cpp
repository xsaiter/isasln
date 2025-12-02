#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  int p = 0, q = n - 1;
  int ra = 0, rb = 0;
  while (p < q) {
    if (t[p] < t[q]) {
      
      ++p;
    } else if (t[p] > t[q]) {
      --q;
    } else {
      ++p; --q;
    }    
  }
  int a = p, b = q;
  cout << a << ' ' << b << endl;
  return 0;
}