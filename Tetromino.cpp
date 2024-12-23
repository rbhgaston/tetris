#include "Tetromino.h"

Tetromino::Tetromino(){
    currentRotation = 0;
}

void Tetromino::rotate(){
    currentRotation = (currentRotation + 1) % 4;
}

int (*Tetromino::getCurrentRotation())[4]{
    return rotations[currentRotation];
}