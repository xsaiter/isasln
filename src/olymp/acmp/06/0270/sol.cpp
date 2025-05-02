#include <bits/stdc++.h>

using namespace std;

enum class Check {
  Java,
  Cpp,
  Error,
  Any
};

Check check_lang(const string &s, int n) {  
  if (!islower(s[0])) {
    return Check::Error;
  }
  for (int i = 1; i < n; ++i) {
    if (islower(s[i])) {
    }
  }
  return Check::Any;
}

string from_cpp_to_java(const string &s, int n) {
  return s;
}

string from_java_to_cpp(const string &s, int n) {
  return s;
}

string solve(string &s) {
  int n = (int)s.size();
  Check c = check_lang(s, n);
  if (c == Check::Java) {
    return from_java_to_cpp(s, n);
  } else if (c == Check::Cpp) {
    return from_cpp_to_java(s, n);
  } else if (c == Check::Any) {
    return s;
  }
  return "Error!";  
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}