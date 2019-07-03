#include "knight_tour.hh"

namespace isa::misc {
using cells_u = std::vector<Knight_tour::Cell>;
using cells_ptr_u = std::shared_ptr<cells_u>;

Knight_tour::Knight_tour(std::size_t width, std::size_t height,
                             const Cell &start)
    : width_(width), height_(height), ncells_(width_ * height_), start_(start) {
}

bool Knight_tour::Route::is_success() const { return success_; }

void Knight_tour::Route::set_success(bool success) { success_ = success; }

std::size_t Knight_tour::Route::size() const { return cells_->size(); }

bool Knight_tour::Route::exists(const Cell &cell) const {
  return std::find(cells_->begin(), cells_->end(), cell) != cells_->end();
}

cells_ptr_u Knight_tour::Route::cells() const { return cells_; }

Knight_tour::Route Knight_tour::find_route() {
  Route res;
  res.cells()->push_back(start_);
  res.set_success(try_find(res, start_));
  return res;
}

bool Knight_tour::try_find(Route &route, const Cell &cell) {
  auto moves = next_moves(route, cell);

  for (auto m = moves->begin(); m != moves->end(); ++m) {
    route.cells()->push_back(*m);
    if (try_find(route, *m)) {
      break;
    }

    auto rem = std::remove(route.cells()->begin(), route.cells()->end(), *m);
    route.cells()->erase(rem, route.cells()->end());
  }

  return route.size() == ncells_;
}

cells_ptr_u Knight_tour::next_moves(Route &route,
                                      const Cell &current) const {
  cells_ptr_u res(new cells_u);
  for (int i = 0; i < 8; ++i) {
    Cell next(current.x_ + shifts_[0][i], current.y_ + shifts_[1][i]);
    if (valid_cell(next) && !route.exists(next)) {
      res->push_back(next);
    }
  }
  return res;
}

bool Knight_tour::valid_cell(const Cell &c) const {
  return c.x_ >= 1 && c.x_ <= width_ && c.y_ >= 1 && c.y_ <= height_;
}
}
