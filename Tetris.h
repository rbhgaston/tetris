#pragma once
#include "raylib.h"
#include "Tetromino.h"

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int TILE_SIZE = 20;

class Board{
    public:
        int board[BOARD_HEIGHT][BOARD_WIDTH];
        Board(){
            for (int i = 0; i < BOARD_HEIGHT; i++){
                for (int j = 0; j < BOARD_WIDTH; j++){
                    board[i][j] = 0;
                }
            }

        }
        void addTetrimino(Tetromino *tetromino, Position *pos){
            for (Position tile : tetromino->getCurrentRotation()){
                    board[pos->x + tile.y][pos->y + tile.x] = 1;
            }
        }

        void draw(){
            for (int i = 0; i < BOARD_HEIGHT; i++){
                for (int j = 0; j < BOARD_WIDTH; j++){
                    if (board[i][j] == 1){
                        DrawRectangle(i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, WHITE);
                    }
                }
            }
        }
};

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
                DrawRectangle((curTetromino.getPosition().x + tile.x) * TILE_SIZE, (curTetromino.getPosition().y + tile.y) * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, WHITE);
            }
        }

    private:
        Board board;
        Tetromino curTetromino;

};




