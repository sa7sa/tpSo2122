#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "helper.h"
#include "funcoes.h"

int main(int argc, char **argv, char **envp){

int c_fifo_fd;
int b_fifo_fd;
int le_resp;
char sintomas[MAX_TAM];
av_doente sintDoente;
medico_esp escolhaBalcao;
perg_balcao blc;

if(argc < 2){
	printf("Nome do doente não definido\n");
	printf("./cliente <nome>\n");
	printf("'default' por defeito\n");
	argv = "default";
}

//Cria FIFO do cliente
blc.pid_cliente = getpid();
sprintf(sintomas, FIFO_BALCAO, blc.pid_cliente);

if(mkfifo(sintomas, 0777 == -1)){
	perror("\nCriação do FIFO falho!!!\n");
	exit(EXIT_FAILURE);
	}
fprintf(stderr, "\nServidor FECHADO, Write ENABLE");

b_fifo_fd = open(FIFO_BALCAO, O_RDWR);

if(b_fifo_fd == -1){
	fprintf(stderr, "\n Falha no servidor\n");
	unlink(c_fifo_fd);
	exit(EXIT_FAILURE);
	}

fprintf(stderr, "\nServidor aberto para Read/Write ENABLE");

c_fifo_fd = open(sintomas, O_RDWR);

if(c_fifo_fd == -1){
	fprintf(stderr, "\nFalha ao abrir o cliente\n");
	close(c_fifo_fd);
	unlink(sintomas);
	exit(EXIT_FAILURE);
}

fprintf(stderr, "\nCliente aberto para Read/Write");

memset(sintDoente.espMed, '\0', MAX_TAM);

while(1){
	printf("Quais são os sintomas\n");
	scanf("%[^\n]", sintomas);
	printf("Eu sou o %s e tenho os seguintes sintomas:\n%s", argv[1], sintomas);
//Envia dados para o balcão
	write(b_fifo_fd, &sintDoente, sizeof(sintDoente));

//Recebe resposta do balcão
	le_resp = read(c_fifo_fd, &escolhaBalcao, sizeof(escolhaBalcao));
if(le_resp == sizeof(escolhaBalcao))
	printf("Especialidade %s\n", &escolhaBalcao.especialidade);
else
	printf("Não foi possivel obter resposta\n");
}

close(c_fifo_fd);
close(b_fifo_fd);

return 0;
}