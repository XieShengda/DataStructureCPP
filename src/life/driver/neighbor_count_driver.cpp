//
// Created by Sender on 5/27/21.
//

#include "../lib/life.cpp"

int main() {
    Life configuration{};
    configuration.initialize();
    for (int row = 1; row <= maxrow; ++row) {
        for (int col = 1; col <= maxcol; ++col) {
            cout << configuration.neighbor_count(row, col) << " ";
        }
        cout << endl;
    }
}