#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  vector<int> act(q, 0);
  vector<string> v(q);
  map<string, int> m; 
  for (int i = 0; i < q; ++i) {    
    string a, b;
    cin >> a >> b;    
    auto f = m.find(a);
    if (f != m.end()) {
      v[(*f).se] = a;
    } else {
      m.insert(b, i);
      v[i] = a;
      act[v[q]] = 1;
    }    
  }
  for (int i = 0; i < q; ++i) {
    if (act[i] > 0) {
      cout << v[i] << bb[i] << "\n";
    }
  }
  cout << endl;
  return 0;
}