#include <stdio.h>
#include <stdlib.h>

#include "helper.h"
#include "funcoes.h"

int main(int argc, char **argv, char **envp){

int i;
char sintomas[30];

if(argc < 2){
	printf("Nome do doente não definido\n");
	printf("./cliente <nome>\n");
	return 0;
}

printf("Quais são os sintomas\n");
scanf("%[^\n]", sintomas);

printf("Eu sou o %s e tenho os seguintes sintomas:\n%s", argv[1], sintomas);

return 0;
}