#include <cstdio>
#include <ctime>

struct TimerClass {
  TimerClass() : timestamp{std::time(nullptr)} {}

  ~TimerClass() {
    const std::time_t age = std::time(nullptr) - timestamp;
    printf("Age of TimerClass: %ld\n", age);
  }

  std::time_t timestamp;
};

auto main() -> int { const TimerClass timer{}; }