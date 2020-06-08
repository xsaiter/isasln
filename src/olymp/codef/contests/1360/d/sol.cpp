#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int solve(int n, int k) {
  int res = 0;
  if (n <= k) {
    res = n;
  } else {
    for (int i = k; i >= 1; --i) {
      int x = n % i;
      if (x == 0) {
        res = n / i;
        break;
      }
    }
  }  
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;   
  while (t--) {
    int n, k;
    cin >> n >> k;
    printf("%d\n", solve(n ,k));
  }
  return 0;
}
