#include <bits/stdc++.h>

using namespace std;

struct A {
  int t, p;
};

int main() {
  int n, v;
  cin >> n >> v;
  vector<A> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].t >> a[i].p;
  }
  return 0;
}