#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {  
  int va = -1, na = 0;
  int vb = -1, nb = 0;
  for (int i = 0; i < n; ++i) {
    if ((i + 1) % 2 == 0) {
      if (a[i] > va) {
        va = a[i];        
      }
      na++;
    } else {
      if (a[i] > vb) {
        vb = a[i];        
      }
      nb++;
    }
  }
  return max(va + na, vb + nb);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}