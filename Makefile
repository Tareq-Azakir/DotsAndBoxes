
CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = dotsandboxes.exe
OBJS = main.o board.o game.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c

board.o: board.c board.h
	$(CC) $(CFLAGS) -c board.c

game.o: game.c game.h board.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f $(OBJS) $(TARGET)
