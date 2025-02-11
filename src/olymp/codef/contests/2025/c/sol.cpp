#include <bits/stdc++.h>

using namespace std;

struct Rec {
  int len;  
  int v;
};

int solve(int n, int k, vector<int> &a) {      
  sort(begin(a), end(a));
  vector<Rec> b;
  int v = a[0];
  int len = 1;
  for (int i = 1; i < n; ++i) {                
    if (a[i] == v) {
      ++len;
    } else {
      Rec rec {
        .len = len,
        .v = v
      };      
      b.push_back(rec);
      len = 1;
      v = a[i];
    }
  }
  Rec last {
    .len = len,
    .v = v
  };
  b.push_back(last);

  sort(begin(b), end(b), 
    [](const Rec &x,  const Rec &y) {
      return x.v < y.v; });        

  int m = (int)b.size();
  int p = 0, q = 0, buf = 0, res = 0;  
  while (true) {
    if (q - p + 1 <= k) {
      buf += b[q].len;
      res = max(res, buf);      
    } else {      
      ++p;      
      res = max(res, buf);
      buf -= b[p - 1].len;      
      buf += b[q].len;
      res = max(res, buf);
    }    
    ++q;
    if (p == m || q == m) {
      break;
    }
    if (b[q].v != b[q - 1].v + 1) {     
      p = q;
      q = p;        
      res = max(res, buf);
      buf = 0;      
    } 
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }    
    cout << solve(n, k, a) << "\n";
  }
  cout << endl;
  return 0;
}