#include <bits/stdc++.h>

using namespace std;

const int N = 10;

void calc(int num, vector<int> &a) {
  while (num > 9) {
    int k = num % 10;
    a[k] += 1;
    num = (num - k) / 10;
  }
  a[num] += 1;
}

vector<int> solve(int n, int m) {
  vector<int> a(N);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int num = i * j;
      calc(num, a);
    }
  }
  return a;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a = solve(n, m);
  for (int i = 0; i < N; ++i) {
    cout << a[i] << '\n';
  }
  cout << endl;
  return 0;
}