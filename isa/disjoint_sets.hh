#pragma once

#include <memory>
#include <set>

namespace isa {
template <class T> class disjoint_sets_s {
public:
  struct item_s {
    explicit item_s(const T &data_) : data(data_) {}

    T data;
    mutable std::shared_ptr<item_s> parent;
    mutable int rank;

    void set_parent(const T &data) const {
      parent = std::make_shared<item_s>(data);
    }

    void inc_rank() const { ++rank; }

    friend bool operator<(const item_s &lhs, const item_s &rhs) {
      return lhs.data < rhs.data;
    }

    friend bool operator==(const item_s &lhs, const item_s &rhs) {
      return lhs.data == rhs.data;
    }

    friend bool operator!=(const item_s &lhs, const item_s &rhs) {
      return !(lhs == rhs);
    }
  };

  void add(const T &data) { items_.insert(item_s(data)); }

  T find(const T &data) {
    auto i = items_.find(item_s(data));

    if (i != items_.end()) {
      if (!(i->parent)) {
        return i->data;
      }

      auto x = find(i->parent->data);

      i->set_parent(x);

      return x;
    }

    throw std::logic_error("not found");
  }

  void union_for(const T &a, const T &b) {
    auto ax = find(a);
    auto bx = find(b);

    if (ax == bx) {
      return;
    }

    auto axi = items_.find(item_s(ax));
    auto bxi = items_.find(item_s(bx));

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
  std::set<item_s> items_;
};
}
