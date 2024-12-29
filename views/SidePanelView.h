#pragma once
#include <string>

#include "../constants.h"
#include "TetrominoView.h"
#include "raylib.h"

/**
 * @brief Represents the side panel view in the Tetris game.
 *
 * This class is responsible for rendering the side panel in the Tetris game,
 * which includes displaying the current score, level, lines cleared, and the
 * hold and next Tetromino pieces.
 */
class SidePanelView {
   public:
    SidePanelView();

    void draw(int score, int level, int lines, TetrominoModel *holdTetromino,
              TetrominoModel *nextTetromino) const;

   private:
    TetrominoView *nextTetrominoView;
    TetrominoView *holdTetrominoView;
};
