#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, const vector<string> &ss) {
  vector<int> res(n);
  const int K = 4;
  for (int i = n - 1; i >= 0; --i) {        
    for (int j = 0; j < K; ++j) {
      if (ss[i][j] == '#') {
        res[n - 1 - i] = j + 1;
        break;
      }
    }
  }
  return res;	
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> ss(n);
    for (int i = 0; i < n; ++i) {
      cin >> ss[i];
    }
    vector<int> res = solve(n, ss);
    for (int i = 0; i < n; ++i) {
      cout << res[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}