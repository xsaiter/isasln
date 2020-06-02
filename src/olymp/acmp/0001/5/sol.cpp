#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

#define All(c) begin(c), end(c)
#define Print_i(c) copy(All(c), ostream_iterator<int>(cout, " "))

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
  Print_i(a);
  cout << "\n";
  Print_i(b);
  cout << "\n";
  cout << ((b.size() >= a.size()) ? "YES" : "NO") << endl;
  return 0;
}