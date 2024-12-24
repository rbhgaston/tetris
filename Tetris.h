#pragma once
#include "raylib.h"
#include "Tetromino.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Board.h"



class Tetris{
    public:
        Tetris(){
            board = Board();
        }
        Tetromino* getCurTetromino(){
            return &curTetromino;
        }
        void setCurTetromino(Tetromino *tetromino){
            curTetromino = *tetromino;
        }

        void draw(){
            board.draw();
            for(Position tile : curTetromino.getCurrentRotation()){
                DrawRectangle((curTetromino.getPosition()->x + tile.x) * TILE_SIZE, (curTetromino.getPosition()->y + tile.y) * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, WHITE);
            }
            board.display();
        }
        
        bool moveCurTetromino(int dx, int dy){
            curTetromino.move(dx, dy);
            if(!board.isInside(&curTetromino) || board.isColliding(&curTetromino))
                curTetromino.move(-dx, -dy);
                return false;
            return true;
        }

        bool rotateCurTetromino(){
            curTetromino.rotate();
            if(!board.isInside(&curTetromino) || board.isColliding(&curTetromino))
                curTetromino.unrotate();
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
                curTetromino.rotate();
            }
        }

        // computes next state of the game
        void nextFrame(){
            curTetromino.move(0, 1);
            bool isColliding = board.isColliding(&curTetromino);
            if (isColliding){
                curTetromino.move(0, -1);
                // debug
                std::cout<<"Colliding"<<std::endl;
                board.addTetromino(&curTetromino, curTetromino.getPosition());
                srand(time(0));
                int x;
                
                Tetromino tetromino = Tetromino();
                do{
                    x = rand() % BOARD_WIDTH;
                }while(!board.isInside(tetromino.setPosition(x,0)));
                
                //debug
                std::cout<<"x: "<<x<<std::endl;
                curTetromino = Tetromino(x, 0);
            }
        
                
                // srand(time(0));
                // int x = rand() % BOARD_WIDTH;
                // curTetromino = Tetromino(x, 0);


            
                
        }
    private:
        Board board;
        int nextTetromino = false;
        Tetromino curTetromino;

};




