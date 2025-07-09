#include <bits/stdc++.h>

using namespace std;

const int D = 650;
const int INF = 1e9;
const int MM = 60;

struct R {
  string name;
  int speed;
};

int get_mins(int h, int m) {
  return h * MM + m;
}

double to_hh(int mm) {
  return (double)mm / (double)MM;
}

int get_speed(const string& a, const string& b) {
  int ha = atoi(a.substr(0, 2).c_str());
  int ma = atoi(a.substr(3, 2).c_str());

  int hb = atoi(b.substr(0, 2).c_str());
  int mb = atoi(b.substr(3, 2).c_str());

  int aa = get_mins(ha, ma);
  int bb = get_mins(hb, mb);

  int mm = bb - aa;
  if (mm == 0) {
    return -INF;
  }
  if (mm < 0) {
    /*if (aa == 0) {
      mm = bb;
    } else {*/
    mm = get_mins(24, 0) - aa + bb;
    //}
  }
  double val = (double)D / (double)to_hh(mm);
  return (int)round(val);
}

void parse(const string& s, R& r) {
  int len = (int)s.size();
  ostringstream os, oa, ob;
  int state = 0;
  for (int j = 0; j < len; ++j) {
    if (state == 0) {
      os << s[j];
      if (s[j] == '"') {
        state = 1;
      }
    } else if (state == 1) {
      os << s[j];
      if (s[j] == '"') {
        state = 2;
      }
    } else if (state == 2) {
      if (s[j] == ' ') {
        state = 3;
      }
    } else if (state == 3) {
      if (s[j] == ' ') {
        state = 4;
      } else {
        oa << s[j];
      }
    } else if (state == 4) {
      ob << s[j];
    }
  }
  r.name = os.str();
  string a = oa.str();
  string b = ob.str();
  r.speed = get_speed(a, b);
}

int main() {
  string s;
  getline(cin, s);
  int n;
  n = atoi(s.c_str());
  vector<R> a(n);
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    parse(s, a[i]);
  }
  sort(begin(a), end(a), [](const R& x, const R& y) {
    return x.speed > y.speed;
    });
  cout << "The fastest train is """ << a[0].name << """." << '\n';
  cout << "Its speed is " << a[0].speed << " km/h, approximately." << endl;
  return 0;
}
