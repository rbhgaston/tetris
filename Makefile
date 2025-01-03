CC = g++
CFLAGS = -std=c++17 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo
SRC = main.cpp ./models/TetrominoModel.cpp ./models/BoardModel.cpp ./controllers/TetrisController.cpp ./views/BoardView.cpp ./views/TetrominoView.cpp ./views/SidePanelView.cpp
OUT = main

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OUT)

