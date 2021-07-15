#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

vi solve(int n, int x, int y) {
  vi res(n);
  return res;
}

int main() {
  int t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    vi res = solve(n, x, y);
    copy(begin(res), end(res), ostream_iterator(cout, " "));
  }
  cout << endl;
  return 0;
}