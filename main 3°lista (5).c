#include <stdio.h>
#include <math.h>
int main(){

int soma=0, N=0, Npar=2;

 printf ("Soma dos quinhentos primeiros pares inteiros:\n");

  for (N=1; N<=500; N++){
   Npar = N%2;
if (Npar == 0){

   printf ("%d+", N);
   soma += N;
}
    printf ("\nSoma = %d\n", soma);
}
    return 0;
}