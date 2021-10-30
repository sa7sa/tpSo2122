#include <stdio.h>
#include <stdlib.h>

#include "helper.h"
//#include "funcoes.h"

int main(int argc, char **argv, char **envp){

int i;
char *sintomas;

if(argc < 2){
	printf("Nome do doente não definido\n");
	printf("./cliente <nome>\n");
	return 0;
}

printf("Quais são os sintomas\n");
scanf("%s", sintomas);

return 0;
}