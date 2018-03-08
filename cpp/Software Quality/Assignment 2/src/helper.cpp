#include "helper.hpp"
#include <iostream>

using namespace std;

int checkIfWinning(char* pos)
{
    bool is_draw = true;
    for (int i = 1; i < 10; i += 3) {
        if (pos[i] == pos[i + 1] && pos[i + 1] == pos[i + 2]) return 1;
    }
    if (pos[1] == pos[4] && pos[4] == pos[7])
        return 1;
    else if (pos[2] == pos[5] && pos[5] == pos[8])
        return 1;
    else if (pos[3] == pos[6] && pos[6] == pos[9])
        return 1;
    else if (pos[1] == pos[5] && pos[5] == pos[9])
        return 1;
    else if (pos[3] == pos[5] && pos[5] == pos[7])
        return 1;
    // Check if the game is a draw
    for (int i = 1; i < 10; ++i) {
        char index_char = '0' + i;
        if (pos[i] == index_char) {
            is_draw = is_draw && true;
        } else
            is_draw = is_draw && false;
    }
    if (is_draw)
        return 0;
    else
        return -1;
}

void displayBoard(char* entries)
{
#ifdef __unix__
    system("clear");  // Clear old board
#elif defined(_WIN32) || defined(WIN32)
    system("cls");  // Clear old board
#endif
    // Draw fancy ASCII board
    cout << "Tic Tac Toe\n";
    cout << "=================\n\n";
    cout << "Player 1 marks with X \nPlayer 2 marks with O\n\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << entries[1] << "  |  " << entries[2] << "  |  " << entries[3] << "\n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << entries[4] << "  |  " << entries[5] << "  |  " << entries[6] << "\n";
    cout << "\t_____|_____|_____"
         << "\n";
    cout << "\t     |     |     "
         << "\t\n";
    cout << "\t  " << entries[7] << "  |  " << entries[8] << "  |  " << entries[9] << "\n";
    cout << "\t     |     |     \n\n\n";
}
