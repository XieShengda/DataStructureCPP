//
// Created by Sender on 5/27/21.
//

#include "life.h"
#include <iostream>

using namespace std;

void Life::initialize() {
    int row, col;
    for (row = 0; row < maxrow + 2; ++row) {
        for (col = 0; col < maxcol + 2; ++col) {
            grid[row][col] = 0;
        }
    }
    cout << "List the coordinates for living cells." << endl;
    cout << "Terminate the list with the special pair -1 -1" << endl;
    cin >> row >> col;
    while (row != -1 || col != -1) {
        if (row > 0 && row < maxrow + 1) {
            if (col > 0 && col < maxcol + 1) {
                grid[row][col] = 1;
            } else {
                cout << "Column" << col << "is out of range." << endl;
            }
        } else {
            cout << "Row" << row << "is out of range." << endl;
        }
        cin >> row >> col;
    }
}

void Life::print() const {
    cout << "\nThe current Life configuration is:" << endl;
    for (int row = 1; row < maxrow + 1; ++row) {
        for (int col = 1; col < maxcol + 1; ++col) {
            cout << (grid[row][col] == 1 ? "*" : " ");
        }
        cout << endl;
    }
    cout << endl;
}

void Life::update() {
    int row, col;
    int new_grid[maxrow + 2][maxcol + 2];
    for (row = 1; row <= maxrow; ++row) {
        for (col = 1; col <= maxcol; ++col) {
            switch (neighbor_count(row, col)) {
                case 2:
                    new_grid[row][col] = grid[row][col]; // Status stays the same.
                    break;
                case 3:
                    new_grid[row][col] = 1; // Cell is now alive.
                    break;
                default:
                    new_grid[row][col] = 0; // Cell is now dead;
            }
        }
    }

    for (row = 1; row < maxrow + 1; ++row) {
        for (col = 1; col < maxcol + 1; ++col) {
            grid[row][col] = new_grid[row][col];
        }
    }
}

int Life::neighbor_count(int row, int col) const {
    int count = 0;
    for (const auto &point : dir) {
        count += this->grid[row + point.x][col + point.y];
    }
    return count;
}

/**
 * Pre: None
 * Post: Instructions for using the Life program have been printed.
 */
void instructions() {
    cout << "Welcome to Sender's game of Life." << endl;
    cout << "This game uses a grid of size " << maxrow << " by " << maxcol << " in which" << endl;
    cout << "each cell can either be occupied by an organism of not." << endl;
    cout << "The occupied cells change from generation to generation" << endl;
    cout << "according to the number of neighboring cells which are alive." << endl;
}