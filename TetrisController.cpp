#include "TetrisController.h"

TetrisController::TetrisController(): board(Board()) {
    std::srand(std::time(0));
    resetBag();
    curTetromino = getRandomTetromino();
    nextTetromino = getRandomTetromino();
    holdTetromino = nullptr;

    boardView = new BoardView(&board);
    curTetrominoView = new TetrominoView(curTetromino);
    sidePanelView = new SidePanelView();
}

Tetromino* TetrisController::getCurTetromino(){
    return curTetromino;
}

void TetrisController::setCurTetromino(Tetromino *tetromino){
    curTetromino = tetromino;
    curTetrominoView->setTetromino(tetromino);
}

void TetrisController::setHoldTetromino(Tetromino *tetromino){
    holdTetromino = tetromino;
}

void TetrisController::setNextTetromino(Tetromino *tetromino){
    nextTetromino = tetromino;
}

Tetromino* TetrisController::getRandomTetromino(){
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

void TetrisController::draw(){
    boardView->draw(); 
    curTetrominoView->draw(curTetromino->getPosition()->x * TILE_SIZE, curTetromino->getPosition()->y * TILE_SIZE);
    // SIDE PANEL
    sidePanelView->draw(score, level, lines, holdTetromino, nextTetromino);
}

bool TetrisController::moveCurTetromino(int dx, int dy){
    curTetromino->move(dx, dy);
    if(!board.isInside(curTetromino) || board.isColliding(curTetromino)){
        curTetromino->move(-dx, -dy);
        return false;
    } 
    return true;
}

bool TetrisController::rotateCurTetromino(){
    curTetromino->rotate();
    if(!board.isInside(curTetromino) || board.isColliding(curTetromino)){
        curTetromino->unrotate();
        return false;
    }
    return true;
}

void TetrisController::handleInput(){
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
    }//TODO change curTetromino to nextTetromino
    if(IsKeyPressed(KEY_C)){
        if (holdUsed) return;
        if(holdTetromino == nullptr){
            setHoldTetromino(curTetromino->reset());
            setCurTetromino(nextTetromino);
            setNextTetromino(getRandomTetromino());
        }else{
            Tetromino* temp = holdTetromino;
            setHoldTetromino(curTetromino->reset());
            setCurTetromino(temp);
        }
        holdUsed = true;
    }
}

// computes next state of the game
// how to change code to make it accept random tetromino blocks

void TetrisController::nextFrame(){
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
        setNextTetromino(getRandomTetromino());

        if(board.isColliding(newTetromino)){
            std::cout<<"Game Over"<<std::endl;
            exit(0);
        }
        setCurTetromino(newTetromino);

        collisionTime = 0;
        playerAction = false;
        
    }else{
        playerAction = false;
    }           
}

void TetrisController::updateScore(int lines){
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

const double TetrisController::getSpeed() const{
    return speed;
}

void TetrisController::updateSpeed(){
    speed = std::max(0.05f, 1.0f - (0.1f * level));
}

void TetrisController::resetBag(){
    bag = {0, 1, 2, 3, 4, 5, 6};
}







