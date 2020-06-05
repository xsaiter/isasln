#include <bits/stdc++.h>

#define N 1001

int a[N];
bool b[N];
int mask[N];

using namespace std;

void init_a() {
  fill_n(a, N, 0);
}

void init_b() {
  fill_n(b, N, false);
}

void init_mask(int x) {  
  fill_n(mask, N, 0);
  fill_n(mask, x, 1);
}

bool solve(int n, int x) {
  init_mask(x);
  init_b();
  for (int i = 0; i < n; ++i) {
    b[i] = (a[i] % 2) == 0 ? false : true;
  }
  do {
    bool z = false;
    for (int i = 0; i < n; ++i) {
      if (mask[i]) {
        z ^= b[i];
      }
    }
    if (z) {
      return true;
    } 
  } while (prev_permutation(mask, mask + n));
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
    init_a();
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }	
    cout << (solve(n, x) ? "yes" : "no") << endl;
  }
  return 0;
}