#include <stdio.h>

int main() {
    int E, R = 1;

    for (E = 0; E <= 15; E++) {
        printf("\n%d ", R);
        R *= 3;
    }

    return 0;
}