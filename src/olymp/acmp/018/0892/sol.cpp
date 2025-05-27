#include <bits/stdc++.h>

using namespace std;

string solve(int n) {  
  if (n == 1 || n == 2 || n == 12) {
    return "Winter";
  }
  if (n == 3 || n == 4 || n == 5) {
    return "Spring";
  }
  if (n == 6 || n == 7 || n == 8) {
    return "Summer";
  }
  if (n == 9 || n == 10 || n == 11) {
    return "Autumn";
  }
  return "Error";
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}