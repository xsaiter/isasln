#include <bits/stdc++.h>

using namespace std;

struct E {
  int a, b;
};

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a = solve(n);
    if (a.empty()) {
      cout << "-1" << '\n';
    } else {
      for (const auto& x : a) {
        cout << x.a << ' ' << x.b << '\n';
      }
    }    
  }
  cout << endl;
  return 0;
}
