#include <bits/stdc++.h>

using namespace std;

int main() {
  double t1, t2, s1, s2, s;
  cin >> t1 >> t2 >> s1 >> s2 >> s;
  bool can = true;
  double ans = 0.0;  
  double pos = 0.0;
  while (true) {
    double dist = s - pos;
    if (dist <= s1) {
      ans += dist / (s1 / t1);
      break;
    } else {
      pos += s1;
      ans += t1;
    }
    ans += t2;
    pos -= s2;
    if (pos <= 0.0) {
      can = false;
      break;
    }
  }  
  if (!can) {   
    cout << "NO";
  } else {
    printf("%.2f", ans);
  }
  cout << endl;
  return 0;
}