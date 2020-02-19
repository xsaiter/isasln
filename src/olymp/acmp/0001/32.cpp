#include <bits/stdc++.h>

using namespace std;

void as_min_str(string &s) {
  sort(s.begin(), s.end(), [](auto l, auto r) { return l < r; });
  const int n = s.size();
  if (n == 1 && s[0] == '0') {
    return;
  }
  if (s[0] != '0') {
    return;
  }
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != '0') {
      j = i;
      swap(s[0], s[j]);
      break;
    }
  }
}

void as_max_str(string &s) {
  sort(s.begin(), s.end(), [](auto l, auto r) { return l > r; });
  const int n = s.size();
  if (n == 1 && s[0] == '0') {
    return;
  }
  if (s[0] != '0') {
    return;
  }
}

// max {a - b}
int main() {
  string rr = "10";
  as_min_str(rr);
  int a, b;
  cin >> a >> b;
  int res = 0;
  if (a > 0) {
    string sa = to_string(a);
    as_max_str(sa);
    a = atoi(sa.c_str());
    if (b > 0) {
      string sb = to_string(b);
      as_min_str(sb);
      b = atoi(sb.c_str());
    } else if (b < 0) {
      b = -b;
      string sb = to_string(b);
      as_max_str(sb);
      b = atoi(sb.c_str());
      b = -b;
    }
  } else if (a < 0) {
    a = -a;
    string sa = to_string(a);
    as_min_str(sa);
    a = atoi(sa.c_str());
    a = -a;
    if (b > 0) {
      string sb = to_string(b);
      as_min_str(sb);
      b = atoi(sb.c_str());
    } else if (b < 0) {
      b = -b;
      string sb = to_string(b);
      as_max_str(sb);
      b = atoi(sb.c_str());
      b = -b;
    }
  } else {
    if (b > 0) {
      string sb = to_string(b);
      as_min_str(sb);
      b = atoi(sb.c_str());
    } else if (b < 0) {
      b = -b;
      string sb = to_string(b);
      as_max_str(sb);
      b = atoi(sb.c_str());
      b = -b;
    }
  }
  res = a - b;
  cout << res << endl;
  return 0;
}