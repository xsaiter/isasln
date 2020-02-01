#include "core.hpp"
#include "isa/sort.hpp"
#include "lia/matrix.hpp"
#include "rb_tree.hpp"
#include <string>
#include <thread>

#include "msh/t_08.hpp"
#include "msh/t_15.hpp"
#include "shen/shen_01.hpp"
#include "utils.hpp"

#include "isa/vect.hpp"

#include "eul/p_001_050.hpp"
#include "graphs/graph.hpp"
#include <iterator>

#include <boost/container/slist.hpp>

#include "dynp/dynp.hpp"

struct Item {
  int x, y;
};

int main(int argc, char const *argv[]) {
  // boost::geometry::convex_hull<int, int>(nullptr, nullptr);

  boost::container::slist<int> list;

  list.push_front(100);
  list.push_front(200);

  auto ma = pso::dynp::new_mat<int>(10, 20, 500);

  std::vector<Item> items;
  items.push_back({1, 1});
  items.push_back({1, 2});
  items.push_back({-3, 4});
  items.push_back({4, 5});

  auto mm =
      std::min_element(items.begin(), items.end(),
                       [](const auto &l, const auto &r) { return l.x < r.x; });

  isa::Range_i range(1, 20);
  std::vector<int> x;
  std::string ss;
  auto fn = []() { return false; };
  auto res_fn = fn();
  x.push_back(1);
  std::vector<int> y;
  std::copy(std::begin(x), std::end(x), std::back_inserter(y));
  std::cout << x[0] << std::endl;
  auto resss = 60 * 300;
  isa::Vect<int> vv{10, 20, 30};
  auto vvc = vv;
  vv[2] = 40;
  auto a = vv[2];
  auto b = vvc[2];
  return 0;
}
