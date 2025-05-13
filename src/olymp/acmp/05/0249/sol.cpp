#include <bits/stdc++.h.>

using namespace std;

// ({}}
int solve(const string &s) {  
  int n = (int)s.size();  
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  int ans = 0;
  stack<char> st;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      st.push(s[i]);
    } else {
      if (st.empty()) {        
        ans += 1;
      } else {
        char c = st.top();
        if ((s[i] == ')' && c != '(') ||
            (s[i] == ']' && c != '[') ||
            (s[i] == '}' && c != '{')) {
          ans += 1;
        } else {
          st.pop();
        }
      }
    }
  }
  ans += st.size();
  return ans;
}

int main() {
  string s;
  cin >> s;  
  cout << solve(s) << endl;
  return 0;
}