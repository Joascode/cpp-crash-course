#include <cstddef>
#include <cstdio>
#include <ctime>
#include <utility>

struct TimerClass {
  explicit TimerClass(const char *name)
      : m_timestamp{std::time(nullptr)}, m_name{name} {}

  TimerClass(const TimerClass &other)
      : m_timestamp{other.m_timestamp}, m_name{other.m_name} {
    printf("Copy constructor\n");
  }

  TimerClass(TimerClass &&other) noexcept
      : m_timestamp{other.m_timestamp}, m_name{other.m_name} {
    printf("Move constructor\n");
    other.m_timestamp = 0;
    other.m_name = nullptr;
  }

  auto operator=(const TimerClass &other) -> TimerClass & {
    printf("Copy assignment\n");
    if (this == &other) {
      return *this;
    }
    m_timestamp = other.m_timestamp;
    m_name = other.m_name;
    return *this;
  }

  auto operator=(TimerClass &&other) noexcept -> TimerClass & {
    printf("Move assignment\n");
    if (this == &other) {
      return *this;
    }
    m_timestamp = other.m_timestamp;
    m_name = other.m_name;
    other.m_name = nullptr;
    other.m_timestamp = 0;
    return *this;
  }

  ~TimerClass() {
    printf("Timestamp: %ld\n", m_timestamp);
    if (m_timestamp != 0) {
      const std::time_t age = std::time(nullptr) - m_timestamp;
      printf("Age of %s: %ld\n", m_name, age);
    } else {
      printf("%s is moved.\n", m_name);
    }
  }

  std::time_t m_timestamp;
  const char *m_name;
};

auto main() -> int {
  TimerClass timer{"first timer"};
  TimerClass timer2{"second timer"};
  const TimerClass timer3{timer};
  timer2 = std::move(timer);
  printf("Name of timer3: %s\n", timer3.m_name);
}