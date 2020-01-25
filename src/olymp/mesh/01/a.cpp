#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int a, b;
  cin >> a >> b;
  int mx = max(a, b);
  int mi = min(a, b);
  vector<int> res;
  for (int i = mi; i <= mx; ++i) {
    if (is_prime(i)) {
      res.push_back(i);
    }
  }
  if (res.empty()) {
    cout << "Absent";
  } else {
    copy(begin(res), end(res), ostream_iterator<int>(cout, "\n"));
  }
  cout << endl;
  return 0;
}