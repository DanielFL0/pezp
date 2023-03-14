CC = gcc
CFLAGS = -g -Wall
TARGET = ./build/pezp
FILES = ./src/*.c
INCLUDE = ./include

all:
	$(CC) $(CFLAGS) -I $(INCLUDE) $(FILES) -o $(TARGET) 