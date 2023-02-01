#include <cstdio>

struct Tracer {
  explicit Tracer(const char *name) : name_{name} {
    printf("%s constructed.\n", name);
  }

  ~Tracer() { printf("%s destructed.\n", name_); }

private:
  const char *const name_;
};

// Both created before main() is run.
// And both destroyed when the program exits.
static Tracer tracer1{"Static variable"};
// In the book it says this variable is printed right after tracer1, but it
// never happened for me. Probably different compiler or compiler version.
thread_local Tracer tracer2{"Thread-local variable"};

auto main() -> int {
  printf("A\n");
  // Scoped to the main function and since it is automatic, deletes itself when
  // main ends.
  const Tracer tracer3{"Automatic variable"};
  printf("B\n");
  // Because we use the keyword `new`, the allocation is dynamic.
  // Since delete tracer4 is never called, this is leaking memory.
  const auto *tracer4 = new Tracer{"Dynamic variable"};
  printf("C\n");
}