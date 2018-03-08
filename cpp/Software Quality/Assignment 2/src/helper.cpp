#include "helper.hpp"
#include <iostream>

using namespace std;

int checkIfWinning(char* entries)
{
    if (entries[1] == entries[2] && entries[2] == entries[3])
        return 1;
    else if (entries[4] == entries[5] && entries[5] == entries[6])
        return 1;
    else if (entries[7] == entries[8] && entries[8] == entries[9])
        return 1;
    else if (entries[1] == entries[4] && entries[4] == entries[7])
        return 1;
    else if (entries[2] == entries[5] && entries[5] == entries[8])
        return 1;
    else if (entries[3] == entries[6] && entries[6] == entries[9])
        return 1;
    else if (entries[1] == entries[5] && entries[5] == entries[9])
        return 1;
    else if (entries[3] == entries[5] && entries[5] == entries[7])
        return 1;
    else if (entries[1] != '1' && entries[2] != '2' && entries[3] != '3' && entries[4] != '4' &&
             entries[5] != '5' && entries[6] != '6' && entries[7] != '7' && entries[8] != '8' &&
             entries[9] != '9')
        return 0;
    else
        return -1;
}

void displayBoard(char* entries)
{
    system("cls");  // Clear old board
    cout << "\tTic Tac Toe";
    cout << "Player 1 marks with X \nPlayer 2 marks with O\n\n";
    cout << "     |     |     \n";
    cout << "  " << entries[1] << "  |  " << entries[2] << "  |  " << entries[3] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << entries[4] << "  |  " << entries[5] << "  |  " << entries[6] << "\n";
    cout << "_____|_____|_____"
         << "\n";
    cout << "     |     |     "
         << "\n";
    cout << "  " << entries[7] << "  |  " << entries[8] << "  |  " << entries[9] << "\n";
    cout << "     |     |     \n\n\n";
}
