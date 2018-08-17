#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

List::List() {
  count = 0;
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head; 
  }

List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List& source) {
  if (this == &source) {
    return *this;
  }

  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

List::List(const List& source) {
  head=new ListNode;
  tail=new ListNode;
  head->next = tail;
  tail->previous=head;
  count=0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

bool List:: isEmpty() const {
  if (count == 0) {
    return true;
  }

  else {
    return false;
  }
}

void List:: makeEmpty() {
  ListNode* a = head->next->next;
  while (a != NULL) {
    delete a->previous;
    a = a->next;
    delete a->previous;
  }
}

ListItr List:: first() {
  ListItr newList(head->next);
  return newList;
}

ListItr List:: last() {
  ListItr newList(tail->previous);
  return newList;
}

void List::insertAfter (int x, ListItr position) {
  if (!position.isPastEnd()) {
    ListNode* node = new ListNode;
    node -> value = x;
    node->previous = position.current;
    node->next = position.current->next;
    position.current->next->previous = node;
    position.current->next = node;
    count++;
  }
}

void List::insertBefore (int x, ListItr position) {
  if (!position.isPastBeginning()) {
    ListNode* node = new ListNode;
    node->value = x;
    node->next = position.current;
    node->previous = position.current->previous;
    position.current->previous->next = node;
    position.current->previous = node;
    count++;
  }
}

void List::insertAtTail (int x) {
  ListNode * node = new ListNode();
  ListNode * prev = tail->previous;
  node->next = tail;
  node->previous = prev;
  prev->next = node;
  tail->previous = node;
  node->value = x;
  count++;
}

void List::remove (int x) {
}


ListItr List::find(int x) {
  ListItr *a = new ListItr(first());
  // while (!check->isPastEnd()) {
  return *a;
}

int List::size() const {
  return count;
}
    
void printList(List& theList, bool forward) {
}
  





  

