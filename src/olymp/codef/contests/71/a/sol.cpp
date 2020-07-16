#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    if (n <= 10) printf("%s\n", s.c_str());
    else printf("%c%d%c\n", s[0], n - 2, s[n - 1]);
  }
  cout << endl;
  return 0;
}