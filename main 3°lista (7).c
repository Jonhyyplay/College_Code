#include <stdio.h>

int main() {
    int N = 1;

    while (N < 200) {
        if (N % 4 == 0) {
            printf("%d\n", N);
        }
        N++;
    }

    return 0;
}