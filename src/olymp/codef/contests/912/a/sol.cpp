#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long A, B, x, y, z;
  cin >> A >> B >> x >> y >> z;  
  long long res = max((long long)0, (long long)2 * x + y - A) + max((long long)0, (long long)3 * z + y - B);
  cout << res << endl;
  return 0;
}