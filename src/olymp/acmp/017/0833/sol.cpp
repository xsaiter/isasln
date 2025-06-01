#include <bits/stdc++.h>

using namespace std;

struct P {
  int l, r;
  int len() const {
    return r - l;
  }
};

void rec(string &s, string &t, int l, int r, vector<P> &res) {
  if (l >= r) {
    return;
  }
  vector<P> b;
  bool beg = false;
  for (int i = l; i <= r; ++i) {
    P x;
    if (s[i] != t[i]) {      
      if (beg) {
        continue;
      } else {
        beg = true;
        x.l = i;
      }
    } else {
      if (beg) {
        x.r = i - 1;
        b.push_back(x);
      }
      beg = false;
    }
    if (beg && i == r) {
      x.r = i;
      b.push_back(x);
    }
  }
  cout << "---\n";
  for (int i = 0; i < (int)b.size(); ++i) {
    cout << b[i].l << "-" << b[i].r << "\n";
  }
  cout << "---\n";  
  int m = (int)b.size();
  for (int i = 0; i < m; ++i) {
    int p = b[i].l;
    int q = b[i].r;
    while (p < q) {
      swap(s[p], s[q]);      
      ++p; --q;
    }
    res.push_back(b[i]);
    rec(s, t, b[i].l, b[i].r, res);
  }               
}

vector<P> solve(string &s, string &t) {  
  int n = (int)s.size();  
  vector<P> res;
  rec(s, t, 0, n - 1, res);
  return res;
}

int main() {
  string s, t;
  cin >> s >> t;
  vector<P> r = solve(s, t);
  int m = (int)r.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << r[i].l + 1 << ' ' << r[i].r + 1 << '\n';
  }
  cout << endl;
  return 0;
}

/*
AGCTA -> GACTA -> TCAGA -> ACTGA
ATCGA
1 2, 1 4, 1 3
*/