#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  constexpr int s = 201;
  int b[s];
  memset(b, 0, sizeof(int) * s);
  for (int i = 0; i < n; ++i) {
    b[a[i] + 100]++;
  }
  int k = 0;
  for (int i = 0; i < s; ++i) {
    if (b[i] > 0) {
      for (int j = 0; j < b[i]; ++j) {
        a[k] = i - 100;
        ++k;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  fflush(stdout);
  return 0;
}