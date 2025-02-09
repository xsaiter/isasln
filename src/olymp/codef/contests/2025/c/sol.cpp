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

  int m = (int)b.size();  
  
  for (int i = 0; i < m; ++i) {
    cout << b[i].value << "-" << b[i].len << '\t';
  }  

  // 4-5  5-2  6-2 result = 9
  // 2-2 3-3 4-3 5-2 result = 6 (k = 2)

  int res = 0;
  int p = 0, q = 0;  
  int loc = b[p].len;  
  while (p < m && q < m) {
    if (q - p + 1 <= k) {
      ++q;
      loc += b[q].len;
    } else {
      res = max(res, loc);
      loc -= b[p].len;
      ++p;      
    }    
    if (b[q] + 1 == b[q + 1]) {
      ++q;
    } else {
      p = q;
    }
    ++q;
    if (q >= m) {
      break;
    }
    loc += b[q].len;      
    res = max(res, loc);    
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
    cout << "t=" << t << '\n';
    int res = solve(n, k, a);
    cout << "__result: " << res << "\n\n";
  }
  cout << endl;
  return 0;
}

vector<int> a(n);