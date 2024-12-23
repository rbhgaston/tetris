#include <iostream>
#include "raylib.h"
#include "Tetromino.h"

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

struct Position{
    int x;
    int y;
};

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
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    if (tetromino->getCurrentRotation()[i][j] == 1){
                        board[pos->x + j][pos->y + i] = 1;
                    }
                }
            }
        }

        void draw(){
            for (int i = 0; i < BOARD_HEIGHT; i++){
                for (int j = 0; j < BOARD_WIDTH; j++){
                    if (board[i][j] == 1){
                        DrawRectangle(i * 20, j * 20, 20, 20, WHITE);
                    }
                }
            }
        }
};

class Tetris{
    public:
        Tetris();

    private:
        int board[BOARD_HEIGHT][BOARD_WIDTH];
        Position currentPos;

};


int main() {

    InitWindow(200, 400, "Raylib Test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        Position pos1 = {0, 0}, pos2 = {4, 0}, pos3 = {0, 1};
        Tetromino tetromino, tetromino2, tetromino3;
        Board board;
        board.addTetrimino(&tetromino, &pos1);
        board.addTetrimino(&tetromino2, &pos2);
        board.draw();
        WaitTime(0.2);
        tetromino3.rotate();

        board.addTetrimino(&tetromino3, &pos3);
        board.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

