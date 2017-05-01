#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *next;                   // This creates a Node pointer named next
};

class LinkedList{
public:
  Node *head;
  void insertAtHead(int data);
  void display();
};

void LinkedList::insertAtHead(int element){
  Node newNode;
  newNode.data = element;
  newNode.next = head;
  head = &newNode;
}

void LinkedList::display(){
  cout << "The contents of the list is\n";
  Node *current = head;
  while(current->next != NULL){
    cout << current->data<<endl;
    current = current->next;
  }
}

int main(){
  LinkedList myList;
  myList.insertAtHead(1);
  myList.insertAtHead(9);
  myList.insertAtHead(34);
  myList.insertAtHead(3);
  myList.display();
}
