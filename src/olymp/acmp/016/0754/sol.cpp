#include <bits/stdc++.h>

using namespace std;

bool valid(vector<int> &m) {
  for (int i = 0; i < 3; ++i) {
    if (m[i] < 94 || m[i] > 727) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> m(3);
  cin >> m[0] >> m[1] >> m[2];
  if (!valid(m)) {
    cout << "Error";
  } else {
    sort(begin(m), end(m));
    cout << m[2];
  }
  cout << endl;
  return 0;
}