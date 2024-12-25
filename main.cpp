#include <iostream>
#include "raylib.h"
#include "Position.h"
#include "Tetris.h"


double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


int main() {
    SetTraceLogLevel(LOG_ERROR); 
    InitWindow(TILE_SIZE * BOARD_WIDTH + SIDE_PANEL_WIDTH, TILE_SIZE * BOARD_HEIGHT, "Raylib Test");
    // DrawRectangle(TILE_SIZE * BOARD_WIDTH + SIDE_PANEL_WIDTH/2, TILE_SIZE*BOARD_HEIGHT, 20, TILE_SIZE, RED);
    
    SetTargetFPS(60);

    Tetris game = Tetris();

    while (!WindowShouldClose()) {
        game.handleInput();
        BeginDrawing();
        // SETTING UP THE BOARD
        // ClearBackground(WHITE);
        for(int i = 0; i < BOARD_WIDTH; i++){
            for(int j = 0; j < BOARD_HEIGHT; j++)
                DrawRectangle(i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE- 1, TILE_SIZE - 1, BLACK);
        }
        
        // move down the tetromino every 0.2 seconds but keeping updating the screen and input 
        if (EventTriggered(0.2)){
            game.nextFrame();
        }
        game.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

