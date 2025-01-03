#include "TetrominoModel.h"

TetrominoModel::TetrominoModel(TetrominoType id, int initialOffsetx,
                               int initialOffsety)
    : id(id), initialOffsetx(initialOffsetx), initialOffsety(initialOffsety) {
    offsetx = initialOffsetx;
    offsety = initialOffsety;
}

void TetrominoModel::rotate() {
    currentRotationIndex = (currentRotationIndex + 1) % 4;
}

void TetrominoModel::unrotate() {
    currentRotationIndex = (currentRotationIndex - 1) % 4;
}

void TetrominoModel::move(int dx, int dy) {
    offsetx += dx;
    offsety += dy;
}

const Position* TetrominoModel::getPosition() const {
    return new Position{offsetx, offsety};
}

const std::vector<Position> TetrominoModel::getCurrentRotation() const {
    return rotations[currentRotationIndex];
}

const TetrominoType TetrominoModel::getId() const { return id; }

const int TetrominoModel::getInitialOffsetx() const { return initialOffsetx; }

const int TetrominoModel::getInitialOffsety() const { return initialOffsety; }

const int TetrominoModel::getOffsetx() const { return offsetx; }

const int TetrominoModel::getOffsety() const { return offsety; }

const int TetrominoModel::getCurrentRotationIndex() const {
    return currentRotationIndex;
}

const std::vector<std::vector<Position>> TetrominoModel::getRotations() const {
    std::vector<std::vector<Position>> result;
    for (int i = 0; i < 4; i++) {
        result.push_back(rotations[i]);
    }
    return result;
}

void TetrominoModel::setPosition(int x, int y) {
    offsetx = x;
    offsety = y;
}

TetrominoModel* TetrominoModel::reset() {
    offsetx = initialOffsetx;
    offsety = initialOffsety;
    currentRotationIndex = 0;
    return this;
}

TetrominoModel::TetrominoModel(const TetrominoModel& other)
    : id(other.getId()),
      currentRotationIndex(other.getCurrentRotationIndex()),
      offsetx(other.getOffsetx()),
      offsety(other.getOffsety()),
      initialOffsetx(other.getInitialOffsetx()),
      initialOffsety(other.getInitialOffsety()) {
    std::vector<std::vector<Position>> otherRotations = other.getRotations();
    for (int i = 0; i < 4; i++) {
        rotations[i] = otherRotations[i];
    }
}

TetrominoModel& TetrominoModel::operator=(const TetrominoModel& other) {
    if (this == &other) return *this;

    currentRotationIndex = other.getCurrentRotationIndex();
    offsetx = other.getOffsetx();
    offsety = other.getOffsety();
    initialOffsetx = other.getInitialOffsetx();
    initialOffsety = other.getInitialOffsety();

    std::vector<std::vector<Position>> otherRotations = other.getRotations();
    for (int i = 0; i < 4; i++) {
        rotations[i] = otherRotations[i];
    }

    return *this;
}