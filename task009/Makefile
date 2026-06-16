CC = gcc
CFLAGS = -Wall -Wextra
TARGET = exe

all: $(TARGET)

$(TARGET): main.c
	@$(CC) $(CFLAGS) $^ -o $(TARGET)
	@./$(TARGET)

run:
	@./$(TARGET)

clean:
	@rm -f *.o $(TARGET)

.PHONY: all run clean

.PRECIOUS: exe