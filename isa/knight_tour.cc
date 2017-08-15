#include "knight_tour.hh"

namespace isa {
namespace misc {

typedef std::vector<knight_tour_t::cell_t> cells_t;
typedef std::shared_ptr<cells_t> cells_ptr_t;

knight_tour_t::knight_tour_t(std::size_t width, std::size_t height,
                             const cell_t &start)
    : width_(width), height_(height), n_cells_(width_ * height_),
      start_(start) {}

bool knight_tour_t::route_t::is_success() const { return success_; }

void knight_tour_t::route_t::set_success(bool success) { success_ = success; }

std::size_t knight_tour_t::route_t::size() const { return cells_->size(); }

bool knight_tour_t::route_t::exists(const cell_t &cell) const {
  return std::find(cells_->begin(), cells_->end(), cell) != cells_->end();
}

cells_ptr_t knight_tour_t::route_t::cells() const { return cells_; }

knight_tour_t::route_t knight_tour_t::find_route() {
  route_t res;
  res.cells()->push_back(start_);
  res.set_success(try_find(res, start_));
  return res;
}

bool knight_tour_t::try_find(route_t &route, const cell_t &cell) {
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

cells_ptr_t knight_tour_t::next_moves(route_t &route,
                                      const cell_t &current) const {
  cells_ptr_t res(new cells_t);
  for (int i = 0; i < 8; ++i) {
    cell_t next(current.x_ + shifts_[0][i], current.y_ + shifts_[1][i]);
    if (valid_cell(next) && !route.exists(next)) {
      res->push_back(next);
    }
  }
  return res;
}

bool knight_tour_t::valid_cell(const cell_t &c) const {
  return c.x_ >= 1 && c.x_ <= width_ && c.y_ >= 1 && c.y_ <= height_;
}
}
}
