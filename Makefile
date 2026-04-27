CC = gcc
CFLAGS = -Wall
LIBS = -lncurses
TARGET = dino_game

all: $(TARGET)

$(TARGET): main.o dino.o
	$(CC) main.o dino.o -o $(TARGET) $(LIBS)

main.o: main.c dino.h
	$(CC) $(CFLAGS) -c main.c

dino.o: dino.c dino.h
	$(CC) $(CFLAGS) -c dino.c

run: all
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)