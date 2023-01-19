#include <cstdio>

void Petruchio(const char *shrew) {
  printf("Fear not, sweet wench, they shall not touch thee, %s.", shrew);
  // Compiler error! The schrew cannot be tamed.
  // Though clang-tidy already warns about it in this case :D
  shrew[0] = "K";
}