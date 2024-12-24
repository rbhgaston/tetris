#include "Tetromino.h"

Tetromino::Tetromino(){
    currentRotation = 0;
}
Tetromino::Tetromino(int x, int y){
    currentRotation = 0;
    offsetx = x;
    offsety = y;
}

void Tetromino::rotate(){
    currentRotation = (currentRotation + 1) % 4;
}

void Tetromino::move(int dx, int dy){
    offsetx += dx;
    offsety += dy;
}
Position Tetromino::getPosition(){
    return Position{offsetx, offsety};
}

std::vector<Position> Tetromino::getCurrentRotation(){
    return rotations[currentRotation];
}