#pragma once
#include <iostream>
#include <vector>

#include "Position.h"

enum TetrominoType { I, J, L, O, S, T, Z };

/**
 * @class TetrominoModel
 * @brief Represents a tetromino piece inside the Tetris board with its
 * rotations and position.
 */
class TetrominoModel {
   public:
    TetrominoModel(TetrominoType id, int initialOffsetx, int initialOffsety);

    void rotate();
    void unrotate();
    void move(int dx, int dy);

    const Position* getPosition() const;
    const std::vector<Position> getCurrentRotation() const;
    const TetrominoType getId() const;
    const int getInitialOffsetx() const;
    const int getInitialOffsety() const;

    void setPosition(int x, int y);

    /**
     * @brief resets the tetromino to its initial state.
     *
     * @return TetrominoModel*
     */
    TetrominoModel* reset();

   protected:
    std::vector<Position> rotations[4];
    const TetrominoType id;
    int currentRotation = 0;
    int offsetx, offsety;
    int initialOffsetx, initialOffsety;
};

class ITetromino : public TetrominoModel {
   public:
    ITetromino() : TetrominoModel(I, 3, 0) {
        rotations[0] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};
        rotations[1] = {{2, 0}, {2, 1}, {2, 2}, {2, 3}};
        rotations[2] = {{0, 2}, {1, 2}, {2, 2}, {3, 2}};
        rotations[3] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}};
    }
};

class JTetromino : public TetrominoModel {
   public:
    JTetromino() : TetrominoModel(J, 3, 0) {
        rotations[0] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};
        rotations[1] = {{1, 0}, {2, 0}, {1, 1}, {1, 2}};
        rotations[2] = {{0, 1}, {1, 1}, {2, 1}, {2, 2}};
        ;
        rotations[3] = {{1, 0}, {1, 1}, {1, 2}, {0, 2}};
    }
};

class LTetromino : public TetrominoModel {
   public:
    LTetromino() : TetrominoModel(L, 3, 0) {
        rotations[0] = {{2, 0}, {0, 1}, {1, 1}, {2, 1}};
        rotations[1] = {{1, 0}, {1, 1}, {1, 2}, {2, 2}};
        rotations[2] = {{0, 1}, {1, 1}, {2, 1}, {0, 2}};
        rotations[3] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};
    }
};

class OTetromino : public TetrominoModel {
   public:
    OTetromino() : TetrominoModel(O, 3, 0) {
        rotations[0] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
        rotations[1] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
        rotations[2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
        rotations[3] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    }
};

class STetromino : public TetrominoModel {
   public:
    STetromino() : TetrominoModel(S, 3, 0) {
        rotations[0] = {{1, 0}, {2, 0}, {0, 1}, {1, 1}};
        rotations[1] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
        rotations[2] = {{1, 1}, {2, 1}, {0, 2}, {1, 2}};
        rotations[3] = {{1, 0}, {1, 1}, {2, 1}, {2, 2}};
    }
};

class TTetromino : public TetrominoModel {
   public:
    TTetromino() : TetrominoModel(T, 3, 0) {
        rotations[0] = {{1, 0}, {1, 1}, {2, 1}, {1, 2}};
        rotations[1] = {{0, 1}, {1, 1}, {2, 1}, {1, 2}};
        rotations[2] = {{1, 0}, {0, 1}, {1, 1}, {1, 2}};
        rotations[3] = {{1, 0}, {0, 1}, {1, 1}, {2, 1}};
    }
};

class ZTetromino : public TetrominoModel {
   public:
    ZTetromino() : TetrominoModel(Z, 3, 0) {
        rotations[0] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
        rotations[1] = {{2, 0}, {1, 1}, {2, 1}, {1, 2}};
        rotations[2] = {{0, 1}, {1, 1}, {1, 2}, {2, 2}};
        rotations[3] = {{1, 0}, {0, 1}, {1, 1}, {0, 2}};
    }
};
