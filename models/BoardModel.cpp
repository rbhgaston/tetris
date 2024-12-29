#include "BoardModel.h"

BoardModel::BoardModel() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            board[i][j] = -1;
        }
    }
}

void BoardModel::lockTetromino(TetrominoModel *tetromino) {
    const Position *pos = tetromino->getPosition();
    for (const Position &tile : tetromino->getCurrentRotation()) {
        board[pos->x + tile.x][(pos->y + tile.y)] = tetromino->getId();
    }
}

const bool BoardModel::isInside(TetrominoModel *tetromino) const {
    const Position *pos = tetromino->getPosition();
    for (const Position &tile : tetromino->getCurrentRotation()) {
        if (pos->x + tile.x < 0 || pos->x + tile.x >= BOARD_WIDTH ||
            pos->y + tile.y >= BOARD_HEIGHT) {
            return false;
        }
    }
    return true;
}

const bool BoardModel::isColliding(TetrominoModel *tetromino) const {
    const Position *pos = tetromino->getPosition();
    for (const Position &tile : tetromino->getCurrentRotation()) {
        if (board[pos->x + tile.x][pos->y + tile.y] != -1 ||
            pos->y + tile.y >= BOARD_HEIGHT) {
            return true;
        }
    }
    return false;
}

int BoardModel::clearLines() {
    int linesCleared = 0;
    for (int j = 0; j < BOARD_HEIGHT; j++) {
        bool full = true;
        for (int i = 0; i < BOARD_WIDTH; i++) {
            if (board[i][j] == -1) {
                full = false;
                break;
            }
        }
        linesCleared += full;
        if (full) {
            for (int k = j; k > 0; k--) {
                for (int i = 0; i < BOARD_WIDTH; i++) {
                    board[i][k] = board[i][k - 1];
                }
            }
        }
    }
    return linesCleared;
}

const int BoardModel::getCell(Position *pos) const {
    return board[pos->x][pos->y];
}

void BoardModel::display() const {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
        for (int i = 0; i < BOARD_WIDTH; i++) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
