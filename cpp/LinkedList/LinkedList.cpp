#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::insertAtHead(int element){ // O(1)
  Node* newNode = new Node;
  newNode->data = element;
  size+=1;
  temp = head;
  head = newNode;
  newNode->next = temp;
}

void LinkedList::insertAfterTail(int element){ // O(n)
  Node* newNode = new Node;
  current = head;  
  cout<<"Current . head "<<current->data<<endl;
  for (int i = 0; i < size; ++i) {
    current = current->next;
  }
  current->next=newNode;
  newNode->data = element;
  newNode->next = NULL;
  size+=1;
}

void LinkedList::display(){     // O(n)
  cout << "The contents of the list is\n";
  current = head;
  for (int i = 0; i < size; ++i) {
    cout << current->data<<"\n";
    current = current->next;
  }
}

int LinkedList::getSize(){      // O(1)
  return size;
}
