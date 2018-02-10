#include <algorithm>
#include <cassert>
#include <sstream>

#include "iom_01.hh"

#include "strings/str_utils.hh"

namespace iom {

struct tm_s {
  int h, m, s;
  int to_secs() const { return h * SECS_IN_HOUR + m * SECS_IN_MIN + s; }

  static const int SECS_IN_HOUR = 3600;
  static const int SECS_IN_MIN = 60;
  static const int HOURS_IN_DAY = 24;

  static tm_s parse(const std::string &s) {
    std::vector<std::string> parts = isa::strings::str_split(s, ':');
    const auto n = parts.size();
    if (n == 3) {
      return tm_s{idx(parts, 0), idx(parts, 1), idx(parts, 2)};
    }
    if (n == 2) {
      return tm_s{0, idx(parts, 0), idx(parts, 1)};
    }
    if (n == 1) {
      return tm_s{0, 0, idx(parts, 0)};
    }
    throw std::runtime_error("illegal format");
  }

  static int idx(const std::vector<std::string> &v, int i) {
    return std::stoi(v.at(i));
  }
};

/*
 * time - hh:mm:ss
 * interval - h:m:s
 * return - hh:mm:ss + n days
*/
std::string iom_01_a_timer(const std::string &time,
                           const std::string &interval) {
  tm_s ttm = tm_s::parse(time);
  tm_s itm = tm_s::parse(interval);

  const int total_secs = ttm.to_secs() + itm.to_secs();

  int m_h = total_secs % tm_s::SECS_IN_HOUR;
  int r_h = (total_secs - m_h) / tm_s::SECS_IN_HOUR;
  int m_m = m_h % tm_s::SECS_IN_MIN;

  int secs = m_m;
  int mins = (m_h - m_m) / tm_s::SECS_IN_MIN;
  int hours = r_h % tm_s::HOURS_IN_DAY;
  int days = (r_h - hours) / tm_s::HOURS_IN_DAY;

  std::ostringstream ss;

  ss << hours << ":" << mins << ":" << secs;
  if (days > 0) {
    ss << "+" << days << " days";
  }

  return ss.str();
}

isa::geo::point_s<double> iom_01_c_treasure(const std::vector<step_s> &steps) {
  const auto a = std::cos(45 * M_PI / 180);

  auto r = isa::geo::make_point(0.0, 0.0);

  for (const step_s &step : steps) {
    if (step.dir == 1) {
      r.y += step.size;
    } else if (step.dir == 2) {
      r.x += step.size * a;
      r.y += step.size * a;
    } else if (step.dir == 3) {
      r.x += step.size;
    } else if (step.dir == 4) {
      r.x += step.size * a;
      r.y -= step.size * a;
    } else if (step.dir == 5) {
      r.y -= step.size;
    } else if (step.dir == 6) {
      r.x -= step.size * a;
      r.y -= step.size * a;
    } else if (step.dir == 7) {
      r.x -= step.size;
    } else if (step.dir == 8) {
      r.x -= step.size * a;
      r.y += step.size * a;
    }
  }

  return r;
}
}
