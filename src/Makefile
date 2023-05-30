CC = gcc
CFLAGS = -g -Wall
TARGET = pezp

DEPS = chunk.c

CFLAGS = -Wall -Wextra -std=c99

all: $(TARGET)

$(TARGET): $(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(DEPS)