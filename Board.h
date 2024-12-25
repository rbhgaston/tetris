#pragma once
#include "raylib.h"
#include "Tetromino.h"
#include <iostream>
#include "Color.h"

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int TILE_SIZE = 20;

class Board{
    public:
        Board();

        void addTetromino(Tetromino *tetromino);
        
        bool isInside(Tetromino *tetromino);

        bool isColliding(Tetromino *tetromino);

        int clearLines();

        void draw();

        // for debugging
        void display();

    private:
        int board[BOARD_WIDTH][BOARD_HEIGHT];
};