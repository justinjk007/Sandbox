#include <iostream>

using namespace std;

struct node{
  int data;
  node *next;                   // This creates a node pointer named next
};

class LinkedList{
public:
  node *head;
  node *tail;
  node current;
  void insertAtHead(int data);
  LinkedList(){                 // Constructor
    this->head = NULL;
    this->tail = NULL;
  };
};

void LinkedList::insertAtHead(int data){
  
}

int main(){
  LinkedList myList;
}
