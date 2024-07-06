// Toda a estrutura organizada desse código foi inspirada pela usada por Erick Vinícius. Créditos à ele por me ajudar a fazê-la!

#include <stdio.h>
#include <math.h>

int lerInteiro(const char* mensagem){
    int valorInserido;
    char c;

    printf("%s", mensagem);
    while (1) {  
        if (scanf("%d", &valorInserido) == 1) {
           
            c = getchar();
            if (c == '\n' || c == EOF) {
                return valorInserido;
            } else {
                // Limpa o buffer até o fim da linha se a entrada não for um inteiro
                printf("Entrada Inválida. Digite somente valores inteiros: ");
                while ((c = getchar()) != '\n' && c != EOF);
                printf("%s", mensagem);
            }
        } else {
            
            printf("Entrada Inválida. Digite somente valores inteiros: ");
            while ((c = getchar()) != '\n' && c != EOF);
            printf("%s", mensagem);
        }
    }
}
float lerFloat(const char* mensagem){ 
    float valor; 
    printf("%s", mensagem); 
    while(scanf("%f", &valor) != 1){
        printf("Entrada invalida, por favor digite um numero\n");
        while(getchar() != '\n'); 
        printf("%s", mensagem);
    }
    return valor; 
}


void questaoA(){
    
    char nomes[10][50]; 
    char start[100];

    printf ("Digite qualquer tecla para iniciar: ");
    scanf ("%s", start);
    
    for (int i = 0; i < 10; i++) {
        printf("Digite o nome da pessoa %d: ", i+1);
        scanf("%s", nomes[i]);
    }

    
    printf("\nNomes digitados:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\n", nomes[i]);
    }
}

void questaoB(){


    int A[8];
    int B[8];
    char start[100];

    printf ("Digite qualquer tecla para iniciar: ");
    scanf ("%s", start);
    
    for (int i = 0; i < 8; i++) {
        printf("Digite o valor %d da Matriz A: ", i + 1);
        scanf("%d", &A[i]);
        B[i] = A[i] * 3;
    }

    for (int i = 0; i < 8; i++) {
        printf ("\nMatriz A: %d", A[i]);
    }

        for (int i = 0; i < 8; i++) {
        printf ("\nMatriz B: %d", B[i]);
    }
}

void questaoC(){

    int A[20];
    int B[20];
    int C[20];
    char start[100];
    
    printf ("Digite qualquer tecla para iniciar: ");
    scanf ("%s", start);

    for (int i = 0; i < 20; i++) {
        printf("Digite o valor %d da Matriz A: ", i + 1);
        scanf("%d", &A[i]);
    }
    
    for (int i = 0; i < 20; i++){
        printf("Digite o valor %d da Matriz B: ", i + 1);
        scanf("%d", &B[i]);

         C[i] = A[i] - B[i];
    }
         
    for (int i = 1; i <= 20; i++){
        printf ("\nMatriz A: %d", A[i]);
    }
    
    for (int i = 1; i <= 20; i++) {
        printf ("\nMatriz B: %d", B[i]);
    }
    
    for (int i = 1; i <= 20; i++) {
        printf ("\nMatriz C: %d", C[i]);
    }
}

void questaoD(){

    int A[15];
    double B[15];
    char start[100];

    printf ("Digite qualquer tecla para iniciar: ");
    scanf ("%s", start);
    
    for (int i = 0; i < 15; i++) {
        printf("Digite o valor %d da Matriz A: ", i + 1);
        scanf("%d", &A[i]);
        B[i] = pow(A[i],2);
    }

    
    for (int i = 0; i < 15; i++){
        printf ("\nMatriz A: %d", A[i]);
    }

    for (int i = 0; i < 15; i++) {
        printf ("\n Matriz B: %.0f", B[i]);        
    }
}

void questaoE(){

    int A[15];
    unsigned long long B[15];
    char start[100];
    
    printf ("Digite qualquer tecla para iniciar: ");
    scanf ("%s", start);

    for (int i = 0; i < 15; i++) {
    
        B[i] = 1;
        
        printf("Digite o valor %d da Matriz A: ", i + 1);
        scanf("%d", &A[i]);
    
        for (int j = 1; j <= A[i]; j++){
            B[i] *= j;
        }
    }

    for (int i = 0; i < 15; i++){
        printf ("\nMatriz A: %d", A[i]);
    }
   
    for (int i = 0; i < 15; i++) {
        printf ("\nMartriz B: %llu", B[i]);
    }
}

