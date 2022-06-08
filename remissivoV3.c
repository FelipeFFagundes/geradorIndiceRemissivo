#include <stdio.h>
#define MAX 30
 
int ocorrencias(char palavra[], char letra, int i) {
 int contagem = 0;

    while (palavra[i] != '\0') contagem += letra == palavra[i++];
    return contagem;
}
 
int main() {
	char palavra[MAX];
	char letra;
	scanf("%s %c", palavra, &letra);
	printf("%d", ocorrencias(palavra, letra, 0));
}