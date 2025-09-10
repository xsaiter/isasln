#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
  if (x == 1 || x == 2) {
    return true;
  }
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int asc(string &s, int m) {
  sort(begin(s), end(s), less<char>());
  return atoi(s.c_str());
}

int desc(string &s, int m) {
  sort(begin(s), end(s), greater<char>());
  return atoi(s.c_str());
}

int main() {
  int n;
  cin >> n;
  string s = to_string(n);
  int m = (int)s.size();
  int a = asc(s, m);
  int b = desc(s, m);
  if (is_prime(a) && is_prime(b)) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;
  return 0;
}