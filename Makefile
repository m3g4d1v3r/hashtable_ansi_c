-include config.mk

CC = gcc
CFLAGS = -Wall -Wextra
TARGET = hashtable_exe 
OBJS = hashtable.o main.o
VALGRIND = valgrind --leak-check=full --track-origins=yes

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

hashtable.o: hashtable.c hashtable.h
	$(CC) $(CFLAGS) -c hashtable.c

main.o: main.c hashtable.h
	$(CC) $(CFLAGS) -c main.c

valgrind: $(TARGET)
	$(VALGRIND) ./$(TARGET)

check: valgrind
	./$(TARGET) && echo "Everything is ok memory-wise."

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean valgrind check

