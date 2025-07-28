#include <bits/stdc++.h>

using namespace std;

int count_mins(int k) {  
  return (k - 1) * 5;  
}

int main() {
  int k;
  cin >> k;  
  int n = count_mins(k);
  int N = 12 * 60;  
  if (n > N) {
    cout << "NO";
  } else {
    int mm = n % 60;
    int hh = (n - mm) / 60;    
    cout << hh << ' ' << mm;
  }
  cout << endl;
  return 0;
}