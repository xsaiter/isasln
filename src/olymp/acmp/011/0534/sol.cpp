#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  int k;
  cin >> k;
  vector<int> p(k);
  for (int i = 0; i < k; ++i) {
    cin >> p[i];
  }
  vector<int> a(N);
  for (int i = 0; i < k; ++i) {
    a[p[i]] += 1;
  }
  for (int i = 0; i < n; ++i) {
    if (c[i] < a[i + 1]) {
      cout << "yes";
    } else {
      cout << "no";
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}