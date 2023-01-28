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

void AddYear(ClockOfTheLongNow &clock) { clock.SetYear(clock.GetYear() + 1); }

auto main() -> int {
  ClockOfTheLongNow clock{2020};
  printf("The year is %d.\n", clock.GetYear());
  AddYear(clock);
  printf("The year is %d.\n", clock.GetYear());
}