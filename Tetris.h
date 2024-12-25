#pragma once
#include "raylib.h"
#include "Tetromino.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Board.h"
#include "Color.h"


class Tetris{
    public:
        Tetris(): board(Board()), curTetromino(getRandomTetromino()){
            std::srand(std::time(0));
        }
        Tetromino* getCurTetromino(){
            return curTetromino;
        }
        void setCurTetromino(Tetromino *tetromino){
            curTetromino = tetromino;
        }

        Tetromino* getRandomTetromino(){
            TetrominoType randomTetrominoType = static_cast<TetrominoType>(rand() % 7);
            Tetromino* newTetromino;
            switch(randomTetrominoType) {
                case I: newTetromino = new ITetromino(); break;
                case O: newTetromino = new OTetromino(); break;
                case T: newTetromino = new TTetromino(); break;
                case S: newTetromino = new STetromino(); break;
                case Z: newTetromino = new ZTetromino(); break;
                case J: newTetromino = new JTetromino(); break;
                case L: newTetromino = new LTetromino(); break;
            }
            return newTetromino;
        }

        void draw(){
            board.draw();
            for(Position tile : curTetromino->getCurrentRotation()){
                DrawRectangle((curTetromino->getPosition()->x + tile.x) * TILE_SIZE, (curTetromino->getPosition()->y + tile.y) * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, getColor(curTetromino->getId()));
            }
        }
        
        bool moveCurTetromino(int dx, int dy){
            curTetromino->move(dx, dy);
            if(!board.isInside(curTetromino) || board.isColliding(curTetromino))
                curTetromino->move(-dx, -dy);
                return false;
            return true;
        }

        bool rotateCurTetromino(){
            curTetromino->rotate();
            if(!board.isInside(curTetromino) || board.isColliding(curTetromino))
                curTetromino->unrotate();
                return false;
            return true;
        }

        void handleInput(){
            if (IsKeyPressed(KEY_LEFT)){
                moveCurTetromino(-1, 0);
            }
            if (IsKeyPressed(KEY_RIGHT)){
                moveCurTetromino(1, 0);
            }
            if (IsKeyPressed(KEY_DOWN)){
                moveCurTetromino(0, 1);
            }
            if (IsKeyPressed(KEY_UP)){
                rotateCurTetromino();
            }
        }

        // computes next state of the game
        // how to change code to make it accept random tetromino blocks

        void nextFrame(){
            curTetromino->move(0, 1);
            bool isColliding = board.isColliding(curTetromino);
            if (isColliding){
                curTetromino->move(0, -1);

                board.addTetromino(curTetromino);
                board.clearLines();

                Tetromino* newTetromino = getRandomTetromino();
                // print new tetromino color
                std::cout<<newTetromino->getId()<<std::endl;

                int x;
                do{
                    x = rand() % BOARD_WIDTH;
                }while(!board.isInside(newTetromino->setPosition(x,0)));

                if(board.isColliding(newTetromino)){
                    std::cout<<"Game Over"<<std::endl;
                    exit(0);
                }
                curTetromino = newTetromino;
            }                
        }
    private:
        Board board;
        int nextTetromino = false;
        Tetromino* curTetromino;

};





