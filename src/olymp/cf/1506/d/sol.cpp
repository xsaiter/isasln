#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int solve(vector<int> &a, int n) {  
  map<int, int> m;
  for (int i = 0; i < n; ++i) {
    auto it = m.find(a[i]);
    if (it != m.end()) {
      (*it).se++;
    } else {
      m.insert({a[i], 1});
    }
  }    
  priority_queue<int> pq;
  for (const auto &e : m) {    
    pq.push(e.se);
  }
  int len = (int)pq.size();
  while (len > 1) {
    auto x = pq.top(); pq.pop();
    auto y = pq.top(); pq.pop();
    --x; --y;
    if (x > 0) pq.push(x);
    if (y > 0) pq.push(y);
    len = (int)pq.size();
  }
  if (len == 0) return 0;
  return pq.top();
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n; ++i) {
      cin >> a[i];
    }   
    cout << solve(a, n) << "\n";
  }
  cout << endl;
  return  0;
}