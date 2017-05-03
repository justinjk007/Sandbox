#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
 private:
  struct Node{
    int data;
    Node* next;                   // This creates a Node pointer named next.
  };
  int size;
  Node* head;
  Node* temp;
  Node* current;
 public:
  LinkedList(){                   // This is the constructor, very important.
    this->head = NULL;
    this->current = NULL;
    this->temp = NULL;
    size = 0;
  }
  void insertAtHead(int data);
  void display();
  int getSize();
};
#endif /* LINKEDLIST_H */
