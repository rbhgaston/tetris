#include <iostream>

#include "./controllers/TetrisController.h"
#include "raylib.h"

double lastUpdateTime = 0;
bool EventTriggered(double interval);

int main() {
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(TILE_SIZE * BOARD_WIDTH + SIDE_PANEL_WIDTH,
               TILE_SIZE * BOARD_HEIGHT, "Tetris");

    SetTargetFPS(60);

    TetrisController controller = TetrisController();

    while (!WindowShouldClose()) {
        controller.handleInput();
        BeginDrawing();

        ClearBackground(BLACK);

        // this would ensure getting the user input although the tetromino is
        // falling down slowly at the beginning
        if (EventTriggered(controller.getSpeed())) controller.nextFrame();
        controller.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}
