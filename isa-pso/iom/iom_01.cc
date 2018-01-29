#include <algorithm>
#include <cassert>

#include "iom_01.hh"

#include "strings/str_utils.hh"

namespace iom {

struct tm_s {
  int h, m, s;
  int to_secs() const { return h * 3600 + m * 60 + s; }
};

inline static int idx(const std::vector<std::string> &v, int i) {
  return std::stoi(v.at(i));
}

tm_s parse_tm(const std::string &s) {
  std::vector<std::string> t_splits = isa::strings::str_split(s, ':');
  return tm_s{idx(t_splits, 0), idx(t_splits, 1), idx(t_splits, 2)};
}

/*
 * time - hh:mm:ss
 * interval - h:m:s
*/
std::string iom_01_a_timer(const std::string &time,
                           const std::string &interval) {
  tm_s t_tm = parse_tm(time);
  tm_s i_tm = parse_tm(interval);

  int t_secs = t_tm.to_secs();
  int i_secs = i_tm.to_secs();

  int r_secs = t_secs + i_secs;

  tm_s r;
  int mod_h = r_secs % 3600;
  r.h = (r_secs - mod_h) / 3600;

  int mod_m = r_secs % 60;

  return "";
}

void iom_01_c_treasure() {}
}
