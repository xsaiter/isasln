#include <bits/stdc++.h>

using namespace std;

struct P {  
  int t;
  bool is_timeout;    
};

struct H {  
  string ip;  
};

H read_head() {
  string s;
  getline(cin, s);
  auto n = s.size();
  auto j = s.find(" ");
  j += 1;  
  H res;    
  res.ip = s.substr(j, n - j);  
  return res;
}

void parse_p(const string &s, P &p) {
  if (s == "Time out") {
    p.is_timeout = true;
    p.t = -1;
    return;
  }
  auto n = s.size();
  auto pos = s.find("Time=");
  if (pos != string::npos) {
    pos += 5;
    auto ss = s.substr(pos, n - pos);
    p.t = atoi(ss.c_str());
    p.is_timeout = false;
  }
}

vector<P> read_packets(int n) {
  vector<P> a(n);  
  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);    
    parse_p(s, a[i]);
  }
  return a;
}

int main() {
  H head = read_head();
  int n = 4;
  vector<P> a = read_packets(n);  
  bool all_err = all_of(begin(a), end(a), 
    [](const P &p) { return p.is_timeout; });
  int sent = n, rec = 0, lost = 0, loss = 0;  
  for (int i = 0; i < n; ++i) {
    if (a[i].is_timeout) {
      lost += 1;
    } else {
      rec += 1;
    }
  }
  if (lost == 0) {
    loss = 0;
  } else if (lost == 1) {
    loss = 25;
  } else if (lost == 2) {
    loss = 50;
  } else if (lost == 3) {
    loss = 75;
  } else if (lost == 4) {
    loss = 100;
  }
  cout << "Ping statistics for " << head.ip << ":" << endl;
  cout << "Packets: Sent = " << sent << ' ';
  cout << "Received = " << rec << ' '; 
  cout << "Lost = " << lost << ' ';
  cout << "(" << loss << "% loss)";
  if (!all_err) {
    cout << endl;
    int tt = 0;
    int mi = INT_MAX, ma = -INT_MAX, av = 0, n_ok = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i].is_timeout) {
        continue;
      }
      if (a[i].t < mi) {
        mi = a[i].t;
      }
      if (a[i].t > ma) {
        ma = a[i].t;
      }
      tt += a[i].t;
      n_ok += 1;
    }
    av = static_cast<int>(round((double)tt / (double)n_ok));
    cout << "Approximate round trip times:" << '\n';
    printf("Minimum = %d Maximum = %d Average = %d", mi, ma, av);
  }
  cout << endl;
  return 0;
}