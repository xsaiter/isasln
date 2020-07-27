#include <bits/stdc++.h>

using namespace std;
using R = long long;

bool solve(vector<int> &a, int n) {
  R sum_all = accumulate(begin(a), end(a), 0LL);
  if (sum_all % 2 != 0) return false;
  R biggest = *(max_element(begin(a), end(a)));
  R sum_other = sum_all - biggest;   
  return biggest <= sum_other;
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
  cout << (solve(a, n) ? "YES" : "NO") << endl;
  return 0;
}