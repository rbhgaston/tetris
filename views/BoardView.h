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

    const BoardModel* getBoard() const;

    BoardView(const BoardView& other);
    BoardView& operator=(const BoardView& other);
    ~BoardView();

   private:
    BoardModel* board;
};
