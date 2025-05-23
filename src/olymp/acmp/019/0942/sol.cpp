#include <bits/stdc++.h>

using namespace std;

const int N = 300;

int cc5(int n, const vector<int> &a) {
  int res = 0;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += a[i];
    if (res + cur <= N) {
      res += cur;
    }
  }
  return res;
}

int cc3(int n, const vector<int> &a) {
  int res = 0;
  int cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    cur += a[i];
    if (res + cur <= N) {
      res += cur;
    }
  }
  return res;
}

int cc1(int n, vector<int> a) {
  sort(begin(a), end(a));
  int res = 0;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += a[i];
    if (res + cur <= N) {
      res += cur;
    }
  }
  return res;
}

int solve(int n, vector<int> &a) {
  int c1 = cc1(n, a);
  int c3 = cc3(n, a);
  int c5 = cc5(n, a);

  if (c1 <= c3) {
    if (c1 <= c5) {
      return 1;
    } else {
      return 5;
    }
  } else {
    if (c3 <= c5) {
      return 3;
    } else {
      return 5;
    }
  }  
  throw("Err");
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }  
  cout << solve(n, a) << endl;
  return 0;
}