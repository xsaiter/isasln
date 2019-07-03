#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#include "isa/geo/geo.hh"
#include "isa/str/str_utils.hh"

namespace pso::iom::t_01 {
struct A_timer {
  /*
   * time - hh:mm:ss
   * interval - h:m:s
   * return - hh:mm:ss + n days
   */
  std::string run(const std::string &time, const std::string &interval) {
    Tm ttm = Tm::parse(time);
    Tm itm = Tm::parse(interval);

    const int total_secs = ttm.to_secs() + itm.to_secs();

    int m_h = total_secs % Tm::SECS_IN_HOUR;
    int r_h = (total_secs - m_h) / Tm::SECS_IN_HOUR;
    int m_m = m_h % Tm::SECS_IN_MIN;

    int secs = m_m;
    int mins = (m_h - m_m) / Tm::SECS_IN_MIN;
    int hours = r_h % Tm::HOURS_IN_DAY;
    int days = (r_h - hours) / Tm::HOURS_IN_DAY;

    std::ostringstream ss;

    ss << hours << ":" << mins << ":" << secs;
    if (days > 0) {
      ss << "+" << days << " days";
    }

    return ss.str();
  }

private:
  struct Tm {
    int h, m, s;
    int to_secs() const { return h * SECS_IN_HOUR + m * SECS_IN_MIN + s; }

    static const int SECS_IN_HOUR = 3600;
    static const int SECS_IN_MIN = 60;
    static const int HOURS_IN_DAY = 24;

    static Tm parse(const std::string &s) {
      std::vector<std::string> parts = isa::str::str_split(s, ':');
      const auto n = parts.size();
      if (n == 3) {
        return Tm{idx(parts, 0), idx(parts, 1), idx(parts, 2)};
      }
      if (n == 2) {
        return Tm{0, idx(parts, 0), idx(parts, 1)};
      }
      if (n == 1) {
        return Tm{0, 0, idx(parts, 0)};
      }
      throw std::runtime_error("illegal format");
    }

    static int idx(const std::vector<std::string> &v, int i) {
      return std::stoi(v[i]);
    }
  };
};

struct C_treasure {
  struct step_s {
    int dir;
    int size;
  };

  isa::geo::Point<double> run(const std::vector<step_s> &steps) {
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
};
} // namespace pso::iom::t_01
