#include <bits/stdc++.h>

using namespace std;

#define N 201

int b[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, v;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v;
    ++(b[v + 100]);
  }
  for (int i = 0; i < N; ++i) {
    v = b[i];
    for (int j = 0; j < v; ++j) {
      cout << i - 100 << " ";
    }
  }
  cout << endl;
  return 0;
}