#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

#include "helper.h"

int b_fifo_fd, c_fifo_fd;

void sig(int i){
fprintf(stderr, "\nBalcão a encerrar\n");

close(b_fifo_fd);
unlink(FIFO_BALCAO);
exit(EXIT_SUCCESS);
}

int main(int argc, char **argv, char **envp){

int resposta;
char sintomas;
doente dt;
av_doente sintDoente;
medico_esp respBalcao;
perg_balcao blc;

printf("Balcão de serviço\n");
if(signal(SIGINT, sig) == SIG_ERR){
	perror("\nImpossivel configurar sinal!!!\n");
exit(EXIT_FAILURE);
}
fprintf(stderr, "\nSinal configurado");

resposta = mkfifo(FIFO_BALCAO, 0777);

if(resposta == -1){
	perror("\n!!!Falha ao ligar ao servidor!!!\n");
	exit(EXIT_FAILURE);
	}

fprintf(stderr, "\nConexão criada.\n");

b_fifo_fd = open(FIFO_BALCAO, O_RDWR);

if(b_fifo_fd == -1){
	perror("\nFalha ao ligar ao servidor!!!\n");
	exit(EXIT_FAILURE);
	}

fprintf(stderr, "\n Ligação criada com o cliente\n");

while(1){
	sintomas = read(b_fifo_fd, &dt, sizeof(dt));
	if(sintomas < sizeof(dt)){
		fprintf(stderr, "\nInformação incompleta\n");
		continue;
	}

printf("\nCliente %s", dt.sintoma);

}

close(b_fifo_fd);
unlink(FIFO_BALCAO);

return 0;
}