#include <bits/stdc++.h>

using namespace std;

string solve(int a, int b, int c) {
  ostringstream oss;
  bool fi = true;
  if (a > 0) {
    oss << a;
    fi = false;
  } else if (a < 0) {
    oss << a;
    fi = false;
  }
  if (b > 0) {
    if (b == 1) {
      if (!fi) {
        oss << "+x";
      } else {
        oss << "x";
      }
    } else {
      if (!fi) {
        oss << "+" << b << "x";
      } else {
        oss << b << "x";
      }
    }
    fi = false;
  } else if (b < 0) {
    if (b == -1) {
      if (!fi) {
        oss << "-x";
      } else {
        oss << "-x";
      }
    } else {
      if (!fi) {
        oss << b << "x";
      } else {
        oss << b << "x";
      }
    }
    fi = false;
  }
  if (c > 0) {
    if (c == 1) {
      if (!fi) {
        oss << "+y";
      } else {
        oss << "y";
      }
    } else {
      if (!fi) {
        oss << "+" << c << "y";
      } else {
        oss << c << "y";
      }
    }
    fi = false;
  } else if (c < 0) {
    if (c == -1) {
      if (!fi) {
        oss << "-y";
      } else {
        oss << "-y";
      }
    } else {
      if (!fi) {
        oss << c << "y";
      } else {
        oss << c << "y";
      }
    }
    fi = false;
  }
  if (fi) {
    oss << a;
  }
  return oss.str();
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << solve(a, b, c) << endl;
  return 0;
}