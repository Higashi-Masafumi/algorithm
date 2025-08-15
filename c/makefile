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

stack:
	$(CC) -o bin/stack $(SRC_DIR)/stack/stack.c

queue:
	$(CC) -o bin/queue $(SRC_DIR)/data_structure/queue.c

deque:
	$(CC) -o bin/deque $(SRC_DIR)/data_structure/deque.c

heap:
	$(CC) -o bin/heap $(SRC_DIR)/data_structure/heap.c

clean:
	rm -f bin/*