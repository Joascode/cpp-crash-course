#include <cstddef>
#include <cstdio>
#include <ctime>
#include <utility>

struct TimerClass {
  explicit TimerClass(const char *name)
      : timestamp{std::time(nullptr)}, name{name} {}
  TimerClass(const TimerClass &other) = default;
  TimerClass(TimerClass &&other) noexcept : timestamp{other.timestamp} {
    printf("Move constructor\n");
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
    printf("Move assignment\n");
    if (this == &other) {
      return *this;
    }
    timestamp = other.timestamp;
    name = other.name;
    other.name = nullptr;
    other.timestamp = 0;
    return *this;
  }

  ~TimerClass() {
    printf("Timestamp: %ld\n", timestamp);
    if (timestamp != 0) {
      const std::time_t age = std::time(nullptr) - timestamp;
      printf("Age of %s: %ld\n", name, age);
    } else {
      printf("%s is moved.\n", name);
    }
  }

  std::time_t timestamp;
  const char *name;
};

auto main() -> int {
  TimerClass timer{"first timer"};
  TimerClass timer2{"second timer"};
  timer2 = std::move(timer);
}