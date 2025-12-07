#include <bits/stdc++.h>

using namespace std;

const int N = 4;

int is_triangle(int a, int b, int c) {
  return a + b > c &&  a + c > b && b + c > a;
}

int is_segment(int a, int b, int c) {
  return a + b == c || a + c == b || b + c == a;
}

bool is_triangle(const vector<int> &a) {
  return is_triangle(a[0], a[1], a[2]) ||  
    is_triangle(a[0], a[1], a[3]) ||
    is_triangle(a[0], a[2], a[3]) ||
    is_triangle(a[1], a[2], a[3]);
}

bool is_segment(const vector<int> &a) {
  return is_segment(a[0], a[1], a[2]) ||  
    is_segment(a[0], a[1], a[3]) ||
    is_segment(a[0], a[2], a[3]) ||
    is_segment(a[1], a[2], a[3]);
}

int main() {
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  if (is_triangle(a)) {
    cout << "TRIANGLE";
  } else if (is_segment(a)) {
    cout << "SEGMENT";
  } else {
    cout << "IMPOSSIBLE";
  }
  cout << endl;
  return 0;
}