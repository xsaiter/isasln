#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int max_res = 0;
  for (int i = 0; i < n; ++i) {
    int t = 0;
    int res = 0;
    for (int j = i; j < n - 1; ++j) {
      if (a[j] < a[j + 1]) {
        if (t == 0) {
          t = 1;
        } else {
          if (t == 1) {
            j = n - 1;
          } else {
            ++res;
            t = 1;
          }
        }
      } else if (a[j] > a[j + 1]) {
        if (t == 0) {
          t = 2;
        } else {
          if (t == 2) {
            j = n - 1;
          } else {
            ++res;
            t = 2;
          }
        }
      }
    }
    if (res > max_res) {
      max_res = res;
    }
  }
  max_res++;
  cout << max_res << endl;
  return 0;
}