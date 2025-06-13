#include <bits/stdc++.h>

using namespace std;

vector<int> calc(int n, const vector<int> &a, bool pos) {
  int beg = -1, fin = -1;  
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0 && pos) {
      beg = i;
      break;
    }
    if (a[i] < 0 && !pos) {
      beg = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] > 0 && pos) {
      fin = i;
      break;
    }
    if (a[i] < 0 && !pos) {
      fin = i;
      break;
    }
  }  
  vector<int> res;
  if (beg != -1 && fin != -1) {
    for (int i = beg; i <= fin; ++i) {    
      if ((a[i] > 0 && pos) || (a[i] < 0 && !pos)) {
        res.push_back(i);      
      }
    }
  }
  return res;
}

vector<int> solve(int n, const vector<int> &a) {
  vector<int> b = calc(n, a, true);
  vector<int> c = calc(n, a, false);
  int pos = 0;
  for (auto i : b) {
    pos += a[i];
  } 
  int neg = 0;
  for (auto i : c) {
    neg += abs(a[i]);
  } 
  if (pos > neg) {
    return b;
  }
  return c;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> res = solve(n, a);
  int m = (int)res.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {    
    cout << (res[i] + 1) << ' ';
  }
  cout << endl;
  return 0;
}