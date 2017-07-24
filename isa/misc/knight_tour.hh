#pragma once

#include <algorithm>
#include <memory>
#include <vector>

namespace isa {
namespace misc {

class knight_tour_t {
public:
  struct cell_t {
    std::size_t x_;
    std::size_t y_;
    cell_t(std::size_t x, std::size_t y) : x_(x), y_(y) {}

    bool operator==(const cell_t &other) {
      return x_ == other.x_ && y_ == other.y_;
    }
  };

  class route_t {
  public:
    route_t() : cells_(new std::vector<cell_t>) {}
    std::shared_ptr<std::vector<cell_t>> cells() const;
    bool is_success() const;

  private:
    friend class knight_tour_t;

    std::shared_ptr<std::vector<cell_t>> cells_;
    bool success_;

    void set_success(bool success);
    std::size_t size() const;
    bool exists(const cell_t &cell_t) const;
  };

  knight_tour_t(std::size_t width, std::size_t height, const cell_t &start);
  route_t find_route();

private:
  std::size_t width_;
  std::size_t height_;
  std::size_t n_cells_;
  cell_t start_;
  const int shifts_[2][8] = {{-2, -1, 1, 2, 2, 1, -1, -2},
                             {1, 2, 2, 1, -1, -2, -2, -1}};

  bool try_find(route_t &route, const cell_t &cell_t);
  std::shared_ptr<std::vector<cell_t>> next_moves(route_t &r,
                                                  const cell_t &current) const;
  bool valid_cell(const cell_t &c) const;
};
}
}
