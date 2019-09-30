#include "all_queens.hpp"
#include <algorithm>

namespace isa::misc {
using Cells = std::vector<All_queens::Cell>;
using Cells_ptr = std::shared_ptr<Cells>;

All_queens::Position::Position() : cells_(new Cells), success_(false) {}
All_queens::All_queens(std::size_t n) : n_(n) {}

All_queens::Position All_queens::find_position() {
  Position pos;
  pos.set_success(try_find(pos));
  return pos;
}

bool All_queens::try_find(Position &pos) {
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

Cells_ptr All_queens::next_moves(Position &pos) const {
  Cells_ptr moves(new Cells);
  int nx = 0;

  auto last = pos.cells()->rbegin();

  if (last != pos.cells()->rend()) {
    if ((*last).x_ == 8) {
      return moves;
    }
    nx = (*last).x_;
  }

  for (int y = 0; y < 8; ++y) {
    moves->push_back(All_queens::Cell(nx + 1, y + 1));
  }

  return moves;
}

bool All_queens::check_position(Position &pos) const {
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
        Cell cc(x, y);
        if (std::find(pos.cells()->begin(), pos.cells()->end(), cc) !=
            pos.cells()->end()) {
          return false;
        }
      }
    }
  }
  return true;
}
} // namespace isa::misc
