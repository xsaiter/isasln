#include <bits/stdc++.h>

using namespace std;

double cost(double p, double t) {
  return max(3 * p / 10, p - (p * t) / 250);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  double x = cost(a, c);
  double y = cost(b, d);
  if (x == y) {
    cout << "Tie";
  } else if (x > y) {
    cout << "Misha";
  } else {
    cout << "Vasya";
  }
  cout << endl;
  return 0;
}