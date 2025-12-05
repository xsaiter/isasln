#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<string> a;  
  string s;
  while (getline(cin, s)) {    
    a.push_back(s);
  }
  int n = (int)a.size();  
  int w = - 1;
  for (int i = 0; i < n; ++i) {
    w = max(w, (int)a[i].size());
  }  
  for (int i = 1; i <= w + 2; ++i) {
    cout << '*';
  }   
  cout << '\n';
  bool state = true;
  for (int i = 0; i < n; ++i) {
    int len = (int)a[i].size();
    cout << '*';
    int l = 0, r = 0;
    auto Align = [&] {
      int d = w - len;
      if (state) {          
        l = (d - 1) / 2;
        r = w - l - len;
      } else {
        r = (d - 1) / 2;
        l = w - r - len;
      }
      state = !state;
    };
    if (w % 2 == 0) {
      if (len % 2 == 0) {
        l = w / 2 - len / 2;
        r = w - l - len;
      } else {
        Align();
      }
    } else {
      if (len % 2 == 0) {
        Align();
      } else {
        l = (w - len) / 2;
        r = l;
      }
    }    
    for (int j = 1; j <= l; ++j) {
      cout << ' ';
    }
    cout << a[i];
    for (int j = 1; j <= r; ++j) {
      cout << ' ';
    }
    cout << '*' << '\n';
  }
  for (int i = 1; i <= w + 2; ++i) {
    cout << '*';
  }   
  cout << endl;
  return 0;
}