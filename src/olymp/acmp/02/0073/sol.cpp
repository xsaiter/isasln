#include <bits/stdc++.h>

using namespace std;

const string ABC = "abcdefghijklmnopqrstuvwxyz";

int to_dig(char c) {
  return (int)c - (int)'0';
}

int pos_abc(char c) {
  int n = (int)ABC.size();
  for (int i = 0; i < n; ++i) {
    if (ABC[i] == c) {
      return i;
    }
  }
  throw("no char");
}

char pos_of_abc(int i) {
  return ABC[i];
}

int to_code_num(char c) {
  if (c == ' ') {
    return 27;
  }
  return pos_abc(c) + 1;
}

char to_decode_num(int x) {
  if (x == 27) {
    return ' ';
  }
  return pos_of_abc(x - 1);
}

char to_code_27(int v) {
  if (v == 0) return '0';
  if (v == 1) return '1';
  if (v == 2) return '2';
  if (v == 3) return '3';
  if (v == 4) return '4';
  if (v == 5) return '5';
  if (v == 6) return '6';
  if (v == 7) return '7';
  if (v == 8) return '8';
  if (v == 9) return '9';
  if (v == 10) return 'A';
  if (v == 11) return 'B';
  if (v == 12) return 'C';
  if (v == 13) return 'D';
  if (v == 14) return 'E';
  if (v == 15) return 'F';
  if (v == 16) return 'G';
  if (v == 17) return 'H';
  if (v == 18) return 'I';
  if (v == 19) return 'J';
  if (v == 20) return 'K';
  if (v == 21) return 'L';
  if (v == 22) return 'M';
  if (v == 23) return 'N';
  if (v == 24) return 'O';
  if (v == 25) return 'P';
  if (v == 26) return 'Q';
  throw("unable to code 27");
}

int to_decode_27(char c) {
  if (c == '0') return 0;
  if (c == '1') return 1;
  if (c == '2') return 2;
  if (c == '3') return 3;
  if (c == '4') return 4;
  if (c == '5') return 5;
  if (c == '6') return 6;
  if (c == '7') return 7;
  if (c == '8') return 8;
  if (c == '9') return 9;
  if (c == 'A') return 10;
  if (c == 'B') return 11;
  if (c == 'C') return 12;
  if (c == 'D') return 13;
  if (c == 'E') return 14;
  if (c == 'F') return 15;
  if (c == 'G') return 16;
  if (c == 'H') return 17;
  if (c == 'I') return 18;
  if (c == 'J') return 19;
  if (c == 'K') return 20;
  if (c == 'L') return 21;
  if (c == 'M') return 22;
  if (c == 'N') return 23;
  if (c == 'O') return 24;
  if (c == 'P') return 25;
  if (c == 'Q') return 26;
  throw("unable to decode 27");
}

char code(char c, int i) {
  int num = to_code_num(c);
  int v = (i + num) % 27;
  return to_code_27(v);
}

char decode(char c, int i) {
  int v = to_decode_27(c);
  bool found = false;
  int num = -1;
  for (int k = 0; k < 512; ++k) {
    if ((i + k) % 27 == v) {
      char r = to_decode_num(k);
      if (c == code(r, i)) {
        found = true;
        num = k;
        break;
      }
    }
  }
  if (!found) {
    throw("not found");
  }
  return to_decode_num(num);
}

string code(const string& s) {
  int n = (int)s.size();
  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    oss << code(s[i], i + 1);
  }
  return oss.str();
}

string decode(const string& s) {
  int n = (int)s.size();
  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    oss << decode(s[i], i + 1);
  }
  return oss.str();
}

string solve(const string& s) {
  return decode(s);
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}