void questaoF(){

    int A[15];
    int B[15];
    int C[30];
    char start[100];
        
    printf ("Digite qualquer tecla para iniciar: ");
    scanf ("%s", start);

    for (int i = 0; i < 15; i++) {
        printf("Digite o valor %d da Matriz A: ", i + 1);
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 15; i++) {
        printf("Digite o valor %d da Matriz B: ", i + 1);
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < 15; i++){
        C[i] = A[i];
        C[i + 15] = B[i];
    }

    for (int i = 0; i < 15; i++){
        printf ("\nMatriz A: %d", A[i]);
    }
    
    for (int i = 0; i < 15; i++){
        printf ("\nMatriz B: %d", B[i]);
    }
    
    for (int i = 0; i < 30; i++){
        printf ("\n\nMatriz C: %d", C[i]);
    }
}

void questaoG(){

    char A[20][100];
    char B[30][100];
    char C[50][100];
    char start[100];
        
    printf ("Digite qualquer tecla para iniciar: ");
    scanf ("%s", start);

    for (int i = 0; i < 20; i++){
        printf("Digite o nome %d da Matriz A: ", i + 1); 
        scanf("%s", A[i]); 
    }
    for (int i = 0; i < 30; i++){
        printf("Digite o nome %d da Matriz B : ", i + 1); 
        scanf("%s", B[i]);
    }

    int iterador = 0;
    for (int i = 0; i < 20; i++) {
        int cont = 0;
        
        for (; A[i][cont] != '\0'; cont++) {
            C[iterador][cont] = A[i][cont];
        }
        C[iterador][cont] = '\0';
        iterador++;
    }
    
    for (int i = 0; i < 30; i++) {
        int cont = 0; 
        for (; B[i][cont] != '\0'; cont++) {
            C[iterador][cont] = B[i][cont];
        }
        C[iterador][cont] = '\0';
        iterador++;
    }

    for (int i = 0; i < 50; i++){
        printf("\nMatrizC[%d] = %s ", i, C[i]);
    }
}

void questaoH(){

    float A[20];
    float B[20];
    char start[100];
    
    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);

    for (int i = 0; i < 20; i++){
        printf("\nDigite o valor %d da Matriz A: ", i + 1); 
        scanf("%f", &A[i]); 
    }
     for (int i = 0; i < 20; i++){
        B[i] = A[19 - i];
    }
    for (int i = 0; i < 20; i++){
        printf ("\nMatriz A: %.1f", A[i]);
    }
    for (int i = 0; i < 20; i++){
        printf ("\nMatriz B: %.1f", B[i]);
    }
}

