#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

class Stack : public LinkedList {
  public:
  void push(int data);
  int pop();
  int peek();
  void operator+=(int data);
};

#endif