#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class LinkedList{		
 private:
  struct Node{
    int data;
    Node* next;                 // This creates a Node pointer named next.
  };
  int size;
  Node* head;
  Node* temp;
  Node* current;
 public:
  LinkedList(){                 // This is the constructor, very important.
    this->head = NULL;
    this->current = NULL;
    this->temp = NULL;
    size = 0;
  }
    void insertAtHead(int data);
    void display();
    int getSize();
  };


void LinkedList::insertAtHead(int element){
  Node* newNode = new Node;
  newNode->data = element;
  size+=1;
  temp = head;
  head = newNode;
  newNode->next = temp;
}

void LinkedList::display(){
  cout << "The contents of the list is\n";
  current = head;
  for (int i = 1; i <= size; ++i) {
    cout << current->data<<"\n";
    current = current->next;
  }
}
  
int LinkedList::getSize(){
  return size;
}
#endif /* LINKEDLIST_H */
