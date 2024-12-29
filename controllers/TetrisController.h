#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "../constants.h"
#include "../models/TetrominoModel.h"
#include "../views/BoardView.h"
#include "../views/SidePanelView.h"
#include "../views/TetrominoView.h"

/**
 * @brief Controls the game logic for Tetris.
 *
 * The TetrisController class is responsible for managing the game state of
 * Tetris, including the game board, Tetromino pieces, and player input.
 */
class TetrisController {
   public:
    TetrisController();

    // getters
    const TetrominoModel* getCurTetromino() const;
    const double getSpeed() const;

    // setters
    void setCurTetromino(TetrominoModel* tetromino);
    void setNextTetromino(TetrominoModel* tetromino);
    void setHoldTetromino(TetrominoModel* tetromino);

    /**
     * @brief picks a random tetromino from the bag and removes it from the bag.
     * if the bag becomes empty, it resets the bag.
     *
     * @return TetrominoModel*
     */
    TetrominoModel* getRandomTetromino();

    /**
     * @brief Draws the board, the current tetromino(that is falling) and the
     * side panel.
     */
    void draw() const;

    /**
     * @brief moves the current tetromino by dx and dy if it is possible.
     *
     * @param dx
     * @param dy
     * @return true if the move was successful, false otherwise.
     */
    bool moveCurTetromino(int dx, int dy);

    /**
     * @brief rotates the current tetromino if it is possible.
     *
     * @return true if the rotation was successful, false otherwise.
     */
    bool rotateCurTetromino();

    /**
     * @brief Handles player input for moving and rotating the current
     * Tetromino. handles right and left movements, soft drop, hard drop,
     * rotation and hold.
     */
    void handleInput();

    /**
     * @brief Updates the game state for the next frame.
     */
    void nextFrame();

    void updateScore(int score);

    void updateSpeed();

    void resetBag();

   private:
    // models
    BoardModel board;
    TetrominoModel* curTetromino;
    TetrominoModel* nextTetromino;
    TetrominoModel* holdTetromino;

    // views
    BoardView* boardView;
    TetrominoView* curTetrominoView;
    SidePanelView* sidePanelView;

    bool holdUsed = false;
    int playerAction = false;

    double lockDelay = 0.5f;
    double collisionTime = 0;
    double speed = 1.0f;

    int score = 0;
    int level = 0;
    int lines = 0;

    // bag of tetrominos: contains maximum of 7 diffrent tetrominos, each
    // tetromino gets removed if selected and the bag is reset to 7 tetrominos
    // when its empty
    std::vector<int> bag;
};
