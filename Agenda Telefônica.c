#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct contato{
    char nome[51];
    char telefone[15];
    char email[250];
}contato;

#define LIMITE 50
#define FILE_NAME "contatos.ccf"

struct contato contatos[LIMITE];
int contador = 0;

void carregarContato(){

    FILE *arquivo = fopen(FILE_NAME, "r");
    contador = 0;

    if (arquivo != NULL){
        rewind(arquivo);
        
        while(!feof(arquivo)){
            fgets(contatos[contador].nome, 50, arquivo);
            if(strcmp(contatos[contador].nome, "") > 0){
                fgets(contatos[contador].telefone, 15, arquivo);
                fgets(contatos[contador].email, 250, arquivo);
                contador++;
            }
        }
    }else {
        printf ("Erro ao carregar os contatos!\n");
    }

    fclose(arquivo);
    }

void salvarContato(struct contato ctt, FILE *arquivo){
    fputs(ctt.nome, arquivo);
    fputs(ctt.telefone, arquivo);
    fputs(ctt.email, arquivo);
}

bool reescreverArquivo(int ignore){
    bool r = false;
    struct contato temp[LIMITE];
    int n = 0;

    remove(FILE_NAME);
    FILE *arquivo = fopen(FILE_NAME, "a+");

    if (arquivo != NULL){    //caso erro, verificar aqui
        for (int i = 0; i < contador; i++){
            if (i != ignore){
                salvarContato(contatos[i], arquivo);
                temp[n] = contatos[i];
                n++;
            }
        }

        for(int i = 0; i < n; i++){
            contatos[i] = temp[i];
        }
        contador = n;
        r = true;
    }

    fclose(arquivo);
    
    return r;
}

bool inserirContato(struct contato ctt){
    
    bool r = false;
    FILE *arquivo = fopen(FILE_NAME, "a+");

    if (arquivo != NULL){
        r = true;

        salvarContato(ctt, arquivo);
        contatos[contador] = ctt;
        contador++;
    }

    fclose(arquivo);

    return r;
}

void adicionarContato(){

    if(contador < LIMITE){
        printf ("\nadicionar Contato\n");

        struct contato ctt;

        printf ("Digite o nome: ");
        fgets(ctt.nome, 50, stdin);
        fflush(stdin);

        printf ("Digite o telefone: ");
        fgets(ctt.telefone, 15, stdin);
        fflush(stdin);

        printf ("Digite o E-mail: ");
        fgets(ctt.email, 250, stdin);
        fflush(stdin);


        if (inserirContato(ctt)){
        printf ("\nContato adicionado com sucesso!\n"); 
        } else{
        printf ("\nErro ao adicionar contato!\n");
        }
    }else{
        printf ("\nLimite de contatos atingido!\n");
    
    }
}

void editarContato(int i){

    struct contato ctt; 

//Na edição do contato desejado, caso não queira mudar alguma informação, basta apertar enter   
    printf ("\nEDITAR CONTATO\n\n");
    printf ("%s", contatos[i].nome);
    fgets (ctt.nome, 50, stdin);
    fflush(stdin);

    if(strlen(ctt.nome) > 1){
        strcpy(contatos[i].nome, ctt.nome); 
    }

    printf ("%s", contatos[i].telefone);
    fgets (ctt.telefone, 15, stdin);
    fflush(stdin);

    if(strlen(ctt.telefone) > 1){
        strcpy(contatos[i].telefone, ctt.telefone);
    }

    printf ("%s", contatos[i].email);
    fgets (ctt.email, 250, stdin);
    fflush(stdin);

    if(strlen(ctt.email) > 1){
        strcpy(contatos[i].email, ctt.email);
    }

    if(reescreverArquivo(-1)){
        printf ("\nContato editado com sucesso!\n\n");
    }else{
        printf ("\nErro ao atualizar contato!\n\n");
    }
}

bool confirme(char *mensagem){
    char r;

    printf ("%s S para SIM ou N para NAO\n", mensagem);
    scanf ("%c", &r);

    if(r == 's' || r == 'S'){
        return true;
    }else{
        return false;
    }
}

void excluirContato(int i){

    if(confirme("\nDeseja realmente excluir este contato?\n")){
        reescreverArquivo(i);
        printf ("\nContato excluido com sucesso!\n\n");
    }
}

void menuSelecao(){
    int selecionado = -1;
    int op = 0;

    printf ("Informe o codigo do contato | 0 - Voltar ao menu: ");
    scanf ("%i", &selecionado);
    fflush(stdin);

    if(selecionado > 0){
        if(selecionado <= LIMITE){
            selecionado--;
            printf ("\nContato selecionado: %s", contatos[selecionado].nome);
            printf ("1 - Editar\n");
            printf ("2 - Excluir\n");
            printf ("Qualquer outra tecla - Sair\n");

            scanf ("%i", &op);
            fflush(stdin);

            
            switch(op){
                case 1: 
                    editarContato(selecionado);
                    break;
                case 2: 
                    excluirContato(selecionado);
                    break;
            }
        }else{
            printf ("\nContato inexistente!\n\n");
        }
    }
}

void mostrarContatos(int i){
    printf ("[%i]\n", i+1);
    printf ("%s", contatos[i].nome);
    printf ("%s", contatos[i].telefone);
    printf ("%s", contatos[i].email);
}

void listarContatos(){
    printf ("\nLISTA DE CONTATOS\n\n");

    for (int i = 0; i < contador; i++){
        mostrarContatos(i);
        printf ("-----------------------\n");
    }

    if(contador > 0)
        menuSelecao();
}

bool corresponderContato (char *a, char *b, int i, int limite){
    if(a[i] == b[i]){
        i++;
        if(i < limite){
            return corresponderContato(a, b, i, limite);

        }else{
            return true;
        }

    }else{
        return false;
    }
}

void buscarContato(){
    char nome[51] = {""};
    bool encontrar = false;
    
    printf ("\nBUSCAR CONTATO\n\n");
    printf ("Digite o nome do contato a ser buscado: ");
    fgets(nome, 50, stdin);
    fflush(stdin);

    size_t limite = strlen(nome);
    limite--;

    printf ("\nRESULTADO\n\n");
    for( int i = 0; i < contador; i++){
        if(strlen(contatos[i].nome) >= limite){
            if(corresponderContato(nome, contatos[i].nome, 0, limite)){
                mostrarContatos(i);
                printf ("-----------------------\n");
                encontrar = true;
            }
        }
    }

    if(encontrar){
        menuSelecao();
    }
}

void menuDefaut(){
    int op = 0;
    while(op != 9){
      printf ("\nO que deseja fazer?\n\n");
      printf ("1 - Adicionar contato\n");
      printf ("2 - Listar contatos\n");
      printf ("3 - Buscar contato\n");
      printf ("9 - Sair\n");

        scanf("%i", &op);
        fflush(stdin);

        if (op != 9){
            switch(op){
                case 1:
                    adicionarContato();
                    break;
                case 2:
                    listarContatos();
                    break;
                case 3:
                    buscarContato();
                    break;
                default:
                    printf ("Opcao invalida!\n");
            }
        } else{
            printf ("\nFim!\n");
        }
    }
}

int main(){
    carregarContato();
    menuDefaut();



    return 0;
}

