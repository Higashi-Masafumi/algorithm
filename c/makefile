CC = gcc
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib

twopointer_naive:
	$(CC) -o bin/twopointer_naive $(SRC_DIR)/twopointer/naive.c $(SRC_DIR)/utils/random_sequence.c

twopointer:
	$(CC) -o bin/twopointer $(SRC_DIR)/twopointer/twopointer.c $(SRC_DIR)/utils/random_sequence.c

euclid:
	$(CC) -o bin/euclid $(SRC_DIR)/euculid/euclid.c $(SRC_DIR)/utils/two_number.c

sieve:
	$(CC) -o bin/sieve $(SRC_DIR)/eratosthenes/sieve.c

spf:
	$(CC) -o bin/spf $(SRC_DIR)/prime_factorization/spf.c $(SRC_DIR)/utils/random_number.c

clean:
	rm -f bin/*