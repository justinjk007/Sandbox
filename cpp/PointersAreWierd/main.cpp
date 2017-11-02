#include <iostream>

using namespace std;

int main()
{
    double val                   = 5.6;
    double* double_pointer       = &val;
    double val_array[3]          = {2, 3, 5};
    double* double_array_pointer = &val_array[0];
    for (int i = 0; i < 3; ++i) cout << double_array_pointer[i] << "\n";
    // This also works for vectors
    return 0;
}
