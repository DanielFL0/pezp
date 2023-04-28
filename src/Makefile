CC = gcc
CFLAGS = -g -Wall
TARGET = pezp

# TODO: check makefile
DEPS = chunk.c debug.c

PZPCCFLAGS = -Wall -Wextra

all: $(TARGET)

$(TARGET): $(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(DEPS)