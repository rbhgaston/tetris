/**
 * @class TetrominoView
 * @brief A class responsible for rendering a Tetromino on the screen.
 *
 * This class provides methods to draw a Tetromino at a specified position
 * and to update the Tetromino model it represents.
 */

#pragma once

#include "../constants.h"
#include "../models/Color.h"
#include "../models/TetrominoModel.h"
#include "raylib.h"

/**
 * @brief A class responsible for rendering a single Tetromino on the screen.
 */
class TetrominoView {
   public:
    TetrominoView(TetrominoModel *tetromino);
    void draw(int x, int y) const;
    void setTetromino(TetrominoModel *tetromino);
    const TetrominoModel *getTetromino() const;

    TetrominoView(const TetrominoView &other);
    TetrominoView &operator=(const TetrominoView &other);
    ~TetrominoView();

   private:
    TetrominoModel *tetromino;
};
