#include "core.hh"

namespace pso {
slnp_u make_sln(int data, slnp_u next) {
  slnp_u res(new sln_u{data, next});
  return res;
}
}
