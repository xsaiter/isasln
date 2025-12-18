#include <bits/stdc++.h>

using namespace std;

int ord(char c) {
  return (int)c - (int)'0';
}

bool solve(string &s) {
  int n = (int)s.size();
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = ord(s[i]);
  }
  int sum = accumulate(a.begin(), a.end(), 0);
  if (sum % 9 == 0) {
    return true;
  }  
  int n2 = 0, n3 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 2) {
      n2 += 1;
    } else if (a[i] == 3) {
      n3 += 1;
    }
  }  
  for (int i = 0; i <= n2; ++i) {
    for (int j = 0; j <= n3; ++j) {
     int x = 2 * i + 6 * j;
     if ((sum + x) % 9 == 0) {
       return true;
     }
    }
  }
  return false;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    cout << (solve(s) ? "YES" : "NO") << endl;
  }
  cout << endl;
  return 0;
}