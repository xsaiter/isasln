#include <bits/stdc++.h>

using namespace std;

int hm(const string &s, const string &t) {
  int k = (int)s.size();  
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    if (s[i] != t[i]) {
      ++ans;
    }
  }
  return ans;
}

vector<int> solve(const string &s, int n, const vector<string> &a) {  
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {    
    d[i] = hm(s, a[i]);
  }
  int mx = *min_element(d.begin(), d.end());
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    if (d[i] == mx) {
      b.push_back(i + 1);
    }
  }
  sort(b.begin(), b.end());
  return b;
}

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b = solve(s, n, a);
  int m = (int)b.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {  
    cout << b[i] << ' ';
  }
  cout << endl;
  return 0;
}