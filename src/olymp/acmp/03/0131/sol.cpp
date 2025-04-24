#include <bits/stdc++.h>

using namespace std;

struct Person {
  int age, s;  
};

int solve(int n, vector<Person> &a) {
  int j = -1;
  int max_age = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i].s == 1 && a[i].age > max_age) {
      max_age = a[i].age;
      j = i;
    }
  }
  if (j == -1) {
    return j;
  }
  return j + 1;
}

int main() {
  int n;
  cin >> n;
  vector<Person> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].age >> a[i].s;
  }
  cout << solve(n, a) << endl;
  return 0;
}