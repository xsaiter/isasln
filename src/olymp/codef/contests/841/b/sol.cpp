#include <bits/stdc++.h>

using namespace std;
using R = long long;

R sum_range(const vector<int> &a, int from, int to) {
  R s = 0;
  for (int i = from; i < to; ++i) {
    s += a[i];
  }
  return s;
}

int other_player(int player) { return player == 1 ? 2 : 1; }
int rem_of_player(int player) { return player == 1 ? 1 : 0; }

int solve(const vector<int> &a, int n) {
  int player = 1;
  int i = 0;
  auto can_move = [&](R s) {
    int rem = rem_of_player(player);
    int k = n - 1;
    bool can = false;
    while (k >= 0) {
      s -= a[k];
      if (s % 2 == rem) {
        i = k;
        can = true;
        break;
      }
      --k;
    }
    return can;
  };
  while (true) {
    auto s = sum_range(a, i, n);
    auto rem = rem_of_player(player);
    if (s % 2 == rem) {
      return player;
    }
    if (!can_move(s)) {
      return other_player(player);
    }
    player = other_player(player);
  }
  return player;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << (solve(a, n) == 1 ? "First" : "Second") << endl;
  return 0;
}