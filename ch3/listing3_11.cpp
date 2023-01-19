#include <cstdio>
auto main() -> int {
  int original = 100;
  int &original_ref = original;
  printf("Original:  %d\n", original);
  printf("Reference: %d\n", original_ref);

  const int new_value = 200;
  // original_ref can't be reseated! original_ref references to original,
  // therefor original will now hold the value 200 as well!
  // This assignment simply puts the value of new_value into original.
  original_ref = new_value;

  printf("Original:  %d\n", original);
  printf("New Value: %d\n", new_value);
  printf("Reference: %d\n", original_ref);
}