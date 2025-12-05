#include <bits/stdc++.h>

using namespace std;

// a[i] = a[i] - 1
// a[i + 1] = a[i + 1] + 1
// extrime min of (max(a) - min(a))

// 4 1 2 3 => 3 2 2 3 => 2 3 2 3 =>> 3 - 2 = 1
// 2 3 2 3 => 1 4 2 3

// 5 14 4 10 2 =>  14 4 -> 5 9 9 10 2 -> 5 9 9 6 6
// 5 14 4 10 2 => 5 14 4 6 6 => 5 8 10 6 6 => 5 8 8 8 6
// 5 14 4 10 2 => 5 14 4 6 6 => 5 9 10 6 6

// if a[i] > alfa then a[i] = alfa else a[i+1] += a[i] - alfa
// if a[i] < beta then a[i] = beta else a[i-1] = a[i-1] - (beta-a[i])


void shift(vector<int> &a, int p, int q, bool eq) {
  int s = a[p] - a[q];
  int rem = s  % 2;
  if (rem == 0) {
    a[p] -= s / 2;
    a[q] += s / 2;
    if (!eq) {      
      a[p]--;
      s[q]++;
    }
  } else {
    a[p] -= (s + 1) / 2;
    a[q] += (s + 1) / 2;
  }
}

int solve(int n, vector<int> &a) {  
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] > a[i]) {      
      shift(a, i - 1, i);
    }
  }    
  int mi = INT_MAX, ma = -INT_MAX;
  for (int i = 0; i < n; ++i) {
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
  }
  return ma - mi;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}