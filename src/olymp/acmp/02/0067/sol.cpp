#include <bits/stdc++.h>

using namespace std;

inline int to_int(const string &s) {
  return atoi(s.c_str());
}

inline bitset<32> apply_mask(const bitset<32> &ip, const bitset<32> &mask) {
  return ip & mask;
}

bitset<32> bitset_ip(const string &ip) {
  ostringstream oss;
  int len = (int)ip.size();  
  string buf;    
  for (int i = 0; i < len; ++i) {    
    if (ip[i] == '.') {      
      bitset<8> b(to_int(buf));      
      oss << b.to_string();
      buf = "";
    } else {
      buf += ip[i];
    }    
  }  
  bitset<8> bb(to_int(buf));
  oss << bb.to_string();
  return bitset<32>(oss.str());
}

int solve(int n, const vector<string> &a, const string &ip1, const string &ip2) {  
  vector<bitset<32>> masks(n);
  for (int i = 0; i < n; ++i) {
    masks[i] = bitset_ip(a[i]);
  }
  int ans = 0;
  bitset<32> bip1 = bitset_ip(ip1);
  bitset<32> bip2 = bitset_ip(ip2);
  for (int i = 0; i < n; ++i) {
    if (apply_mask(bip1, masks[i]) == apply_mask(bip2, masks[i])) {
      ans += 1;      
    }
  }
  return ans;
}

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m;
  cin >> m;  
  for (int i = 0; i < m; ++i) {
    string c1, c2;
    cin >> c1 >> c2;
    cout << solve(n, a, c1, c2) << '\n';
  }  
  cout << endl;
  return 0;
}