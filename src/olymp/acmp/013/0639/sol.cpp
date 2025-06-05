#include <bits/stdc++.h>

using namespace std;

struct P {
  double score;
  string name;
};

struct Team {
  int m;
  vector<P> b;
};

int main() {
  int n;
  cin >> n;
  vector<Team> a(n);
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;    
    vector<P> b(m);
    for (int j = 0; j < m; ++j) {
      cin >> b[j].score >> b[j].name;
    }
    a[i].m = m;
    a[i].b = b;
  }
  int N = 0;
  vector<P> c;
  for (int i = 0; i < n; ++i) {
    N += a[i].m;
    for (int j = 0; j < a[i].m; ++j) {      
      c.push_back(a[i].b[j]);
    }
  }
  sort(begin(c), end(c), [](const P &x, const P &y) {
    return x.score > y.score;
  });    
  printf("%d\n", N);
  for(int i = 0; i < N; ++i) {    
    printf("%.2f %s\n", c[i].score, c[i].name.c_str());
  }  
  return 0;
}