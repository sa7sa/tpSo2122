#ifndef HELPER_H
#define HELPER_H

//Estrutura onde são guardados os dados dos clientes
typedef struct cliente{
	char nome[20];			//Nome do cliente
	char sintoma[];		//Qual o sintoma
}doente;

//Estrutura onde são guardados os dados devolvidos pelo balcão
typedef struct avaliaCliente{
	int prioridade;		//Prioridade do sintoma
	int tempoEspera;		//Clientes em fila de espera
	char especialidade[20];	//Médico da especialidade
}AvDoente

#endif //HELPER_H