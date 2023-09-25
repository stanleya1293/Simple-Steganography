CC = g++
CFLAGS = -c -Wall -Wextra
TARGET = steganography

all: $(TARGET)

$(TARGET): main.o Steganography.o
	$(CC) main.o Steganography.o -o $(TARGET)

main.o: main.cpp Steganography.h
	$(CC) $(CFLAGS) main.cpp -o main.o

Steganography.o: Steganography.cpp Steganography.h
	$(CC) $(CFLAGS) Steganography.cpp -o Steganography.o

clean:
	$(RM) $(TARGET) *.o *~
