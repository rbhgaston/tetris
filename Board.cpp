#include "Board.h"



Board::Board(){
    for (int i = 0; i < BOARD_WIDTH; i++){
        for (int j = 0; j < BOARD_HEIGHT; j++){
            board[i][j] = -1;
        }
    }

}


void Board::lockTetromino(Tetromino *tetromino){
    Position *pos = tetromino->getPosition();
    for (Position &tile : tetromino->getCurrentRotation()){
            board[pos->x + tile.x][(pos->y + tile.y)] = tetromino->getId();
            std::cout<<tetromino->getId();
    }
}

bool Board::isInside(Tetromino *tetromino){
    Position *pos = tetromino->getPosition();
    for (Position &tile : tetromino->getCurrentRotation()){
        if (pos->x + tile.x < 0 || pos->x + tile.x >= BOARD_WIDTH || pos->y + tile.y >= BOARD_HEIGHT){
            return false;
        }
    }
    return true;
}

bool Board::isColliding(Tetromino *tetromino){
    Position *pos = tetromino->getPosition();
    for (Position &tile : tetromino->getCurrentRotation()){
        if (board[pos->x + tile.x][pos->y + tile.y] != -1 || pos->y + tile.y >= BOARD_HEIGHT){
            return true;
        }
    }
    return false;
}

int Board::clearLines(){
    int linesCleared = 0;
    for (int j = 0; j < BOARD_HEIGHT; j++){
        bool full = true;
        for (int i = 0; i < BOARD_WIDTH; i++){
            if (board[i][j] == -1){
                full = false;
                break;
            }
        }
        linesCleared += full;
        if (full){
            for (int k = j; k > 0; k--){
                for (int i = 0; i < BOARD_WIDTH; i++){
                    board[i][k] = board[i][k - 1];
                }
            }
        }
    }
    return linesCleared;
}

void Board::draw(){
    for (int i = 0; i < BOARD_WIDTH; i++){
        for (int j = 0; j < BOARD_HEIGHT; j++){
            if (board[i][j] != -1){
                DrawRectangle(i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, getColor((TetrominoType)board[i][j]));
            }
        }
    }
}

// for debugging
void Board::display(){
    for (int j = 0; j < BOARD_HEIGHT; j++){
        for (int i = 0; i < BOARD_WIDTH; i++){
            std::cout<<board[i][j];
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

