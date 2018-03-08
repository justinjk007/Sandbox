#include <iostream>
#include "helper.hpp"

using namespace std;

int main()
{
    char entries[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player       = 1;
    int i, choice;
    char mark;
    do {
        displayBoard(&entries[0]);
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;
        mark     = (player == 1) ? 'X' : 'O';
        bool key = true;
        for (int i = 1; i < 10; ++i) {
            char index_char = '0' + i;
            if (choice == i && entries[i] == index_char) {
                entries[i] = mark;
                key        = false;
            }
        }
        if (key) {
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
        cout << "======> Player " << --player << " win ";
    else
        cout << "======> Game is a draw";
    cin.ignore();
    cin.get();
    return 0;
}
