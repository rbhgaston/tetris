#pragma once
#include "raylib.h"
#include "Tetromino.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Board.h"

const int SIDE_PANEL_WIDTH = 150;

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

        void updateScore(int score); 

    private:
        Board board;
        Tetromino* curTetromino;
        Tetromino* nextTetromino;
        Tetromino* holdTetromino;
        bool holdUsed = false;
        double lockDelay = 0.5;
        double collisionTime = 0;
        int playerAction = false;

        int score = 0;
        int level = 0;
        int linesClearedSinceLevelUp = 0;
        
};





