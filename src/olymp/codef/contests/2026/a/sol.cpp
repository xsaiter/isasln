#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

struct Sec {
  P a, b;

  int len() const {        
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));    
  }
};

void solve(int X, int Y, int K, Sec &p, Sec &q) {
  int size = min(X, Y);
  p.a.x = 0;
  p.a.y = 0;
  p.b.y = size;  
  double min_len = (double)K;
  int c = 0;
  while (c <= X) {
    p.b.x = c;
    double len = p.len();    
    if (len >= min_len) {
      q.a.x = 0;
      q.a.y = c;
      q.b.x = size;
      q.b.y = 0;      
      break;
    }
    ++c;    
  }  
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int X, Y, K;
    cin >> X >> Y >> K;
    Sec p, q;
    solve(X, Y, K, p, q);
    cout << p.a.x << " " << p.a.y << " " << p.b.x << " " <<  p.b.y << '\n';
    cout << q.a.x << " " << q.a.y << " " << q.b.x << " " <<  q.b.y << '\n';
  }
  cout << endl;
  return 0;
}