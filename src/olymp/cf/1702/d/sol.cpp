#include <bits/stdc++.h>

using namespace std;

int get_code(char c) {
  return (int)c - (int)'a' + 1;
}

string solve(string &w, int p) {  
  int n = (int)w.size();  
  vector<int> a(27, 0);
  int total = 0;
  for (int i = 0; i < n; ++i) {
    int code = get_code(w[i]);    
    total += code;
    a[code]++;
  }
  for (int i = 26; i >= 1; --i) {
    while (a[i] > 0 && total > p) {
      total -= i; --a[i];
    }
    if (total <= p) {
      break;
    }
  }
  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    int code = get_code(w[i]);
     if (a[code] > 0) {
       --a[code];
       oss << w[i];
     }
  }  
  return oss.str();
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string w;
    cin >> w;
    int p;
    cin >> p;
    cout << solve(w, p) << '\n';
  }
  cout << endl;
  return 0;
}