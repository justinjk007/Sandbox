#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <chrono>

using namespace std;

int main( )
{

    auto start = chrono::high_resolution_clock::now();  // Start clock

    list<int> data( 100000 );
    generate( data.begin(), data.end(), rand ); // Populate with random numbers
    data.sort();

    auto finish                      = chrono::high_resolution_clock::now();  // Stop clock
    chrono::duration<double> elapsed = finish - start;                        // Mesure time elapsed
    cout << "\n------ Elapsed time: " << elapsed.count() << " s ------\n";

    return 0;
}
