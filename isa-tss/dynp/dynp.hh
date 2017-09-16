// dynamic prog

#pragma once

#include <string>
#include <vector>

namespace dynp {
int add_least_to_palindrome(const std::string &s);
int house_robber(const std::vector<int> &a);
int levenshtein_distance(const std::string &from, const std::string &to);
int max_common_sequence(const std::string &s1, const std::string &s2);

struct subarray_with_max_sum_res_s {
  int beg, end, sum;
};

void subarray_with_max_sum(const std::vector<int> &a,
                           subarray_with_max_sum_res_s &res);

struct turtle_travel_res_s {
  struct cell_s {
    int x, y, val;
    cell_s(int x_, int y_, int val_) : x(x_), y(y_), val(val_) {}
  };

  int sum;
  std::vector<cell_s> path;
};

void turtle_travel(const std::vector<std::vector<int>> &a, int rows, int cols,
                   turtle_travel_res_s &res);

struct largest_square_res_s {
  int bottomRightRow;
  int bottomRightCol;
  int side;
};

void largest_square(const std::vector<std::vector<int>> &a, int rows, int cols,
                    largest_square_res_s &res);
}
