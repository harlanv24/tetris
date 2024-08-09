CXX = g++
CXXFLAGS = -std=c++11 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`
TARGET = tetris

# List of object files
OBJS = main.o TetrisBoard.o Block.o Game.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)

main.o: main.cpp TetrisBoard.h Block.h Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

TetrisBoard.o: TetrisBoard.cpp TetrisBoard.h
	$(CXX) $(CXXFLAGS) -c TetrisBoard.cpp

Block.o: Block.cpp Block.h
	$(CXX) $(CXXFLAGS) -c Block.cpp

Game.o: Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

clean:
	rm -f *.o $(TARGET)