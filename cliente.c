#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "helper.h"

int main(int argc, char **argv, char **envp){

int c_fifo_fd;
int b_fifo_fd;
int le_resp;
char fifo_name[MAX_TAM];
doente dt;
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
sprintf(fifo_name, FIFO_CLIENTE, blc.pid_cliente);

if(mkfifo(fifo_name, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH) == -1){
	perror("\nCriação do FIFO falhou!!!\n");
	exit(EXIT_FAILURE);
	}
fprintf(stderr, "\nTentativa de ligação ao balcão criada\n");

b_fifo_fd = open(FIFO_BALCAO, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);

if(b_fifo_fd == -1){
	fprintf(stderr, "\n Falha no servidor!!!\n");
	unlink(fifo_name);
	exit(EXIT_FAILURE);
	}

fprintf(stderr, "\n*** Servidor aberto para Read/Write ENABLE ***\n");

c_fifo_fd = open(fifo_name, O_RDWR);

if(c_fifo_fd == -1){
	perror("\nFalha ao abrir o cliente");
	close(c_fifo_fd);
	unlink(fifo_name);
	exit(EXIT_FAILURE);
}

fprintf(stderr, "\nCliente aberto para Read/Write");

memset(dt.nome, '\0', MAX_TAM);

while(1){
	printf("\nQuais são os sintomas?\n");
	scanf("%s", &dt.sintoma);
	//printf("Eu sou o %s e tenho os seguintes sintomas:\n%s", argv[1], &dt.sintoma);
//Envia dados para o balcão
	write(b_fifo_fd, &sintDoente, sizeof(sintDoente));

//Recebe resposta do balcão
	le_resp = read(c_fifo_fd, &escolhaBalcao, sizeof(escolhaBalcao));
if(le_resp == sizeof(escolhaBalcao))
	printf("Especialidade %s\n", escolhaBalcao.especialidade);
else
	printf("Não foi possivel obter resposta\n");
}

close(c_fifo_fd);
close(b_fifo_fd);

return 0;
}