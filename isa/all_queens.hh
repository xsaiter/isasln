#pragma once

#include <vector>
#include <memory>

namespace isa {
namespace misc {

class all_queens_t {
public:
  struct cell_t {
    std::size_t x_;
    std::size_t y_;
    bool operator==(const cell_t &other) {
      return x_ == other.x_ && y_ == other.y_;
    }
    cell_t(std::size_t x, std::size_t y) : x_(x), y_(y) {}
  };

  class position_t {
  public:
    position_t();
    std::shared_ptr<std::vector<cell_t>> cells() const { return cells_; }
    bool is_success() const { return success_; }

  private:
    friend class all_queens_t;
    std::shared_ptr<std::vector<cell_t>> cells_;
    bool success_;

    void set_success(bool success) { success_ = success; }
    std::size_t size() const { return cells_->size(); }
  };

  all_queens_t(std::size_t n);
  position_t find_position();

private:
  std::size_t n_;
  bool try_find(position_t &pos);
  std::shared_ptr<std::vector<cell_t>> next_moves(position_t &pos) const;
  bool check_position(position_t &pos) const;
};
}
}