void questaoI(){

    float A[5];
    float B[5];
    float C[5];
    float D[15];
    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);
    
    for (int i = 0; i < 5; i++) {
        printf ("Digite o valor %d para a Matriz A: ", i + 1);
        scanf("%f", &A[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf ("Digite o valor para a Matriz B: ");
        scanf ("%f", &B[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf ("Digite o valor %d para a Matriz C: ", i + 1);
        scanf("%f", &C[i]);
    }

    int dIndex = 0;
    for (int i = 0; i < 5; i++) {
        D[dIndex++] = A[i];
        D[dIndex++] = B[i];
        D[dIndex++] = C[i];
    }
    
    for (int i = 0; i < 15; i++) {
        printf("\nMatriz D: %.2f", D[i]);
    }
}

void questaoJ(){

    int A[20];
    int B[20]; 

    char start[100];

        printf("Digite qualquer tecla para iniciar: ");
        scanf("%s", start);

    for (int i = 0; i < 20; i++){
        B[i] = 0;
        
        printf ("\nDigite o valor %d para a Matriz A: ", i + 1);
        scanf ("%d", &A[i]);
        
        for (int cont = 1; cont <= A[i]; cont++){
            B[i] += cont;
        }
    }

    for (int i= 0; i < 20; i++){
        printf("\nMatriz B: %d ", B[i]);
    }

}

void questaoK(){

    int A[10];
    int B[10]; 
    
    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    
    scanf("%s", start);
    for (int i=0; i < 10; i++){
        printf ("\nDigite o valor %d da Matriz A: ", i + 1);
        scanf ("%d", &A[i]);
        
        if (A[i] >= 0){ 
        
        B[i] = -(A[i]);
        }
    }

    for (int i=0; i<10; i++) {
        printf("\nMatriz B: %d", B[i]);
    }

}

void questaoL(){

    float A[10], B[10];
    
    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    
    scanf("%s", start);

    for (int i=0; i < 10; i++){
        printf ("\nDigite o valor %d na Matriz A: ", i + 1);
        scanf ("%f", &A[i]);

        B[i] = A[i]/2;
    }
                
    for (int i=0; i < 10; i++){
        printf("\nMatriz A: %.1f", A[i]);
    }

    for (int i=0; i < 10; i++){
        printf("\n\nMatriz B: %.1f", B[i]);
    }
}

void questaoM(){
    
    int valor;
    int A[10];
    
    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    
    scanf("%s", start);

    printf("Digite um valor: ");
    scanf("%d", &valor);

    for (int i = 0; i < 10; i++) {
        A[i] = valor * (i + 1);
    }

    printf("\nTabuada do valor %d:\n", valor);
    for (int i = 0; i < 10; i++) {
        printf("%d x %d = %d\n", valor, i + 1, A[i]);
    }
}

void questaoN(){

    float A[20], maior, menor, Sm = 0, Md;

    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);

    for (int i = 0; i < 20; i++) {
        printf("Para o valor %d, digite uma Temperatura em Celsius: ", i + 1);
        scanf("%f", &A[i]);

        Sm += A[i];
    }

    Md = Sm / 20;
    maior = menor = A[0];

    for (int i = 1; i < 20; i++) {
        if (A[i] > maior) {
            maior = A[i];
        }
        if (A[i] < menor) {
            menor = A[i];
        }
    }

    printf("\nMenor valor: %.1f", menor);
    printf("\nMaior valor: %.1f", maior);
    printf("\nMedia das Temperaturas: %.2f", Md);
    }

void questaoO(){

    float A[25], B[25];
    char start[100];

    printf ("Digite qualquer tecla para iniciar: ");
    scanf ("%s", start);
    
    for (int i = 0; i < 25; i++) {
        printf("Digite a temperatura %d em Celsius da Matriz A: ", i + 1);
        scanf("%f", &A[i]);
        B[i] = (A[i] * 1.8) + 32;
    }

    
    for (int i = 0; i < 25; i++){
        printf ("\nMatriz A (Graus Celsius): %.2f", A[i]);
    }
    
    for (int i = 0; i < 25; i++) {
        printf ("\nMatriz B(Graus Fahrenheit): %.2f", B[i]);
    }
}

void questaoP(){

        int A[12];
        int B[12];
        char start[100];

        printf ("Digite qualquer tecla para iniciar: ");
        scanf ("%s", start);
        
        for (int i = 0; i < 12; i++) {
            printf("Digite o valor %d da Matriz A: ", i + 1);
            scanf("%d", &A[i]);
            if (A[i] % 2 == 1) {
                B[i] = A[i] * 2;
            } else {
                B[i] = A[i];
            }
        }
        
        for (int i = 0; i < 12; i++){
            printf ("\nMatriz A: %d", A[i]);
        }
        
        for (int i = 0; i < 12; i++) {
            printf ("\nMatriz B: %d", B[i]);
        }
    }

void questaoQ(){

    int A[15];
    float B[15];
    char start[100];

    printf ("Digite qualquer tecla para iniciar: ");
    scanf ("%s", start);
    
    for (int i = 0; i < 15; i++) {
        
        printf("Digite o valor %d da Matriz A: ", i + 1);
        scanf("%d", &A[i]);
        
        if (A[i] % 2 == 0) {
        B[i] = A[i] / 2;
        } else {
        B[i] = A[i] * 1.5;
        }
    }
    
    for (int i = 0; i < 15; i++){
        printf ("\nMatriz A: %d", A[i]);
    }
    
    for (int i = 0; i < 15; i++) {
        printf ("\nMatriz B: %.1f", B[i]);
    }
}

void questaoR(){

    int A[6], B[6], C[6], D[6];
    char start[100];
    int j = 0, k = 0; 

    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);

    for (int i = 0; i < 6; i++) {
        printf("Digite o valor %d da Matriz A: ", i + 1);
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 6; i++) {
        printf("Digite o valor %d da Matriz B: ", i + 1);
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0) { 
            D[k++] = A[i];
            if (k < 6) { 
                D[k++] = B[i];
            }
        } else { 
            C[j++] = A[i];
            if (j < 6) { 
                C[j++] = B[i];
            }
        }
    }
    
    for (int i = 0; i < j; i++) {
        printf("\nMatriz C: %d", C[i]);
    }
    
    for (int i = 0; i < k; i++) {
        printf("\nMatriz D: %d", D[i]);
    }
    printf("\n");
}

