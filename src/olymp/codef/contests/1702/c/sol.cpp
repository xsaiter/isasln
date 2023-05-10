#include <bits/stdc++.h>

using namespace std;

bool solve(int n, vector<int> &u, int a, int b) {
  int pa = -1, pb = -1;
  for (int i = 0; i < n; ++i) {
    if (u[i] == a) {
      pa = i;
    } else if (u[i] == b) {
      pb = i;      
    }
    if (pa != -1 && pb != -1 && pa < pb) {
      return true;
    }
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {    
    int n, k;
    cin >> n >> k;    
    vector<int> u(n);
    for (int i = 0; i < n; ++i) {
      cin >> u[i];
    }    
    for (int i = 0; i < k; ++i) {
      int a, b;
      cin >> a >> b;
      cout << (solve(n, u, a, b) ? "YES" : "NO") << '\n';
    }    
  }
  cout << endl;
  return 0;
}
