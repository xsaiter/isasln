#include <algorithm>
#include "all_queens.hh"

namespace isa {
namespace misc {

typedef std::vector<all_queens::cell_t> cells_t;
typedef std::shared_ptr<cells_t> cells_ptr_t;

all_queens::position_t::position_t() : cells_(new cells_t) {}
all_queens::all_queens(std::size_t n) : n_(n) {}

all_queens::position_t all_queens::find_position() {
  position_t pos;
  pos.set_success(try_find(pos));
  return pos;
}

bool all_queens::try_find(position_t &pos) {
  auto moves = next_moves(pos);

  for (auto m = moves->begin(); m != moves->end(); ++m) {
    pos.cells()->push_back(*m);
    if (try_find(pos)) {
      break;
    }

    auto rem = std::remove(pos.cells()->begin(), pos.cells()->end(), *m);
    pos.cells()->erase(rem);
  }

  return check_position(pos) && pos.size() == n_;
}

cells_ptr_t all_queens::next_moves(position_t &pos) const {
  cells_ptr_t moves(new cells_t);
  int nx = 0;

  auto last = pos.cells()->rbegin();

  if (last != pos.cells()->rend()) {
    if ((*last).x_ == 8) {
      return moves;
    }
    nx = (*last).x_;
  }

  for (int y = 0; y < 8; ++y) {
    moves->push_back(all_queens::cell_t(nx + 1, y + 1));
  }

  return moves;
}

bool all_queens::check_position(position_t &pos) const {
  for (auto c = pos.cells()->begin(); c != pos.cells()->end(); ++c) {
    for (int s = 0; s < 6; ++s) {
      std::size_t x = (*c).x_;
      std::size_t y = (*c).y_;
      while (0 < x && x <= n_ && 0 < y && y <= n_) {
        switch (s) {
        case 0:
          ++x;
          break;
        case 1:
          ++x;
          --y;
          break;
        case 2:
          --x;
          --y;
          break;
        case 3:
          --x;
          break;
        case 4:
          --x;
          ++y;
          break;
        case 5:
          ++x;
          ++y;
          break;
        }
        cell_t cc(x, y);
        if (std::find(pos.cells()->begin(), pos.cells()->end(), cc) !=
            pos.cells()->end()) {
          return false;
        }
      }
    }
  }
  return true;
}
}
}
