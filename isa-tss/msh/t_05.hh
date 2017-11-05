#pragma once

#include <set>

#include "ranges.hh"

namespace tss {
namespace msh {
struct divs_s {
  int x, y;
};

int operator<(const divs_s &a, const divs_s &b);
bool operator==(const divs_s &a, const divs_s &b);
bool operator!=(const divs_s &a, const divs_s &b);

bool is_friendly(int m, int n);

std::set<divs_s> t_05_a_friendly(int m, int n);
}
}
