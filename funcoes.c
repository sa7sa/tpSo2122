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

void criaFIFO(char *fifoName){
perg_balcao blc

blc.pid_cliente = getpid();
sprintf(fifoName, FIFO_CLIENTE, blc.pid_cliente);

if(mkfifo(fifoName, 0777) == -1){
	perror("\nCriação do FIFO falhou!!!\n");
	exit(EXIT_FAILURE);
	}
	
fprintf(stderr, "\nLigação ao balcão criada\n");
}

int openFIFO(char *f_name){
int fifo;

fifo = open(f_name, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);

if(fifo == -1){
	fprintf(stderr, "\n Falha no servidor!!!\n");
	unlink(f_name);
	exit(EXIT_FAILURE);
	}
return fifo;
}