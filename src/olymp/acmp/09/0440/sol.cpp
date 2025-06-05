#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

const int N = 5;
const int R = 10;

bool is_inside(const P &c, const P &p) {
  return (p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y) <= R * R;
}

int check(const vector<P> &cc, const P &p) {  
  for (int i = 0; i < N; ++i) {    
    if (is_inside(cc[i], p)) {
      return i;
    }
  }
  return -1;
}

int solve(const vector<P> &a) {  
  vector<P> cc(N);
  cc[0] = { .x = 0, .y = 0 };
  cc[1] = { .x = 25, .y = 0 };
  cc[2] = { .x = 50, .y = 0 };
  cc[3] = { .x = 75, .y = 0 };
  cc[4] = { .x = 100, .y = 0 };
  vector<bool> b(N, false);
  for (int i = 0; i < N; ++i) {
     int j = check(cc, a[i]);
     if (j != -1) {
       b[j] = true;
     }
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if (b[i]) {
      ans += 1;
    }
  }
  return ans;
}

int main() {
  vector<P> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  cout << solve(a) << endl;
  return 0;
}