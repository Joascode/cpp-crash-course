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
    printf("variable m_name is at address: %p\n", m_name);
    printf("variable other.m_name is at address: %p\n", other.m_name);
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
    // There's a lot of test prints in this exercise to determine what happens.
    // I was contemplating whether this would violate the copy rules or not.
    // Since it points to the same location in memory.
    // But since it's a const *char, the location is only readable and not
    // assignable.
    // Should other.m_name change value, it points to a new block of memory.
    // m_name in this instance remains unchanged.
    m_name = other.m_name;
    printf("variable m_name is at address: %p\n", m_name);
    printf("variable other.m_name is at address: %p\n", other.m_name);
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
  // This apparently does work
  timer.m_name = "test name";
  printf("variable timer.m_name is at address: %p\n", timer.m_name);
  timer2 = std::move(timer);
  // A simple long for-loop to get a timestamp difference between creation and
  // deletion. Fortunately, the compiler didn't compile this away in my case :)
  for (auto i = 0L; i < 100000000; i++) {
  }
  printf("Name of timer3: %s\n", timer3.m_name);
}