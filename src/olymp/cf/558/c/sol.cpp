#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int solve(int n, vector<int> &a) {  
  int m = *(max_element(a.begin(), a.end())) + 1;      
  m *= 2;
  vector<int> b(m), c(m);  
  for (int i = 0; i < n; ++i) {    
    int x = a[i];
    c[x] += 1;
    int step = 0;
    while(1) {
      x *= 2;      
      if (x >= m) {
        break;
      }
      step++;
      b[x] += step;
      c[x] += 1;
    }
    x = a[i];
    step = 0;
    while(x > 1) {
      x /= 2;
      step++;
      b[x] += step;
      c[x] += 1;      
    }
  }  
  int ans = INF;
  for (int i = 0; i < m; ++i) {    
    if (c[i] == n) {
      ans = min(ans, b[i]);
    }
  }  
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}
 