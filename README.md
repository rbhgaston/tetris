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

2. **Install Raylib and Make:**
   Follow the instructions on the [Raylib installation page](https://github.com/raysan5/raylib#installation) to install Raylib on your system.
   Then install Make.

3. **Update the Makefile:**
   Ensure that the path to Raylib is correctly set in the `Makefile`.

4. **Build the project:**

   ```sh
   make
   ```

5. **Run the game:**
   ```sh
   ./main
   ```

### Enjoy the Game

You can now enjoy playing Tetris!
