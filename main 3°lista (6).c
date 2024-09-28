#include <stdio.h>
int main(){

int N=0, Nimpar=1;

 printf ("Vinte primeiros impares inteiros:\n");

  for (N=0; N<=20; N++){
    Nimpar = N % 2;
if (Nimpar == 1){
 
 printf ("%d\n", N);
} else {
  continue;
 }
  }
    return 0;
}