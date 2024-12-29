#pragma once

#include "raylib.h"
#include "Tetromino.h"
#include "constants.h"
#include "Color.h"

class TetrominoView{
    public:
        TetrominoView(Tetromino *tetromino);
        void draw(int x, int y);
        void setTetromino(Tetromino *tetromino);
    private:
        Tetromino *tetromino;
};

