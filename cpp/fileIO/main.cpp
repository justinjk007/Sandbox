#include <fstream>

using namespace std;

int main(){
  ofstream myfile;
  // (5.09,5.80), (1.68,4.90), (1.48,1.38), (4.76,0.10), (7.00,2.83)
  myfile.open ("example.csv");
  myfile << "x,y,\n";
  myfile << "5.09,5.80,\n";
  myfile << "1.68,4.90\n";
  myfile << "1.48,1.38\n";
  myfile << "4.76,0.10\n";
  myfile << "7.00,2.83\n";
  myfile.close();
  return 0;
}
