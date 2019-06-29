#pragma once

#include <memory>
#include <vector>

namespace isa::misc {
class all_queens_s {
public:
  struct cell_s {
    std::size_t x_;
    std::size_t y_;
    bool operator==(const cell_s &other) {
      return x_ == other.x_ && y_ == other.y_;
    }
    cell_s(std::size_t x, std::size_t y) : x_(x), y_(y) {}
  };

  class position_s {
  public:
    position_s();
    std::shared_ptr<std::vector<cell_s>> cells() const { return cells_; }
    bool is_success() const { return success_; }

  private:
    friend class all_queens_s;
    std::shared_ptr<std::vector<cell_s>> cells_;
    bool success_;

    void set_success(bool success) { success_ = success; }
    std::size_t size() const { return cells_->size(); }
  };

  all_queens_s(std::size_t n);
  position_s find_position();

private:
  std::size_t n_;
  bool try_find(position_s &pos);
  std::shared_ptr<std::vector<cell_s>> next_moves(position_s &pos) const;
  bool check_position(position_s &pos) const;
};
} // namespace isa::misc
