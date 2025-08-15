CC = gcc
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib

twopointer_naive:
	$(CC) -o twopointer_naive $(SRC_DIR)/twopointer/naive.c $(SRC_DIR)/utils/random_sequence.c

twopointer:
	$(CC) -o twopointer $(SRC_DIR)/twopointer/twopointer.c $(SRC_DIR)/utils/random_sequence.c

clean:
	rm -f twopointer_naive