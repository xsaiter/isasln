#include <bits/stdc++.h>

using namespace std;

bool ok(const string &s, int p, int q) {
  int cnt = 0;
  for (int i = p; i <= q; ++i) {
    if (s[i] == '(') {
      ++cnt;
    } else {
      --cnt;
    }
    if (cnt < 0) {
      return false;
    }
  }
  return cnt == 0;
}

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();  
  int best_cnt = 0;
  int best_len = -1;
  int p = 0;
  while (p < n) {
    int z = 0;
    int len = 0;    
    int cur = 0;    
    for (int i = p; i < n; ++i) {      
      if (s[i] == '(') {
        ++z;
      } else {
       --z;
      }
      if (z < 0) {
        p = i;        
        break;        
      }
      if (z == 0) {
        ++cur;
        len = cur;
      }
      if (z > 0) {
        ++cur;
      }
    }    
    if (len > best_len) {
      best_len = len;
      best_cnt = 1;
    } else if (len == best_len) {
      best_cnt++;
    }
    ++p;
  }
  if (best_len == 0) {
    best_cnt = 1;
  }
  cout << best_len << ' ' << best_cnt << endl;
  return 0;
}