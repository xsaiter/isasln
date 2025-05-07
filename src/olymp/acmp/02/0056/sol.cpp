#include <bits/stdc++.h>

using namespace std;

void display(set<string> s) {
  vector<string> v(begin(s), end(s));
  int n = (int)s.size();
  for (int i = 0; i < n; ++i) {
    cout << v[i];    
    if (i != n - 1) {
     cout << ", ";
    }
  }  
}                           

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<string> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  set<string> f;
  for (int i = 0; i < n; ++i) {
   f.insert(a[i]);
  }
  set<string> mf;
  set<string> af;
  for (int i = 0; i < m; ++i) {
    if (find(a.begin(), a.end(), b[i]) != a.end()) {
      mf.insert(b[i]);
    } else {
      af.insert(b[i]);
    }
  }  
  cout << "Friends: "; display(f); cout << '\n';
  cout << "Mutual Friends: "; display(mf); cout << '\n';
  cout << "Also Friend of: "; display(af);
  cout << endl;
  return 0;
}