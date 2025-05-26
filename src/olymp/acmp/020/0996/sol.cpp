#include <bits/stdc++.h>

using namespace std;

// a[n] = a[n-1] + 3
// a[n] = a[n-1] + 2
     
int solve(int n) {
  int ans = 1;
  set<int> st;
  st.insert(ans);
  for (int i = 2; i <= n; ++i) {
    if (st.contains(i)) {
      ans += 3;      
    } else {
      ans += 2;
    }
    st.insert(ans);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}