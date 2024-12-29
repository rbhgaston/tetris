#pragma once
#include "Tetromino.h"
#include <iostream>
#include "Color.h"
#include "constants.h"

class Board{
    public:
        Board();

        void lockTetromino(Tetromino *tetromino);
        
        bool isInside(Tetromino *tetromino);

        bool isColliding(Tetromino *tetromino);

        int clearLines();

        void draw();

        int getCell(int x, int y);

        // for debugging
        void display();

    private:
        int board[BOARD_WIDTH][BOARD_HEIGHT];
};