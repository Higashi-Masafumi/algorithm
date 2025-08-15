# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "../../include/utils.h"

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    generate_two_random_numbers(&a, &b);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int result = gcd(a, b);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
    printf("a: %d, b: %d\n", a, b);
    printf("GCD: %d\n", result);

    return 0;
}