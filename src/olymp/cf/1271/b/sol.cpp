#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using R = pair<vi, bool>;

R solve(string s, int n, char a, char b) {
  vector<int> pos;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == a) {
      s[i] = b;
      s[i + 1] = ((s[i + 1] == a) ? b : a);
      pos.push_back(i + 1);
    }
  }
  if (s[n - 1] == a) {
    return {pos, false};
  }
  return {pos, true};
}

void show_pos(const vi &pos) {
  cout << pos.size() << "\n";
  for (auto &i : pos) {
    cout << i << " ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  R r = solve(s, n, 'W', 'B');
  if (r.second) {
    show_pos(r.first);
  } else {
    r = solve(s, n, 'B', 'W');
    if (r.second) {
      show_pos(r.first);
    } else {
      cout << "-1";
    }
  }
  cout << endl;
  return 0;
}