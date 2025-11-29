#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

struct E {
  int a, b, c;

  bool operator>(const E &e) const {
    return c > e.c;
  }
};

int solve(int n, int m, const vector<E> &ee) {
  priority_queue<E, vector<E>, greater<E>> pq;  
  int ans = 0
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<E> ee(m);
  for (int i = 0; i < m; ++i) {
    cin >> ee[i].a >> ee[i].b >> ee[i].c;
  }
  cout << solve(n, m, ee) << endl;  
  return 0;
}