CC = g++
CFLAGS = -std=c++17 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo
SRC = main.cpp Tetromino.cpp TetrisController.cpp Board.cpp BoardView.cpp TetrominoView.cpp SidePanelView.cpp
OUT = main

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OUT)

