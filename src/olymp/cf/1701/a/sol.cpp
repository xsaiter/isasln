#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a) {  
  if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) {
    return 0;
  }
  if (a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1) {
    return 2;
  }
  return 1;
}

int main() {
  int t;
  cin >> t;    
  while (t--) {  		 		                             
    vector<int> a(4);
    cin >> a[0] >> a[1];
    cin >> a[2] >> a[3];
    cout << solve(a) << '\n';
  }
  cout << endl;
  return 0;
}
