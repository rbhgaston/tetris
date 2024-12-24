#include <iostream>
#include "raylib.h"
#include "Tetromino.h"
#include "Position.h"
#include "Tetris.h"





int main() {

    InitWindow(TILE_SIZE * BOARD_WIDTH, TILE_SIZE * BOARD_HEIGHT, "Raylib Test");
    SetTargetFPS(60);

        
    Tetris game = Tetris();

    while (!WindowShouldClose()) {
        BeginDrawing();
        // SETTING UP THE BOARD
        ClearBackground(WHITE);
        for(int i = 0; i < BOARD_WIDTH; i++){
            for(int j = 0; j < BOARD_HEIGHT; j++)
                DrawRectangle(i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE- 1, TILE_SIZE - 1, BLACK);
        }

        if (game.getCurTetromino() == nullptr)
            game.setCurTetromino(new Tetromino(5, 0));
            
        game.getCurTetromino()->move(0, 1);
        game.draw();
        WaitTime(0.2);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}

