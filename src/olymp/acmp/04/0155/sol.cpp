#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.0001;

double cca(double c1, double c2) {
  return c1 + c2;
}

double ccb(double c1, double c2) {
  return c1 * c2 / (c1 + c2);
}

double calc(int q, int p, vector<double> &a) {
  int len = p - q;
  int K = 1 << len;  
  for (int i = 0; i < N; +i) {
  }
  return res;
}

bool solve(int n, vector<int> &a, double c) {  
  int N = 1 << (n - 1);
  for (int i = 0; i < N; ++i) {
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  double c;
  cin >> c;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << (solve(n, a, c) ? "YES" : "NO") << endl;
  return 0;
}
