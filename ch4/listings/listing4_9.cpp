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

auto main() -> int {
  Groucho groucho;
  try {
    groucho.Forget(0xC0dE);
    groucho.Forget(0xFACE);
    groucho.Forget(0xC0FFEE);
  } catch (const std::runtime_error &error) {
    printf("Exception caught with message: %s\n", error.what());
  }
}