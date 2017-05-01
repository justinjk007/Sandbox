#include <iostream>

using namespace std;

class Rectangle
{
public:
  double Length;
  double Width;
  void setSides(double len, double wid){
    this->Length = len; 
    this->Width = wid; 
  };
  double getArea();
};

double Rectangle::getArea(){
  double Area = this->Length * this->Width;
  return Area;
}

int main(){
  Rectangle object1;
  object1.setSides(2,10);
  cout<<"The area of the rectangle is "<<object1.getArea()<<"\n";
}
