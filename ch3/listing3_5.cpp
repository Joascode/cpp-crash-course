#include <cstdio>

struct College {
  // C-style string for pointer decay example
  // clang-tidy recommends std::array<>
  char name[256]; // NOLINT
};

void PrintName(College *colleges, size_t n_colleges) {
  for (size_t i = 0; i < n_colleges; i++) {
    printf("%s College\n", colleges[i].name);
  }
}

auto main() -> int {
  College best_colleges[] = {"Magdalen", "Nuffield", "Kellogg"}; // NOLINT
  // best_colleges array decays into a pointer of the first element
  PrintName(best_colleges, sizeof(best_colleges) / sizeof(College));
}