void questaoS(){

    int A[6];
    int B[6];
    int C[12];
    int vlrs_A_B = 0;
   
    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);
     
     for (int i = 0; i < 6; i++){
        printf("Digite o valor %d na Matriz A (vai ser aceito apenas valores pares: ", i + 1);
        scanf("%d", &A[i]);
        if (A[i] % 2 == 0){
            C[vlrs_A_B++] = A[i];
        } else {
            printf("\nValor invalidado! Digite novamente: ");
            i--;
        }
    }

    for (int i = 0; i < 6; i++){
        printf("Digite o valor %d na Matriz B (vai ser aceito apenas valores impares: ", i + 1);
        scanf("%d", &B[i]);
        if (B[i] % 2 == 1){
            C[vlrs_A_B++] = B[i];
        } else {
            printf("\nValor invalidado! Digite novamente: ");
            i--;
        }
    }

    printf("\nMatriz C: \n");
    for (int i = 0; i < vlrs_A_B; i++){
        printf("%d ", C[i]);
    }
}

void questaoT(){
    int A[10];
    int B[10];
    int C[20];
    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);

    int vlrs_A_B = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite valores na Matriz A (vai ser aceito apenas os divisiveis por 2 e 3): ");
        scanf("%d", &A[i]);
        if (A[i] % 2 == 0 && A[i] % 3 == 0) {
            C[vlrs_A_B++] = A[i];
        } else {
            printf("\nValor inválido! Digite novamente: ");
            i--;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("Digite na Matriz B (vai ser aceito apenas os multiplos de 5): ");
        scanf("%d", &B[i]);
        if (B[i] % 5 == 0) {
            C[vlrs_A_B++] = B[i];
        } else {
            printf("\nValor inválido! Digite novamente: ");
            i--;
        }
    }

    printf("\nMatriz C:\n");
    for (int i = 0; i < vlrs_A_B; i++) {
        printf("%d ", C[i]);
    }
}

void questaoU(){

    int A[12];
    int B[12];
    int C[24];
    int iC = 0;
    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);

    for (int i = 0; i < 12; i++) {
        
        printf("\nDigite o valor %d da Matriz A: ", i + 1);
        scanf("%d", &A[i]);

        if (A[i] % 2 == 0 || A[i] % 3 == 0) {
            C[iC] = A[i];
            printf("\nC: [%d] (%d)", iC, C[iC]);
            iC++;
            } else{
                printf("\nValor invalidado! Digite novamente: ");
                i--;
        }
        
    }

        for (int i = 0; i < 12; i++) {
        printf("\nDigite o valor %d da Matriz B: ", i + 1);
        scanf("%d", &B[i]);

        if (B[i] % 5 != 0) {
            C[iC] = B[i];
            printf("\nC: [%d] (%d)", iC, C[iC]);
            iC++;
        } else {
            printf("\nValor invalidado! Digite novamente: ");
            i--;
        }
    }
            for (int i = 0; i < iC; i++) {
            printf ("\nMatriz C: %d", C[i]);
    }
}       

void questaoV(){

int A[30];
  int NPar[30];
  int NImpar[30];
  int iPar = 0;
  int iImpar = 0;
  char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);

  for(int i = 0; i < 30; i++){
  printf("\nDigite o valor %d da Matriz A: ", i+1);
  scanf("%d", &A[i]);

    if (A[i] % 2 == 0) {
      NPar[iPar] = A[i];
      iPar++;
    
    }else{
      NImpar[iImpar] = A[i];
      iImpar++;
    
    }
  }
  printf("\n\nNumeros Pares:\n");
  
  for(int i = 0; i < iPar; i++){
  printf("\nMatriz A: (%d)", NPar[i]);
  }

  printf("\n\nNumeros Impares:\n");
  
  for(int i = 0; i <iImpar ; i++){
  printf("\nMatriz A: (%d)", NImpar[i]);
  } 
}

