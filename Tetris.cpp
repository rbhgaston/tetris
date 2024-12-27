#include "Tetris.h"

Tetris::Tetris(): board(Board()){
    std::srand(std::time(0));
    resetBag();
    curTetromino = getRandomTetromino();
    nextTetromino = getRandomTetromino();
    holdTetromino = nullptr;
}

Tetromino* Tetris::getCurTetromino(){
    return curTetromino;
}

void Tetris::setCurTetromino(Tetromino *tetromino){
    curTetromino = tetromino;
}

Tetromino* Tetris::getRandomTetromino(){
    int randomId = rand() % bag.size();
    int randomTetrominoType = bag[randomId];
    bag.erase(bag.begin() + randomId);

    if (bag.size() == 0){
        resetBag();
    }

    Tetromino* newTetromino;
    switch(randomTetrominoType) {
        case I: newTetromino = new ITetromino(); break;
        case O: newTetromino = new OTetromino(); break;
        case T: newTetromino = new TTetromino(); break;
        case S: newTetromino = new STetromino(); break;
        case Z: newTetromino = new ZTetromino(); break;
        case J: newTetromino = new JTetromino(); break;
        case L: newTetromino = new LTetromino(); break;
    }
    return newTetromino;
}

void Tetris::draw(){
    board.draw();
    for(Position tile : curTetromino->getCurrentRotation()){
        DrawRectangle((curTetromino->getPosition()->x + tile.x) * TILE_SIZE, (curTetromino->getPosition()->y + tile.y) * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, getColor(curTetromino->getId()));
    }
    // SIDE PANEL
    DrawRectangle(TILE_SIZE * BOARD_WIDTH, 0, SIDE_PANEL_WIDTH, TILE_SIZE * BOARD_HEIGHT, GRAY);
    // score
    DrawText("Score", TILE_SIZE * BOARD_WIDTH + 10, 10, 20, BLACK);
    DrawText(std::to_string(score).c_str(), TILE_SIZE * BOARD_WIDTH + 10, 35, 20, BLACK);
    // level
    DrawText("Level", TILE_SIZE * BOARD_WIDTH + 10, 60, 20, BLACK);
    DrawText(std::to_string(level).c_str(), TILE_SIZE * BOARD_WIDTH + 10, 80, 20, BLACK);
    // lines cleared
    DrawText("Lines", TILE_SIZE * BOARD_WIDTH + 10, 110, 20, BLACK);
    DrawText(std::to_string(lines).c_str(), TILE_SIZE * BOARD_WIDTH + 10, 130, 20, BLACK);
    // next tetromino
    DrawText("Next", TILE_SIZE * BOARD_WIDTH + 10, 160, 20, BLACK);
    for(Position tile : nextTetromino->getCurrentRotation()){
        DrawRectangle(TILE_SIZE * BOARD_WIDTH + 10 + tile.x * TILE_SIZE, 180 + tile.y * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, getColor(nextTetromino->getId()));
    }
    // hold tetromino
    DrawText("Hold", TILE_SIZE * BOARD_WIDTH + 10, 240, 20, BLACK);
    if(holdTetromino != nullptr){
        for(Position tile : holdTetromino->getCurrentRotation()){
            DrawRectangle(TILE_SIZE * BOARD_WIDTH + 10 + tile.x * TILE_SIZE, 260 + tile.y * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, getColor(holdTetromino->getId()));
        }
    }
    // // next tetromino
    // DrawText("Next", TILE_SIZE * BOARD_WIDTH + 10, 150, 20, BLACK);
    // for(Position tile : nextTetromino->getCurrentRotation()){
    //     DrawRectangle(TILE_SIZE * BOARD_WIDTH + 10 + tile.x * TILE_SIZE, 180 + tile.y * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, getColor(nextTetromino->getId()));
    // }
    // // hold tetromino
    // DrawText("Hold", TILE_SIZE * BOARD_WIDTH + 10, 300, 20, BLACK);
    // if(holdTetromino != nullptr){
    //     for(Position tile : holdTetromino->getCurrentRotation()){
    //         DrawRectangle(TILE_SIZE * BOARD_WIDTH + 10 + tile.x * TILE_SIZE, 330 + tile.y * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, getColor(holdTetromino->getId()));
    //     }
    // }
    

}

bool Tetris::moveCurTetromino(int dx, int dy){
    curTetromino->move(dx, dy);
    if(!board.isInside(curTetromino) || board.isColliding(curTetromino)){
        curTetromino->move(-dx, -dy);
        return false;
    } 
    return true;
}

bool Tetris::rotateCurTetromino(){
    curTetromino->rotate();
    if(!board.isInside(curTetromino) || board.isColliding(curTetromino)){
        curTetromino->unrotate();
        return false;
    }
    return true;
}

void Tetris::handleInput(){
    if (IsKeyPressed(KEY_LEFT)){
        if(moveCurTetromino(-1, 0))
        playerAction = true;
    }
    if (IsKeyPressed(KEY_RIGHT)){
       if( moveCurTetromino(1, 0))
        playerAction = true;
    }
    if (IsKeyPressed(KEY_DOWN)){
        if(moveCurTetromino(0, 1))
        playerAction = true;
    }
    if (IsKeyPressed(KEY_UP)){
        if(rotateCurTetromino())
        playerAction = true;
    }
    if(IsKeyPressed(KEY_SPACE)){
        while(moveCurTetromino(0, 1));
    }
    if(IsKeyPressed(KEY_C)){
        if (holdUsed) return;
        if(holdTetromino == nullptr){
            holdTetromino = curTetromino->reset();
            curTetromino = nextTetromino;
            nextTetromino = getRandomTetromino();
        }else{
            Tetromino* temp = holdTetromino;
            holdTetromino = curTetromino->reset();
            curTetromino = temp;
        }
        holdUsed = true;
    }
}

// computes next state of the game
// how to change code to make it accept random tetromino blocks

void Tetris::nextFrame(){
    curTetromino->move(0, 1);
    bool isColliding = board.isColliding(curTetromino);

    if (isColliding){
        curTetromino->move(0, -1);

        if(collisionTime == 0) collisionTime = GetTime();
        
        if(playerAction && GetTime() - collisionTime < lockDelay) return;

        board.lockTetromino(curTetromino);
        holdUsed = false;
        int linesCleared = board.clearLines();
        updateScore(linesCleared);
        updateSpeed();

        Tetromino* newTetromino = nextTetromino;
        nextTetromino = getRandomTetromino();

        if(board.isColliding(newTetromino)){
            std::cout<<"Game Over"<<std::endl;
            exit(0);
        }
        curTetromino = newTetromino;

        collisionTime = 0;
        playerAction = false;
        
    }else{
        playerAction = false;
    }           
}

void Tetris::updateScore(int lines){
    int factor;
    switch(lines){
        case 0: factor = 0; break;
        case 1: factor = 40; break;
        case 2: factor = 100; break;
        case 3: factor = 300; break;
        case 4: factor = 1200; break;
        default: factor = 1200;
    }

    score += factor * (level + 1);
    
    this->lines += lines;
    // level up
    level = this->lines / 10;
}

const double Tetris::getSpeed() const{
    return speed;
}

void Tetris::updateSpeed(){
    speed = std::max(0.05f, 1.0f - (0.1f * level));
}

void Tetris::resetBag(){
    bag = {0, 1, 2, 3, 4, 5, 6};
}







