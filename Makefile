CC = gcc
CXX = g++
CFLAG = -std=gnu11 -g
TARGET = vector
OBJ = vector.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAG) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAG) -c $<

test: test.cpp $(TARGET)
	$(CXX) $< -o $@

format:
	clang-format -i *.c

clean:
	$(RM) $(TARGET) $(OBJ) test
