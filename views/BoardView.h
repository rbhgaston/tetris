#pragma once
#include "../models/BoardModel.h"
#include "raylib.h"

/**
 * @class BoardView
 * @brief Displays the game board for Tetris.
 *
 * The BoardView class is responsible for rendering the game board to the
 * screen.
 */
class BoardView {
   public:
    BoardView(BoardModel* board);

    void draw() const;

   private:
    BoardModel* board;
};
