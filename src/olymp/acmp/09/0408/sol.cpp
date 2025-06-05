#include <bits/stdc++.h>

using namespace std;

const string ERR = "Impossible.";

string conv(int k, const string& s, int& ok) {
  int m = (int)s.size();
  if (m > k) {
    ok = -1;
    return ERR;
  }
  int d = k - m;
  ostringstream oss;
  int nbeg = 0, nend = 0;
  if (d % 2 != 0) {
    nbeg = (d - 1) / 2;
  } else {
    nbeg = d / 2;
  }
  nend = d - nbeg;
  for (int i = 0; i < nbeg; ++i) {
    oss << '+';
  }
  oss << s;
  for (int i = 0; i < nend; ++i) {
    oss << '+';
  }
  return oss.str();
}

string solve(int k, int n, const vector<string>& s) {
  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    int ok = 0;
    string t = conv(k, s[i], ok);
    if (ok == -1) {
      return ERR;
    }
    oss << t << '\n';
  }
  return oss.str();
}

int main() {
  int k, n;
  cin >> k >> n;  
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    cout << s[i] << '\n';
  }  
  cout << endl;
  //cout << solve(k, n, s) << endl;
  return 0;
}