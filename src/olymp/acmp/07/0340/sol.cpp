#include <bits/stdc++.h>

using namespace std;

string solve(vector<int> &a, vector<int> &b) {
  ostringstream os;
  sort(begin(a), end(a));
  sort(begin(b), end(b));  
  if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
    os << "Boxes are equal";
  } else if (a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2]) {
    os << "The first box is smaller than the second one";
  } else if (a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2]) {
    os << "The first box is larger than the second one";
  } else {
    os << "Boxes are incomparable";
  }
  return os.str();
}

int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  vector<int> b(3);
  cin >> b[0] >> b[1] >> b[2];
  cout << solve(a, b) << endl;
  return 0;
}