CC = gcc
CFLAGS = -g -Wall
TARGET = pezp
DEPS = chunk.c node.c linked_list.c file_loader.c virtual_machine.c

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(DEPS)