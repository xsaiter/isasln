#include <bits/stdc++.h>

using namespace std;

int sum_range(const vector<int> &b, int i, int j) {
  int v = 0;
  if (i > 0) {
    v = b[i - 1];
  }
  return b[j] - v;
}

int solve(vector<int> &b, int n) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int len = j - i + 1;
      int sum = sum_range(b, i, j);      
      if (len == sum) {
        ++res;
      }
    }
  }  
  return res;
}

inline int asi(char c) {
  return (int)(c) - (int)'0';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;  

  while (t--) {
    int n;
    cin >> n;
    
    string s;
    cin >> s;       
              
    vector<int> b(n);
    b[0] = asi(s[0]);
    for (int i = 1; i < n; ++i) {
      b[i] = b[i - 1] + asi(s[i]);
    }            

    cout << solve(b, n) << "\n";    
  }

  cout << endl;   

  return 0;
}