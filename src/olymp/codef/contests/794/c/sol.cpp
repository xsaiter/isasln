#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

using P = pair<char, int>;

vector<P> a, b;
int head, tail;
int n;

int first_index(vector<P> &x) {
  int m = x.size();
  for (int i = 0; i < m; ++i) {
    if (x[i].second > 0) {
      return i;
    }
  }
  return -1;
}

int share(vector<P> &x, int rem) {
  int m = x.size();
  for (int i = 0; i < m; ++i) {
    if (x[i].second == 0) {
      continue;
    }
    int d = x[i].second - rem;
    if (d >= 0) {
      return i;
    } else {
      rem -= x[i].second;
    }
  }
  return -1;
}

void proc(bool is_a, string &res) {
  auto ia = first_index(a);
  auto ib = first_index(b);
  int rem = 0;
  int d = tail - head + 1;
  if (d % 2 == 0) {
    rem = d / 2;
  } else {
    rem = (d + 1) / 2;
  }
  if (is_a) {
    if (a[ia].first < b[ib].first) {
      res[head] = a[ia].first;
      a[ia].second--;
      ++head;
    } else {
      int idx = share(a, rem);
      res[tail] = a[idx].first;
      a[idx].second--;
      --tail;
    }
  } else {
    if (b[ib].first > a[ia].first) {
      res[head] = b[ib].first;
      b[ib].second--;
      ++head;
    } else {
      int idx = share(b, rem);
      res[tail] = b[idx].first;
      b[idx].second--;
      --tail;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  cin >> s >> t;
  n = s.size();
  head = 0, tail = n - 1;
  sort(begin(s), end(s), [](auto x, auto y) { return x < y; });
  sort(begin(t), end(t), [](auto x, auto y) { return x > y; });
  a.push_back({s[0], 1});
  b.push_back({t[0], 1});
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      a.back().se++;
    } else {
      a.push_back({s[i], 1});
    }
    if (t[i] == t[i - 1]) {
      b.back().se++;
    } else {
      b.push_back({t[i], 1});
    }
  }
  string res(n, '?');
  int k = 0;
  while (k < n) {
    proc(!(k % 2), res);
    ++k;
  }
  cout << res << endl;
  return 0;
}