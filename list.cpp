#include "list.h"

void List::insert(int index, int value) {
  LinkedList::insert(index, value);
}

int List::get(int index) { // Added 'List::' prefix
  return LinkedList::get(index);
}

void List::remove(int index) { // Added 'List::' prefix
  LinkedList::remove(index);
}