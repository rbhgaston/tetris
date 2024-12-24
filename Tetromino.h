#pragma once
#include <vector>
#include "Position.h"

enum TetrominoType{
    I, J, L, O, S, T, Z
};


//TODO implement as I type for testing
class Tetromino{
    public:
        Tetromino() {
            rotations[0] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};
            rotations[1] = {{2, 0}, {2, 1}, {2, 2}, {2, 3}};
            rotations[2] = {{0, 2}, {1, 2}, {2, 2}, {3, 2}};
            rotations[3] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}};
        }
        Tetromino(int x, int y);
        void rotate();
        void unrotate();
        void move(int dx, int dy);
        Position* getPosition();
        Tetromino* setPosition(int x, int y){
            offsetx = x;
            offsety = y;
            return this;
        }
        std::vector<Position> getCurrentRotation();
        // copy constructor
        Tetromino(const Tetromino &tetromino){
            offsetx = tetromino.offsetx;
            offsety = tetromino.offsety;
            currentRotation = tetromino.currentRotation;
            id = tetromino.id;
            for (int i = 0; i < 4; i++){
                rotations[i] = tetromino.rotations[i];
            }
        }

    //protected:
    
        std::vector<Position> rotations [4];
        TetrominoType id;
        int currentRotation = 0;
        int offsetx = 0 , offsety = 0;

};

class ITetromino: public Tetromino{
    public:
        ITetromino(){
            rotations[0] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};
            rotations[1] = {{2, 0}, {2, 1}, {2, 2}, {2, 3}};
            rotations[2] = {{0, 2}, {1, 2}, {2, 2}, {3, 2}};
            rotations[3] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}};

            id = I;
        }
};

class JTetromino: public Tetromino{
    public:
        JTetromino(){
            rotations[0] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};
            rotations[1] = {{1, 0}, {2, 0}, {1, 1}, {1, 2}};
            rotations[2] = {{0, 1}, {1, 1}, {2, 1}, {2, 2}};;
            rotations[3] = {{1, 0}, {1, 1}, {1, 2}, {0, 2}};

            id = J;
        }
};

class LTetromino: public Tetromino{
    public:
        LTetromino(){
            rotations[0] = {{2, 0}, {0, 1}, {1, 1}, {2, 1}};
            rotations[1] = {{1, 0}, {1, 1}, {1, 2}, {2, 2}};
            rotations[2] = {{0, 1}, {1, 1}, {2, 1}, {0, 2}};
            rotations[3] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};

            id = L;
        }
};

class OTetromino: public Tetromino{
    public:
        OTetromino(){
            rotations[0] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
            rotations[1] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
            rotations[2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
            rotations[3] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};

            id = O;
        }
};
// TODO check
class STetromino: public Tetromino{
    public:
        STetromino(){
            rotations[0] = {{1, 0}, {2, 0}, {0, 1}, {1, 1}};
            rotations[1] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
            rotations[2] = {{1, 1}, {2, 1}, {0, 2}, {1, 2}};
            rotations[3] = {{1, 0}, {1, 1}, {2, 1}, {2, 2}};

            id = S;
        }
};

class TTetromino: public Tetromino{
    public:
        TTetromino(){
            rotations[0] = {{1, 0}, {0, 1}, {1, 1}, {2, 1}};
            rotations[1] = {{1, 0}, {0, 1}, {1, 1}, {1, 2}};
            rotations[2] = {{0, 1}, {1, 1}, {2, 1}, {1, 2}};
            rotations[3] = {{1, 0}, {1, 1}, {2, 1}, {1, 2}};

            id = T;
        }
};

class ZTetromino: public Tetromino{
    public:
        ZTetromino(){
            rotations[0] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
            rotations[1] = {{2, 0}, {1, 1}, {2, 1}, {1, 2}};
            rotations[2] = {{0, 1}, {1, 1}, {1, 2}, {2, 2}};
            rotations[3] = {{1, 0}, {0, 1}, {1, 1}, {0, 2}};

            id = Z;
        }
};
