#include <bits/stdc++.h>

using namespace std;

struct S {  
  map<string, int> m;  

  bool has(const string &name) const {
    return m.find(name) != m.end();
  }

  string next(const string &name) {    
    auto it = m.find(name);        
    (*it).second += 1;
    ostringstream oss;
    oss << name;
    oss << (*it).second;
    string new_name = oss.str();
    add_new({new_name, 0});
    return new_name;
  }

  void add_new(const string &name) {
    m.insert({name, 0});
  }
};

vector<string> solve(int n, vector<string> &a) {  
  vector<string> b(n);
  S s;
  for (int i = 0; i < n; ++i) {
    if (!s.has(a[i])) {
      b[i] = "OK";
      s.add_new(a[i]);
    } else {
      b[i] = s.next(a[i]);
    }
  }
  return b;
}

int main() {  
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
   }
   vector<string> b = solve(n, a);
   for (int i = 0; i < n; ++i) {
     cout << b[i] << '\n';
   }
  cout << endl;
  return 0;
}