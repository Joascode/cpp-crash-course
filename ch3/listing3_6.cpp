#include <cstdio>

auto main() -> int {
  char lower[] = "abc?e";
  char upper[] = "ABC?E";
  char *upper_ptr = upper; // Equivalent to &upper[0]

  // The mechanism is the same for changing the 4th element in the array
  // even though upper_ptr is a pointer to the first element of the array
  lower[3] = 'd';
  upper_ptr[3] = 'D';

  const char letter_d = lower[3];
  const char letter_D = upper_ptr[3];

  printf("lower: %s\nupper: %s\n", lower, upper);

  // lower[7] = 'g'; <- Super bad. Out-of-bounds array access.
}