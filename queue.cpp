#include "queue.h"

// Queue : FIFO(First In First Out)
void Queue::push(int data) {
  insert(size_, data); // always insert at the end
}

int Queue::pop() {
  int data = get(0); // saving the data to return
  remove(0);

  return data;
} 

int Queue::peek() {
  return get(0); // just peeking
}

void Queue::operator+=(int data) {
  push(data);
}