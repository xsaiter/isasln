#include <bits/stdc++.h>

using namespace std;

string to_str(const vector<int> &a) {
  ostringstream oss;
  for (const auto &e : a) {
    oss << e;
  }
  return oss.c_str();
}

vector<int> ma(int m) {
  vector<int> a;
  return a;
}

vector<int> mi(int m) {
  vector<int> a;
  return a;
}

int main() {
  int m;
  cin >> m;  
  vector<int> a = ma();
  vector<int> b = mi();
  cout << to_str(a) << ' ' << to_str(b) << endl;
  return 0;
}