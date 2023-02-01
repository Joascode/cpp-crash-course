#include <cstdio>

struct Tracer {
  explicit Tracer(const char *name) : name_{name} {
    printf("%s constructed.\n", name);
  }

  ~Tracer() { printf("%s destructed.\n", name_); }

private:
  const char *const name_;
};