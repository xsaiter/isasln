#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Seg {
  int a, b;
};

// min(L/M)

// 1/2 vs 2/3 vs 3/4

Seg solve(int n, vector<int> &a) {
  sort(a.begin(), a.end());
  Seg s;
  int d = INF;
  int p = - 1, q = -1;
  for (int i = 1; i < n; ++i) {
    int dd = a[i] - a[i - 1];
    if (d > dd) {
      d = dd;
      p = i - 1;
      q = i;
    }    
  } 
  return { .a = a[p], .b = a[q] };
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0 ; i < n; ++i) {
    cin >> a[i];
  }
  Seg s = solve(n, a);
  cout << s.a << " " << s.b << endl;
  return 0;
}