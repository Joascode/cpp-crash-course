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

auto IsLeapYear(const ClockOfTheLongNow &clock) -> bool {
  // Since GetYear is const we can use it here.
  // Once a argument is const, we can only use const methods on that parameter.
  if (clock.GetYear() % 4 > 0) {
    return false;
  }
  if (clock.GetYear() % 100 > 0) {
    return false;
  }
  if (clock.GetYear() % 400 > 0) {
    return false;
  }
  return true;
}