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
    // Example of using the `this` pointer. Doesn't add value in this case.
    this->year_ = new_year;
    return true;
  }
  auto GetYear() const -> int { return year_; }

private:
  int year_;
};

struct Avout {
  // Use of member initialization list, to set const member variable during
  // object construction.
  Avout(const char *name, int year_of_apert)
      : name{name}, apert{year_of_apert} {}

  void Announce() const {
    printf("My name is %s and my next apert is %d.\n", name, apert.GetYear());
  }
  // Member variable is now const: the pointed-to value can
  // not be modified.
  const char *name;
  ClockOfTheLongNow apert;
};

auto main() -> int {
  const Avout raz{"Erasmas", 3010};
  const Avout jad{"Jad", 4000};

  raz.Announce();
  jad.Announce();
}