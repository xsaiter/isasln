#include <bits/stdc++.h>

using namespace std;

inline int sum_digits(int a) {
  int res = 0;
  while (a != 0) {
    res += a % 10;
    a = a / 10;
  }
  return res;
}

bool better(int a, int b) {
  int sa = sum_digits(a);
  int sb = sum_digits(b);
  return (sa == sb) ? (a < b) : (sa > sb);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) {
      a.push_back(i);
    }
  }
  sort(begin(a), end(a), better);
  cout << a[0] << endl;
  return 0;
}