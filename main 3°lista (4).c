#include <stdio.h>
int main(){
 int soma=0, N=0;

 printf ("Soma dos cem primeiros inteiros:\n");

  for (N=1; N<=100; N++){
   
   printf ("%d+", N);
   soma += N;
}
    printf ("\n\nSoma = %d\n", soma);

    return 0;
}