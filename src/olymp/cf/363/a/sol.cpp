#include <bits/stdc++.h>

using namespace std;

vector<int> get_digits(int n) {
  vector<int> res;
  if (n == 0) res.push_back(0);
  while (n > 0) {
    int d = n % 10;
    res.push_back(d);         
    n = (n - d) / 10;    
  }  
  return res;
}

string spoke(int d) {
  ostringstream oss;
  if (d >= 5) {
    oss << "-O|";
    d -= 5;
  } else {
    oss << "O-|";    
  }
  if (d == 0) { oss << "-OOOO"; }
  else if (d == 1) { oss << "O-OOO"; }
  else if (d == 2) { oss << "OO-OO"; }
  else if (d == 3) { oss << "OOO-O"; }
  else if (d == 4) { oss << "OOOO-"; }
  return oss.str();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> digits = get_digits(n);
  for (auto d : digits) {
    cout << spoke(d) << "\n";
  }
  cout << endl;
  return 0;
}