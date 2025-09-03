#include <bits/stdc++.h>

using namespace std;

int solve(const string &s) {
  int n = (int)s.size();
  int ok = 0, err = 1;
  stack<char> st;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (c == ')' || c == ']' || c == '}') {
      if (st.empty()) {
        return err;
      }
      char t = st.top();
      if (c == ')' && t != '(') {
        return err;
      }
      if (c == ']' && t != '[') {
        return err;
      }
      if (c == '}' && t != '{') {
        return err;
      }
      st.pop();
    } else {
      st.push(c);
    }
  }
  if (!st.empty()) {
    return err;
  }
  return ok;
}

int main() {
  vector<string> a;
  while(1) {
    string s;
    if (getline(cin, s)) {
      a.push_back(s);
    } else {
      break;
    }
  }
  int n = (int)a.size();  
  for (int i = 0; i < n; ++i) {
    cout << solve(a[i]);
  }
  cout << endl;
  return 0;
}