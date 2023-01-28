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
  // Member variable is now const: the pointed-to value can not be modified.
  const char *name = "Erasmas";
  ClockOfTheLongNow apert;
};

void DoesNotCompile(const Avout &avout) {
  avout.apert.AddYear(); // Compiler error: avout is const.
}