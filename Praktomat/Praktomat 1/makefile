# Compiler
CC = gcc

# Compiler-Flags
CFLAGS = -Wall -Wextra -std=c11

# Name des Ziels
TARGET = hello_world

# Regeln
all: $(TARGET)

$(TARGET): Hello\ World.c
	$(CC) $(CFLAGS) -o $(TARGET) "Hello World.c"

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean run
