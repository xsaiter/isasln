#include <bits/stdc++.h>

using namespace std;

struct cell {
  int x, y;
};

constexpr int n = 3;

int b[9][9];

int main() {
  int res = 0;
  cell c[n];
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    c[i].x = s[0] - 'A' + 1;
    c[i].y = s[1] - '0';
    b[c[i].x][c[i].y] = -1;
  }
  int nx, ny;
  auto a = c[0]; // q
  for (int i = 1; i < 9; ++i) {
    if (b[a.x][i] != -1) {
      b[a.x][i] = 1;
    }
    if (b[i][a.y] != -1) {
      b[i][a.y] = 1;
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 1; j < 8; ++j) {
      if (i == 0) {
        nx = a.x + j;
        ny = a.y + j;
      } else if (i == 1) {
        nx = a.x - j;
        ny = a.y + j;
      } else if (i == 2) {
        nx = a.x - j;
        ny = a.y - j;
      } else if (i == 3) {
        nx = a.x + j;
        ny = a.y - j;
      }
      if (nx < 9 && nx > 0 && ny < 9 && ny > 0 && b[nx][ny] != -1) {
        b[nx][ny] = 1;
      }
    }
  }

  a = c[1]; // r
  for (int i = 1; i < 9; ++i) {
    if (b[a.x][i] != -1) {
      b[a.x][i] = 1;
    }
    if (b[i][a.y] != -1) {
      b[i][a.y] = 1;
    }
  }

  a = c[2]; // k
  for (int i = 0; i < 8; ++i) {
    if (i == 0) {
      nx = a.x + 2;
      ny = a.y + 1;
    } else if (i == 1) {
      nx = a.x + 1;
      ny = a.y + 2;
    } else if (i == 2) {
      nx = a.x - 1;
      ny = a.y + 2;
    } else if (i == 3) {
      nx = a.x - 2;
      ny = a.y + 1;
    } else if (i == 4) {
      nx = a.x - 2;
      ny = a.y - 1;
    } else if (i == 5) {
      nx = a.x - 1;
      ny = a.y - 2;
    } else if (i == 6) {
      nx = a.x + 1;
      ny = a.y - 2;
    } else if (i == 7) {
      nx = a.x + 2;
      ny = a.y - 1;
    }
    if (nx < 9 && nx > 0 && ny < 9 && ny > 0 && b[nx][ny] != -1) {
      b[nx][ny] = 1;
    }
  }

  for (int i = 1; i < 9; ++i) {
    for (int j = 1; j < 9; ++j) {
      if (b[i][j] == 1) {
        ++res;
      }
    }
  }
  cout << res << endl;
  return 0;
}