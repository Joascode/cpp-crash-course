#include <cstdio>

struct RatThing {
  static int rat_things_power;
  static void PowerUpRatThing(int nuclear_isotopes) {
    rat_things_power += nuclear_isotopes;
    const auto waste_heat = rat_things_power * 20;
    if (waste_heat > 10000) {
      printf("Warning! Hot doggie!\n");
    }
    printf("Rat-thing power: %d\n", rat_things_power);
  }
};

// With static member variables, you have to initialize them at global scope.
// EXCEPT: when you define the static member variable as const.
int RatThing::rat_things_power = 200;

auto main() -> int {
  RatThing::PowerUpRatThing(100);
  RatThing::PowerUpRatThing(500);
}