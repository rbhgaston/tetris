#pragma once

#include <raylib.h>
#include "Tetromino.h"


inline Color getColor(TetrominoType type){
    switch (type){
        case I:
            return SKYBLUE;
        case J:
            return BLUE;
        case L:
            return ORANGE;
        case O:
            return YELLOW;
        case S:
            return GREEN;
        case T:
            return PURPLE;
        case Z:
            return RED;
    }
    return BLACK;
}

