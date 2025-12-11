#include <bits/stdc++.h>

using namespace std;

const int N = 26;

int ord(char c) { 
  return (int)c - (int)'a';
}

char to_ch(int x) {
  return (char)(x + (int)'a');
}

string remove_spaces(const string &s) {
  int n = (int)s.size();
  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    if (s[i] != ' ') {
      oss << s[i];
    }
  }
  return oss.str();
}

string ltrim(const string &s) {
  ostringstream oss;
  int n = (int)s.size();
  bool start = true;
  for (int i = 0; i < n; ++i) {
    if (s[i] == ' ') {
      if (!start) {
        oss << s[i];
      } 
    } else {
      start = false;
      oss << s[i];
    }
  }
  return oss.str();
}

string rtrim(const string &s) {
  ostringstream oss;
  int n = (int)s.size();
  bool start = true;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == ' ') {
      if (!start) {
        oss << s[i];
      } 
    } else {
      start = false;
      oss << s[i];
    }
  }
  return oss.str();
}

string trim(const string &s) {
  return rtrim(ltrim(s));
}

bool find_key(const string &str, const string &t, vector<int> &key) {    
  string s = trim(str);
  int n = (int)s.size(); 
  int m = (int)t.size();
  if (n != m) {
    return false;
  }  
  for (int i = 0; i < n; ++i) {
    if (s[i] == ' ' || t[i] == ' ') {
      continue;
    }
    int x = key[ord(s[i])];
    if (x == -1) {
      key[ord(s[i])] = (int)ord(t[i]);
    }
  }  
  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    if (s[i] == ' ') {
      continue;
    }
    oss << to_ch(key[ord(s[i])]);
  }
  string r = oss.str();
  if (r != t) {
    return false;
  }
  return true;
}

int main() {    
  string s;
  getline(cin, s);  
  int n = atoi(s.c_str());
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    getline(cin, a[i]);
  }  
  string pattern = "the quick brown fox jumps over the lazy dog";
  bool has_key = false;  
  vector<int> real_key;
  for (int i = 0; i < n; ++i) {
    vector<int> key(N, -1);
    if (find_key(a[i], pattern, key)) {
      has_key = true;
      real_key = key;
      break;
    }
  }  
  if (has_key) {        
    for (int i = 0; i < n; ++i) {
      ostringstream oss;      
      int m = (int)a[i].size();
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == ' ') {
          oss << ' ';
        } else {
          oss << to_ch(real_key[ord(a[i][j])]);
        }
      }      
      cout << oss.str() << '\n';
    }
  } else {
    cout << "No solution";
  }
  cout << endl;
  return 0;
}