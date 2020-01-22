#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

#define All(c) begin(c), end(c)

int main() {
  int n;
  cin >> n;
  vi a;
  vi b;
  a.reserve(n);
  b.reserve(n);
  int c;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    if (c % 2 != 0) {
      a.push_back(c);
    } else {
      b.push_back(c);
    }
  }
  copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
  cout << "\n";
  copy(begin(b), end(b), ostream_iterator<int>(cout, " "));
  cout << "\n";
  cout << ((b.size() >= a.size()) ? "YES" : "NO") << endl;
  return 0;
}