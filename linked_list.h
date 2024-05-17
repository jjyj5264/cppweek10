#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

class LinkedList {
  public:
  LinkedList();
  ~LinkedList();
  void print();

  protected:
  void insert(int index, int value);
  int get(int index);
  void remove(int index);
  Node *head_;
  int size_;
};

#endif