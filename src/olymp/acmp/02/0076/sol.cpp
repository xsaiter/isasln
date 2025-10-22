#include <bits/stdc++.h>

using namespace std;

struct E {
  int v;
  bool to;
  
  int enter() const {
    if (to) {
      return 0;
    }
    return 1;
  }
};

E new_e(int v, bool to) {
  return E {.v = v, .to = to};
}

int parse_v(const string &s) {  
  int hh = atoi(s.substr(0, 2).c_str());
  int mm = atoi(s.substr(3, 2).c_str());
  return hh * 60 + mm;
}

E read_e(bool to) {
  string s;
  cin >> s;
  int v = parse_v(s);
  return new_e(v, to);
}

int solve(int n, vector<E> &ee) {  
  auto e_cmp = [](const E &a, const E &b) {
    if (a.v != b.v) {
      return a.v < b.v;
    }
    return a.enter() < b.enter();
  };
  sort(begin(ee), end(ee), e_cmp);
  int ans = 0;
  int cur = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (ee[i].to) {
      cur += 1;
    } else {
      cur -= 1;
    }
    ans = max(ans, cur);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<E> ee(2 * n);
  for (int i = 0; i < n; ++i) {    
    ee[2 * i] = read_e(true);
    ee[2 * i + 1] = read_e(false);
  }
  int ans = solve(n, ee);
  cout << ans << endl;
  return 0;
}