#pragma once
#include <vector>
#include "Position.h"

//TODO implement as I type for testing
class Tetromino{
    public:
        Tetromino();
        Tetromino(int x, int y);
        void rotate();
        void unrotate();
        void move(int dx, int dy);
        Position* getPosition();
        Tetromino* setPosition(int x, int y){
            offsetx = x;
            offsety = y;
            return this;
        }
        std::vector<Position> getCurrentRotation();
        // copy constructor
        Tetromino(const Tetromino &tetromino){
            offsetx = tetromino.offsetx;
            offsety = tetromino.offsety;
            currentRotation = tetromino.currentRotation;
        }

    protected:
        std::vector<Position> rotations [4]= {
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
            {{2, 0}, {2, 1}, {2, 2}, {2, 3}},
            {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
            {{1, 0}, {1, 1}, {1, 2}, {1, 3}}
        };
        int currentRotation = 0;
        int offsetx = 0 , offsety = 0;

};