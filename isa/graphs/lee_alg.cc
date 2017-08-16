#include <queue>

#include "lee_alg.hh"

#define DIRECTIONS 4

namespace isa {
namespace graphs {
bool lee_alg(const lee_opts_t &opts, std::vector<lee_cell_t> &result) {
  int dx[DIRECTIONS] = {1, 0, -1, 0};
  int dy[DIRECTIONS] = {0, -1, 0, 1};

  int rows = opts.rows;
  int cols = opts.cols;

  lee_cell_t cc[rows][cols];

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cc[i][j].visited = false;
      cc[i][j].discovered = false;
      cc[i][j].n = 0;
    }
  }

  int bx = opts.beg_x;
  int by = opts.beg_y;

  int ex = opts.end_x;
  int ey = opts.end_y;

  cc[bx][by].n = 1;
  cc[bx][by].x = bx;
  cc[bx][by].y = by;
  cc[bx][by].visited = true;

  std::queue<lee_cell_t> q;

  q.push(cc[bx][by]);

  bool stop = false;

  int x, y, num, nx, ny;

  while (!stop && !q.empty()) {
    lee_cell_t c = q.front();
    q.pop();

    x = c.x;
    y = c.y;
    num = c.n + 1;

    for (int i = 0; i < DIRECTIONS; ++i) {
      nx = x + dx[i];
      ny = y + dy[i];

      if (nx >= 0 && nx < cols && ny >= 0 && ny < rows && !cc[nx][ny].visited &&
          opts.a[nx][ny] == 0) {
        cc[nx][ny].x = nx;
        cc[nx][ny].y = ny;
        cc[nx][ny].n = num;
        cc[nx][ny].visited = true;

        if (nx == ex && ny == ey) {
          stop = true;
          break;
        }

        q.push(cc[nx][ny]);
      }
    }
  }

  if (!stop) {
    return false;
  }

  x = ex;
  y = ey;
  num = cc[x][y].n;

  while (x != bx || y != by) {
    for (int i = 0; i < DIRECTIONS; ++i) {
      nx = x + dx[i];
      ny = y + dy[i];

      if (cc[nx][ny].n == num - 1) {
        num = cc[nx][ny].n;

        result.push_back(cc[nx][ny]);

        x = nx;
        y = ny;

        break;
      }
    }
  }

  return true;
}
}
}
