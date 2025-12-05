#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int d = 2;
    cout << d << '\n';    
    int prev = 1;
    cout << prev << " ";    
    vector<int> a(n, 0);
    a[prev - 1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        if (prev * d == j) {
          cout << j << " ";
          a[j - 1] = 1;
          prev = j;
        }
      }
      if (a[i - 1] == 0) {
        cout << i << " ";
        prev = i - 1;
      }
    }        
    cout << '\n';
  }
  cout << endl;
  return 0;
}

// 1 2 4 3 5 6 
// 1 2 4 3 6 5 