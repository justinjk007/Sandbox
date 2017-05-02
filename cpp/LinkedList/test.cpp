#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){
  LinkedList myList;
  cout << "The size of the list is "<<myList.getSize()<<endl;
  myList.insertAtHead(1);
  myList.insertAtHead(9);
  myList.insertAtHead(34);
  myList.insertAtHead(3);
  cout << "After adding 4 elements\n";
  cout << "The size of the list is "<<myList.getSize()<<endl;
  myList.display();
  cout << "The size of the list is "<<myList.getSize()<<endl;
  myList.insertAtHead(77);
  myList.insertAtHead(977);
  myList.insertAtHead(877);
  cout << "After adding 3 more elements\n";
  myList.display();
  cout << "The size of the list is "<<myList.getSize()<<endl;
}
