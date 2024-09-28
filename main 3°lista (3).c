#include <stdio.h>
int main(){
 float N, i;
 

printf ("Escolha um valor: ");
scanf ("%f", &N);

printf ("\nTabuada de %.0f:\n", N);

for (i=1; i<=10; i++){
printf ("%.0f + %.0f = %.0f\n", N, i, N+i);
}

for (i=1; i<=10; i++){
printf ("%.0f - %.0f = %.0f\n", N, i, N-i);
}

for (i=1; i<=10; i++){
printf ("%.0f x %.0f = %.0f\n", N, i, N*i);
}

for (i=1; i<=10; i++){
printf ("%.0f / %.0f = %.1f\n", N, i, N/i);
}


   return 0;
}