void PowerUpRatThing(int nuclear_isotopes) {
  // With thread_local, static is assumed.
  thread_local int rat_things_power = 200; // NOLINT
}

auto main() -> int {
  int *my_int_ptr = new int;      // allocates memory for an int at runtime.
  int *my_int_ptr2 = new int{42}; // initializes dynamic object to 42.
  // to dealocate
  delete my_int_ptr;
  delete my_int_ptr2;

  int *my_int_array_ptr = new int[100];
  delete[] my_int_array_ptr;
}