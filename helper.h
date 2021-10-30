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
	char espMed[20];	//Médico da especialidade
}avDoente

//Estrutura com as definições dos médicos
typedef struct especialista{
	char nomeMedico[20];
	char especialidade[20];
}medicoEsp;

#endif //HELPER_H