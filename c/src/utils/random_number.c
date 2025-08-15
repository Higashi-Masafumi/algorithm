#include <stdlib.h>
#include <time.h>

int random_number() {
    srand(time(0));
    return rand() % 1000 + 1;
}