#pragma once
#include <vector>
#include "Position.h"

//TODO implement as I type for testing
class Tetromino{
    public:
        Tetromino();
        Tetromino(int x, int y);
        void rotate();
        void move(int dx, int dy);
        Position getPosition();
        std::vector<Position> getCurrentRotation();

    protected:
        std::vector<Position> rotations [4]= {
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}}
        };
        int currentRotation;
        int offsetx = 0 , offsety = 0;

};