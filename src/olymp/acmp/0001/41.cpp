#include <bits/stdc++.h>

using namespace std;

#define N 201

int b[N];

int main() {
  int n, v;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v);
    ++(b[v + 100]);
  }
  for (int i = 0; i < N; ++i) {
    v = b[i];
    for (int j = 0; j < v; ++j) {
      printf("%d ", i - 100);
    }
  }
  fflush(stdout);
  return 0;
}