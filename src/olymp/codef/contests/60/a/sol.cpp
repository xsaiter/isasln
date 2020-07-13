#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  int n, m;
  cin >> n >> m;  
  vector<P> pp(m);  
  cin >> ws;
  for (int i = 0; i < m; ++i) {            
    string s;        
    getline(cin, s);    
    int a, b;
    if (s[7] == 'l') a = 0; else a = 1;
    int n = (int)s.size();
    int j = n;    
    while (s[--j] != ' ') {}    
    b = atoi(s.substr(j + 1, n - j + 1).c_str());
    pp[i] = {a, b};
  }    
  for (auto &p : pp) {
    
  }
  cout << endl;
  return 0;
}