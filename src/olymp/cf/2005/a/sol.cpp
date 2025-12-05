#include <bits/stdc++.h>

using namespace std;

string solve(int n) {
  string ss = "aeiou";
  ostringstream os;
  int rem = n % 5;  
  int k = (n - rem) / 5;
  for (int i = 0; i < 5; ++i) {
    for (int j = 1; j <= k; ++j) {      
      os << ss[i];
    }
    if (rem > 0) {
      os << ss[i];
      --rem;
    }    
  }  
  return os.str();
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << solve(n) << '\n';
  }
  cout << endl;
  return 0;
}