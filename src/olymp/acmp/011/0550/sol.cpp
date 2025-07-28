#include <bits/stdc++.h>

using namespace std;

bool is_leap(int n) {
  return n % 400 == 0 || (n % 4 == 0 && n % 100 != 0);  
}

string day(int n) {
  if (is_leap(n)) {
    return "12/09/";
  }
  return "13/09/";  
}

string fmt_year(int n) {
  string s = to_string(n);
  if (n < 10) {
    return "000" + s;
  } 
  if (n < 100) {
    return "00" + s;
  }
  if (n < 1000) {
    return "0" + s;
  }
  return s;
}

string solve(int n) {  
  return day(n) + fmt_year(n);
}          

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}