#include <bits/stdc++.h>

using namespace std;

struct C {
  int k, l, m;  

  int lost() const {
    return k * l / 100;
  }
  int present() const {
    return k - lost();
  }
  int present_cost() const {
    return present() * m;
  }
  int lost_cost() const {
   return lost() * m;
  }
};

int extra_cost(const C &a, const C &b) {
  int na = a.present();
  int nb = b.present();
  if (na == nb) {
    return 0;
  }
  if (na > nb) {
    return (na - nb) * a.m;
  }
  return (nb - na) * b.m;
}

int solve(const C &a, const C &b) {
  return a.lost_cost() + b.lost_cost() + extra_cost(a, b);  
}

int main() {
  C a;
  cin >> a.k >> a.l >> a.m;
  C b;
  cin >> b.k >> b.l >> b.m;
  cout << solve(a, b) << endl;
  return 0;
}