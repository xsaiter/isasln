#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> a(3);
    for (int i = 0 ; i < 3; ++i) {
      cin >> a[i];
    }
    sort(begin(a), end(a));    
    int d = a[0] - (a[2] - a[1]);
    if (d < 0) {      
      a[1] += a[0];
    } else {
      a[1] += a[2] - a[1];
      a[1] += d / 2;
      a[2] += d / 2;
    }
    cout << min(a[1], a[2]) << "\n";
  }
  cout << endl;
  return 0;
}