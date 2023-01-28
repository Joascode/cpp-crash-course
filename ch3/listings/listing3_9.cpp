struct Element {
  Element *next{};
  void InsertAfter(Element *new_element) {
    new_element->next = next;
    next = new_element;
  }
  char prefix[2]; // NOLINT
  short operating_number;
};