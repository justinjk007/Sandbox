#include <iostream>

using namespace std;

int main()
{
    double val                   = 5.6;
    double* double_pointer       = &val;
    double val_array[3]          = {2, 3, 5};
    double* double_array_pointer = &val_array[0];

    // This works, both loops are the same thing
    for (int i = 0; i < 3; ++i) cout << double_array_pointer[i] << "\n";
    for (int i = 0; i < 3; ++i) cout << *(double_array_pointer + i) << "\n";
    // This also works for vectors

    // These are the same, weirdly we are dereferencing a varible pointer like an array
    cout << double_pointer[0] << "\n";
    cout << *(double_pointer + 0) << "\n";
    return 0;
}
