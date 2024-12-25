#pragma once
#include <vector>
#include "Position.h"
#include <iostream>

enum TetrominoType{
    I, J, L, O, S, T, Z
};

class Tetromino{
    public:
        Tetromino(TetrominoType id);
        void rotate();
        void unrotate();
        void move(int dx, int dy);
        Position* getPosition();
        Tetromino* setPosition(int x, int y); 
        std::vector<Position> getCurrentRotation();

        Tetromino(const Tetromino &tetromino);
        Tetromino& operator=(const Tetromino &tetromino);

        const TetrominoType getId() const;

    protected:
        std::vector<Position> rotations [4];
        const TetrominoType id;
        int currentRotation = 0;
        int offsetx = 0 , offsety = 0;

};

class ITetromino: public Tetromino{
    public:
        ITetromino() : Tetromino(I) {
            rotations[0] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};
            rotations[1] = {{2, 0}, {2, 1}, {2, 2}, {2, 3}};
            rotations[2] = {{0, 2}, {1, 2}, {2, 2}, {3, 2}};
            rotations[3] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}};
        }
};

class JTetromino: public Tetromino{
    public:
        JTetromino() : Tetromino(J) {
            rotations[0] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};
            rotations[1] = {{1, 0}, {2, 0}, {1, 1}, {1, 2}};
            rotations[2] = {{0, 1}, {1, 1}, {2, 1}, {2, 2}};;
            rotations[3] = {{1, 0}, {1, 1}, {1, 2}, {0, 2}};
        }
};

class LTetromino: public Tetromino{
    public:
        LTetromino() : Tetromino(L) {
            rotations[0] = {{2, 0}, {0, 1}, {1, 1}, {2, 1}};
            rotations[1] = {{1, 0}, {1, 1}, {1, 2}, {2, 2}};
            rotations[2] = {{0, 1}, {1, 1}, {2, 1}, {0, 2}};
            rotations[3] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};
        }
};

class OTetromino: public Tetromino{
    public:
        OTetromino() : Tetromino(O) {
            rotations[0] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
            rotations[1] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
            rotations[2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
            rotations[3] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
        }
};

class STetromino: public Tetromino{
    public:
        STetromino() : Tetromino(S) {
            rotations[0] = {{1, 0}, {2, 0}, {0, 1}, {1, 1}};
            rotations[1] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
            rotations[2] = {{1, 1}, {2, 1}, {0, 2}, {1, 2}};
            rotations[3] = {{1, 0}, {1, 1}, {2, 1}, {2, 2}};
        }
};

class TTetromino: public Tetromino{
    public:
        TTetromino() : Tetromino(T) {
            rotations[0] = {{1, 0}, {0, 1}, {1, 1}, {2, 1}};
            rotations[1] = {{1, 0}, {0, 1}, {1, 1}, {1, 2}};
            rotations[2] = {{0, 1}, {1, 1}, {2, 1}, {1, 2}};
            rotations[3] = {{1, 0}, {1, 1}, {2, 1}, {1, 2}};
        }
};

class ZTetromino: public Tetromino{
    public:
        ZTetromino() : Tetromino(Z) {
            rotations[0] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
            rotations[1] = {{2, 0}, {1, 1}, {2, 1}, {1, 2}};
            rotations[2] = {{0, 1}, {1, 1}, {1, 2}, {2, 2}};
            rotations[3] = {{1, 0}, {0, 1}, {1, 1}, {0, 2}};
        }
};
