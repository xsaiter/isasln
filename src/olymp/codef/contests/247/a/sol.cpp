#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b;
  int pos = 0, neg = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 0) {
      ++pos;
    } else {
      ++neg;
      if (neg == 3) {
        b.push_back(pos + neg - 1);
        pos = 0;
        neg = 1;
      }
    }
  }
  b.push_back(pos + neg);
  cout << b.size() << "\n";                   
  copy(begin(b), end(b), ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}