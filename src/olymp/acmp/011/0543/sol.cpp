#include <bits/stdc++.h>

using namespace std;

int solve(int N, int w, int d, int P) {  
  int n = N - 1;
  int k = n * (n + 1) / 2;
  int M = k * w;
  if (M == P) {
    return N;
  }
  for (int i = 1; i <= N - 1; ++i) {
    M = (k - i) * w + i * (w - d);
    if (M == P) {
      return i;
    }
  } 
  throw "Err";
}

int main() {
  int N, w, d, P;
  cin >> N >> w >> d >> P;
  cout << solve(N, w, d, P) << endl;

  return 0;
}