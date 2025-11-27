#include <bits/stdc++.h>

using namespace std;

struct P {
  int ii, jj;
};

vector<vector<char>> solve(int n, int m, vector<string> &a) {
  vector<vector<char>> b(n, vector<char>(m));
  vector<P> p(4, {-1, -1});  
  bool hit = false;
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      if (a[i][j] == '*') {
        p[0]= {i, j};
        hit = true;
        break;
      }
    }
    if (hit) {
      break;
    }
  }
  hit = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '*') {
        p[1] = {i, j};
        hit = true;
        break;
      }
    }
    if (hit) {
      break;
    }
  }
  hit = false;
  for (int j = m - 1; j >= 0; --j) {
    for (int i = 0; i < n; ++i) {
      if (a[i][j] == '*') {
        p[2]= {i, j};
        hit = true;
        break;
      }
    }
    if (hit) {
      break;
    }
  }
  hit = false;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (a[i][j] == '*') {
        p[3] = {i, j};
        hit = true;
        break;
      }
    }
    if (hit) {
      break;
    }
  }  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (p[1].ii <= i && i <= p[3].ii 
        && p[0].jj <= j && j <= p[2].jj) {
        b[i][j] = '*';
      } else {
        b[i][j] = '.';
      }
    }
  }  
  return b;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<char>> b = solve(n, m, a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << b[i][j];
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}