#include <bits/stdc++.h>

using namespace std;

struct E {
  int t;
  string who; 
  string msg;

  int size() const {
    if (t == 0) {
      return (int)msg.size();
    }
    return 0;
  }

  void display() const {
    if (t == 0) {
      cout << who << ':' << msg;
    } else if (t == -1) {
      cout << '-' << who;
    } else {
      cout << '+' << who;
    }
    cout << '\n';
  }
};

E new_e_mod(int t, const string &who) {
  return E { .t = t, .who = who };
}

E new_e_send(const string &who, const string &msg) {
  return E { .t = 0, .who = who, .msg = msg };
}

E parse_e(const string &s) {
  int n = (int)s.size();
  int t = 0;
  if (s[0] == '-') {
    t = -1;
  } else if (s[0] == '+') {
    t = 1;
  }
  if (t != 0) {
    return new_e_mod(t, s.substr(1, n - 1));
  }
  int pos = (int)s.find(":");  
  return new_e_send(s.substr(0, pos), s.substr(pos + 1, n - pos));
}

int solve(int n, const vector<string> &a) {
  vector<E> ee(n);
  for (int i = 0; i < n; ++i) {    
    ee[i] = parse_e(a[i]);    
  }
  int ans = 0;
  map<string, E> dict;
  for (int i = 0; i < n; ++i) {
    if (ee[i].t == 0) {            
      int cnt = (int)dict.size();
      ans += cnt * ee[i].size();      
    } else if (ee[i].t == -1) {
      dict.erase(ee[i].who);
    } else if (ee[i].t == 1) {      
      auto it = dict.find(ee[i].who);
      if (it == dict.end()) {
        dict.insert({ee[i].who, ee[i]});
      }
    }
  }
  return ans;
}

int main() {
  vector<string> a;
  string s;
  while (getline(cin, s)) {
    a.push_back(s);
  }  
  int n = (int)a.size();
  cout << solve(n, a) << endl;
  return 0;
}