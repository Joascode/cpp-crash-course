#include <cstdio>

struct College {
  // C-style string for pointer decay example
  // clang-tidy recommends std::array<>
  char name[256];
};

void PrintName(College *college_ptr) {
  // Another array decay to pointer occurs here, where printf %s expects a
  // C-style array. name inside College struct is a C-style array and decays
  // into a pointer.
  printf("%s College\n", college_ptr->name);
}

auto main() -> int {
  College best_colleges[] = {"Magdalen", "Nuffield", "Kellogg"};
  // best_colleges array decays into a pointer of the first element
  PrintName(best_colleges); // Prints Magdalen College
}