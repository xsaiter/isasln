#include <bits/stdc++.h>

using namespace std;

int calc(const vector<int> &a) {
  int res = 0;
  int mx = 0;
  int n = (int)a.size();
  for (int i = 0; i < n; ++i) {
    res += a[i];
    mx = max(mx, a[i]);
  }
  res -= mx;
  return res;
}

int answer(int n, const string &s, int skip) {  
  vector<int> va(256, 0);
  vector<int> vb(256, 0);
  for (int i = 0; i < n; ++i) {
    if (i == skip) {
      continue;
    }
    int c = (int)s[i];
    int j = i;
    if (i > skip) {
      --j;
    }    
    if (j % 2 == 0) {
      va[c]++;
    } else {
      vb[c]++;
    }
  }  
  return calc(va) + calc(vb);    
}

int solve(int n, const string &s) {
  if (n % 2 == 0) {
    return answer(n, s, -1);    
  }
  int res = INT_MAX;
  for (int i = 0; i < n; ++i) {
    res = min(res, answer(n, s, i));
  }  
  return res + 1;
}

int main() {  
  int t;
  cin >> t;
  while (t--) {
     int n;
     cin >> n;
     string s;
     cin >> s;
     cout << solve(n, s) << '\n';
  }
  cout << endl;
  return 0;
}
