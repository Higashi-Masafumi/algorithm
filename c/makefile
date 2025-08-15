CC = gcc
CFLAGS = -I$(INCLUDE_DIR)
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib

# Create directories
$(shell mkdir -p bin lib)

# Build libraries directly
libs:
	$(CC) $(CFLAGS) -c $(SRC_DIR)/data_structure/heap.c -o heap.o
	ar rcs $(LIB_DIR)/libheap.a heap.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/utils/random_sequence.c -o utils.o
	ar rcs $(LIB_DIR)/libutils.a utils.o
	rm -f *.o

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

binary_search:
	$(CC) -o bin/binary_search $(SRC_DIR)/search/binary_search.c $(SRC_DIR)/utils/random_sequence.c

binary_tree:
	$(CC) -o bin/binary_tree $(SRC_DIR)/search/binary_tree.c $(SRC_DIR)/utils/random_sequence.c

treap:
	$(CC) -o bin/treap $(SRC_DIR)/search/treap.c $(SRC_DIR)/utils/random_sequence.c

insertion_sort:
	$(CC) -o bin/insertion_sort $(SRC_DIR)/sort/insertion_sort.c $(SRC_DIR)/utils/random_sequence.c

binary_insertion_sort:
	$(CC) -o bin/binary_insertion_sort $(SRC_DIR)/sort/binary_insertion_sort.c $(SRC_DIR)/utils/random_sequence.c

bubble_sort:
	$(CC) -o bin/bubble_sort $(SRC_DIR)/sort/bubble_sort.c $(SRC_DIR)/utils/random_sequence.c

quick_sort:
	$(CC) -o bin/quick_sort $(SRC_DIR)/sort/quick_sort.c $(SRC_DIR)/utils/random_sequence.c

merge_sort:
	$(CC) -o bin/merge_sort $(SRC_DIR)/sort/merge_sort.c $(SRC_DIR)/utils/random_sequence.c

heap_sort: libs
	$(CC) $(CFLAGS) -o bin/heap_sort $(SRC_DIR)/sort/heap_sort.c -L$(LIB_DIR) -lheap -lutils

kmp:
	$(CC) -o bin/kmp $(SRC_DIR)/string_search/kmp.c $(SRC_DIR)/utils/random_sequence.c

rolling_hash:
	$(CC) -o bin/rolling_hash $(SRC_DIR)/string_search/rolling_hash.c $(SRC_DIR)/utils/random_sequence.c

clean:
	rm -f bin/* lib/*

.PHONY: libs clean