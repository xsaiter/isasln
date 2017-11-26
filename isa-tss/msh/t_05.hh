#pragma once

#include <set>
#include <string>

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

std::vector<std::string> t_05_b_bracket2(int n);

std::string t_05_e_scale(int src_val, int src, int dest);

int t_05_birthday(int birth_day, int birth_month, int cur_day, int cur_month,
                  int cur_year);
}
}
