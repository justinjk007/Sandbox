class LinkedList{		// This is the constructor, very important.
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
  LinkedList(){        
    this->head = NULL;
    this->current = NULL;
    this->temp = NULL;
    size = 0;
  }
  void insertAtHead(int data);
  void display();
  int getSize();
};
