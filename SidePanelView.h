#pragma once
#include "raylib.h"
#include "constants.h"
#include "TetrominoView.h"
#include <string>

class SidePanelView{
    public:
        void draw(int score, int level, int lines, Tetromino *holdTetromino, Tetromino *nextTetromino);
    private:
        TetrominoView *nextTetrominoView = new TetrominoView(nullptr);
        TetrominoView *holdTetrominoView = new TetrominoView(nullptr);
};

