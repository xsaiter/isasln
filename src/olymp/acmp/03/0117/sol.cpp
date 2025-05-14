#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct P {
  int x, y;
};

int cross_prod(const P& a, const P& b, const P& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int dist2(const P& a, const P& b) {
  return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

void show(const string& text, int n, const vector<P>& a) {
  cout << text << ":\n";
  for (int i = 0; i < n; ++i) {
    cout << a[i].x << "-" << a[i].y << "\n";
  }
}

P top_of(stack<P>& st) {
  return st.top();
}

P before_top_of(stack<P>& st) {
  P buf = st.top(); st.pop();
  P res = st.top();
  st.push(buf);
  return res;
}

stack<P> get_hull(int n, vector<P>& a) {
  stack<P> hull;
  if (n < 4) {
    for (int i = 0; i < n; ++i) {
      hull.push(a[i]);
    }
    return hull;
  }

  int min_y_pos = 0;
  int min_y = a[0].y;

  for (int i = 1; i < n; ++i) {
    if (a[i].y < min_y) {
      min_y = a[i].y;
      min_y_pos = i;
    }
  }

  swap(a[0], a[min_y_pos]);

  auto pivot = a[0];

  auto beg = a.begin();

  advance(beg, 1);  

  sort(beg, a.end(), [&](const P& p1, const P& p2) {
    int r = cross_prod(pivot, p1, p2);
    if (r == 0) {
      auto d1 = dist2(pivot, p1);
      auto d2 = dist2(pivot, p2);
      return d1 > d2;
    }
    return r > 0;
    });

  hull.push(a[0]);
  hull.push(a[1]);
  hull.push(a[2]);

  for (int i = 3; i < n; ++i) {
    while (true) {
      P t = top_of(hull);
      P bt = before_top_of(hull);

      if (cross_prod(bt, t, a[i]) <= 0) {        
        hull.pop();
      } else {
        break;
      }
    }
    hull.push(a[i]);
  }

  return hull;
}

double area(stack<P>& hull) {
  vector<P> a;
  while (!hull.empty()) {
    a.push_back(hull.top());
    hull.pop();
  }
  int n = (int)a.size();  
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    P p1 = (i == 0 ? a[n - 1] : a[i - 1]);
    P p2 = a[i];
    ans += (p1.y + p2.y) * (p1.x - p2.x);
  }
  ans = fabs(ans) * 0.5;
  return ans;
}

int solve(int n, vector<P>& a) {
  stack<P> hull = get_hull(n, a);
  double ans = area(hull);
  return (int)round(ans);
}

int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  cout << solve(n, a) << endl;
  return 0;
}