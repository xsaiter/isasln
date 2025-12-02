#include <bits/stdc++.h> 

using namespace std;

int main() {
  int n; 
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));  
  for (int i = 0; i < n; i++) {    
    cin >> a[i][i];
  } 
  if (n % 2 == 0) {
    for (int i = 1; i < n; i++) {
      if (i % 2 == 0) {
        for (int m = 0, j = i; j < n; j++, m++) {
           a[j][m] = min(a[j - 1][m], a[j][m + 1]);
        }
      } else {
        for (int m = 0, j = i; j < n; j++, m++) {
          a[j][m] = max(a[j - 1][m], a[j][m + 1]);
        }
      }
    }
  } else {
    for (int i = 1; i < n; i++) {
      if (i % 2 == 0) {
        for (int m = 0, j = i; j < n; j++, m++) {
          a[j][m] = max(a[j - 1][m], a[j][m + 1]);
        }
      } else {
        for (int m = 0, j = i; j < n; j++, m++) {
          a[j][m] = min(a[j - 1][m], a[j][m + 1]);
        }
      }
    }
  }
  cout << a[n - 1][0] << endl;
  return 0;
}
