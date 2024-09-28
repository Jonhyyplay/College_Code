#include <stdio.h>

int main() {
    int dividendo, divisor, quociente = 0;

    printf("Digite o dividendo: ");
    scanf("%d", &dividendo);

    printf("Digite o divisor: ");
    scanf("%d", &divisor);

    while (dividendo >= divisor) {
        dividendo -= divisor;
        quociente++;
    }

    printf("O quociente da divisao vai ser: %d\n", quociente);

    return 0;
}