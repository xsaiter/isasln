#include <bits/stdc++.h>

using namespace std;

const string e = "2.7182818284590452353602875";

string solve(int n) {
  if (n == 0) {
    return "3";
  }
  const int len = (int)e.size();
  int j = n + 2;
  j = min(j, len - 1);
  int c = (int)e[j];
  if (j + 1 < len) {
    int next = e[j + 1];
  }  
  return e.substr(0, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;  
  cout << solve(n) << endl;
  return 0;
}