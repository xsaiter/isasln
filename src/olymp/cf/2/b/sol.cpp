#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9;

int fa(int n, int p) {
  if (n == 0) {
    return 1;
  }
  int ans = 0;
  while (n % p == 0) {
    ans += 1;
    n /= p;
  }
  return ans;
}

void display(int ans, const string &s) {
  cout << ans << '\n' << s << endl;
}

void show(int n, int ans, const vector<vector<char>> &di, int ci, int cj) {  
  ostringstream oss;
  if (ans > 1 && ci > -1 && cj > -1) {
    ans = 1;
    for (int i = 0; i < cj; ++i) {
      oss << 'R';
    }
    for (int i = 0; i < ci; ++i) {
      oss << 'D';
    }
    for (int i = 0; i < n - cj - 1; ++i) {
      oss << 'R';
    }
    for (int i = 0; i < n - ci - 1; ++i) {
      oss << 'D';
    }
    display(ans, oss.str());
  } else {    
    int ii = n - 1, jj = n - 1;
    while (ii != 0 || jj != 0) {
      oss << di[ii][jj];
      if (di[ii][jj] == 'D') {
        --ii;
      } else if (di[ii][jj] == 'R') {
        --jj;
      }
    }
    string s = oss.str();
    reverse(s.begin(), s.end());
    display(ans, s);
  }  
}

void solve(int n, const vector<vector<int>> &a) {
  vector<vector<int>> dp2(n, vector<int>(n, INF));
  vector<vector<int>> dp5(n, vector<int>(n, INF));
  vector<vector<char>> di2(n, vector<char>(n));
  vector<vector<char>> di5(n, vector<char>(n));
  int ci = -1, cj = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 0) {
        ci = i; cj = j;
      }
    }
  }
  dp2[0][0] = fa(a[0][0], 2);
  dp5[0][0] = fa(a[0][0], 5);  
  for (int i = 1; i < n; ++i) {
    dp2[i][0] = dp2[i - 1][0] + fa(a[i][0], 2); di2[i][0] = 'D';
    dp5[i][0] = dp5[i - 1][0] + fa(a[i][0], 5); di5[i][0] = 'D';    
  }
  for (int j = 1; j < n; ++j) {
    dp2[0][j] = dp2[0][j - 1] + fa(a[0][j], 2); di2[0][j] = 'R';
    dp5[0][j] = dp5[0][j - 1] + fa(a[0][j], 5); di5[0][j] = 'R';
  }
  int v, x, y;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      v = fa(a[i][j], 2);
      x = dp2[i - 1][j] + v;
      y = dp2[i][j - 1] + v;
      if (x < y) {
        dp2[i][j] = x;
        di2[i][j] = 'D';
      } else {
        dp2[i][j] = y;
        di2[i][j] = 'R';
      }
      v = fa(a[i][j], 5);
      x = dp5[i - 1][j] + v;
      y = dp5[i][j - 1] + v;
      if (x < y) {
        dp5[i][j] = x;
        di5[i][j] = 'D';
      } else {
        dp5[i][j] = y;
        di5[i][j] = 'R';
      }
    }
  }
  if (dp2[n -  1][n - 1] < dp5[n - 1][n - 1]) {
    show(n, dp2[n -  1][n - 1], di2, ci, cj);    
  } else {
    show(n, dp5[n -  1][n - 1], di5, ci, cj);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  solve(n, a);  
  return 0;
}