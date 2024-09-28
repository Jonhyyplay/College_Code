#include <stdio.h>
int main(){
    int Qdr;
    unsigned long long Gr_at = 1, Sm_Total = 0; //Se os valores forem apenas positivos e em faixas de valores altos.
    
    
    for( Qdr=1; Qdr<=64; Qdr++){
        
        printf("\n\nQuadrado atual: %d", Qdr);
        printf("\nGraos no quadrado atual: %llu",Gr_at);
        
        Sm_Total += Gr_at;
        Gr_at *= 2; 

        printf("\n\nSoma total de graos atual: %llu", Sm_Total);
    }
    return 0;
}