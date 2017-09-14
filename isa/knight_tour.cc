#include "knight_tour.hh"

namespace isa {
namespace misc {

typedef std::vector<knight_tour_s::cell_s> cells_t;
typedef std::shared_ptr<cells_t> cells_ptr_t;

knight_tour_s::knight_tour_s(std::size_t width, std::size_t height,
                             const cell_s &start)
    : width_(width), height_(height), n_cells_(width_ * height_),
      start_(start) {}

bool knight_tour_s::route_s::is_success() const { return success_; }

void knight_tour_s::route_s::set_success(bool success) { success_ = success; }

std::size_t knight_tour_s::route_s::size() const { return cells_->size(); }

bool knight_tour_s::route_s::exists(const cell_s &cell) const {
  return std::find(cells_->begin(), cells_->end(), cell) != cells_->end();
}

cells_ptr_t knight_tour_s::route_s::cells() const { return cells_; }

knight_tour_s::route_s knight_tour_s::find_route() {
  route_s res;
  res.cells()->push_back(start_);
  res.set_success(try_find(res, start_));
  return res;
}

bool knight_tour_s::try_find(route_s &route, const cell_s &cell) {
  auto moves = next_moves(route, cell);

  for (auto m = moves->begin(); m != moves->end(); ++m) {
    route.cells()->push_back(*m);
    if (try_find(route, *m)) {
      break;
    }

    auto rem = std::remove(route.cells()->begin(), route.cells()->end(), *m);
    route.cells()->erase(rem, route.cells()->end());
  }

  return route.size() == n_cells_;
}

cells_ptr_t knight_tour_s::next_moves(route_s &route,
                                      const cell_s &current) const {
  cells_ptr_t res(new cells_t);
  for (int i = 0; i < 8; ++i) {
    cell_s next(current.x_ + shifts_[0][i], current.y_ + shifts_[1][i]);
    if (valid_cell(next) && !route.exists(next)) {
      res->push_back(next);
    }
  }
  return res;
}

bool knight_tour_s::valid_cell(const cell_s &c) const {
  return c.x_ >= 1 && c.x_ <= width_ && c.y_ >= 1 && c.y_ <= height_;
}
}
}
