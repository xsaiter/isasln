#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
  i64 a, b;
  cin >> a >> b;
  if (a < b) {
    cout << "<";
  } else if (a > b) {
    cout << ">";
  } else {
    cout << "=";
  }
  cout << endl;
  return 0;
}