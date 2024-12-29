#include "TetrominoView.h"

TetrominoView::TetrominoView(TetrominoModel *tetromino)
    : tetromino(tetromino) {}

void TetrominoView::draw(int x, int y) const {
    for (const Position &tile : tetromino->getCurrentRotation()) {
        DrawRectangle(x + tile.x * TILE_SIZE, y + tile.y * TILE_SIZE,
                      TILE_SIZE - 1, TILE_SIZE - 1,
                      getColor(tetromino->getId()));
    }
}

void TetrominoView::setTetromino(TetrominoModel *tetromino) {
    this->tetromino = tetromino;
}