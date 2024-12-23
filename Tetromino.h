#pragma once
#include <vector>

//TODO implement as I type for testing
class Tetromino{
    public:
        Tetromino();
        void rotate();
        int (*getCurrentRotation())[4];
    protected:
         int rotations [4][4][4]= {{{0, 0, 0, 0},
                 {1, 1, 1, 1},
                 {0, 0, 0, 0},
                 {0, 0, 0, 0}},
                 {{0, 0, 1, 0},
                 {0, 0, 1, 0},
                 {0, 0, 1, 0},
                 {0, 0, 1, 0}},
                 {{0, 0, 0, 0},
                 {0, 0, 0, 0},
                 {1, 1, 1, 1},
                 {0, 0, 0, 0}},
                 {{0, 1, 0, 0},
                 {0, 1, 0, 0},
                 {0, 1, 0, 0},
                 {0, 1, 0, 0}}};
        int currentRotation;

};