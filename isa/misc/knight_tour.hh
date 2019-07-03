#pragma once

#include <algorithm>
#include <memory>
#include <vector>

namespace isa::misc {
class Knight_tour {
public:
  struct Cell {
    std::size_t x_;
    std::size_t y_;
    Cell(std::size_t x, std::size_t y) : x_(x), y_(y) {}

    bool operator==(const Cell &other) {
      return x_ == other.x_ && y_ == other.y_;
    }
  };

  class Route {
  public:
    Route() : cells_(new std::vector<Cell>) {}
    std::shared_ptr<std::vector<Cell>> cells() const;
    bool is_success() const;

  private:
    friend class Knight_tour;

    std::shared_ptr<std::vector<Cell>> cells_;
    bool success_;

    void set_success(bool success);
    std::size_t size() const;
    bool exists(const Cell &cell) const;
  };

  Knight_tour(std::size_t width, std::size_t height, const Cell &start);
  Route find_route();

private:
  std::size_t width_;
  std::size_t height_;
  std::size_t ncells_;
  Cell start_;
  const int shifts_[2][8] = {{-2, -1, 1, 2, 2, 1, -1, -2},
                             {1, 2, 2, 1, -1, -2, -2, -1}};

  bool try_find(Route &route, const Cell &cell);
  std::shared_ptr<std::vector<Cell>> next_moves(Route &route,
                                                const Cell &current) const;
  bool valid_cell(const Cell &c) const;
};
} // namespace isa::misc
