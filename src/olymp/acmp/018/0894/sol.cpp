#include <bits/stdc++.h>

using namespace std;

const double PI = 3.1415926;

double solve(double s, double r) {  
  return sqrt((PI * r * r - s) / PI);
}

int main() {
  double s, r;
  cin >> s >> r;
  double r2 = solve(s, r);
  printf("%.3f", r2);
  return 0;
}