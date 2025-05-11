#include <bits/stdc++.h>

using namespace std;

struct R {
  string name;
  string a, b;
  double speed;
};

double speed_for(string a, string b) {
  int ha = atoi(a.substr(0, 2).c_str());
  int ma = atoi(a.substr(3, 2).c_str());

  int hb = atoi(a.substr(0, 2).c_str());
  int mb = atoi(a.substr(3, 2).c_str());  
}

int main() {
  int n;
  cin >> n;
  R best;  
  best.speed = -1;
  for (int i = 0; i < n; ++i) {
    R r;
    cin >> r.name >> r.a >> r.b;
    r.speed = speed_for(r.a, r.b);
    if (r.speed > best.speed) {
      best = r;
    }
  }
  cout << "The fastest train is """ <<  best.name << """" << '\n';
  cout << "Its speed is" << best.speed
  return 0;
}
