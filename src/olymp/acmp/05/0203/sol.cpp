#include <bits/stdc++.h>

using namespace std;

int solve(const string &s, const string &t) {  
  int n = (int)s.size();  
  for (int k = 0; k < n; ++k) {    
   if (s[0] == t[k]) {
     bool yes = true;
     for (int i = k; i < n; ++i) {
       if (s[i - k] != t[i]) {
         yes = false;
         break;
       }
     }
     if (yes) {       
       for (int i = 0; i < k; ++i) {
         if (s[n - k + i] != t[i]) {
           yes = false;
         }
       }
       if (yes) {
         return k;         
       }
     }
   }
  }
  return -1;
}

int main() {
  string s, t;
  cin >> s >> t;
  cout << solve(s, t) << endl;
  return 0;
}