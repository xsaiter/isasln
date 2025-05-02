#include <bits/stdc++.h>

using namespace std;

const string NO = "NO SOLUTION";

string s_pow(const string &s, int k) {
  int n = (int)s.size();
  const int lim = 1023;
  ostringstream os;
  int len = 0;
  while(k-- && len <= lim) {
    os << s;
    len += n;
  }
  string t = os.str();
  len = min(lim, (int)t.size());
  return t.substr(0, len);  
}

string s_sq(const string &s, int k) {  
  int n = (int)s.size();
  k = abs(k);
  int rem = n % k;
  if (rem > 0) {
    return NO;
  }
  int len = n / k;  
  for (int i = 0; i < len; ++i) {        
    for (int j = 1; j < k; ++j) {
      if (s[i] != s[len * j + i]) {
        return NO;
      }
    }
  }  
  return s.substr(0, len);
}

string solve(string &s, int k) {
  if (k > 0) {
    return s_pow(s, k);
  }
  return s_sq(s, k);
}

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << solve(s, k) << endl;
  return 0;
}