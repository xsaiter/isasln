#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &a, int n, int x) {
  string mask(x, 1);
  mask.resize(n, 0);
  do {
    int z = 0;
    for (int i = 0; i < n; ++i) {
      if (mask[i]) {
        z += a[i];
      }
    }            
    if (z % 2 > 0) {
      return true;
    } 
  } while (prev_permutation(mask.begin(), mask.end()));
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int t = 0; t < tt; ++t) {
    int n, x;
    cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i <  n; ++i) {
      cin >> a[i];
		}	
	  bool res = solve(a, n, x);		
		cout << (res ? "yes" : "no") << endl;
  }
  return 0;
}