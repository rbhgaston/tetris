# Tetris

This project is an implementation of the classic Tetris game using C++ and the Raylib graphics library. The goal of the project was to create a functional Tetris game retro-themed, complete with user input, and various game mechanics. Many game features have been implemented in this project including the basic rules of Tetris (right and left movement, rotation), holding, hard drop, soft drop, lock delay, speed increase with the level reached as well as line clearing and a scoring system.

## Architecture

This project follows MVC (Model-View-Controller).

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- Raylib library
- Make

### Installation

1. **Clone the repository:**

   ```sh
   git clone https://github.com/yourusername/tetris.git
   cd tetris
   ```

2. **Install Raylib:**
   Follow the instructions on the [Raylib installation page](https://github.com/raysan5/raylib#installation) to install Raylib on your system.

3. **Option 1: Update the Makefile and Build the project:**
   Ensure that the path to Raylib is correctly set in the `Makefile`.

   **Option 2: Run it direclty in the Terminal:**
   Or if do not have make, you can simply execute this command in your terminal
   Macos

   ```sh
   g++ main.cpp ./models/TetrominoModel.cpp ./models/BoardModel.cpp ./controllers/TetrisController.cpp ./views/BoardView.cpp ./views/TetrominoView.cpp ./views/SidePanelView.cpp -o main -I/opt/homebrew/include -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo -std=c++17
   ```

   Windows

   ```sh
    g++ main.cpp ./models/TetrominoModel.cpp ./models/BoardModel.cpp ./controllers/TetrisController.cpp ./views/BoardView.cpp ./views/TetrominoView.cpp ./views/SidePanelView.cpp -o main -IC:\raylib\include -LC:\raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm -std=c++17

   ```

4. **Run the game:**
   ```sh
   ./main
   ```

### Enjoy the Game

You can now enjoy playing Tetris!
