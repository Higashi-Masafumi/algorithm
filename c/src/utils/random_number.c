#include <stdlib.h>
#include <time.h>

int random_number() {
    srand(time(NULL));
    return rand() % 1000 + 1;
}