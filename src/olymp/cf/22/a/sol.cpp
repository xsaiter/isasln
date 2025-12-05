#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int mi = 101, me = 101, x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x < mi) {
      me = mi;
      mi = x;
    } else if (x > mi) {      
      me = min(x, me);
    }
  }  
  if (me < 101 && mi != me) { cout << me; } else { cout << "NO"; }
  cout << endl;
  return 0;
}