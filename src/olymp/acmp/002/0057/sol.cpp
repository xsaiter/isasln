#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
constexpr double eps = 1e-2;
constexpr double INF = DBL_MAX;
int x[N], y[N];
double g[N][N];
int n, c, p, sx, sy;

double adj[N][N];

void test() {
  n = 6;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      adj[i][j] = INF;
    }
  }

  for (int i = 0; i < n; ++i) {
    adj[0][1] = 2;
    adj[0][3] = 1;
    adj[0][4] = 4;

    adj[1][0] = 2;
    adj[1][3] = 3;
    adj[1][5] = 7;
    adj[1][2] = 3;

    adj[2][3] = 5;
    adj[2][1] = 3;
    adj[2][5] = 8;

    adj[3][4] = 9;
    adj[3][0] = 1;
    adj[3][2] = 5;
    adj[3][1] = 3;

    adj[4][3] = 9;
    adj[4][0] = 4;

    adj[5][2] = 8;
    adj[5][1] = 7;
  }

  // auto res_prim = prim();
}

void print_adj() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << adj[i][j] << " ";
    }
    cout << "\n";
  }
  cout << endl;
}

int get_r(int v, const vector<bool> &selected) {
  int mr = -1;
  double mw = INF;
  for (int i = 0; i < n; ++i) {
    if (selected[i] == false && adj[v][i] < mw) {
      mr = i;
      mw = adj[v][i];
    }
  }
  return mr;
}

double get_len(int start) {
  double res = 0.0;
  vector<bool> selected(n, false);

  selected[start] = true;

  for (int j = 0; j < n; ++j) {
    double mrw = INF;
    int mr = -1;
    for (int s = 0; s < n; ++s) {
      if (selected[s] == true) {
        int r = get_r(s, selected);
        if (r != -1 && adj[s][r] < mrw) {
          mr = r;
          mrw = adj[s][r];
        }
      }
    }
    if (mr != -1) {
      selected[mr] = true;
      res += mrw;
    }
  }

  return res;
}

int main() {
  cin >> n >> c >> p;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  cin >> sx >> sy;
  x[n] = sx;
  y[n] = sy;
  ++n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      adj[i][j] = INF;
      if (i != j && adj[j][i] < INF) {
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        adj[i][j] = sqrt(dx * dx + dy * dy);
        adj[j][i] = adj[i][j];
      }
    }
  }

  auto len = get_len(n - 1);
  auto res = p <= len * c;
  if (res) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}