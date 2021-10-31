#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_TAM 50
#define FIFO_BALCAO "fBalcao"		//Nome do pipe do balcão
#define FIFO_CLIENTE "fCliente_%d"	//Nome do pipe de cliente

//Estrutura onde são guardados os dados dos clientes
typedef struct cliente{
	char nome[MAX_TAM];			//Nome do cliente
	char sintoma[MAX_TAM];		//Qual o sintoma
}doente;

//Estrutura onde são guardados os dados devolvidos pelo balcão
typedef struct balcao{
	int prioridade;		//Prioridade do sintoma
	int tempoEspera;		//Clientes em fila de espera
	char espMed[MAX_TAM];	//Médico da especialidade
}av_doente;

//Estrutura com as definições dos médicos
typedef struct especialidade{
	char nomeMedico[MAX_TAM];
	char especialidade[MAX_TAM];
}medico_esp;

//Estrutura com definições cliente->balcão
typedef struct{
	pid_t pid_cliente;
}perg_balcao;