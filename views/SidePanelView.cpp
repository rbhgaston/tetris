#include "SidePanelView.h"

SidePanelView::SidePanelView() {
    nextTetrominoView = new TetrominoView(nullptr);
    holdTetrominoView = new TetrominoView(nullptr);
}

void SidePanelView::draw(int score, int level, int lines,
                         TetrominoModel *holdTetromino,
                         TetrominoModel *nextTetromino) const {
    DrawRectangle(TILE_SIZE * BOARD_WIDTH, 0, SIDE_PANEL_WIDTH,
                  TILE_SIZE * BOARD_HEIGHT, GRAY);
    // score
    DrawText("Score", TILE_SIZE * BOARD_WIDTH + 10, 10, 20, BLACK);
    DrawText(std::to_string(score).c_str(), TILE_SIZE * BOARD_WIDTH + 10, 35,
             20, BLACK);
    // level
    DrawText("Level", TILE_SIZE * BOARD_WIDTH + 10, 60, 20, BLACK);
    DrawText(std::to_string(level).c_str(), TILE_SIZE * BOARD_WIDTH + 10, 80,
             20, BLACK);
    // lines cleared
    DrawText("Lines", TILE_SIZE * BOARD_WIDTH + 10, 110, 20, BLACK);
    DrawText(std::to_string(lines).c_str(), TILE_SIZE * BOARD_WIDTH + 10, 130,
             20, BLACK);

    // next tetromino
    nextTetrominoView->setTetromino(nextTetromino);
    DrawText("Next", TILE_SIZE * BOARD_WIDTH + 10, 160, 20, BLACK);
    nextTetrominoView->draw(TILE_SIZE * BOARD_WIDTH + 10, 180);

    // hold tetromino
    holdTetrominoView->setTetromino(holdTetromino);
    DrawText("Hold", TILE_SIZE * BOARD_WIDTH + 10, 240, 20, BLACK);
    if (holdTetromino != nullptr) {
        holdTetrominoView->draw(TILE_SIZE * BOARD_WIDTH + 10, 260);
    }
}