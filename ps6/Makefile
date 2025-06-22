# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wno-vla-parameter
LDLIBS=-lm -lcurses
OUTPUT=arkanoid

# targets
all: $(OUTPUT)

$(OUTPUT): paddle.o brick.o ball.o game.o pch.o menu.o main.o
	cppcheck --enable=performance --error-exitcode=1 *.c
	$(CC) $(CFLAGS) paddle.o brick.o ball.o game.o pch.o menu.o main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o

pch.o: pch.c pch.h
	$(CC) $(CFLAGS) -c pch.c $(LDLIBS) -o pch.o

menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c $(LDLIBS) -o menu.o

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c $(LDLIBS) -o game.o

ball.o: ball.c ball.h
	$(CC) $(CFLAGS) -c ball.c $(LDLIBS) -o ball.o

brick.o: brick.c brick.h
	$(CC) $(CFLAGS) -c brick.c $(LDLIBS) -o brick.o

paddle.o: paddle.c paddle.h
	$(CC) $(CFLAGS) -c paddle.c $(LDLIBS) -o paddle.o

# remove compiled files
clean: 
	rm -rf $(OUTPUT) *.o
