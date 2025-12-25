#include <bits/stdc++.h>

using namespace std;

bool hit(int x) {
  string s = to_string(x);
  return s.back() == '5';
}

struct R {
  int v, k;
};

int solve(int n, vector<int> &a) {
  int ans = 0;
  int mx = *max_element(a.begin(), a.end());
  vector<R> wins;
  for (int i = 0; i < n; ++i) {   
    if (a[i] == mx) {
      wins.push_back(R {.v = mx, .k = i});
    }
  }
  for (int i = 0; i < n; ++i) {
    
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}

