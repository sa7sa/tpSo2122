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
    char *f_resp = FIFO_CLIENTE;
    doente dt;
    medico_esp escolhaBalcao;
    perg_balcao blc;

    if(argc < 2){
        printf("Nome do doente não definido\n");
        printf("./cliente <nome>\n");
        printf("'default' por defeito\n");
        argv[1] = "default";
    }

    criaFIFO(FIFO_CLIENTE);//Cria FIFO do cliente->balcao

    fprintf(stderr, "\n*** Servidor aberto para Read/Write ENABLE ***\n");

    c_fifo_fd = openFIFO(FIFO_CLIENTE);

    b_fifo_fd = openFIFO(FIFO_BALCAO);

	printf(":(\n");

    if(c_fifo_fd == -1){
        perror("\nFalha ao abrir o cliente");
        close(c_fifo_fd);
        unlink(f_resp);
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "\nCliente aberto para Read/Write");

    //memset(dt.nome, '\0', sizeof (dt));

    dt.nome = argv[1];

    printf("\nNome do doente: %s\n", dt.nome);

    printf("\nQuais são os sintomas?\n");
    scanf("%s", &dt.sintoma);
    printf("Eu sou o %s e tenho os seguintes sintomas: %s", argv[1], dt.sintoma);
//Envia dados para o balcão
    write(b_fifo_fd, &dt, sizeof(dt));

//Recebe resposta do balcão
    le_resp = read(c_fifo_fd, &escolhaBalcao, sizeof(escolhaBalcao));
    if(le_resp == sizeof(escolhaBalcao))
        printf("Especialidade %s\n", escolhaBalcao.especialidade);
    else
        printf("Não foi possivel obter resposta\n");


    close(c_fifo_fd);
    close(b_fifo_fd);

    return 0;
}