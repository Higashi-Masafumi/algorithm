CC = gcc
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib

twopointer_naive:
	$(CC) -o twopointer_naive $(SRC_DIR)/twopointer/naive.c $(SRC_DIR)/utils/random_sequence.c

twopointer:
	$(CC) -o twopointer $(SRC_DIR)/twopointer/twopointer.c $(SRC_DIR)/utils/random_sequence.c

euclid:
	$(CC) -o euclid $(SRC_DIR)/euculid/euclid.c $(SRC_DIR)/utils/two_number.c

sieve:
	$(CC) -o sieve $(SRC_DIR)/eratosthenes/sieve.c

clean:
	rm -f twopointer_naive
	rm -f twopointer
	rm -f euculid
	rm -f sieve