#include <bits/stdc++.h>

using namespace std;

int line(char a, char b, char c) {
  if (a == b && b == c) {
    if (a == 'X') {
      return 1;
    } else  if (a == 'O'){
      return 2;
    }
  }
  return 0;
}

bool is_person(int r) {
  return r == 1 || r == 2;
}

int solve(int n, const vector<string> &a) {  
  int r = 0;
  for (int i = 0; i < n; ++i) {
    r = line(a[i][0], a[i][1], a[i][2]);
    if (is_person(r)) {
      return r;
    }
    r = line(a[0][i], a[1][i], a[2][i]);
    if (is_person(r)) {
      return r;
    }
  }
  r = line(a[0][0], a[1][1], a[2][2]);
  if (is_person(r)) {
    return r;
  }
  r = line(a[0][2], a[1][1], a[2][0]);
  if (is_person(r)) {
    return r;
  }
  return 0;
}

int main() {
  int n = 3;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int r = solve(n, a);
  if (r == 1) {
    cout << "Win";
  } else if (r == 2) {
    cout << "Lose";
  } else if (r == 0) {
    cout << "Draw";
  }
  cout << endl;
  return 0;
}