#include "rang.hpp"
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace rang;

int main(int argc, char *argv[]) {
  cout << fg::green << "Hello\n" << style::reset;
  cout << fg::red << "Hello\n" << style::reset;
  cout << fg::cyan << "Hello\n" << style::reset;
  cout << fg::gray << "Hello\n" << style::reset;
  cout << fg::magenta << "Hello\n" << style::reset;
  cout << fg::blue << "Hello\n" << style::reset;
  cout << fg::yellow << "Hello\n" << style::reset;
  cout << fg::black <<bg::red<< "Hello\n" << style::reset;
  return 0;
}

void timeout(int time_in_seconds) {
  /**
   * Dumb method for timeout with timer on screen. This methods
   * accepts time in seconds and wait for it.
   */
  for (int i = 0; i < time_in_seconds; ++i) {
    cout << "[ " << i + 1 << " ]"
         << "\r";
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}
