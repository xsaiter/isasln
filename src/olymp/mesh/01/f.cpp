#include <bits/stdc++.h>

using namespace std;

std::string calc(int x1, int x2, int x3, int x4, int x5) {
  constexpr unsigned int n = 14;
  int a[n]{0};
  ++a[x1];
  ++a[x2];
  ++a[x3];
  ++a[x4];
  ++a[x5];
  int f23 = 0;
  int f2 = 0;
  int chain = 0;
  for (unsigned int i = 0; i < n; ++i) {
    if (a[i] == 5) {
      return "Impossible";
    }
    if (a[i] == 4) {
      return "Four of a Kind";
    }
    if (a[i] == 2) {
      if (f23 == 3) {
        f23 = -1;
      } else {
        f23 = 2;
      }
      f2++;
    } else if (a[i] == 3) {
      if (f23 == 2) {
        f23 = -1;
      } else {
        f23 = 3;
      }
    }
    if (f23 == -1) {
      return "Full House";
    }
    if (a[i] == 0) {
      chain = 0;
    } else {
      ++chain;
      if (chain == 5) {
        return "Straight";
      }
    }
  }
  if (f23 == 3) {
    return "Three of Kind";
  }
  if (f2 == 1) {
    return "One Pair";
  }
  if (f2 == 2) {
    return "Two Pairs";
  }
  return "Nothing";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x1, x2, x3, x4, x5;
  cin >> x1 >> x2 >> x3 >> x4 >> x5;
  auto res = calc(x1, x2, x3, x4, x5);
  cout << res << endl;
  return 0;
}