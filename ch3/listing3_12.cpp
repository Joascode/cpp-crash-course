struct Element {
  Element *next{};
  void InsertAfter(Element *new_element) {
    new_element->next = this->next;
    this->next = new_element;
  }
  char prefix[2]; // NOLINT
  short operating_number;
};