#include <algorithm>
#include "all_queens.hh"

namespace isa {
namespace misc {

using cells_t = std::vector<all_queens_s::cell_s>;
using cells_ptr_t = std::shared_ptr<cells_t>;

all_queens_s::position_s::position_s() : cells_(new cells_t) {}
all_queens_s::all_queens_s(std::size_t n) : n_(n) {}

all_queens_s::position_s all_queens_s::find_position() {
  position_s pos;
  pos.set_success(try_find(pos));
  return pos;
}

bool all_queens_s::try_find(position_s &pos) {
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

cells_ptr_t all_queens_s::next_moves(position_s &pos) const {
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
    moves->push_back(all_queens_s::cell_s(nx + 1, y + 1));
  }

  return moves;
}

bool all_queens_s::check_position(position_s &pos) const {
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
        cell_s cc(x, y);
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
