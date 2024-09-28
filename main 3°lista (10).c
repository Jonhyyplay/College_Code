#include <stdio.h>
int main(){
    int ANTERIOR=1, ATUAL=0, PROXIMO=1;
    
    for(int i=0; i<=15; i++){
        printf("\n%d ", PROXIMO);
        PROXIMO = ATUAL + ANTERIOR;
        ATUAL = ANTERIOR;
        ANTERIOR = PROXIMO;
    }   
    return 0;
}