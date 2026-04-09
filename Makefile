CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = entropy
SRC = entropy.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

test: $(TARGET)
	./test.sh

clean:
	rm -f $(TARGET)
