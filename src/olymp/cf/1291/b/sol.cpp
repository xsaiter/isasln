#include <bits/stdc++.h>

using namespace std;

string solve(vector<int> &a, int n) {
  int pos_beg = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] < i) {
      break;
    }
    pos_beg = i;
  }
  int pos_end = n;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] < n - 1 - i) {
      break;
    }
    pos_end = i;
  }
  return pos_end <= pos_beg ? "Yes" : "No";
}

int main() {
  Solution sln;
  auto ress = sln.letterCombinations("2");
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(a, n) << "\n";
  }
  cout << endl;
  return 0;
}