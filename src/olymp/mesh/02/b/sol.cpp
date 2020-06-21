#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  do {
    cout << s << "\n";
  } while (next_permutation(s.begin(), s.end()));
  cout << endl;
  return 0;
}