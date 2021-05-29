//
// Created by Sender on 5/27/21.
//

#ifndef DATASTRUCTURECPP_LIFE_H
#define DATASTRUCTURECPP_LIFE_H

struct Point {
    int x;
    int y;
};

const int maxrow = 20, maxcol = 60;
const Point dir[] = {{-1, -1},
                     {-1, 0},
                     {-1, 1},
                     {0,  -1},
                     {0,  1},
                     {1,  -1},
                     {1,  0},
                     {1,  1}};

class Life {
public:

    void initialize();

    void print() const;

    void update();

    int neighbor_count(int row, int col) const;

private:

    int grid[maxrow + 2][maxcol + 2];

};


#endif //DATASTRUCTURECPP_LIFE_H
