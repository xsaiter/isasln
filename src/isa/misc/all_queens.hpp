#pragma once

#include <memory>
#include <vector>

namespace isa::misc {
class All_queens {
public:
  struct Cell {
    std::size_t x_;
    std::size_t y_;
    bool operator==(const Cell &other) {
      return x_ == other.x_ && y_ == other.y_;
    }
    Cell(std::size_t x, std::size_t y) : x_(x), y_(y) {}
  };

  class Position {
  public:
    Position();
    std::shared_ptr<std::vector<Cell>> cells() const { return cells_; }
    bool is_success() const { return success_; }

  private:
    friend class All_queens;
    std::shared_ptr<std::vector<Cell>> cells_;
    bool success_;

    void set_success(bool success) { success_ = success; }
    std::size_t size() const { return cells_->size(); }
  };

  All_queens(std::size_t n);
  Position find_position();

private:
  std::size_t n_;
  bool try_find(Position &pos);
  std::shared_ptr<std::vector<Cell>> next_moves(Position &pos) const;
  bool check_position(Position &pos) const;
};
} // namespace isa::misc
