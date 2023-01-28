#include <cstdio>

void WriteTo(char *word, int index, char letter) { word[index] = letter; }

auto ReadFrom(const char *word, int index) -> char { return word[index]; }

auto main() -> int {
  char lower[] = "abc?e";  // NOLINT
  char upper[] = "ABC?E";  // NOLINT
  char *upper_ptr = upper; // Equivalent to &upper[0]

  // The mechanism is the same for changing the 4th element in the array
  // even though upper_ptr is a pointer to the first element of the array
  WriteTo(lower, 3, 'd');
  WriteTo(upper_ptr, 3, 'D');

  const char letter_d = ReadFrom(lower, 3);
  const char letter_D = ReadFrom(upper_ptr, 3); // NOLINT

  printf("lower: %s\nupper: %s\n", lower, upper);
}