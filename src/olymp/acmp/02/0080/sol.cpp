#include <bits/stdc++.h>

using namespace std;

const string YES = "YES";
const string NO = "NO";
const string ERR = "ERROR";

bool is_dig(char c) {
  return c == '0' || c == '1'
    || c == '2' || c == '3'
    || c == '4' || c == '5'
    || c == '6' || c == '7'
    || c == '8' || c == '9';
}

bool is_op(char c) {
  return c == '+' || c == '-' 
    || c == '*' || c == '/';
}

bool is_eq(char c) {
  return c == '=';
}

string solve(const string &s) {
  const int n = (int)s.size();
  int state = 1;
  int a = 0, b = 0, c = 0;
  char op = '+';
  string buf;
  bool first = true;
  for (int i = 0; i < n; ++i) {
    if (state == 1) {
      if (is_dig(s[i])) {
        buf += s[i];
        first = false;
      } else if (is_op(s[i])) {
        if (first) {
          if (s[i] == '-') {
            first = false;
            buf += s[i];            
          } else {
            return ERR;
          }
        } else {
          op = s[i];
          if (buf.empty()) {
            return ERR;
          }
          a = atoi(buf.c_str());
          buf = "";
          state = 2;
          first = true;
        }
      } else {
        return ERR;
      }
    } else if (state == 2) {
      if (is_dig(s[i])) {
        buf += s[i];
      } else if (is_eq(s[i])) {
        if (buf.empty()) {
          return ERR;
        }
        b = atoi(buf.c_str());
        buf = "";
        state = 3;
      } else {
        return ERR;
      }
    } else if (state == 3) {
      if (is_dig(s[i])) {
        buf += s[i];
        first = false;
      } else {
        if (first) {
          if (s[i] == '-') {
            first = false;
            buf += s[i];
          } else {
            return ERR;
          }          
        } else {
          return ERR;
        }
      }
    }
  }
  if (state < 3) {
    return ERR;
  }    
  if (buf.empty()) {
    return ERR;
  }
  c = atoi(buf.c_str());
  bool yes = false;
  if (op == '+') {
    yes = (a + b == c);
  } else if (op == '-') {
    yes = (a - b == c);
  } else if (op == '*') {
    yes = (a * b == c);
  } else if (op == '/') {
    if (b == 0) {
      yes = false;
    } else {
      yes = (a / b == c);
    }
  }
  if (yes) {
    return YES;
  }
  return NO;
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}