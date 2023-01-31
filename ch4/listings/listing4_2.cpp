#include <cstdio>

// static storage duration variable
// This global static variable is reachable within this translation unit.

// Instead of static int rat_things_power = 0; we can also do:
// By using extern, this variable is now available externally, with external
// linking. Meaning it's reachable outside of it's own translation unit.
extern int rat_things_power = 0; // NOLINT

void PowerUpRatThing(int nuclear_isotopes) {
  rat_things_power += nuclear_isotopes;
  const auto waste_heat = rat_things_power * 20;
  if (waste_heat > 10000) {
    printf("Warning! Hot doggie!\n");
  }
}

auto main() -> int {
  printf("Rat-thing power: %d\n", rat_things_power);
  PowerUpRatThing(100);
  printf("Rat-thing power: %d\n", rat_things_power);
  PowerUpRatThing(500);
  printf("Rat-thing power: %d\n", rat_things_power);
}