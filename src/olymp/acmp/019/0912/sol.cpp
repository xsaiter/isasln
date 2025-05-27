#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(101);
  for (int i = 0; i < n; ++i) {
    b[a[i]] += 1;
  }
  int mb = -1e9;
  int ans = 0;
  bool dup = false;
  for (int i = 1; i <= 100; ++i) {    
    if (b[i] > mb) {
      mb = b[i];
      ans = i;
      dup = false;
    } else if (b[i] == mb) {
      dup = true;
    }
  }
  if (dup) {
    cout << 0;
  } else {
    cout << ans;
  }
  cout << endl;
  return 0;
}