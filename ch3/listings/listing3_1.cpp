#include <cstdio>

auto main() -> int {
  int gettysburg{};
  printf("gettysburg: %d\n", gettysburg);
  int *gettysburg_address = &gettysburg;
  printf("&gettysburg: %p\n", gettysburg_address);
}