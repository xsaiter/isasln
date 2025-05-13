#include <bits/stdc++.h>

using namespace std;

const int N = 4;

int to_dig(char c) {
  return (int)c - (int)'0';
}

int to_num(vector<int> &a) {
  return 1000 * a[0] + 100 * a[1] + 10 * a[2] + a[3];
}

vector<int> to_vec(int n) {
  string s = to_string(n);
  int m = (int)s.size();
  vector<int> a(N);
  if (m > 0) a[0] = to_dig(s[0]);
  if (m > 1) a[1] = to_dig(s[1]);
  if (m > 2) a[2] = to_dig(s[2]);
  if (m > 3) a[3] = to_dig(s[3]);
  return a;
}

int to_max_num(int n) {
  vector<int> a = to_vec(n);
  sort(a.begin(), a.end(), [](const int &x, const int &y) { return x > y; });
  return to_num(a);
}

int to_min_num(int n) {
  vector<int> a = to_vec(n);
  sort(a.begin(), a.end(), [](const int &x, const int &y) { return x < y; });
  return to_num(a);
}

bool is_kaprekar(int n) {  
  return to_max_num(n) - to_min_num(n) == n;
}                   

int main() {
  int n;
  cin >> n;   
  int i = 0;  
  while (!is_kaprekar(n)) {
    n = to_max_num(n) - to_min_num(n);
    i += 1;
  }
  cout << n << '\n' << i << endl;
  return 0;
}