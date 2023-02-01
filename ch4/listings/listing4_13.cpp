#include <cstdio>
#include <stdexcept>

struct CyberdyneSeries800 {
  CyberdyneSeries800() { printf("I'm a friend of Sarah Conner."); }
  // DON'T DO THIS!
  ~CyberdyneSeries800() { throw std::runtime_error{"I'll be back."}; } // NOLINT
};

auto main() -> int {
  try {
    // Automatic variable, gets cleaned up automatically
    const CyberdyneSeries800 t800;
    throw std::runtime_error{"Come with me if you want to live."};
  } catch (const std::runtime_error &e) {
    // Since the block-scope of t800 ends in try, t800 gets destructed and
    // throws its own exception as well. There are now 2 exceptions in flight.
    // Normal behaviour of the C++ runtime is to TERMINATE!
    // Neither error is printed.
    printf("Caught exception: %s\n", e.what());
  }
}