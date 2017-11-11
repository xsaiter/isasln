#pragma once

#include <memory>
#include <set>

namespace isa {
template <typename T> class disjoint_sets_s {
public:
  struct item_s {
    item_s(const T &d) : data(d) {}
    std::shared_ptr<item_s> parent;
    T data;
    int rank;
    void set_parent(const T &arg) {
      parent = std::shared_ptr<item_s>(new item_s(arg));
    }

    friend bool operator<(const item_s &a, const item_s &b) {
      return a.data < b.data;
    }

    friend bool operator==(const item_s &a, const item_s &b) {
      return a.data == b.data;
    }

    friend bool operator!=(const item_s &a, const item_s &b) {
      return !(a == b);
    }
  };

  void add(const T &t) { sets_.insert(item_s(t)); }

  T find(const T &t) {
    item_s that(t);

    typename std::set<item_s>::iterator i = sets_.find(that);

    if (i != sets_.end()) {
      if (!((*i).parent)) {
        return (*i).data;
      }

      T parent_data = ((*i).parent)->data;
      T x = find(parent_data);
      item_s ii = (*i);
      ii.set_parent(x);

      return x;
    }

    throw std::logic_error("");
  }

  void union_for(const T &a, const T &b) {
    T ax = find(a);
    T bx = find(b);

    if (ax == bx) {
      return;
    }

    typename std::set<item_s>::iterator iax = sets_.find(item_s(ax));
    typename std::set<item_s>::iterator ibx = sets_.find(item_s(bx));

    item_s &a_item = const_cast<item_s &>(*iax);
    item_s &b_item = const_cast<item_s &>(*ibx);

    if (a_item == b_item) {
      return;
    }

    if (a_item.rank > b_item.rank) {
      b_item.set_parent(a);
      a_item.rank++;
    } else {
      a_item.set_parent(b);
      b_item.rank++;
    }
  }

private:
  std::set<item_s> sets_;
};
}
