#include <bits/stdc++.h>

#define N 100001

using namespace std;

int n, k;
char s[N];

bool calc() {  
  if (n <= k) {
    return false;
  }
  char buf[5];
  int m = n - k + 1;
  vector<int> v(m);
  for (int i = 0; i < m; ++i) {    
    copy(s + i, s + i + k, buf);
    v[i] = atoi(buf);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; ++i) {
    if (v[i] == v[i + 1]) {
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  scanf("%d %d %s", &n, &k, s);
  bool r = calc();
  if (r) {
    printf("YES");
  } else {
    printf("NO");
  } 
  return 0;
}