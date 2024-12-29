#pragma once
#include "raylib.h"
#include "Board.h"

class BoardView {
public:
    BoardView(Board* board);

    void draw();

    private:
        Board* board;
};

