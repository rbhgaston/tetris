#include "TetrisController.h"

TetrisController::TetrisController() : board(BoardModel()) {
    std::srand(std::time(0));
    resetBag();
    curTetromino = getRandomTetromino();
    nextTetromino = getRandomTetromino();
    holdTetromino = nullptr;

    boardView = new BoardView(&board);
    curTetrominoView = new TetrominoView(curTetromino);
    sidePanelView = new SidePanelView();
}

const TetrominoModel* TetrisController::getCurTetromino() const {
    return curTetromino;
}

const TetrominoModel* TetrisController::getHoldTetromino() const {
    return holdTetromino;
}

const TetrominoModel* TetrisController::getNextTetromino() const {
    return nextTetromino;
}

void TetrisController::setCurTetromino(TetrominoModel* tetromino) {
    curTetromino = tetromino;
    curTetrominoView->setTetromino(tetromino);
}

void TetrisController::setHoldTetromino(TetrominoModel* tetromino) {
    holdTetromino = tetromino;
}

void TetrisController::setNextTetromino(TetrominoModel* tetromino) {
    nextTetromino = tetromino;
}

TetrominoModel* TetrisController::getRandomTetromino() {
    int randomId = rand() % bag.size();
    int randomTetrominoType = bag[randomId];
    bag.erase(bag.begin() + randomId);

    if (bag.size() == 0) {
        resetBag();
    }

    TetrominoModel* newTetromino;
    switch (randomTetrominoType) {
        case I:
            newTetromino = new ITetromino();
            break;
        case O:
            newTetromino = new OTetromino();
            break;
        case T:
            newTetromino = new TTetromino();
            break;
        case S:
            newTetromino = new STetromino();
            break;
        case Z:
            newTetromino = new ZTetromino();
            break;
        case J:
            newTetromino = new JTetromino();
            break;
        case L:
            newTetromino = new LTetromino();
            break;
    }
    return newTetromino;
}

void TetrisController::draw() const {
    boardView->draw();
    curTetrominoView->draw(curTetromino->getPosition()->x * TILE_SIZE,
                           curTetromino->getPosition()->y * TILE_SIZE);
    // SIDE PANEL
    sidePanelView->draw(score, level, lines, holdTetromino, nextTetromino);
}

bool TetrisController::moveCurTetromino(int dx, int dy) {
    curTetromino->move(dx, dy);
    if (!board.isInside(curTetromino) || board.isColliding(curTetromino)) {
        curTetromino->move(-dx, -dy);
        return false;
    }
    return true;
}

bool TetrisController::rotateCurTetromino() {
    curTetromino->rotate();
    if (!board.isInside(curTetromino) || board.isColliding(curTetromino)) {
        curTetromino->unrotate();
        return false;
    }
    return true;
}

void TetrisController::handleInput() {
    // move left
    if (IsKeyPressed(KEY_LEFT)) {
        if (moveCurTetromino(-1, 0)) playerAction = true;
    }
    // move right
    if (IsKeyPressed(KEY_RIGHT)) {
        if (moveCurTetromino(1, 0)) playerAction = true;
    }
    // rotate
    if (IsKeyPressed(KEY_UP)) {
        if (rotateCurTetromino()) playerAction = true;
    }
    // soft drop
    if (IsKeyPressed(KEY_DOWN)) {
        if (moveCurTetromino(0, 1)) playerAction = true;
    }
    // hard drop
    if (IsKeyPressed(KEY_SPACE)) {
        while (moveCurTetromino(0, 1));
    }
    // hold mechanism
    if (IsKeyPressed(KEY_C)) {
        if (holdUsed) return;
        if (holdTetromino == nullptr) {
            setHoldTetromino(curTetromino->reset());
            setCurTetromino(nextTetromino);
            setNextTetromino(getRandomTetromino());
        } else {
            TetrominoModel* temp = holdTetromino;
            setHoldTetromino(curTetromino->reset());
            setCurTetromino(temp);
        }
        holdUsed = true;
    }
}

void TetrisController::nextFrame() {
    curTetromino->move(0, 1);
    bool isColliding = board.isColliding(curTetromino);

    // if the tetromino is colliding with the board pieces, handle lock delay
    // allows the user to move the pieces for a short time after collision
    // before locking it down
    if (isColliding) {
        curTetromino->move(0, -1);

        if (collisionTime == 0) collisionTime = GetTime();

        if (playerAction && GetTime() - collisionTime < lockDelay) return;

        board.lockTetromino(curTetromino);
        holdUsed = false;
        int linesCleared = board.clearLines();
        updateScore(linesCleared);
        updateSpeed();

        TetrominoModel* newTetromino = nextTetromino;
        setNextTetromino(getRandomTetromino());

        if (board.isColliding(newTetromino)) {
            std::cout << "Game Over" << std::endl;
            exit(0);
        }
        setCurTetromino(newTetromino);

        collisionTime = 0;
        playerAction = false;

    } else {
        playerAction = false;
    }
}

void TetrisController::updateScore(int lines) {
    int factor;
    // factor according to the number of lines cleared
    switch (lines) {
        case 0:
            factor = 0;
            break;
        case 1:
            factor = 40;
            break;
        case 2:
            factor = 100;
            break;
        case 3:
            factor = 300;
            break;
        case 4:
            factor = 1200;
            break;
        default:
            factor = 1200;
    }
    // classic scoring system
    score += factor * (level + 1);

    this->lines += lines;
    // level up
    level = this->lines / 10;
}

const BoardModel* TetrisController::getBoard() const { return &board; }
const bool TetrisController::getHoldUsed() const { return holdUsed; }
const bool TetrisController::getPlayerAction() const { return playerAction; }
const int TetrisController::getScore() const { return score; }
const int TetrisController::getLevel() const { return level; }
const int TetrisController::getLines() const { return lines; }
const double TetrisController::getLockDelay() const { return lockDelay; }
const double TetrisController::getCollisionTime() const {
    return collisionTime;
}
const double TetrisController::getSpeed() const { return speed; }

void TetrisController::updateSpeed() {
    speed = std::max(0.05f, 1.0f - (0.1f * level));
}

void TetrisController::resetBag() { bag = {0, 1, 2, 3, 4, 5, 6}; }

std::vector<int> TetrisController::getBag() const { return bag; }

TetrisController::~TetrisController() {
    delete curTetromino;
    delete nextTetromino;
    delete holdTetromino;

    delete boardView;
    delete curTetrominoView;
    delete sidePanelView;
}

TetrisController::TetrisController(const TetrisController& other) {
    board = BoardModel(*other.getBoard());
    curTetromino = new TetrominoModel(*other.getCurTetromino());
    nextTetromino = new TetrominoModel(*other.getNextTetromino());
    holdTetromino = new TetrominoModel(*other.getHoldTetromino());

    boardView = new BoardView(&board);
    curTetrominoView = new TetrominoView(curTetromino);
    sidePanelView = new SidePanelView();

    holdUsed = other.getHoldUsed();
    playerAction = other.getPlayerAction();

    lockDelay = other.getLockDelay();
    collisionTime = other.getCollisionTime();
    speed = other.getSpeed();

    score = other.getScore();
    level = other.getLevel();
    lines = other.getLines();

    bag = other.getBag();
}
