#include <stdio.h>
int main(){
 
  for (int G = 10; G<=100; G+=10){
    float F = G * 1.8 + 32;

    printf ("\n\nTemperatura em Celsius: %d", G);
    printf ("\nTemperatura em Fahrenheit: %.1f", F);
 }

    return 0;
}