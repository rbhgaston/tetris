#include "TetrominoModel.h"

TetrominoModel::TetrominoModel(TetrominoType id, int initialOffsetx,
                               int initialOffsety)
    : id(id), initialOffsetx(initialOffsetx), initialOffsety(initialOffsety) {
    offsetx = initialOffsetx;
    offsety = initialOffsety;
}

void TetrominoModel::rotate() { currentRotation = (currentRotation + 1) % 4; }

void TetrominoModel::unrotate() { currentRotation = (currentRotation - 1) % 4; }

void TetrominoModel::move(int dx, int dy) {
    offsetx += dx;
    offsety += dy;
}

const Position* TetrominoModel::getPosition() const {
    return new Position{offsetx, offsety};
}

const std::vector<Position> TetrominoModel::getCurrentRotation() const {
    return rotations[currentRotation];
}

const TetrominoType TetrominoModel::getId() const { return id; }

const int TetrominoModel::getInitialOffsetx() const { return initialOffsetx; }

const int TetrominoModel::getInitialOffsety() const { return initialOffsety; }

void TetrominoModel::setPosition(int x, int y) {
    offsetx = x;
    offsety = y;
}

TetrominoModel* TetrominoModel::reset() {
    offsetx = initialOffsetx;
    offsety = initialOffsety;
    currentRotation = 0;
    return this;
}