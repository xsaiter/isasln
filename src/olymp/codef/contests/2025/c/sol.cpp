#include <bits/stdc++.h>

using namespace std;

struct Rec {
  int len;  
  int value;
};

int solve(int n, int k, vector<int> &a) {      
  sort(begin(a), end(a));
  vector<Rec> b;
  int cur = a[0];
  int len = 1;
  for (int i = 1; i < n; ++i) {                
    if (a[i] == cur) {
      ++len;
    } else {
      Rec rec;
      rec.len = len;
      rec.value = cur;
      b.push_back(rec);
      len = 1;
      cur = a[i];
    }
  }
  Rec last;
  last.len = len;
  last.value = cur;
  b.push_back(last);

  sort(begin(b), end(b), 
    [](const Rec &x,  const Rec &y) {
      return x.value < y.value; });
        
  // 3 4 5 6 7   9 10 11 12 13 14 15 16 17 18   25 26 27

  int m = (int)b.size();
  int p = 0, q = 0, loc = 0, res = 0;
  while (true) {
    if (q - p + 1 <= k) {
      loc += b[q].len;
      res = max(res, loc);      
    } else {      
      ++p;
      q = p;
      res = max(res, loc);
      loc = b[p].len;
      res = max(res, loc);
    }    
    ++q;
    if (q == m) {
      break;
    }
    if (b[q].value != b[q - 1].value + 1) {     
      p = q;
      q = p;        
      res = max(res, loc);
      loc = 0;
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