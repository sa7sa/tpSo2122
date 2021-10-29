#ifndef HELPER_H
#define HELPER_H

//Estrutura onde são guardados os dados dos clientes
typedef struct cliente{
	char nome[20];
	char sintoma[];
}doente;

//Estrutura onde são guardados os dados devolvidos pelo balcão
typedef struct avaliaCliente{
	int prioridade;
	int espera;
	char expecialidade[20];
}AvDoente

#endif //HELPER_H
