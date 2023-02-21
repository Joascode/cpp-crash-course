#include <cstdio>
#include <ctime>

struct TimerClass {
  TimerClass() : timestamp{std::time(nullptr)} {}
  TimerClass(const TimerClass &other) = default;
  TimerClass(TimerClass &&other) noexcept : timestamp{other.timestamp} {
    other.timestamp = 0;
  }

  auto operator=(const TimerClass &other) -> TimerClass & {
    if (this == &other) {
      return *this;
    }
    timestamp = other.timestamp;
    return *this;
  }
  auto operator=(TimerClass &&other) noexcept -> TimerClass & {
    if (this == &other) {
      return *this;
    }
    timestamp = other.timestamp;
    other.timestamp = 0;
    return *this;
  }

  ~TimerClass() {
    if (timestamp != 0) {
      const std::time_t age = std::time(nullptr) - timestamp;
      printf("Age of TimerClass: %ld\n", age);
    }
  }

  std::time_t timestamp;
};

auto main() -> int { const TimerClass timer{}; }