void questaoW(){

    int A[10];
    int B[10];
    int C[10];
    int quadrado = 0;
    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);
    
    for(int i = 0; i < 10; i++){
    printf("\nDigite o valor %d da Matriz A: ", i+1);
    scanf("%d", &A[i]);
    }
    
    for(int i = 0; i < 10; i++){
    printf("\nDigite o valor %d da Matriz B: ", i+1);
    scanf("%d", &B[i]);
    }
  
     for(int i = 0; i < 10; i++){
     quadrado = A[i] + B[i];
     C[i] = quadrado * quadrado;
    }

    printf ("\nMatriz C: ");
    for (int i = 0; i < 10; i++) {
    printf("%d ", C[i]);
}


}

void questaoX(){

    float A[6];
    float B[6];
    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);
    
    
        for (int i = 0; i < 6; i++) {
            
        printf("Digite o elemento %d da Matriz A: ", i + 1);
        scanf("%f", &A[i]);
        }

    
        for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) {
                B[i] = A[i + 1];
            } else {
                B[i] = A[i - 1];
            }
        }

        printf("\nMatriz A:\n");
    for (int i = 0; i < 6; i++) {
        printf("%.2f ", A[i]);
    }

    printf("\n\nMatriz B:\n");
    for (int i = 0; i < 6; i++) {
        printf("%.2f ", B[i]);
    }
}

void questaoY(){

    int N[10];
    float NPar[10];
    int j = 0;
    char start[100];

        printf("Digite qualquer tecla para iniciar: ");
        scanf("%s", start);

    for (int i = 0; i < 10; i++) {
        printf("\nDigite o valor %d da Matriz A: ", i + 1);
        scanf("%d", &N[i]);
        
        if (((int)N[i]) % 2 == 0) {
        NPar[j] = N[i];
        j++;
        }
    }

        printf("\n\nValores pares presentes: %d", j);

    for (int i = 0; i < j; i++) {
        printf("\nQuais sao eles? %.1f", NPar[i]);
    }
}

void questaoZ(){

    int A[10];
    int NImpar = 0;
    float prct = 0;
    char start[100];

    printf("Digite qualquer tecla para iniciar: ");
    scanf("%s", start);

    for (int i = 0; i < 10; i++) {
        printf("\nDigite o valor %d da Matriz A: ", i + 1);
        scanf("%d", &A[i]);

        if (A[i] % 2 == 1) {
            NImpar++;
        }
    }

    prct = (float)NImpar / 10 * 100;

    printf("\nTotal de elementos impares: %d", NImpar);
    printf("\n\nPercentual de valores impares: %.2f%%", prct);
}


void menu() {
    printf("\nEscolha a questao que deseja ver a seguir: \n");

    printf("\n(a) Leitura de dez nomes e apresentacao");
    printf("\n(b) Leitura de oito elementos, multiplicacao por 3 e apresentacao");
    printf("\n(c) Subtracao de duas matrizes de 20 elementos e apresentacao");
    printf("\n(d) Quadrado dos elementos de uma matriz de 15 elementos e apresentacao");
    printf("\n(e) Fatorial dos elementos de uma matriz de 15 elementos e apresentacao");
    printf("\n(f) Juncao de duas matrizes de 15 elementos e apresentacao");
    printf("\n(g) Juncao de duas matrizes de nomes e apresentacao");
    printf("\n(h) Inversao de uma matriz de 20 elementos e apresentacao");
    printf("\n(i) Juncao de tres matrizes de 5 elementos e apresentacao");
    printf("\n(j) Somatorio de elementos de uma matriz de 20 elementos e apresentacao");
    printf("\n(k) Valor negativo dos elementos de uma matriz de 10 elementos e apresentacao");
    printf("\n(l) Metade exata dos elementos de uma matriz de 10 elementos e apresentacao");
    printf("\n(m) Calculo da tabuada de um valor de 1 a 10 e apresentacao");
    printf("\n(n) Leitura de 20 temperaturas, menor, maior e media");
    printf("\n(o) Conversao de temperaturas de Celsius para Fahrenheit e apresentacao");
    printf("\n(p) Multiplicacao dos elementos impares por 2 em uma matriz de 12 elementos");
    printf("\n(q) Divisao por 2 dos elementos de indice par de uma matriz de 15 elementos");
    printf("\n(r) Elementos impares e pares de duas matrizes de 6 elementos");
    printf("\n(s) Juncao de duas matrizes de 6 elementos pares e impares");
    printf("\n(t) Juncao de duas matrizes de 10 elementos divisiveis por 2, 3 e multiplos de 5");
    printf("\n(u) Juncao de duas matrizes de 12 elementos divisiveis por 2, 3 e nao multiplos de 5");
    printf("\n(v) Quantidade de pares e impares em uma matriz de 30 elementos");
    printf("\n(w) Quadrado da soma dos elementos de duas matrizes de 10 elementos");
    printf("\n(x) Atribuicao de elementos pares e impares de uma matriz de 6 elementos");
    printf("\n(y) Total de elementos pares em uma matriz de 15 elementos");
    printf("\n(z) Total e percentual de elementos impares em uma matriz de 10 elementos");

    printf("\n\nDigite apenas a letra da questao: ");

}
// Menu, onde se encontra todo os textos das questões

