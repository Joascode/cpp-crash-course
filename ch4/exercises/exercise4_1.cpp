#include <ctime>

struct TimerClass {
  TimerClass() : timestamp{std::time(nullptr)} {}

  std::time_t timestamp;
};

auto main() -> int { const TimerClass timer{}; }