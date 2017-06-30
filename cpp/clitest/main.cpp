#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 2) {
    printf("Test 1.0, the mini applet for Blah Blah\n");
    printf("Copyright (c) 2017, JustinJK007.  All rights reserved.\n");
    printf("This program was made available under the unlicense\n");
    printf("See LICENSE file included with the distribution for details and disclaimer.\n");
    printf("Error : No arguments specified (use -help or -h for help)\n");
  }
  else {
    std::cout << "Have " << argc << " arguments:" << std::endl;
    for (int i = 0; i < argc; ++i) {
      std::cout << argv[i] << std::endl;
    }
  }
  return 0;
}
