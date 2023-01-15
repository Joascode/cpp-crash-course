#include <cstdio>

auto main() -> int {
  char lower[] = "abc?e";  // NOLINT
  char upper[] = "ABC?E";  // NOLINT
  char *upper_ptr = upper; // Equivalent to &upper[0]

  // Pointer arithmetic
  *(lower + 3) = 'd';
  *(upper_ptr + 3) = 'D';

  // The book says *(lower + 4) = letter d/D, which isn't true: it's e/E.
  const char letter_d = *(lower + 4);
  const char letter_D = *(upper_ptr + 4); // NOLINT

  // This line isn't in the book, but I wanted to test it. I didn't trust the +
  // 4 pointer arithmetic above.
  printf("letter_d: %c\nletter_D: %c\n", letter_d, letter_D); // NOLINT
  printf("lower: %s\nupper: %s\n", lower, upper);

  // *(lower + 7) = 'g'; <- Super bad. Out-of-bounds array access.
}