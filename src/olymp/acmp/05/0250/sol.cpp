#include <bits/stdc++.h>

using namespace std;

struct E {
  vector<int> w;
  int n;
  int v;  
};

int solve(int n) {  
  string s = to_string(n);
  int m = (int)s.size();
  vector<E> a;  
  for (int i = 0; i < m; ++i) {
    int v = (int)s[i] - (int)'0';

    auto it = find_if(begin(a), end(a), 
      [&](const E &x) { return x.v == v; });

    if (it != a.end()) {
      (*it).n += 1;
      (*it).w.push_back(m - i);
    } else {
      E e;
      e.v = v;
      e.n = 1;
      e.w.push_back(m - i);
      a.push_back(e);
    }
  }
  for (auto &e : a) {
    int xx = e.n;
  }
  int res = 0;
  return res;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}