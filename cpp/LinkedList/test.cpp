#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){
  LinkedList myList;
  cout << "The size of the list is "<<myList.getSize()<<endl;
  myList.insertAtHead(1);
  myList.insertAtHead(9);
  myList.insertAtHead(3);
  cout << "After adding 3 elements\n";
  cout << "The size of the list is "<<myList.getSize()<<endl;
  myList.display();
  cout << "\nThe size of the list is "<<myList.getSize()<<endl;
  myList.insertAfterTail(77);
  myList.insertAfterTail(977);
  myList.insertAfterTail(877);
  cout << "After adding 3 more elements\n";
  myList.display();
  cout << "\nThe size of the list is "<<myList.getSize()<<endl;
  myList.insertAtHead(34);
  myList.insertAtHead(3);
  myList.insertAtHead(977);
  cout << "After adding 3 more elements\n";
  myList.display();
  cout << "\nThe size of the list is "<<myList.getSize()<<endl;
}
