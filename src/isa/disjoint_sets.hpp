#pragma once

#include <memory>
#include <set>

namespace isa {
template <typename T>
class Disjoint_sets {
 public:
  struct Item {
    explicit Item(const T& data_) : data(data_) {}

    T data;
    mutable std::shared_ptr<Item> parent;
    mutable int rank;

    void set_parent(const T& data) const {
      parent = std::make_shared<Item>(data);
    }

    void inc_rank() const { ++rank; }

    friend bool operator<(const Item& lhs, const Item& rhs) {
      return lhs.data < rhs.data;
    }

    friend bool operator==(const Item& lhs, const Item& rhs) {
      return lhs.data == rhs.data;
    }

    friend bool operator!=(const Item& lhs, const Item& rhs) {
      return !(lhs == rhs);
    }
  };

  void add(const T& data) { items_.insert(Item(data)); }

  T find(const T& data) {
    auto i = items_.find(Item(data));

    if (i == items_.end()) {
      throw std::logic_error("not found");
    }

    if (!(i->parent)) {
      return i->data;
    }

    auto x = find(i->parent->data);

    i->set_parent(x);

    return x;
  }

  void union_for(const T& a, const T& b) {
    auto ax = find(a);
    auto bx = find(b);

    if (ax == bx) {
      return;
    }

    auto axi = items_.find(Item(ax));
    auto bxi = items_.find(Item(bx));

    if (*axi != *bxi) {
      if (axi->rank > bxi->rank) {
        bxi->set_parent(a);
        axi->inc_rank();
      } else {
        axi->set_parent(b);
        bxi->inc_rank();
      }
    }
  }

 private:
  std::set<Item> items_;
};
}  // namespace isa
