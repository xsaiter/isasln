#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

auto greater_pii = [](const pii &l, const pii &r) { return l.se < r.se; };
using PQ = priority_queue<pii, vector<pii>, decltype(greater_pii)>;

struct S { int t[3]; };
vector<S> ss;

bool can(PQ &pq) {  
  int n = (int)pq.size();
  if (n < 3) {
    return false;
  }
  auto a = pq.top(); pq.pop();
  auto b = pq.top(); pq.pop();
  auto c = pq.top(); pq.pop();
  S s;
  s.t[0] = a.fi; a.se--;
  s.t[1] = b.fi; b.se--;
  s.t[2] = c.fi; c.se--;
  sort(begin(s.t), end(s.t), greater<int>());
  ss.push_back(s);
  if (a.se > 0) pq.push(a); 
  if (b.se > 0) pq.push(b); 
  if (c.se > 0) pq.push(c);
  return true;
}

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  sort(begin(r), end(r));
  vector<pii> v;
  v.push_back({r[0], 1});
  for (int i = 1; i < n; ++i) {
    if (r[i] == r[i - 1]) {
      v.back().se++;
    } else {
      v.push_back({r[i], 1});
    }
  }  
  PQ pq(begin(v), end(v), greater_pii);
  while (can(pq)) { }  
  cout << ss.size() << "\n";  
  for (auto &x : ss) {
    cout << x.t[0] << " " << x.t[1] << " " << x.t[2] << "\n";
  }
  cout << endl;
  return 0;
}