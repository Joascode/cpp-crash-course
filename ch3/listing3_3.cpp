#include <cstdio>

struct ClockOfTheLongNow {
  explicit ClockOfTheLongNow(int year) {
    if (!SetYear(year)) {
      year_ = 2019;
    }
  }
  void AddYear() { year_++; }
  auto SetYear(int new_year) -> bool {
    if (new_year < 2019) {
      return false;
    }
    year_ = new_year;
    return true;
  }
  auto GetYear() const -> int { return year_; }

private:
  int year_;
};

auto main() -> int {
  ClockOfTheLongNow clock = ClockOfTheLongNow(2019);
  ClockOfTheLongNow *clock_ptr = &clock;
  clock_ptr->SetYear(2020);
  printf("Address of clock: %p\n", clock_ptr);
  printf("Value of clock's year: %d\n", clock_ptr->GetYear());
  // printf("Value of clock's year: %d\n", (*clock_ptr).GetYear()); <- This is
  // the same behaviour as clock_ptr->GetYear()
}