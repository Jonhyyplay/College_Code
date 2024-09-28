#include <stdio.h>
int main(){
    int i, F; 

        printf("Fatorial dos impares entre 1 e 10:\n");
        F = 1;  
        
        for (i = 1; i <= 10; i++) {
         
         F *= i;
         
         if (i % 2 == 0){
            continue;
        }
           printf ("\nFatorial de %d: %d\n",i, F);
        }
    
    
    return 0;
}




       