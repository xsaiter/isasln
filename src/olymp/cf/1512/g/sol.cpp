#include <bits/stdc++.h>

using namespace std;

vector<int> get_prime_factors(int n) {
  vector<int> res;
  while (n % 2 == 0) {      
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      res.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) {
    res.push_back(n);
  }  
  return res;
}

vector<int> get_divs(int n) {
  vector<int> res;
  vector<int> factors = get_prime_factors(n);
  int m = (int)factors.size();  
  for (int i = 0; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      
    }
  }
  return res;
}

int solve(int c) {
  int res = 0;
  int x = 1;
  //for (int i = 0 ; i < 10000
  return res;
}

int main() {
  int t;
  cin << t;
  while (t--) {
    int c;
    cin << c;
    cout << solve(c) << '\n';
  }
  cout << endl;
  return 0;
}


10 -> 1 2 5 10
20 -> 1 2 5