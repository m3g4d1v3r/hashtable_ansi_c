-include config.mk

CC = gcc
CFLAGS = -Wall -Wextra
TARGET = hashtable_exe 
OBJS = hashtable.o main.o
VALGRIND = valgrind --leak-check=full --track-origins=yes
DISTFILES = hashtable.c hashtable.h main.c Makefile configure

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
	./$(TARGET) && echo "All tests passed."

distcheck: check
	mkdir -p dist
	cp $(DISTFILES) dist/
	cd dist && tar czf ../$(TARGET).tar.gz *
	rm -rf dist

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean valgrind check distcheck

