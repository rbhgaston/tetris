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
        int board[BOARD_WIDTH][BOARD_HEIGHT];
        Board(){
            for (int i = 0; i < BOARD_WIDTH; i++){
                for (int j = 0; j < BOARD_HEIGHT; j++){
                    board[i][j] = -1;
                }
            }

        }


        void addTetromino(Tetromino *tetromino, Position *pos){
            for (Position &tile : tetromino->getCurrentRotation()){
                    board[pos->x + tile.x][(pos->y + tile.y)] = tetromino->id;
            }
        }
        
        bool isInside(Tetromino *tetromino){
            Position *pos = tetromino->getPosition();
            for (Position &tile : tetromino->getCurrentRotation()){
                if (pos->x + tile.x < 0 || pos->x + tile.x >= BOARD_WIDTH || pos->y + tile.y >= BOARD_HEIGHT){
                    return false;
                }
            }
            return true;
        }

        bool isColliding(Tetromino *tetromino){
            Position *pos = tetromino->getPosition();
            for (Position &tile : tetromino->getCurrentRotation()){
                if (board[pos->x + tile.x][pos->y + tile.y] != -1 || pos->y + tile.y >= BOARD_HEIGHT){
                    return true;
                }
            }
            return false;
        }

        void clearLines(){
            for (int j = 0; j < BOARD_HEIGHT; j++){
                bool full = true;
                for (int i = 0; i < BOARD_WIDTH; i++){
                    if (board[i][j] == -1){
                        full = false;
                        break;
                    }
                }
                if (full){
                    for (int k = j; k > 0; k--){
                        for (int i = 0; i < BOARD_WIDTH; i++){
                            board[i][k] = board[i][k - 1];
                        }
                    }
                }
            }
        }

        void draw(){
            for (int i = 0; i < BOARD_WIDTH; i++){
                for (int j = 0; j < BOARD_HEIGHT; j++){
                    if (board[i][j] != -1){
                        DrawRectangle(i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, getColor((TetrominoType)board[i][j]));
                    }
                }
            }
        }

        // for debugging
        void display(){
            for (int j = 0; j < BOARD_HEIGHT; j++){
                for (int i = 0; i < BOARD_WIDTH; i++){
                    std::cout<<board[i][j];
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
        }

};