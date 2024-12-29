#include "BoardView.h"

BoardView::BoardView(BoardModel* board) : board(board) {}

void BoardView::draw() const {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            if (board->getCell(new Position{i, j}) != -1) {
                DrawRectangle(
                    i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1,
                    getColor(
                        (TetrominoType)board->getCell(new Position{i, j})));
            }
        }
    }
}