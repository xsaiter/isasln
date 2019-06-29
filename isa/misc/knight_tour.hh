#pragma once

#include <algorithm>
#include <memory>
#include <vector>

namespace isa::misc {
class knight_tour_s {
public:
  struct cell_s {
    std::size_t x_;
    std::size_t y_;
    cell_s(std::size_t x, std::size_t y) : x_(x), y_(y) {}

    bool operator==(const cell_s &other) {
      return x_ == other.x_ && y_ == other.y_;
    }
  };

  class route_s {
  public:
    route_s() : cells_(new std::vector<cell_s>) {}
    std::shared_ptr<std::vector<cell_s>> cells() const;
    bool is_success() const;

  private:
    friend class knight_tour_s;

    std::shared_ptr<std::vector<cell_s>> cells_;
    bool success_;

    void set_success(bool success);
    std::size_t size() const;
    bool exists(const cell_s &cell) const;
  };

  knight_tour_s(std::size_t width, std::size_t height, const cell_s &start);
  route_s find_route();

private:
  std::size_t width_;
  std::size_t height_;
  std::size_t ncells_;
  cell_s start_;
  const int shifts_[2][8] = {{-2, -1, 1, 2, 2, 1, -1, -2},
                             {1, 2, 2, 1, -1, -2, -2, -1}};

  bool try_find(route_s &route, const cell_s &cell);
  std::shared_ptr<std::vector<cell_s>> next_moves(route_s &route,
                                                  const cell_s &current) const;
  bool valid_cell(const cell_s &c) const;
};
} // namespace isa::misc
