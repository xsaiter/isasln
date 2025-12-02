#include <bits/stdc++.h>

using namespace std;

const int N = 31;

int solve(vector<int> &a) {  
  int mx = *max_element(a.begin(), a.end());
  int k = 0;
  for (int i = 0; i < N; ++i) {
    if (a[i] < mx) {
      k += 1;
    }
  }
  if (k == 4) {
    return mx;
  }
  return ans;
}

int main() {
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  cout << solve(a) << endl;
  return 0;
}