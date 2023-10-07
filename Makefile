CC=g++
CFLAGS=-c -DLINUX -I. -LSDL/lib
LDFLAGS=-lSDL -lSDL_gfx
SOURCES=main.cpp game.cpp board.cpp io.cpp pieces.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tetris

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)
