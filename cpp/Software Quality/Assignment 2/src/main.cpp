#include <iostream>
#include "helper.hpp"

using namespace std;

int main()
{
    char entries[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player       = 1, i, choice;
    char mark;
    do {
        displayBoard(&entries[0]);
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && entries[1] == '1')
            entries[1] = mark;
        else if (choice == 2 && entries[2] == '2')
            entries[2] = mark;
        else if (choice == 3 && entries[3] == '3')
            entries[3] = mark;
        else if (choice == 4 && entries[4] == '4')
            entries[4] = mark;
        else if (choice == 5 && entries[5] == '5')
            entries[5] = mark;
        else if (choice == 6 && entries[6] == '6')
            entries[6] = mark;
        else if (choice == 7 && entries[7] == '7')
            entries[7] = mark;
        else if (choice == 8 && entries[8] == '8')
            entries[8] = mark;
        else if (choice == 9 && entries[9] == '9')
            entries[9] = mark;
        else {
            cout << "Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        i = checkIfWinning(&entries[0]);
        player++;
    } while (i == -1);
    displayBoard(&entries[0]);
    if (i == 1)
        cout << "==>\aPlayer " << --player << " win ";
    else
        cout << "==>\aGame draw";
    cin.ignore();
    cin.get();
    return 0;
}