//*********************************************************

void limparTela() { 
    for (int i = 0; i < 200; i++) {
        printf("\n");
    }
}
// Uma forma de 'limpar' a tela, uma vez que outros sistemas operacionais não consigam 
// rodar alguns comandos como system('cls') no Linux.

//*********************************************************
void lerQuestao(char escolha){
     
     switch (escolha) {
            case 'a': questaoA();break;
            case 'b': questaoB();break;
            case 'c': questaoC();break;
            case 'd': questaoD();break;
            case 'e': questaoE();break; 
            case 'f': questaoF();break;
            case 'g': questaoG();break;
            case 'h': questaoH();break;
            case 'i': questaoI();break;
            case 'j': questaoJ();break;
            case 'k': questaoK();break;
            case 'l': questaoL();break;
            case 'm': questaoM();break;
            case 'n': questaoN();break;
            case 'o': questaoO();break;
            case 'p': questaoP();break;
            case 'q': questaoQ();break;
            case 'r': questaoR();break;
            case 's': questaoS();break;
            case 't': questaoT();break;
            case 'u': questaoU();break;
            case 'v': questaoV();break;
            case 'w': questaoW();break;
            case 'x': questaoX();break;
            case 'y': questaoY();break;
            case 'z': questaoZ();break;
        default:
            printf("\nValor invalido, por favor insira uma letra minuscula de (a) a (t): ");
            break;
        }
}
// Optei por separar dessa vez as questões, para que assim o código fique mais limpo e facilitei algumas iterações e utilizações futuras

void page(){
    char escolha;
    int loop=1;
    int voltar;
    int validacao;
    menu();

      do{
        scanf(" %c", &escolha);
        while (getchar() != '\n'); // limpa o buffer de entrada

        validacao = (escolha >= 'a' && escolha <= 'z');
        
        if (validacao){ 
            do{
                    limparTela();
                    lerQuestao(escolha);
                    int voltarValido = 1;
                    printf("\n\nDeseja voltar ao Menu? (1)-Sim/ (0)-Nao. /\nPara repetir a questao, aperte (2) \n: ");
                    do{
                        voltar = lerInteiro("");
                        if (voltar == 1 || voltar == 0 || voltar == 2 ){
                            voltarValido = 0; 
                        } else{
                            printf("\nDigito inválido: ");
                            voltarValido = 1; 
                        }
                    }while(voltarValido);

                    if (voltar == 2){
                        limparTela();
                    }else if (voltar == 1){
                        limparTela();
                        menu();
                        break;
                    }else if (voltar==0){
                        limparTela();
                        printf("\nFinalizando o programa...Obrigado pela disponibilidade!");
                        loop = 0; 
                        break;
                    }
                }while(voltar==2);

            }else{
                printf("\nValor invalido, por favor insira uma letra minuscula de (a) a (z): ");
            }
                //Toda a funcionalidade do mini-programa se encontra aqui. :)
        }while(loop);
}

// Aqui é onde está todo o funcionamento do código em relação à ir para uma questão, voltar, repetir e finalizar o programa. 
//*********************************************************

int main(){
    page();
    return 0;
}
// Obrigado por vir aqui
// assinado por: Jonathan C. M. Júnior (Jonhyyplay)