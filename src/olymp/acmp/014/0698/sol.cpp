#include <bits/stdc++.h>

using namespace std;

struct Suit {
  char c;  
};

struct Rank {
  char c;  

  int rank() const {
    if (c == '6') {
      return 6;
    } 
    if (c == '7') {
      return 7;
    }
    if (c == '8') {
      return 8;
    }
    if (c == '9') {
      return 9;
    }
    if (c == 'T') {
      return 10;
    }
    if (c == 'J') {
      return 11;
    }
    if (c == 'Q') {
      return 12;
    }
    if (c == 'K') {
      return 13;
    }
    if (c == 'A') {
      return 14;
    }
    throw("Unexpected rank: " + c);
  }
};

bool operator==(const Suit &x, const Suit &y) {
  return x.c == y.c;
}

bool operator!=(const Suit &x, const Suit &y) {
  return !(x == y);
}

bool operator==(const Rank &x, const Rank &y) {
  return x.c == y.c;
}

bool operator!=(const Rank &x, const Rank &y) {
  return !(x.c == y.c);
}

struct C {  
  Rank r;
  Suit s;
  int rank(const Suit &t) const {
    if (t == s) {
      return r.rank() * 1024;
    }
    return r.rank();
  }
};

bool operator==(const C &x, const C &y) {
  return x.r == y.r && x.s == y.s;
}

C parse_card(const string &s) {  
  Rank rank { .c = s[0] };
  Suit suit { .c = s[1] };
  return C { .r = rank, .s = suit };
}

bool solve(int n, int m, const Suit &t, vector<C> &a, vector<C> &b) {    
  auto cmp = [&](const C &x, const C &y) -> bool {
    return x.rank(t) < y.rank(t);
  };
  sort(begin(a), end(a), cmp);
  sort(begin(b), end(b), cmp);
  vector<bool> used(n, false);
  for (int i = 0; i < m; ++i) {
    bool passed = false;
    for (int j = 0; j < n; ++j) {      
      if (!used[j]) {
        bool cmp_rank = b[i].r.rank() < a[j].r.rank();
        bool is_ta = a[j].s == t;
        bool is_tb = b[i].s == t;
        bool eq_suite = a[j].s == b[i].s;

        if (is_tb) {
          if (is_ta && cmp_rank) {
            passed = true;
          }
        } else {                    
          if ((!is_ta && eq_suite && cmp_rank) || is_ta) {
            passed = true;
          }
        }
        if (passed) {
          used[j] = true;
          break;
        }
      }      
    }
    if (!passed) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  Suit t;
  cin >> t.c;  
  vector<C> a(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    a[i] = parse_card(s);
  }
  vector<C> b(m);
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    b[i] = parse_card(s);
  }
  cout << (solve(n, m, t, a, b) ? "YES" : "NO") << endl;
  return 0;
}