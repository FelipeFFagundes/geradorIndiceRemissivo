#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
char frase[50];
int i, flag=0, total=0;

printf("Insira a frase:\n");
fgets(frase,51,stdin);

    for(i=0;frase[i]!='\0';i++) {
    	if(!flag && frase[i]!=' ') {
    		flag=1;
    		total++;
    	}
    	else if(flag && frase[i]==' ')
    		flag=0;
    }
    
printf("numero total de palavras: %d\n",total);

return 0;
}