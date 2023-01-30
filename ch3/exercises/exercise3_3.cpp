#include <cstdio>

struct Element {
  Element *next{};
  Element *previous{};

  void InsertBefore(Element *new_element) {
    // if (new_element->next != nullptr && new_element->next != this) {
    //   next = new_element->next;
    //   new_element->next = this;
    // }
    if (new_element->next != nullptr) {
      new_element->next = this;
    }
    new_element->previous = previous;
    previous = new_element;
  }
  void InsertAfter(Element *new_element) {
    // if (new_element->previous != nullptr && new_element->previous != this) {
    //   previous = new_element->previous;
    //   new_element->previous = this;
    // }
    if (new_element->previous != nullptr) {
      new_element->previous = this;
    }
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

  trooper1.InsertAfter(&trooper3);

  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;

  trooper3.InsertBefore(&trooper1);

  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 2187;

  trooper2.InsertBefore(&trooper1);
  trooper2.InsertAfter(&trooper3);

  // Begin at trooper1, as long as cursor isn't a nullptr, get the next trooper.
  printf("front to back\n");
  for (Element *cursor = &trooper1; cursor != nullptr; cursor = cursor->next) {
    printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1],
           cursor->operating_number);
  }
  printf("back to front\n");
  for (Element *cursor = &trooper3; cursor != nullptr;
       cursor = cursor->previous) {
    printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1],
           cursor->operating_number);
  }
}