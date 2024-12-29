#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "Tetromino.h"
#include "constants.h"
#include "BoardView.h"
#include "TetrominoView.h"
#include "SidePanelView.h"

class TetrisController{
    public:
        TetrisController();
        Tetromino* getCurTetromino(); 
        void setCurTetromino(Tetromino *tetromino);
        void setNextTetromino(Tetromino *tetromino);
        void setHoldTetromino(Tetromino *tetromino);

        Tetromino* getRandomTetromino();

        void draw();
        
        bool moveCurTetromino(int dx, int dy);

        bool rotateCurTetromino();

        void handleInput();

        // computes next state of the game
        // how to change code to make it accept random tetromino blocks
        void nextFrame();  

        void updateScore(int score); 

        const double getSpeed() const;

        void updateSpeed();
        
        void resetBag();

    private:
        Board board;
        BoardView* boardView;
        Tetromino* curTetromino;
        TetrominoView *curTetrominoView;
        Tetromino* nextTetromino;
        Tetromino* holdTetromino;
        SidePanelView* sidePanelView;
        bool holdUsed = false;
        double lockDelay = 0.5f;
        double collisionTime = 0;
        int playerAction = false;

        int score = 0;
        int level = 0;
        int lines = 0;
        double speed = 1.0f;

        std::vector<int> bag;
};





