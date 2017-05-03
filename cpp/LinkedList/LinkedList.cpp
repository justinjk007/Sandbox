#include <iostream>
#include "LinkedList.h"
using namespace std;

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
