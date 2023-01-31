// Example of automatic storage duration
// Both nuclear_isotopes and waste_heat are automatic variables
// due to function scope.
void PowerUpRatThing(int nuclear_isotopes) { // NOLINT
  const int waste_heat = 0;
}