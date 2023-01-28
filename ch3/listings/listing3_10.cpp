#include <cstdio>

struct Element {
  Element *next{};
  void InsertAfter(Element *new_element) {
    new_element->next = next;
    next = new_element;
  }
  char prefix[2]; // NOLINT
  short operating_number;
};

auto main() -> int {
  Element trooper1;
  Element trooper2;
  Element trooper3;

  trooper1.prefix[0] = 'T';
  trooper1.prefix[1] = 'K';
  trooper1.operating_number = 421;
  trooper1.InsertAfter(&trooper2);
  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 2187;
  trooper2.InsertAfter(&trooper3);
  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;

  // Begin at trooper1, as long as cursor isn't a nullptr, get the next trooper.
  for (Element *cursor = &trooper1; cursor != nullptr; cursor = cursor->next) {
    printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1],
           cursor->operating_number);
  }
}