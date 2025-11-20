#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int INF = 1e9;

struct A {
  string name;
  int score;
};

struct R {
  int pos, cur;
};

R new_r(int pos, int cur) {
  return R{ .pos = pos, .cur = cur };
}

struct V {
  vector<R> r;

  void add(int pos, int score) {
    int cur = score;
    if (!r.empty()) {
      cur = r.back().cur + score;
    }
    r.push_back(new_r(pos, cur));
  }

  int last_score() const {
    return r.back().cur;
  }

  int len() const {
    return (int)r.size();
  }

  R at(int pos) {
    return r[pos];
  }
};

map<string, V> create_map(int n, const vector<A> &a) {
  map<string, V> m;
  for (int i = 0; i < n; ++i) {
    auto it = m.find(a[i].name);
    if (it != m.end()) {
      (*it).se.add(i, a[i].score);
    } else {
      V v;
      v.add(i, a[i].score);
      m.insert({ a[i].name, v });
    }
  }
  return m;
}

string solve(int n, const vector<A>& a) {
  map<string, V> m = create_map(n, a);  
  vector<A> bb;
  for (const auto& kv : m) {
    bb.push_back(A{ .name = kv.fi, .score = kv.se.last_score() });
  }
  sort(bb.begin(), bb.end(),
    [](const A& l, const A& r) { return l.score > r.score; });
  int nbb = (int)bb.size();
  vector<string> cands;
  int lim = bb[0].score;
  cands.push_back(bb[0].name);
  for (int i = 1; i < nbb; ++i) {
    if (bb[i].score == lim) {
      cands.push_back(bb[i].name);
    } else {
      break;
    }
  }    
  string best_name;
  int best = INF;
  int ncands = (int)cands.size();      
  for (int i = 0; i < ncands; ++i) {    
    auto it = m.find(cands[i]);    
    int nr = (*it).se.len();
    int pos = INF;
    for (int j = 0; j < nr; ++j) {
      R r = (*it).se.at(j);      
      if (r.cur >= lim) {
        pos = r.pos;
        break;
      }      
    }
    if (pos < best) {
      best = pos;
      best_name = cands[i];
    }
  }
  return best_name;
}

int main() {
  int n;
  cin >> n;
  vector<A> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].name >> a[i].score;
  }  
  cout << solve(n, a) << endl;
  return 0;
}