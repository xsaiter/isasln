#include <bits/stdc++.h>

using namespace std;

bool sort_cmp(char a, char b) {  
  if ((islower(a) && islower(b)) || 
      (isupper(a) && isupper(b))) {
    return a < b;
  }
  if (islower(a)) {
    return true;
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<string> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  set<char> ss;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j]) {
        char ab = a[i][j] == '.' ? b[i][j] : a[i][j];
        ss.insert(ab);
      }    
    }
  }    
  if (ss.empty()) {
    cout << 0 << endl;
  } else {
    cout << ss.size() << '\n';
    vector<char> cc(begin(ss), end(ss));
    sort(begin(cc), end(cc), sort_cmp);
    for (char c : cc) {
      cout << c;
    }
  }
  cout << endl;
  return 0;
}