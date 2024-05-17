#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() {
  head_ = nullptr;
  size_ = 0;
}

LinkedList::~LinkedList() {
  Node *current = head_; // starting from the head

  // int _count = 0; // leak checking

  while (current != nullptr) {   // until the end of the linked list is reached
    Node *next = current->next_; // 1. store the next node of the current node.
    delete current;              // 2. free the memory of the current node.
    current = next;              // 3. move to the next node.
    // _count++;
  }
  // std::cout << "~LinkedList(): " + std::to_string(_count) << std::endl;
}

void LinkedList::print() {
  Node *current = head_; // starting from the head

  while (current != nullptr) {
    std::cout << current->value_ << " ";
    current = current->next_; // move to the next node
  }

  std::cout << std::endl;
}

void LinkedList::insert(int index, int value) {
  Node *newNode = new Node(value);

  if (index == 0) {         // if the index is 0, insert the new node at the beginning
    newNode->next_ = head_; // set the next pointer of the new node to the current head
    head_ = newNode;        // update the head to new node
  } else {                  // if the index is not 0
    Node *current = head_;  // 0th index, to find the node before the specified index

    for (int i = 0; i < index - 1; i++) { // until before the specified index
      current = current->next_;           // at the end, current points to the node 'before' the specified index
    }

    newNode->next_ = current->next_; // put the new node between the current node and the next node
    current->next_ = newNode;        // update the next pointer of the current node to the new node
  }

  size_++;
}

int LinkedList::get(int index) {
  Node *current = head_; // starting from the head

  for (int i = 0; i < index; i++) { // until the specified index
    current = current->next_;       // at the end, current points to the node at the specified index
  }

  return current->value_;
}

void LinkedList::remove(int index) {
  Node *temp = nullptr; // temp is a pointer to store the node to be removed

  if (index == 0) {       // if the index is 0,
    temp = head_;         // set the temp pointer to the current head
    head_ = head_->next_; // update the head to point to the next node
  } else {
    Node *current = head_; // starting from the head

    for (int i = 0; i < index - 1; i++) { // until before the specified index
      current = current->next_;           // at the end, current points to the node 'before' the specified index
    }

    temp = current->next_;        // ex) 1, 2, 3, 4 -> remove 3 -> 1, 2, 4, temp has to be 3, current has to be 2.
    current->next_ = temp->next_; // update
  }

  delete temp; // finally
  size_--;
}