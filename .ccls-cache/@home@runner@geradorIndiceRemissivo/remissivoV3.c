#include <stdio.h>
#include <stdlib.h>


int main(){
  char ch, variavel[]="Tem", file_name[25];
  int count=0;
  FILE *fp;

  printf("Por favor digite o nome do arquivo\n");
  gets(file_name);
  printf("\n");
  
  fp = fopen(file_name, "r");
  printf("\n");

  if (fp == NULL){
    perror("Erro ao abrir o arquivo.\n");
    exit(EXIT_FAILURE);
  }

  printf("Os conteúdo do arquivo %s são:\n", file_name);

  while((ch = fgetc(fp)) != EOF){
    if(ch==variavel){
        count++;
    }
    printf("%c", ch);
}
  printf("%d",count);
  fclose(fp);
  return 0;
}