#include "Tetromino.h"



Tetromino::Tetromino(int x, int y){
    offsetx = x;
    offsety = y;
}


void Tetromino::rotate(){
    currentRotation = (currentRotation + 1) % 4;
}

void Tetromino::unrotate(){
    currentRotation = (currentRotation - 1) % 4;
}

void Tetromino::move(int dx, int dy){
    offsetx += dx;
    offsety += dy;
}
Position* Tetromino::getPosition(){
    return new Position{offsetx, offsety};
}

std::vector<Position> Tetromino::getCurrentRotation(){
    return rotations[currentRotation];
}