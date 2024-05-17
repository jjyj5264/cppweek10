#include "stack.h"

// Stack : LIFO(Last In First Out)
void Stack::push(int data) {
  insert(0, data); // always insert at the front
}

int Stack::pop() {
  int data = get(0); // saving the data to return
  remove(0);
  
  return data;
}

int Stack::peek() {
  return get(0); // just peeking
}

void Stack::operator+=(int data) {
  push(data);
}
