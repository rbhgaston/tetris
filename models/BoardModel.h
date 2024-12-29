
#pragma once

#include <iostream>

#include "../constants.h"
#include "Color.h"
#include "TetrominoModel.h"

/**
 * @class BoardModel
 * @brief Represents the game board for Tetris.
 *
 * The BoardModel class manages the state of the Tetris game board, including
 * locking tetrominoes, checking for collisions, and clearing completed lines.
 */
class BoardModel {
   public:
    BoardModel();

    /**
     * @brief Locks the given TetrominoModel onto the board.
     *
     * @param tetromino Pointer to the TetrominoModel to be locked.
     */
    void lockTetromino(TetrominoModel *tetromino);

    /**
     * @brief Checks if the given TetrominoModel is inside the board boundaries.
     *
     * @param tetromino Pointer to the TetrominoModel to be checked.
     * @return true if the TetrominoModel is inside the board, false otherwise.
     */
    const bool isInside(TetrominoModel *tetromino) const;

    /**
     * @brief Checks if the given TetrominoModel is colliding with any locked
     * pieces on the board.
     *
     * @param tetromino Pointer to the TetrominoModel to be checked.
     * @return true if the TetrominoModel is colliding, false otherwise.
     */
    const bool isColliding(TetrominoModel *tetromino) const;

    /**
     * @brief Clears any completed lines on the board.
     *
     * @return The number of lines that were cleared.
     */
    int clearLines();

    const int getCell(Position *pos) const;

    /**
     * @brief Displays the current state of the board for debugging purposes.
     */
    void display() const;

   private:
    int board[BOARD_WIDTH][BOARD_HEIGHT];
};