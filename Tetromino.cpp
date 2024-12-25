#include "Tetromino.h"

Tetromino::Tetromino(TetrominoType id): id(id) {
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

// Tetromino::Tetromino(const Tetromino &tetromino): id(tetromino.id){
//     offsetx = tetromino.offsetx;
//     offsety = tetromino.offsety;
//     currentRotation = tetromino.currentRotation;
//     for (int i = 0; i < 4; i++){
//         rotations[i] = tetromino.rotations[i];
//     }
// }

// // assignment operator
// Tetromino& Tetromino::operator=(const Tetromino &tetromino){
//     if (this == &tetromino)
//         return *this;
//     offsetx = tetromino.offsetx;
//     offsety = tetromino.offsety;
//     currentRotation = tetromino.currentRotation;
//     for (int i = 0; i < 4; i++){
//         rotations[i] = tetromino.rotations[i];
//     }
//     return *this;
// }


const TetrominoType Tetromino::getId() const{
    return id;
}

Tetromino* Tetromino::setPosition(int x, int y){
    offsetx = x;
    offsety = y;
    return this;
}