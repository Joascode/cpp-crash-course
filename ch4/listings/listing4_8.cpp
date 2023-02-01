#include <cstdio>
#include <stdexcept>

struct Groucho {
  void Forget(int toForget) { // NOLINT
    if (toForget == 0xFACE) {
      throw std::runtime_error{"I'd be glad to make an exception."};
    }
    printf("Forgot 0x%x\n", toForget);
  }
};