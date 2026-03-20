#include <bits/stdc++.h>

using namespace std;

struct C {
  int x, y;  
};

C new_c(int x, int y) {
  return C {.x = x,.y = y};
}

bool solve(int n, int x, int y, string &s) {
  C a = new_c(0, 0);
  C b = new_c(abs(x), abs(y));  
  int dx = b.x - a.x;
  int dy = b.y - a.y;  
  int k4 = 0, k8 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '4') {
      ++k4;         
    } else {
      ++k8;
    }
  }
  dx -= k8;
  dy -= k8;
  dx = max(dx, 0);
  dy = max(dy, 0);
  return k4 >= (dx + dy);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    cout << (solve(n, x, y, s) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}