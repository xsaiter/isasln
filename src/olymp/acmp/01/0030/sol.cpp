#include <bits/stdc++.h>

#define N 10
#define K 3

using namespace std;

int res[N];
int a[K];
int b[K];

void save() {
  for (int i = 0; i < K; ++i) {
    int x = a[i];
    ++res[x % 10];
    ++res[(x - x % 10) / 10];
  }  
}

bool same() {
  return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
};

int asint(const string& s, int pos) {
  return atoi(s.substr(pos, 2).c_str());
}

int main() {
  string sa, sb;
  cin >> sa >> sb;    
  a[0] = asint(sa, 0);
  a[1] = asint(sa, 3);
  a[2] = asint(sa, 6);

  b[0] = asint(sb, 0);
  b[1] = asint(sb, 3);
  b[2] = asint(sb, 6);
  save();
  while (!same()) {
    ++a[2];
    if (a[2] == 60) {
      a[2] = 0;      
      ++a[1];
      if (a[1] == 60) {
        a[1] = 0;
        ++a[0];
        if (a[0] == 24) {
          a[0] = 0;
        } 
      }     
    }
    save();    
  }    
  for (int i = 0; i < N; ++i) {
    printf("%d\n", res[i]);
  }
  return 0;
}