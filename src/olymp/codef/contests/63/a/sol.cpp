#include <bits/stdc++.h>

using namespace std;

struct E {
  string name, pos;  
  int order;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<E> ee(n);
  for (int i = 0; i < n; ++i) {
    string name, pos;  
    cin >> name >> pos;
    ee[i] = {name, pos, i};
  }
  auto sort_cmp = [](const E &l, const E &r) {
    if (l.pos == r.pos) {
      return l.order < r.order;
    } else {
      if (l.pos == "rat") {
        return true;
      } else if (l.pos == "woman") {
        if (r.pos == "rat") {
          return false; 
        } else if (r.pos == "child") {
          return l.order < r.order;
        } else {
          return true;
        }      
      } else if (l.pos == "child") {
        if (r.pos == "rat") {
          return false;
        } else if (r.pos == "woman") {
          return l.order < r.order;
        } else {
          return true;
        }                  
      } else if (l.pos == "man") { 
        if (r.pos == "rat" || r.pos == "child" || r.pos == "woman") {
          return false;
        } else {
          return true;
        }
      } else if (l.pos == "captain") { 
        if (r.pos == "rat" || r.pos == "child" || r.pos == "woman" || r.pos == "man") {
          return false;
        } else {
          return true; 
        }        
      }     
    }
    return false;
  };
  sort(begin(ee), end(ee), sort_cmp);
  for (int i = 0; i < n; ++i) {
    cout << ee[i].name << "\n";
  }
  cout << endl;
  return 0;
}