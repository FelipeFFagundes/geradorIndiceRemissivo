#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>

/* O nome oficial deste programa */
#define PROGRAM_NAME "IndiceRemissivo"

#define AUTHORS proper_name ("Arthur Viegas")
#define AUTHORS proper_name ("Felipe Fagundes")
#define AUTHORS proper_name ("Israel Garcia")

#define TAMANHO_PALAVRA 30
#define MI 1000000

void usage(int status){
    if (status != EXIT_SUCCESS) {
      printf("");
    } else {
        printf (("\
            Usage: %s [FILE]\n\
        "), PROGRAM_NAME);
        fputs (("\
            Cria um arquivo csv que exibe a ocorrência das palavras contidas no arquivo .txt.\n\
        "), stdout);
    }
}

//Estruta com a palavra, a quantidade de vezes que apareceu e o ponteiro para a próxima palavra
typedef struct typeword Palavra;

struct typeword{
    char string[TAMANHO_PALAVRA];
    int contador;
    Palavra* proxima;
};


//Verifica se adiciona uma nova palavra ou se somente soma o contador de uma palavra já existente
Palavra* ChecaPalavra(char *word, Palavra *lista, int *conta_palavras){
    Palavra *i;

    //Se a lista for vazia, aloca memória e cria a primeira palavra
    if(lista == NULL){
        //Aloca memória
        Palavra* proxima_palavra;
        proxima_palavra = (Palavra*)malloc(sizeof(Palavra));

        //Passa os valores
        strcpy(proxima_palavra -> string, word);
        proxima_palavra -> contador = 1;
        *conta_palavras = *conta_palavras + 1;
        proxima_palavra -> proxima = NULL;
        lista = proxima_palavra;
        return lista;
    }

    i  = lista;
    Palavra *fim_lista;

    //Vai percorrendo a lista para ver se acha a palavra na lista
    while(i!=NULL){
        if(strcmp(i -> string, word) == 0){
            i -> contador++;
            return lista;
        }
        if(i -> proxima==NULL){
            fim_lista = i;
        }
        i = i -> proxima;
    }

    //Se não achou a palavra na lista, aloca memória para uma nova palavra
    Palavra *nova_palavra;
    nova_palavra = (Palavra*)malloc(sizeof(Palavra));

    strcpy(nova_palavra -> string, word);
    nova_palavra -> contador = 1;
    nova_palavra -> proxima = NULL;
    fim_lista -> proxima = nova_palavra;
    *conta_palavras = *conta_palavras + 1;
    return lista;

}

//Lê o arquivo
Palavra* LeitorArquivo(char *filename)
{
    int tamanho_string, read_size;
    int conta_palavras = 0;           //Contador de palavras
    int contador=0;

    FILE *handler = fopen(filename, "r");
    FILE *txt_output = fopen("exit.csv", "w");
    char buffer[MI];                  //Buffer com a string inteira do .txt
    Palavra *lista_palavras = NULL;   //Lista Simplesmente Encadeada de palavras
    

    if(!handler){
        printf("Failed to open text file\n");
        return lista_palavras;
    }
    if(!txt_output){
        printf("Failed to open json file\n");
        return lista_palavras;
    }

    //Pega todo o .txt e coloca no buffer
    while(!feof(handler)){
        buffer[contador] = fgetc(handler);
        contador++;
    }

    char *token = strtok(buffer, " ");

    //Separa a string inteira em substrings
    while(token!=NULL){
        lista_palavras = ChecaPalavra(token, lista_palavras, &conta_palavras);
        token = strtok(NULL, " ");
    }

    //Print no arquivo .csv
    fprintf(txt_output,"string;contador");

    //Print das palavras e seus contadores no arquivo .csv
    Palavra* aux;
    if(lista_palavras == NULL){
        printf("Lista vazia");
    }
    else{
        for(aux = lista_palavras; aux != NULL; aux = aux -> proxima){
            fprintf(txt_output,"\n%s;%d", aux -> string, aux -> contador);
        }
    }
    printf("\n");

    return lista_palavras;
}

int main()
{
    Palavra *lista;
    lista = LeitorArquivo("ArqTeste.txt");
    
    return 0;
}
