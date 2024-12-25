#pragma once
#include "raylib.h"
#include "Tetromino.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Board.h"


class Tetris{
    public:
        Tetris();
        Tetromino* getCurTetromino(); 
        void setCurTetromino(Tetromino *tetromino);

        Tetromino* getRandomTetromino();

        void draw();
        
        bool moveCurTetromino(int dx, int dy);

        bool rotateCurTetromino();

        void handleInput();

        // computes next state of the game
        // how to change code to make it accept random tetromino blocks

        void nextFrame();               
    private:
        Board board;
        int nextTetromino = false;
        Tetromino* curTetromino;

};





