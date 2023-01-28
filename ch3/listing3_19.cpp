/*
  This is for example purposes only!
*/

// Example of auto deducing the correct type based on initializer.
// VS Code apparently also helps by showing the used type.
// PS. Auto formatting messing up the comments behind the types.
auto the_answer{42};           // int
auto foot{12L};                // long
auto rootbeer{5.0F};           // float
auto cheeseburger{10.0};       // double
auto politifact_claims{false}; // bool
auto cheese{"string"};         // const char * (char[7])

struct Dwarf {};

Dwarf dwarves[13]; // NOLINT

struct Contract {
  // Useless method for example purposes.
  void Add(const Dwarf &);
};

void FormCompany(Contract &contract) {
  // Use of auto inside a range loop.
  // The use of auto here helps in refactoring. Should the type of dwarves
  // change, then auto should deduce the correct type afterwards.
  for (const auto &dwarf : dwarves) {
    contract.Add(dwarf);
  }
}