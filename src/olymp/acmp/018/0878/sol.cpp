#include <bits/stdc++.h>

using namespace std;

const int N = 26;

struct R {
  int v;
  int pos;
};

R new_r(int v, int pos) {
  return R {.v = v, .pos = pos};
}

int dig(char c) {
  return (int)c - (int)'A';
}

bool solve(string &s, vector<int> &a) {
  vector<R> b(N);
  for (int i = 0; i < N; ++i) {    
    b[i] = new_r(dig(s[i]), i);
  }
  sort(begin(b), end(b), 
    [](const R &x, const R &y) {
      return x.v < y.v;
    });

  for (int i = 0; i < N; ++i) {
    if (b[i].v < i) {
      return false;
    }
  }
  
  for (int i = 0; i < N; ++i) {
    a[i] = b[i].pos + 1;
  }
  return true;
}

int main() {
  string s;
  cin >> s;  
  vector<int> a(N);
  bool ans = solve(s, a);
  if (ans) {
    cout << "YES" << '\n';
    for (int i = 0; i < N; ++i) {
      cout << a[i] << ' ';
    }
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}