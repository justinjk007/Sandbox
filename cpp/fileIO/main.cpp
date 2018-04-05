#include <fstream>
#include <iostream>
#include <string>

int main()
{
    // File for input
    std::ifstream file;
    file.open("FooBar.csv", std::ios::in);
    if (!file) {
        std::cerr << "Unable to open csv file";
        exit(1);
    }

    double sum1[3] = {0.0};
    double sum2[3] = {0.0};
    int scenario   = 0;
    std::string cell;

    while (getline(file, cell, ',')) {
        scenario = std::stoi(cell);
        for (int skip = 0; skip < 7; skip++) {
            getline(file, cell, ',');  // Skip next 7 columns
        }
        getline(file, cell, ',');
        sum1[scenario - 1] += stod(cell);
        getline(file, cell, ',');  // Skip 1 more column
        getline(file, cell, '\n');
        sum2[scenario - 1] += stod(cell);
    }
    std::cout << 1 << "," << sum1[0] / 125.0 << "," << sum2[0] / 125.0 << "\n";
    std::cout << 2 << "," << sum1[1] / 125.0 << "," << sum2[1] / 125.0 << "\n";
    std::cout << 3 << "," << sum1[2] / 125.0 << "," << sum2[2] / 125.0 << "\n";

    file.close();
}
