#include <cstdio>

void WriteTo(char *word, size_t n_letters, int index, char letter) {
  if (index < n_letters - 1) {
    word[index] = letter;
  }
}

auto ReadFrom(const char *word, size_t n_letters, int index) -> char {
  if (index < n_letters - 1) {
    return word[index];
  }
  return word[0];
}

auto main() -> int {
  char lower[] = "abc?e";  // NOLINT
  char upper[] = "ABC?E";  // NOLINT
  char *upper_ptr = upper; // Equivalent to &upper[0]

  // The mechanism is the same for changing the 4th element in the array
  // even though upper_ptr is a pointer to the first element of the array
  WriteTo(lower, sizeof(lower) / sizeof(lower[0]), 3, 'd');
  WriteTo(upper_ptr, sizeof(upper) / sizeof(upper[0]), 3, 'D');

  const char letter_d = ReadFrom(lower, sizeof(lower) / sizeof(lower[0]), 3);
  const char letter_D = // NOLINT
      ReadFrom(upper_ptr, sizeof(upper) / sizeof(upper[0]), 6);

  printf("lower: %s\nupper: %s\n", lower, upper);
  printf("lower d: %c\nupper D: %c\n", letter_d, letter_D);
}