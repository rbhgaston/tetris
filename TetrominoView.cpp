#include "TetrominoView.h"

TetrominoView::TetrominoView(Tetromino *tetromino): tetromino(tetromino){}

void TetrominoView::draw(int x, int y){
    for (Position &tile : tetromino->getCurrentRotation()){
        // DrawRectangle((tetromino->getPosition()->x + tile.x) * TILE_SIZE, (tetromino->getPosition()->y + tile.y) * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, getColor(tetromino->getId()));
        DrawRectangle(x + tile.x*TILE_SIZE, y + tile.y*TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, getColor(tetromino->getId()));
    }
}

void TetrominoView::setTetromino(Tetromino *tetromino){
    this->tetromino = tetromino;
}