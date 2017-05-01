#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *next;                   // This creates a Node pointer named next
};

class LinkedList{
public:
  Node *head;
  Node *tail;
  void insertAtHead(int data);
  void display();
  // LinkedList(){              // Constructor
  //   this->head = NULL;
  //   this->tail = NULL;
  // };
};

void LinkedList::insertAtHead(int element){
  Node newNode;
  newNode.data = element;
  cout<<"Value of newNode now is "<<newNode.data<<endl;
  newNode.next = head;
  cout<<"Value of next node is "<<newNode.next<<endl;
  head = &newNode;
}

void LinkedList::display(){
  cout << "The contents of the list is\n";
  Node *current = head;
  while(current != tail){
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
  // myList.display();
}
